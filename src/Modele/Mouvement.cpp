#include "Mouvement.hpp"

#include <list>
#include <vector>

std::array<MoveDefinition, 18> buildMoveTable(){
    std::array<MoveDefinition, 18> moveTable;
    moveTable[U] =  MoveDefinition{{1,2,3,0,4,5,6,7,8,9,10,11}, {0,0,0,0,0,0,0,0,0,0,0,0}, {1,2,3,0,4,5,6,7}, {0,0,0,0,0,0,0,0} }; // U
    moveTable[D] =  MoveDefinition{{0,1,2,3,7,4,5,6,8,9,10,11}, {0,0,0,0,0,0,0,0,0,0,0,0}, {0,1,2,3,7,4,5,6}, {0,0,0,0,0,0,0,0}}; //D
    moveTable[B] = MoveDefinition{{0,1,10,3,4,5,11,7,8,9,6,2}, {0,0,1,0,0,0,1,0,0,0,1,1}, {0,5,1,3,4,6,2,7}, {0,1,2,0,0,2,1,0}}; // B
    moveTable[F] = MoveDefinition{{9,1,2,3,8,5,6,7,0,4,10,11}, {1,0,0,0,1,0,0,0,1,1,0,0}, {3,1,2,7,0,5,6,4}, {2,0,0,1,1,0,0,2}}; // F
    moveTable[L] = MoveDefinition{{0,1,2,11,4,5,6,9,8,3,10,7}, {0,0,0,0,0,0,0,0,0,0,0,0}, {0,1,6,2,4,5,7,3}, {0,0,1,2,0,0,2,1}}; // L
moveTable[R] = MoveDefinition{{0,8,2,3,4,10,6,7,5,9,1,11}, {0,0,0,0,0,0,0,0,0,0,0,0}, {4,0,2,3,5,1,6,7}, {1,2,0,0,2,1,0,0}}; // R

    std::vector<Mouvement> liste = {U, D, B, F, L, R};
    std::vector<Mouvement> liste_2 = {U2, D2, B2, F2, L2, R2};
    std::vector<Mouvement> liste_prime = {U_PRIME, D_PRIME, B_PRIME, F_PRIME, L_PRIME, R_PRIME};


    //Pour initialiser ...2
    std::array<int, 12> edge_perm_2;
    std::array<int, 12> edge_orientation_delta_2;
    std::array<int, 8> corner_perm_2;
    std::array<int, 8> corner_orientation_delta_2;

    //Pour initialiser ...PRIME
    std::array<int, 12> edge_perm_prime;
    std::array<int, 12> edge_orientation_delta_prime;
    std::array<int, 8> corner_perm_prime;
    std::array<int, 8> corner_orientation_delta_prime;

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 12; j++){

            //Initialisation de ...2
            edge_perm_2[j] = moveTable[liste[i]].edge_perm[moveTable[liste[i]].edge_perm[j]];
            edge_orientation_delta_2[j] = (moveTable[liste[i]].edge_orientation_delta[moveTable[liste[i]].edge_perm[j]] + moveTable[liste[i]].edge_orientation_delta[j]) % 2;
        }
            //Initialisation de ...PRIME
            // edge_perm_prime[j] = moveTable[liste_2[i]].edge_perm[moveTable[liste[i]].edge_perm[j]];


        for(int j = 0; j < 8; j++){
            corner_perm_2[j] = moveTable[liste[i]].corner_perm[moveTable[liste[i]].corner_perm[j]];
            corner_orientation_delta_2[j] = (moveTable[liste[i]].corner_orientation_delta[moveTable[liste[i]].corner_perm[j]] + moveTable[liste[i]].corner_orientation_delta[j]) % 3;

        }

        moveTable[liste_2[i]] = MoveDefinition{edge_perm_2, edge_orientation_delta_2, corner_perm_2, corner_orientation_delta_2};

        for(int j = 0; j < 12; j++){
            edge_perm_prime[j] = moveTable[liste_2[i]].edge_perm[moveTable[liste[i]].edge_perm[j]];
            edge_orientation_delta_prime[j] = (moveTable[liste_2[i]].edge_orientation_delta[moveTable[liste[i]].edge_perm[j]] + moveTable[liste[i]].edge_orientation_delta[j]) % 2;
        }

        for(int j = 0; j < 8; j++){
            corner_perm_prime[j] = moveTable[liste_2[i]].corner_perm[moveTable[liste[i]].corner_perm[j]];
            corner_orientation_delta_prime[j] = (moveTable[liste_2[i]].corner_orientation_delta[moveTable[liste[i]].corner_perm[j]] + moveTable[liste[i]].corner_orientation_delta[j]) % 3;

        }
        moveTable[liste_prime[i]] = MoveDefinition{edge_perm_prime, edge_orientation_delta_prime, corner_perm_prime, corner_orientation_delta_prime};

    }
    return moveTable;

}

const std::array<MoveDefinition, 18>& getMoveTable() {
    static std::array<MoveDefinition, 18> table = buildMoveTable();
    return table;
}







