#ifndef _CMAPLOAD_H
#define _cMAPLOAD_H
#include <stdio.h>
#include <vector>
#include <io.h>
#include <stdlib.h>
#include "cMyDefine.h"
#include "cVector.h"
#define GETLOAD (cMapLoad::GetInstance())
using namespace std;
typedef int(*ALL)[5][8];
typedef struct MapData
{
public:
	int		m_MapData[5][5][8]; //X,Z,Y 순으로 최대맵크기
	int		m_YCount;
	int		m_XCount;
	int     m_ZCount;
	int		m_ClearCount;

public:
#pragma region CREATE
	MapData(int _x, int _y, int _z, int _clear)
	{
		this->m_ClearCount = _clear;
		this->m_XCount = _x;
		this->m_YCount = _y;
		this->m_ZCount = _z;
	}
		MapData() { ; }
#pragma endregion
}MAPDATA;
class cMapLoad
{
private:
	vector<string> m_vFileNames;
	MAPDATA*	  m_pMapDatas;
	bool		m_LoadError;
	int				m_NowStage;
private:
	cMapLoad();
public:
	~cMapLoad();

public:
	static cMapLoad* GetInstance()
	{
		static cMapLoad _instance;
		return &_instance;
	}
private:
	void PathInAllLoad(); // res/MapData에있는 모든 파일 읽기
public:
	cVector GetStartPoint(int num) //시작점 리턴
	{
		for (int y = 0; y < m_pMapDatas[num].m_YCount;y++)
		{
			for (int x = 0; x < m_pMapDatas[num].m_XCount;x++)
			{
				for (int z = 0; z < m_pMapDatas[num].m_ZCount; z++)
				{
					if (m_pMapDatas[num].m_MapData[x][z][y] == START)
						return cVector(x, y, z);
				}
			}
		}
		return cVector(-100, -100, -100);
	}
	cVector GetPortalObject(int num,int n) //포탈 리턴
	{
		int t = 0;
		for (int y = 0; y < m_pMapDatas[num].m_YCount; y++)
		{
			for (int x = 0; x < m_pMapDatas[num].m_XCount; x++)
			{
				for (int z = 0; z < m_pMapDatas[num].m_ZCount; z++)
				{
					if (m_pMapDatas[num].m_MapData[x][z][y] == PORTAL)
					{
						if (t == n)
							return cVector(x, y, z);
						else
							t++;
					}
				}
			}
		}
		return cVector(-100, -100, -100);
	}
	cVector GetEndPoint(int num) // 끝점 리턴
	{
		for (int y = 0; y < m_pMapDatas[num].m_YCount; y++)
		{
			for (int x = 0; x < m_pMapDatas[num].m_XCount; x++)
			{
				for (int z = 0; z < m_pMapDatas[num].m_ZCount; z++)
				{
					if (m_pMapDatas[num].m_MapData[x][z][y] == END)
						return cVector(x, y, z);
				}
			}
		}
		return cVector(-100, -100, -100);
	}
public:
	
	void Load(); //현재파일로딩 Get함수로 획득가능
#pragma region Get
	inline int GetYCount(int num)
	{ 
			return m_pMapDatas[num].m_YCount; 
	}
	inline int GetXCount(int num) { return m_pMapDatas[num].m_XCount; }
	inline int GetZCount(int num) { return m_pMapDatas[num].m_ZCount; }
	inline int GetClearCount(int num) { return m_pMapDatas[num].m_ClearCount; }
	inline int GetData(int num,int x, int y, int z)
	{
		return m_pMapDatas[num].m_MapData[x][z][y];
	}
	inline ALL GetAllData(int num)
	{
		return m_pMapDatas[num].m_MapData;
	}
	inline string GetFileNames(int number)
	{
		if (m_vFileNames.empty())
			return "NOFILES";
		return m_vFileNames[number];
	}
	inline int GetFileNamesCount()
	{
		return m_vFileNames.size();
	}
	void SetNowNumber(int number)
	{
		m_NowStage = number;
	}
	int GetNowNumber()
	{
		return m_NowStage;
	}
	//num은 스테이지번호
#pragma endregion

};
#endif // !_CMAPLOAD_h
