#ifndef SPHERE_H
#define SPHERE_H
#include "geometry.h"
struct Sphere : Geometry{

    void IntersectRay(Ray R, IntersectInfo Info);
};
#endif // SPHERE_H
