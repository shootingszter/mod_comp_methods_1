#include <iostream>

template<typename T>

struct Vector2
{
    T x, y;

    Vector2<T>& operator+=( Vector2<T> const& v)
    {
        x += y.x; y += v.y;
        return *this;
    }

    Vector2<T>& operator+( Vector2<T> const& a, Vector2<T> const& b )
    {
        return Vector2<T>{a.x + b.x, a.y + b.y};
    }
};