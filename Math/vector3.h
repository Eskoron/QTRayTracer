#ifndef VECTOR3_H
#define VECTOR3_H

#include "RMath.h"

struct Vector3{

    float X;
    float Y;
    float Z;


    Vector3(){
        X = 0;
        Y = 0;
        Z = 0;
    }

    Vector3(float InX, float InY, float InZ){
        X = InX;
        Y = InY;
        Z = InZ;
    }

    //return squared size of the vector
    inline float SizeSquared() const{
        return (X*X + Y*Y + Z*Z);
    }


    //returns size of the vector
    inline float Size() const{
        return RMath::Sqrt(SizeSquared());
    }

    //calculates normal without checking for 0
    inline Vector3& UnsafeNormal(){
        float InvertedLength = RMath::Invert(Size());
        X /= InvertedLength;
        Y /= InvertedLength;
        Z /= InvertedLength;
        return *this;
    }


};

#endif // VECTOR3_H
