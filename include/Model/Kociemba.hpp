#ifndef Kociemba_H
#define Kociemba_H
#include "CubeState.h"
#include "Utility/Utility.h"


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




#endif
