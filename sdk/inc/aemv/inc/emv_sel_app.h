#ifndef __EMV_SEL_APP__
#define __EMV_SEL_APP__

#include <emv_data.h>
#include <emv_interface.h>
extern int Emv_Sel_App(char cTransType,int nEmvTransSerial,E_INPUTAMT eInputAMT);

/******************************************************************************
 *  	��������:	SelectIcFile: 
 *	��������:	
 *	��ڲ���:	
 *	���ڲ���:     
 * 	����ֵ  :		
 ******************************************************************************/
int SelectIcFile(char cSelMode,char *pszFileName,int nLenFileName,ST_ICFILE *stIcFile);
int PP_ADF_iSelectIcFile(char cSelMode,char *pszFileName,int nLenFileName,ST_ICFILE *stIcFile);
int PP_PPSE_iSelectIcFile(char cSelMode,char *pszFileName,int nLenFileName,ST_ICFILE *stIcFile);
int LC_PPSE_SelectIcFile(char cSelMode,char *pszFileName,int nLenFileName,ST_ICFILE *stIcFile);
/******************************************************************************
 *  	��������:	GetICCAID: 
 *	��������:	��ȡIC��AID
 *	��ڲ���:	
 *	���ڲ���:     
 * 	����ֵ  :		
 ******************************************************************************/
 int GetICCAID(pTlvData tlv,int nNum,ST_ICCAID *stICCAID,YESORNO bIssCodeIndex);
 /******************************************************************************
 *  	��������:	RF_GetICCAID: 
 *	��������:	��ȡIC��AID
 *	��ڲ���:	
 *	���ڲ���:     
 * 	����ֵ  :		
 ******************************************************************************/
  int RF_GetICCAID(pTlvData tlv,int nNum,ST_RF_ICCAID *stICCAID);
 /******************************************************************************
 *  	��������:	SortAIDList: 
 *	��������:	�Ժ�ѡAID�б�������ȼ���������
 					�������ð������
 *	��ڲ���:	ST_ICCAID  stICCAID[]: ��ѡ�б�
 					int nAIDNum: ��ѡ�б�����
 *	���ڲ���:     ST_ICCAID  stICCAID[]:�����ȼ�����õĺ�ѡ�б�
 * 	����ֵ  :		��
 ******************************************************************************/
void SortAIDList(ST_ICCAID stICCAID[],int nAIDNum);

 /******************************************************************************
 *  	��������:	SortAIDListEx: 
 *	��������:	�Ժ�ѡAID�б�������ȼ���������
 					�������ð������
 *	��ڲ���:	ST_ICCAID  stICCAID[]: ��ѡ�б�
 					int nAIDNum: ��ѡ�б�����
 *	���ڲ���:     ST_ICCAID  stICCAID[]:�����ȼ�����õĺ�ѡ�б�
 * 	����ֵ  :		��
 ******************************************************************************/
void SortAIDListEx(ST_RF_ICCAID stICCAID[],int nAIDNum);
#endif