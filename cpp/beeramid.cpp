/**
 * Given a sum of money (bonus) and the price for a can of beer, 
 * determine the tallest square beercan pyramid you can build.
 * 
 * Nothing too crazy here, just determining the largest sum of
 * squares contained within some number (bonus/price).
 */

int beeramid(int bonus, double price) {
  int remaining = bonus / price;
  int layer = 1;
  for (; remaining >= 0; layer++) {
    remaining -= (layer * layer);
  }
  return layer-2;
}
