#include <engine.h>

using namespace be;

template <typename vecT>
Vector2<vecT> operator+(const Vector2<vecT>&a, const Vector2<vecT>&b)
{
    Vector2 <vecT> vector;
    vector.x = b.x + a.x;
    vector.y = a.y + a.y;
    return vector;
}

template <typename vecT>
Vector2<vecT> operator*(const Vector2<vecT>&a, const Vector2<vecT>&b)
{
    Vector2 <vecT> vector;
    vector.x = b.x * a.x;
    vector.y = b.y * a.y;
    return vector;
}

template <typename vecT>
Vector3<vecT> operator+(const Vector3<vecT>&a, const Vector3<vecT>&b)
{
    Vector3 <vecT> vector;
    vector.x = b.x + a.x;
    vector.y = b.y + a.y;
    vector.z = b.z + a.z;
    return vector;
}

template <typename vecT>
Vector3<vecT> operator*(const Vector3<vecT>&a, const Vector3<vecT>&b)
{
    Vector3 <vecT> vector;
    vector.x = b.x * a.x;
    vector.y = b.y * a.y;
    vector.z = b.z * a.z;
    return vector;
}
