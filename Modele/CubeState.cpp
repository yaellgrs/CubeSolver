#include "CubeState.h"

CubeState::CubeState(std::array<int, 12> permutation_arrete, std::array<int, 12> rotation_arrete, std::array<int, 8> permutation_corner, std::array<int, 8> rotation_corner) : permutation_arrete(permutation_arrete),  rotation_arrete(rotation_arrete), permutation_corner(permutation_corner), rotation_corner(rotation_corner){

}

CubeState::~CubeState() = default;



