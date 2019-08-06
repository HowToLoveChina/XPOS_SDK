#include "driver/mf_misc.h"
#include "pub/osl/inc/osl_system.h"
#include "pub/osl/inc/osl_BaseParam.h"
#include "xGui/inc/draw_buf.h"
#include "xGui/inc/2ddraw.h"
#include "xGui/inc/xgui_key.h"
#include "xGui/inc/message.h"
#include <string.h>
#include "xGui/inc/pageproc.h"
#include <stdio.h>


static void _paint_msg(char* msg)
{
	char* pstr;
	int yPos = 0;
	//�����л��з������
	while ((pstr = strstr(msg, "\n")) != 0)
	{
		pstr[0] = '\0';
		xgui_TextOut(0, xgui_GetLineTop(yPos) , msg);
		pstr ++;
		msg = pstr;
		yPos ++;
	}

	xgui_TextOut(0, xgui_GetLineTop(yPos) , msg);

}

static void _lcdLight_paint(int nTime ,char * szMsg)
{
	char szContent[128] = {0};
	switch(nTime)	{
	case 30:
		sprintf(szContent,"-> 30 sec\n   1 min\n   3 min\n   10 min\n   30 min\n   %s",szMsg);
		break;
	case 60:
		sprintf(szContent,"   30 sec\n ->1 min\n   3 min\n   10 min\n   30 min\n   %s",szMsg);
		break;
	case 3 * 60:
		sprintf(szContent,"   30 sec\n   1 min\n ->3 min\n   10 min\n   30 min\n   %s",szMsg);
		break;
	case 10 * 60:
		sprintf(szContent,"   30 sec\n   1 min\n   3 min\n ->10 min\n   30 min\n   %s",szMsg);
		break;
	case 30 * 60:
		sprintf(szContent,"   30 sec\n   1 min\n   3 min\n   10 min\n ->30 min\n   %s",szMsg);
		
		break;
	case LCD_LIGHT_MAX:
		sprintf(szContent,"   30 sec\n   1 min\n   3 min\n   10 min\n   30 min\n ->%s",szMsg);
		break;
	default:
		sprintf(szContent," ->30 sec\n   1 min\n   3 min\n   10 min\n   30 min\n   %s",szMsg);
		break;
	}


	xgui_BeginBatchPaint();

	xgui_ClearDC();

	_paint_msg(szContent);

	//xgui_Page_OP_Paint( "Cancel" , "Save");

	xgui_EndBatchPaint();
}

int TimeSet_Show(int nLightTime , char * szMsg)
{
	int presskey;

	int time[6] = {30, 60, 3 * 60, 10 * 60, 30 * 60, LCD_LIGHT_MAX};
	int nCurIndex = 0;
	int nTotalCount = sizeof(time) / sizeof(int);
	int i;
	MESSAGE pMsg;

	_lcdLight_paint(nLightTime , szMsg);

	//��ȡ��ǰֵ�������е�������֮��Ӽ�ֻ���������мӼ���ˢ�µ�ʱ���ٸ��������������ж�ȡ��Ӧ��ֵ
	for (i = 0; i < nTotalCount; ++ i)	{
		if (nLightTime == time[i])		{
			nCurIndex = i;
			break;
		}
	}

	while(1){
		if (xgui_GetMessageWithTime(&pMsg, 100) == MESSAGE_ERR_NO_ERR) {

			if (pMsg.MessageId == XM_KEYPRESS) {
				presskey = pMsg.WParam;

				switch(presskey) {
					case KEY_UP:case KEY_LEFT: case KEY_1 : case KEY_XING:
						nCurIndex = (-- nCurIndex < 0 ? nTotalCount - 1 : nCurIndex);
						_lcdLight_paint(time[nCurIndex] , szMsg);
						break;
					case KEY_DOWN:case KEY_RIGHT: case KEY_2 : case KEY_JING:
						nCurIndex = (++ nCurIndex % nTotalCount);
						_lcdLight_paint(time[nCurIndex] , szMsg);
						break;
					case KEY_QUIT:
						return -1;
					case KEY_OK:	
						return time[nCurIndex];
						break;
					default:
						xgui_proc_default_msg(&pMsg);
						break;
				}
			}
			else{
				xgui_proc_default_msg(&pMsg);
			}
		}
	} 

	return -1;
}

void PowerDownTimeSet_Show()
{
	int nLightTime = osl_lcd_PowerDownTime();
	int nRet = 0;

	nRet = TimeSet_Show(nLightTime , "Disable");
	if(nRet != -1){
		osl_lcd_SetPowerDownTime(nRet);
	}
}

void eneyTimeSet_Show()
{
	int nLightTime = osl_Enercy_Time();
	int nRet=0;
	
	nRet = TimeSet_Show(nLightTime , "Disable");
	if(nRet != -1){
		osl_Enercy_SetTime(nRet);
	}
}

void lcdLightSet_Show()
{
	int nLightTime = osl_lcd_BackLightTime();
	int nRet=0;
	nRet = TimeSet_Show(nLightTime , "Always");

	if(nRet != -1){
		osl_lcd_SetBackLightTime(nRet);
	}
}