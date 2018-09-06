#include "cWindows.h"

cWindows::cWindows(char* _WindowsName, int _WindowsSizeX , int _WindowsSizeY , unsigned int _WindowsMode)
{
	strcpy(m_WindowsName, _WindowsName);
	m_WindowsSizeX = _WindowsSizeX;
	m_WindowsSizeY = _WindowsSizeY;
	m_WindowsMode = _WindowsMode;
	m_w = m_WindowsSizeX;
	m_h = m_WindowsSizeY;

}
cWindows::~cWindows()
{


}
cVector cWindows::ScreenToWorld(int _x,int _y)
{
	GLdouble wx;
	GLdouble wy;
	GLdouble wz;

	cVector Temp;
	GLdouble projection[16];
	GLdouble modelView[16];
	GLint viewPort[4];
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	glGetDoublev(GL_MODELVIEW_MATRIX, modelView);
	glGetIntegerv(GL_VIEWPORT, viewPort);
	GLfloat zCursor, winX, winY;
	winX = (float)_x;
	winY = (float)viewPort[3] - (float)_y;
	glReadPixels((int)winX, (int)winY, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &zCursor);
	gluUnProject(winX, winY, zCursor, modelView, projection, viewPort, &wx, &wy, &wz);
	return cVector(wx, wy, wz);
}