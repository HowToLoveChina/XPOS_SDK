#pragma once

#include "xGui/inc/xgui_pub.h"
#include "xGui/inc/2ddraw.h"


typedef struct __st_datetime{
	int nYear;				//��
	int nMonth;				//��
	int nDay;				//��
	int nHour;				//ʱ
	int nMinute;			//��
	int nSecond;			//��
	int m_currentSel;		//��ǰ���㣬0-�꣬1-�£�2-�գ�3-ʱ��4-�֣�5-��
	char firstTimePress;	//��ǰ�����Ƿ��ǻ�ȡ��������һ������,0-�ǣ�1-��
}DATETIME_ST;

int dateTimeInput_Show(DATETIME_ST * pdt);