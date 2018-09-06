#ifndef _CSHOW_H
#define _CSHOW_H
#include <gl/glut.h>
class cShow
{
public:
	int			m_NowY;
public:
	cShow(int _nowy);
	~cShow();
public:
	void Redner();

};
#endif // !_CSHOW_H
