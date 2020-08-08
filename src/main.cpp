#include <iostream>
#include <vector>

#include "ppm.hpp"
#include "ray.hpp"
#include "vec.hpp"

template <typename T> Color<T> ray_color(const Ray<T> &r) {
  Vec3 unit_direction = unit_vector(r.d());
  T t = 0.5 * (unit_direction.y() + 1.0);
  return (T(1.0) - t) * Color<T>(1, 1, 1) + t * Color<T>(0.5, 0.7, 1.0);
}

int main() {
  using T = float;

  // image
  const int h = 9 * 1 << 6;
  const int w = 16 * 1 << 6;
  const double aspect_ratio = double(w) / h;

  // camera
  auto viewport_height = 2.0;
  auto viewport_wigth = aspect_ratio * viewport_height;
  auto focal_length = 1.0;

  auto origin = Point3<T>(0, 0, 0);
  auto horizontal = Vec3<T>(viewport_wigth, 0, 0);
  auto vertical = Vec3<T>(0, viewport_height, 0);
  auto lower_left_corner = origin - horizontal / T(2.) - vertical / T(2.) -
                           Vec3<T>(0, 0, focal_length);

  // render
  std::vector<Color<T>> color_buf(h * w);

  for (int i = 0; i < h; i++) {
    fprintf(stderr, "\rLine %d rendering...", i);
    for (int j = 0; j < w; j++) {
      auto u = T(j) / (w - 1);
      auto v = T(1) - T(i) / (h - 1);
      Ray<T> r(origin,
               lower_left_corner + u * horizontal + v * vertical - origin);
      Color<T> c = ray_color(r);
      color_buf[i * w + j] = c;
    }
  }
  fprintf(stderr, "\nDone.\n");

  print_to_ppm(color_buf.data(), h, w);
}
