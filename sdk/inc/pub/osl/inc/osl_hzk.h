/*! \file osl_hzk.h
	\brief �ֿ����
*	\author lx
*	\date 2014/02/08
*/
#pragma once

#include "pub\pub.h"


LIB_EXPORT int osl_hzk_is_gbk_char(unsigned char *ch1);

LIB_EXPORT void osl_hzk_init();

/**
* @brief ��ȡ���ĵ���
* @param type 0-12 1-16 2-24
* @param hz �ַ�
* @param pbuff ������
* @return 
*/
LIB_EXPORT void osl_get_cn_bit(int type , unsigned char * hz ,  unsigned char *pbuff);
/**
* @brief ��ȡӢ�ĵ���
* @param type 0-12*24
* @param phz �ַ�
* @param pbuff ������
* @return 
*/
LIB_EXPORT void osl_get_en_bit(int type , unsigned char * phz , unsigned char *pbuff);


LIB_EXPORT void osl_set_gb2312_mode(char mode);