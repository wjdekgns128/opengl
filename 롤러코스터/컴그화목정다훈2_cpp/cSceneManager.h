#ifndef CSCENEMANAGER_H
#define CSCENEMANAGER_H
#include "cScene.h"
#include "cMyInclude.h"
class cSceneManager
{
public:
	int				m_w;
	int				m_h;
private:

	cScene*			m_pScene[100];
	int				m_Now;
public:
	cSceneManager();
	virtual ~cSceneManager();
public:
	void Entry(int Number, cScene* m_p);
	void Trans(int Number);
public:
	inline cScene*		GetNowScene() {
		if (m_Now == -1)
			return NULL;
		return m_pScene[m_Now];
	}
};
#endif // !CSCENEMANAGER_h
