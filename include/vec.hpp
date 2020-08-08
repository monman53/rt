#pragma once

template <typename T> class Vec3 {
  T x_, y_, z_;

public:
  Vec3() : x_(0), y_(0), z_(0) {}
  Vec3(T x) : x_(x), y_(0), z_(0) {}
  Vec3(T x, T y) : x_(x), y_(y), z_(0) {}
  Vec3(T x, T y, T z) : x_(x), y_(y), z_(z) {}

  T x() const { return x_; }
  T y() const { return y_; }
  T z() const { return z_; }
};

template <typename T> using Color = Vec3<T>;
