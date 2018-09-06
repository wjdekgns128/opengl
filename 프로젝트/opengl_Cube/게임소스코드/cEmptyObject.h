#ifndef _CEMPTYOBJECT_H
#define _CEMPTYOBJECT_H
#include "cBaseObject.h"

class cEmptyObject : public cBaseObject
{
private:
public:
	cEmptyObject();
	cEmptyObject(cVector vector);

	~cEmptyObject();
public:
	void Render();
	void Update(float time);
};
#endif