#ifndef CSTARTOBJECT_H
#define CSTARTOBJECT_H
#include "cBaseObject.h"
#include "cMyDefine.h"

class cStartObject : public cBaseObject
{
public:
	cStartObject();
	cStartObject(cVector vector);

	~cStartObject();
public:
	void Render();
	void Update();
};
#endif