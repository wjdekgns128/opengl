#ifndef _CSCENE_H
#define _CSCENE_H
class cScene 
{
public:
	cScene()
	{
		;
	}
	virtual ~cScene()
	{
		;
	}
public:
	virtual void Init() = 0;
	virtual void Destroy() = 0;
	virtual void Update(float time) = 0;
	virtual void Render() = 0;
	virtual void MouseClick(int button, int state, int x, int y) = 0;
	virtual void MouseMove(int x, int y) = 0;
	virtual void SKeyBoard(int Type,int key, int x, int y) = 0;
	virtual void KeyBoard(int Type,unsigned  char  key, int x, int y) = 0;
	virtual void InitWindown(int w, int h) = 0;
};
#endif // !_CSCENE_H
