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