#include "cMain.h"
cMain::cMain() : cWindows("����2",1000,700, GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH)
{

}
cMain::~cMain()
{
}
void cMain::Init()
{

	Entry(0, new cGame());
	Trans(0);
}
