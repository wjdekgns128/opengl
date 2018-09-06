#include "cMyInclude.h"
#include "cMain.h"
GLvoid Update(int Value);
GLvoid drawScene(GLvoid);
GLvoid Mouse(int button, int state, int x, int y);
GLvoid MouseMove(int x, int y);
GLvoid KeyBoard(int key, int x, int y);
GLvoid KeyBoardUp(int key, int x, int y);

GLvoid KeyBoard1(unsigned  char  key, int x, int y);
GLvoid KeyBoardUp(unsigned  char  key, int x, int y);

GLvoid Windown(int w, int h);

double Timer = 0;
double LastTimer = 0;
void main(int argc, char *argv[])
{
	//�ʱ�ȭ �Լ���
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	glutInitDisplayMode(cMain::GetInstance()->GetMode()); // ���÷��� ��� ����
	glutInitWindowPosition(100, 100); // �������� ��ġ����
	glutInitWindowSize(cMain::GetInstance()->GetSizeX(), cMain::GetInstance()->GetSizeY()); // �������� ũ�� ����
	glutCreateWindow(cMain::GetInstance()->GetName()); // ������ ���� (������ �̸�) 
	glutTimerFunc(13, Update, 1);
	glutDisplayFunc(drawScene);
	glutMouseFunc(Mouse);
	glutMotionFunc(MouseMove);
	glutPassiveMotionFunc(MouseMove);
	glutSpecialFunc(KeyBoard);
	glutReshapeFunc(Windown);
	glutKeyboardFunc(KeyBoard1);
	glutKeyboardUpFunc(KeyBoardUp);
	glutSpecialUpFunc(KeyBoardUp);
		cMain::GetInstance()->Init();

	glutMainLoop();

}
GLvoid Windown(int w, int h)
{
	if (cMain::GetInstance()->GetNowScene() != NULL)
		cMain::GetInstance()->GetNowScene()->InitWindown(w,h);
	cMain::GetInstance()->SetWindowns(w, h);
}
GLvoid Update(int Value)
{
	glutPostRedisplay();
	/*Timer = glutGet(GLUT_ELAPSED_TIME) * 0.001;
	if (Timer - LastTimer >= (16*0.001))
	{
		LastTimer = Timer;
		if (cMain::GetInstance()->GetNowScene() != NULL)
			cMain::GetInstance()->GetNowScene()->Update(16 * 0.001);
	}
	*/
	if (cMain::GetInstance()->GetNowScene() != NULL)
		cMain::GetInstance()->GetNowScene()->Update((1000.0 / 60.0) * 0.001);
	glutTimerFunc(1000.0/60.0, Update, 0);
}
GLvoid drawScene(GLvoid)
{
	if (cMain::GetInstance()->GetNowScene() != NULL)

		cMain::GetInstance()->GetNowScene()->Render();
}
GLvoid KeyBoard(int key, int x, int y)
{
	if (key == 'q')
		exit(0);
	if (cMain::GetInstance()->GetNowScene() != NULL)

		cMain::GetInstance()->GetNowScene()->SKeyBoard(KEYBOARDDOWN,key, x, y);

}
GLvoid KeyBoardUp(int key, int x, int y)
{
	if (cMain::GetInstance()->GetNowScene() != NULL)

		cMain::GetInstance()->GetNowScene()->SKeyBoard(KEYBOARDUP, key, x, y);
}
GLvoid KeyBoard1(unsigned  char  key, int x, int y)
{

	if (cMain::GetInstance()->GetNowScene() != NULL)

		cMain::GetInstance()->GetNowScene()->KeyBoard(KEYBOARDDOWN,key, x, y);

}
GLvoid KeyBoardUp(unsigned  char  key, int x, int y)
{
	if (cMain::GetInstance()->GetNowScene() != NULL)

		cMain::GetInstance()->GetNowScene()->KeyBoard(KEYBOARDUP, key, x, y);
}
GLvoid Mouse(int button, int state, int x, int y)
{
	if (cMain::GetInstance()->GetNowScene() != NULL)

		cMain::GetInstance()->GetNowScene()->MouseClick(button, state, x, y);

}
GLvoid MouseMove(int x, int y)
{
	if (cMain::GetInstance()->GetNowScene() != NULL)

		cMain::GetInstance()->GetNowScene()->MouseMove(x, y);
}
