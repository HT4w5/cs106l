//#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

template <typename Iterator>
Corpus tokenize(const std::string &source)
{
  std::vector<Iterator> spaceIts = find_all(source.begin(), source.end(), isspace); // Get all whitespace iterators.
  Corpus tokens;                                                                    // Store tokens.
  // Token inserter.
  std::insert_iterator<Corpus> inserter(tokens, tokens.end());
  // Transform tokenize lambda.
  auto lambdaTokenize = [&source](std::string::const_iterator it1, std::string::const_iterator it2) -> Token
  {
    return Token(source, it1, it2);
  };
  // Transform to find all tokens.
  std::transform(spaceIts.begin(), spaceIts.end() - 1, spaceIts.begin() + 1, inserter, lambdaTokenize);
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
  /* TODO: Implement this method */
  return std::set<Mispelling>();
};

/* Helper methods */

#include "utils.cpp"