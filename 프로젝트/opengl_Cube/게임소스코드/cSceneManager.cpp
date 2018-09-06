#include "cSceneManager.h"

cSceneManager::cSceneManager()
{
	for (int i = 0; i < 100; i++)
		m_pScene[i] = NULL;

	m_Now = -1;
}
cSceneManager::~cSceneManager()
{
	for (int i = 0; i < 100; i++)
		SAFE_DELETE(m_pScene[i]);
}
void cSceneManager::Entry(int Number, cScene* m_p)
{
	m_pScene[Number] = m_p;
	m_Now = Number;
}
void cSceneManager::Trans(int Number)
{
	if (m_Now == -1)
		return;
	if (m_Now != Number)
		m_pScene[m_Now]->Destroy();
	m_pScene[Number]->InitWindown(m_w, m_h);
	m_pScene[Number]->Init();
	m_Now = Number;
}