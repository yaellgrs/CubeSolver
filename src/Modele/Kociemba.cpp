#include "Model/Kociemba.hpp"

#include <iostream>

#include "../../include/Model/CubeState.h"


/*
 *  CODE
 */

int coord_twist(CubeState* cubeState) {
    int res = 0;
    int puissance_3 = 1;
    for (int i = cubeState->rotation_corner.size() - 1; i >= 0; i--) {
        res += (puissance_3 * cubeState->rotation_corner[i]);
        puissance_3 *= 3;


    }
    return res;

}

int coord_flip(CubeState* cubeState) {
    int res = 0;
    int puissance_2 = 1;
    for (int i = cubeState->rotation_corner.size() - 1; i >= 0; i--) {
        res += (puissance_2 * cubeState->rotation_corner[i]);
        puissance_2 *= 2;
    }
    return res;
}

/*
 * DECODE
 */

std::array<int,8> coord_twist(int code) {
    std::array<int, 8> rotation_corner{};
    int cp_code = code;
    for(int i = rotation_corner.size() - 1; i >= 0; i--) {
        rotation_corner[i] = cp_code % 3;
        cp_code /=  3;
    }
    return rotation_corner;

}

std::array<int,12> coord_flip(int code) {
    std::array<int, 12> rotation_arrete{};
    int cp_code = code;
    for(int i = rotation_arrete.size() - 1; i >= 0; i--) {
        rotation_arrete[i] = cp_code % 2;
        cp_code /=  2;
    }
    return rotation_arrete;

}


