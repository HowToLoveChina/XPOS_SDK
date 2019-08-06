/*! \file messagebox.h
	\brief ��ʾ�Ի���
*	\author lx
*	\date 2014/02/08
*/
#ifndef _MESSAGEBOXPAGE_H___
#define _MESSAGEBOXPAGE_H___


#include "xgui_pub.h"

#define MSGBOX_RET_OK		1
#define MSGBOX_RET_QUIT		2
#define MSGBOX_RET_TIMEOUT	3
#define MSGBOX_RET_ANY		-1


/**
* @brief ��ʾ���жԻ���
* @param title �Ի������
* @param msg �Ի�������
* @param pszLeftOp ��ť
* @param pszRightOp �Ұ�ť
* @param timeover ��ʱʱ��
* @return �������
*/
LIB_EXPORT int xgui_messagebox_show(char *title, char *msg , char* pszLeftOp, char* pszRightOp , int timeover);
LIB_EXPORT int xgui_messagebox_showEx(char *title, char *msg , char* pszLeftOp, char* pszRightOp ,int timeover , int flag);

#endif
