// CubeSolver.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include <iostream>
#include "Cube/Cube3D.h"
#include "View/ViewerTerminal.h"



int main()
{

    CubeState resolu(
        {0,1,2,3,4,5,6,7,8,9,10,11},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,2,3,4,5,6,7},
        {0,0,0,0,0,0,0,0}
    );

    Cube3D cube;
    cube.setFromState(resolu);

    ViewerTerminal view = ViewerTerminal(&cube);
    view.drawCube();

    Cube3D cube2;
    cube2.setFromState(resolu.applyMove(U2));
    ViewerTerminal view2 = ViewerTerminal(&cube2);
    view2.drawCube();

}

