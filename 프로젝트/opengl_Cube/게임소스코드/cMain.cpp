#include "cMain.h"
cMain::cMain() : cWindows("CUBE",600,600, GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH)
{

}
cMain::~cMain()
{
}
void cMain::Init()
{
	Entry(0, new cLogo);
	Entry(1, new cMenu);
	Entry(2, new  cSelete);
	Entry(3, new cGame);
	Trans(0);
}
