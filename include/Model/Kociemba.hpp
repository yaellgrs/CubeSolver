#ifndef Kociemba_H
#define Kociemba_H
#include "CubeState.h"


//Code en base 3 (pour + d'espace) la rotation des coins
int coord_twist(CubeState* cubeState);
//Code en base 2 (pour + d'espace) la rotation des arretes
int coord_flip(CubeState* cubeState);
//Code des arretes FL, FR, BR, BL
int slice(CubeState* cubeState);

//Decode la rotation des coins
std::array<int,8> coord_twist(int code);
//Decode la rotaion des arretes
std::array<int,12> coord_flip(int code);




#endif
