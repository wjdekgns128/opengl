// 모든 오브젝트들이 기본적으로 가지고있어야하는 것들(2D,3D변환..)

#ifndef _CBACKGROUND_H
#define _CBACKGROUND_H
#include "cBaseObject.h"
#include "cMyDefine.h"

class cBackGround : public cBaseObject
{
private:
	GLubyte *pBytes; // 데이터를 가리킬 포인터
	BITMAPINFO *info;
	GLuint textures[5];
public:
	cBackGround();
	~cBackGround();
	
public:
public:
	void Update();
	void Render2D();
	void Render3D();
	void Mouse(int button, int state, int x, int y);
	bool Coll2d(cVector start,cVector Scl)
	{
		return false;
	}
	// 투디 충돌체크
};
#endif // !_CBASEOBJECT_h
