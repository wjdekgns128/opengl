#ifndef _CMAIN_H
#define _CMAIN_H
#include "cWindows.h"
#include "cGame.h"
class cMain : public cWindows
{

private:
	cMain();
	~cMain();
public:
	void Init();
public:

	static cMain* GetInstance()
	{
		static cMain _instance;
		return &_instance;
	}
	
};


#endif