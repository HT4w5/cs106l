/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <sstream>

std::string kYourName = "John Doe"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename)
{
  std::string line;
  std::ifstream ifs(filename);
  std::set<std::string> applicantSet;
  while (std::getline(ifs, line))
  {
    applicantSet.insert(line);
  }
  return applicantSet;
}

std::pair<char, char> get_initials(const std::string &name)
{
  char first, last;
  first = name[0];
  for (size_t i = 1; i < name.size(); ++i)
  {
    if (name[i] == ' ')
    {
      last = name[i + 1];
      break;
    }
  }
  return {first, last};
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string *> find_matches(std::string name, std::set<std::string> &students)
{
  auto my_initials = get_initials(name);
  std::queue<const std::string *> matches;
  for (const auto &candidate : students)
  {
    if (my_initials == get_initials(candidate))
    {
      matches.push(&candidate);
    }
  }
  return matches;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string *> &matches)
{
  if (!matches.empty())
  {
    return *(matches.front());
  }
  else
  {
    return "NO MATCHES FOUND.";
  }
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
