#include "cUIButton.h"

void cUIButton::Entry(int number, const char* name, int x, int y, int w, int h, bool click ) // 텍스쳐
{
	SaveData.tex = true;
	m_pSprite->Entry(number, name);
	EntryPrivete(number, x, y, w, h, click);
}
void cUIButton::Entry(int number, int x, int y, int w, int h, bool click ) //텍스쳐안넣을떄
{
	SaveData.tex = false;

	EntryPrivete(number, x, y, w, h, click);
}
void cUIButton::EntryPrivete(int number, int x, int y, int w, int h, bool click)
{
	SaveData.show = true;
	SaveData.number = number;
	SaveData.x = x;
	SaveData.y = y;
	SaveData.w = w;
	SaveData.h = h;
	SaveData.apl = 1;
	SaveData.click = click;
	m_Max++;
	m_Data[number] = SaveData;
}
void cUIButton::Render2D()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	for (int i = 0; i < m_Max; i++)
	{

		if (m_Data[i].show == false)
			continue;
		if (m_Data[i].tex == true)
		{
			m_pSprite->OnRender(i);
			glBegin(GL_QUADS);
			glColor4f(1, 1, 1,m_Data[i].apl);
			glTexCoord2f(0, 1);
			glVertex3f(m_Data[i].x, m_Data[i].y, 0);
			glTexCoord2f(1, 1);

			glVertex3f(m_Data[i].x+m_Data[i].w, m_Data[i].y, 0);
			glTexCoord2f(1, 0);

			glVertex3f(m_Data[i].x + m_Data[i].w, m_Data[i].y+m_Data[i].h, 0);
			glTexCoord2f(0, 0);

			glVertex3f(m_Data[i].x, m_Data[i].y+ m_Data[i].h, 0);
			glEnd();
			m_pSprite->OffRender(i);
		}
		else
		{
			glBegin(GL_QUADS);
			glColor4f(1, 1, 1, m_Data[i].apl);
			glVertex3f(m_Data[i].x, m_Data[i].y, 0);
			glVertex3f(m_Data[i].x + m_Data[i].w, m_Data[i].y, 0);
			glVertex3f(m_Data[i].x + m_Data[i].w, m_Data[i].y + m_Data[i].h, 0);
			glVertex3f(m_Data[i].x, m_Data[i].y + m_Data[i].h, 0);
			glEnd();
		}
	}
	glDisable(GL_BLEND);
}
bool cUIButton::CollButton(int x, int y)
{
	bool check = false;
	for (int i = 0; i < m_Max; i++)
	{
		if (m_Data[i].click == false || (m_Data[i].show == false))
			continue;
		if (x <m_Data[i].x + m_Data[i].w && x > m_Data[i].x && y < m_Data[i].y + m_Data[i].h && y > m_Data[i].y)
		{
			check = true;
			m_ReutrnSeleteButton(i, m_pScene);
			break;
		}

	}
	return check;
}