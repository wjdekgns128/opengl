#ifndef _CEMPTYOBJECT_H
#define _CEMPTYOBJECT_H
#include "cBaseObject.h"

class cEmptyObject : public cBaseObject
{
private:
	float m_apl;
public:
	cEmptyObject(float n= 1);
	cEmptyObject(cVector vector,float n);

	~cEmptyObject();
public:
	void Render();
	void Update();
};
#endif