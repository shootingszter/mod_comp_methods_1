#include <iostream>
#include <math.h>

template<typename T>

struct Vector2
{
    T x, y;
};

template<typename T>

Vector2<T>& operator+=( Vector2<T> const& v)
    {
        x += y.x; y += v.y;
        return *this;
    }

template<typename T>

Vector2<T>& operator+=( Vector2<T> const& a, Vector2<T> const& b )
    {
        return Vector2<T>{a.x + b.x, a.y + b.y};
    }

int main()
{
    
}
