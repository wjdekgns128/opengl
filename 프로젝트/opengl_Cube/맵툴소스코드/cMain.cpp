#include "cMain.h"
cMain::cMain() : cWindows("MAPTOOL",600,600, GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH)
{

}
cMain::~cMain()
{
}
void cMain::Init()
{
	Entry(0, new cGame);

	Trans(0);
}
