#ifndef CFPSCAMERA_H
#define CFPSCAMERA_H
#include "cMyInclude.h"
class cFPSCamera
{
public:
	float				g_Angle; // y축 카메라만 회전
private:
	cVector				m_CamEye; // 바라보고있는 위치
	cVector				m_CamLook; //  바라보고있는 타켓 위치
	cVector				m_CamUp; // 업백터
	cVector				m_AngleCamEye; //회전후 실제 위치좌표
	float				m_xSpeed; //x축 속도
	float				m_zSpeed;// z축 속도
	float				m_xAngle; // x축앵글
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
	inline void SetxSpeed(float speed) // 속도 지정해주면 업데이트함수에서 계산해서 이동함 // 자연스러움 이동 및 다중키 이동을 위해
	{
		m_xSpeed = speed;
	}
	inline void SetzSpeed(float speed)
	{
		m_zSpeed = speed;
	}
	inline void SetAddXAngle(float angle)
	{
		m_xAngle += angle; //  더하기

	}
	inline void SetXAngle(float angle) // 그냥 값넣기
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

public: // Get함수들
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

private: //내부적 계산필요한 함수들
	void MoveZ(cVector temp);//z축
	void MoveX();
	void MathAngleEye() //추후 수정
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
