#pragma once

#include "..\inc\emv_input_public.h"

/*
*	ֻ�������ֵĽ��档Ҳ�������������������롣�����뷨��ҳ��һ����Ϊ���У����б���Ϊ��һ�У��ڶ��к͵����н�����ʾ�������������ʾ���������
*/
 
typedef struct _inputNum_st
{
	char* title;	//���⣬����һ��
	char* header;	//��һ����ʾ��
	int timeout;	//��ʱʱ��,msΪ��λ
	int maxLength;	//�����������󳤶�
	int minLength;	//�����������С����
	int len_null;	//�Ƿ�����0����
	char* outBuff;	//[OUT] �������ݻ����������ⲿ����
	char argot;		//�Ƿ���Ҫ������ֵ�������봦����
	char pwType;	//�Ƿ����������ͣ�1�ǣ�0��������������ͣ�������������ʾ*
	char showFooter;//�Ƿ���ʾ�����е���ʾ����
	char inputEN;	//�Ƿ�֧������Ӣ����ĸ
	int inputAmt;
	int usescan;
}INPUTNUM_ST;

int emv_inputNumberString_page(INPUTNUM_ST* inputNumSt);
