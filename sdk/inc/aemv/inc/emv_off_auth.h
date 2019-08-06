#ifndef __EMV_OFF_AUTH__
#define __EMV_OFF_AUTH__
//SDA�������
#include <emv_interface.h>
#define CERT_HEADER		0x6A	/**<֤������ͷ*/
#define CERT_TAILER		0xBC	/**<����β*/

/**<֤�����ͣ����е�4�ֽ�Ϊ֤���ʽ*/
#define TYPE_CERT_ISSPK		0x02		/**<�����й�Կ֤���ʽ*/
#define TYPE_CERT_SSAD		0x03		/**<ǩ����̬Ӧ�����ݸ�ʽ*/
#define TYPE_CERT_ICCPK		0x04		/**<IC����Կ֤���ʽ*/
#define TYPE_CERT_DSD		0x05		/**<��̬��֤��̬ǩ�����ݸ�ʽ*/
#define TYPE_CERT_FDSD		0x06		/**<���ٶ�̬��֤��̬ǩ�����ݸ�ʽ*/
#define TYPE_CERT_ODADSD		0x95		/**<ODA��̬��֤��̬ǩ�����ݸ�ʽ*/
#define TYPE_CERT_CDSD		0x25		/**<������֤��̬ǩ�����ݸ�ʽ*/
#define TYPE_CERT_PIN		0x24		/**<PIN֤���ʽ*/

#define	TYPE_CERT_SM_ISSPK	0x12		/**< ����SM2�㷨�ķ����й�Կ֤���ʽ*/
#define	TYPE_CERT_SM_SSAD	0x13		/**< SM2ǩ����̬Ӧ�ø�ʽ*/
#define TYPE_CERT_SM_ICCPK	0x14		/**<SM2�㷨IC����Կ֤���ʽ*/
#define TYPE_CERT_SM_DSD	0x15		/**<SM2�㷨��̬��֤��̬ǩ�����ݸ�ʽ*/
#define TYPE_CERT_SM_ODADSD	0xA5		/**SM2<ODA��̬��֤��̬ǩ�����ݸ�ʽ*/
#define TYPE_CERT_SM_FDSD	0x16		/**<���ٶ�̬��֤��̬ǩ�����ݸ�ʽ*/
#define ALG_PK_NONE	Ox00
#define ALG_PK_RSA		0x01
#define ALG_PK_SM2		0x04

#define ALG_HASH_SHA1	0x01
#define ALG_HASH_SM3	0x07


typedef struct
{
	char cIndex; 				/**<ע�����Ĺ�Կ����*/
 	char szCert[248];		/**<��Կ֤��*/
 	int	 nCertLen;		/**<��Կ֤�鳤��*/
 	char szpkRemainder[248];	/**<��Կ����*/
 	int	nRemainderLen;		/**<��Կ�����*/
 	char	szIsspkExp[3];			/**<��Կָ��*/
 	int	nExpLen;			/**<��Կָ������*/
 	char	szpan[10];			/**<IC�����ʺ�*/
 	int	nPanLen;			/**<���ʺų���*/
}STCERT;

typedef struct
{
	uchar uiLen;
	uchar ucModulus[MAXLEN_MODULUS];  
	uchar ucExponent[3];
}STRSA;

typedef struct
{
	uchar ucXa[64+1];
	uchar ucYa[64+1];
}STSM;

extern int Dpas_CDA_GAC();
extern int PayPass_OffAuth_CDA_First();
extern int CDA_AC_PAYPASS(int nGacStep, char *pszGacRes, int nGacLen);
extern int CDA_GAC(int nGacStep, char *pszGacRes, int nGacLen);
extern int GetPinPk(XM_RSA_PUBLIC_KEY *pk);

extern int Emv_OffAuth();
extern int CalcSM2(STSM *stSm,unsigned char *r, unsigned char *s, unsigned char *msg, unsigned int msglen);
extern int Emv_SM_OffAuth();

extern int GetCAPK_EX(STRSA *pk);
extern int GetCAPK(STRSA *pk);
extern int GetCertInfo(char cCertType,STCERT *stCert);
extern int GetAuthData(unsigned char cCertType,char *pszData,int *nLen);
extern int OffAuth_SM_DDA(char cCertType);
/******************************************************************************
 *  	��������:	Emv_OffAuth: 
 *	��������:	
 *	��ڲ���:	
 *	���ڲ���:     
 * 	����ֵ  :		
 ******************************************************************************/
int Rf_OffAuth(int odatype);
#endif