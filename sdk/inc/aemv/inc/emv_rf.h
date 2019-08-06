#ifndef __EMV_RF__
#define __EMV_RF__

#include <emv_interface.h>

#define EMV_RF_PROP_MSD			0x0080		/**< 1:֧�ַǽӴ����� (MSD) ,0:��֧��*/
#define EMV_RF_PROP_PBOCCLSS		0x0040		/**< 1:֧�ַǽӴ�PBOC,0:��֧��*/
#define EMV_RF_PROP_QPBOC			0x0020		/**< 1:֧�ַǽӴ�qPBOC,0:��֧��*/
#define EMV_RF_PROP_PBOC			0x0010		/**< 1:֧�ֽӴ�PBOC,0:��֧��*/
#define EMV_RF_PROP_OFFLINE_ONLY	0x0008		/**< 1:��д����֧���ѻ�
											    		0:��д��������������*/
#define EMV_RF_PROP_ONLINEPIN		0x0004		/**< 1:֧������PIN,0:��֧��*/
#define EMV_RF_PROP_SIGNATURE		0x0002		/**< 1:֧��ǩ��,0:��֧��*/
#define EMV_RF_PROP_ODA			0x0001	//��1�ֽڵ�1λ֧��ODA

#define EMV_RF_PROP_ONLINE			0x0180		/**< 1:Ҫ����������,0:��Ҫ��*/			
#define EMV_RF_PROP_CVM			0x0140		/**< 1:Ҫ��CVM,0:��Ҫ��*/
#define EMV_RF_TM_CDCVM			0x0240		/**< 1:֧��CDCVM,0:��֧��*/
#define EMV_RF_PROP_FDDA        0x80000000  /**< �ն�֧��01�汾��FDDA **/
#define EMV_RF_PROP_ISSUSER_SCRIPT    0x0280  // �����нű��Ƿ�֧�� �ֽ�3λ8
#define EMV_RF_PROP_MOBILE    0x0240  //mobile 

#define UN_RF_PROP_ONLINEPIN		0xFFFB		/**< 1:֧������PIN,0:��֧��*/
#define UN_RF_PROP_SIGNATURE		0xFFFD		/**< 1:֧��ǩ��,0:��֧��*/


/*9F6C �����صĿ�Ƭ��������*/
#define VISA_CARD_CASH_DECLIEN			0x0004	/**< VISA - (�޷���Ӧ����;���ƻ��ֽ�Ӧ����Ч�����ֽ����л�����������)Switch Interface for Cash Transactions(Application Usage Control - Cash Transactions),��VISA 'Req 5.76'*/
#define VISA_CARD_CASHBACK_DECLIEN		0x0002	/**< VISA - Switch Interface for Cashback Transactions(Application Usage Control - Cashback Transactions'*/
#define EMV_CARD_PROP_ONLINEPIN			0x0080	/**< ��Ҫ����PIN*/
#define EMV_CARD_PROP_SIANATURE			0x0040	/**< ��Ҫǩ��*/
#define EMV_CARD_PROP_DAFAIL_ONLINE		0x0020	/**< ����ѻ�������֤ʧ�ܶ��ҿ�������Ҫ������*/
#define EMV_CARD_PROP_DAFAIL_PBOCTERMIN	0x0010	/**< ����ѻ�������֤ʧ�ܶ����ն�֧��PBOC����ֹ*/
#define EMV_CARD_PROP_EXPIR_ONLINE		0x0008	/**< ���Ӧ�ù��ڣ���������*/
#define EMV_CARD_PROP_CDCVM				0x0180		/**< CDCVM�Ƿ�ִ�У� 1-CDCVM��ִ�У�0-CDCVMδִ��*/
#define EMV_CARD_PROP_ISSUSER_SCRIPT	0x0140		// �����нű��Ƿ�֧�֣��ֽ�2 λ7

YESORNO GetICTransPropIsSet(int nMask);
YESORNO GetTmTransPropIsSet(int nMask);

/*	9F10�з��صĽ��ױ�ʶ*/
#define	IAD_AAC(x )				(( *((x) + 4) & 0x30) == 0x00 )
#define	IAD_TC(x )				(( *((x) + 4) & 0x30) == 0x10 )
#define	IAD_ARQC(x )			(( *((x) + 4) & 0x30) == 0x20 )
#define 	IAD_FCHECK(x)			( *((x) + 5) & 0x20) 		/*��ƬƵ�ȼ�鳬��λ:
														�����ֽ𵥱ʽ����޶�
														�����ֽ�����
														��Ȩ������ CTTA ���� CTTAUL
														���С�ڵ����ֽ�������ֵ*/

#define ISS_IDD_ECBAL			0x01	/**< �����ֽ����*/
#define ISS_IDD_CTTA			0x02	/**< �ۻ������ܶ�*/
#define ISS_IDD_ECBAL_CTTA		0x03	/**< �����ֽ�����CTTA*/
#define ISS_IDD_CTTA_CTTAL		0x04	/**< CTTA��CTTAL*/
#define ISS_IDD_OFFBAL			0x05	/**< �����ѻ����ѽ��*/

/**<Entry Point Pre-Processing Indicators*/
typedef struct {
	char cStatusCheck;				/**< Status Check Requested */
	char bIsRf;						/**< Contactless Application Not Allowed */
	char bAmtZero;					/**< Zero Amount*/
	char bCVMExceeded;				/**< Reader CVM Required Limit Exceeded */
	char bFLExceeded;				/**< Reader Contactless Floor Limit Exceeded*/
	char sTTQ[5+1];					/**< Copy of TTQ*/
}ST_PreIndicator;

/******************************************************************************
 *  	��������:	RF_Sel_App: 
 *	��������:	qpbocӦ��ѡ��
 *	��ڲ���:	char cTransType,	��������
 					int nEmvTransSerial,	�������к�
 *	���ڲ���:     char *pcTransMode	����ģʽ
 * 	����ֵ  :		SUCC
 					FAIL
 ******************************************************************************/
extern int RF_Sel_App(char cTransType,int nEmvTransSerial,char *pcTransMode);

/******************************************************************************
 *  	��������:	RF_Sel_AppEx: 
 *	��������:	�ǽ�Ӧ��ѡ��
 *	��ڲ���:	char cTransType,	��������
 					int nEmvTransSerial,	�������к�
 *	���ڲ���:     char *pcTransMode	����ģʽ
 * 	����ֵ  :		SUCC
 					FAIL
 ******************************************************************************/
extern int RF_Sel_AppEx(char cTransType,int nEmvTransSerial,char *pcTransMode);

int RF_EMV_vDealKernelID(char *cpAid,int nAidLen,uchar *ucpKernelId);
int EMV_iSetCurrentKid(int iKernelId);
int EMV_iSendOutInformation(int iFlag, OUTCOME_ERR_TYPE eErrorType,int iKernelId);

int ParseIssData(void);
int Rf_Amount_Check();
/*	Func:	���׳ɹ����ؽ�������*/
int RF_Init_App(char *pcTransMode);
int RF_CheckExceptionFile();
int RF_deactive( int nTime );
int Rf_fail_Proc(STEMVPROC *stProc);
/******************************************************************************
 *  	��������:	Rf_Msd: 
 *	��������:	
 *	��ڲ���:	
 *	���ڲ���:     
 * 	����ֵ  :		
 ******************************************************************************/
int Rf_Msd(int *nEmvRes,char *cTransMode);
/******************************************************************************
 *  	��������:	RF_QPBOC_Trans: 
 *	��������:	
 *	��ڲ���:	
 *	���ڲ���:     
 * 	����ֵ  :		
 ******************************************************************************/
int Rf_Qpboc(STEMVPROC *stProc);

//PAYPASS ADF����
int PayPass_FinalSelect(ST_RF_ICCAID *stICCAID,STEMVPROC *stProc);
#endif

