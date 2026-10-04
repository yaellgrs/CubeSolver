#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <span>
#include <cassert> 
#include "CubeUtility.h"

class ICube {
private:
	int order;// dimension du cube (3 pour un cube 3x3x3)

public:
	ICube(int order) {
		this->order = std::max(2, order);
	}

	//renvoie la couleur a la position (row;col) de la face ex (1;1) de la face jaune vaut jaune sur un 3x3
	virtual CubeColor getSticker(Face face, int row, int col) const = 0;

protected:
    CubeColor getColor(int piece, int orientation, int face, std::span<const CubeColor> colors) const;
    virtual int getCorner(Face face, int row, int col) const;

public:
	int getOrder() const { return order; }


};