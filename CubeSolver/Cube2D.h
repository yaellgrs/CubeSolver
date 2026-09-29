#pragma once

#include "ICube.h"


class Cube2D : public ICube {
private:
	//corners
	std::array<int, 8> m_cornerOrientation{};//0 a 2
	std::array<int, 8> m_cornerPermutation;

public:
	Cube2D() : ICube(2) {
		for (int i = 0; i < 8; i++) {
			m_cornerPermutation[i] = i;
		}
	}

	virtual CubeColor getSticker(Face face, int row, int col) const override;
	CubeColor getColor(int piece, int orientation, int face) const;
	
private:
	int getCorner(Face face, int row, int col) const;

};