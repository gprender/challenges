/**
 * Calculate the score for a single throw in the dice game 'Greed'
 * 
 * The rules of the game aren't super important, just that there are
 * different scores for each dice face in single and three-of-a-kind.
 * I wanted to avoid using a pile of branching conditions, so I used
 * a couple of map-like arrays ('triple' and 'single').
 */

#include <vector>
#include <array>

int score(const std::vector<int>& dice) {
  std::array<int,6> counts = {0};
  for (auto const i : dice) counts[i-1]++;
  
  std::array<int,6> triple = {1000,200,300,400,500,600};
  std::array<int,6> single = {100,0,0,0,50,0};

  int score = 0, i = 0;
  for (auto const c : counts) {
    if (c >= 3) {
      score += triple[i] + (c % 3) * single[i];
    } else {
      score += c * single[i];
    }
    i++;
  }
  return score;
}
