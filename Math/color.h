#ifndef COLOR_H
#define COLOR_H

class Color{
public:
    char Red;
    char Green;
    char Blue;
    char Alpha;

    Color():Red(0),Green(0),Blue(0),Alpha(0){}

    Color(char* RGBA):Red(RGBA[0]),Green(RGBA[1],Blue(RGBA[2]),Alpha(RGBA[3]){}

    Color(Vector3 V):Red(V.X),Green(V.Y),Blue(V.Z),Alpha(0){}

}
#endif // COLOR_H
