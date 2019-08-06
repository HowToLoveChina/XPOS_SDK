#ifndef __EMV_DATA__
#define __EMV_DATA__ 
#include "define.h"

#define LEN_RANDOM 4

typedef struct {
	unsigned char szDF_84[16+1];			/*	DF��*/
	int nDFLen;							/**<�ļ�������*/
	unsigned char szFCI_A5[MAXLEN_ICCRESP+1];	/*	FCI����*/
	int nFCILen;							/**<FCI���ݳ���*/
}ST_ICFILE;

/*****paypass���������ӿ�********/
/* ����Ԫ�ṹ */
typedef struct ST_DATA_ELEMENT
{
	uchar   ucTag[3+1];		// ���ݱ�ǩ(��󳤶�3�ֽ�)
	uchar   ucLenTag;		// ���ݱ�ǩ��ʵ�ʳ���
	uchar   ucLenCheck;		// ����У���־		0---��У�鳤��  1--У�鳤��
	ushort  usLenMin;		// ���ݵ���С���� 
	ushort  usLenMax;		// ���ݵ���󳤶� 
	uchar   ucState;		// ����Ԫ״̬(0---������  1---Emtpy 2--Not Empty)
	uchar	cTempType;		// ����Ԫ�������ڵ�ģ��
	uchar   ucIsSupportRA;	// �Ƿ�֧��RA��������
}ST_Element;



#endif

extern int InitEmvData(char *pszData,int nLen);
extern void FreeEmvData(void);
extern YESORNO TagIsTermData(char *pszTag,int nLen);
//extern int GetEmvData(char *pszTag,char *pszData,int *nDataLen);
extern int SaveEmvTlvData(TlvData elem,YESORNO bOverride);
extern int PP_SaveEmvTlvDataForUnknown(TlvData elem,int iType);
extern int SaveEmvData(char *pszTag,char *pszData,int nLen,YESORNO bOverride);
extern int SetEmvData(int nIndex,char cTransType,int nEmvTransSerial);
extern void paypass_random_number(char *sRanNumber);

//paypass���������ӿ�
void FreeActResource(void);
void UpdateParamForSelectNextApp(void);		//next app����
void PP_UpdateParamForSelectNextApp(char *pActParam,int iActParamLen);
int ClearHashTableData(void);
int InitEmvDataEx(void);
int InitEmvDataEx2(char *pszData,int nLen);
//int LC_InitEmvData(char *pszData,int nLen,EMV_stTermAIDList *pstTermAid,int iAidCount);
int PP_iPreProcess(void);
void FreeEmvDataEx(void);
void LC_FreeEmvData(void);
void FreeEmvDataEx2(void);
int  PP_iSaveDetInfo(char *pTlvList,int iListLen);
int PP_iIsPermitDetUpate(char *pTag,int iTagLen);
int  PP_iParseAndStoreCardResponse(char *pTemp,int iTempLen,TlvData elem);
int EMV_iTermSupportAidCount(void);
void EMV_vDisplayTermSupportAid(void);
int PayPass_IsKnownTag(char *pTag,int iTagLen);
int PayPass_iUpdateUnknownTagState(char *Tag,int iTagLen,int iValueLen);
int PayPass_iUpdateTermParamTagState(char *Tag,int iTagLen,int iValueLen);
int PayPass_iCheckTagState(char *Tag);
void PP_vInitTableElement(void);
void PP_vInitTableElement_ADF(void);
int PayPass_iSetUnknownTagUpdateRA(char *pTag,int iTagLen);

int EMV_GetCurrentKid(void);
int EMV_iSetCurrentKid(int iKernelId);

