#ifndef CMYDEFINE_H
#define CMYDEFINE_H


#ifndef SAFE_DELETE
#define SAFE_DELETE(p)			{if(p) {delete (p);     (p)=NULL;}}
#endif
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p)			{if(p) {delete[] (p);     (p)=NULL;}}
#endif

#define KEYBOARDDOWN 0
#define KEYBOARDUP 1

#ifndef M_PI
#define M_PI	3.1415926535
#endif
#define ToRadian(degree)(degree * (M_PI / 180.0f))
#define ToDegree(radian )(radian  * (180.0f  / M_PI))
#define RGBFloat(a){(float)((float)a/255.0)}

#define VIEWUPMAX 89 //카메라 y축시점 위로 최대치
#define VIEWDOWNMAX 89  // 아래로
#define MAX(A,B) (A > B ? A : B)
#define MIN(A,B) ( A > B ? B : A)
enum TYPE
{
	EMPTY = 0,
	START = 1,
	END = 2,
	WALL,
	HARDWALL,
	PORTAL,
};
#endif // !cMyDefine_H
