#ifndef CFPSCAMERA_H
#define CFPSCAMERA_H
#include "cMyInclude.h"
class cFPSCamera
{
public:
	float				g_Angle; // y�� ī�޶� ȸ��
private:
	cVector				m_CamEye; // �ٶ󺸰��ִ� ��ġ
	cVector				m_CamLook; //  �ٶ󺸰��ִ� Ÿ�� ��ġ
	cVector				m_CamUp; // ������
	cVector				m_AngleCamEye; //ȸ���� ���� ��ġ��ǥ
	float				m_xSpeed; //x�� �ӵ�
	float				m_zSpeed;// z�� �ӵ�
	float				m_xAngle; // x��ޱ�
	float				m_yAngle;
	
public:

public:
	cFPSCamera();
	~cFPSCamera();


public:
	void Update();
public:
#pragma region SetCam


	inline void SetEye(cVector _temp)
	{
		m_CamEye = _temp;
	}
	inline void SetUp(cVector _temp)
	{
		m_CamUp = _temp;
	}
	inline void SetEye(float x, float y, float z)
	{
		m_CamEye.x = x;
		m_CamEye.y = y;
		m_CamEye.z = z;
	}
	inline void SetUp(float x, float y, float z)
	{
		m_CamUp.x = x;
		m_CamUp.y = y;
		m_CamUp.z = z;
	}
	inline void SetLook(cVector _temp)
	{
		m_CamLook = _temp;
	}
	inline void SetLook(float x, float y, float z)
	{
		m_CamLook.x = x;
		m_CamLook.y = y;
		m_CamLook.z = z;
	}
	inline void SetxSpeed(float speed) // �ӵ� �������ָ� ������Ʈ�Լ����� ����ؼ� �̵��� // �ڿ������� �̵� �� ����Ű �̵��� ����
	{
		m_xSpeed = speed;
	}
	inline void SetzSpeed(float speed)
	{
		m_zSpeed = speed;
	}
	inline void SetAddXAngle(float angle)
	{
		m_xAngle += angle; //  ���ϱ�

	}
	inline void SetXAngle(float angle) // �׳� ���ֱ�
	{
		m_xAngle = angle;

	}
	inline void SetAddYAngle(float angle)
	{
		const float limit = VIEWUPMAX * 3.14 / 180.0;
		const float limit1 = VIEWDOWNMAX * 3.14 / 180.0;

		m_yAngle += angle;

		if (m_yAngle < -limit1)
			m_yAngle = -limit1;
		if (m_yAngle > limit)
			m_yAngle = limit;


	}
	inline void SetYAngle(float angle)
	{
		m_yAngle = angle;

	}
#pragma endregion

public: // Get�Լ���
#pragma region GetCam

	inline cVector GetAngleEye()
	{
		return m_AngleCamEye;
	}
	inline float		GetXAngle()
	{
		return m_xAngle;
	}
	inline float GetYAngle()
	{
		return m_yAngle;
	}
	inline cVector GetEye()
	{
		return m_CamEye;
	}
	inline cVector GetUp()
	{
		return m_CamUp;
	}
	inline cVector GetLook()
	{
		return m_CamLook;
	}
#pragma endregion

private: //������ ����ʿ��� �Լ���
	void MoveZ(cVector temp);//z��
	void MoveX();
	void MathAngleEye() //���� ����
	{
		glPushMatrix();
		glLoadIdentity();
		glMatrixMode(GL_MODELVIEW);
		glTranslatef(5, 0, 5);
		glRotatef(g_Angle, 0, 1, 0);
		glTranslatef(-5, 0, -5);
		GLfloat matrixMV[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, matrixMV);
		m_AngleCamEye = cVector(matrixMV[14], 15, matrixMV[12]);
		glPopMatrix();

	}
};
#endif // !cFPSCamera_h
