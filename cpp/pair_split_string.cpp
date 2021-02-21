// Split a string into pairs of chars
// The last pair of an odd-length string gets a '_' buffer.

#include <string>
#include <vector>

std::vector<std::string> solution(const std::string &s) 
{
  std::vector<std::string> split_pairs;
  auto it = s.begin();
  while (it != s.end()) {
    auto first = *it++;
    auto second = (it != s.end()) ? *it++ : '_';  // this is a super cool line
    auto pair = std::string(1,first) + second;
    split_pairs.push_back(pair);
  }
  return split_pairs;
}
