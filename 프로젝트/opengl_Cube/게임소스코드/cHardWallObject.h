#ifndef _CHARDWALLOBJECT_H
#define _CHARDWALLOBJECT_H
#include "cBaseObject.h"

class cHardWallObject : public cBaseObject
{
private:
public:
	cHardWallObject();
	cHardWallObject(cVector vector);

	~cHardWallObject();
public:
	void Render();
	void Update(float time);
public:
	void RenderObject();
};
#endif