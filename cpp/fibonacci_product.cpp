/**
 * For an input integer 'prod', find the consecutive Fibonacci numbers
 * F_n, F_(n+1) such that F_n * F_(n+1) = prod. If no two such Fibonacci
 * numbers exist, find the smallest two whose product is greater than prod.
 * 
 * Nothing too clever here, just iterating through the Fibonacci sequence
 * until we meet or exceed the goal. One solution to this used std::swap()
 * to do the inside of the while loop in 2 lines, which would be a small
 * improvement over this version.
 */

#include <vector>

using ull = unsigned long long;

class ProdFib {
  public:
    static std::vector<ull> productFib(ull prod) {
      ull f_prev = 0, f_n = 1;
      while (f_prev * f_n < prod) {
        ull f_next = f_prev + f_n;
        f_prev = f_n;
        f_n = f_next;
      }
      return {f_prev, f_n, (f_prev * f_n == prod)};
    }
};
