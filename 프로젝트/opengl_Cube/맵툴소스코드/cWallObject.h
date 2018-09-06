#ifndef _CWALLOBJECT_H
#define _CWALLOBJECT_H
#include "cBaseObject.h"

class cWallObject : public cBaseObject
{
public:
	cWallObject();
	cWallObject(cVector vector);

	~cWallObject();
public:
	void Render();
	void Update();
};
#endif