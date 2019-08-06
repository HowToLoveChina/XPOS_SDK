#ifndef _DEF_HEAD_H_
#define _DEF_HEAD_H_

#ifdef WIN32
	#ifdef USE_DLLMODE
		#ifdef UMS_DLL_EXPORTS
		#define UMS_API __declspec(dllexport)
		#else
		#define UMS_API __declspec(dllimport)
		#endif
	#else
		#define UMS_API
	#endif
#else
	#define UMS_API
#endif



#ifdef HX_APP_VARIABLES
    #define EXTERN 
#else
    #define EXTERN extern 
#endif

//#include "struct.h"
//#include "coredef.h"
//#include "poslib.h" 

typedef unsigned char	uchar;
typedef unsigned char	byte;
typedef const char		cchar;
typedef unsigned int	uint;
typedef const int		cint;
typedef unsigned short	ushort;
typedef unsigned long	ulong;


#ifdef WIN32
#define __FUNCTION__	""
#endif

//#define Icc_Close Icc_Release

/**<��������*/
typedef enum                    /**<��ֵ���ݲ�ͬ���̻��߶���*/
{
    UKEY_1 = 0x01,              /**<���ּ�1*/
    UKEY_2 = 0x02,              /**<���ּ�2*/
    UKEY_3 = 0x03,              /**<���ּ�3*/
    UKEY_4 = 0x04,              /**<���ּ�4*/
    UKEY_5 = 0x05,              /**<���ּ�5*/
    UKEY_6 = 0x06,              /**<���ּ�6*/
    UKEY_7 = 0x07,              /**<���ּ�7*/
    UKEY_8 = 0x08,              /**<���ּ�8*/
    UKEY_9 = 0x09,              /**<���ּ�9*/
    UKEY_0 = 0x0a,              /**<���ּ�0*/
    UKEY_ENTER   = 0x10,        /**<ȷ�ϼ�*/
    UKEY_CANCEL  = 0x11,        /**<ȡ����*/
    UKEY_UP      = 0x12,        /**<���Ϸ�ҳ��*/
    UKEY_DOWN    = 0x13,        /**<���·�ҳ��*/
    UKEY_FUN     = 0x14,        /**<���ܼ�*/
    UKEY_BACK    = 0x15,        /**<�˸��*/
    UKEY_POINT   = 0x16,        /**<���*/
    UKEY_LETTER  = 0x17,        /**<��ĸ��*/
    UKEY_MENU    = 0x18,        /**<�˵���*/
    UKEY_F1  = 0x19,            /**<F1��*/
    UKEY_F2  = 0x1A,            /**<F2��*/
    UKEY_F3  = 0x1B,            /**<F3��*/
    UKEY_F4  = 0x1C             /**<F4��*/
} KEY_VALUE;


//2.2.2	ϵͳ��API

//�ն���Ϣ�ṹ��
typedef struct
{
	byte	Terminal[20];	//�ն��ͺ�,�����(����+�ͺ�,PAX��XGD��LND��NLD��VFI��HZR��SYD)
	byte	SN[40];			//�ն�Ӳ�����к�
	int		Disp_X;			//�����������
	int		Disp_Y;			//�����������
	int		Disp_Line1;		//��������Ļ��ʾ����
	int		Disp_Line2;		//С������Ļ��ʾ����
	int		Disp_Chinese;	//һ����ʾ�����ַ�������
	int		Disp_Character;	//һ����ʾӢ�ġ������ַ�������(С����)
}TERMINALINFO;

//���ط��������Ͷ���
typedef int (*ServerFunc)(const char *pszAppName, void *pvInData, int iInLen, void *pvOutData, int *piOutLen);

//���ط������Խṹ��
typedef struct _ServerAttr
{
    char szServerName[32];    //��������
    ServerFunc pServerFunc;   //������ָ��
    int iVerSion;             //�������汾
} ServerAttr;

//��������ö��
typedef enum
{
ULANGUAGE_CHINESE =  0,   //����
ULANGUAGE_ENGLISH,        //Ӣ��
ULANGUAGE_JAPANSES        //����
}ULanguage;

//ϵͳ��API����ö��
typedef enum
{
	USYS_PARAERROR = -2,  //������
	USYS_FAIL      = -1,  //ʧ��
	USYS_SUCCESS    = 0,   //�ɹ�
	USYS_FIRST     = 1,   //������º��һ������
	USYS_NOFIRST   = 2    //����ǵ�һ������
}USysStatus;

//2.2.3	��ʾ��API

//��ʾ��API�����붨��
typedef enum
{ 
	SCREEN_MAIN,     //����
	SCREEN_GUEST	 //����
} DispStatus;

typedef enum
{
	UDISP_DEV_FAIL  =-3,		//�豸ԭ��ʧ��
	UDISP_FILE_FAIL =-2,		//�ļ�ԭ��ʧ��
	UDISP_FAIL     	=-1,		//δ֪ԭ��ʧ��
	UDISP_SUCCESS  	=0			//�ɹ�
} ScreenType;

//2.2.5	������API

#define UMAX_RSA_MODULUS_LEN   512   //RSA���ģ����
#define UMAX_RSA_PRIME_LEN     256   //RSA���ģ��������
//������API�����붨��
typedef enum
{
	UUTIL_TIMEOUT        = -3,    //���볬ʱ
	UUTIL_CANCEL         = -2,    //����ȡ��
	UUTIL_FAIL           = -1,    //ʧ��
	UUTIL_SUCCESS        =  0	    //�ɹ�
} UtilStatus;
//�����ά���ʽ����
typedef enum
{
	UCODE_QRCODE,
	UCODE_PDF417,
	UCODE_GMCODE,
	UCODE_CODE128,
	UCODE_CODE39,     
	UCODE_EAN13,     
	UCODE_EAN128
} BarCode;
//RSA��Կ�ṹ����
typedef struct 
{
	uint   uiBits;   //ģλ��,bit��λ
	byte   ucModulus[UMAX_RSA_MODULUS_LEN];   //ģ
	byte   ucExponent[UMAX_RSA_MODULUS_LEN];  //ָ��
}URSAPUBLICKEY;
//RSA˽Կ�ṹ����
typedef struct 
{
	uint   uiBits;    //ģλ��,bit��λ
	byte   ucModulus[UMAX_RSA_MODULUS_LEN];   //ģ
	byte   ucPublicExponent [UMAX_RSA_MODULUS_LEN];  //��Կָ��
	byte  ucExponent[UMAX_RSA_MODULUS_LEN];   //˽Կָ��
	byte   ucPrime[2][UMAX_RSA_PRIME_LEN];     //pq����,��������
	byte   ucPrimeExponent[2][UMAX_RSA_PRIME_LEN]; //CRTָ��,������ָ������ֵ
	byte   ucCoefficient[UMAX_RSA_PRIME_LEN];  //CRTϵ��,��������������ֵ
}URSAPRIVATEKEY;
//RSA�㷨��Կ����ö��
typedef enum 
{
	URSA_KEY_LEN_512,
	URSA_KEY_LEN_1024,
	URSA_KEY_LEN_2048
}URSAKeyLen;
//RSA�㷨ָ��ö��
typedef enum 
{
	URSA_EXP_3,       //0x03
	URSA_EXP_10001    //0x10001
}URSAEXP;
//ǩ��������ö��
typedef enum
{
	USIGNATURE_INT,         //����ǩ����
	USIGNATURE_EXT_COM1,    //����PinPad��,�������ǩ����,��ӦUPORT_COM1
	USIGNATURE_EXT_COM2,    //��������COM��ǩ����,��ӦUPORT_COM2
	USIGNATURE_EXT_COM3,    //��������COM��ǩ����,��ӦUPORT_COM3
	USIGNATURE_EXT_COM4,    //��������COM��ǩ����,��ӦUPORT_COM4
	USIGNATURE_EXT_COM5,    //��������COM��ǩ����,��ӦUPORT_COM5
	USIGNATURE_EXT_USB1,   //����PinPad��,�������ǩ����,��ӦUPORT_USB1
	USIGNATURE_EXT_USB2,   //��������USB��ǩ����,��ӦUPORT_USB2
	USIGNATURE_EXT_USB3,   //��������USB��ǩ����,��ӦUPORT_USB3
}USignaturePad;

//2.2.6	ͨѶ��API

//SSL�������
typedef int USSL_HANDLE;

//ͨѶ��ʽö��
typedef enum
{
	UCOMM_GPRS, //GPRS ͨѶ
	UCOMM_RS232, //RS232 ͨѶ
	UCOMM_WIFI, //WIFI ͨѶ

	UCOMM_CDMA,       //CDMAͨѶ
	UCOMM_IP,         //��̫��IPͨѶ
	UCOMM_MODEM,       //MODEMͨѶ
} CommMode;

//ͨѶ�෵��ֵö��
typedef enum
{ 
	UCOMM_SSL_RESOURCE             = -17, //����SSL�������
	UCOMM_SSL_NONSUPPORT           = -16, //��֧�ֵ��ļ���ʽ��Э��汾�������׼�
	UCOMM_SSL_CERT_NOT_YET_VALID   = -15, //�Է�֤�黹δ��Ч
	UCOMM_SSL_CERT_HAS_EXPIRED     = -14,  //�Է�֤���ѹ���
	UCOMM_SSL_NOCONNECT            = -13,  //SSL��δ����
	UCOMM_SSL_SET_CIPHER_FAIL      = -12,  //�����㷨�׼�ʧ��
	UCOMM_SSL_LOAD_KEY_FAIL        = -11,  //����˽Կʧ��
	UCOMM_SSL_LOAD_CERT_FAIL       = -10,  //����֤��ʧ��
	UCOMM_SSL_LOAD_CA_FAIL         = -9,  //����CAʧ��
	UCOMM_DEVICE_UNAVAILABLE       = -8,   //�費����
	UCOMM_PARA_ERR                 = -7,   //������
	UCOMM_CONNECT_ERR              = -6,  //�޷�����
	UCOMM_CONNECTING               = -5,   //ͨѶ������,PPP������
	UCOMM_LOGOFF                   = -4,   //ͨѶ��·�Ͽ�
	UCOMM_CANCEL                   = -3,   //����ȡ��
	UCOMM_TIMEOUT                  = -2,   //��ʱ
	UCOMM_FAIL                     = -1,   //ʧ��
	UCOMM_SUCCESS                  =  0,  //�ɹ�
	UCOMM_LINK_OK                  =  1    //ͨѶ��·OK
} CommStatus;

//�Ҷ�ģʽö��
typedef enum 	/*�Ҷ�ģʽ*/
{
	UHANGUP_FAST,/*���ٹҶ�,��������������ֻ�Ҷ�SOCKET�Ҳ���tcpwait*/
//	UHANGUP_DELAY, /*���Ҷ�,��������������ֻ�Ҷ�SOCKET����tcpwait*/
	UHANGUP_FAST_PPP, /*ֻ��������߹Ҷ�PPP��SOCKET�Ҳ���tcpwait*/
//	UHANGUP_DEALY_PPP, /*ֻ��������߹Ҷ�PPP��SOCKET����tcpwait*/
//    UHANGUP_EXIT
}HangUpMode;

//��������ע������ṹ��(GPRS��CDMA)
typedef struct
{
	char  NetUsername[41] ; /* ����modem����PPP��·ʱҪ�õ����û��� */
	char  NetPassword[21] ; /* ����modem����PPP��·ʱҪ�õ������� */
	char  ModemDialNo[21] ; /*����modem����PPP��·ʱʹ�õĽ������,����ATD+�������ʽ,�硰ATD*99***1#�����ʽ*/
	char  GprsApn[41] ;	/*�ƶ�APN����*/
	char  SimPin[11] ;	/*SIM��pin*/
	char  WorkMode ;   /*0x01������; 0x02������*/
	char  DtrFlag;	/*�Ƿ�������,0x00������,0x01������*/
    char  PppType;    /*Э������*/
}PPPLOGINCONFIG;

//��̫��ͨѶ�����ṹ��
typedef struct
{
	byte DHCP;        /*�Ƿ���DHCP,0-��,1-��*/
	char  IP[16] ;	/*����IP��ַ*/
	char Gateway[16] ;	/*��������*/
	char  Mask[16] ;	/*������������*/
    char  Dns1[16];/*DNS*/
    char  Dns2[16];/*DNS*/
}IPCONFIG;

#if 0
//WIFI�����ʽ
typedef enum
{ 
	WLN_KEY_TYPE_NOKEY,  /*��ʹ������*/
	WLN_KEY_TYPE_HEX,    /*ʹ��ʮ�����Ƶ������ʽ*/
	WLN_KEY_TYPE_ASCII  /*ʹ��ASCII�������ʽ*/
}UWLNKEYTYPE;

//WIFI��ȫ����ģʽ
typedef enum
{ 
	WLN_NET_SEC_NONE,       /*��ʹ�ð�ȫ����ģʽ*/
	WLN_NET_SEC_WEP_OPEN,   /*ʹ�ÿ�����Կ��WEPģʽ*/
	WLN_NET_SEC_WEP_SHARED, /*ʹ�ù�����Կ��WEPģʽ*/
	WLN_NET_SEC_WPA,        /*ʹ��WPAģʽ*/
	WLN_NET_SEC_WPA2,        /*ʹ��WPA2ģʽ*/
	WLN_NET_SEC_WPA_PSK,     /*ʹ��WPA-PSKģʽ*/
	WLN_NET_SEC_WPA2_PSK     /*ʹ��WPA2-PSKģʽ*/
}UWLNNETSEC;
#endif

/*WIFI��ȫ����ģʽ��������*/
typedef enum
{
    WLN_NET_WSEC_OFF,
    WLN_NET_WSEC_WEP,
    WLN_NET_WSEC_TKIP,
    WLN_NET_WSEC_WEP128,
    WLN_NET_WSEC_AES,
} UWLNNETWSEC;

/*WIFI��ȫ������֤��ʽ*/
typedef enum
{
    WLN_NET_AUTH_OPEN,
    WLN_NET_AUTH_WEP,
    WLN_NET_AUTH_Shared,
    WLN_NET_AUTH_IEEE8021X,
    WLN_NET_AUTH_WPA_PSK,
    WLN_NET_AUTH_WPA_EAP,
    WLN_NET_AUTH_WPA2_PSK,
    WLN_NET_AUTH_WPA2_EAP,
    WLN_NET_AUTH_WPA_CCKM,
    WLN_NET_AUTH_WPA2_CCKM,
    WLN_NET_AUTH_NONE,
} UWLNNETWAUTHTYPE;

/**<WIFIͨѶ�����ṹ��:*/
typedef struct
{
    byte DHCP;           /**<�Ƿ���DHCP��0x00-��0x01-��*/
    int  Wsec; /*Contains the numeric value for network security type.�μ�enum UWLNNETWSEC*/
    int  WAuthType; /*Contains the numeric value for the network authentication type.�μ�UWLNNETWAUTHTYPE*/
    byte SSID[100];      /**<WIFI�û���*/
    byte Pwd[100];       /**<WIFI����*/
    char IP[16];        /**<����IP��ַ*/
    char Gateway[16];   /**<��������*/
    char Mask[16];      /**<������������*/
    char Dns1[16];      /**<DNS*/
    char Dns2[16];      /**<DNS*/
} WIFICONFIG;

/**<WIFI�ȵ���Ϣ�ṹ��:*/
typedef struct
{
    byte SSID[100];		/*WIFI�ȵ�����*/
    int  Wsec; /*Contains the numeric value for network security type.�μ�enum UWLNNETWSEC*/
    int  WAuthType; /*Contains the numeric value for the network authentication type.�μ�UWLNNETWAUTHTYPE*/
} WIFIINFO;

//IP��WIFIͨѶ����IP��Ϣ
typedef struct
{
	char  IP[16];         /*����IP��ַ*/
	char  Gateway[16];	  /*��������*/
	char  Mask[16];       /*������������*/
    char  Dns1[16];       /*DNS*/
	char  Dns2[16];       /*DNS*/
	char  MAC[18];        /*MAC��ַ,��ʽ��00-23-5A-15-99-42*/
}TERMINALIPINFO;

//MODEMͨѶ�����ṹ��
typedef struct
{
	int     DialMode;      /*����ģʽ��0ͬ��,1�첽*/
	char	PredialNo[10]; /*���ߺ���*/
	char	TelNo[3][21]; /*�绰����*/
	int		IsCheckDialTone; /*�Ƿ��Ⲧ����0Ĭ�ϼ��,1����� */
}MODEMCONFIG;

//������չ�ӿ�ö��
typedef enum
{
	UPORT_COM1,    //COM��1,��Ĭ�ϵ�PinPad��
	UPORT_COM2,    //COM��2,��Ĭ�ϵ�RS232��1
	UPORT_COM3,    //COM��3,��Ĭ�ϵ�RS232��2
	UPORT_COM4,    //COM��4
	UPORT_COM5,    //COM��5
	UPORT_USB1,   //USB��1,������USB PinPad��
	UPORT_USB2,   //USB��2
	UPORT_USB3,   //USB��3
	UPORT_LAN      //��̫��TCP/IP��
}ExtPort;

//����ͨѶ������ö��
typedef enum
{
	UBPS9600,
	UBPS115200
}BaudRate;//����ʵ��֧�����ʵ��

//����ͨѶ����λ��ֹͣλ��У��λ����ö��
typedef enum
{
	UDB8		= 0xc0,		//8λ����λѡ��
	UDB7		= 0x40,		//7λ����λѡ��
	UDB6		= 0x80,		//6λ����λѡ��
	UDB5		= 0x00,		//5λ����λѡ��
	USTOP2	= 0x20,		//2λֹͣλ
	USTOP15	= 0x10,		//1.5λֹͣλ
	USTOP1	= 0x08,		//1λֹͣλ
	UNP		= 0x04,		//��У��
	UEP		= 0x02,		//żУ��
	UOP		= 0x01		//��У��
}AuxFlag;

//����ͨ�Ų����ṹ��
typedef struct
{
	int Aux; /*���ں�,�μ�enum ExtPort */	
	int iBaudRate; /*���ڲ�����,�μ�enum BaudRate*/
	int iAuxFlag; /*��������������λ,ֹͣλ,У��λ��*/
}RS232CONFIG;

//������������ͨѶ�����ṹ��(��̫����WIFI��GPRS��CDMA)
typedef struct
{
	char	HostIp[2][16]; /*������IP��ַ*/
	int		HostPort[2]; /*����˿ں�*/
	char	HostDns[50]; /*����������*/
}HOSTCONFIG;

//ͨѶ������ʼ�����Ͻṹ��(��̫����WIFI��GPRS��CDMA��MODEM)
typedef struct
{
int iCommMode;	/*ͨѶ��ʽ,��ȡ�����������ͨѶ��ʽ,�μ�enum CommMode */
	union
	{
		PPPLOGINCONFIG	st_ppploginconfig ;	/*GPRS��CDMA����,�ο�PPPLOGINCONFIG */
		IPCONFIG		 st_ipconfig;/*��̫������,�ο�IPCONFIG */
		WIFICONFIG      st_wificonfig;/*WIFI����,�ο�WIFICONFIG */
		MODEMCONFIG     st_modemconfig;/*MODEMͨѶ����,�ο�MODEMCONFIG */
	} INITCONFIG;
	void ( *ShowFunc )( void ) ;			/*����ʱ��ʾ�Ľ�����Ϣ*/
	int   CycCount; /*ѭ������*/
}COMMCONFIG;

//������������ͨѶ�������Ͻṹ��(��̫����WIFI��GPRS��CDMA��MODEM)
typedef struct
{
	int iCommMode;/*ͨѶ��ʽ,��ȡ�����������ͨѶ��ʽ,�μ�enum CommMode */ 
	
	HOSTCONFIG     st_hostconfig;	//�μ� HOSTCONFIG
	
	void ( *ShowFunc )( void ) ;			/*����ʱ��ʾ�Ľ�����Ϣ*/
}COMMHOSTCONFIG;

//SSLЭ��ö��
typedef enum
{
	UPROTOCOL_TLSv1_2    //TLS�汾1.2
}UProtocolType;

//SSL֤���ļ���ʽö��
typedef enum
{
	USSL_FILE_DER,  //DER (ASN1) �ļ���ʽ 
	USSL_FILE_PEM   //PEM (BASE64) �ļ���ʽ 
}USSLFileFormat;

//SSL�����׼�ö��
typedef enum
{
	CIPHER_RSA_NULL_MD5,   /*�����׼�-RSA_NULL_MD5*/
	CIPHER_RSA_NULL_SHA,   /*�����׼�-RSA_NULL_SHA*/
	CIPHER_RSA_RC4_40_MD5, /*�����׼�-RSA_RC4_40_MD5*/
	CIPHER_RSA_RC4_128_MD5,  /*�����׼�-RSA_RC4_128_MD5*/
	CIPHER_RSA_RC4_128_SHA,  /*�����׼�-RSA_RC4_128_SHA*/
	CIPHER_RSA_RC2_40_MD5,  /*�����׼�-RSA_RC2_40_MD5*/
	CIPHER_RSA_IDEA_128_SHA,  /*�����׼�-IDEA_128_SHA*/
	CIPHER_RSA_DES_40_CBC_SHA,  /*�����׼�-DES_40_CBC_SHA*/
	CIPHER_RSA_DES_64_CBC_SHA,  /*�����׼�-DES_64_CBC_SHA*/
	CIPHER_RSA_DES_192_CBC3_SHA,  /*�����׼�-DES_192_CBC3_SHA*/
	CIPHER_DH_RSA_DES_192_CBC3_SHA,  /*�����׼�-DH_DSS_DES_192_CBC3_SHA*/
	CIPHER_DH_DSS_DES_40_CBC_SHA,  /*�����׼�-DH_DSS_DES_40_CBC_SHA*/
	CIPHER_DH_DSS_DES_64_CBC_SHA,  /*�����׼�-DH_DSS_DES_64_CBC_SHA*/
	CIPHER_DH_DSS_DES_192_CBC3_SHA,  /*�����׼�-DH_DSS_DES_192_CBC3_SHA*/
	CIPHER_DH_RSA_DES_40_CBC_SHA,  /*�����׼�-DH_RSA_DES_40_CBC_SHA*/
	CIPHER_DH_RSA_DES_64_CBC_SHA,  /*�����׼�-DH_RSA_DES_64_CBC_SHA*/
	CIPHER_EDH_DSS_DES_40_CBC_SHA,  /*�����׼�-EDH_DSS_DES_40_CBC_SHA*/
	CIPHER_EDH_DSS_DES_64_CBC_SHA,  /*�����׼�-EDH_DSS_DES_64_CBC_SHA*/
	CIPHER_EDH_DSS_DES_192_CBC3_SHA,  /*�����׼�-EDH_DSS_DES_192_CBC3_SHA*/
	CIPHER_EDH_RSA_DES_40_CBC_SHA,  /*�����׼�-EDH_RSA_DES_40_CBC_SHA*/
	CIPHER_EDH_RSA_DES_64_CBC_SHA,  /*�����׼�-EDH_RSA_DES_64_CBC_SHA*/
	CIPHER_EDH_RSA_DES_192_CBC3_SHA,  /*�����׼�-EDH_RSA_DES_192_CBC3_SHA*/
	CIPHER_ADH_RC4_40_MD5,  /*�����׼�-ADH_RC4_40_MD5*/
	CIPHER_ADH_RC4_128_MD5,  /*�����׼�-ADH_RC4_128_MD5*/
	CIPHER_ADH_DES_40_CBC_SHA,  /*�����׼�-ADH_DES_40_CBC_SHA*/
	CIPHER_FZA_DMS_NULL_SHA,  /*�����׼�-FZA_DMS_NULL_SHA*/
	CIPHER_CK_FZA_DMS_FZA_SHA,  /*�����׼�-CK_FZA_DMS_FZA_SHA*/
	CIPHER_CK_FZA_DMS_RC4_SHA,  /*�����׼�-CK_FZA_DMS_RC4_SHA*/
	CIPHER_CK_ADH_DES_64_CBC_SHA,  /*�����׼�-CK_ADH_DES_64_CBC_SHA*/
	CIPHER_CK_ADH_DES_192_CBC_SHA  /*�����׼�-CK_ADH_DES_192_CBC_SHA*/
}UCipherSuite;

//GSM��վ��Ϣ�ṹ
typedef struct
{
	byte szMCC[5];     //�ƶ����Ҵ���,��λ��,���й�460
	byte szMNC[5];     //�ƶ������,���ƶ�00,��ͨ01
	byte szLAC[5];     //������
	byte szCID[5];     //С����
	int  nSIG;        //�ź�ǿ��,ȡ�����������ֵ���110,��ֵ���220
	int  nTAG;        //ʱ����ǰ��,��Χ0-63
}BASESTATIONGSM;

//CDMA��վ��Ϣ�ṹ
typedef struct
{
	byte szMCC[5];       //�ƶ����Ҵ���,��λ��,���й�460
	byte szSID[5];       //ϵͳʶ����,ÿ���ؼ���ֻ��һ��sid,
	byte szNID[5];       //����ʶ����,�ɸ�����������,Ҳ�����ɵؼ��ֹ�˾����,ÿ���ؼ��п�����1��3��nid
	byte szBID[5];       //��ʾ���������е�ĳһ��С��,�������Ϊ��վ
	int  nSIG;          //�ź�ǿ��,ȡ�����������ֵ���110,��ֵ���220
	int  nTAG;          //ʱ����ǰ��,0-63
}BASESTATIONCDMA;

//2.2.7	IC������API

//IC������ö��
typedef enum
{
	//	UICC_SLE4442,//Ԥ��
	//	UICC_SLE4428, //Ԥ��
	//	UICC_SLE4436, //Ԥ��
	//	UICC_AT24C64, //Ԥ��
	UICC_CPUCARD,
	UICC_MIFARE, //�ǽ�MIFARE��,Ԥ��
	//	UICC_RFCPU_1356,      //�ǽ�CPU��13.56M
	//	UICC_RFCPU_24        //�ǽ�CPU��2.4G
} IccType;

//IC����ö��
typedef enum
{
	USLOT_PSAM1,       //�Ӵ�ʽPSAM����1
	USLOT_PSAM2,       //�Ӵ�ʽPSAM����2
	USLOT_PSAM3,       //�Ӵ�ʽPSAM����3
	USLOT_PSAM4,       //�Ӵ�ʽPSAM����4
	USLOT_EXCARD,      //�Ӵ�ʽ�û�����
	USLOT_INRF,         //���÷ǽӿ���
	USLOT_EXRF_COM1,    //���÷ǽӿ���COM1��
	USLOT_EXRF_COM2,    //���÷ǽӿ���COM2��
	USLOT_EXRF_COM3,    //���÷ǽӿ���COM3��
	USLOT_EXRF_USB     //���÷ǽӿ���USB��
} SlotType;


//IC��ָ��ṹ��
typedef struct
{
	//	byte OperType;	/* �ο�enum - OperationType */
	byte CLA;			/* Class byte of the command message*/
	byte INS;			/* Instrution*/
	byte P1;			/* Parameter1*/
	byte P2;			/* Parameter2*/
	byte Lc;			/* length of being sent data*/
	byte Le;			/* length of expected data,ʵ�ʷ���ֵ*/
	byte SW1;			/* status word1*/
	byte SW2;			/* status word2*/
	byte C_Data[256];	/* command data*/
	byte R_Data[256];	/* response data*/
} ICCAPDU;

//IC������������ö��
typedef enum 	
{
	UICC_NORF            = -3,   // �޷ǽӿ�Ƭ
	//	UICC_EMPTY           = -3,   // �����޿�Ƭ
	UICC_COMMAND_FAIL    = -2,   // �뿨ƬͨѶ����
	UICC_FAIL            = -1,   // ����ʧ��
	UICC_OK              =  0    // �����ɹ�
}ICCStatus;

//2.2.9	�ļ�����API

//�ļ�����ض���
typedef int FILE_HANDLE;
//�ļ��洢λ��ö��
typedef enum /*�ļ��洢λ��,˽�б�ʾ�洢�ڵ�ǰ��Ӧ��Ŀ¼��,����ǰ��Ӧ�ÿɷ��ʵ�;���б�ʾ�洢�ڹ���λ��,������Ӧ�ö��ɷ���*/
{
	FILE_PRIVATE,       //˽��,���ļ��洢�ڵ�ǰ��Ӧ��Ŀ¼��,������Ӧ�ò��ɷ���
		FILE_PUBLIC         //����,���ļ��洢�ڹ���λ��,������Ӧ�ö��ɷ���
}FILELOCATION;
//�ļ���ģʽ����
typedef  enum
{
	FILE_RDONLY = 0, //ֻ��,�����ڷ��ش�
		FILE_WRONLY,     //ֻд,�����ڷ��ش�
		FILE_RDWR,       //��д,�����ڷ��ش�
		FILE_APPEND,     //׷��,�������򴴽�,����ʱָ��ָ���ļ�β
		FILE_CREAT,      //����,�Ѵ���ʱɾ���ؽ�
}FileFlags;

//�ļ�ָ�붨λ
typedef  enum
{
	FILE_SEEK_SET = 0,       //���ļ�ͷ
		FILE_SEEK_CUR,           //����ǰλ��
		FILE_SEEK_END            //���ļ�β
}FileSeekFlags;

//�ļ���������ֵ
typedef enum
{
	UFILE_NO_EXIST      = -12,             //ָ�����ļ�������
	UFILE_PARAERROR     = -11,            //������
	UFILE_NO_RECORD		= -10,             //��¼δ�ҵ�
	UFILE_REMOVE_FAIL	= -9,              //�ƶ��ļ�����
	UFILE_CLOSE_FAIL	= -8,              //�ر��ļ�����
	UFILE_DELETE_FAIL	= -7,              //ɾ���ļ���¼����
	UFILE_SEEK_FAIL		= -6,              //��λ�ļ�ָ�����
	UFILE_READ_FAIL		= -5,              //������
	UFILE_WRITE_FAIL	= -4,              //д����
	UFILE_CREATE_FAIL 	= -3,              //�ļ��ؽ�����
	UFILE_OPEN_FAIL  	= -2,              //�򿪴���
	UFILE_FAIL			= -1,              //�ļ�����ʧ��
	UFILE_SUCCESS       =  0               //�ļ������ɹ�
}FileRet;

//�ļ��������������ṹ
typedef struct
{
	uint   StartOffset;  //�ӽṹ�ĵڼ����ֽڿ�ʼ����,��ʼλ��Ϊ0
	uint   Length;       //�Ƚ��ֽڳ���
	byte*   SearchKey;    //���ҹؼ���
}DBSEARCOND;

//2.2.10	���������API

//PinPad����ö��
typedef enum
{
	UPP_INT		=0,     /* ����������� */
	UPP_EXT_COM1,		     /* COM1������������� */
	UPP_EXT_COM2,		     /* COM2������������� */
	UPP_EXT_USB		     /* USB������������� */
}PinPadType;

//����ģʽ
typedef enum
{
	UDES_TYPE_SINGLE	=1,	/* ��DES */
	UDES_TYPE_TRIPLE,		/* 3DES */
	UDES_TYPE_SM4			/* ����SM4 */
}DesType;

//��Կ����
typedef enum
{
	UKEY_TYPE_MST		=0,	/* ����Կ */
	UKEY_TYPE_PIN,			/* PIN������Կ */
	UKEY_TYPE_MAC,			/* MAC������Կ */
	UKEY_TYPE_TRACK,          /*TRACK������Կ*/
	UKEY_TYPE_TEST          /*���Թ�����Կ*/
}KeyType;

//PINPAD��������ӿڷ���ֵ
typedef enum
{
	UPIN_TIMEOUT     = -3,   //�������볬ʱ
	UPIN_ABORT		= -2,	// ����Ա��������
	UPIN_ERROR		= -1,	// ������� 
	UPIN_ESC			=  0,	// �û�ȡ������
	UPIN_SUCCESS		=  1,	// ����ɹ� 
	UPIN_NONE		=  2	// ������,���൱��BYPASS 
}PinInputStatus;

//��PIN���뺯������ֵ����
typedef enum
{
	UPP_ERROR_SM	 = -10,				//������Կ/�㷨����ʧ��
	UPP_KEY_EXIST    = -9,              //��Կ���Ѵ���
	UPP_DECLINED     = -8,               //�������ܾ�
	UPP_ERROR		= -7,				// ���� 
	UPP_FAILURE		= -6,				// ϵͳ�����ʧ�� 
	UPP_ESCAPE		= -5,				// �������˳� 
	UPP_TIMEOUT		= -4,				// ��ʱ(���ü���ͨѶ)
	UPP_MAC_ERROR	= -3,				// ����MAC���� 
	UPP_ERR_PAN		= -2,				// ���˺����� 
	UPP_ABORT		= -1,				// �û����� 
	UPP_SUCCESS		= 0				    // �ɹ� 
}PPStatus;

//2.2.11	EMV��API

#define  UMAX_TERMINAL_APPL    20         //��Ƭ�ն˹�֧ͬ�ֵ����Ӧ����
#define  UMAX_EXCEPTION_BIN_COUNT	100  //��BIN�����������
//EMV������������ö��
typedef enum
{ 
	UEMV_PRM_ERR  =-4,    //EMV������
	UEMV_PRM_NOT_FOUND=-3,		    //EMV����δ�ҵ�
	UEMV_PRM_CAPK_CHK_HASH_FAIL=-2,	//��ԿHASHУ�����
	UEMV_PRM_FAIL=-1,				//EMV��������ʧ��
	UEMV_PRM_OK=0             		//EMV���������ɹ�
} ParamStatus;

//EMV����״̬ö��
typedef enum
{
	UEMV_QPBOC_DODGE          = -20,       /**<��������ʧ��*/
	UEMV_EC_DECLINED          = -19,       //�����ֽ��ѻ��ܾ�
	UEMV_APP_NOACCEPT         = -18,       //Ӧ�ò�����,������ѡ��
	UEMV_SCRIPT_FAIL          = -17,		//�����нű�ִ��ʧ��
	UEMV_ARPC_FAIL            = -16,		//��������֤ʧ��
	UEMV_DECLINED             = -15,		//���׾ܾ�
	UEMV_CANCEL               = -14,		//����ȡ��
	UEMV_ONLINE               = -13,		//����Ӧ����
	UEMV_CVM_FAIL             = -12,     //�ֿ�����֤ʧ��
	UEMV_APP_EXPIRED          = -11,     //Ӧ����ʧЧ
	UEMV_APP_EFFECT           = -10,     //Ӧ����δ��Ч
	UEMV_AUTH_FAIL            = -9,      //������֤ʧ��
	UEMV_FALLBACK             = -8,		//����fallback
	UEMV_APP_BLOCK            = -7,		//Ӧ������
	UEMV_CANDIDATELIST_EMPTY  = -6,		//�޹�ͬӦ��
	UEMV_PARA_ERR             = -5,      //������
	UEMV_CARD_BLOCK           = -4,      //��Ƭ����
	UEMV_COMMAND_FAIL         = -3,      //����ʧ��
	UEMV_CARD_REMOVED         = -2,		//�����п�Ƭ���ƿ�
	UEMV_FAIL 				 = -1,		//ִ��ʧ��
	UEMV_OK					 =  0,		//ִ�гɹ�
	UEMV_OTHER_INTERFACE= 1,//�볢������ͨ�Ž���
	UEMV_QPBOC_OFFLINE   = 2,//�ǽӴ�QPBOC�����ѻ�����
	UEMV_QPBOC_ONLINE          = 3,  //�ǽӴ�QPBOC��������
	UEMV_PBOC_ONLINE           = 4,//�ǽӴ�PBOC��������
	//UEMV_MSD_ONLINE           = 5//�ǽӴ�MSD��������
	UEMV_EC_ACCEPT             = 6,       //�����ֽ��ѻ�����
	UEMV_OFFLINE_ACCEPT        = 7        //��׼�����ѻ�����
} EmvStatus;

//�ն˲����ṹ��
typedef struct { 
    char    TermCap[3] ;           /*�ն����� '9F33'*/
    char    AdditionalTermCap[5] ; /*�ն˸�������*/
    char    IFDSerialNum[9] ;    /*IFD���к� '9F1E'*/
    char    TermCountryCode[2] ;  /*�ն˹��Ҵ��� '9F1A'*/
    char    TermID[9] ;       /*�ն˱�ʶ '9F1C'*/
    char    TermType ;       /*�ն����� '9F35'*/
    char    TransCurrCode[2] ;   /*���׻��� '5F2A'*/
    char    TransCurrExp;      /*���׻���ָ�� '5F36'*/
    //PSE Selection
    char    bPSE;          /*�Ƿ�֧��ѡ��PSE 1*/
    char    bCardHolderConfirm;   /*�Ƿ�֧�ֳֿ���ȷ�� 1*/
    char    bPreferedOrder;     /*�Ƿ�֧����ѡ��ʾ 1*/
    char    bPartialAID;       /*�Ƿ�֧�ֲ���AIDƥ�� 1*/
    char    bMultiLanguage;     /*�Ƿ�֧�ֶ����� 0*/
    char    bCommonCharset;     /*�Ƿ�֧�ֹ����ַ��� 0*/
    //Data Authentication
    char    bIPKCValidtionCheck;   /*�Ƿ��鷢���й�Կ��֤��Ч�� 1*/
    char    bContainDefaultDDOL;   /*�Ƿ����Ĭ��DDOL 1*/
    char    bCAPKFailOperAction;   /*CAPK��ȡ����ʱ�Ƿ���Ҫ����Ա��Ԥ 1*/
    char    bCAPKChecksum;      /*�Ƿ����CAPKУ�� 1*/
    //Cardholder Verification Method
    char    bBypassPIN;       /*�Ƿ�֧������PIN���� (�������,����)*/
    char    bGetDataForPINCounter;  /*PIN���Լ������Ƿ�֧��GetData 1*/
    char    bFailCVM;        /*�Ƿ�֧�ִ����CVM(1����ΪYes)*/
    char    bAmountBeforeCVM;     /*CVMǰ�Ƿ���֪��� 1*/
    //Term Risk Management
    char    bLimitFloorCheck;    /*�Ƿ��������޶��� 1*/
    char    bRandomTransSelect;   /*�Ƿ�����������ѡ�� 1*/
    char    bValocityCheck;     /*�Ƿ����Ƶ�ȼ�� 1*/
    char    bTransLog;        /*�Ƿ��¼������־ 1*/
    char    bExceptionFile;     /*�Ƿ�֧�ֿ�Ƭ������ 1*/
    char    bTRMBaseOnAIP;      /*�ն˷��չ����Ƿ����Ӧ�ý������� 1*/
    //Terminal Action Analysis
    char    bTerminalActionCodes;  /*�Ƿ�֧���ն���Ϊ���� 1*/
    char    bDefActCodesBefore1stGenAC; /*ȱʡ��Ϊ�����Ƿ�����FirstGenerateAC ?*/
    char    bDefActCodesAfter1stGenAC;  /*ȱʡ��Ϊ�����Ƿ����FirstGenerateAC ?*/
    //Completion Processing
    char    bForceOnline;      /*�Ƿ�����ǿ������ 1*/
    char    bForceAccept;      /*�Ƿ�����ǿ�ƽ��ܽ��� 1*/
    char    bAdvices;         /*�Ƿ�֧��֪ͨ 0*/
    char    bIISVoiceReferal;    /*�Ƿ�֧�ַ���������������ο� ?*/
    char    bCardVoiceReferal;    /*�Ƿ�֧�ַ���������������ο� ?*/
    char    bBatchDataCapture;    /*�Ƿ�֧�������ݲɼ�*/
    char    bDefaultTDOL;      /*�Ƿ���ȱʡTDOL*/
    //Exception Handling
    char    cEntryModeUsingMagStripe; /*IC�����϶�ֻ��ˢ��ʱPOSEntryModeֵ*/
    char    bAccountSelect;     /*�Ƿ�֧���˺�ѡ��*/
}TERMCONFIG; 


//EMV_AID�����ṹ��
typedef struct
{
	byte AID[16];						//AID
	byte AID_Length;						//AID����
	byte bAppSelIndicator;				//Ӧ��ѡ��ָʾ��
	byte bTerminalPriority;				//�ն����ȼ�
	/* Domestic */
	byte bMaxTargetDomestic;				/*ƫ�����ѡ������Ŀ��ٷ���*/
	byte bTargetPercentageDomestic;		/*���ѡ���Ŀ��ٷ���*/
	byte abTFL_Domestic[4];				/* �ն�����޶� */
	byte abThresholdValueDomestic[4];		/*ƫ�����ѡ�����ֵ*/
	/* International */
	byte bMaxTargetPercentageInt;			/*ƫ�����ѡ������Ŀ��ٷ���*/
	byte bTargetPercentageInt;				/*���ѡ���Ŀ��ٷ���*/
	byte abTFL_International[4];			/* �ն�����޶� */
	byte abThresholdValueInt[4];			/*ƫ�����ѡ�����ֵ*/
	
	byte abTerminalApplVersion[4];			/* �ն�Ӧ�ð汾 */
	byte abMerchantCategoryCode[2];		/* �̻�������tag: 9F15 */        
	byte bTransactionCategoryCode;		/* ����������Europay only, tag: 9F53 */
	byte abTrnCurrencyCode[2];			/* ���Ҵ���tag: 5F2A */
	byte abTerminalCountryCode[2];		/* ���Ҵ����ն�tag: 9F1A */
	byte TAC_Default[5];					/* TACȱʡdata format (n 5) */    
	byte TAC_Denial[5];					/* TAC�ܾ�data format (n 5) */    
	byte TAC_Online[5];					/* TAC����data format (n 5) */  
	byte abDDOL[20];					/* DDOL */
	byte DDOL_Length;					/* DDOL���� */
	byte abTDOL[20];					/* TDOL */
	byte TDOL_Length;					/* TDOL���� */
	byte abTrnCurrencyExp;				/* tag: 5F36 */
	byte abEC_TFL[6];					/* �ն˵����ֽ����޶�tag: 9F7B n12*/
	byte TerminalType;					/* �ն�����data format (n 3) */
	byte TerminalCap[3];					/* �ն�����data format (n 3) */
	byte AddTerminalCap[5];				/* �ն˸�������data format (n 3) */
	byte abRFOfflineLimit[6];		/*�ǽӴ��ѻ�����޶�DF19*/
	byte abRFTransLimit[6];		/*�ǽӴ������޶�DF20*/
	byte abRFCVMLimit[6];				/*�ն�ִ��CVM�޶�DF21*/
	byte abTransProp[4];			    /*�ն˽�������9F66*/
	byte bStatusCheck;          	    /*�ǽӴ�״̬���, 0x00-�����,0x01-���*/
	byte abAcquirerID[6];         	    /*�յ��б�ʶ9F01*/
}APPLICATIONPARAMS;

//EMV_AID�����ܽṹ��
typedef struct
{
	byte bTermAppCount;//ʵ��AID��������
	APPLICATIONPARAMS TermApp[UMAX_TERMINAL_APPL];
}TERMINALAPPLIST;

//CA��Կ�ṹ��
typedef struct
{								
	byte RID[5];						/* Registered Application Provider Identifier */
	byte CA_PKIndex;				/* ��֤���Ĺ�Կ���� */
	byte CA_HashAlgoIndicator;		/* ��֤���Ĺ�Կ��ʲ�㷨��ʶ */
	byte CA_PKAlgoIndicator;			/* ��֤���Ĺ�Կ�㷨��ʶ */
	byte LengthOfCAPKModulus;		/* ��֤���Ĺ�Կģ���� */
	byte CAPKModulus[248];			/* ��֤���Ĺ�Կģ */
	byte LengthOfCAPKExponent;		/* ��֤���Ĺ�Կָ������ */
	byte CAPKExponent[3];			/* ��֤���Ĺ�Կָ�� */
	byte ChecksumHash[20];			/* ��֤���Ĺ�ԿУ��ֵ */
	byte CAPKExpDate[3];				/* ��֤���Ĺ�Կ��Ч�� */
}CAPUBLICKEY;

//EMV�ص�����
typedef struct
{
	int (*EMV_InputPasswd)(char cType, ushort chance,char *pszPin);
	int (*EMV_InputAmount)(byte *Amount);
}STEMVCALLBACKFUN;
//�ǽ�ģʽö��
typedef enum
{
	UEMV_RF_PBOC       = 0,     //�ǽ�PBOC��׼����
	UEMV_RF_QPBOC      = 1,     //�ǽ�qPBOC
	//UEMV_RF_MSD        = 2,//�ǽ�MSD
	UEMV_RF_PBOC_SINGLE     = 3      //�ǽ�PBOC������
}EmvRFType;

//��BIN�������ṹ��
typedef struct
{
  byte bBINLen;
  byte abBIN[10];		       /* 5A: BCD */
}EMVEXCEPTIONBIN;

//��BIN�������ܽṹ��
typedef struct
{
  byte            bCount;  //ʵ������
  EMVEXCEPTIONBIN ExpBIN[UMAX_EXCEPTION_BIN_COUNT];
}EMVEXCEPTIONBINLIST;

//����·������
#define CLSS_VISA_QVSDC          2   // qPBOC��ʽ
#define CLSS_VISA_VSDC           3   // �����ǽ�PBOC��ʽ

//AC����
#define AC_AAC                0x00
#define AC_TC                 0x01
#define AC_ARQC               0x02

//�ֿ�����֤��ʽ
#define RD_CVM_NO             0x00   // no CVM
#define RD_CVM_SIG            0x10   // signature
#define RD_CVM_ONLINE_PIN     0x11   // online PIN

//�ں�����
#define KERNTYPE_DEF             0
#define KERNTYPE_JCB             1
#define KERNTYPE_MC              2
#define KERNTYPE_VIS             3
#define KERNTYPE_PBOC            4
#define KERNTYPE_AE              5
#define KERNTYPE_RFU             6

//�ǽӽ���Ԥ����ṹ
typedef struct
{
    ulong ulTermFLmt;       /* �ն��ѻ��޶�*/
    ulong ulRdClssTxnLmt;   /* �������ǽӽ����޶� */
    ulong ulRdCVMLmt;       /* ������CVM�޶� */
    ulong ulRdClssFLmt;     /* �������ǽ��ѻ��޶�*/
    byte aucAID[17];        /*Ӧ��AID */
    byte ucAidLen;          /*Ӧ��AID����*/
    byte ucKernType;        /*Ӧ���ں˺�
	KERNTYPE_DEF: �ں˸���RID����ƥ��
	KERNTYPE_JCB: JCB.
	KERNTYPE_MC: MASTERCARD.
	KERNTYPE_VIS: VISA.
	KERNTYPE_PBOC: PBOC.
	KERNTYPE_AE: American Express.*/
    // payWave				//QPBOC�Ĳ���Ҳ��������һ��
    byte ucCrypto17Flg;		/* MSD CVN17�Ƿ�֧�ֱ�־, 0-��֧��,1- ֧��*/
    byte ucZeroAmtNoAllowed;/* ���Ϊ0����־,0-�����Ϊ0,�ҽ�����Ϊ0�����������;1-�����Ϊ0,�Ҳ�������Ϊ0 ;2-��������Ƿ�Ϊ0*/
    byte ucStatusCheckFlg;  /* ״̬����־, 0-��֧�� (�������,���޸�TTQ),1- ֧�� (��ʱ������׽��Ϊ1Ԫ,���ں���ǿ���޸�TTQΪ��������)*/
    byte aucReaderTTQ[5];   /* �ն˽�������TTQ*/
    // common
    byte ucTermFLmtFlg;		/* �ն��ѻ��޶����־,0-�����, 1-������޶����, 2-��鵫�޶���� */
    byte ucRdClssTxnLmtFlg;		/* �������ǽӽ����޶�,����־,0-�����, 1-������޶����, 2-��鵫�޶����*/
    byte ucRdCVMLmtFlg;		/* ������CVM�޶����־,0-�����, 1-������޶����, 2-��鵫�޶����*/
    byte ucRdClssFLmtFlg;		/* �������ǽ��ѻ��޶����־,0-�����, 1-������޶����, 2-��鵫�޶����*/
    byte aucRFU[2];
} Clss_PreProcInfo;

//�ǽӽ�����ز����ṹ
typedef struct
{
    ulong ulAmntAuth;          // ��Ȩ���(ulong)
    ulong ulAmntOther;         // �������(ulong)
    ulong ulTransNo;           // �������м�����(4 BYTE)
    byte ucTransType;          // ��������'9C'
    byte aucTransDate[4];      // �������� YYMMDD	3�ֽ�BCD��β��0x00
    byte aucTransTime[4];      // ����ʱ�� HHMMSS	3�ֽ�BCD��β��0x00
} Clss_TransParam;

//Ӧ����Ϣ�ṹ��
typedef struct
{
    char  szAID[32 + 1];          //AID  ASCII��ʽ "\0"����
    char  szAppName[32 + 1];      //Ӧ���� ASCII��ʽ "\0"����
} STAPPINFO;

//�ص������ṹ��2
typedef struct
{
    int (*EMV_InputPasswd)(char cType, ushort chance, char *pszPin);
    int (*EMV_InputAmount)(byte *Amount);
    int (*EMV_cVerifyIDCard)(void); //����ֵ���� ��ο�����ԭ��˵��
    int (*EMV_cSelectAapp)(STAPPINFO *pstAPPList, int nAPPNum); //����ֵ������ο�����ԭ��˵��
    int (*EMV_cqPBOCDodgeRefresh)(void *psCmdBuf);
    int (*EMV_cqPBOCDogeRemoveTrace)(void);
} STEMVCALLBACKFUN2;

//2.2.12	TMS��API

#define UMAX_APP_COUNT  30  //Ӧ���������
#define UMAX_MODULE_COUNT  800  //�����ļ��������
//Ӧ����Ϣ�ṹ��
typedef struct
{
	char AppName[20+1];          //Ӧ����
	char AppDispName[20+1];     //Ӧ����ʾ��,�������01000006��ǩ,���ͱ�ǩ����
	char AppVar[15+1];          //Ӧ�ð汾��,TMSϵͳֻ֧��15λ�汾��
	char TerminalID[8+1];//�ն˺�
	char ShopId[15+1];//�̻���
	byte bisMainApp;           //�Ƿ�����Ӧ��,0-��,1-��
}UAPPINFO;

//Ӧ����Ϣ�ܽṹ��
typedef struct
{
	byte		bCount;                       //ʵ��Ӧ����
	UAPPINFO	AppInfo[UMAX_APP_COUNT];	//�μ�struct UAPPINFO
}UAPPINFOLIST;

//ģ������ö��
typedef enum
{
	UMODULE_FILE    = 0,       //�ļ�,2-5���ļ�����ʹ��0,������������
	UMODULE_PARAFILE = 1,      //�����ļ�
	UMODULE_TRADE   = 2,       //ҵ��ģ��
	UMODULE_PUBLIC  = 3,       //����ģ��
	UMODULE_API     = 4,       //APIģ��
	UMODULE_PRIVATE = 5,       //����˽�п�
	UMODULE_DATA    = 6,       //�������ļ�(Ԥ��)
	UMODULE_DRIVER  = 7,//Ӳ������(Ԥ��)
	UMODULE_OS      = 8,       //�ײ�OS(Ԥ��)
	UMODULE_APP     = 9        //Ӧ��,��ִ���ļ�
}UModuleType;

//ģ����Ϣ�ṹ��
typedef struct
{
	char ModuleName[50];    //ģ����
	int  ModuleType;        //�μ�enum UModuleType
	char AppName[20+1];      //Ӧ����,�������ļ�����ĳ��Ӧ��
}UMODULEINFO;

//ģ����Ϣ�ܽṹ��
typedef struct
{
	ushort	nCount;								//ʵ�������ļ���
	UMODULEINFO ModuleInfo[UMAX_MODULE_COUNT];	//�μ�struct UMODULEINFO
}UMODULEINFOLIST;

//TMS����ͨѶ����ö��
typedef enum
{
	UTMS_BYRS232 = 1,  //����
	UTMS_BYMODEM     = 2,  //MODEM�첽
	UTMS_BYETHENET   = 3,  //������̫��
	UTMS_BYWIFI      = 4,  //WIFI
	UTMS_BYGPRS      = 5,  //GPRS,WCDMA(wcdma��gprs������ͬ)
	UTMS_BYCDMA      = 6,  //CDMA
	UTMS_BYMODEMPPP  = 7,  //MODEMPPP���ź���TCPIP
	UTMS_BYUSB       = 8   //USB
}UTMSComType;

//TMS����ͨѶ�ṹ
typedef struct
{
	unsigned char ucCOMMType;  /*ͨ�����ͣ��μ� enum UTMSCOMTYPE*/
	unsigned char ucTPDUFlag;  /*TPDU���ڱ�ʶ: 0-��,1-��*/
	unsigned char aucTPDU[5];  /*TPDU����(���ʶ��TPDU)*/
	unsigned int  uiSockID; /*tcpipͨѶSocket ID UTMSCOMTYPE��3,4,5,6,7*/
	unsigned long hCommHandle; /*ͨѶ��� UTMSCOMTYP�� 1,2,8*/
/*���²���Ϊ����POS�����õ��Ĳ���,�������Ҳ��ÿɶ���,���õ�������Ҫ��Ӳ����뼰ʱ��Ӧ*/
	unsigned char ucPackNum; /*���ؽ׶η������������������ذ���������С1,���8*/
	unsigned int uiFrameLen;/*���ؽ׶δ�������֡�ĳ���(��λ���ֽ�)*/
	unsigned char ucSyncFlag; /*ǿ���ն�������ִ��һ��һ���ı��Ľ���ģʽ��0-�ر� 1-��*/
	unsigned char ucIfCheck; /*���ؽ׶�����У���ʶ��0-��У��  1-У��*/
	unsigned char ucBreakType;  /*���ؽ׶��Ƿ�������(ȡ��/�����)�ж�����0-������ 1-����*/
	unsigned int  uiReTime; /*ͨѶ���Ľ��ճ�ʱ��,���½��մ���(���������ط����Ĵ���)*/
	unsigned int  uiTimeoutMs; /*����ͨѶ���Ľ��ճ�ʱʱ��(��λ������)*/
	unsigned int   uiDelayTime; /*�ն�ÿ���������ݰ�֮ǰ����ʱ(��λ������)*/
	unsigned int   uiSlotTime;  /*�������������������ʱ��(��λ������)*/
	unsigned char  auReserver[100];  /*Ԥ����*/
	unsigned int   uiRFULen; /*��չ�ռ䳤��*/
	void        *pvRFU;  /*��չ�ռ�ָ��*/
	unsigned char DlTxnType;	/*���ؽ������� 0-��ʼ��,1-����,2-��������*/
}UTMSPARAMETERS;

//TMS��API����ֵö��
typedef enum
{	
	UTMS_TIMEOUT			= -3,        //��ʱ
	UTMS_QUIT				= -2,	//ȡ��
	UTMS_FAIL                = -1,       //ʧ��
	UTMS_OK                  =  0        //�ɹ�
}UTMSStatus;

#define KEY_BUF_SIZE		128		//�������뻺��ĳ���
#define	ITWELLSYSINFOLEN	40		//��
#define SWIPEDANDINICEVENT	0xFF	//���������дſ�����
//#define INICEVENT			0xF0	//�����������IC�Ĳ���
#define XGDOK				0X01

#define BEEPERROR			1		//�������쳣��
#define BEEPNORMAL      	0		//������������
#define DECRYP				0		//����
#define ENCRYP				1		//����

//pos�Ĺ���״̬�����������͵Ĵ���
#define WORK_STATUS			0		//��������״̬������״̬
#define	UPLOGRMB			1		/*����������ʱѡ��ͬ�Ľ��׼�¼*/
#define UPLOGFRN			2
#define UPLOGALL			3
#define UPLOGDETAILTYPE1	4		//����ƽ��̵ĵ�������
#define UPLOGDETAILTYPE2	4		//���˲�ƽ��̵ĵ�������

#define		PIN_PED			0x00	//����
#define		PIN_PP			0x01	//����

#define		TIMEOUT			-2		//��ʱ

#define		COM_PAD_NO		0x00			//rs232 A
#define		PINPADCOM		0x01			//pinpad
#define		COM_RS232B_NO	0x02			//rs232 B
#define		USB_DEVICE		0x04
#define		USB_HOST		0x06

#define		MAX_LCD_LINENUM 			5	//LCD����ʾ���������

#if (defined(V50X_MACHINE))
#define		MAX_LCDWIDTH				26
#else
#define		MAX_LCDWIDTH				20
#endif

#define		MAX_MENUNAME_LEN			14		//�˵�����󳤶�
#define		SEARCH_DIRECTION_NEXT 		1
#define		SEARCH_DIRECTION_PREV 		0
#define		MCARDNO_MAX_LEN 			19		//���ŵ���󳤶�
#define		MAX_AMT_LEN					12		//������
#define		MAX_PWD_LEN 				8		//������볤��
#define		BASE_YEAR 					2000	//��׼��
#define		INPUT_TIMEOUT_VAL			30		//30s ���볬ʱֵ
#define		INPUT_INFINITE				-1
#define		INPUT_TIMEOUT 				-2		//���볬ʱ����
#define		SCRIPT_SUCCESS				0		//�ű����гɹ�
#define		SCRIPT_CANCEL 				-1		//�ű���ȡ��
#define		SCRIPT_ERROR				-3		//�ű���ʽ����
#define		SCRIPT_NONEXIST				-4
#define		SCRIPT_CHECKERR				-5
#define		SCRIPT_MEMLACK				-6

#define MAX_RSA_MODULUS_LEN		512   // RSA���ģ����
#define MAX_RSA_PRIME_LEN		256   // RSA���ģ��������

// RSA��Կ�ṹ����
typedef struct{
unsigned int uiBits;   //ģλ����bit��λ
unsigned char ucModulus[MAX_RSA_MODULUS_LEN];   //ģ
unsigned char ucExponent[MAX_RSA_MODULUS_LEN];  //ָ��
}RSAPUBLICKEY;
 
//RSA˽Կ�ṹ����
typedef struct{
unsigned int uiBits;    //ģλ����bit��λ
unsigned char ucModulus[MAX_RSA_MODULUS_LEN];   //ģ
unsigned char ucPublicExponent [MAX_RSA_MODULUS_LEN];  //��Կָ��
unsigned char ucExponent[MAX_RSA_MODULUS_LEN];   //˽Կָ��
unsigned char ucPrime[2][MAX_RSA_PRIME_LEN];     //pq��������������
unsigned char ucPrimeExponent[2][MAX_RSA_PRIME_LEN]; //CRTָ����������ָ������ֵ
unsigned char ucCoefficient[MAX_RSA_PRIME_LEN];  //CRTϵ������������������ֵ
}RSAPRIVATEKEY;

#endif

