#include "utils/StringUtils.h"
#include <cctype>

namespace playbook::utils {

std::string trim(const std::string &value) {
  if (value.empty())
    return value; // If empty return the string itself

  // Assume there are no non-whitespace characters in the string
  size_t firstCharIndex = std::string::npos;

  // Find first occurence of a non-whitespace character (left to right)
  for (size_t i = 0; i < value.size(); i++) {
    if (isspace(static_cast<unsigned char>(value.at(i)))) {
      firstCharIndex = i;
      break;
    }
  }
  if (firstCharIndex == std::string::npos)
    return ""; // If the entire string is whitespace, return an empty string

  // Set boundary for lastCharIndex to firstCharIndex initially
  // Ensures that there is a bound, essentially [firstCharIndex, lastCharIndex]
  size_t lastCharIndex = firstCharIndex;
  // Find last occurence of a non-whitespace character (right to left)
  for (size_t i = value.size() - 1; i > firstCharIndex; i--) {
    if (!isspace(static_cast<unsigned char>(value.at(i)))) {
      lastCharIndex = i;
      break;
    }
  }

  // Get the substring from firstCharIndex to lastCharIndex (inclusive)
  return value.substr(firstCharIndex, lastCharIndex - firstCharIndex + 1);
}

} // namespace playbook::utils
