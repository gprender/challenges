/**
 * Return the order of unique elements in a vector or string.
 * e.g. {1, 1, 2, 2, 3, 1} => {1, 2, 3, 1}
 * 
 * vector.back() produces undefined behaviour when the vector is empty,
 * so we have to check for that first. I wonder if there's a clean way
 * to check for an empty vector once (at the beginning) instead of checking
 * for each element.
 */

#include <string>
#include <vector>

template<typename T> 
std::vector<T> uniqueInOrder(const std::vector<T>& iterable){
  std::vector<T> result;
  for (auto const e : iterable) {
    if (result.empty() || e != result.back()) {
      result.push_back(e);
    }
  }
  return result;
}

std::vector<char> uniqueInOrder(const std::string& iterable){
  std::vector<char> result;
  for (auto const c : iterable) {
    if (result.empty() || c != result.back()) {
      result.push_back(c);
    }
  }
  return result;
}
