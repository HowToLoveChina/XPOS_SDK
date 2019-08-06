#pragma once

#include "upay_pub.h"


static const char m_check_list[] = {39, 0, 3, 11, 41, 42 , 60 ,255};
char * upay_pub_check_list()
{
	return (char *)m_check_list;
}

static void upay_pub_init(st_tmf_param  * tmf_param , char * title , int eTransType)
{
	memset(tmf_param, 0, sizeof(st_tmf_param));

	strcpy(tmf_param->vCarduseMode, "00");		// 00	δָ��  01	�ֹ�	02	����		03	������
	strcpy(tmf_param->vPinInputmode, "2");		// 0	δָ��	1	�����а���PIN		2	�����в�����PIN
	tmf_param->bPIN_getcode = 0;					// �Ƿ���pin
	tmf_param->bOnlinPin = 0;					// �Ƿ���pin
	tmf_param->bEncryType = '0';				// PIN���ܷ���   0��PIN�����֣�δ֪ 	1��ANSI X9.8 Format���������˺���Ϣ��		2��ANSI X9.8 Format�������˺���Ϣ��
	tmf_param->bMagEncry = '0';				// �ŵ����ܱ�־   0�������� 	1������
	tmf_param->vTmCardmode[0] = '6';
	tmf_param->vICcode[0] = '0';
	tmf_param->vPartMark[0] = '1';
	tmf_param->title = title;
	tmf_param->eTransType = eTransType;

	memset( &tmf_param->tlv_send,0x00,sizeof(tmf_param->tlv_send));
	memset( &tmf_param->tlv_recv,0x00,sizeof(tmf_param->tlv_recv));
	memset( &tmf_param->old_data,0x00,sizeof(tmf_param->old_data));

	tmf_param->check_list = upay_pub_check_list();
	tmf_param->mac = 1;
	tmf_param->reversed = 1;
	tmf_param->manage = 0;

}

st_tmf_param  * upay_pub_create( int eTransType )
{
	st_tmf_param *ret =(st_tmf_param *) malloc(sizeof(st_tmf_param));	
	upay_pub_init(ret , (char *)"����" , eTransType);
	return ret;
}

void upay_pub_destory( st_tmf_param * tmf_param )
{
	tlv_free_buff( &tmf_param->tlv_send );
	tlv_free_buff( &tmf_param->tlv_recv );
	tlv_free_buff( &tmf_param->old_data );
	free(tmf_param);
}

