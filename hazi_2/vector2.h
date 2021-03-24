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
};