#ifndef __RF_PAYPASS_API__
#define __RF_PAYPASS_API__

#include "emv_interface.h"

//������
#define PP_RET_SUCC							0
#define PP_RET_TERMINAL						1		//������ֹ
#define PP_RET_SELECT_NEXT					2		//ѡ����һ��Ӧ��
#define PP_RET_MAGSTRIPE_NOT_SUPPORTED		3		//����ģʽ��֧��,������ֹ
#define PP_RET_TRAN_AMOUNT_NOT_EXIST		4		//���׽����ڣ�������ֹ
#define PP_RET_TRY_AGAIN					5		//���»ӿ�
#define PP_RET_TRY_AGAIN_CDV				6		//�ƶ��豸���»ӿ�
#define PP_RET_ERR_TRY_OTH					7		//�����������棬������ֹ
#define PP_RET_PDOL_MISS					8		//PDOL MISS ������ֹ
#define PP_RET_FIRST_WRITE_FLAG_TIME_OUT    9		//��һ��д��־Ϊ�գ�������ֹ
#define PP_RET_USER_STOP					10		//�û�ȡ����������ֹ


//paypass����������
//���»ӿ�/�ƶ��豸���»ӿ�/������ֹ/������������


	
int PP_iPayPassFlow(STEMVPROC *stProc);
int PP_iPayPassInit(void);
int PP_iFreeTranRelateBuf(void);


//PPSE�׶δ����봦��
int PP_PPSE_ErrorProcess(int iResultCode);

//ֹͣ�ͺŴ���
int PP_iCheckStopSignal(int iStep);



#endif