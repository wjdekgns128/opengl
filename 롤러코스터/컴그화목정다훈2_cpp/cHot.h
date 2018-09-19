#pragma once
#ifndef CHOT_H
#define CHOT_H

#include "cBaseDay.h"
#include <gl/glut.h>
class cHot : public cBaseDay
{
private:
	
public:
	cHot()
	{
	}
	~cHot()
	{

	}
public:
	void Render();
	void Update(float _time);
	void CreateObject() { ; }



};

#endif