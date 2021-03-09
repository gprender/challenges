/**
 * Calculate the integer value of a Roman numeral string.
 * 
 * I found this one to be pretty tough; Roman numerals have some tricky logic.
 * After reading some other solutions, I've realised that a std::map would
 * be a much better alternative to the switch statement in digit_hash().
 * There were also some really clever ways to do the decoding with just a 
 * simple iteration, rather than all the pointer finagling that I did.
 */

#include <iostream>
#include <string>

int digit_hash(char const c);

int solution(std::string const& roman) {
  int total = 0;
  auto it = roman.begin();
  while (it != roman.end()) {
    int term = digit_hash(*it++); 
    int next_digit = digit_hash(*it);
    if (next_digit > term) {
      term = next_digit - term;
      it++;
    } else if (next_digit == term) {
      while (digit_hash(*it) == next_digit) {
        term += digit_hash(*it++);
      }
    }
    total += term;
  }
  return total;
}

int digit_hash(char const c) {
  switch (c) {
    case 73: return 1;
    case 86: return 5;
    case 88: return 10;
    case 76: return 50;
    case 67: return 100;
    case 68: return 500;
    case 77: return 1000;
    default: return 0;
  }
}
