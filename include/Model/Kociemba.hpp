#ifndef Kociemba_H
#define Kociemba_H
#include "CubeState.h"
#include "Utility/Utility.h"
#include <set>


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

//Code en base 3 (pour + d'espace) la rotation des coins
int coord_twist(CubeState* cubeState);
//Code en base 2 (pour + d'espace) la rotation des arretes
int coord_flip(CubeState* cubeState);
//Code des arretes FL, FR, BR, BL
int slice(CubeState* cubeState);
//Code lehmer

template<std::size_t N>
int coord_perm(const std::array<int, N> &tab) {
        int resultat = 0;
        int taille_tab = tab.size();
        int count;
        for (int i = 0; i < tab.size()-1; i++) {
            count = 0;
            for (int j = i+1; j < tab.size(); j++) {
                if (tab[i] > tab[j]) {
                    count++;
                }else {
                    break;
                }

            }
            resultat += (count * factorielle(tab.size() - 1 - i));
        }
        return resultat;
}


//Decode la rotation des coins
std::array<int,8> coord_twist(int code);
//Decode la rotaion des arretes
std::array<int,12> coord_flip(int code);
//Decode des arretes FL, FR, BR, BL
std::array<int , 4> slice(int code);
//Decode code de lehmer
template<std::size_t N>
std::array<int, N> coord_perm(int v) {
    std::vector<int> recherche = {};
    std::array<int, N> resultat = {};
    int fact = 0;
    for (int i = 0; i < N; i++) {
        fact = factorielle(N-1-i);
        resultat[i] = v / fact;
        v = v % fact;
        recherche.push_back(i);

    }

    bool is_in = false;
    for (int i : recherche) {
        for (int j : resultat) {
            if (i == j) {
                is_in = true;
                break;
            }
        }

        if (!is_in) {
            resultat[N - 1] = i;
            break;
        }

        is_in = false;
    }

    return resultat;
}

// ============================================================
// 2. PRÉCALCUL (une seule fois, au démarrage)
// ============================================================






#endif
