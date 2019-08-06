/*! \file osl_print.h
	\brief ��ӡ����
*	\author lx
*	\date 2014/02/08
*/
#pragma once

#include "pub\pub.h"


#define PRINT_ERR_OK			(0)
#define PRINT_ERR_NO_PAPER1		(-1)
#define PRINT_ERR_NO_PAPER2		(-2)
#define PRINT_ERR_NO_PAPER3		(-3)
#define PRINT_ERR_FILE_ERR		(-4)
#define PRINT_ERR_TIMEROVER		(-5)


#define PRINT_FONT_TYPE(x)		"<font_type=" #x ">"
#define CN_FONT_SIZE(x)			"<cn_font_size=" #x ">"
#define	EN_FONT_SIZE(x)			"<en_font_size=" #x ">"
#define	CN_FONT_ZOOM(x)			"<cn_font_zoom=" #x ">"
#define	EN_FONT_ZOOM(x)			"<en_font_zoom=" #x ">"
#define	PRINT_LINE_SPACE(x)		"<print_line_space=" #x ">"
#define	PRINT_COL_SPACE(x)		"<print_col_space=" #x ">"
#define	PRINT_ROW_SPACE(x)		"<print_row_space=" #x ">"
#define	PRINT_ALIGN(x)			"<print_align=" #x ">"
#define	PRINT_IMG(x)			"<print_img=" #x ">"
#define	PRINT_HEAT_FACTOR(x)	"<print_heat_factor=" #x ">"
#define	PRINT_BLOCK(x)			"<print_block=" #x ">"
#define	PRINT_BLOCK_WIDTH(x)	"<print_bwidth=" #x ">"
#define	PRINT_COL_TO(x)			"<print_col_to=" #x ">"

/**
* @brief ������������
* @param v ����
* @return �����ַ�
*/
LIB_EXPORT const char *  osl_print_cn_font_size(int v);
/**
* @brief ����Ӣ������
* @param v ����
* @return �����ַ�
*/
LIB_EXPORT const char *  osl_print_en_font_size(int v);
/**
* @brief ���ķŴ�
* @param w ����
* @param h ����
* @return �����ַ�
*/
LIB_EXPORT const char *  osl_print_cn_font_zoom(int w,int h);
/**
* @brief Ӣ�ķŴ�
* @param w ����
* @param h ����
* @return �����ַ�
*/
LIB_EXPORT const char *  osl_print_en_font_zoom(int w,int h);
/**
* @brief �����м��
* @param v ���
* @return �����ַ�
*/
LIB_EXPORT const char *  osl_print_line_space(int v);
/**
* @brief ������ֽ
* @param v ����
* @return �����ַ�
*/
LIB_EXPORT const char *  osl_print_col_space(int v);
/**
* @brief ������ֽ
* @param v ����
* @return �����ַ�
*/
LIB_EXPORT const char *  osl_print_row_space(int v);
/**
* @brief ���뷽ʽ
* @param v 0�� 1�� 2��
* @return �����ַ�
*/
LIB_EXPORT const char *  osl_print_align(int v);
/**
* @brief ��ӡͼƬ
* @param imgfile �ļ���
* @return  �����ַ�
*/
LIB_EXPORT const char *  osl_print_img(const char *imgfile);
/**
* @brief ����ʱ��
* @param v ʱ��
* @return �����ַ�
*/
LIB_EXPORT const char *  osl_print_heat_factor(int v);

/**
* @brief ��ȡ��ӡ������
* @return 
*/
LIB_EXPORT char * osl_print_get();
/**
* @brief ������ݵ���ӡ������
* @param pbuff ����
* @return 
*/
LIB_EXPORT void osl_print_add(const char * pbuff);
/**
* @brief ��ӡ�������ͷ�
* @return 
*/
LIB_EXPORT void osl_print_free();


/**
* @brief ��ӡ��ʼ��
* @return 
*/
LIB_EXPORT void osl_print_init();
/**
* @brief ��ӡ���
* @param data ����
* @return 0�ɹ�
*/
LIB_EXPORT int  osl_print_write(char * data);


/**
* @brief ����ԭʼ�ļ�����
* @param blockfile �ļ�
* @return  �����ַ�
*/
LIB_EXPORT const char * osl_print_block(const char *blockfile);

LIB_EXPORT const char *  osl_print_block_width(int v);






