#pragma once
#include "pub/pub.h"

enum{
	READ_CARD_RET_CANCEL,
	READ_CARD_RET_MAGNETIC,
	READ_CARD_RET_IC,
	READ_CARD_RET_RF,
	READ_CARD_RET_TIMEOVER,
	READ_CARD_RET_FAIL
};

enum{
	READ_CARD_MODE_MAG = 0x01,
	READ_CARD_MODE_IC = 0x02,
	READ_CARD_MODE_RF = 0x04
};

typedef struct __st_read_card_in{
	char title[32];
	int trans_type;
	char amt[32];
	int card_mode;
	int card_timeover;
	int pin_input;
	int pin_max_len;
	int pin_timeover;
	int key_pid;
	int pin_key_index;
	char ic_tags[256];
	char card_page_msg[50];
}st_read_card_in;


typedef struct __st_read_card_out{
	int card_type;
	char exp_data[8];
	char ic_data[1024];
	int ic_data_len;
	char pan[32];
	char pan_sn[8];
	char pin_block[32];
	char ksn[10];
	int  pin_len;
	char track2[140];
	int track2_len;
	char track3[140];
	int track3_len;
	char vChName[45 +1];
}st_read_card_out;

//���׽����
#define EMVAPI_RET_TC	 0	 //TC��׼
#define EMVAPI_RET_ARQC	 1	 //��������
#define EMVAPI_RET_AAC	 -1	 //���׾ܾ�
#define EMVAPI_RET_AAR	 -2	 //������ֹ
#define EMVAPI_RET_CANCEL	-3	//�û�ȡ��
#define EMVAPI_RET_TIMEOUT	-4	//���׳�ʱ


/*************************************************************************************
��    Ȩ������ħ�����ӿƼ����޹�˾
��	  �ߣ�zhiyu
��    �ܣ������Ķ�����������
���������card_in��������Ҫ����Ĳ���	
���������card_out��������ɺ�����Ĳ���
��    �أ�
     	EMVAPI_RET_TC	 0	 //TC��׼
		EMVAPI_RET_ARQC	 1	 //��������
		EMVAPI_RET_AAC	 -1	 //���׾ܾ�
		EMVAPI_RET_AAR	 -2	 //������ֹ
		EMVAPI_RET_CANCEL	-3	//�û�ȡ��
*************************************************************************************/
LIB_EXPORT int emv_read_card(st_read_card_in *card_in, st_read_card_out *card_out);

LIB_EXPORT void EMV_iKernelInit(void);

LIB_EXPORT void bInputPin(int (*InputPin)(char *,char *,char ,char *));