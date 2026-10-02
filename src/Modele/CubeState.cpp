#include "Model/CubeState.h"

CubeState::CubeState(std::array<int, 12> permutation_arrete, std::array<int, 12> rotation_arrete, std::array<int, 8> permutation_corner, std::array<int, 8> rotation_corner) : permutation_arrete(permutation_arrete),  rotation_arrete(rotation_arrete), permutation_corner(permutation_corner), rotation_corner(rotation_corner){

}

CubeState::~CubeState() = default;

CubeState CubeState::applyMove(Mouvement m){
    
    std::array<int, 12> new_permutation_arretes= this->permutation_arrete;
    std::array<int, 12> new_rotation_arretes = this->rotation_arrete;

    std::array<int, 8> new_permutation_angles = this->permutation_corner;
    std::array<int, 8> new_rotation_angles = this->rotation_corner;
       
    if(m == U){   
        MoveDefinition MoveDefinition = {

        };
        //Changement arretes
        int UF = new_permutation_arretes[0];
        int UR = new_permutation_arretes[1];
        int UB = new_permutation_arretes[2];
        int UL = new_permutation_arretes[3];

        new_permutation_arretes[0] = UL;
        new_permutation_arretes[1] = UF;
        new_permutation_arretes[2] = UR;
        new_permutation_arretes[3] = UB;

        //Changement corner
        int UFL = new_permutation_angles[0];
        int UFR = new_permutation_angles[1];
        int UBR = new_permutation_angles[2];
        int UBL = new_permutation_angles[3];

        new_permutation_angles[0] = UBL;
        new_permutation_angles[1] = UFL;
        new_permutation_angles[2] = UFR;
        new_permutation_angles[3] = UBR;

        return CubeState(new_permutation_arretes, new_rotation_arretes, new_permutation_angles, new_rotation_angles);
                
    }

    if(m == U2){
        //Changement arretes
        int UF = new_permutation_arretes[0];
        int UR = new_permutation_arretes[1];
        int UB = new_permutation_arretes[2];
        int UL = new_permutation_arretes[3];

        new_permutation_arretes[0] = UL;
        new_permutation_arretes[1] = UF;
        new_permutation_arretes[2] = UR;
        new_permutation_arretes[3] = UB;

        //Changement corner
        int UFL = new_permutation_angles[0];
        int UFR = new_permutation_angles[1];
        int UBR = new_permutation_angles[2];
        int UBL = new_permutation_angles[3];

        new_permutation_angles[0] = UBL;
        new_permutation_angles[1] = UFL;
        new_permutation_angles[2] = UFR;
        new_permutation_angles[3] = UBR;

        return CubeState(new_permutation_arretes, new_rotation_arretes, new_permutation_angles, new_rotation_angles);
    }
}

