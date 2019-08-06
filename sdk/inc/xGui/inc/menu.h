/*! \file menu.h
	\brief �˵��б�
*	\author lx
*	\date 2014/02/07
*/

#ifndef ___MENU_H___
#define ___MENU_H___ 

#include "xgui_pub.h"
#include "2ddraw.h"

#define LINESPERPAGE	5
#define WIDTHPERLINE	108
#define MAX_ITEMTEXT_LEN	256

#define AS_ARROW_NONE	(0 << 0)
#define AS_ARROW_UP		(1 << 0)
#define AS_ARROW_DOWN	(1 << 1)
#define AS_ARROW_BOTH	(AS_ARROW_UP | AS_ARROW_DOWN)

#define MENU_RET_QUIT		-1
#define MENU_RET_HANDOFF	-2
#define MENU_RET_TIMEOVER	-3

#define MENU_REFRESH	(-6)

typedef struct __st_menuitem{
	char * szItemText;
	unsigned int nTextLen;
	int position;
	int nId;
	int nData;
	struct __st_menuitem * prev;
	struct __st_menuitem * next;
}MENUITEM_ST;

typedef struct _st_xmenu {
	 MENUITEM_ST *m_pMenuHead;
	 MENUITEM_ST *m_pMenuTail;
	 MENUITEM_ST *m_pCurSel;
	int m_nLineHeight;
	int m_nCurPos;
	int m_nCount;
	int m_nChHorzPos;
	char * m_szText;
	
	
	int m_bCreated;
	int m_bEnable;
	int m_bVisible;
	int m_bInited;
	RECT m_rect;
	int m_nStyle ;
	unsigned char m_retkey[20];
	int m_retkey_len;
	int m_nLastkey;
	int pDelMenuMsg;
	unsigned int m_nkeySel;
	int m_nline;
	unsigned int m_nTimeOver;
	unsigned int m_nTick;
	int flag;
}XMENU;

/**
* @brief �����˵�
* @param szName �˵�����
* @param nStyle ��ʽ
* @param pRect ����
* @param nParam ��ʱʱ��
* @return �˵��ṹ
*/
LIB_EXPORT XMENU * xgui_menu_Create( char * szText, int nStyle,RECT * pRect, int nParam);
LIB_EXPORT XMENU * xgui_menu_Create1( char * szText, int nStyle,RECT * pRect, int nParam);
LIB_EXPORT XMENU * xgui_menu_CreateEx( char * szText, int nStyle,RECT * pRect, int nParam , int flag);

/**
* @brief ��ʾ�˵�
* @param pm �˵��ṹ
* @return 0�ɹ�
*/
LIB_EXPORT void xgui_menu_Show(XMENU * pm);

/**
* @brief ��Ӳ˵���
* @param pm �˵��ṹ
* @param szItemText �˵�����
* @param nID �˵�id
* @return 0�ɹ�
*/
LIB_EXPORT int xgui_menu_AppendMenu(XMENU * pm,  char * szItemText,int nID);
/**
* @brief ����˵���
* @param pm �˵��ṹ
* @param szItemText �˵�����
* @param nPosition �˵�id
* @param nID
* @return 0�ɹ�
*/
LIB_EXPORT int xgui_menu_InsertMenu(XMENU * pm,  char* szItemText, int nPosition,int nID);
/**
* @brief ɾ���˵���
* @param pm �˵��ṹ
* @param nPosition �˵�λ��
* @return 0�ɹ�
*/
LIB_EXPORT int xgui_menu_RemoveMenu(XMENU * pm, int nPosition);
/**
* @brief ��ȡ�˵�����
* @param pm �˵��ṹ
* @param szItemText �˵�����
* @param nPosition �˵�λ��
* @return 0�ɹ�
*/
LIB_EXPORT int xgui_menu_GetItemText(XMENU * pm, char * szItemText, int nPosition) ;
/**
* @brief ���ò˵�����
* @param pm �˵��ṹ
* @param szItemText �˵�����
* @param nPosition �˵�λ��
* @return 0�ɹ�
*/
LIB_EXPORT int xgui_menu_SetItemText(XMENU * pm, char * szItemText, int nPosition) ;
/**
* @brief ��ȡ�˵�������
* @param pm �˵��ṹ
* @return �˵�������
*/
LIB_EXPORT int xgui_menu_GetCount(XMENU * pm );
/**
* @brief ��ȡ�˵�id
* @param pm �˵��ṹ
* @param nPosition �˵�λ��
* @param pID �˵�id
* @return 0�ɹ�
*/
LIB_EXPORT int xgui_menu_GetItemID(XMENU * pm, int nPosition, int * pID);
/**
* @brief ��ȡ�˵�λ��
* @param pm �˵��ṹ
* @param nID �˵�id
* @return �˵�λ��
*/
LIB_EXPORT int xgui_menu_GetItemPosition(XMENU * pm, int nID);

/**
* @brief ��ȡ��ǰλ��
* @param pm �˵��ṹ
* @return ��ǰλ��
*/
LIB_EXPORT int xgui_menu_GetCurSel(XMENU * pm) ;
/**
* @brief ���õ�ǰλ��
* @param pm �˵��ṹ
* @param nPosition ��ǰλ��
* @return 0�ɹ�
*/
LIB_EXPORT int xgui_menu_SetCurSel(XMENU * pm, int nPosition);

/**
* @brief �˵���ʾ����
* @param pm �˵��ṹ
* @return �������
*/
LIB_EXPORT int xgui_menu_domodal(XMENU * pm);

/**
* @brief �ͷŲ˵� 
* @param pm �˵��ṹ
* @return 0�ɹ�
*/
LIB_EXPORT void xgui_menu_delete(XMENU * pm);
/**
* @brief ���ôӲ˵�����ʱ�İ���
* @param pm �˵��ṹ
* @param key ����
* @param len ��������
* @return 0�ɹ�
*/
LIB_EXPORT int xgui_menu_SetReturnKey(XMENU *pm, char *key, int len);
/**
* @brief ��ȡ�˵�����ʱ�İ���
* @param pm �˵��ṹ
* @return ����ֵ
*/
LIB_EXPORT int xgui_menu_getlastkey(XMENU * pm);
/**
* @brief ���ò˵�����
* @param pm �˵��ṹ
* @param szText �˵�����
* @return 0�ɹ�
*/
LIB_EXPORT int xgui_menu_SetTitle(XMENU* pm, const char *szText);
/**
* @brief ��ȡ�˵�����
* @param pm �˵��ṹ
* @param nID �˵�id
* @return �˵�����
*/
LIB_EXPORT int xgui_menu_GetItemData_ID(XMENU* pm, int nID);
/**
* @brief ���ò˵�����
* @param pm �˵��ṹ
* @param nID �˵�id
* @param nData �˵�����
* @return 
*/
LIB_EXPORT int xgui_menu_SetItemData_ID(XMENU *pm,int nID, int nData);
/**
* @brief ѡ��˵�
* @param pm �˵��ṹ
* @param nID �˵�id
* @return 0�ɹ�
*/
LIB_EXPORT int xgui_menu_SelItemData_ID(XMENU* pm, int nID);

LIB_EXPORT void xgui_menu_SetDelMsg(XMENU * pm,int bData);

#endif

