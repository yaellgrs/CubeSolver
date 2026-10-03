#ifndef CubeState_H
#define CubeState_H

#include <iostream>
#include <vector>
#include <map>
#include <array>
#include "Mouvement.hpp"



struct MoveDefinition {
    std::array<int, 12> edge_perm;
    std::array<int, 12> edge_orientation_delta;
    std::array<int, 8> corner_perm;
    std::array<int, 8> corner_orientation_delta;
};

class CubeState{
    public :
    //arrete
    std::array<int, 12> permutation_arrete{};
    //Avec la face bleu devant
    //[UF=0, UR=1, UB=2, UL=3 , FL= 4, FR = 5, BR = 6, BL = 7, DF = 8, DR = 9, DB = 10, DL = 11]
    std::array<int, 12> rotation_arrete{};

    //corner
    std::array<int, 8> permutation_corner{};
    std::array<int, 8> rotation_corner{};

    CubeState(std::array<int, 12> permutation_arrete, std::array<int, 12> rotation_arrete, std::array<int, 8> permutation_corner, std::array<int, 8> rotation_corner);
    ~CubeState();

    CubeState applyMove(Mouvement m);








};

#endif