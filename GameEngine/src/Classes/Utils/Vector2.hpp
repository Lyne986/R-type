#ifndef __RT_GAMEENGINE_UTILS_VECTOR_HPP__
    #define __RT_GAMEENGINE_UTILS_VECTOR_HPP__

    #include "UtilsNamespace.hpp"

    #include <sstream>

template <typename T>
struct RT::GE::Utils::Vector2 {
    T x;
    T y;

    Vector2(T x, T y) : x(x), y(y) {}
    Vector2() : x(0), y(0) {}

    Vector2(const Vector2 &other) = default;

    Vector2<T> operator+(const Vector2<T> &other) const {
        return Vector2<T>(x + other.x, y + other.y);
    }

    Vector2<T> operator-(const Vector2<T> &other) const {
        return Vector2<T>(x - other.x, y - other.y);
    }

    Vector2<T> operator*(const Vector2<T> &other) const {
        return Vector2<T>(x * other.x, y * other.y);
    }

    Vector2<T> operator/(const Vector2<T> &other) const {
        return Vector2<T>(x / other.x, y / other.y);
    }

    Vector2<T> operator+(const T &other) const {
        return Vector2<T>(x + other, y + other);
    }

    Vector2<T> operator-(const T &other) const {
        return Vector2<T>(x - other, y - other);
    }

    Vector2<T> operator*(const T &other) const {
        return Vector2<T>(x * other, y * other);
    }

    Vector2<T> operator/(const T &other) const {
        return Vector2<T>(x / other, y / other);
    }

    Vector2<T> &operator+=(const Vector2<T> &other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2<T> &operator-=(const Vector2<T> &other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vector2<T> &operator*=(const Vector2<T> &other) {
        x *= other.x;
        y *= other.y;
        return *this;
    }

    Vector2<T> &operator/=(const Vector2<T> &other) {
        x /= other.x;
        y /= other.y;
        return *this;
    }

    Vector2<T> &operator+=(const T &other) {
        x += other;
        y += other;
        return *this;
    }

    Vector2<T> &operator-=(const T &other) {
        x -= other;
        y -= other;
        return *this;
    }

    Vector2<T> &operator*=(const T &other) {
        x *= other;
        y *= other;
        return *this;
    }

    Vector2<T> &operator/=(const T &other) {
        x /= other;
        y /= other;
        return *this;
    }

    bool operator==(const Vector2<T> &other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vector2<T> &other) const {
        return x != other.x || y != other.y;
    }

    bool operator<(const Vector2<T> &other) const {
        return x < other.x && y < other.y;
    }

    bool operator>(const Vector2<T> &other) const {
        return x > other.x && y > other.y;
    }

    bool operator<=(const Vector2<T> &other) const {
        return x <= other.x && y <= other.y;
    }

    bool operator>=(const Vector2<T> &other) const {
        return x >= other.x && y >= other.y;
    }

    Vector2<T> &operator=(const Vector2<T> &other) {
        x = other.x;
        y = other.y;
        return *this;
    }

    Vector2<T> &operator=(const T &other) {
        x = other;
        y = other;
        return *this;
    }

    Vector2<T> &operator++() {
        x++;
        y++;
        return *this;
    }

    Vector2<T> &operator--() {
        x--;
        y--;
        return *this;
    }

    Vector2<T> operator++(int) {
        Vector2<T> tmp(*this);
        operator++();
        return tmp;
    }

    Vector2<T> operator--(int) {
        Vector2<T> tmp(*this);
        operator--();
        return tmp;
    }

};

inline std::ostream &operator<<(std::ostream &os, const RT::GE::Utils::Vector2<int> &vector) {
    os << "Vector2<int>(" << vector.x << ", " << vector.y << ")";
    return os;
}

#endif