#pragma once

#include "pub\pub.h"

#ifdef __cplusplus
extern "C"{
#endif


typedef struct __st_qcamp_data{
	int type;
	int length;
	char outdata[512];
}st_qcamp_data;


LIB_EXPORT int atc_qcamp_open(int height, int width);
LIB_EXPORT int atc_qcamp_close();

LIB_EXPORT int atc_qcamp_start(st_qcamp_data * qcamp_data, int timeover1, void * pfun);
LIB_EXPORT int atc_qcamp_start1();
LIB_EXPORT int atc_qcamp_stop();


LIB_EXPORT int atc_qgpio(int index, int val);
LIB_EXPORT int atc_qgpio_ex(int val);

LIB_EXPORT int atc_qr_decode(char * str, int size);
LIB_EXPORT int atc_qr_encode(char * indata, int size, char *outdata);
LIB_EXPORT void atc_qr_code_test();

/* ɨ������
	
	atc_qcamp_open_ex	��ɨ�裬���̿�ʼɨ��ʱ�䣬���Բ���ֱ�ӿ�ʼɨ��

	ɨ��ҳ��
	{
		atc_qcamp_start_ex	��ʼɨ��
		while		// ѭ���ȴ�ɨ����Ϣ
		{
			if (pMsg.MessageId == XM_SCAN_OK) 	
		}
		atc_qcamp_stop_ex
	}

	atc_qcamp_close_ex  �ر�ɨ�裬�ʹ�ɨ����ԣ�û�д򿪲���Ҫ�ر�

*/



LIB_EXPORT int atc_qcamp_open_ex(int width, int height);		//width=0 height =0

LIB_EXPORT int atc_qcamp_close_ex();

//��ʼɨ��
LIB_EXPORT int atc_qcamp_start_ex();
//ֹͣɨ��
LIB_EXPORT int atc_qcamp_stop_ex();

#ifdef __cplusplus
}
#endif	