#pragma once

int uninpay_init(char *app_path);



//�������ܡ�������
//����˳���ֱ���淶 ��32��֧�ֵĽ�������˵��
typedef enum _eTRANSTYPE
{
	FUNC_BALANCE = 0,			/**< ��ѯ*/
	//������
	FUNC_SALE,				/**< ����*/
	//Ԥ��Ȩ��
	FUNC_PREAUTH,				/**< Ԥ��Ȩ*/
	FUNC_AUTHSALE,				/**< Ԥ��Ȩ�������*/
	FUNC_AUTHSALEOFF,			/**< Ԥ��Ȩ���֪ͨ*/
	FUNC_AUTHSETTLE,			/**< Ԥ��Ȩ����*/
	FUNC_ADDTO_PREAUTH,			/**< ׷��Ԥ��Ȩ*/
	//�˻���
	FUNC_REFUND ,				/**< �˻�*/
	//������
	FUNC_VOID_SALE,			/**< ���ѳ���*/
	FUNC_VOID_AUTHSALE,			/**< Ԥ��Ȩ��ɳ���*/
	FUNC_VOID_AUTHSETTLE,		/**< ���㳷��*/
	FUNC_VOID_PREAUTH,			/**< Ԥ����Ȩ����*/
	FUNC_VOID_REFUND,			/**< �����˻�*/
	//������
	FUNC_OFFLINE,				/**< ���߽���*/
	FUNC_ADJUST,				/**< �������*/
	//����Ǯ����
	FUNC_EP_LOAD,				/**< EPȦ��*/
	FUNC_EP_PURCHASE,			/**< EP����*/
	FUNC_CASH_EP_LOAD,			/**< �ֽ��ֵȦ��     */
	FUNC_NOT_BIND_EP_LOAD,		/**< ��ָ���ʻ�Ȧ�� */
	//������
	FUNC_INSTALMENT,			/**< ���ڸ���*/
	FUNC_VOID_INSTALMENT,		/**< ��������*/
	//������
	FUNC_BONUS_IIS_SALE,		/**< �����л�������*/
	FUNC_VOID_BONUS_IIS_SALE,	/**< ���������л�������*/
	FUNC_BONUS_ALLIANCE,		/**< ���˻�������*/
	FUNC_VOID_BONUS_ALLIANCE,	/**< �������˻�������*/
	FUNC_ALLIANCE_BALANCE,		/**< ���˻��ֲ�ѯ*/
	FUNC_ALLIANCE_REFUND,		/**< ���˻����˻�*/
	FUNC_INTEGRALSIGNIN,		//����Ա����ǩ��
	//�����ֽ���
	FUNC_QPBOC,					/**< ��������*/
	FUNC_EC_PURCHASE,			/**< �����ֽ�����*/
	FUNC_EC_LOAD,				/**< �����ֽ�ָ���˻�Ȧ��*/
	FUNC_EC_LOAD_CASH,			/**< �����ֽ�Ȧ���ֽ�*/
	//FUNC_EC_LOAD_NOT_BIND,		/**< �����ֽ�Ȧ���ָ���˻�*/
	FUNC_EC_NOT_BIND_OUT,		//�����ֽ��ָ���˻�Ȧ��ת��
	FUNC_EC_NOT_BIND_IN,		//�����ֽ��ָ���˻�ת��
	FUNC_EC_VOID_LOAD_CASH,		/**< �����ֽ�Ȧ���ֽ���*/
	FUNC_EC_REFUND,				/**< �����ֽ��ѻ��˻�*/
	FUNC_EC_BALANCE,			/**< �����ֽ�����ѯ*/
	//�޿���
	FUNC_APPOINTMENT_SALE,		/**< �޿�ԤԼ����*/
	FUNC_VOID_APPOINTMENT_SALE,	/**< �����޿�ԤԼ����*/
	//������ֵ��
	FUNC_MAG_LOAD_CASH,			/**< ����Ԥ���ѿ��ֽ��ֵ*/
	FUNC_MAG_LOAD_ACCOUNT,		/**< ����Ԥ���ѿ��˻���ֵ*/
	//�ֻ�оƬ��
	FUNC_PHONE_SALE,			/**< �ֻ�оƬ����*/
	FUNC_VOID_PHONE_SALE,		/**< �����ֻ�оƬ����*/
	FUNC_REFUND_PHONE_SALE,		/**< �ֻ�оƬ�˻�*/
	FUNC_PHONE_PREAUTH,			/**< �ֻ�оƬԤ��Ȩ*/	
	FUNC_VOID_PHONE_PREAUTH,	/**< �����ֻ�оƬԤ��Ȩ*/
	FUNC_PHONE_AUTHSALE,		/**< �ֻ�оƬԤ��Ȩ���*/
	FUNC_PHONE_AUTHSALEOFF,		/**< �ֻ�оƬ���֪ͨ*/
	FUNC_VOID_PHONE_AUTHSALE,	/**< �����ֻ��������*/
	FUNC_PHONE_BALANCE,			/**< �ֻ�оƬ����ѯ*/
	//������
	FUNC_ORDER_SALE,			/**< ��������*/
	FUNC_VOID_ORDER_SALE,		/**< �������ѳ���*/
	FUNC_ORDER_PREAUTH,			/**< ����Ԥ��Ȩ*/
	FUNC_VOID_ORDER_PREAUTH,	/**< ����Ԥ��Ȩ����*/
	FUNC_ORDER_AUTHSALE,		/**< ����Ԥ��Ȩ���*/
	FUNC_VOID_ORDER_AUTHSALE,	/**< ����Ԥ��Ȩ��ɳ���*/
	FUNC_ORDER_AUTHSALEOFF,		/**< ����Ԥ��Ȩ���֪ͨ*/
	FUNC_ORDER_REFUND,			/**< �����˻�*/
	//����
	FUNC_EMV_SCRIPE,			/**< EMV�ű����֪ͨ*/
	FUNC_EMV_REFUND,			/**< EMV�ѻ��˻�*/
	FUNC_PBOC_LOG,				/**< ��PBOC��־*/
	FUNC_LOAD_LOG,				/**< ��Ȧ����־*/
	FUNC_REVERSAL,				/**< ����*/
	FUNC_TC,					
	FUNC_SETTLE,					/**< ����*/
	COUNTTRANSTYPECOUNT,
}TRANSTYPE;

typedef enum _UPAY_RET{
	UPAY_RET_CANCEL = -7,
	UPAY_RET_TIME_OVER = -4,
	UPAY_RET_TERMINATE,

	UPAY_RET_OK = 0,
	UPAY_RET_KEYIN,
	UPAY_RET_MAGTEK,
	UPAY_RET_ICC,
	UPAY_RET_RFID,
	UPAY_RET_FALLBACK_MAGTEK,
	UPAY_RET_FALLBACK_KEYIN,
}UPAY_RET;



typedef struct ___card_reader_info
{
	//input

	//title
	char title[20];
	//amount
	long long amt;
	//trans type
	TRANSTYPE  type;
	//ic data tags
	char icTags[128];
	//ic data tags len
	char icTagsLen;

	
	//output

	//card proc item
	UPAY_RET ret;
	//card pan
	char sPan[20];
	//card expdata
	char sExpData[6];
	//card track2 data
	char sTrack2[37 + 1];
	//card track3 data
	char sTrack3[104 + 1];
	//card Service Code
	char sServiceCode[2 + 1];
	//Card Serial  No
	char sCardSerialNo[4];

	//card IC Data
	char sICdata[512];
	//card IC Data Len
	int nICdatalen;


}cardreader;

// Set Transaction amount
cardreader *cardreader_create(TRANSTYPE type);
// Set Transaction amount
void cardreader_destory(cardreader * info);


// Set Transaction amount
int cardreader_set_amt(cardreader *info , long long amt );
// Set Transaction Title
int cardreader_set_title(cardreader *info , const char *title );

// Add Tag 
int cardreader_add_tag(cardreader *info , const char *tag);


// Card Reader
int cardreader_run(cardreader *info);

// Get IC data
int cardreader_icdata_asc(cardreader *info ,const char * tag , char *buff);

// ic_online Res
int cardreader_ic_onlineRes(cardreader *info ,char *sField55,int nFieldLen);



#define MFSDK_KT_MAINKEY		0x00
#define MFSDK_KT_PINENC			0x01
#define MFSDK_KT_MACENC			0x02
#define MFSDK_KT_MAGDEC			0x03
#define MFSDK_KT_TRANSKEY		0x04


#define MFSDK_ENCRYPT			0x00
#define MFSDK_DECRYPT			0x01


/**
* @brief Save the key in plaintext
* @param [type] Key type, one of MFSDK_KT_MAINKEY to MFSDK_KT_TRANSKEY
* @param [gid] Key Index 0-9
* @param [key] 16-byte key plaintext
* @param [kvc] 4 bytes kvc
* @return 0 succ
*/
int mfsdk_save_plaintext_key(int type, int gid, unsigned char * key, unsigned char *kvc);


/**
* @brief Save the key ciphertext
* @param [type] Key type, one of MFSDK_KT_MAINKEY to MFSDK_KT_MAGDEC
* @param [gid] Key Index 0-9
* @param [key] 16-byte key ciphertext
* @param [kvc] 4 bytes kvc
* @return 0 succ
*/
int mfsdk_save_encrypted_key(int type, int gid, unsigned char * key, unsigned char *kvc);

/**
* @brief Encryption and decryption operation
* @param [type] Key type, one of MFSDK_KT_MAINKEY to MFSDK_KT_MAGDEC
* @param [gid] Key Index 0-9
* @param [mode] MFSDK_ENCRYPT or MFSDK_DECRYPT
* @param [ind] Input data
* @param [size] Data size
* @param [outd] Output Data
* @return 0 succ
*/
int mfsdk_3des_run(int type, int gid, int mode, unsigned char *ind, int size, unsigned char *outd);
