#ifndef __RES_H__
#define __RES_H__

#include "xgui_pub.h"

typedef struct _gui_res{
	int nResType;	//��Դ����
	int nWidth;		//��Դ���
	int nHeight;	//��Դ�߶�
	int nID;		//��ԴID
	unsigned char *pData;//��Դ����
} GUIRES;

struct _guires_list{
	GUIRES * pGuiRes;
	struct _guires_list * pNext;
	struct _guires_list * pPrev;
	int nPosX;
	int nPosY;
	int nDrawMode;
};

#define  RES_TYPE_IMAGE		0x01
#define  RES_TYPE_TEXT		0x02
#define  RES_TYPE_SOUND		0x03
#define  RES_TYPE_VIDEO		0x04
#define  RES_TYPE_BWIMAGE   0x05


#endif
