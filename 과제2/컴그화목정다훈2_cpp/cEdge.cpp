#include "cEdge.h"
cEdge::cEdge()
{
	m_pPointVector.clear();
	m_pEdgePoint.clear();
	m_pEdgeAngle.clear();
	m_tempnumber = 0;
}
cEdge::~cEdge()
{

}
void cEdge::Render2D()
{
	glLineWidth(20);

	glBegin(GL_LINE_STRIP);

	for (int i = 0; i < m_pEdgePoint2D.size(); i++)
	{
		
		glColor3ub(255, 128, 65);
		glVertex2f(m_pEdgePoint2D[i].x, m_pEdgePoint2D[i].y);
	}
	glEnd();
	glLineWidth(1);
}
void cEdge::RenderPlayer()
{

	//첫번째 롤러코스터
	glColor3ub(255, 255, 0);
	glPushMatrix();
	glTranslatef(m_pEdgePoint[m_nowNumber].x, m_pEdgePoint[m_nowNumber].z + 4.5, m_pEdgePoint[m_nowNumber].y);
	glRotatef(m_pEdgeAngle[m_nowNumber].x, m_pEdgeAngleXYZ[m_nowNumber].x, m_pEdgeAngleXYZ[m_nowNumber].z, m_pEdgeAngleXYZ[m_nowNumber].y);
	if (m_pEdgePoint[m_nowNumber].y < m_pEdgePoint[(m_nowNumber + 1) % m_pEdgePoint.size()].y)
		glRotatef(180, 0, 1, 0);
	glScalef(15, 5, 10);
	glutSolidCube(1);
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glTranslatef(-0.405, 1, 0);
	glScalef(0.1, 1.1, 1);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glTranslatef(0.405, 1, 0);
	glScalef(0.1, 1.1, 1);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glTranslatef(0, 1, 0.5);
	glScalef(0.8, 1.1, 0.1);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glColor3ub(70, 231, 45);
	glTranslatef(0, 1.1, -0.3);
	glScalef(0.2, 1.5, 0.2);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();


	glColor3ub(255, 255, 0);
	glPushMatrix();
	glTranslatef(m_pEdgePoint[m_nowNumber1].x, m_pEdgePoint[m_nowNumber1].z + 4.5, m_pEdgePoint[m_nowNumber1].y);
	glRotatef(m_pEdgeAngle[m_nowNumber1].x, m_pEdgeAngleXYZ[m_nowNumber1].x, m_pEdgeAngleXYZ[m_nowNumber1].z, m_pEdgeAngleXYZ[m_nowNumber1].y);

	if (m_pEdgePoint[m_nowNumber1].y < m_pEdgePoint[(m_nowNumber1 + 1) % m_pEdgePoint.size()].y)
		glRotatef(180, 0, 1, 0);
	glScalef(15, 5, 10);
	glutSolidCube(1);
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glTranslatef(-0.405, 1, 0);
	glScalef(0.1, 1.1, 1);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glTranslatef(0.405, 1, 0);
	glScalef(0.1, 1.1, 1);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glTranslatef(0, 1, 0.5);
	glScalef(0.8, 1.1, 0.1);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glColor3ub(70, 231, 45);
	glTranslatef(0, 1.1, -0.3);
	glScalef(0.2, 1.5, 0.2);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();



	glColor3ub(255, 255, 0);
	glPushMatrix();
	glTranslatef(m_pEdgePoint[m_nowNumber2].x, m_pEdgePoint[m_nowNumber2].z + 4.5, m_pEdgePoint[m_nowNumber2].y);
	glRotatef(m_pEdgeAngle[m_nowNumber2].x, m_pEdgeAngleXYZ[m_nowNumber2].x, m_pEdgeAngleXYZ[m_nowNumber2].z, m_pEdgeAngleXYZ[m_nowNumber2].y);
	if (m_pEdgePoint[m_nowNumber2].y < m_pEdgePoint[(m_nowNumber2 + 1) % m_pEdgePoint.size()].y)
		glRotatef(180, 0, 1, 0);
	glScalef(15, 5, 10);
	glutSolidCube(1);
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glTranslatef(-0.405, 1, 0);
	glScalef(0.1, 1.1, 1);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glTranslatef(0.405, 1, 0);
	glScalef(0.1, 1.1, 1);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glTranslatef(0, 1, 0.5);
	glScalef(0.8, 1.1, 0.1);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glColor3ub(70, 231, 45);
	glTranslatef(0, 1.1, -0.3);
	glScalef(0.2, 1.5, 0.2);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();


	glColor3ub(255, 255, 0);
	glPushMatrix();
	glTranslatef(m_pEdgePoint[m_nowNumber3].x, m_pEdgePoint[m_nowNumber3].z + 4.5, m_pEdgePoint[m_nowNumber3].y);
	glRotatef(m_pEdgeAngle[m_nowNumber3].x, m_pEdgeAngleXYZ[m_nowNumber3].x, m_pEdgeAngleXYZ[m_nowNumber3].z, m_pEdgeAngleXYZ[m_nowNumber3].y);
	if (m_pEdgePoint[m_nowNumber3].y < m_pEdgePoint[(m_nowNumber3 + 1) % m_pEdgePoint.size()].y)
		glRotatef(180, 0, 1, 0);
	glScalef(15, 5, 10);
	glutSolidCube(1);
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glTranslatef(-0.405, 1, 0);
	glScalef(0.1, 1.1, 1);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glTranslatef(0.405, 1, 0);
	glScalef(0.1, 1.1, 1);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glTranslatef(0, 1, 0.5);
	glScalef(0.8, 1.1, 0.1);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glColor3ub(70, 231, 45);
	glTranslatef(0, 1.1, -0.3);
	glScalef(0.2, 1.5, 0.2);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
}
void cEdge::Render3D()
{
	

	if (m_pEdgePoint.size() > 0)
	{

		for (int i = 0; i < m_vpBullet.size(); i++)
			m_vpBullet[i]->Render();

		m_tempnumber++;
		m_tempnumber1++;
		m_tempnumber2++;
		m_tempnumber3++;

		if (m_tempnumber >= m_number[m_nowNumber])
		{
			if (m_number[m_nowNumber] == 0)
				m_nowNumber += 4;
			else
				m_nowNumber += 2;

			m_nowNumber %= m_pEdgePoint.size();
			m_tempnumber = 0;
		}
		if (m_tempnumber1 >= m_number[m_nowNumber1])
		{
		
			if (m_number[m_nowNumber1] == 0)
				m_nowNumber1 += 4;
			else
				m_nowNumber1 += 2;


			m_nowNumber1 %= m_pEdgePoint.size();
			m_tempnumber1 = 0;
		}
		if (m_tempnumber2 >= m_number[m_nowNumber2])
		{
			
			if (m_number[m_nowNumber2] == 0)
				m_nowNumber2 += 4;
			else
				m_nowNumber2 += 2;

			m_nowNumber2 %= m_pEdgePoint.size();
			m_tempnumber2 = 0;
		}
		if (m_tempnumber3 >= m_number[m_nowNumber3])
		{
		
			if (m_number[m_nowNumber3] == 0)
				m_nowNumber3 += 4;
			else
				m_nowNumber3 += 2;

			m_nowNumber3 %= m_pEdgePoint.size();
			m_tempnumber3 = 0;
		}
		if (m_mode == 0)
		{
			glPushMatrix();
			glLoadIdentity();
			glTranslatef(m_pEdgePoint[m_nowNumber].x, m_pEdgePoint[m_nowNumber].z + 30, m_pEdgePoint[m_nowNumber].y);
			glRotatef(m_pEdgeAngle[m_nowNumber].x, m_pEdgeAngleXYZ[m_nowNumber].x, m_pEdgeAngleXYZ[m_nowNumber].z, m_pEdgeAngleXYZ[m_nowNumber].y);
	
			glScalef(20, 20, 30);

			glPushMatrix();
			if (m_pEdgePoint[m_nowNumber].y <m_pEdgePoint[(m_nowNumber + 1) % m_pEdgePoint.size()].y)
				glTranslatef(0, 0, -1.5);
			else
				glTranslatef(0, 0, 1.5);

			GLfloat matrixMV[16];
			glGetFloatv(GL_MODELVIEW_MATRIX, matrixMV);
			TEMPS = cVector(matrixMV[12], matrixMV[13], matrixMV[14]);
			glPopMatrix();

			glPopMatrix();
			cVector t = m_pEdgePoint[m_nowNumber];
			float t12 = t.y;
			float t22 = t.z + 30;
			t.z = t12;
			t.y = t22;
			m_pCam->SetLook(t);
			m_pCam->SetEye(TEMPS);
			m_pCam->Update();

		}
		
		RenderPlayer();
	
	
		for (int i = 0; i < m_pEdgePoint.size(); i++)
		{
			if (i % 35 == 0)
			{
				glColor3ub(255, 40, 40);
				glPushMatrix();
				glTranslatef(m_pEdgePoint[i].x, m_pEdgePoint[i].z + 1.5, m_pEdgePoint[i].y);
				glRotatef(m_pEdgeAngle[i].x, m_pEdgeAngleXYZ[i].x, m_pEdgeAngleXYZ[i].z, m_pEdgeAngleXYZ[i].y);
				glScalef(20, 1, 5);
				glutSolidCube(1);
				glPopMatrix();
			}


		}
		glLineWidth(20);
		glPointSize(5);
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < m_pEdgePoint.size(); i++)
		{
			glColor3ub(255, 128, 65);
			glPushMatrix();

			glVertex3f(m_pEdgePoint[i].x, m_pEdgePoint[i].z + 1.5, m_pEdgePoint[i].y);
			glPopMatrix();

		}

		glEnd();
		glLineWidth(1);
	

	}
}
void cEdge::Update(float time)
{
	for (int i = 0; i < m_vpBullet.size(); i++)
	{
		m_vpBullet[i]->Update(time);
		if (m_vpBullet[i]->GetState() == 2)
		{
			m_vpBullet.erase(m_vpBullet.begin() + i);
		}
	}
}
void cEdge::Mouse(int button, int state, int x, int y)
{


}

void cEdge::GetSPline()
{

	if (m_pPointVector.size() < 2)
	{
		return;
	}
	m_nowNumber = 60;
	m_nowNumber1 = 40;
	m_nowNumber2 = 20;
	m_nowNumber3 = 0;
	m_tempnumber = 0;
	m_tempnumber1 = 0;
	m_tempnumber2 = 0;
	m_tempnumber3 = 0;
	m_pEdgePoint.clear();
	m_pEdgeAngle.clear();
	m_pEdgeAngleXYZ.clear();
	m_number.clear();
	
	cVector m0;
	cVector m1;
	cVector m2;
	cVector m3;
	cVector Aftor;
	m_mode = 3;
	vector<float> test;

	float x;
	float y;
	float z;
	m_pPointVector.push_back(m_pPointVector[0]);

	for (int i = 0; i < m_pPointVector.size(); i++)
	{
		for (float t = 0; t < 1; t += 0.05)
		{
			float tt = t*t;
			float t1 = 1 - t;
			float t2 = 2 * t;
			float h00 = (1 + t2) * (t1)* (t1);
			float h10 = t * (t1)* (t1);
			float h01 = tt * (3 - t2);
			float h11 = tt * (t - 1);

			if (!i)
			{
				m0 = GetSPLineGet(m_pPointVector[i + 1]->Get3DVector(), m_pPointVector[i]->Get3DVector());
				m1 = GetSPLineGet(m_pPointVector[i + 2]->Get3DVector(), m_pPointVector[i]->Get3DVector());
				x = h00 * m_pPointVector[i]->Get3DVector().x + h10 * m0.x + h01 * m_pPointVector[i + 1]->Get3DVector().x + h11 * m1.x;
				y = h00 * m_pPointVector[i]->Get3DVector().y + h10 * m0.y + h01 * m_pPointVector[i + 1]->Get3DVector().y + h11 * m1.y;
				z = h00 * m_pPointVector[i]->GetSclVector().z + h10 * m0.z + h01 * m_pPointVector[i + 1]->GetSclVector().z + h11 * m1.z;
				Aftor = cVector(x, y, z);
				m_pEdgePoint.push_back(Aftor);
			}
			else if (i < m_pPointVector.size() - 2)
			{
				m1 = GetSPLineGet(m_pPointVector[i + 1]->Get3DVector(), m_pPointVector[i - 1]->Get3DVector());
				m2 = GetSPLineGet(m_pPointVector[i + 2]->Get3DVector(), m_pPointVector[i]->Get3DVector());
				x = h00 * m_pPointVector[i]->Get3DVector().x + h10 * m1.x + h01 * m_pPointVector[i + 1]->Get3DVector().x + h11 * m2.x;
				y = h00 * m_pPointVector[i]->Get3DVector().y + h10 * m1.y + h01 * m_pPointVector[i + 1]->Get3DVector().y + h11 * m2.y;
				z = h00 * m_pPointVector[i]->GetSclVector().z + h10 * m1.z + h01 * m_pPointVector[i + 1]->GetSclVector().z + h11 * m2.z;
				Aftor = cVector(x, y, z);

				m_pEdgePoint.push_back(Aftor);
			}
			else if (i == m_pPointVector.size() - 1)
			{
				m2 = GetSPLineGet(m_pPointVector[i]->Get3DVector(), m_pPointVector[i - 2]->Get3DVector());
				m3 = GetSPLineGet(m_pPointVector[i]->Get3DVector(), m_pPointVector[i - 1]->Get3DVector());
				x = h00 * m_pPointVector[i - 1]->Get3DVector().x + h10 * m2.x + h01 * m_pPointVector[i]->Get3DVector().x + h11 * m3.x;
				y = h00 * m_pPointVector[i - 1]->Get3DVector().y + h10 * m2.y + h01 * m_pPointVector[i]->Get3DVector().y + h11 * m3.y;
				z = h00 * m_pPointVector[i - 1]->GetSclVector().z + h10 * m2.z + h01 * m_pPointVector[i]->GetSclVector().z + h11 * m3.z;
				Aftor = cVector(x, y, z);

				m_pEdgePoint.push_back(Aftor);
			}

			else
			{
			
				break;
			}
		
		}
		if (m_pEdgePoint.size() != 0)
		{
			float r = 0;
			for (int i = 0; i < m_pEdgePoint.size() - 1; i++)
			{
				r += (m_pEdgePoint[i] - m_pEdgePoint[i + 1]).GetVectorSize();

			}
			m_pEdgePoint.clear();
			test.push_back(r);
		}
		else
		{
			test.push_back(0);
		}
	}
	m_pEdgePoint.clear();
	for (int i = 0; i < m_pPointVector.size(); i++)
	{
		if (m_pEdgePoint.size() != 0)
			m_pEdgePoint.pop_back();
		float tttt = (1 / test[i]);
		for (float t = 0; t < 1; t += tttt) // 캣멀롬 스플라인
		{
			float tt = t*t; // 필요한값
			float t1 = 1 - t; //..
			float t2 = 2 * t; //..
			float h00 = (1 + t2) * (t1)* (t1);//..
			float h10 = t * (t1)* (t1);//..
			float h01 = tt * (3 - t2);//..
			float h11 = tt * (t - 1);//..
			
			if (!i)
			{
				m0 = GetSPLineGet(m_pPointVector[i + 1]->Get3DVector(), m_pPointVector[i]->Get3DVector());
				m1 = GetSPLineGet(m_pPointVector[i + 2]->Get3DVector(), m_pPointVector[i]->Get3DVector());
				x = h00 * m_pPointVector[i]->Get3DVector().x + h10 * m0.x + h01 * m_pPointVector[i + 1]->Get3DVector().x + h11 * m1.x;
				y = h00 * m_pPointVector[i]->Get3DVector().y + h10 * m0.y + h01 * m_pPointVector[i + 1]->Get3DVector().y + h11 * m1.y;
				z = h00 * m_pPointVector[i]->GetSclVector().z + h10 * m0.z + h01 * m_pPointVector[i + 1]->GetSclVector().z + h11 * m1.z;
				Aftor = cVector(x, y, z);
				m_pEdgePoint.push_back(Aftor);
			}
			//점이 2~3개 일떄도 이어야하기때문에
			else if (i < m_pPointVector.size() - 2) 
			{
				m1 = GetSPLineGet(m_pPointVector[i + 1]->Get3DVector(), m_pPointVector[i - 1]->Get3DVector());
				m2 = GetSPLineGet(m_pPointVector[i + 2]->Get3DVector(), m_pPointVector[i]->Get3DVector());
				x = h00 * m_pPointVector[i]->Get3DVector().x + h10 * m1.x + h01 * m_pPointVector[i + 1]->Get3DVector().x + h11 * m2.x;
				y = h00 * m_pPointVector[i]->Get3DVector().y + h10 * m1.y + h01 * m_pPointVector[i + 1]->Get3DVector().y + h11 * m2.y;
				z = h00 * m_pPointVector[i]->GetSclVector().z + h10 * m1.z + h01 * m_pPointVector[i + 1]->GetSclVector().z + h11 * m2.z;
				Aftor = cVector(x, y, z);

				m_pEdgePoint.push_back(Aftor);
			}
			else if (i == m_pPointVector.size() - 1)
			{
				m2 = GetSPLineGet(m_pPointVector[i]->Get3DVector(), m_pPointVector[i - 2]->Get3DVector());
				m3 = GetSPLineGet(m_pPointVector[i]->Get3DVector(), m_pPointVector[i - 1]->Get3DVector());
				x = h00 * m_pPointVector[i - 1]->Get3DVector().x + h10 * m2.x + h01 * m_pPointVector[i]->Get3DVector().x + h11 * m3.x;
				y = h00 * m_pPointVector[i - 1]->Get3DVector().y + h10 * m2.y + h01 * m_pPointVector[i]->Get3DVector().y + h11 * m3.y;
				z = h00 * m_pPointVector[i - 1]->GetSclVector().z + h10 * m2.z + h01 * m_pPointVector[i]->GetSclVector().z + h11 * m3.z;
				Aftor = cVector(x, y, z);

				m_pEdgePoint.push_back(Aftor);
			}
			else
			{
				break;
			}
		

		}
	
	}
	for (int i = 0; i < m_pEdgePoint.size(); i++)
	{
		cVector number = m_pEdgePoint[i] - m_pEdgePoint[(i + 1) % m_pEdgePoint.size()];
		if (m_pEdgePoint[i].z < m_pEdgePoint[(i + 1) % m_pEdgePoint.size()].z - 0.01)
		{
			m_number.push_back(2);


		}
		else if (m_pEdgePoint[i].z > m_pEdgePoint[(i + 1) % m_pEdgePoint.size()].z + 0.003)
		{
			m_number.push_back(0);

		}
		else
		{
			m_number.push_back(1);
		}
	}
	for (int i = 0; i < m_pEdgePoint.size() ; i++)
	{
		cVector Temp;
		int number1 = (i + 1) % m_pEdgePoint.size();
		if(m_pEdgePoint[i].y < m_pEdgePoint[number1].y)
			Temp  = m_pEdgePoint[number1] - m_pEdgePoint[i]   ;
		else
			Temp = m_pEdgePoint[i] - m_pEdgePoint[number1];

		cVector Temp2 =  Temp.cross(cVector(0, 1, 0));
		float x = ToDegree(Temp.angle(cVector(0, 1, 0)));
	
		if (x < 0)
			x *= -1;
		m_pEdgeAngleXYZ.push_back(Temp2);
		m_pEdgeAngle.push_back(cVector(x,0,0));
	
	}
}
void cEdge::GetSP2DLine(bool check )
{

	m_pEdgePoint2D.clear();
	cVector m0;
	cVector m1;
	cVector m2;
	cVector m3;
	cVector Aftor;
	float x;
	float y;
	
	if(check)
	m_pPointVector.push_back(m_pPointVector[0]);
	
	for (int i = 0; i < m_pPointVector.size(); i++)
	{
	
		for (float t = 0; t < 1; t += 0.05)
		{
			float tt = t*t;
			float t1 = 1 - t;
			float t2 = 2 * t;
			float h00 = (1 + t2) * (t1)* (t1);
			float h10 = t * (t1)* (t1);
			float h01 = tt * (3 - t2);
			float h11 = tt * (t - 1);

			if (!i)
			{
				m0 = GetSPLineGet(m_pPointVector[i + 1]->Get2DVector(), m_pPointVector[i]->Get2DVector());
				m1 = GetSPLineGet(m_pPointVector[i + 2]->Get2DVector(), m_pPointVector[i]->Get2DVector());
				x = h00 * m_pPointVector[i]->Get2DVector().x + h10 * m0.x + h01 * m_pPointVector[i + 1]->Get2DVector().x + h11 * m1.x;
				y = h00 * m_pPointVector[i]->Get2DVector().y + h10 * m0.y + h01 * m_pPointVector[i + 1]->Get2DVector().y + h11 * m1.y;
				Aftor = cVector(x, y,0);
				m_pEdgePoint2D.push_back(Aftor);
			}
			else if (i < m_pPointVector.size() - 2)
			{
				m1 = GetSPLineGet(m_pPointVector[i + 1]->Get2DVector(), m_pPointVector[i - 1]->Get2DVector());
				m2 = GetSPLineGet(m_pPointVector[i + 2]->Get2DVector(), m_pPointVector[i]->Get2DVector());
				x = h00 * m_pPointVector[i]->Get2DVector().x + h10 * m1.x + h01 * m_pPointVector[i + 1]->Get2DVector().x + h11 * m2.x;
				y = h00 * m_pPointVector[i]->Get2DVector().y + h10 * m1.y + h01 * m_pPointVector[i + 1]->Get2DVector().y + h11 * m2.y;
				Aftor = cVector(x, y, 0);

				m_pEdgePoint2D.push_back(Aftor);
			}
			else if (i == m_pPointVector.size() - 1)
			{
				m2 = GetSPLineGet(m_pPointVector[i]->Get2DVector(), m_pPointVector[i - 2]->Get2DVector());
				m3 = GetSPLineGet(m_pPointVector[i]->Get2DVector(), m_pPointVector[i - 1]->Get2DVector());
				x = h00 * m_pPointVector[i - 1]->Get2DVector().x + h10 * m2.x + h01 * m_pPointVector[i]->Get2DVector().x + h11 * m3.x;
				y = h00 * m_pPointVector[i - 1]->Get2DVector().y + h10 * m2.y + h01 * m_pPointVector[i]->Get2DVector().y + h11 * m3.y;
				Aftor = cVector(x, y, 0);

				m_pEdgePoint2D.push_back(Aftor);
			}

			else
			{
				break;
			}

		}
	


	}
}
void cEdge::Key(unsigned char  key)
{
	if (m_pEdgePoint.size() <= 0)
		return;
	if (key == ' ')
	{
		m_vpBullet.push_back(new cBullet(m_pEdgePoint[m_nowNumber], m_pEdgePoint[(m_nowNumber + 10) % m_pEdgePoint.size()], m_pEdgeAngleXYZ[m_nowNumber],m_pEdgeAngle[m_nowNumber]));
	}
}