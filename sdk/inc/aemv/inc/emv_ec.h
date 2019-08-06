#ifndef __EMV_EC__
#define __EMV_EC__
#include <define.h>
#define LEN_EC_IAC 6
#define LEN_EC_BALANCE 6
#define LEN_EC_THRESHOLD 6

/******************************************************************************
 *  	函数名称:	GetandSaveECData: 
 *	函数介绍:	
 *	入口参数:	
 *	出口参数:     
 * 	返回值  :		
 ******************************************************************************/
extern int EC_GetECBalance();

/******************************************************************************
 *  	函数名称:	SetECIndicator: 
 *	函数介绍:	设置终端支持指示器
 *	入口参数:	const char *pszDol	
 					YESORNO bTIndicator
 *	出口参数:     
 * 	返回值  :		SUCC
 					FAIL
 ******************************************************************************/
extern int EC_SetIndicator();

/******************************************************************************
 *  	函数名称:	EC_ReadData: 
 *	函数介绍:	读取电子现金相关数据
 *	入口参数:	
 *	出口参数:     
 * 	返回值  :		
 ******************************************************************************/
extern int EC_ReadData(char *cTransMode);

/******************************************************************************
 *  	函数名称:	EC_GetGacType: 
 *	函数介绍:	获取电子现金请求密文类型
 *	入口参数:	
 *	出口参数:     
 * 	返回值  :		
 ******************************************************************************/
extern int EC_GetGacType(E_GAC *eGacType,char cTransMode);

/******************************************************************************
 *  	函数名称:	EC_GetOnlinePin: 
 *	函数介绍:	获取联机PIN
 *	入口参数:	
 *	出口参数:     
 * 	返回值  :		SUCC
 					FAIL
 					QUIT 取消退出
 ******************************************************************************/
int EC_GetOnlinePin();
/******************************************************************************
 *  	函数名称:	IsEcOnly: 
 *	函数介绍:	判断是否为纯电子现金卡
 *	入口参数:	
 *	出口参数:     
 * 	返回值  :		
 ******************************************************************************/
char IsEcOnly();

/******************************************************************************
 *  	函数名称:	PP_GetCardBalance: 
 *	函数介绍:	
 *	入口参数:	
 *	出口参数:     
 * 	返回值  :		
 ******************************************************************************/
extern int PP_GetCardBalance();

/******************************************************************************
 *  	函数名称:	PP_GetData: 
 *	函数介绍:	
 *	入口参数:	
 *	出口参数:     
 * 	返回值  :		
 ******************************************************************************/
extern int PP_GetData(char * pTag);


#endif