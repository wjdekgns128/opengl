#ifndef _CCAM_H
#define _CCAM_H
#include "cMyInclude.h"
class cCam
{
public:
protected:
	cVector				m_CamEye; // �ٶ󺸰��ִ� ��ġ
	cVector				m_CamLook; //  �ٶ󺸰��ִ� Ÿ�� ��ġ
	cVector				m_CamUp; // ������
	cVector				m_AngleCamEye; //ȸ���� ���� ��ġ��ǥ
	float				m_xSpeed; //x�� �ӵ�
	float				m_zSpeed;// z�� �ӵ�
	float				m_xAngle; // x��ޱ�
	float				m_yAngle;
	int					m_windowsX;
	int					m_windowsY;
public:

public:
	cCam();
	~cCam();


public:
	virtual void Update() = 0;
	virtual void MoveZ(cVector temp) = 0;//z��
	virtual void MoveX() = 0;
	virtual void MouseMove(int x, int y) = 0;
	virtual void KeyBoard(int Type, unsigned char key) = 0;
public:
#pragma region SetCam
	inline void SetWindowns(int _x,int _y)
	{
		m_windowsX = _x;
		m_windowsY = _y;
	}

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
	inline void SetY(float y)
	{
		m_CamEye.y = y;
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

};
#endif // !cFPSCamera_h
