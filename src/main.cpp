// CubeSolver.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include <iostream>

#include "Kociemba.hpp"
#include "Cube/Cube3D.h"
#include "View/ViewerTerminal.h"
#include "Utility/Utility.h"



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
        {0,1,2,3,4,5,6,7,8,9,10,11},
        {0,0,0,0,0,0,0,0,0,0,0,0},
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
    return 0;


}

