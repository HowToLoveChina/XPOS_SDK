#ifndef _MF_SSL_
#define _MF_SSL_
#pragma once
#include "pub/pub.h"

LIB_EXPORT int mf_ssl_get_state(int s);

LIB_EXPORT int mf_ssl_mbedtls(int mbedtls);

LIB_EXPORT int mf_ssl_init(int index, char * cacert, char * clientcert, char * clientkey,int level);
LIB_EXPORT int mf_ssl_connect(int index , char * ip , int port, void * func);
//�ְ� 256һ��������
LIB_EXPORT int mf_ssl_send2(int index, char * pdata, int size);
LIB_EXPORT int mf_ssl_send(int index, char * pdata, int size);

//�ж����ն���
LIB_EXPORT int mf_ssl_recv2(int index, char * pdata, int size);
//����size���Ⱥ����
LIB_EXPORT int mf_ssl_recv(int index, char * pdata, int size);

LIB_EXPORT int mf_ssl_recv3(int index);

LIB_EXPORT int mf_ssl_close(int index);

#endif