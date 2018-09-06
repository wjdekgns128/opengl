#ifndef _CUIBUTTON_H
#define _CUIBUTTON_H
#include "cSprite.h"
typedef void(*m_pFunc)(int, void* s);

struct ButtonData
{
public:
	int number;
	int x;
	int y;
	int w;
	int h;
	bool click;
	bool show;//표현
	bool tex; //텍스쳐사용하는지
	float apl;
};
class cUIButton
{

private:
	cSprite*		m_pSprite;
	ButtonData		m_Data[50];
	ButtonData		SaveData;
	int				m_Max;
	m_pFunc			m_ReutrnSeleteButton;
	void*			m_pScene;
public:
	cUIButton()
	{
		m_pSprite = new cSprite;
		m_Max = 0;
	}
	~cUIButton()
	{
		SAFE_DELETE(m_pSprite);
	}
public:
	void SetActive(int number,bool _test)
	{
		m_Data[number].show = _test;
	}
	void SetApl(int number, float _apl)
	{
		m_Data[number].apl = _apl;
	}
	float GetApl(int number)
	{
		return m_Data[number].apl;
	}
	bool GetActive(int number)
	{
		return m_Data[number].show;
	}
	void Render2D();
	void Entry(int number, const char* name, int x, int y, int w, int h,bool click =true); // 텍스쳐
	void Entry(int number, int x, int y, int w, int h, bool click = true); //텍스쳐안넣을떄
	bool CollButton(int x, int y);
	void SetFunction(void* f,void* s)
	{
		m_ReutrnSeleteButton = (m_pFunc)f;
		m_pScene = s;
	}
private:
	void EntryPrivete(int number, int x, int y, int w, int h, bool click);
};

#endif