#ifndef _MOUSE_H_
#define _MOUSE_H_

/***���ṹ***/
typedef struct                                                  
{
	int x;			//��������
	int y;			//���������
	int key;		//��ť��״̬��0,1λ�ֱ��ʾ���Ҽ�����λΪ1��ʾ���£�0��ʾ�ɿ�
}MOUSE;                  //���ṹ

extern MOUSE mouse;//����ȫ�ֱ���������Ŀ���̹���ͬһ�����ṹ
//��ÿ������Ҫ���ģ��ļ���Ӧ���� mouse.h

 
/***����ʼ��***/
void Mouse_Init(void);
/***��긴λ***/
void MouseInit(void);
/***��귶Χ***/
void MouseRange(int x1, int y1, int x2, int y2);
/***�õ���갴��״̬(�������������)***/
int MouseBut(MOUSE * mouse);
/***�õ����λ�úͰ���״̬***/
int MouseGet(MOUSE *mouse);
//int MouseMove(MOUSE *mouse);
void MouseSpeed(int x, int y);
void SetMouseSen(int x,int y);
/***�������***/
void MouseOff(MOUSE *mouse);
/***�����������λ��***/
void MouseSet(int x,int y);
//void MouseSet1(int x,int y);
/***64k�����***/
void MouseOn(MOUSE mouse);
/***64k�����ʾ***/
void MouseShow(MOUSE *mouse);
/***256�����***/
//void MouseOn1(MOUSE mouse);
/***256�����ʾ***/
//void MouseShow1(MOUSE *mouse);
/***�ж�����Ƿ���ָ�������ڲ�***/
int MouseIn(int x1, int y1, int x2, int y2);
/***�ж������ĳһλ�õİ�ѹ״̬***/
int MousePress(int x1, int y1, int x2, int y2);
/***�õ�ĳһ�����ɫֵ***/
unsigned int Getpixel64k(int x, int y);
/***�õ�ĳһ�����ɫֵ***/
//unsigned int Getpixel256(int x, int y);

/***�����***/

void draw_mouse(int mx,int my);

void CurShow(void);

void Cursor(int x,int y,int flag);

void Curinit(void);

void Curhide(void);

void getmouse(int *button,int *x,int *y);

int MouseX(MOUSE* mouse);

int MouseY(MOUSE* mouse);
int  MouseKey(MOUSE* mouse);
void BarShow(MOUSE* mouse);
void BarOn(MOUSE mouse);
 
#endif
