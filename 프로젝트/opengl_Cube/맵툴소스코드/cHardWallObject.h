#ifndef _CHARDWALLOBJECT_H
#define _CHARDWALLOBJECT_H
#include "cBaseObject.h"

class cHardWallObject : public cBaseObject
{
public:
	cHardWallObject();
	cHardWallObject(cVector vector);

	~cHardWallObject();
public:
	void Render();
	void Update();
};
#endif