#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <array>

enum class CubeColor {White,Red,Blue,Orange,Green,Yellow};

enum Corners {UFR ,URB ,UBL ,ULF ,DFR ,DRB ,DBL ,DLF };

enum class Face {D,F,L,B,R,U};

struct CornerPosition { Face face[3]; };

inline const std::array<std::array<CubeColor, 3>, 8> cornerColors =
{ {
    { CubeColor::Yellow, CubeColor::Red,    CubeColor::Green  }, 
    { CubeColor::Yellow, CubeColor::Green,  CubeColor::Orange }, 
    { CubeColor::Yellow, CubeColor::Orange, CubeColor::Blue   }, 
    { CubeColor::Yellow, CubeColor::Blue,   CubeColor::Red    }, 
    { CubeColor::White,  CubeColor::Green,  CubeColor::Red    }, 
    { CubeColor::White,  CubeColor::Orange, CubeColor::Green  }, 
    { CubeColor::White,  CubeColor::Blue,   CubeColor::Orange },
    { CubeColor::White,  CubeColor::Red,    CubeColor::Blue   }  
} };


class ICube {
private:
	int order;// dimension du cube (3 pour un cube 3x3x3)

public:
	ICube(int order) {
		this->order = std::max(2, order);
	}

	//renvoie la couleur a la position (row;col) de la face ex (1;1) de la face jaune vaut jaune sur un 3x3
	virtual CubeColor getSticker(Face face, int row, int col) const = 0;



};