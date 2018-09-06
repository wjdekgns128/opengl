#ifndef _CWALLOBJECT_H
#define _CWALLOBJECT_H
#include "cBaseObject.h"

class cWallObject : public cBaseObject
{
private:
	cVector		m_NormalVector[6];

public:
	cWallObject();
	cWallObject(cVector vector);

	~cWallObject();
public:
	void Render();
	void Update(float time);
public:
	void RenderObject();
};
#endif