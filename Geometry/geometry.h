#ifndef GEOMETRY_H
#define GEOMETRY_H

class Geometry{

public:

    Vector3 Position;
    Vector3 Scale;
    Rotator Rotation;

    Geometry();
    virtual ~Geometry();

    virtual void IntersectRay(Ray r, IntersectInfo Info);
};

#endif // GEOMETRY_H
