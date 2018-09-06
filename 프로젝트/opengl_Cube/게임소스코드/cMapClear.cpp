#include "cMapClear.h"
#include "cMapLoad.h"
void cMapClear::Load()
{
	if (m_LoadCheck)
		return;
	m_Fname = "res/User/UserData.txt";;

	int nResult = access(m_Fname.c_str(), 0);

	if (nResult == 0)
	{
		FILE* fp = fopen(m_Fname.c_str(), "r");
		for (int i = 0; i < GETLOAD->GetFileNamesCount(); i++)
		{
			int s = 0;
			fscanf(fp, "%d\n", &s);
			m_vSaveData.push_back(s);
		}
		fclose(fp);
	}
	else
	{
		for (int i = 0; i < GETLOAD->GetFileNamesCount();i++)
		{
			m_vSaveData.push_back(0);
		}
		Save();
		//¾øÀ½
	}
	m_LoadCheck = true;
}
void cMapClear::Save()
{

	FILE* fp = fopen(m_Fname.c_str(), "w");
	for (int i = 0; i < GETLOAD->GetFileNamesCount(); i++)
	{
		fprintf(fp,"%d\n", m_vSaveData.at(i));
	}
	fclose(fp);

}