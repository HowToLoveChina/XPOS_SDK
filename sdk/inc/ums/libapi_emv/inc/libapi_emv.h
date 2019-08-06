#ifndef _LIBAPI_EMV__H__
#define _LIBAPI_EMV__H__

#include "def.h"



//��������Emv �ں˻ص���������������
//����˵��:
//		���:cType :��ʾ��Ϣ����1���ѻ�����2-���һ���ѻ�����3 ��������
//				chance���ѻ�PIN ����ʣ�����
//		����: pszPin����������
//
//����ֵ:
//		�ѻ����أ� -3 ��ȡ����ֹ����=0 δ�������밴ȷ��(bypass) > 0 ��
//						������볤��
//		�������أ�-3 ��ȡ����ֹ����=0 ��������ֱ�Ӱ�ȷ��>0 �ɹ�
int EMV_InputPasswd(char cType, ushort chance, char *pszPin);


//��������:Emv �ں˻ص��������������
//����˵��:�����
//			      ����Amount������Ľ�12 �ֽ�ASCII �Ҷ��룬��0
//����ֵ: EMV_CANCEL = -14, //����ȡ��
//			EMV_OK = 0 //ִ�гɹ�
int EMV_InputAmount(byte *Amount);

//��ȡEMV ����ģ��汾��
//���:��
//����:pszVer ģ��汾��
//����ֵ:�ɹ�����ģ��汾�ų���
//			UEMV_FAIL = -1, //ִ��ʧ��
int EMV_GetModuleVer(char *pszVer);

//��������:EMV �ն˲���ʼ��
//����˵��:���ptermconfig ���ն˲���
//					st_callbackfun; �ص�����
//				����:��
//����ֵ: UEMV_PRM_ERR =-8, //EMV ������
//			UEMV_PRM_FAIL=-1, //EMV ��������ʧ��
//			UEMV_PRM_OK=0 //EMV ���������ɹ�
//����˵��:����Ӧ��ʱ����
//int EMV_TermConfigInit(const TERMCONFIG *ptermconfig, STEMVCALLBACKFUN *st_callbackfun);
int EMV_TermConfigInit(const TERMCONFIG *ptermconfig);

//��������:��ȡ�ں˰汾
//����˵��:���Size ������ֵ��󳤶�
//				����KernelVersion: ���ص��ں˰汾
//����ֵ:��
//
void EMV_GetKernelVersion(char *KernelVersion, int size);

//��������:���EMV �ں���ˮ��������¼
//����˵��:�����
//				������
//����ֵ: UEMV_PRM_FAIL=-1, //EMV ��������ʧ��
//			UEMV_PRM_OK=0 //EMV ���������ɹ�
//����˵��: �彻����ˮʱ����
int EMV_ClrWater(void);

//��������:����TAG ��ȡ��Ƭ���ݣ��ӿ�Ƭ�л�ȡTAG ֵ
//����˵��:���iSlotType���μ�enum SlotType
//					iCardType���μ�enum IccType
//					tag: ����tag
//			����:DataBuf: �������ָ��
//					Len: ������ݳ���
//����ֵ: UEMV_PRM_NOT_FOUND=-3, //EMV ����δ�ҵ�
//			UEMV_PRM_FAIL=-1, //EMV ��������ʧ��
//			UEMV_PRM_OK=0 //EMV ���������ɹ�
//����˵��:֧�ַǽ�
//int EMV_GetCardData(int iSlotType, int iCardType, char* Tag, byte* DataBuf, int* Len);
int EMV_GetCardData(char* Tag, byte* DataBuf, int* Len);

//��������:����ָ��tag �����ݣ����浽EMV �ں�
//����˵��: ���Tag�� tag ֵ
//					  Len�����ݳ���	
//					  Value: ��������
//				������
//����ֵ: UEMV_PRM_ERR =-8, //EMV ������
//			UEMV_PRM_FAIL=-1, //EMV ��������ʧ��
//			UEMV_PRM_OK=0 //EMV ���������ɹ�
//����˵��:���׹������ã����һ�ʽ��ף�
//				��Դ���ն˵�tag ���޸ģ���Դ�ڿ�Ƭ��tag �޷��޸�
int EMV_StoreKernelData(char *Tag, int Len, byte *Value);


//������������ָ��tag �����ݣ���EMV �ں��л�ȡָ��TAG ֵ
//����˵��:���Tag: tag ֵ
//				����Len��Value ���ݳ���
//					   Value: ȡ������������
//����ֵ: UEMV_PRM_NOT_FOUND=-3, //EMV ����δ�ҵ�
//			UEMV_PRM_FAIL=-1, //EMV ��������ʧ��
//			UEMV_PRM_OK=0 //EMV ���������ɹ�
//����˵��: ���ڴ�tag�����Ǵ�tag û�г�ֵʱ������UEMV_PRM_FAIL��
//				�����ڴ�tag����tag �Ϸ�������UEMV_PRM_NOT_FOUND
int EMV_GetKernelData (char *Tag, int *Len, byte *Value);

//��������: ����AID ����
//����˵��: ���pTerminalApps: AID ��������ָ��
//				������
//����ֵ: UEMV_PRM_ERR =-8, //EMV ������
//			UEMV_PRM_FAIL=-1, //EMV ��������ʧ��
//			UEMV_PRM_OK=0 //EMV ���������ɹ�
int EMV_PrmSetAIDPrm(TERMINALAPPLIST *pTerminalApps);

//��������: ��ȡAID ����
//����˵��: �����
//				����pTerminalApps: AID ��������ָ��
//
//����ֵ: UEMV_PRM_NOT_FOUND=-3, //EMV ����δ�ҵ�
//			UEMV_PRM_FAIL=-1, //EMV ��������ʧ��
//			UEMV_PRM_OK=0 //EMV ���������ɹ�
int EMV_PrmGetAIDPrm(TERMINALAPPLIST *pTerminalApps);

//��������: ɾ��AID ����
//����˵��: ���AID: AID ����ָ��
//					 AID_Len: AID ����
//				������
//����ֵ: UEMV_PRM_NOT_FOUND=-3, //EMV ����δ�ҵ�
//			UEMV_PRM_FAIL=-1, //EMV ��������ʧ��
//			UEMV_PRM_OK=0 //EMV ���������ɹ�
int EMV_PrmDelAIDPrm(byte *AID, byte AID_Len);

//��������: ���AID ����
//����˵��: �����
//				������
//����ֵ: UEMV_PRM_FAIL=-1, //EMV ��������ʧ��
//			UEMV_PRM_OK=0 //EMV ���������ɹ�
//
int EMV_PrmClearAIDPrmFile(void);

//��������: ���湫Կ
//����˵��: ���ppkKey: ��Կ�ṹָ��
//				������
//����ֵ: UEMV_PRM_ERR =-8, //EMV ������
//			UEMV_PRM_CAPK_CHK_HASH_FAIL=-2, //��ԿHASH У�����
//			UEMV_PRM_FAIL=-1, //EMV ��������ʧ��
//			UEMV_PRM_OK=0 //EMV ���������ɹ�
//����˵��:���ڹ��ܹ�ԿУ��ֵ�����޸ģ��Ͻӿڲ������ã���ʹ��
//				EMV_PrmSetCAPKTLV ���湫Կ
//
int EMV_PrmSetCAPK(CAPUBLICKEY *ppkKey);

//��������: ���湫Կ
//����˵��: ���pCAPK: ��Կ����TLV ��ʽ�����"��֤���Ĺ�Կ����"
//			      		  nLen����Կ���ݳ���
//			       ������
//����ֵ: UEMV_PRM_ERR =-8, //EMV ������
//			UEMV_PRM_CAPK_CHK_HASH_FAIL=-2, //��ԿHASH У�����
//			UEMV_PRM_FAIL=-1, //EMV ��������ʧ��
//			UEMV_PRM_OK=0 //EMV ���������ɹ�
//	
int EMV_PrmSetCAPKTLV(byte *pCAPK, int nLen);

//��������: ����RID ��������ȡ��Կ
//����˵��: ���RID: RID ����
//					PKIndex: ��Կ����
//				����ppkKey: ��ȡ���Ĺ�Կ
//����ֵ: UEMV_PRM_NOT_FOUND=-3, //EMV ����δ�ҵ�
//			UEMV_PRM_FAIL=-1, //EMV ��������ʧ��
//			UEMV_PRM_OK=0 //EMV ���������ɹ�
//����˵��: ���ڹ��ܹ�ԿУ��ֵ�����޸ģ��Ͻӿڲ������ã���ʹ��
//				EMV_PrmGetCAPKTLV
int EMV_PrmGetCAPK(CAPUBLICKEY *ppkKey, byte *RID, byte PKIndex);

//��������: ����RID ��������ȡ��Կ
//����˵��: ���RID: RID ����
//					PKIndex: ��Կ����
//				����pCAPK: ��ȡ���Ĺ�Կ����,TLV ��ʽ,�����"��֤���Ĺ�Կ������
//						pnLen:��Կ���ݳ���
//����ֵ: UEMV_PRM_NOT_FOUND=-3, //EMV ����δ�ҵ�
//			UEMV_PRM_FAIL=-1, //EMV ��������ʧ��
//			UEMV_PRM_OK=0 //EMV ���������ɹ�
//
int EMV_PrmGetCAPKTLV(byte *pCAPK, int *pnLen, byte *RID, byte PKIndex);

//��������: ����RID ������ɾ����Կ
//����˵��: ���RID: RID ����
//					 PKIndex: ��Կ����
//				����
//����ֵ: UEMV_PRM_NOT_FOUND=-3, //EMV ����δ�ҵ�
//			UEMV_PRM_FAIL=-1, //EMV ��������ʧ��
//			UEMV_PRM_OK=0 //EMV ���������ɹ�
//����˵��: ֧��Emv_PrmSetCAPK ��Emv_SetCAPKTLV ����Ĺ�Կ
int EMV_PrmDelCAPK(byte *RID, byte PKIndex);

//��������:��չ�Կ����
//����˵��: �����
//				������
//����ֵ: UEMV_PRM_FAIL=-1, //EMV ��������ʧ��
//			UEMV_PRM_OK=0 //EMV ���������ɹ�
//����˵��: ֧��Emv_PrmSetCAPK ��Emv_SetCAPKTLV ����Ĺ�Կ
int EMV_PrmClearCAPKFile(void);

//��������: EMV/PBOC �����̣�����Ӧ��ѡ�񡢷���GPO �������Ӧ�ó�ʼ��
//				��ȡӦ������
//����˵��: ���iSlotType���μ�enum SlotType
//					iCardType���μ�enum IccType
//				������
//����ֵ: UEMV_DECLINED = -15, //���׾ܾ�
//			UEMV_CANCEL = -14, //����ȡ��
//			UEMV_ONLINE = -13, //����Ӧ����
//			UEMV_CVM_FAIL = -12, //�ֿ�����֤ʧ��
//			UEMV_FALLBACK = -8, //����fallback
//			UEMV_APP_BLOCK = -7, //Ӧ������
//			UEMV_CANDIDATELIST_EMPTY = -6, //�޹�ͬӦ��
//			UEMV_PARA_ERR = -5, //������
//			UEMV_CARD_BLOCK = -4, //��Ƭ����
//			UEMV_COMMAND_FAIL = -3, //����ʧ��
//			UEMV_CARD_REMOVED = -2, //�����п�Ƭ���ƿ�
//			UEMV_FAIL = -1, //ִ��ʧ��
//			UEMV_OK = 0 //ִ�гɹ�
int EMV_ProcessSingleFlow(int iSlotType, int iCardType);

//��������: EMV/PBOC ��׼����(����ǰ)
//		�����Ĵ�������:����Ӧ��ѡ�񡢷���GPO �������Ӧ�ó�ʼ����ȡӦ�����ݡ�
//		�ѻ�������֤���������ơ��ֿ�����֤���ն˷��չ�����Ƭ��Ϊ����
//����˵��: ���iSlotType���μ�enum SlotType
//					iCardType���μ�enum IccType
//					OnlineFlag��ǿ��������ʶ��0 ��ǿ�ƣ�1 ǿ��
//				����pbMessage������˵��������NULL ʱ����ʾ�����������˵��
//����ֵ: UEMV_EC_DECLINED = -19, //�����ֽ��ѻ��ܾ�
//			UEMV_DECLINED = -15, //���׾ܾ�
//			UEMV_CANCEL = -14, //����ȡ��
//			UEMV_ONLINE = -13, //����Ӧ����
//			UEMV_CVM_FAIL = -12, //�ֿ�����֤ʧ��
//			UEMV_APP_EXPIRED = -11, //Ӧ����ʧЧ
//			UEMV_APP_EFFECT = -10, //Ӧ����δ��Ч
//			UEMV_AUTH_FAIL = -9, //������֤ʧ��
//			UEMV_FALLBACK = -8, //����fallback
//			UEMV_APP_BLOCK = -7, //Ӧ������
//			UEMV_CANDIDATELIST_EMPTY = -6, //�޹�ͬӦ��
//			UEMV_PARA_ERR = -5, //������
//			UEMV_CARD_BLOCK = -4, //��Ƭ����
//			UEMV_COMMAND_FAIL = -3, //����ʧ��
//			UEMV_CARD_REMOVED = -2, //�����п�Ƭ���ƿ�
//			UEMV_FAIL = -1, //ִ��ʧ��
//			UEMV_OK = 0 //ִ�гɹ�
//			UEMV_EC_ACCEPT = 6, //�����ֽ��ѻ�����
//			UEMV_OFFLINE_ACCEPT = 7 //��׼�����ѻ�����
//����˵��:Onlineflag ���ȼ�����SetParameter ��0001��
//			�����ֽ��ѻ����ܷ���UEMV_EC_ACCEPT��
//			������ѻ����ܷ���UEMV_OFFLINE_ACCEPT
//			�����ֽ��ѻ��ܾ�UEMV_EC_DECLINED�������ܾ�ΪUEMV_DECLINED��
int EMV_ProcessNormFlow(int iSlotType, int iCardType, int OnlineFlag, byte *pbMessage);

//��������: EMV/PBOC ǿ������(������)�������Ĵ������̣�
//					�������������нű��������	
//����˵��: ���SlotType���μ�enum SlotType
//					CardType���μ�enum IccType
//					bCommResult:����������:2 ������׼,1 �����ܾ�,0 ͨѶʧ��
//					usAuthResCode��������������
//					Field55Data�����յ���IC ��������
//					DataLen�� �����Field55Data ���ݳ���
//				����pbMessage������˵��������NULL ʱ����ʾ�����������˵��
//����ֵ: UEMV_DECLINED = -15, //��Ƭ�ܾ�
//			UEMV_PARA_ERR = -5, //������ݴ�
//			UEMV_COMMAND_FAIL = -3, //�뿨Ƭ���ݽ���ʧ��
//			UEMV_CARD_REMOVED = -2, //�����п�Ƭ���ƿ�
//			UEMV_FAIL = -1, //����ʧ��
//			UEMV_OK = 0 //ִ�гɹ�
//����˵��: ���Field55Data Ϊ����������IC �������ݣ��������ȣ�
//			�ڶ���GAC ����TC ʱ������UEMV_OK������AAC ʱ������
//			UEMV_DECLINED��
//			�ⲿ��֤ʧ��,�ű�ִ��ʧ�ܵ�ʧ��ԭ���ͨ��IC ��tag ���ݷ����õ�
int EMV_ProcessFroceFlow(int iSlotType, int iCardType, byte bCommResult, 
				char *usAuthResCode, char *Field55Data, uint *DataLen, byte *pbMessage);

//��������:��ȡ��Ƭ���ն˹�֧ͬ�ֵ�Ӧ��
//����˵��: ���iSlotType���μ�enum SlotType
//					iCardType���μ�enum IccType
//				����
//����ֵ: UEMV_APP_BLOCK = -7, //Ӧ������
//			UEMV_CANDIDATELIST_EMPTY = -6, //�޹�ͬӦ��
//			UEMV_PARA_ERR = -5, //������
//			UEMV_CARD_BLOCK = -4, //��Ƭ����
//			UEMV_COMMAND_FAIL = -3, //����ʧ��
//			UEMV_CARD_REMOVED = -2, //�����п�Ƭ���ƿ�
//			UEMV_FAIL = -1, //ִ��ʧ��
//			UEMV_OK = 0 //ִ�гɹ�
//����˵��:�ο�PBOC ��׼
//				��ȡ��Ӧ���б���API ����ά��
int EMV_GetAppCandidate(int iSlotType, int iCardType);

//��������:����Ӧ�����ȼ�����֧ͬ�ֵ�Ӧ�����򣬹��û�ѡ��
//����˵��: ���iSlotType���μ�enum SlotType
//					iCardType���μ�enum IccType
//				����
//����ֵ: UEMV_CANCEL = -14, //����ȡ��
//			UEMV_APP_BLOCK = -7, //Ӧ������
//			UEMV_COMMAND_FAIL = -3, //����ʧ��
//			UEMV_CARD_REMOVED = -2, //�����п�Ƭ����
//			UEMV_FAIL = -1, //ִ��ʧ��
//			UEMV_OK = 0 //ִ�гɹ�
//����˵��:���ն˲�֧�ֳֿ���ѡ��Ӧ�ã�Ӧ�Զ�ѡ�����ȼ���ߵ�Ӧ�ã�
//			�����ڶ�����ȼ���ͬ��Ӧ�ã������ѡ��һ��
int EMV_SelectApp(int iSlotType, int iCardType);

//��������: Ӧ�ó�ʼ��������GPO ����֪ͨIC ����ʼ����
//����˵��: ���iSlotType���μ�enum SlotType
//					iCardType���μ�enum IccType
//				����
//����ֵ: UEMV_APP_NOACCEPT = -18, //Ӧ�ò����ܣ�������ѡ��
//			UEMV_FALLBACK = -8, //����fallback
//			UEMV_APP_BLOCK = -7, //Ӧ������
//			UEMV_PARA_ERR = -5, //������
//			UEMV_COMMAND_FAIL = -3, //����ʧ��
//			UEMV_CARD_REMOVED = -2, //�����п�Ƭ���ƿ�
//			UEMV_FAIL = -1, //ִ��ʧ��
//			UEMV_OK = 0 //ִ�гɹ�
int EMV_InitiateApp(int iSlotType, int iCardType);

//���������ն˻�ȡIC ���а��������ݣ�����ɽ����еĸ��ֹ���
//����˵��: ���iSlotType���μ�enum SlotType
//					iCardType���μ�enum IccType
//				����
//����ֵ: UEMV_COMMAND_FAIL = -3, //����ʧ��
//			UEMV_CARD_REMOVED = -2, //�����п�Ƭ���ƿ�
//			UEMV_FAIL = -1, //ִ��ʧ��
//			UEMV_OK = 0 //ִ�гɹ�
//����˵��: ��ȡ��Ƭ���������ݣ����ݴ洢��API ����ά��
int EMV_ReadAppData(int iSlotType, int iCardType);

//��������: �ѻ�������֤�������ն˼���Ƭ֧�������ִ����Ӧ������֤
//����˵��: ���iSlotType���μ�enum SlotType
//					iCardType���μ�enum IccType
//				����
//����ֵ: UEMV_AUTH_FAIL = -9, //������֤ʧ��
//			UEMV_COMMAND_FAIL = -3, //�뿨Ƭ���ݽ���ʧ��
//			UEMV_CARD_REMOVED = -2, //�����п�Ƭ���ƿ�
//			UEMV_FAIL = -1, //ִ��ʧ��
//			UEMV_OK = 0 //ִ�гɹ�
int EMV_DataAuth(int iSlotType, int iCardType);

//��������: ���״������ƣ����IC ���е�Ӧ�����ն���Ӧ�õļ��ݳ̶ȣ���������ĵ�����
//����˵��: ���iSlotType���μ�enum SlotType
//					iCardType���μ�enum IccType
//				����
//����ֵ: UEMV_DECLINED = -15, //���׾ܾ�
//			UEMV_APP_EXPIRED = -11, //Ӧ����ʧЧ
//			UEMV_APP_EFFECT = -10, //Ӧ����δ��Ч
//			UEMV_PARA_ERR = -5, //������
//			UEMV_COMMAND_FAIL = -3, //����ʧ��
//			UEMV_CARD_REMOVED = -2, //�����п�Ƭ���ƿ�
//			UEMV_FAIL = -1, //ִ��ʧ��
//			UEMV_OK = 0 //ִ�гɹ�
int EMV_ProcRestrict(int iSlotTyp, int iCardType);

//���������ն˷��չ������ն�Ϊ�����յ��С������м�֧��ϵͳ������թ�ķ��չ���
//����˵��: ���iSlotType���μ�enum SlotType
//					iCardType���μ�enum IccType
//				����
//����ֵ: UEMV_DECLINED = -15, //���׾ܾ�
//			UEMV_PARA_ERR = -5, //������
//			UEMV_COMMAND_FAIL = -3, //����ʧ��
//			UEMV_CARD_REMOVED = -2, //�����п�Ƭ���ƿ�
//			UEMV_FAIL = -1, //ִ��ʧ��
//			UEMV_OK = 0 //ִ�гɹ�
//����˵��: ���չ����漰�Ľ�����ˮ������API ���ں�����ά��
int EMV_TermRiskManage(int iSlotType, int iCardType);

//��������: �ֿ�����֤,����֤��ǰ��Ƭ��ʹ�����Ƿ��ǿ�Ƭ��Ӧ����Ȩ���ˡ�
//����˵��: ���iSlotType���μ�enum SlotType
//					iCardType���μ�enum IccType
//				����
//����ֵ: UEMV_DECLINED = -15, //���׾ܾ�
//			UEMV_CANCEL = -14, //����ȡ��
//			UEMV_CVM_FAIL = -12, //�ֿ�����֤ʧ��
//			UEMV_PARA_ERR = -5, //������
//			UEMV_COMMAND_FAIL = -3, //����ʧ��
//			UEMV_CARD_REMOVED = -2, //�����п�Ƭ���ƿ�
//			UEMV_FAIL = -1, //ִ��ʧ��
//			UEMV_OK = 0 //ִ�гɹ�
int EMV_VerfCardholder(int iSlotType, int iCardType);

//��������: �ն���Ϊ�������ն˽��жϽ����Ƿ�Ӧ����׼Ϊ�ѻ����ס�
//			�ܾ��ѻ����׻�תΪ�������ס�
//����˵��: ���iSlotType���μ�enum SlotType
//					iCardType���μ�enum IccType
//				����
//����ֵ: UEMV_DECLINED = -15, //���׾ܾ�
//			UEMV_ONLINE = -13, //����Ӧ����
//			UEMV_PARA_ERR = -5, //������
//			UEMV_COMMAND_FAIL = -3, //����ʧ��
//			UEMV_CARD_REMOVED = -2, //�����п�Ƭ���ƿ�
//			UEMV_FAIL = -1, //ִ��ʧ��
//			UEMV_OK = 0 //ִ�гɹ�
int EMV_TermAnalys(int iSlotType, int iCardType);

//��������: �����ֽ�����ѯ
//����˵��: ���SlotType���μ�enum SlotType
//					CardType���μ�enum IccType
//				����Amount�����
//����ֵ: UEMV_FAIL = -1, //ִ��ʧ��
//			UEMV_OK = 0, //ִ�гɹ�
//����˵��: ��ȡ�����ֽ���֧�ֽӴ�ʽ���ǽӴ�ʽ
int EMV_GetECBalance(int iSlotType, int iCardType, unsigned long *Amount);

//��������: ���÷ǽӽ��׿�BIN �������б�
//����˵��: ���st_EmvExpBINList���ο�struct EMVEXCEPTIONBINLIST
//				������
//����ֵ: UEMV_PRM_FAIL=-1, //EMV ��������ʧ��
//			UEMV_PRM_OK=0 //EMV ���������ɹ�
//
int EMV_RF_PrmSetExceptionBINList(const EMVEXCEPTIONBINLIST *st_EmvExpBINList);

//��������: ��ȡ�ǽӽ��׿�BIN �������б�
//����˵��: �����
//				����st_EmvExpBINList���ο�struct EMVEXCEPTIONBINLIST
//����ֵ: UEMV_PRM_NOT_FOUND=-3, //EMV ����δ�ҵ�
//			UEMV_PRM_FAIL=-1, //EMV ��������ʧ��
//			UEMV_PRM_OK=0 //EMV ���������ɹ�
int EMV_RF_PrmGetExceptionBINList(EMVEXCEPTIONBINLIST *st_EmvExpBINList);

//��������: ɾ��һ���ǽӽ��׿�BIN ������
//����˵��: ���st_EmvExpBIN���ο�struct EMVEXCEPTIONBIN
//				����
//����ֵ: UEMV_PRM_NOT_FOUND=-3, //EMV ����δ�ҵ�
//			UEMV_PRM_FAIL=-1, //EMV ��������ʧ��
//			UEMV_PRM_OK=0 //EMV ���������ɹ�
int EMV_RF_PrmDelExceptionBIN(const EMVEXCEPTIONBIN *st_EmvExpBIN);

//��������: ��շǽӽ��׿�BIN �������б��ļ�
//����˵��: �����
//				����
//����ֵ: UEMV_PRM_FAIL=-1, //EMV ��������ʧ��
//			UEMV_PRM_OK=0 //EMV ���������ɹ�
//
int EMV_RF_PrmClearExceptionBINFile(void);

//��������: �ǽӴ�ʽ���״������:qPBOC ����Ԥ����,Ӧ��ѡ��,����GPO ����
//			����Ӧ�ó�ʼ��,��ȡӦ������,�ѻ�������֤,֧����������
//����˵��: ���iSlotType���μ�enum SlotType
//					iCardType���μ�enum IccType
//					Amount: ���
//					iEmvRFType: �μ�enum EmvRFType
//				����pbMessage������˵��������NULL ʱ����ʾ�����������˵��
//����ֵ: UEMV_QPBOC_DODGE = -20, //��������ʧ��
//			UEMV_APP_NOACCEPT = -18, //Ӧ�ò����ܣ�������ѡ��
//			UEMV_DECLINED = -15, //���׾ܾ�
//			UEMV_CANCEL = -14, //����ȡ��
//			UEMV_CVM_FAIL = -12, //�ֿ�����֤ʧ��
//			UEMV_APP_EXPIRED = -11, //Ӧ����ʧЧ
//			UEMV_APP_EFFECT = -10, //Ӧ����δ��Ч
//			UEMV_AUTH_FAIL = -9, //������֤ʧ��
//			UEMV_APP_BLOCK = -7, //Ӧ������
//			UEMV_CANDIDATELIST_EMPTY = -6, //�޹�ͬӦ��
//			UEMV_PARA_ERR = -5, //������
//			UEMV_CARD_BLOCK = -4, //��Ƭ����
//			UEMV_COMMAND_FAIL = -3, //����ʧ��
//			UEMV_CARD_REMOVED = -2, //�����п�Ƭ���ƿ�
//			UEMV_FAIL = -1, //ִ��ʧ��
//			UEMV_OTHER_INTERFACE = 1, //�볢������ͨ�Ž���
//			UEMV_QPBOC_OFFLINE = 2, //�ǽӴ�QPBOC �����ѻ�����
//			UEMV_QPBOC_ONLINE = 3, //�ǽӴ�QPBOC ��������,Ӧ�ò���������������
//			UEMV_PBOC_ONLINE = 4 //�ǽӴ�PBOC ��������,Ӧ�ò���������������
//����˵��: ������Ѱ��������EmvRFType ִ�в�ͬ�ķǽ����̣�
//			�������������ص�EMV_cqPBOCDodgeRefresh ˢ�½�����ʾ��Ѱ����
//			����������ȫ����������ɹ����ص�EMV_cqPBOCDogeRemoveTrace ��
//			Ӧ��ɾ��ʧ�ܽ�����ˮ��
//			����������ȫ����������ʧ�ܣ�����UEMV_QPBOC_DODGE��Ӧ�ò���
//			��ʧ�ܽ�����ˮ������ʧ�ܷ����뱣��ʧ�ܽ�����ˮ(��������ʱ�ڻص�
//			EMV_cqPBOCDodgeRefresh �ڼ�¼ʧ�ܽ�����ˮ)��
int EMV_RF_ProcessFlow(int iSlotType, int iCardType, unsigned long *Amount,int iEmvRFType, byte *pbMessage);

//��������: �ǽӴ�ʽ���������̣���������֤�������нű������
//����˵��: ���iSlotType���μ�enum SlotType
//					iCardType���μ�enum IccType
//					bCommResult: ����������2 ������׼,1 �����ܾ�,0ͨѶʧ��
//					usAuthResCode��������������
//					Field55Data�����յ���IC ��������
//					DataLen�� �����Field55Data ���ݳ���
//				����Field55Data���������IC ��������
//						DataLen�� ������Field55Data ���ݳ���
//						pbMessage������˵��������NULL ʱ����ʾ�����������˵��
//����ֵ: UEMV_SCRIPT_FAIL = -17, //�����нű�ִ��ʧ��
//			UEMV_ARPC_FAIL = -16, //��������֤ʧ��
//			UEMV_DECLINED = -15, //��Ƭ�ܾ�
//			UEMV_PARA_ERR = -5, //������ݴ�
//			UEMV_COMMAND_FAIL = -3, //�뿨Ƭ���ݽ���ʧ��
//			UEMV_CARD_REMOVED = -2, //�����п�Ƭ���ƿ�
//			UEMV_FAIL = -1, //����ʧ��
//			UEMV_OK = 0 //ִ�гɹ�
//����˵��: �ǽ�PBOC ��������������
int EMV_RF_OnlineFollowProcess(int iSlotType, int iCardType, byte bCommResult, 
		char *usAuthResCode, char *Field55Data, uint *DataLen, byte *pbMessage);

//��������: �ǽӴ�ʽ������ɣ��ǽӶ������µ�
//����˵��: ���iSlotType���μ�enum SlotType
//					iCardType���μ�enum IccType
//					TransFinal: 0-���׾ܾ�,1-���׽���
//				������
//����ֵ: UEMV_FAIL = -1, //ִ��ʧ��
//			UEMV_OK = 0, //ִ�гɹ�
int EMV_RF_Complete(int iSlotType, int iCardType, byte TransFinal);


//���ں˷ǽӶ�����(Ԥ��)

//�������ܱ���AID ����
int EMV_PCDPrmSetAIDPrm(TERMINALAPPLIST *pTerminalApps);
int EMV_PCDPrmGetAIDPrm(TERMINALAPPLIST *pTerminalApps);
int EMV_PCDPrmDelAIDPrm(byte *AID, byte AID_Len);
//��������:���AID ����
int EMV_PCDPrmClearAIDPrmFile(void);
//��������:���湫Կ
int EMV_PCDPrmSetCAPK(CAPUBLICKEY *ppkKey);
//��������: ����RID ��������ȡ��Կ
int EMV_PCDPrmGetCAPK(CAPUBLICKEY *ppkKey, byte *RID, byte PKIndex);
//��������: ����RID ������ɾ����Կ
int EMV_PCDPrmDelCAPK(byte *RID, byte PKIndex);
//��������:��չ�Կ����
int EMV_PCDPrmClearCAPKFile(void);
//��������:���ÿ�BIN �������б�
int EMV_PCDPrmSetExceptionBINList(const EMVEXCEPTIONBINLIST *st_EmvExpBINList);
//��������:��ȡ��BIN �������б�
int EMV_PCDPrmGetExceptionBINList(EMVEXCEPTIONBINLIST *st_EmvExpBINList);
//��������:ɾ��һ����BIN ������
int EMV_PCDPrmDelExceptionBIN(const EMVEXCEPTIONBIN *st_EmvExpBIN);
//��������:��տ�BIN �������б��ļ�
int EMV_PCDPrmClearExceptionBINFile(void);
//��������:�ǽӶ�����������ʼ��
int EMV_PCDConfigInit(int iSlotType, const TERMCONFIG *ptermconfig);
//��������: �ǽӴ�ʽ���״��������qPBOC ����Ԥ����Ѱ����Ӧ��ѡ�񡢷���GPO
//			�������Ӧ�ó�ʼ������ȡӦ�����ݡ��ѻ�������֤
int EMV_PCDProcessFlow(unsigned long *Amount,int iEmvRFType, byte Timeout, byte *pbMessage);
//��������: ��ȡ���׽��
int EMV_PCDProcessFlow_GetResult(byte *pbMessage);
//��������:ȡ������
int EMV_PCDProcessFlow_Cancel(byte *pbMessage);
//��������: �ǽӴ�ʽ���������̣���������֤�������нű������
int EMV_PCDOnlineFollowProcess(byte bCommResult, char *usAuthResCode,
		char *Field55Data, uint *DataLen, byte *pbMessage);
//�������ܷǽӴ�ʽ������ɣ��ǽӶ������µ�
int EMV_PCDComplete(byte TransFinal);
//�������ܻ�ȡ�����ֽ����
int EMV_PCDGetECBalance(unsigned long *Amount);
//�������ܽ������豸�л��������״̬
int EMV_PCDSwitch2Pinpad(void);
//

//////////////////////////////////////////////////////////////////////////////////


//��������:��aid ���ü���ǣ�����Ԥ����Ԥ������̶�Ӧ
//				PBOC �淶��ʮ����6.2.2 �½�
//����˵��: ���iSlotType���μ�enum SlotType
//					iCardType���μ�enum IccType
//					ptPreProcInfo �μ�struct Clss_PreProcInfo
//					ptTransParam �μ�struct Clss_TransParam
//				������
//����ֵ: UEMV_PARA_ERR = -5, //������
//			UEMV_FAIL = -1, //ִ��ʧ��
//			UEMV_OK = 0, //ִ�гɹ�
//			UEMV_OTHER_INTERFACE = 1, //�볢������ͨ�Ž���
//����˵��:���е�AID ��������Ԥ����Ҫ���򷵻�UEMV_OTHER_INTERFACE��
//				ֻҪһ��AID ����Ҫ�󷵻�UEMV_OK��
//				�������󷵻�UEMV_PARA_ERR��
//				�������󷵻�UEMV_FAIL
//			��ע��Clss_PreProcInfo *ptPreProcInfo ����������ָ�룬��
//			Clss_PreProcInfo �ĳ�ԱaucRFU ��ֵΪ��"FF"ʱ����ʾ��ֹ�������һ�����ݣ�
//			Ԥ����ʱ�轫�������AID ���ն�Ӧ�ú�ѡ�б���ɾ��������ͨ��
//			EMV_RF_AppSlt �뿨Ƭ���AID ƥ��
int EMV_RF_PreTransProc(/*int iSlotType, */int iCardType,
			Clss_PreProcInfo *ptPreProcInfo, Clss_TransParam *ptTransParam);

//��������:Ӧ��ѡ�񣬽���Ӧ�ú�ѡ�б�����Ӧ��ѡ�����ں��Զ�ѡ��������ȼ�Ӧ��
//����˵��: ���iSlotType���μ�enum SlotType
//					 iCardType���μ�enum IccType
//				����pucKernType  ����ѡ���Ӧ���ں�����
//				 	KERNTYPE_JCB��JCB	KERNTYPE_MC:MASTERCARD	
//					KERNTYPE_VIS��VISA     KERNTYPE_PBOC��PBOC
//					KERNTYPE_AE: American Express  
//					    pucDtOut--����ѡ��ʱ���ն�AID ���ƣ�BCD ��ʽ
//					   pnDtLen -- pucDtOut �����ݳ���
//����ֵ: UEMV_APP_NOACCEPT = -18,//����ѡ��Ӧ�ã�Ӧɾ����ǰӦ��
//			UEMV_CANDIDATELIST_EMPTY = -6, //���ն�֧��Ӧ��
//			UEMV_PARA_ERR = -5, //������
//			UEMV_CARD_BLOCK = -4, //��Ƭ����
//			UEMV_CANCEL = -14, //����ȡ��
//			UEMV_APP_BLOCK = -7, //Ӧ������
//			UEMV_COMMAND_FAIL = -3, //����ʧ��
//			UEMV_CARD_REMOVED = -2, //�����п�Ƭ����
//			UEMV_FAIL = -1, //ִ��ʧ��
//			UEMV_OK = 0 //ִ�гɹ�
//			UEMV_OTHER_INTERFACE = 1, //�볢������ͨ�Ž���
//����˵��: ��ע�����ǽ����̴����������������ѡ��Ӧ�õ����֮ʱ�������µ���
//			��������ӿڡ����˽ӿ��ڷ�װ������Ҫ�Զ�ɾ����ǰӦ�ã�ֱ�Ӵ���
//			��Ӧ��ѡ��
//			����Ƿǽӽ���Ԥ����EMV_RF_PreTransProc �󣬵�һ��ִ�иýӿ�ʱ
//			��Ҫ������ѡ�б���ִ������ѡ��
//			�����������ѡ��Ӧ�ã�����ִ�иýӿ�ʱ��ֻ��Ҫɾ����ǰӦ�ú����
//			����Ӧ��ѡ��
//			�����һ����Ȩʧ�ܣ�����ִ�иýӿ�ʱ��ֻ��Ҫɾ����ǰӦ�ú������
//			��Ӧ��ѡ��
//			�������ѡ��ʱ��Ӧ�ã�����UEMV_OTHER_INTERFACE
int EMV_RF_AppSlt(/*int iSlotType, */int iCardType, uchar *pucKernType,
			uchar *pucDtOut, int *pnDtLen);

//��������: ʵ��GPO ����Ӧ�����ݣ�ʵ��QPBOC ��GP0 ��Read Reord �������
//				�ص��Ƿǽ�PBOC ·����ҲҪʵ��GPO ��Read Record��
//				֧����������
//����˵��: ���iSlotType���μ�enum SlotType				
//					 iCardType���μ�enum IccType
//				����pucTransPath ����·������
//					CLSS_VISA_QVSDC ��qPBOC ��ʽ  CLSS_VISA_VSDC�������ǽ�PBOC ��ʽ
//					   pucACType   AC ���ͣ�//QPBOC ����
//								AC_ AAC, AC_ TC, AC_ ARQC
//					   pucType��ֻ��ARQC ��AC �����¸ò�������Ч�ֿ�����֤��ʽ
//					   	RD_CVM_NO�� �޳ֿ�����֤
//						RD_CVM_ONLINE_PIN�� ����PIN
//						RD_CVM_SIG�� ǩ��
//					ֻ��AC ����ΪTC ��������Ż���Ҫִ�зǽӵڶ�����Ȩ��
//					���AC ����ΪARQC������ִ�еڶ�����Ȩ
//����ֵ: UEMV_APP_NOACCEPT = -18,//����ѡ��Ӧ�ã�Ӧɾ����ǰӦ��
//			UEMV_DECLINED = -15, //���׾ܾ�
//			UEMV_CANCEL = -14, //����ȡ��
//			UEMV_ONLINE = -13, //����Ӧ����
//			//���AC ΪAAC ����UEMV_DECLINED,���AC ΪAC_ ARQC ����UEMV_ONLINE
//			//���AC ΪTC �������л����ǽ�PBOC �򷵻�UEMV_OK
//			UEMV_APP_EXPIRED = -11, //Ӧ����ʧЧ//QPBOC
//			UEMV_PARA_ERR = -5, //������
//			UEMV_COMMAND_FAIL = -3, //����ʧ��
//			UEMV_CARD_REMOVED = -2, //�����п�Ƭ���ƿ�
//			UEMV_FAIL = -1, //ִ��ʧ��
//			UEMV_OK = 0, //ִ�гɹ�
//			UEMV_OTHER_INTERFACE = 1,, //��ֹ�ǽӴ�����, ʹ�ýӴ����淽ʽִ�н��ס�
//����˵��: �������������ص�EMV_cqPBOCDodgeRefresh ˢ�½�����ʾ��Ѱ����
//				����������ȫ����������ɹ����ص�EMV_cqPBOCDogeRemoveTrace ��
//				Ӧ��ɾ��ʧ�ܽ�����ˮ��
int EMV_RF_1stProctrans (/*int iSlotType, */int iCardType, uchar *pucTransPath, 
				uchar *pucACType, uchar *pucType);

//��������: �ǽӵڶ�����Ȩ��ʵ���ѻ�������֤���ֿ�����֤(ֻ����QPBOC ��
//				��,1stProctrans ACType ΪTC ��ִ�д˺���)
//				�����QPBOC TC ���ף�ֻ��Ҫ�ѻ�������֤��
//				�����ʱAC ���ͷ���ARQC,����Ҫ���سֿ�����֤����
//����˵��: ���iSlotType���μ�enum SlotType
//					iCardType���μ�enum IccType
//				����pucACType ��������õ�AC ����(�˴����ܷ���AC_ AAC, AC_ TC, AC_ ARQC��
//					pucType��ֻ��ARQC ��AC �����¸ò�������Ч�ֿ�����֤��ʽ
//						RD_CVM_NO�� �޳ֿ�����֤
//						RD_CVM_ONLINE_PIN�� ����PIN
//						RD_CVM_SIG�� ǩ��
//����ֵ: UEMV_QPBOC_DODGE = -20, //��������ʧ��	
//			UEMV_DECLINED = -15, //���׾ܾ�
//			UEMV_CANCEL = -14, //����ȡ��
//			UEMV_ONLINE = -13, //����Ӧ����
//			UEMV_AUTH_FAIL = -9, //������֤ʧ��
//			UEMV_PARA_ERR = -5, //������
//			UEMV_FAIL = -1, //ִ��ʧ��
//			UEMV_OK = 0, //ִ�гɹ�
//����˵��: ����������ȫ����������ʧ�ܣ�����UEMV_QPBOC_DODGE��Ӧ�ò���
//			��ʧ�ܽ�����ˮ������ʧ�ܷ����뱣��ʧ�ܽ�����ˮ(��������ʱ�ڻص�
//			EMV_cqPBOCDodgeRefresh �ڼ�¼ʧ�ܽ�����ˮ)��
//			��fdda ʧ�ܣ�����9f6c �жϷ���UEMV_ONLINE ��UEMV_AUTH_FAIL
int EMV_RF_2sdProctrans(int iSlotType, int iCardType, uchar *pucACType, uchar *pucType);

////////////////////////////////////////////////////
//�ص�������ԭ�ͼ�����˵��
////////////////////////////////////////////////////

//��������: Emv �ں˻ص��������ֿ���֤����֤
//����˵��: ���
//				����
//����ֵ: UEMV_CANCEL = -14, //����ȡ��
//			UEMV_CVM_FAIL = -12, //�ֿ�����֤ʧ��
//			UEMV_OK = 0, //ִ�гɹ�
//
int EMV_cVerifyIDCard(void);

//��������: Emv �ں˻ص�������Ӧ��ѡ��
//����˵��: ���pstAPPList Ӧ�ýṹ������
//						nAPPNum Ӧ�ø���
//				������
//����ֵ>=0 ��ʾѡ���Ӧ��
//			UEMV_CANCEL = -14, //����ȡ��
//			
int EMV_cSelectAapp(STAPPINFO *pstAPPList, int nAPPNum);

//��������: Emv �ں˻ص����������������ػ�ˢ�½�����ʾ��Ϣ������Ѱ��
//����˵��: ���psCmdBuf
//					0-�������������»ӿ���
//					1-�����ػӿ��Ų��������»ӿ�
//				������
//����ֵ: UEMV_FAIL = -1, //ִ��ʧ��
//			UEMV_OK = 0, //ִ�гɹ�
//����˵��: psCmdBuf:ָ���ַ���
//				0-�ص�����ˢ��POS ������ʾ��Ϣ�����ȴ����»ӿ��������ڲ�����static
//				   �������š���������ʧ�ܽ�����ˮ��
//				1-�ص�����ˢ��POS ������ʾ��Ϣ����ʾ�¿�������ԭ����һ�£�����
//				   �����»ӿ�
int EMV_cqPBOCDodgeRefresh(void *psCmdBuf);

//��������: Emv �ں˻ص�����������������ɻص���Ӧ��ɾ��ʧ�ܵĽ�����ˮ
//����˵��: �����
//				������
//����ֵ: UEMV_FAIL = -1, //ִ��ʧ��
//			UEMV_OK = 0, //ִ�гɹ�
//����˵��: ����������ɣ��ص��ú�����Ӧ��ɾ��ʧ�ܵĽ�����ˮ
int EMV_cqPBOCDogeRemoveTrace(void);
///////////////////////////////////////////////////////////////////////////////////


//��������Emv �ں˻ص���������
//����˵��: ���pstEMVCALLBACKFUN EMV �ص������ṹ��
//				������
//����ֵ: UEMV_PRM_ERR =-4, //EMV ������
//			UEMV_PRM_FAIL=-1, //EMV ��������ʧ��
//			UEMV_PRM_OK=0 //EMV ���������ɹ�
//����˵��: EMV �ں˳�ʼ��֮�����
int EMV_SetCallbackFun(STEMVCALLBACKFUN2 *pstEMVCALLBACKFUN);

//��������: Emv ��������
//����˵��: ���psParameter �����б�TLV ��ʽ
//				������
//����ֵ: UEMV_PRM_ERR =-4, //EMV ������
//			UEMV_PRM_FAIL=-1, //EMV ��������ʧ��
//			UEMV_PRM_OK=0 //EMV ���������ɹ�
//����˵��: TLV��4 �ֽ�TAG��2 �ֽ�HEX ����LENGTH�������ֽڵ�VALUE
//				0001���Ƿ�ǿ��������0x00-��0x01-�ǣ��������̽���֮�����ָ�				
//					Ϊǿ����������
//				0002���Ƿ�֧�ֵ����ֽ�0x00-��0x01-�ǣ��������̽���֮�����
//					�ָ�Ϊ��֧�ֵ����ֽ𣩣�
//				0003���Ƿ�����ѡ����Ӧ�ã�0x00-��0x01-�ǣ��������̽���֮��
//					�������״̬����
//				0004���Ƿ�֧����������0x00-��0x01-�ǣ�EMV �ں˳�ʼ��֮���
//					�ã�Ĭ�ϲ�֧�ּ�����������ֱ�ӷ���ʧ�ܣ�����¿���Ӧ�����⣩����
//				0005��������¼�ɴ���ʱ��T2��Ĭ�ϡ�60��s��
//				0006������������¼������Ĭ�ϡ�3����
//				0007���Ƿ�֧�ֹ���IC ����ʹ�ù��ܹ�Կ�ѻ�������֤��0x00-��0x01-
//					�ǣ�EMV �ں˳�ʼ��֮����ã�
//
int EMV_SetParameter(char *psParameter);


//��������:��ȡ�ǽ����̴������
//����˵��:
//				���	��
//				����	pnErrorCode �������
//����ֵ	UEMV_FAIL 				 = -1,		//ִ��ʧ��
//			UEMV_OK					 =  0,		//ִ�гɹ�
//����˵��	���ǽӽ������̷���ʧ��ʱ���ɵ��ô˽ӿ�
//				��ȡ����Ĵ�����룬������뼰����������¼D
int EMV_RF_GetErrorCode(int *pnErrorCode);


#endif
