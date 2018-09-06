#ifndef _CPORTALOBJECT_H
#define _CPORTALOBJECT_H
#include "cBaseObject.h"
#include "cMyDefine.h"

class cPortalObject : public cBaseObject
{
public:
	bool				m_Moveing;
	float				m_r;
public:
	cPortalObject();
	cPortalObject(cVector vector);

	~cPortalObject();
public:
	void Render();
	void Update(float time);
};
#endif