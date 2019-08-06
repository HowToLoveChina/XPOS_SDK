#ifndef __LIBAPI_MAG_HEADER__
#define __LIBAPI_MAG_HEADER__

#include "libapi_pub.h"

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:2.2.8.3	��ȡ��������ģ��汾��(Mag_GetModuleVer)
Input : Nothing
Output : pszVer   ģ��汾��
return: �ɹ�����ģ��汾�ų���
		UTRACK_FAIL   =-1,           Fail
Remarks: Nothing
*************************************************************************************/
int Mag_GetModuleVer(char *pszVer);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:2.2.8.4	������������ʼ����Mag_Init��
Input : Nothing
Output : Nothing
return: UTRAC_MAG_FAIL        = -5,     //����������������ʧ��
		UTRAC_MAG_OK        = 1,      //�����������������ɹ�
Remarks: Nothing
*************************************************************************************/
int Mag_Init(void);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:2.2.8.5	����������������Mag_GetAllTrack���ɶ�ȡ1��2��3�ŵ���Ϣ�ASCII���ʽ
Input : LrcFlag: �ο�enum TrackLrc����LRC_TRACK2 | LRC_TRACK3����ʾͬʱУ��ŵ�2��3LRC(��֧�ֵĳ���NothingЧ)
		WaitFlag���ȴ���ʶ��0Ϊ���ȴ��������أ�>0Ϊ�ȴ�ʱ�䵥λΪ��
Output : CardBuf1��һ������
		CardBuf2����������
		CardBuf3����������
return: UTRACK_MAG_FAIL        = -5,      //����������������ʧ��
		UTRACK_NOEVENT   = -4,     //���ȴ�ʱ�Ż᷵�أ�˵�����ε���δ��⵽ˢ��
		UTRACK_CONTROL       = -3,     // �û��˳� 
		UTRACK_TIMEOUT   = -2,     // ˢ����ʱ 
		UTRACK_FAIL      = -1,     // ˢ����ʧ�� 
		UTRACK_OK        = 0,      //�ȴ�ʱ,���ش�ֵ����Ϊˢ���ɹ�(����ˢ����һ���ŵ�); ���ȴ�ʱ,Ϊ��⵽ˢ������ȡ�ɹ�
		UTRACK_NUM       = 2      // ���俨��(Ԥ��) 
Remarks: �����̱���ԭˢ������ʽ���䣻
		���δ�����ŵ���������Ӧ�Ļ�����Nothing���ݣ�
		����ŵ�������ȥ����ʼ���š��������š�У��ֵ��
		����LrcFlagֵ����Ӧ�ŵ�����LRCУ�飬У��ʧ�ܷ���UTRACK_FAIL
*************************************************************************************/
int Mag_GetAllTrack(byte *CardBuf1, byte *CardBuf2, byte *CardBuf3, int LrcFlag, ushort WaitFlag);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:2.2.8.6	�رմ������豸��Mag_Close��
Input : Nothing
Output : Nothing
return: UTRAC_MAG_FAIL        = -5,     //����������������ʧ��
		UTRAC_MAG_OK        = 1,      //�����������������ɹ�
Remarks: Nothing
*************************************************************************************/
int Mag_Close(void);


#endif /*__LIBAPI_MAG_HEADER__*/
