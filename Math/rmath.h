#ifndef RMATH_H
#define RMATH_H
#include <math.h>
#define PI 3.1415926535897932f

struct RMath{

    //PI
    //static const float PI = 3.1415926535897932f;
    static const float INV_PI = 0.31830988618f;
    static const float HALF_PI = 1.57079632679f;

    inline static float Sqrt(float i){
        return sqrtf(i);
    }

    inline static float Invert(float i){
        return (1.0f / i);
    }

    inline static float Sin(float i){

        return sinf(i);
    }

    inline static float Cos(float i){
        return cosf(i);
    }

    inline static float Tan(float i){
         return tanf(i);
    }

    inline static float Mod(float i,float k){
        return modf(i,k);
    }

    static inline void SinCos( float* ScalarSin, float* ScalarCos, float  Value )
        {
            // Map Value to y in [-pi,pi], x = 2*pi*quotient + remainder.
            float quotient = (INV_PI*0.5f)*Value;
            if (Value >= 0.0f)
            {
                quotient = (float)((int)(quotient + 0.5f));
            }
            else
            {
                quotient = (float)((int)(quotient - 0.5f));
            }
            float y = Value - (2.0f*PI)*quotient;

            // Map y to [-pi/2,pi/2] with sin(y) = sin(Value).
            float sign;
            if (y > HALF_PI)
            {
                y = PI - y;
                sign = -1.0f;
            }
            else if (y < -HALF_PI)
            {
                y = -PI - y;
                sign = -1.0f;
            }
            else
            {
                sign = +1.0f;
            }

            float y2 = y * y;

            // 11-degree minimax approximation
            *ScalarSin = ( ( ( ( (-2.3889859e-08f * y2 + 2.7525562e-06f) * y2 - 0.00019840874f ) * y2 + 0.0083333310f ) * y2 - 0.16666667f ) * y2 + 1.0f ) * y;

            // 10-degree minimax approximation
            float p = ( ( ( ( -2.6051615e-07f * y2 + 2.4760495e-05f ) * y2 - 0.0013888378f ) * y2 + 0.041666638f ) * y2 - 0.5f ) * y2 + 1.0f;
            *ScalarCos = sign*p;
    }
};
#endif // RMATH_H
