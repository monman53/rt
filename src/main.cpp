#include <iostream>
#include <vector>

#include "ppm.hpp"
#include "vec.hpp"

int main() {
  const int h = 9 * 1 << 6;
  const int w = 16 * 1 << 6;

  std::vector<Color<double>> color_buf(h * w);

  for (int i = 0; i < h; i++) {
    fprintf(stderr, "\rLine %d rendering...", i);
    for (int j = 0; j < w; j++) {
      const double r = double(i) / h;
      const double g = double(j) / w;
      const double b = 0.5;
      const Color<double> c(r, g, b);
      color_buf[i * w + j] = c;
    }
  }
  fprintf(stderr, "\nDone.\n");

  print_to_ppm(color_buf.data(), h, w);
}
