#ifndef _TOOL_
#define _TOOL_

extern unsigned long long BcdtoUint64( unsigned char *pszBcdBuf,  int nBufLen);
extern int IntTo4Bcd(char *psBcd, int *pnBcdLen, int nNum);
extern int VisaGetAmount(unsigned char cTransType);
extern int EmvGetAmount();

int GetPanFromTrack(const char *pszTrack,int nMaxTrackLen,int *nPanLen,char *sPan);
/******************************************************************************
 *  	��������:	RecoverTrack2: 
 *	��������:	��ԭ���ŵ��ȼ�����Ϊ���ŵ�����
 *	��ڲ���:	
 *	���ڲ���:     
 * 	����ֵ  :		
 ******************************************************************************/
int RecoverTrack2(char *psInTrack2,int nLen,char *psOutTrack2,int *nOutLen);
/******************************************************************************
 *  	��������:	GetExpiryFromTrack2: 
 *	��������:	�Ӷ��ŵ����ݻ�ȡ��Ч��
 *	��ڲ���:	
 *	���ڲ���:     
 * 	����ֵ  :		
 ******************************************************************************/
int GetExpiryFromTrack2(const char *pszTrack,int nMaxTrackLen,char *sExpiry);
/******************************************************************************
 *  	��������:	EmvGetAmt: 
 *	��������:	��ȡ���
 *	��ڲ���:	
 *	���ڲ���:     
 * 	����ֵ  :		
 ******************************************************************************/
int EmvGetAmt(char cTransType);
#endif