#ifndef RMATH_H
#define RMATH_H
#include <math.h>


struct RMath{

    inline static float Sqrt(float i){
        return sqrtf(i);
    }

    inline static float Invert(float i){
        return (1.0f / i);
    }

};
#endif // RMATH_H
