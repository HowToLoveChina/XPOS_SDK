/*! \file power_init.h
	\brief ��Դ����
*	\author lx
*	\date 2014/02/08
*/
#pragma once

#include "pub\pub.h"


/**
* @brief ��Դ�����ʼ��
* @param 
* @return 
*/
LIB_EXPORT void power_init(void);

/**
* @brief ���¼�ʱ����������߻�ػ�ʱ��
* @param 
* @return 
*/
LIB_EXPORT void resetpowersuspendtimeout();


/**
* @brief �Ƿ�رձ���
* @param 0���رձ���  1�Զ��رձ���
* @return 
*/
LIB_EXPORT void setbacklightflag(int bpowersuspend);

/**
* @brief �Ƿ��Զ�����
* @param 0�ر��Զ�����  1�Զ�����
* @return 
*/
LIB_EXPORT void setpowersuspend(int bpowersuspend);