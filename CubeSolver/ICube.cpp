#include "ICube.h"

CubeColor ICube::getColor(int piece, int orientation, int face, std::span<const CubeColor> colors) const
{
	int n = colors.size();

	CubeColor color = colors[orientation % 3];

	if (color == CubeColor::White && face == (int)Face::D) return CubeColor::White;
	if (color == CubeColor::Yellow && face == (int)Face::U) return CubeColor::Yellow;

	for (int i = 0; i < n; ++i)
	{
		CubeColor color = colors[(i + orientation) % n];

		if (color == (CubeColor)face)
			return color;
	}

	return CubeColor::White;
}

int ICube::getCorner(Face face, int row, int col) const
{
	/*
			on prend la face rouge en face et la face blanc vers le bas
			face vers le bas : index 0,0 devant a gauche
			face sue le coté : index 0,0 en haut a gauche
	*/

	int i = this->order - 1;

	switch ((Face)face) {
	case Face::U:
		if (row == 0 && col == 0) return Corners::ULF;
		if (row == 0 && col == i) return Corners::UFR;
		if (row == i && col == 0) return Corners::UBL;
		if (row == i && col == i) return Corners::URB;
		break;
	case Face::D:
		if (row == 0 && col == 0) return Corners::DLF;
		if (row == 0 && col == i) return Corners::DFR;
		if (row == i && col == 0) return Corners::DBL;
		if (row == i && col == i) return Corners::DRB;
		break;
	case Face::F:
		if (row == 0 && col == 0) return Corners::ULF;
		if (row == 0 && col == i) return Corners::UFR;
		if (row == i && col == 0) return Corners::DLF;
		if (row == i && col == i) return Corners::DFR;
		break;
	case Face::B:
		if (row == 0 && col == 0) return Corners::URB;
		if (row == 0 && col == i) return Corners::UBL;
		if (row == i && col == 0) return Corners::DRB;
		if (row == i && col == i) return Corners::DBL;
		break;
	case Face::L:
		if (row == 0 && col == 0) return Corners::UBL;
		if (row == 0 && col == i) return Corners::ULF;
		if (row == i && col == 0) return Corners::DBL;
		if (row == i && col == i) return Corners::DLF;
		break;
	case Face::R:
		if (row == 0 && col == 0) return Corners::UFR;
		if (row == 0 && col == i) return Corners::URB;
		if (row == i && col == 0) return Corners::DFR;
		if (row == i && col == i) return Corners::DRB;
		break;


	}
	return 0;
}
