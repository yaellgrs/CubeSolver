#pragma once

#include "ICube.h"


class Cube3D : public ICube {

	//corners
	std::array<int, 8> cornerOrientation{};//0 a 2
	std::map<int, int> cornerPermutation;//(0->ordre^3 - 1 ),(0->ordre^3 - 1) 

	//edges
	std::vector<int> edgeOrientation;//0 a 2
	std::map<int, int> edgePermutation;//(0->ordre^3 - 1 ),(0->ordre^3 - 1)  

	Cube3D(int order) : ICube(order) {

	}
};