/**
 * For an integer n, calculate the following:
 *    (1! + 2! + ... + (n-1)! + n!) / n!
 * 
 * We can actually do this calculation without explicitly finding n!:
 *    = (1! / n!) + (2! / n!) + ... + ((n-1) / n!) + (n! / n!)
 * 
 * Then, flipping the summation around:
 *    = 1 + 1/n + 1/(n * (n-1)) + ... + (1 / n!)
 */

class Suite {
  
  public:
    static double going(int n) {
      double result = 1;
      double prev_term = 1;
      for (int i=0; i<(n-1); i++) { 
        prev_term *= (double)1/(n-i);
        result += prev_term;
      }
      return result;
    }
  
};
