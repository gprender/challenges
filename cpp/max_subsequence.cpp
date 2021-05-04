/**
 * Find the sum of the maximum contiguous subsequence of a vector.
 * 
 * Coincidentally, I saw this problem on codewars when it'd just
 * come up in a recent interview for me. So, here's me solving it
 * after the fact.
 * 
 * Initially, this problem sounds really hard to solve in a reasonable
 * amount of time, but as soon as we realize that contiguous subsequences
 * with a sum less than 0 can immediately be dismissed (since the empty
 * subsequence has a sum of 0), we can solve the problem with a single,
 * simple iteration over the vector.
 */

#include <vector>

int maxSequence(vector<int> const& arr) {
  int best_sum = 0, current_sum = 0;
  for (auto const e : arr) {
    current_sum = std::max(0, current_sum + e);
    if (current_sum > best_sum) {
      best_sum = current_sum;
    }
  }
  return best_sum;
}
