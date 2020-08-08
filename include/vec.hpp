#pragma once

#include <cmath>

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

  T length() const { return std::sqrt(length_squared()); }

  T length_squared() const { return x_ * x_ + y_ * y_ + z_ * z_; }

  // operator overloads
  Vec3 operator-() const { return Vec3(-x_, -y_, -z_); }

  Vec3 operator+(const Vec3 &r) {
    return Vec3(x_ + r.x(), y_ + r.y(), z_ + r.z());
  }

  Vec3 &operator+=(const Vec3 &v) {
    x_ += v.x();
    y_ += v.y();
    z_ += v.z();
    return *this;
  }

  Vec3 operator-(const Vec3 &r) {
    return Vec3(x_ - r.x(), y_ - r.y(), z_ - r.z());
  }

  Vec3 &operator-=(const Vec3 &v) {
    x_ -= v.x();
    y_ -= v.y();
    z_ -= v.z();
    return *this;
  }

  Vec3 &operator*=(const T t) {
    x_ *= t;
    y_ *= t;
    z_ *= t;
    return *this;
  }

  Vec3 &operator/=(const T t) { return *this *= T(1) / t; }
};

template <typename T> Vec3<T> operator*(T t, const Vec3<T> &v) {
  return Vec3(t * v.x(), t * v.y(), t * v.z());
}

template <typename T> Vec3<T> operator*(const Vec3<T> &v, T t) { return t * v; }

template <typename T> Vec3<T> operator/(const Vec3<T> &v, T t) {
  return (T(1) / t) * v;
}

template <typename T> T dot(const Vec3<T> &l, const Vec3<T> &r) {
  return l.x() * r.x() + l.y() * r.y() + l.z() * r.z();
}

template <typename T> Vec3<T> closs(const Vec3<T> &l, const Vec3<T> &r) {
  return Vec3(l.y() * r.z() - l.z() * r.y(), l.z() * r.x() - l.x() * r.z(),
              l.x() * r.y() - l.y() * r.x());
}

template <typename T> Vec3<T> unit_vector(Vec3<T> v) { return v / v.length(); }

template <typename T> using Point3 = Vec3<T>;
template <typename T> using Color = Vec3<T>;
