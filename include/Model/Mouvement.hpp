#ifndef Mouvement_H
#define Mouvement_H

#include "CubeState.h"

#include <iostream>
#include <vector>
#include <map>
#include <array>

enum Mouvement {U, U2, U_PRIME, D, D2, D_PRIME, B, B2, B_PRIME, L, L2, L_PRIME, R, R2, R_PRIME, F, F2, F_PRIME};
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

std::array<MoveDefinition, 18> buildMoveTable();

const std::array<MoveDefinition, 18>& getMoveTable();

#endif