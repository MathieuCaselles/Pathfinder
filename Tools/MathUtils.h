#include <math.h>

struct Vector2f
{
    Vector2f(float x, float y) :m_x(x), m_y(y) {};

    float m_x; 
    float m_y; 
};

inline float getDistanceBetween2Points(const Vector2f& point1, const Vector2f& point2)
{
    return sqrtf(powf(point2.m_x - point1.m_x, 2) + powf(point2.m_y - point1.m_y, 2));
}