#ifndef ROTATOR_H
#define ROTATOR_H
#include "quaternion.h"
#include "rmath.h"
struct Rotator{


    //RRotation around the right axis(Y)
    float Pitch;

    //Rotation around the up axis(Z)
    float Yaw;

    //Rotationa round the foward axis(X)
    float Roll;


    inline Rotator():Pitch(0.0f),Yaw(0.0f),Roll(0.0f){}

    explicit inline Rotator(float InF):Pitch(InF),Yaw(InF),Roll(InF){

    }

    inline Rotator(float InPitch, float InYaw, float InRoll):Pitch(InPitch),Yaw(InYaw),Roll(InRoll){}

    inline Rotator(Quaternion Q);

public:

    inline Rotator operator+(const Rotator& R) const;
    inline Rotator operator-(const Rotator& R) const;
    inline Rotator operator*(float Scale) const;

    inline Rotator operator+=(const Rotator& R);
    inline Rotator operator-=(const Rotator& R);
    inline Rotator operator*=(float Scale);

    inline bool operator==(const Rotator R) const;
    inline bool operator!=(const Rotator R) const;

    inline Rotator Add(float DeltaPitch, float DeltaYaw, float DeltaRoll);

    inline void Inverse();

    inline void Normalize();

    inline float NormalizeAxis( float Angle );

    inline Vector3 Vector() const;

    inline Vector3 Euler() const;

    inline Quaternion Quaternion();

    RotateVector(const Vector3& V) const;

    UnrotateVector(const Vector3& V) const;

    Rotator Clamp() const;

    inline float ClampAxis(float Angle) const;

};


inline Rotator Rotator::operator+(const Rotator& R) const{
    return Rotator(Pitch+R.Pitch,Yaw+R.Yaw,Roll+R.Roll);
}

inline Rotator Rotator::operator-(const Rotator& R) const{
    return Rotator(Pitch-R.Pitch,Yaw-R.Yaw,Roll-R.Roll);
}

inline Rotator Rotator::operator*(float Scale) const{
    return Rotator(Pitch*Scale, Yaw*Scale, Roll*Scale);
}

inline Rotator Rotator::operator+=(const Rotator& R){
    Pitch+=R.Pitch;
    Yaw += R.Yaw;
    Roll += R.Roll;
    return *this;
}
inline Rotator Rotator::operator-=(const Rotator& R){
    Pitch-=R.Pitch;
    Yaw -= R.Yaw;
    Roll -= R.Roll;
    return *this;
}

inline Rotator Rotator::operator*=(float Scale){
    Pitch *= Scale;
    Yaw *= Scale;
    Roll *= Scale;
    return *this;
}

inline bool Rotator::operator==(const Rotator R) const{

    return Pitch==R.Pitch && Yaw==R.Raw && Roll == R.Roll;
}

inline bool Rotator::operator!=(const Rotator R) const{
    return Pitch!=R.Pitch || Yaw!=R.Yaw || Roll!=R.Roll;
}

inline Rotator Rotator::Add(float DeltaPitch, float DeltaYaw, float DeltaRoll){

    Yaw   += DeltaYaw;
    Pitch += DeltaPitch;
    Roll  += DeltaRoll;
    return *this;
}

inline Rotator Clamp() const{

    return Rotator(ClampAxis(Pitch),ClampAxis(Yaw),ClampAxis(Roll));
}

inline float Rotator::ClampAxis(float Angle) const{

    Angle=RMath::Mod(Angle,360.0f);
    if(Angle<0.f){
        Angle+=360.0f;
    }

    return Angle;
}

inline void Rotator::Normalize(){
    Pitch=NormalizeAxis(Pitch);
    Yaw = NormalizeAxis(Yaw);
    Roll = NormalizeAxis(Roll);
}


inline float Rotator::NormalizeAxis( float Angle )
{
    // returns Angle in the range [0,360)
    Angle = ClampAxis(Angle);

    if (Angle > 180.f)
    {
        // shift to (-180,180]
        Angle -= 360.f;
    }

    return Angle;
}

inline Quaternion Rotator::Quaternion(){

    const float DEG_TO_RAD = RMath::PI/(180.f);
        const float DIVIDE_BY_2 = DEG_TO_RAD/2.f;
        float SP, SY, SR;
        float CP, CY, CR;

        RMath::SinCos(&SP, &CP, Pitch*DIVIDE_BY_2);
        RMath::SinCos(&SY, &CY, Yaw*DIVIDE_BY_2);
        RMath::SinCos(&SR, &CR, Roll*DIVIDE_BY_2);

        Quaternion RotationQuat;
        RotationQuat.X =  CR*SP*SY - SR*CP*CY;
        RotationQuat.Y = -CR*SP*CY - SR*CP*SY;
        RotationQuat.Z = CR*CP*SY - SR*SP*CY;
        RotationQuat.W = CR*CP*CY + SR*SP*SY;
}

#endif // ROTATOR_H
