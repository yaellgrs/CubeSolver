#include "Model/CubeState.h"

CubeState::CubeState(std::array<int, 12> permutation_arrete, std::array<int, 12> rotation_arrete, std::array<int, 8> permutation_corner, std::array<int, 8> rotation_corner) : permutation_arrete(permutation_arrete),  rotation_arrete(rotation_arrete), permutation_corner(permutation_corner), rotation_corner(rotation_corner){

}

CubeState::~CubeState() = default;

CubeState CubeState::applyMove(Mouvement m) const{
    
    std::array<int, 12> new_permutation_arrete;
    std::array<int, 12> new_rotation_arrete;
    std::array<int, 8> new_permutation_corner;
    std::array<int, 8> new_rotation_corner;
    const auto MoveTable = getMoveTable()[m];

    for(int i = 0; i < 12; i++){
        new_permutation_arrete[i] = this->permutation_arrete[MoveTable.edge_perm[i]];
        new_rotation_arrete[i] = (this->rotation_arrete[MoveTable.edge_perm[i]] + MoveTable.edge_orientation_delta[i]) % 2;
    }

    for(int i = 0; i < 8; i++){
        new_permutation_corner[i] = this->permutation_corner[MoveTable.corner_perm[i]];
        new_rotation_corner[i] = (this->rotation_corner[MoveTable.corner_perm[i]] + MoveTable.corner_orientation_delta[i]) % 3;
    }

    return CubeState(new_permutation_arrete, new_rotation_arrete, new_permutation_corner, new_rotation_corner);

}


