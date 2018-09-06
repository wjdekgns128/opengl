#ifndef CVECTOR_H
#define CVECTOR_H
#include <math.h>

class cVector
{
public:
	float x;
	float y;
	float z;

	cVector()
	{
	}
	cVector(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	~cVector()
	{

	}

	float GetVectorSize()
	{
		return sqrtf(this->x * this->x + this->y* this->y + this->z * this->z);
	}
	cVector operator+(const cVector &vec) const
	{
		return cVector(this->x + vec.x, this->y + vec.y, this->z + vec.z);
	}
	cVector operator-(const cVector &vec) const
	{
		return cVector(this->x - vec.x, this->y - vec.y, this->z - vec.z);
	}
	cVector operator*(const float n) const
	{
		return  cVector(this->x * n, this->y *n, this->z *n);
	}
	void normalize()
	{
		float n = GetVectorSize();
		this->x /= n;
		this->y /= n;
		this->z /= n;
	}
	float dot(const cVector &vec) const
	{
		return this->x * vec.x + this->y * vec.y + this->z * vec.z;
	}
	cVector cross(const cVector &vec) const
	{
		return cVector(this->y * vec.z - this->z * vec.y, 
			this->z*vec.x - this->x*  vec.z, 
			this->x*vec.y - this->y * vec.x);
	}

	float angle(cVector &vec) // 두백터 각도 (라디안값)
	{
		return (acos(dot(vec) / (GetVectorSize() * vec.GetVectorSize())));
	}
};

#endif // !CVECTOR_H
