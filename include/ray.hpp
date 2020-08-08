#pragma once

#include "vec.hpp"

template <typename T> class Ray {
  Point3<T> o_;
  Vec3<T> d_;

public:
  Ray() {}
  Ray(const Point3<T> &o, const Vec3<T> &d) : o_(o), d_(d) {}

  Point3<T> o() const { return o_; }
  Vec3<T> d() const { return d_; }

  Point3<T> at(T t) const { return o_ + t * d_; }
};
