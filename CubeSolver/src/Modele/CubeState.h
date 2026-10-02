#ifndef CubeState_H
#define CubeState_H

#include <iostream>
#include <vector>
#include <map>
#include <array>

enum Mouvement {U, U2, U_PRIME, D, D2, D_PRIME, B, B2, B_PRIME, L, L2, L_PRIME, R, R2, R_PRIME};
//u -> up
//d -> down
//b -> back
//r -> right
//l -> left

//"..."_PRIME -> sens anti horaire
//"..."2 -> 2 tour horaire

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
    //[UF -> blanc/bleu, UR, UB, UL, FR -> BLEU/orange, BR -> ORANGE / vert, FL, BL, DF -> bleu jaune, DR, DB, DL]
    std::array<int, 12> rotation_arrete{};

    //corner
    std::array<int, 8> permutation_corner{};
    std::array<int, 8> rotation_corner{};

    CubeState(std::array<int, 12> permutation_arrete, std::array<int, 12> rotation_arrete, std::array<int, 8> permutation_corner, std::array<int, 8> rotation_corner);
    ~CubeState();

    CubeState applyMove(Mouvement m);








};

#endif