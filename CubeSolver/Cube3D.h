#pragma once

#include "ICube.h"


class Cube3D : public ICube {
private:
	//corners
	std::array<int, 8> m_cornerOrientation{};//0 a 2
	std::array<int, 8> m_cornerPermutation;//(0->ordre^3 - 1 ),(0->ordre^3 - 1) 

	//edges
	std::array<int, 12> m_edgeOrientation{ };//0 a 2
	std::array<int, 12> m_edgePermutation;//(0->ordre^3 - 1 ),(0->ordre^3 - 1)  
public:
	Cube3D() : ICube(3) {
		for (int i = 0; i < 8; i++) {
			m_cornerPermutation[i] = i;
		}
		for (int i = 0; i < 12; i++) {
			m_edgePermutation[i] = i;
		}
	}
	virtual CubeColor getSticker(Face face, int row, int col) const override;

private:
	bool isCorner(int row, int col) const;
	int getEdge(Face face, int row, int col) const;
};