#pragma once

#include "pub\tlv\tlv_func.h"

//ҵ����̲������

#define MAX_LEN_CARD_NUM			19	// ������󳤶�
#define LEN_CARD_EXP_DATE			4	// ����Ч��

#define PIN_PSW_MAX_LEN				8    // PIN�������ݳ���
#define OPER_PSW_LEN				6    // ����Ա���볤��
#define GOODS_NO_STR_LEN			30   // ��Ʒ���볤��
#define AMOUNT_STR_MAX_LEN			12   // ����󳤶�
#define EVENT_NO_STR_LEN			30   // ��Ŀ���볤��
#define TRANS_CERT_NO_LEN			6    // ����ƾ֤�ų���
#define CARD_NUM_MAX_LEN			19   // ������󳤶�

#define SERVICE_ENTRY_MODE_LEN		3    // ��������뷽ʽ��
#define CARD_SEQ_NUM_LEN			3    // ��Ƭ���к�
#define SERCICE_COND_MODE_LEN		2    // �����������
#define SERVICE_PINCAPCODE_LEN		2    // �����PIN��ȡ��
#define AUTH_MECH_CODE_LEN			11   // ��Ȩ�������볤��
#define AUTH_CODE_LEN				6    // ��Ȩ�볤��
#define MSG_TYPE_CODE_LEN			2    // ��Ϣ������
#define CARD_CORP_CODE_LEN			3    // �������ÿ���˾���볤��
#define CERTIFICATE_TYPE_LEN		2    // �ֿ���֤�������볤��
#define CERTIFICATE_NUM_LEN			20   // �ֿ���֤��������󳤶�
#define ACQ_INSTITUE_LEN			11   // �յ��б�ʶ�볤��
#define ISS_CODE_LEN				11   // �����б�ʶ�볤��
#define POS_CENTER_CODE_LEN			12   // POS���ı�ʶ�볤��  
#define POS_TRANS_TYPE_LEN			4    // �������ͳ���
#define POS_TRANS_BATCH_NO_LEN		6    // �������κ�
#define POS_TRANS_DATE_LEN			4    // �������� MMDD
#define POS_TRANS_TIME_LEN			6    // ����ʱ�� HHMMSS
#define POS_REFER_NO_LEN			12   // �ο��ų���
#define POS_PONITS_LEN				10   // ������ֵ������
#define MSG_RSP_CODE_LEN			2    // Ӧ���볤��
#define POS_TERMINAL_CODE_LEN		8	 // �ն˴��볤��
#define POS_MERCHANT_CODE_LEN		15   // �̻�����
#define POS_CURRENCY_CODE_LEN		3    // ���׻��Ҵ���
#define POS_TRANS_PROCODE_LEN		6    // ���״�����
#define POS_SETTLE_TOTAL_LEN		30   // �����ܶ����
#define POS_INTO_ACCOUNT_NUM_LEN	28	 // ת���˻���־�볤��  
#define POS_PHONE_NUM_LEN			11   // �ֻ����볤��
#define POS_ORDER_NUM_LEN			6    // ԤԼ���볤��
#define POS_CVN2_NUM_LEN			3    // CVN2�볤��
#define POS_CERT_NUM_LAST_LEN		6    // ���֤�����6λ
#define POS_ENCRYPT_KEY_LEN			100  // POS�����·�����Կ�������� 
#define POS_TRACE_1_DATA_LEN		100  //һ�ŵ����ݳ���
#define POS_TRACE_2_DATA_LEN		37   // ���ŵ����ݳ���
#define POS_TRACE_3_DATA_LEN		104  // ���ŵ����ݳ���
#define POS_TRACE_2_DATA_BCD_LEN	19   // ���ŵ����ݳ���
#define POS_TRACE_3_DATA_BCD_LEN	52	 // ���ŵ����ݳ���
#define POS_TRANS_BILLS_LEN			3    // ���ױ������ַ�������
#define POS_YEAR_LEN				4    //���
#define POS_CARDHOLDTYPE_LEN		20   //֤�����볤��
#define POS_ISS_EXT_LEN				20   // �����б�ʾ��չ
#define POS_CUP_EXT_LEN				20   // ��������ʾ��չ
#define POS_ACQ_EXT_LEN				20   // �յ��б�ʾ��չ 
#define POS_MONEY_TYPE_LEN			3    //�������
#define POS_WIN_POINT_LEN			12   //��������
#define POS_FIRST_HANDPAY_LEN		12   //����������
#define POS_ONCE_HANDPAY_LEN		12   //ÿ��������
#define POS_DATA_634_LEN			60   //63.4�򳤶�
#define POS_IC_AID_MAX_LEN			32   // AID��󳤶�
#define POS_IC_TC_MAX_LEN			16   // IC������֤����󳤶�
#define POS_DATA_44_LEN				50	 //44�򳤶�
#define FIELD_55_MAX_SIZE			512

typedef struct _st_tmf_param
{
	char sPan[MAX_LEN_CARD_NUM + 1];
	char sAmt[AMOUNT_STR_MAX_LEN + 1];
	char sExpData[LEN_CARD_EXP_DATE + 1];
	char sCardSerialNo[CARD_SEQ_NUM_LEN + 1];
	char sTrack2[POS_TRACE_2_DATA_LEN + 1];
	char sTrack3[POS_TRACE_3_DATA_LEN + 1];
	char sInputMode[SERVICE_ENTRY_MODE_LEN + 1];
	char sPin[PIN_PSW_MAX_LEN + 1];
	int  nPinLen;
	char sField55[FIELD_55_MAX_SIZE+1];
	int nFilde55Len;

	char vCarduseMode[2 + 1];	//��������뷽ʽ�루���ڱ������͵Ŀ�ʹ�÷�ʽ��
	char vPinInputmode[1 + 1];	//����㷽ʽ���Ƿ����pin��
	char bPIN_getcode;			//PIN��ȡ��
	char bOnlinPin;				//�Ƿ���������pin
	char bEncryType;			//PIN���ܷ���
	char bMagEncry;				//�ŵ����ܱ�־
	char vTmCardmode[2];		//�ն˶�ȡ(��)����
	char vICcode[2];			//IC����������
	char vPartMark[2];			//֧�ֲ��ֿۿ�ͷ������ı�־
	char vCardUse[32];			//��ʹ�÷�ʽ�����ڼ�¼����
	char vChName[45 +1];		//�ֿ�������
	char vAccountType[4];		//�˻����ͣ����ڻ������ѽ���ʱҪ����д��
	char * title;
	int eTransType;

	//����
	st_tlv_data tlv_send ;

	//����
	st_tlv_data tlv_recv ;

	//ԭ������Ϣ
	st_tlv_data old_data ;

	char reversed;
	char mac;
	char manage;
	const char * check_list;

}st_tmf_param;
