// CubeSolver.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include <iostream>

#include "Kociemba.hpp"
#include "Cube/Cube3D.h"
#include "View/ViewerTerminal.h"
#include "Utility/Utility.h"
#include <chrono>



int main()
{
    //
    // CubeState resolu(
    //     {0,1,2,3,4,5,6,7,8,9,10,11},
    //     {0,0,0,0,0,0,0,0,0,0,0,0},
    //     {0,1,2,3,4,5,6,7},
    //     {0,0,0,0,0,0,0,0}
    // );
    //
    // Cube3D cube;
    // cube.setFromState(resolu);
    //
    // ViewerTerminal view = ViewerTerminal(&cube);
    // view.drawCube();
    //
    // Cube3D cube2;
    // cube2.setFromState(resolu.applyMove(U2));
    // ViewerTerminal view2 = ViewerTerminal(&cube2);
    // view2.drawCube();

    CubeState test(
        {4, 1, 2, 5, 0, 7, 3, 6, 8, 9, 10, 11}, // [4, 1, 2, 5, 0, 7, 3, 6, 8, 9, 10, 11]
        {0,0,0,0,1,0,0,1,0,1,1,0}, // 10010110 -> 150
        {0,1,2,3,4,5,6,7},
        {0, 1, 0, 2, 0, 0, 1, 2}
    );
    std::cout << coord_twist(&test) << std::endl;


    std::cout << puissance(3, 7) << std::endl;
    std::array<int, 8> test_1 = coord_twist(896);
    std::string res = "[";
    for (auto a : test_1) {
        res += std::to_string(a);
        res += ";";

    }
    res += "]";
    std::cout << res << std::endl;

    std::cout << coord_flip(&test) << std::endl ;

    std::array<int, 12> test_2 = coord_flip(150);
    res = "[";
    for (auto a : test_2) {
        res += std::to_string(a);
        res += ";";

    }
    res += "]";

    std::cout << res << std::endl;

    std::cout << slice(&test) << std::endl;

    res = "";

    auto debut = std::chrono::high_resolution_clock::now();
    std::vector<std::vector<int>>  resultat = triangle_pascal(12, 4);
    auto fin = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> temps_ecoule = fin - debut;


    for (auto first : resultat) {
        res += "[";
        for (auto second : first) {
            res += std::to_string(second);
            res += " - ";
        }
        res += "]\n";
    }

    std::cout << res << std::endl ;
    std::cout << "Duree fonction triangle pascal = " + std::to_string(temps_ecoule.count()) + " seconde."<< std::endl;

    res = "{";

    std::array<int , 4> caca = slice(48);

    for (auto pipi : caca) {
        res += std::to_string(pipi);
        res += " - ";
    }

    res += " fin }";

    std::cout << res << std::endl;

    return 0;


}

