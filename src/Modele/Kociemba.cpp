#include "Model/Kociemba.hpp"

#include <iostream>

#include "../../include/Model/CubeState.h"
#include "Utility/Utility.h"


// ============================================================
// 1. COORDONNÉES (un état du cube = quelques entiers)
// ============================================================
// PHASE 1                                          nb de valeurs
//   twist : orientation des 8 coins                3^7    = 2 187  (le 8e est déduit)
//   flip  : orientation des 12 arêtes              2^11   = 2 048  (la 12e est déduite)
//   slice : emplacements des 4 arêtes de tranche   C(12,4) =   495  (sans leur ordre)
//   but   : twist = 0, flip = 0, slice = slice_resolu
//
// PHASE 2 (valables seulement dans G1)
//   cp    : permutation des 8 coins                 8! = 40 320
//   ep8   : permutation des 8 arêtes hors tranche   8! = 40 320
//   sp    : permutation des 4 arêtes de la tranche  4! =     24
//   but   : cp = 0, ep8 = 0, sp = 0  (cube résolu)


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

    // POUR DEBUGUER 
    // std::string debug = "{";
    //
    //
    // for (auto oui : retenir) {
    //     debug += std::to_string(oui);
    //     debug += " - ";
    // }
    //
    // debug += "fin}";
    //
    // std::cout << debug << std::endl;

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
    std::vector<std::vector<int>> triangle =  triangle_pascal(12, 4);
    int i = 0;
    for (int k = 4; k >= 1; k--) {
        int start = 0;
        int end = 12;
        int mid = (start + end) / 2;
        while(true) {
            if (mid < k) {
                resultat[i] = 0;
                i++;
                break ;
            }
            if (triangle[mid][k] > code) {
                end = mid;
            }
            if (triangle[mid][k] <= code) {
                if (mid == 12) {
                    resultat[i] = mid;
                    code -= triangle[mid][k];
                    i++;
                    break;
                }
                if (triangle[mid+1][k] <= code) {
                    start = mid;
                } else {
                    resultat[i] = mid;
                    code -= triangle[mid][k];
                    i++;
                    break;

                }


            }
            mid = (start + end) / 2;



        }


    }
    return resultat;
}


// ============================================================
// 2. PRÉCALCUL (une seule fois, au démarrage)
// ============================================================






