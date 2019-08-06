#ifndef __ERRORCODE_H__
#define __ERRORCODE_H__
#include "pub/pub.h"
#define ERR_BASE		(-1000)





/***************** UI�������  *************************  */

#define UI_ERROR (ERR_BASE - 2000)

#define   NOLINE  (-1)   /* ����Ϊ�� */
#define  LINE_OVER  (-2)    /* ����������� */
#define  MAX_TIME_OVER  (-3)   /*ʱ�����ó������ʱ������*/
#define  MAX_LEN_OVER    (-4)  /* ���ݳ�������󳤶� */

#define TIMEOUT_EXIT            0 /*  ��ʱ�˳� */
#define  SURE_EXIT                 2    /*��ȷ�����˳�*/
#define  CANCLE_EXIT             1   /*  ��ȡ�����˳� */



#define MF_MES_TIP_ERROR               1       /*��Ϣ�ĳ�����ʾ��*/

#define UI_TIMEOUT   (UI_ERROR-3)  

/*****************USB ͨѶ����*******************/
#define USB_BASE_ERROR           (ERR_BASE-200)

#define USB_FD_ERROR               (USB_BASE_ERROR-1)     /* �ļ�����������  */
#define USB_MEMORY_ERROR      (USB_BASE_ERROR-2)     /*  �ڴ����  */
#define USB_READ_TIME_OUT     (USB_BASE_ERROR-3)    /* ����ʱ�䳬ʱ  */
#define USB_READ_ERROR           (USB_BASE_ERROR-4)    /*   */
#define USB_WRITE_TIME_OUT   (USB_BASE_ERROR-5)    /*   д��ʱ�䳬ʱ */
#define CONNECT_ERROR             (USB_BASE_ERROR-6)    /*  ���ӳ��� */
#define USB_OPEN_ERROR           (USB_BASE_ERROR-7)    /*  USB ��ʧ��   */
#define USB_INIT_ERROR            (USB_BASE_ERROR -8)  /* USB��ʼ��ʧ�� */
#define USB_CLEAR_ERROR         (USB_BASE_ERROR-9)  /*USB ���ʧ��*/
 

/*��ʱʱ��*/
#define WRITE_TIME_OUT 2000  /*3����д�볬ʱʱ��*/
#define READ_TIME_OUT  2000    /*10���ȡUSB��ʱʱ��*/
#define LOW_TIME_OUT 30      /* ������ͳ�ʱʱ�� */
#define HIGHT_TIME_OUT 120   /* */
#define SUIT_TIME_OUT 80     /* */





/***************** ͨѶ����*******************/
#define ERR_COM			(ERR_BASE)
/*****************USB ͨѶ����*******************/
#define ERR_COM_USB	(ERR_COM-100)
#define ERR_COM_USB_PARAM (ERR_COM_USB)

#define ERR_PPP			(ERR_COM-110)
#define ERR_PPP_PARAM	(ERR_PPP)
#define ERR_PPP_TIMEOUT	(ERR_PPP-1)
#define ERR_PPP_OVERNUM	(ERR_PPP-2)

#define ERR_COM_TCP		(ERR_COM-200)
#define ERR_TCP_FCNTL_FGETFL           (ERR_COM_TCP)                 /**<fcntl( F_GETFL ) error*/
#define ERR_TCP_FCNTL_FSETFL           (ERR_COM_TCP-1)             /**<fcntl( F_SETFL ) error������ʽ����ʧ��*/
#define ERR_TCP_REFUSED                    (ERR_COM_TCP-2)             /**<connect refused*/
#define ERR_TCP_SELECT                       (ERR_COM_TCP-3)            /**<select  error*/
#define ERR_TCP_SELECT_TIMEOUT      (ERR_COM_TCP-4)            /**<select  timeout*/
#define ERR_TCP_GETSOCKOPT             (ERR_COM_TCP-5)           /**<getsockopt error*/
#define ERR_TCP_CONNECT_SOMEERR  (ERR_COM_TCP-6)           /**<some error*/

/**< �ļ���������*/
#define ERR_FILE					(ERR_BASE-1000)		/**< �ļ���������*/
#define ERR_FILE_FILENAME		(ERR_FILE)			/**< �ļ���Ϊ�ջ��ļ������ȴ���*/
#define ERR_FILE_RECLEN			(ERR_FILE-1)			/**< �ļ���¼���ȴ���*/
#define ERR_FILE_FILELEN		(ERR_FILE-3)			/**< ���ļ����ȴ���*/
#define ERR_FILE_PARAM_IVALID	(ERR_FILE-4)			/**< �������Ϸ�*/
#define ERR_FILE_NO_SPACE		(ERR_FILE-5)			/**< д�ļ��ռ䲻��*/
#define ERR_FILE_SEEK			(ERR_FILE-6)			/**< �ļ���λ����*/
#define ERR_FILE_NOT_EXIST		(ERR_FILE-7)			/**< �ļ�������*/
#define ERR_FILE_DEL_FILE		(ERR_FILE-8)			/**< �ļ�ɾ������*/
#define ERR_FILE_DEL_IDX		(ERR_FILE-9)			/**< ����ɾ������*/
#define ERR_FILE_CREAT_IDX		(ERR_FILE-10)		/**< ������������*/
#define ERR_FILE_CREAT_FILE		(ERR_FILE-11)		/**< �����ļ�����*/
#define ERR_FILE_CLOSE_FILE		(ERR_FILE-12)		/**< �ļ��رմ���*/
#define ERR_FILE_OPEN_FILE		(ERR_FILE-13)		/**< ���ļ�����*/
#define ERR_FILE_READ_HEAD		(ERR_FILE-14)		/**< ��ͷ�ļ�����*/
#define ERR_FILE_READ_FILE		(ERR_FILE-15)		/**< ���ļ�����*/
#define ERR_FILE_READ_REC		(ERR_FILE-16)		/**< ����¼����*/
#define ERR_FILE_READ_INDEX	(ERR_FILE-17)		/**< ����������*/
#define ERR_FILE_WRITE_REC		(ERR_FILE-18)		/**< д��¼����*/
#define ERR_FILE_WRITE_HEAD	(ERR_FILE-19)		/**< д�ļ�ͷ����*/
#define ERR_FILE_FIND_REC		(ERR_FILE-20)		/**< ���Ҽ�¼����*/
#define ERR_FILE_UPDATEINDEX	(ERR_FILE-21)		/**< ������������*/
#define ERR_FILE_DELINDEX		(ERR_FILE-22)		/**< ɾ����������*/	
#define ERR_FILE_MALLOC			(ERR_FILE-23)		/**< �ڴ�������*/


/**< TLV �������� */
#define ERR_TLV					(ERR_BASE -1100)		
#define ERR_TLV_COUNT			(ERR_TLV)			/**< ����TLV���ݶ������*/
#define ERR_TLV_PARSER			(ERR_TLV -1)			/**< ����TLV���ݴ�*/
#define ERR_TLV_NULL			(ERR_TLV -2)			/**< TLVָ��Ϊ��*/
#define ERR_TLV_GETDATA		(ERR_TLV -3)			/**< TLV��ȡ���ݴ���*/
#define ERR_TLV_SRCLEN			(ERR_TLV -4)			/**< Դ���ݳ��ȴ���*/
#define ERR_TLV_GETTMPLT		(ERR_TLV -5)			/**< TLV��ȡģ�����ݴ���*/
#define ERR_TLV_DATA_NOT_EXIST	(ERR_TLV -6)		/**< ���ݲ�����*/
#define ERR_TLV_TAG_FORMAT	(ERR_TLV -7)			/**< TAG��ʽ����*/
#define ERR_TLV_MAXLEN			(ERR_TLV -8)			/**< �����ɽ�������󳤶�*/


/******************************************************************************
 *  ��������:	Ex_Get_Public_ErrCode: 
 *	��������:	��ȡ������
 *	��ڲ���:	��
 *	���ڲ���:     ��
 * 	����ֵ  :		�������ֵ
 ******************************************************************************/
void Ex_Set_PublibErrCode(int nCode);
/******************************************************************************
 *  ��������:	Ex_Get_Public_ErrCode: 
 *	��������:	��ȡ������
 *	��ڲ���:	��
 *	���ڲ���:     ��
 * 	����ֵ  :		�������ֵ
 ******************************************************************************/
LIB_EXPORT int Ex_Get_Public_ErrCode();
#endif
