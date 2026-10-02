#pragma once

#include "IViewer.h"

class ViewerTerminal : public IViewer {


public:
	ViewerTerminal(ICube* cube) : IViewer(cube) {

	}

	virtual void drawCube() override;
};