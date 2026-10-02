// CubeSolver.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include <iostream>
#include "Cube/Cube3D.h";
#include "View/ViewerTerminal.h"



int main()
{
    Cube3D cube;
    ViewerTerminal view = ViewerTerminal(&cube);
    view.drawCube();
}

