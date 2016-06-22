#ifndef QUATERNION_H
#define QUATERNION_H

#include "rotator.h"
#include "matrix44.h"
struct Quaternion{

      float X;
      float Y;
      float Z;
      float W;

      //default Constructor
      inline Quaternion():X(0.0f),Y(0.0f),Z(0.0f),W(1.0f){}

      //Constructor
      inline Quaternion(float InX, float InY, float InZ, float InW):X(InX),Y(InY),Z(InZ),W(InW){}

      explicit inline Quaternion(Rotator r);

      explicit inline  Quaternion(Matrix44 M);

      inline bool operator==(const Quaternion& Other) const;

      inline bool operator!=(const Quaternion& Other) const;

      inline Quaternion operator+ (const Quaternion& Other) const;

      inline Quaternion operator- (const Quaternion& Other) const;

      inline Quaternion operator* (const Quaternion& Other) const;

      inline Quaternion operator/ (const Quaternion& Other) const;

      inline Quaternion operator+= (const Quaternion& Other);

      inline Quaternion& set(float InX, float InY, float InZ);

      Matrix44 ToRotationMatrix() const;

      Quaternion& Inverse();

      Quaternion& Normalize();
};

explicit inline Quaternion::Quaternion(Rotator r){
    *this = r.Quaternion();
}
explicit inline Quaternion::Quaternion(Matrix44 M){


}

inline bool Quaternion::operator ==(const Quaternion& Other) const{
    return ((X == Other.X) &&
            (Y == Other.Y) &&
            (Z == Other.Z) &&
            (W == Other.W));
}

inline bool Quaternion::operator!=(const Quaternion& Other) const
{
    return !(*this == other);
}

inline void Quaternion::Normalize(){


}

inline Quaternion& Quaternion::set(float InX, float InY, float InZ){
    float angle = X * 0.5f;
    const float sr = RMath::Sin(angle);
    const float

}

inline Matrix33 Quaternion::ToRotationMatrix(){

    Matrix33 m;
    const float tx = 2.0f * X;
    const float ty = 2.0f * Y;
    const float tz = 2.0f * Z;
    const float twx = tx * W;
    const float twy = ty *W;
    const float twz  = tz * W;
    const float txx = tx *x;
    const float tyy = ty *y;
    const float tzz = tz *z;

    m.set(0,0,1.0f-(tyy+tzz));
}


#endif // QUATERNION_H
