#pragma once

#include "ICube.h"

class IViewer {
protected:
	ICube* m_cube;

public:
	IViewer(ICube* cube) : m_cube(cube) {

	}
	virtual void drawCube() = 0;

};