#ifndef __RF_H__
#define __RF_H__
#include "pub/pub.h"

#define  RF_INIT_ERROR (-5)
/******************************************************************************
 *  ��������:	Rf_PowerOn
 *	��������:	���ǽӿ��ϵ�
 *	��ڲ���:	
 *	���ڲ���:     
 * 	����ֵ  :		
 ******************************************************************************/
LIB_EXPORT extern int Rf_PowerOn();

/******************************************************************************
 *  ��������:	Rf_PowerDown
 *	��������:	���ǽӿ��µ�
 *	��ڲ���:	
 *	���ڲ���:     
 * 	����ֵ  :		
 ******************************************************************************/
LIB_EXPORT extern int Rf_PowerDown();
/******************************************************************************
 *  ��������:	Rf_Device_PowerOn
 *	��������:	���ǽ��豸�ϵ�
 *	��ڲ���:	
 *	���ڲ���:     
 * 	����ֵ  :		
 ******************************************************************************/
LIB_EXPORT extern int Rf_Device_PowerOn(int nType);

LIB_EXPORT extern int Rf_WriteCmd(const unsigned char * InData,int Insize,unsigned char *OutData,int *OutSize);
LIB_EXPORT extern int Rf_Check_CardIsExist();

LIB_EXPORT extern int Rf_Device_open();
//
//
//extern void test_rfid();
#endif



