#ifndef _DEFINE_H_
#define _DEFINE_H_

#include<string.h> 
#include<ctype.h>  
//modified by zhiyu 0923
//#include<malloc.h>  
#include<limits.h>  
#include<stdio.h>   
#include<stdlib.h>  
#include<math.h>  
#include<time.h>
/**<api*/

//#define M919_DEVICE		1		//919�豸��
#include "mf_basic.h"
#include "pub_define.h"

#include "emv_tag.h"
#include "emv_err_code.h"

/**<publib*/
#include "struct_hashtable.h"
#include "ex_convert.h"
#include "dev_file.h"
#include "printfdebug.h"

//����malloc��ͷ�ļ� add by zhiyu 0929 
#include "pub/common/misc/inc/mfmalloc.h"

//typedef unsigned char BYTE;

#define EMV_VERSION			"EMV4.3F_2017-09-01_ZY"	//MF919��֤�汾

//#define  L2_APPROVE  1  //1 - L2��֤ʱ�궨�忪��   0-Ĭ���ύ�����ã�SVNֻ�ϴ�Ϊ0�İ汾����ǰ������Ӧ�÷����п�Ƭ����tagһ��������ֹ

//#define AUTO_APPROVE	1//�Զ������Կ��� ���Ӵ����Կ������ǽӹر�
#ifndef AUTO_APPROVE
#define		QUICS	1	//QUICS�궨��
#ifndef		QUICS		
#define		VCPS		//vcps�궨��
#endif
#endif

#define MAXLEN_PAN 19
#define MAXLEN_TRACK2 37

#define MAXLEN_FILE		255
#define MAXDOL_LEN		256
#define MAXLEN_ICCRESP  MAXDOL_LEN//512 
 
#define TABLESIZE(table)    (sizeof(table)/sizeof(table[0]))

typedef enum {
	GAC_AAC = 0,
	GAC_TC,
	GAC_ARQC,
	GAC_AAR,
	GAC_TOTAL
}E_GAC;

#define FALSE 0
#define TRUE (!FALSE)


#define SUCC		0
#define FAIL		(-1)
#define QUIT		(-2)
#define TIMEOUT		(-3)
#define GOTO		(-4)
#define UNKNOW		(-5)
#define UNSUPPORT	(-6)
#define TERMINATE	(-7)
#define GOTOCONTACT (-8)
#define GOTOOTHER	(-9)
#define	GOTOUPCARD	(-10)
#define GOTO_TRYAGAIN		(-11)		//���»ӿ�
#define GOTO_CDV_TRYAGAIN	(-12)		//�ƶ��豸���»ӿ�
#define L1_ERROR	(-13)				//L1������--����L1������,L1�Ĵ������Ǹ�ֵ,���ܻ��nRet�ظ�
#define GOTO_DPAS_ZIP	(-14)
#define GOTO_DPAS_MS	(-15)
#define GOTOOTHERCARD	(-16)
//#define ASSERT_FAIL(e) \
//	if ((e) == FAIL)\
//	{\
//		return FAIL;\
//	}
//	
//#define ASSERT_QUIT(e) \
//	if ((e) == QUIT)\
//	{\
//		return QUIT;\
//	}
//#define ASSERT_UNSUCC(e) \
//	if ((e) != SUCC)\
//	{\
//		return FAIL;\
//	}\
//

#define EQ(a,b) ((a)==(b))  
#define LT(a,b) ((a)<(b))  
#define LQ(a,b) ((a)<=(b))

extern YESORNO g_RequestCDA;
//extern YESORNO g_bSm;

extern void Emv_SetErrCode(char cCode);
extern void Emv_vSetSW1SW2(int iSW1SW2);
extern int Emv_iGetSW1SW2(void);
extern int EMV_iGetL1ErrorCode(void);
extern void EMV_iSetL1ErrorCode(int iErrorCode);

//#define MAXLEN_AUTHDATA   1500  
#define MAXLEN_AUTHDATA   2048+512		//paypass�����ѻ�ǩ������2048--�ָ�IC����Կ����hash�ռ�2048+512

#ifdef M919_DEVICE
	#define MAXNUM_AIDLIST 5		//����PBOC3.0�ն��ͼ�ָ��Ҫ���ն�AID��಻����20��
#else
	#define MAXNUM_AIDLIST 20		//����PBOC3.0�ն��ͼ�ָ��Ҫ���ն�AID��಻����20��
#endif

/**<*/
//STICS stICS;
//ST_UI stUI;         /* ����EMV���õ��ⲿ����ָ��  */
//STCOMM stICOp;

//ST_TERMAID	*szAIDList;
//ST_TERMAID	*szAIDList;

#ifdef WIN32
//#define __func__ "func" 
#endif

typedef enum {
	ERR_NONE = 0,	
	ERR_PARAM,	
	ERR_COMM,		
	ERR_MEM,		

	ERR_TIMEOUT,	
	ERR_INTR,	

	ERR_UNSUPPORT,	
	ERR_USR_CANCEL,	

	ERR_I2C,			

	ERR_KEY_INVALID,	
	ERR_KEY_FETCH,	
	ERR_KEY_SAVE,		
	ERR_AUTH_FAILED,	
	ERR_COND_NOTMET,	
	ERR_KEY_LIMIT,		

	ERR_RSA_FAILED,	
	ERR_ICC_DEV,		
	ERR_OFFLINE_PIN_FAILED,	
	ERR_PIN_EMPTY,	

	ERR_CONNECT, 
	ERR_SENDDATA, 
	ERR_NODATA, 
	ERR_MEMOPER, 
	ERR_DATATOOBIG, 

	ERR_MAX
}ERR_CODE;

//char szEmvData[8000];
#endif