#include "Cube2D.h"

CubeColor Cube2D::getSticker(Face face, int row, int col) const
{
	//ex tab de permutation : { 1, 3, 4, 5, 2, 6, 7, 0 }
	//ex tab d'orientation : { 0, 1, 1, 0, 0, 2, 0, 1}
	/*
		possibilité : (0, 0), (1, 0), (0, 1), (1, 1)
		ex: face : 3 ( White, Red, Blue, Orange, Green, Yellow ) 3 = Orange
			row : 0
			col = 1

		blanc : 0 1 2 3
		rouge : 1 2 4 5
		bleu : 0 2 4 6
		orange : 2 3 6 7
		vert : 1 3 5 7
		jauen : 4 5 6 7

		on recup les indices de permutation : 2 3 6 7
		( bas/haut, gauche, droite ) en tennant le blanc en bas 
		2 : Blanc Bleu Orange -> orientation de 1 -> Orange Blanc Bleu
		3 : Blanc Orange Vert -> orientation de 0 -> Blanc Orange Vert
		6 : jaune bleu Orange -> orientation de 0 -> jaune bleu Orange
		7 : jaune Orange vert -> orientation de 0 -> vert jaune Orange

		(0, 1) de blanc = corner 6
		-> jaune bleu Orange 

		return orange


	*/

	int corner = getCorner(face, row, col);//ULF
	int piece = this->m_cornerPermutation[corner];//5
	int orientation = this->m_cornerOrientation[corner];//0


	return getColor(piece, orientation, (int)face);
}


CubeColor Cube2D::getColor(int piece, int orientation, int face) const
{
	const auto& colors = cornerColors[piece];

	CubeColor color = colors[orientation % 3];

	if (color == CubeColor::White && face == (int)Face::D) return CubeColor::White;
	if (color == CubeColor::Yellow && face == (int)Face::U) return CubeColor::Yellow;

	for (int i = 0; i < 3; ++i)
	{
		CubeColor color = colors[(i + orientation) % 3];

		if (color == (CubeColor)face)
			return color;
	}

	return CubeColor::White;
}


int Cube2D::getCorner(Face face, int row, int col) const {
 
	/*
		on prend la face rouge en face et la face blanc vers le bas
		face vers le bas : index 0,0 devant a gauche
		face sue le coté : index 0,0 en haut a gauche 
	*/

	switch ((Face)face) {
		case Face::U:
			if (row == 0 && col == 0) return Corners::ULF;
			if (row == 0 && col == 1) return Corners::UFR;
			if (row == 1 && col == 0) return Corners::UBL;
			if (row == 1 && col == 1) return Corners::URB;
			break;
		case Face::D:
			if (row == 0 && col == 0) return Corners::DLF;
			if (row == 0 && col == 1) return Corners::DFR;
			if (row == 1 && col == 0) return Corners::DBL;
			if (row == 1 && col == 1) return Corners::DRB;
			break;
		case Face::F:
			if (row == 0 && col == 0) return Corners::ULF;
			if (row == 0 && col == 1) return Corners::UFR;
			if (row == 1 && col == 0) return Corners::DLF;
			if (row == 1 && col == 1) return Corners::DFR;
			break;
		case Face::B:
			if (row == 0 && col == 0) return Corners::URB;
			if (row == 0 && col == 1) return Corners::UBL;
			if (row == 1 && col == 0) return Corners::DRB;
			if (row == 1 && col == 1) return Corners::DBL;
			break;
		case Face::L://
			if (row == 0 && col == 0) return Corners::UBL;
			if (row == 0 && col == 1) return Corners::ULF;
			if (row == 1 && col == 0) return Corners::DBL;
			if (row == 1 && col == 1) return Corners::DLF;
			break;
		case Face::R://
			if (row == 0 && col == 0) return Corners::UFR;
			if (row == 0 && col == 1) return Corners::URB;
			if (row == 1 && col == 0) return Corners::DFR;
			if (row == 1 && col == 1) return Corners::DRB;
			break;


	}
	return 0;
}


