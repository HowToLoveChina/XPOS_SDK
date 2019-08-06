#pragma once
#include "pub/pub.h"

#define RET_SIGN_OK  1
#define RET_SIGN_CANCEL  0
#define RET_SIGN_EXIST  2
#define RET_SIGN_TIMEOUT  3


 typedef struct _procs{
	 //������� ˮӡ
	 int (*page_paint)(const char *m_watermark);  
	 int (*page_getbackcount)();  
	 //�Ƿ�����ȡ��
	 int (*page_usecancel)(); 

	 //ȡ���Ƿ���ʾ
	 int (*page_usecancelask)();  
	 
	 //ȡ����ȡˮӡ
	 int (*page_getwatermark)( char *outwatermark);


	 //�켣���ٵ���
	 int (*page_getwritepointcount)();  

	 //�Ƿ�ʹ������Աȷ��ҳ��
	 int (*page_usesigntype)(); 

	 //ͼƬ�Ƿ�ʹ��320*130�ֱ���
	 int (*page_use320_130)(); 

	 //�켣���ٱʻ���
	 int (*page_getpointupcount)();  

	 int (*page_buffwidth)();
	 int (*page_buffheight)();
	 
 }ap_sign_procs;

 //�趨������
LIB_EXPORT void ap_setprocs( ap_sign_procs *procs );

//�Ƿ���ǩ��
LIB_EXPORT int ap_sign_exist( const char *xlh );

//ǩ������
LIB_EXPORT int ap_sign_proc( const char *xlh,const char * date,const char * ckh );

//ǩ������
LIB_EXPORT int ap_sign_proc2( const char *xlh,const char * date,const char * ckh , int timeout );


//��ȡ��ӡ�ַ���
LIB_EXPORT extern const char * ap_sign_print(const char *xlh );

//JBIG����ӿ�
LIB_EXPORT int ap_sign_encode( const char *xlh,char **jbigencode );

//JBIG����ͷ�
LIB_EXPORT int ap_sign_encode_free( char *jbigencode );


//����ǩ������
LIB_EXPORT extern int ap_sign_clean();

LIB_EXPORT extern void ap_sign_test();

LIB_EXPORT int ap_sign_savetofile(char * data, const char *xlh);
