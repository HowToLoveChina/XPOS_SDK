/*! \file xgui_bmp.h
	\brief ͼƬ����
*	\author lx
*	\date 2014/02/08
*/
#pragma once

#include "xgui_pub.h"

/**
* @brief ����bmpͼƬ
* @param filename �ļ���
* @param width ͼƬ���
* @param height ͼƬ�߶�
* @return ͼ��λͼ������ָ�룬�ں����ڷ��䣬�ⲿʹ�ú���Ҫ�ͷ�
*/
LIB_EXPORT char * xgui_load_bmp(char * filename , int *width , int *height);

//24bitbmpͼƬ
LIB_EXPORT char * xgui_load_bmp24bit(char * filename , int *width , int *height);

LIB_EXPORT char * xgui_load_bmp4bit(char * filename , int *width , int *height);


LIB_EXPORT char * xgui_load_bmp_all(char * filename , int *width , int *height, int * color);
LIB_EXPORT char * xgui_get_bmp_file(char *filename);