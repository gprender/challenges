/**
 * Given an input string, convert any dash or underscore delimited seprations
 * to camelCase (e.g. 'hello-world' -> 'helloWorld')
 *
 * This takes a lot more work than I'd expect; I'm always surprised 
 * at how difficult string processing is in C/C++. 
 */


#include <string>

std::string to_camel_case(std::string text) {
  for (auto const delim : {'-', '_'}) {
    auto match_idx = text.find(delim);
    while (match_idx != std::string::npos) {
      text.erase(match_idx, 1);
      auto c = text[match_idx];
      std::string C (1, (char)toupper(c));
      text.replace(match_idx, 1, C);
      match_idx = text.find(delim);
    }
  }
  return text;
}
