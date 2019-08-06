/*! \file ime.h
	\brief ���뷨
*	\author lx
*	\date 2014/02/07
*/

#ifndef __T9IME_H__
#define __T9IME_H__

#include "xgui_pub.h"
	
#define IME_MODE_T9PY			(1<<0)		//���뷨���л�
#define IME_MODE_ALPHABET_UP	(1<<1)		//�������д��ĸ
#define IME_MODE_ALPHABET_LOW	(1<<2)		//������Сд��ĸ	
#define IME_MODE_NUMBER			(1<<3)		//��������������
#define IME_MODE_HANDWRITE		(1<<4)
#define IME_MODE_T9BH			(1<<5)		//������ƴ�����뺺��

#define IME_HANDWRITE_AUP			(0)
#define IME_HANDWRITE_ALOW			(1)
#define IME_HANDWRITE_NUMBER		(2)
#define IME_HANDWRITE_SYMBOL		(3)
#define IME_HANDWRITE_CHS			(4)

#define IME_MODE_DEFAULT	(IME_MODE_T9PY | IME_MODE_ALPHABET_UP | IME_MODE_ALPHABET_LOW | IME_MODE_NUMBER)

#define IME_POS_DEFAULT			-1

#define IME_OPMODE_ONLYEMPTY	0
#define IME_OPMODE_ALWAYS		1

/**
* @brief �������뷨��ʽ
* @param nDefMode Ĭ�ϵķ�ʽ
* @param nAllowMode ��������뷨�л�ģʽ
* @param bPassword �Ƿ������ʽ
* @param bSmsInput =1�����ַ��� =0���ֽ���
* @return 
*/
LIB_EXPORT int xgui_ImeSetMode(int nDefMode, int nAllowMode, int bPassword, int bSmsInput);
/**
* @brief ��ȡ���뷨��ʽ
* @param pDefMode Ĭ�ϵķ�ʽ
* @param pAllowMode ��������뷨�л�ģʽ
* @param pbPassword �Ƿ������ʽ
* @return 
*/
LIB_EXPORT int xgui_ImeGetMode(int *pDefMode, int *pAllowMode, int *pbPassword);
/**
* @brief ����������ʾ����
* @param szLeftOp ��ť��ʾ
* @param nMode ģʽ
* @return 
*/
LIB_EXPORT void xgui_ImeSetOpInfo(char * szLeftOp, int nMode);
/**
* @brief ���뷨����
* @param pcInputBuffer ���뻺����
* @param nMaxLength ��������С
* @param pPosition ��ʼλ��
* @param pcHelpString ��ʾ����
* @return 
*/
LIB_EXPORT int xgui_ImeStartInput(char * pcInputBuffer, int nMaxLength, int * pPosition, char * pcHelpString);





#endif

