#pragma once

#include <cstdio>

#include "vec.hpp"

template <typename T>
static void print_to_ppm(const Color<T> *color_buf, int h, int w) {
  printf("P3\n");
  printf("%d %d\n", w, h);
  printf("255\n");
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      const auto c = color_buf[i * w + j];
      const auto r = c.x();
      const auto g = c.y();
      const auto b = c.z();
      const int ir = static_cast<int>(255 * r);
      const int ig = static_cast<int>(255 * g);
      const int ib = static_cast<int>(255 * b);
      printf("%d %d %d\n", ir, ig, ib);
    }
  }
}
