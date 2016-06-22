#ifndef QUATERNION_H
#define QUATERNION_H

#include "Vector3.h"
struct Quaternion{

      float X;
      float Y;
      float Z;
      float W;

      //default Constructor
      Quaternion():X(0.0f),Y(0.0f),Z(0.0f),W(1.0f){}

      //Constructor
      Quaternion(float InX, float InY, float InZ, float InW):X(InX),Y(InY),Z(InZ),W(InW){}

      //From Euler Angles
      Quaternion(float InAngleX,float InAngleY,float InAngleZ);

      //From Euler Angles
      Quaternion(Vector3 V);

      bool operator==(const Quaternion& Other) const;

      bool operator!=(const Quaternion& Other) const;

      Quaternion operator+ (const Quaternion& Other) const;

      Quaternion operator- (const Quaternion& Other) const;

      Quaternion operator* (const Quaternion& Other) const;

      Quaternion operator/ (const Quaternion& Other) const;

      void set(float InX, float InY, float InZ);

};


inline Quaternion::Quaternion(Vector3 V){
              set(V.X,V.Y,V.Z);
}

inline Quaternion::Quaternion(float InAngleX, float InAngleY, float InAngleZ){
    set(InAngleX,InAngleY, InAngleZ);
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


#endif // QUATERNION_H
