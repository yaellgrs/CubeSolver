#include "Model/Kociemba.hpp"

#include <iostream>

#include "../../include/Model/CubeState.h"
#include "Utility/Utility.h"


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
    for (int i = cubeState->rotation_arrete.size() - 1; i >= 0; i--) {
        res += (puissance_2 * cubeState->rotation_arrete[i]);
        puissance_2 *= 2;
    }
    return res;
}

int slice(CubeState* cubeState){
    int renvoie = 0;
    std::array<int, 4> retenir = {};
    std::array<int, 4> valeur_a_rechercher = {4, 5, 6, 7};
    int j = 0;
    for (int i = 0; i < cubeState->permutation_arrete.size(); i++) {
        for (auto recherche : valeur_a_rechercher) {
            if (recherche == cubeState->permutation_arrete[i]) {
                retenir[j] = i;
                j++;
            }
        }
    }

    for (int i = 0; i < retenir.size(); i++) {
        int k = i + 1;
        if (retenir[i] >= i+1) {
            renvoie += (factorielle(retenir[i]) / (factorielle(k) * factorielle(retenir[i] - k)));

        }



    }

    return renvoie;

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

std::array<int , 4> slice(int code) {
    std::array<int, 4> resultat = {};
    for (int k = 4; k >= 1; k--) {
        
    }
}




