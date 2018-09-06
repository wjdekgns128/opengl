#ifndef _CWINDOWS_H
#define _CWINDOWS_H
#include "cMyInclude.h"
#include "cSceneManager.h"
class cWindows : public cSceneManager
{
	int			m_WindowsSizeX;
	int			m_WindowsSizeY;
	char		m_WindowsName[50];
	unsigned int	m_WindowsMode;
public:
	cWindows(char* _WindowsName = "test", int _WindowsSizeX = 800, int _WindowsSizeY = 600, unsigned int _WindowsMode = GLUT_SINGLE | GLUT_RGBA);
	~cWindows();

public:

	inline char* GetName() { return m_WindowsName; }
	inline int GetSizeX() { return m_WindowsSizeX; }
	inline int GetSizeY() { return m_WindowsSizeY; }
	inline unsigned int  GetMode() { return m_WindowsMode; }
	inline void SetWindowns(int w, int h)
	{
		m_WindowsSizeX =w;
		m_WindowsSizeY = h;
	}
	cVector ScreenToWorld(int _x, int _y);
};
#endif // !_CWINDOWS_H
