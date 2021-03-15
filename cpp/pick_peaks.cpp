/**
 * Find all local minima and their positions in a vector.
 * 
 * PeakData is just an aggregate data type with std::vector<int>
 * fields named 'pos' and 'peaks' for codewars' test suite.
 */

#include <iostream>
#include <vector>

PeakData pick_peaks(std::vector<int> v) {
  PeakData result;
  int prev = v[0], increasing = 0, peak_pos = 0;
  for (size_t i=0; i<v.size(); i++) {
    if (v[i] > prev) {
      increasing = 1;
      peak_pos = i;
    } 
    else if (v[i] < prev && increasing) {
      increasing = 0;
      result.pos.push_back(peak_pos);
      result.peaks.push_back(v[peak_pos]);
    }
    prev = v[i];
  }
  return result;
}
