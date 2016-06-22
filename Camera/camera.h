#ifndef CAMERA_H
#define CAMERA_H
#include "./Math/Vector3.h"
#include "./Math/Rotator.h"
#include "../defines.h"
#include "../Renderer/Ray.h"
struct Camera{

    Vector3 Position;
    Rotator Rotation;

    Vector3 UpVector;
    Vector3 RightVector;

    uint ResolutionWidth;
    uint ResolutionHeight;

    virtual Ray GetRay(uint x, uint y);
};
#endif // CAMERA_H
