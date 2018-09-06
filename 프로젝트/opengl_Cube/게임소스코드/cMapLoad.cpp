#include "cMapLoad.h"

cMapLoad::cMapLoad()
{
	m_LoadError = false;
	m_NowStage = 0;
}
cMapLoad::~cMapLoad()
{
	
	SAFE_DELETE_ARRAY(m_pMapDatas);
}
void cMapLoad::Load()
{
	if (m_LoadError)
		return;
	int Z = 5;
	int X = 5;

	PathInAllLoad();
	m_pMapDatas = new MapData[m_vFileNames.size()];

	for (int i = 0; i < m_vFileNames.size(); i++)
	{
		string name = "res/Map/" + m_vFileNames[i];
		FILE* fp;
		fopen_s(&fp,name.c_str(), "r");
		int MapType;
		int Y;
		int ClearCount;
		
		fscanf_s(fp,"%d %d\n", &MapType, &ClearCount);
		if (MapType == 0)
			Y = 7;
		else
			Y = 8;
		m_pMapDatas[i].m_XCount = X;
		m_pMapDatas[i].m_YCount = Y;
		m_pMapDatas[i].m_ZCount = Z;
		m_pMapDatas[i].m_ClearCount = ClearCount;
		
		for (int _y = 0; _y < Y; _y++)
		{
			for (int _x = 0; _x < X; _x++)
			{
				fscanf_s(fp, "%d %d %d %d %d", &m_pMapDatas[i].m_MapData[_x][0][_y]
					, &m_pMapDatas[i].m_MapData[_x][1][_y]
					, &m_pMapDatas[i].m_MapData[_x][2][_y]
					, &m_pMapDatas[i].m_MapData[_x][3][_y]
					, &m_pMapDatas[i].m_MapData[_x][4][_y]);
			}
			fscanf_s(fp, "\n");
		}

		fclose(fp);


		//for (int _y = 0; _y < Y; _y++)
		//{
		//	for (int _x = 0; _x < X; _x++)
		//	{
		//		printf("%d %d %d %d %d\n", m_pMapDatas[i].m_MapData[_x][0][_y]
		//			, m_pMapDatas[i].m_MapData[_x][1][_y]
		//			, m_pMapDatas[i].m_MapData[_x][2][_y]
		//			, m_pMapDatas[i].m_MapData[_x][3][_y]
		//			, m_pMapDatas[i].m_MapData[_x][4][_y]);
		//	}
		//	printf("\n");
		//}
	}

	m_LoadError = true;
}
void cMapLoad::PathInAllLoad()
{

	long h_file;
	int result = 0;
	char* Path = "res/Map";
	_finddata_t search;
	
	h_file = _findfirst("res/Map//*.txt*", &search);

	if (h_file == -1)
	{
		printf("NO FILE\n");
	}
	while (result != -1)
	{
		printf("%s\n", search.name);
		string temp = search.name;
		/*char* temp = new char[strlen(search.name)-1];
		for (int i = 0; i < strlen(search.name); i++)
			temp[i] = search.name[i];
		temp[strlen(search.name)] = NULL;*/
		m_vFileNames.push_back(temp);
		result = _findnext(h_file, &search);
	}

	_findclose(h_file);


}