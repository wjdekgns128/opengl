// ��� ������Ʈ���� �⺻������ �������־���ϴ� �͵�(2D,3D��ȯ..)

#ifndef _CBACKGROUND_H
#define _CBACKGROUND_H
#include "cBaseObject.h"
#include "cMyDefine.h"

class cBackGround : public cBaseObject
{
private:
	GLubyte *pBytes; // �����͸� ����ų ������
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
	// ���� �浹üũ
};
#endif // !_CBASEOBJECT_h
