#ifndef __EMV_CH_VERIFY__
#define __EMV_CH_VERIFY__
#include <emv_interface.h>
#define MAXLEN_CVM	252

#define CVM0_CON_FAIL				0x00	/**<CVM����ʧ��*/
#define CVM0_CON_PLAINPIN			0x01	/**<IC�����е�����PIN��֤*/
#define CVM0_CON_ONLINEPIN			0x02	/**<��������PIN��֤*/
#define CVM0_CON_PLAINPIN_SIG		0x03	/**<IC�����е�����PIN��֤��ǩ����ֽ�ϣ�*/
#define CVM0_CON_ENCIPHPIN			0x04	/**<IC�����еļ���PIN��֤*/
#define CVM0_CON_ENCIPHPIN_SIG		0x05	/**<IC�����еļ���PIN��֤��ǩ����ֽ�ϣ�*/
#define CVM0_CON_SIG				0x1E	/**<ǩ����ֽ�ϣ�*/
#define CVM0_CON_NOCVM				0x1F	/**<����CVM*/
#define CVM0_CON_CERT				0x20	/**<�ֿ��˳�ʾ֤��*/

#define CVM1_CON_ALL		0x00	/**<����*/
#define CVM1_CON_ATM		0x01	/**<ATM������ֽ����*/
#define CVM1_CON_NOCASH	0x02	/**<��������ֽ����*/
#define CVM1_CON_CVM		0x03	/**<����ն�֧��CVM*/
#define CVM1_CON_MANUAL	0x04	/**<������˹�ֵ���ֽ���*/
#define CVM1_CON_CASHBACK	0x05	/**<����Ƿ��ֽ���*/
#define CVM1_CON_LX			0x06	/**<���������Ӧ�ñ��ֽ�������ֵС��X*/
#define CVM1_CON_GX		0x07	/**<���������Ӧ�ñ��ֽ�������ֵ����X*/
#define CVM1_CON_LY			0x08	/**<���������Ӧ�ñ��ֽ�������ֵС��Y*/
#define CVM1_CON_GY		0x09	/**<���������Ӧ�ñ��ֽ�������ֵ����Y*/


#define VERIFY_PLAIN	0x00	/**<����PIN��֤*/
#define VERIFY_ENCYPT	0x01	/**<����PIN��֤*/

#define OFFLINE_PIN_NOMAL		0x03	/**<��ʾ�����ѻ�PIN*/
#define OFFLINE_PIN_AGAIN		0x02	/**<��ʾ�ٴ������ѻ�PIN*/
#define OFFLINE_PIN_LAST		0x01	/**<���һ�������ѻ�PIN*/

/**<CVM�����3�ֽ�*/
#define CVM_RESULT_SUCC	0x02		/**<�ɹ�*/
#define CVM_RESULT_FAIL	0x01		/**<ʧ��*/
#define CVM_RESULT_UNKNOW	0x00		/**<δ֪(ǩ��)*/

#define CVMR3_UNKNOW_ONLINE		0x10	/**<����*/	
#define CVMR3_UNKNOW_SIGNATRUE	0x20	/**<ǩ��*/
#define CVMR3_UNKNOW_OTHER		0x30	/**<����*/

extern int Emv_Ch_Verify(STEMVPROC *stProc);
extern int PayPass_Ch_Verify(int iType,int *piCvmFlag);
/******************************************************************************
 *  	��������:	GetOnlinePin: 
 *	��������:	��ȡ����PIN
 *	��ڲ���:	
 *	���ڲ���:     
 * 	����ֵ  :		SUCC
 					FAIL
 					QUIT ȡ���˳�
 ******************************************************************************/
extern int GetOnlinePin(void);
#endif