#ifndef _CENDOBJECT_H
#define _CENDOBJECT_H
#include "cBaseObject.h"
#include "cMyDefine.h"

class cEndObject : public cBaseObject
{
private:
public:
	cEndObject();
	cEndObject(cVector vector);

	~cEndObject();
public:
	void Render();
	void Update(float time);

};
#endif