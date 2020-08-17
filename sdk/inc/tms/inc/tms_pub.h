#pragma once

#include <pub/pub.h>
#ifdef __cplusplus
extern "C"{
#endif

//������̨TMS
LIB_EXPORT int tms_init();

//���������غõ��ļ�
LIB_EXPORT int tms_update(const char *file);



typedef enum eTMSACTION{
	TA_DOWNLOADING,	//׼��������������
	TA_UPDATEING,	//׼���������غõĳ���
}TMSACTION;


//����  0 ȡ����Ӧ����  1 �����Ӧ����
typedef int (*tms_action)(TMSACTION type);


//���tms�¼�����
LIB_EXPORT int tms_set_actionproc( tms_action proc);

//endtime �봦���������ʱ�������˳�
typedef int (*_tms_proc)(int endtime);

//����ʹ��tms�̺߳�̨������
LIB_EXPORT void	tms_setproc(_tms_proc proc);


LIB_EXPORT int tms_init2();
LIB_EXPORT int tms_check_update( const char *file);
LIB_EXPORT int tms_heart();

//�޺�̨����  ֻ�а�����Ӧ
LIB_EXPORT int tms_init3();
#ifdef __cplusplus
}
#endif	