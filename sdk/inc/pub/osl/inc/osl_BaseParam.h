#pragma once
/*! \file osl_BaseParam.h
	\brief ��������
*	\author lx
*	\date 2014/02/07
*/
#include "pub/pub.h"

#define TS_DATA_FILE		"data\\ts_data.ini"
#define SYSTEM_PROFILE		"data\\sysCfg.ini"		//ϵͳ�����ļ�����
#define TAMPER_INI_FILENAME	"data\\Tamper.ini"

#if OS_LINUX | WIN32
#define DATAVERSION_FILENAME  "xxxx\\data.ini"    //���ݰ汾��
#else
#define DATAVERSION_FILENAME  "data\\data.ini"    //���ݰ汾��
#endif

#define BASEPARAM_SECTION	"BaseParam"			//�ڻ��������������ļ��еĶ�����
#define LCDCONTRAST			"lcdContrast"		//Һ���Աȶ�,0~63
#define KEYSOUNDOPEN		"keySoundOpen"		//����������,0��1��
#define TTSSOUNDOPEN		"ttsSoundOpen"		//tts����,0��1��
#define LCDLIGHTTIME		"lcdLightTime"		//����ʱ��������Ϊ��λ
#define ENERCYTIME          "enercyTime"		//����ʱ��
#define POWER_DOWN_TIME		"PowrDownTime"		//�ػ�ʱ��
#define NET_MODE			"netMode"			//����ģʽ

#define POWER_SECTION		"Power"				//��Դ�������������ļ��еĶ�����
#define POWER_KEY_DOWN_TIME	"PowerKeyDownTime"		//��Դ�����¹ػ�ʱ��

#define TS_PARAM_SECTION	"param_section"
#define TS_LEFT_KEY			"ts_left_key"
#define TS_RIGHT_KEY		"ts_right_key"
#define TS_TOP_KEY			"ts_top_key"
#define TS_BOTTOM_KEY		"ts_bottom_key"

#define LCD_LIGHT_MAX	99999999

LIB_EXPORT void osl_ts_get(int *left , int *right , int * top, int * bottom);
LIB_EXPORT void osl_ts_set(int left , int right , int top, int bottom);
LIB_EXPORT int osl_get_language();
LIB_EXPORT void osl_set_language(int val);

#define DEVICE_VISION	 osl_getDeviceVision()  //ϵͳ�汾��


/**
* @brief ��ȡϵͳ�汾��
* @return ϵͳ�汾��
*/
LIB_EXPORT const char * osl_getDeviceVision();



#define APP_VISION	 osl_getAppVision()  //Ӧ�ð汾��




/**
* @brief ��ȡӦ�ð汾��
* @return Ӧ�ð汾��
*/
LIB_EXPORT const char * osl_getAppVision();
/**
* @brief ����Ӧ�ð汾��
* @param Ӧ�ð汾��
* @return 
*/
LIB_EXPORT void osl_setAppVision(const char *appvision);

#define DATA_VISION	 osl_GetDataVision()  //Ӧ�ð汾��

/**
* @brief ��ȡӦ�ð汾��
* @return 
*/
LIB_EXPORT  const char * osl_GetDataVision(); //��ȡ���ݰ汾��
/*
* [BaseParam]
* lcdContrast=60
* keySoundOpen=1
* lcdLightTime=120
*
*ֱ��ͨ��read_profile_int����write_profile_intд
*/


/**
* @brief ����������
* @param ʱ��
* @return 
*/
LIB_EXPORT int osl_BuzzerSound(int nMillisecond);


/**
* @brief �����Ƿ���������
* @param 1�� 0��
* @return 
*/
LIB_EXPORT int osl_SwitchKeySound(int nOpen);


/**
* @brief ��ȡ��ǰ�������Ƿ���
* @return 1�� 0��
*/
LIB_EXPORT int osl_IsKeySoundOpen();


/**
* @brief Һ������ʱ����Ϊ��λ
* @return ����ʱ��
*/
LIB_EXPORT int osl_lcd_BackLightTime();


LIB_EXPORT int osl_get_lcd_contrast();
LIB_EXPORT int osl_set_lcd_contrast(int val);



/**
* @brief ����Һ������ʱ������Ϊ��λ
* @param nTime ����ʱ��
* @return 
*/
LIB_EXPORT int osl_lcd_SetBackLightTime(int nTime);


/**
* @brief ��ȡӲ���豸�ͺ�
* @return 
*/
LIB_EXPORT int osl_GetDeviceType();
LIB_EXPORT const char *osl_getDeviceTypeName();

LIB_EXPORT int osl_get_is_mh();
LIB_EXPORT int osl_get_is_k21();
LIB_EXPORT int osl_get_is_m90();
LIB_EXPORT int osl_get_is_printer();
LIB_EXPORT int osl_get_is_power2quit();
LIB_EXPORT int osl_get_is_dual_module();
LIB_EXPORT int osl_get_is_m66();
LIB_EXPORT int osl_get_is_m67();
LIB_EXPORT int osl_get_is_m68();
LIB_EXPORT int osl_get_is_m90_key_map();
LIB_EXPORT int osl_get_is_m69();
enum{
	DEV_MODE_QR = 0,		// ����
	DEV_MODE_SCAN,			// ɨ��ǹ
};

// �豸
LIB_EXPORT int osl_get_dev_mode();


/**
* ����Ӳ���豸�ͺ�
*@return �豸�ͺ� 
* 
*/
LIB_EXPORT int ols_SetDeviceType(int  nDeviceType);

//! ͨѶģ������
enum{
	MODEL_WIRELESS = 0,		///<����
	MODEL_MODEM,			///<����
	MODEL_WIFI,				///<wifi
	MODEL_WIN32_SOCK,	///<ģ����

};
enum{
	MODEL_MODE_ONLY_WIRELESS = 0,		// �� ����
	MODEL_MODE_ONLY_WIFI,				// �� wifi
	MODEL_MODE_FRIST_WIRELESS,		// ���� ����
	MODEL_MODE_FRIST_WIFI,				// ���� wifi
};

/**
* @brief osl_model_type
* @return MODEL_WIRELESS ���� MODEL_MODEM����
*/
LIB_EXPORT int osl_model_type();
LIB_EXPORT void osl_model_set(int type);
/**
* @brief ��ʼ����ȫ���
* @return 
*/
LIB_EXPORT void osl_initTamper();
/**
* @brief ���ý���ʱ������Ϊ��λ
* @param nTime ʱ��
* @return 
*/
LIB_EXPORT int osl_Enercy_SetTime( int nTime );

/**
* @brief ����ʱ����Ϊ��λ
* @return ����ʱ��
*/
LIB_EXPORT int osl_Enercy_Time();

/**
* @brief �ػ�ʱ����Ϊ��λ
* @return �ػ�ʱ��
*/
LIB_EXPORT int osl_lcd_PowerDownTime();

/**
* @brief ���ùػ�ʱ�䣬��Ϊ��λ
* @param nTime ʱ��
* @return 
*/
LIB_EXPORT int osl_lcd_SetPowerDownTime( int nTime );
LIB_EXPORT int osl_get_net_mode();
LIB_EXPORT void osl_set_net_mode(int mode);
