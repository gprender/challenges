/**
 * Construct Pascal's Triangle of height n, flattened to a vector.
 * 
 * I found this one to be really interesting to solve; I wanted
 * to come up with a solution that iteratively builds the triangle
 * without using some magic formula for the value of each cell.
 * 
 * There's a neat property I noticed with the indices when you flatten 
 * Pascal's Triangle to a 1-d container, which I'll try to draw out in ASCII: 
 * 
 *        0
 *      1   2
 *    3   4   5
 *  6   7   8   9
 * 
 * We can see that any line of indices increases like a subsequence
 * of the sum of the natural numbers. e.g.: 
 *     (0 1 3 6) => (0 +=1 +=2 +=3) 
 *     (0 2 5 9) => (0 +=2 +=3 +=4)
 * We can take advantage of this property find the parent indices of
 * each cell, and then calculate that cell's value with a simple summation.
 * 
 * There's a few places in my solution where it looks like I'm pulling
 * magic numbers out of a hat, but all of the numbers arise from the 
 * above property, using some subsequence of the natural numbers.
 */

#include <vector>

std::vector<long long> pascalsTriangle(int const n) {
  int ncells = n * (n + 1) / 2; 
  std::vector<long long> ptriangle (ncells);
  
  // initialize the first /-diagonal 'column' to 1s
  for (int row=0, idx=0; row<n; row++) {
    ptriangle[idx] = 1;
    idx += (row + 1);
  }
  
  // iteratively build up the remaining columns
  for (int col=1, top_idx=2; col<n; col++) {
    ptriangle[top_idx] = 1;  // init the top element of this column
    
    // set the remaining cells in the column to the sum of its parents
    int rparent = top_idx, lparent = top_idx-1;
    for (int row=1, idx=(top_idx+col+1); row<(n-col); row++) {
      ptriangle[idx] = ptriangle[lparent] + ptriangle[rparent];
      rparent = idx;
      lparent = idx-1;
      idx += (row + col + 1);
    }
    top_idx += (col + 2);
  } 
  
  return ptriangle;
}
