#ifndef MATRIX44_H
#define MATRIX44_H

class Matrix44{

float M[4][4];

inline Matrix44& operator*(Matrix44 M);

inline Matrix44& operator+(Matrix44 M);


};

#endif // MATRIX44_H
