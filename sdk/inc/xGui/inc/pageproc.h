/*! \file pageproc.h
	\brief ȫ����Ϣ����
*	\author lx
*	\date 2014/02/08
*/
#pragma once

#include "xgui_pub.h"
#include "messagedatastruct.h"

/**
* @brief ȫ����Ϣ����
* @param pMsg ��Ϣ�ṹ
* @return  ��������0δ����
*/
LIB_EXPORT int xgui_proc_default_msg(PMESSAGE pMsg);


LIB_EXPORT void xgui_set_return_desktop(unsigned char flag);
LIB_EXPORT unsigned char xgui_get_return_desktop(void);

/**
* @brief ȫ�ִ�������� 
* @param pfunc ȫ�ִ�����
* @return  0�ɹ�
*/
LIB_EXPORT int xgui_default_msg_func_add(void * pfunc);