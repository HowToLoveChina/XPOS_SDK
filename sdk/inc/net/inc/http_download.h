/*! \file http_download.h
	\brief http����
*	\author lx
*	\date 2014/02/08
*/
#pragma once

#include <pub/pub.h>
#ifdef __cplusplus
extern "C"{
#endif



/**
* @brief http ����
* @param url ��ַ
* @param fullpathfilename ���ص������ļ���
* @param iscontinue �Ƿ�����  1���� 0��������
* @return 0�ɹ�  <0ʧ��
*/
LIB_EXPORT int http_download(const char *url,const char *fullpathfilename,int iscontinue);

/**
* @brief http ����
* @param url ��ַ
* @param fullpathfilename ���ص������ļ���
* @param iscontinue �Ƿ�����  1���� 0��������
* @param nRetry ���Դ���
* @return 0�ɹ�  <0ʧ��
*/
LIB_EXPORT int http_download_retry( const char *url,const char *fullpathfilename,int iscontinue, int nRetry );



//���ȴ���
typedef int (*http_download_progress)( int current, int total);
LIB_EXPORT int http_download_progress_set(http_download_progress progressfun);

#ifdef __cplusplus
}
#endif

