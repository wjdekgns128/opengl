#ifndef CPARTICLEOBJECT
#define CPARTICLEOBJECT
#include <gl/glut.h>
#include "cParticleObject.h"

#include <vector>
using namespace std;

class cParticleBase
{
public:
	bool						m_check;

private:
	bool						m_deletecheck;
	vector<cParticleObject>		m_vObject;
public:
	cParticleBase();
	~cParticleBase();
public:
	void		Setting(int max,int x , int y,int z);
	void		Start();
	void		Update(float time);
	void		Render();
};

#endif
