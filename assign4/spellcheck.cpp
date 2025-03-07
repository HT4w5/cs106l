#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(const std::string &source)
{
  auto spaceIts = find_all(source.begin(), source.end(), isspace); // Get all whitespace iterators.
  Corpus tokens;                                                   // Store tokens.
  // Transform tokenize lambda.
  auto lambdaTokenize = [&source](std::string::const_iterator it1, std::string::const_iterator it2) -> Token
  {
    return Token(source, it1, it2);
  };
  // Transform to find all tokens.
  std::transform(spaceIts.begin(), spaceIts.end() - 1, spaceIts.begin() + 1, std::inserter(tokens, tokens.end()), lambdaTokenize);
  // Remove empty tokens.
  // Token check lambda.
  auto lambdaCheckEmpty = [](Token tok)
  {
    return tok.content.empty();
  };
  std::erase_if(tokens, lambdaCheckEmpty);

  return tokens;
}

std::set<Mispelling> spellcheck(const Corpus &source, const Dictionary &dictionary)
{
  namespace rv = std::ranges::views;
  namespace rng = std::ranges;
  // Correctly spelled predicate.
  auto isIncorrect = [&dictionary](Token elem)
  {
    return !dictionary.contains(elem.content);
  };
  // Generate suggestions operation.
  auto genSuggest = [&dictionary](Token elem) -> Mispelling
  {
    // Is one-step-away predicate.
    auto isOneStepAway = [&elem](std::string word) -> bool
    {
      return levenshtein(elem.content, word) == 1;
    };
    // Generate range of suggestions.
    auto suggestions = dictionary | rv::filter(isOneStepAway) | rng::to<std::set<std::string>>();
    return {elem, suggestions};
  };
  // Empty suggestions predicate.
  auto hasSuggestions = [](Mispelling elem) -> bool
  {
    return !elem.suggestions.empty();
  };
  // Generate mispelling set.
  return source | rv::filter(isIncorrect) | rv::transform(genSuggest) | rv::filter(hasSuggestions) | rng::to<std::set<Mispelling>>();
};

/* Helper methods */

#include "utils.cpp"