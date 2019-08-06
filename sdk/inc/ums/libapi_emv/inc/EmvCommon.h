#ifndef _EMV_COMMON_H_
#define _EMV_COMMON_H_

#define BOOL int
#define TRUE 1
#define FALSE 0

#define MAX_APP_ITEMS       16



#define MAX_APPNAME_LEN					33		//AppName����󳤶�

#define CAPK_FILE	"Emv_Capk.dat"
#define APP_FILE	"Emv_AppLst.dat"


#define PEDICCARD	0x01			//0x01:����IC��
#define EXICCARD	0x02			//����IC��
#define PEDPICCCARD	0x03			//����PICC
#define EXPICCCARD	0x04			//����PICC 



#define STATPIN_NONE 			0		//����ҪPIN
#define STATPIN_INOLINEPIN 		1		//����������PIN
#define STATPIN_CDCVM	   		2		//������CDCVM
#define STATPIN_PINBYPASS  		3		//����PIN,�û�ֱ��PYPASS
#define STATPIN_OFFLINEPIN 		4		//�ɹ���ִ�����ѻ�PIN
#define STATPIN_CERT			5		//�ɹ��Ľ�����֤����֤

//#define TERM_AIDLIST		"termaid.lst"   
#define ICC_SCRIPT_FILE		"iccscript"
#define FILE_TRADE_ATT		"trade.att"


//�ǽӽ���ͨ��
#define TRADE_CHANNEL_AUTO 0
#define TRADE_CHANNEL_ONLINE 1
#define TRADE_CHANNEL_OFFLINE 2
#define TRADE_CHANNEL_CLPBOC  3


//STRUCTOR DEF
typedef struct _EMV_APPLIST_{
    unsigned char AppName[MAX_APPNAME_LEN];	//����Ӧ����,��'\x00'��β���ַ���
    unsigned char AID[17];				//Ӧ�ñ�־
    unsigned char AidLen;				//AID�ĳ���
    unsigned char SelFlag;				//ѡ���־(0����ƥ��/1ȫƥ��)      
    unsigned char Priority;				//���ȼ���־
    unsigned char TargetPer;			//Ŀ��ٷֱ���
    unsigned char MaxTargetPer;			//���Ŀ��ٷֱ���
    unsigned char FloorLimitCheck;		//�Ƿ�������޶�
    unsigned char RandTransSel;			//�Ƿ�����������ѡ��
    unsigned char VelocityCheck;		//�Ƿ����Ƶ�ȼ��
    unsigned long FloorLimit;			//����޶�
    unsigned long Threshold;			//��ֵ
    unsigned char TACDenial[6];			//�ն���Ϊ����(�ܾ�)
    unsigned char TACOnline[6];			//�ն���Ϊ����(����)
    unsigned char TACDefault[6];		//�ն���Ϊ����(ȱʡ)
    unsigned char AcquierId[7];			//�յ��б�־
    unsigned char dDOL[100];				//�ն�ȱʡDDOL
    unsigned char PreferAppName[17];   
    unsigned char AppLabel[17];
    unsigned char PreferLang[8 + 1]; //5F2D ��ѡ����
    unsigned char codeIdx;  //9f11 ��������
    unsigned char TerminalType;  //�ն�����
    //����
    unsigned char bUseIntParam;  //�Ƿ�ʹ�ù��ʲ���
    unsigned char TargetPerInt;
    unsigned char MaxTargetPerInt;
    unsigned char FloorLimitInt[4];
    unsigned char ThresholdInt[4];
	
    unsigned char Capability[3];			//�ն�����
    unsigned char ExCapability[5];			//�ն���չ����
   
    unsigned char reserved_0[92];
    unsigned char tDOL[256];			//�ն�ȱʡTDOL
    unsigned char Version[3];			//Ӧ�ð汾
    unsigned char RiskManData[10];		//���չ�������
	unsigned char EC_bTermLimitCheck;	//�Ƿ�֧���ն˽����޶�
	unsigned long EC_TermLimit;			//�ն˽����޶
	unsigned char CL_bStatusCheck;		//�Ƿ�֧��qPBOC״̬���
	unsigned long CL_FloorLimit;        //�ǽӴ��ն�����޶�
	unsigned long CL_TransLimit;        //�ǽӴ��ն˽����޶�
	unsigned long CL_CVMLimit;          //�ǽӴ��ն�CVM��
	unsigned char TermQuali_byte2;      //���׽����ÿ��AID�޶���жϽ������ˢ��ǰ����ͨ���˱��������жϽ��
	unsigned char bOnlinePin;           //��AID�Ƿ�֧������PIN
}EMV_APPLIST;

typedef struct _EMV_CLAPPLIST_{
    unsigned char AppName[MAX_APPNAME_LEN];	//����Ӧ����,��'\x00'��β���ַ���
    unsigned char AID[17];					//Ӧ�ñ�־
    unsigned char AidLen;					//AID�ĳ���
    unsigned char SelFlag;					//ѡ���־( ����ƥ��/ȫƥ��) 
    
    unsigned char Priority;					//���ȼ���־
    unsigned char TargetPer;				//Ŀ��ٷֱ���
    unsigned char MaxTargetPer;				//���Ŀ��ٷֱ���
    unsigned char FloorLimitCheck;			//�Ƿ�������޶�
    
    unsigned char RandTransSel;				//�Ƿ�����������ѡ��
    unsigned char VelocityCheck;			//�Ƿ����Ƶ�ȼ��
    
    unsigned long FloorLimit;				//����޶�
    unsigned long Threshold;				//��ֵ
    unsigned char TACDenial[6];				//�ն���Ϊ����(�ܾ�)
    unsigned char TACOnline[6];				//�ն���Ϊ����(����)
    
    unsigned char TACDefault[6];			//�ն���Ϊ����(ȱʡ)
    unsigned char AcquierId[7];				//�յ��б�־
    unsigned char dDOL[100];				//�ն�ȱʡDDOL
    unsigned char PreferAppName[17];   
    unsigned char AppLabel[17];
    unsigned char PreferLang[8 + 1]; //5F2D ��ѡ����
    unsigned char codeIdx;  //9f11 ��������
    unsigned char TerminalType;  //�ն�����
	//����
    	unsigned char bUseIntParam;  //�Ƿ�ʹ�ù��ʲ���
	unsigned char TargetPerInt;
	unsigned char MaxTargetPerInt;
	unsigned char FloorLimitInt[4];
	unsigned char ThresholdInt[4];

	unsigned char Capability[3];			//�ն�����
	unsigned char ExCapability[5];			//�ն���չ����
    	unsigned char reserved_0[92];
	unsigned char tDOL[82];				//�ն�ȱʡTDOL
    //
    // 24byte for paywave
  	unsigned char CL_bZeroAmtNoCheck;   //�Ƿ񲻽���0����鷴�߼�
  	unsigned char CL_zeroAmtCheckOpt; //0--0������� ��0--�ܾ�����
	unsigned char CL_bTransLimitCheck;
	unsigned char CL_bCVMLimitCheck;
	unsigned char CL_bFloorLimitCheck;
	unsigned char CL_bCLFloorLimit;  //�Ƿ��зǽ�����޶�
	unsigned char CL_bAppNotAllowed;//��̬����
	unsigned char bSupCVN17; ///* MSD CVN17 �Ƿ�֧�ֱ�־, 0-��֧�֣�1- ֧��*/
	unsigned char TermQuali_byte3;
	unsigned char TermQuali_byte4;
 	unsigned char reserved_for_paywave[14];
   //
   // for paypasss 104byte
   	unsigned char MagStripeAVN[2];  //Mag-stripe Application Version Number (Reader)
	unsigned char KernelID;
	unsigned char KernelConfig;
	unsigned char CVMCapabilityCVM;
	unsigned char CVMCapabilityNoCVM;
	unsigned char MagCVMCapabilityCVM;
	unsigned char MagCVMCapabilityNoCVM;

	unsigned char TransLimitODCVM[4];
	unsigned char TransLimitNoODCVM[4];
	unsigned char uDOL[81];
	unsigned char reserved_for_paypass[7];
   //
    unsigned char reserved_2[46];                 //����
    unsigned char Version[3];				//Ӧ�ð汾
    
    unsigned char RiskManData[10];			//���չ�������
	unsigned char EC_bTermLimitCheck;		//�Ƿ�֧���ն˽����޶�
	
	unsigned long EC_TermLimit;				//�ն˽����޶
	
	unsigned char CL_bStatusCheck;			//�Ƿ�֧��qPBOC״̬���
	
	unsigned long CL_FloorLimit;			//�ǽӴ��ն�����޶�
	unsigned long CL_TransLimit;			//�ǽӴ��ն˽����޶�
	unsigned long CL_CVMLimit;				//�ǽӴ��ն�CVM��
	
	unsigned char TermQuali_byte2;			//���׽����ÿ��AID�޶���жϽ������ˢ��ǰ����ͨ���˱��������жϽ��
	unsigned char bOnlinePin;               //��AID�Ƿ�֧������PIN
	
	//���зǽӽ����¼�
	unsigned char CL_TermQuali_byte1;		//9f66�ĵ�һ���ֽ�
	unsigned char CL_CountryCode[2];		//���Ҵ��� ȱʡ0156
	unsigned char CL_TransCurrCode[2];		//���׻��Ҵ���, ȱʡ0156
	unsigned char CL_LimitForNoTicket[6];	//����ӡƾ�����޶�,���ڻ��������޶��ӡƾ��
}EMV_CLAPPLIST;


typedef struct _EMV_CAPK_{
    unsigned char RID[5];				//Ӧ��ע�������ID
    unsigned char KeyID;				//��Կ����
    unsigned char HashInd;				//HASH�㷨��־���Ƿ������test
    unsigned char ArithInd;				//RSA01/SM04�㷨��־
    unsigned char ModulLen;				//ģ����
    unsigned char Modul[248];			//ģ
    unsigned char ExponentLen;			//ָ������
    unsigned char Exponent[3];			//ָ��
    unsigned char ExpDate[3];			//��Ч��(YYMMDD)
    unsigned char CheckSum[20];			//��ԿУ���
}EMV_CAPK;

typedef struct _EMV_PARAM_{
	unsigned char MerchName[128];			//�̻�����ԭ����256�ֽڱ�Ϊ128�ֽ�
	unsigned long FloorLimit;				//����޶��ӦAID�����е�ͬ���ֶ�
	unsigned char bCheckFloorLimit;			//�Ƿ��������޶���
	unsigned char bSupCandFromAidList_CL;	//�ǽ��Ƿ�֧����AID�б�ķ�ʽ������ѡ�б�
	unsigned char IfSupportOnline;			//�Ƿ�֧������
	unsigned char IfSupportRFPBOC;			//�Ƿ�֧�ַǽ�PBOC
	unsigned char IfSupportContactMode;		//�Ƿ�֧�ֽӴ�ģʽ
	unsigned char IfRequireCVM;				//�Ƿ�Ҫ��CVM
	unsigned char IfSupportOnlinePIN;		//�Ƿ�֧������PIN
	unsigned char IfSupportSign;			//�Ƿ�֧��ǩ��
	unsigned char maxNumFashCardRec;		//���������¼��
	unsigned char FlashCardTimeout;			//��������ʱ��Ĭ��60
	unsigned char IfSupFlashCardHandle;		//�Ƿ�֧����������0-��֧�� 1-������������ 2-������������
	///////////add 20140910
	unsigned char IfSkipCardHolderVerify;   //�Ƿ������ֿ�����֤
	unsigned char pureECCSupportState;		//֧�ִ������ֽ𿨵�״̬,�����д������ֽ𿨽��׼����Ϊ0xff,
	///////////end
	unsigned char takePriorityForOrg;//���Ȳ����ĸ�����֯��AID, 0--��֧�֣�1-�������ȣ�����ֵδ����(ע:����δ�������Ա�����ų������ã����Թ��ڳ��������Ϊ1��ʾ��������)
	unsigned char indShowCardNoForOnlineQpboc;   //����Qpboc��ʾ���ŵȴ��û�ȷ�ϱ�־��b1=1:������ʾ����; b2=1:�ѻ���֤ʧ��ת������ʾ���š�
	unsigned char bSupCDCVM; //�Ƿ�֧��CDCVM����Ϊ1��ʾ֧��
	//����Ϊ�ǽӿ���ҵ�����
	unsigned char openQPSState; //0--��֧��QPS  1--����  2������ֵ--��������QPS
	//����ֵֻ������QPSЭ��
	unsigned char stageForQPS;
	unsigned char bOpenNoSign;  //�Ƿ�ͨ��ǩ
	unsigned char limitForQPS[6];
	unsigned char limitForNoSign[6];
	////////////////////////////////
	unsigned char currFlashTimeout;			//��ǰ�������̳�ʱʱ��(s)
	unsigned char bCheckCapkExp;			//�Ƿ��⹫Կ����
	unsigned char FlashCardTimeoutHigh;		//������ʱ(���ֽ�)
	unsigned char currFlashTimeoutHigh;		//��ǰ�������̳�ʱʱ��(���ֽ�s)
	////////////////////////////////////
	unsigned char reserv_1[89];
	unsigned char MerchCateCode[2];			//�̻������(ûҪ��ɲ�����)
	unsigned char MerchId[15];				//�̻���־(�̻���)
	unsigned char TermId[8];				//�ն˱�־(POS��)
	unsigned char TerminalType;				//�ն�����
	unsigned char Capability[3];			//�ն�����
	unsigned char ExCapability[5];			//�ն���չ����
	unsigned char TransCurrExp;				//���׻��Ҵ���ָ��
	unsigned char ReferCurrExp;				//�ο�����ָ��
	unsigned char ReferCurrCode[2];			//�ο����Ҵ���
	unsigned char CountryCode[2];			//�ն˹��Ҵ���
	unsigned char TransCurrCode[2];			//���׻��Ҵ���
	unsigned long ReferCurrCon;				//�ο����Ҵ���ͽ��״����ת��ϵ��(���׻��ҶԲο����ҵĻ���*1000)
	unsigned char TransType;				//��ǰ�������� 
	unsigned char ForceOnline;				//�̻�ǿ������(1 ��ʾ������������)
	unsigned char GetDataPIN;				//������ǰ�Ƿ�����Դ���
	unsigned char SupportPSESel;			//�Ƿ�֧��PSEѡ��ʽ
	unsigned char TermTransQuali[4];		//�ն˽�������
	unsigned char TermIsSupEct;				//�ն��Ƿ�֧�ֵ����ֽ���
	unsigned char ECTSI;					//�����ֽ��ն�֧��ָʾ��
	unsigned char bSurportSM;				//�Ƿ�֧�ֹ���
	unsigned char EC_bTermLimitCheck;	//�Ƿ�֧���ն˽����޶�
	unsigned long EC_TermLimit;			//�ն˽����޶
	unsigned char CL_bStatusCheck;		//�Ƿ�֧��qPBOC״̬���
	unsigned long CL_FloorLimit;		//�ǽӴ��ն�����޶�
	unsigned long CL_TransLimit;		//�ǽӴ��ն˽����޶�
	unsigned long CL_CVMLimit;			//�ǽӴ��ն�CVM�޶�

	//
	unsigned char TermVersion[2];		//Ӧ�ð汾
	unsigned char TermTargetPer;		//���ѡ��Ŀ��ٷ���
	unsigned char TermMaxTargetPer;		//ƫ�����ѡ������Ŀ��ٷ���
	unsigned long TermThreshold;		//ƫ�����ѡ����ֵ
	unsigned char AIDForECCOnly[16];	//�������ֽ�Ӧ�õ�aid
	unsigned char AidLenForECCOnly;		//AID�ĳ���
	char	      AcquierId[11+1];		//�յ���ID(��ʶ��),�ӱ�����18�ֽ���ȡ12�ֽڣ��11���ֽڣ����bcd����0��12λbcd��n6-11
	unsigned char bSupportQPBOCEx;		//�Ƿ�֧����չqpboc�Ĺ���
	unsigned char bSupportAccTypeSel;	//�Ƿ�֧���˻�����ѡ��
	unsigned char qpbocExMacKeyIdx;		//��Ϊ�տ��Ϊ��ҵӦ�õĹ�����Կ������
	unsigned char Reserve[4];			//��λ3���ֽ�
}EMV_PARAM;

typedef struct _tagRecNumForFlash
{
	unsigned char flashTm[7];
	unsigned char SFIForPan;
	unsigned char RecNumForPan;
	unsigned char SFIForTrack2;
	unsigned char RecNumForTrack2;
	unsigned char SFIForLastRec;
	unsigned char RecNumForLastRec;
	unsigned char SDASign;
	unsigned char atc[2]; //0x9f36
	unsigned char currCode[2];//save5F2A -->Rd0x9F51  or DF71
	unsigned char eccBal[6]; //dave9f5d or in 9f10-->rd 9f79 or DF79
	unsigned char authAmt[6];
	unsigned char panLen;
	unsigned char pan[10];
	unsigned char aidLen;
	unsigned char aid[16];
	unsigned char unused[2];
} TRecNumForFlash;

typedef struct tagEmvCbFuncs
{
	//int (*pcbfWaitAppSel)(int TryCnt, EMV_APPLIST *AppNameList, int AppNum);
	int (*pcbfWaitAppSel)(int TryCnt, EMV_CLAPPLIST *AppNameList, int AppNum);
	int (*pcbfGetUnknowTLV)(unsigned short Tag, unsigned char *dat, int len);
	int (*pcbfGetDateTime)(unsigned char *DateTime);
	void (*pcbIoCtrl)(unsigned char ioname,unsigned char *iovalue);
	int (*pcbfInputAmt)(unsigned char *AuthAmt, unsigned char *CashBackAmt);
	void (*pcbfAdviceProc)(void);
	int (*pcbfVerifyCert)(void);
	void (*pcbfVerifyPINOK)(void);
	int (*pcbfGetHolderPwd)(int iTryFlag, int iRemainCnt, unsigned char *pszPlainPin);
	int (*pcbfReferProc)(void);
	void  (*pcbfGetAllAmt)(unsigned char *PANData,int PANDataLen, unsigned char *AuthAmt, unsigned char *bcdTotalAmt);
	int (*pcbfDispCardNo)(void);
	int (*pcbfAppConfirmBeforeSelect)(unsigned char *Aid, int aidLen);
	int (*pcbfReadAndHandleQPbocExData)(unsigned long *amt, unsigned char *qpbocExType);
	int (*pcbfUpdateQPbocExData)(void);
	int (*pcbfAccountTypeSelect)(const char **accTypeList, int num, unsigned char *selItemNo);
	int (*pcbfGetIFDSerialNum)(unsigned char *ifdSN);	
	int (*pcbfGetEccSignAndAmt)(unsigned char *eccSign, unsigned char *tradeAmt, const unsigned char *eccTradeLimit);
	int (*pcbfHandleBeforeGPO)(void);
	int (*pcbCardInQPSBinList)(unsigned char stageForQPS);//���ӵ�
	int (*pcbSpecifyQPSHandle)(void);  //С�������ж�
	int (*pcbHandleAfterReadCardNo)(const char *cardNo);

	void (*pcbFlashResultProc)(TRecNumForFlash *pFlashRec, int state);//state = 0��ʾû�п�Ǯ
	
	//Ϊ��������emv�ӿڶ���
}TEmvCBFuncs;

extern TEmvCBFuncs 	g_ecbFuns;



// useful macro
#define _MIN(a, b)		( (a)<(b) ? (a) : (b) )
#define _MAX(a, b)		( (a)>(b) ? (a) : (b) )

// macros for analyze EMV TLV string
#define TAGMASK_CLASS		0xC0		// tag mask of tag class
#define TAGMASK_CONSTRUCTED	0x20		// tag mask of constructed/primitive data
#define TAGMASK_FIRSTBYTE	0x1F		// tag mask of first byte
#define TAGMASK_NEXTBYTE	0x80		// tag mask of next byte

#define LENMASK_NEXTBYTE	0x80		// length mask
#define LENMASK_LENBYTES	0x7F		// mask of bytes of lenght

#define TAG_NULL_1			0x00		// null tag
#define TAG_NULL_2			0xFF		// null tag


#define ICC_EMV				0			//emv����




#define ENGLISH				0
#define CHINESE				1

#define TYPE_CASH			0x01		//��������(�ֽ�)
#define TYPE_GOODS			0x02		//��������(����)
#define TYPE_SERVICE		0x04		//��������(����)
#define TYPE_CASHBACK		0x08		//��������(����)
#define TYPE_INQUIRY		0x10		//��������(��ѯ)
#define TYPE_PAYMENT		0x20		//��������(֧��)
#define TYPE_ADMINISTRATIVE	0x40		//��������(����)
#define TYPE_TRANSFER		0x80		//��������(ת��)

#define MAX_APP_NUM			32			//Ӧ���б����ɴ洢��Ӧ����
#define MAX_CAPK_NUM		64			//��֤��Կ�����ɴ洢�Ĺ�Կ��
#define MAX_CAPKREVOKE_NUM	96			//��֤��Կ�����б��������32*3

#define PART_MATCH			0x00		//ASI(����ƥ��)
#define FULL_MATCH			0x01		//ASI(��ȫƥ��)

#define EMV_GET_POSENTRYMODE			0 
#define EMV_GET_BATCHCAPTUREINFO		1 
#define EMV_GET_ADVICESUPPORTINFO		2 

//���״����������붨��
#define EMV_OK              0			//�ɹ�  
#define ERR_EMVRSP         (-2)			//���������
#define ERR_APPBLOCK       (-3)			//Ӧ������
#define ERR_NOAPP          (-4)			//��Ƭ��û��EMVӦ��
#define ERR_USERCANCEL     (-5)			//�û�ȡ����ǰ��������
#define ERR_TIMEOUT        (-6)			//�û�������ʱ
#define ERR_EMVDATA        (-7)			//��Ƭ���ݴ���
#define ERR_NOTACCEPT      (-8)			//���ײ�����
#define ERR_EMVDENIAL      (-9)			//���ױ��ܾ�
#define ERR_KEYEXP         (-10)		//��Կ����
#define ERR_NOPINPAD       (-11)		//û��������̻���̲�����
#define ERR_NOPIN          (-12)		//û��������û���������������
#define ERR_CAPKCHECKSUM   (-13)		//��֤������ԿУ��ʹ���
#define ERR_NOTFOUND       (-14)		//û���ҵ�ָ�������ݻ�Ԫ��
#define ERR_NODATA         (-15)		//ָ��������Ԫ��û������
#define ERR_OVERFLOW       (-16)		//�ڴ����
#define ERR_NOTRANSLOG     (-17)		//�޽�����־
#define ERR_NORECORD       (-18)		//�޼�¼
#define ERR_NOLOGITEM      (-19)		//Ŀ־��Ŀ����
#define ERR_ICCRESET       (-20)		//IC����λʧ��
#define ERR_ICCCMD         (-21)		//IC����ʧ��
#define ERR_ICCBLOCK       (-22)		//IC������ 
#define ERR_ICCNORECORD    (-23)		//IC���޼�¼
#define ERR_GENAC1_6985    (-24)		//GEN AC�����6985
#define ERR_USECONTACT     (-25)		//�ǽ�ʧ�ܣ����ýӴ�����
#define ERR_APPEXP         (-26)		//qPBOC��Ӧ�ù���
#define ERR_BLACKLIST      (-27)		//qPBOC��������
#define ERR_GPORSP         (-28)		//err from GPO
#define ERR_TRANSEXCEEDED		(-30)	//�ǽӽ��׳���
#define ERR_QPBOCFDDAFAIL		(-31)
///////////////140910����
#define ERR_UNSUPPORTED			(-32)	//��֧��
#define ERR_NOFILE				(-33)	//û���ļ�
#define ERR_DENIALFORECC		(-34)	//�ܾ��������ֽ𿨵���������
#define ERR_RMAC				(-35)	//��ȫ����macУ���
#define ERR_RFNOTAG9F66			(-36)	//�ǽӵ�PDOL��û��9f66
#define ERR_MACCHECK			(-37)
#define ERR_MEMERR				(-38)	//6581 �ڴ�ʧ��
#define ERR_LENERR				(-39)	//6700 ���ȴ���
#define ERR_CONDNOTSATISFIED	(-40)	//6985 ����������
#define ERR_CMDNOEXIST			(-41)	//6d00 �������
#define ERR_CMDNOTSUPPORT		(-42)	// 6e00 �������Ͳ�֧��
#define ERR_TCUNAVAILABLE		(-43)	//9406 ����TC������
#define ERR_READ_LAST_REC		-44		//�����һ����¼ʧ��
#define ERR_ECBALANCE_SHORT		-45		//�������ֽ�����
#define ERR_FLASHED_CARD		(-46)	//��ȡ���һ����¼�������뵱��������������
#define ERR_CURRFLASH_TIMEOUT	(-47)	//��ǰ�������̳�ʱ
#define ERR_USEDFLASHED_CARD	(-48)	//��ʾʹ�õ�ǰ�����������Ŀ�Ƭ
#define ERR_ALLFLASH_TIMEOUT	(-49)   //ȫ��������ʱ����ʱӦ�ó���Ӧ�õ��û�ȡ��ʱ��������¼
#define ERR_FLASH_READCARD		(-50)   //���������ж���ʧ��
#define ERR_EMVREADFILE			(-51)	//emv���ж��ļ�ʧ��
#define ERR_EMVWRITEFILE		(-52)	//emv��д�ļ�ʧ��
#define ERR_EMVFAIL				(-53)	//emv����ʧ��
#define ERR_EXCEEDED_CLFLOORLMT			-54  //�����ǽ��ѻ��޶�
#define ERR_UNIMPL_CB 					-55  //δʵ�ֵĻص�



#define REFER_APPROVE		0x01		//�ο�������(ѡ����׼)
#define REFER_DENIAL		0x02		//�ο�������(ѡ��ܾ�)
#define ONLINE_APPROVE		0x00		//����������(������׼)     
#define ONLINE_FAILED		0x01		//����������(����ʧ��) 
#define ONLINE_REFER		0x02		//����������(�����ο�)
#define ONLINE_DENIAL		0x03		//����������(�����ܾ�)
#define ONLINE_ABORT		0x04		//����PBOC(������ֹ)
#define ONLINE_REFERANDFAIL 0x05		//�����ܾ��������ο�


#define PATH_PBOC			0x00		//Ӧ��·��:��׼PBOC
#define PATH_QPBOC			0x01		//Ӧ��·��:qPBOC
#define PATH_MSD			0x02		//Ӧ��·��:MSD
#define PATH_ECash			0x03		//Ӧ��·��:�����ֽ�







EMV_CLAPPLIST *GetCurrSelectedApp(void);
int EmvUpFlashClearCurrent_Api(void);
int EmvUpFlashGetFailRecForUpload_Api(unsigned char *pBuf);
int EmvCheckQpbocFlashState_Api(void);

//������һЩ���Եĺ�
#define TESTCASE_QPBOC_SIGN_MASK	0xFC00
#define TESTCASE_QPBOC_SIGN_NOFLASH	0x4000
#define TESTCASE_QPBOC_SIGN_ONCE		0x8000

#define TESTCASE_QPBOC_READLASTREC_FAIL    1  //qpboc�����һ����¼ʧ��
#define TESTCASE_QPBOC_READ_PAN_FAIL			0x4  //���������ж����˺�ʧ��
#define TESTCASE_QPBOC_READ_ATC_FAIL			0x5   ////���������ж�ATC��ʧ��
void SetTestCaseCode(unsigned short caseCode);

//���ص�ǰ������״̬
typedef enum tagUPFlashState
{
	UPFLASHSTATE_NONE = 0,                       //����״̬
	UPFLASHSTATE_IN_CURRENT = 1,          //��ǰ����������
	UPFLASHSTATE_TMOUT_CURRENT =  2, //��ǰ�������̳�ʱ
	UPFLASHSTATE_TMOUT_REC =  3     //�м�¼��ʱ��Ҫ������
} TUPFlashState;

#if 0

//emvЭ��ջ��ʼ��
int EmvInit_Api(void);


//
void EmvClear_Api(void);

void EmvSetTradeAmt_Api(const unsigned char *bcdConsumeAmt, const unsigned char *bcdCashbackAmt);


//�ǽ�Ԥ������
int EmvCLPreProcess_Api(int qpbocTradeChannel, int otherTradeChannel);
//
int EmvAppSel_Api(int Slot, unsigned long TransNo);
//
int EmvReadAppData_Api(void);
//
int EmvCardAuth_Api(void);
///
int EmvProcTrans_Api(unsigned char *bcdConsumeMoney, unsigned char *bcdCashBackMoney, unsigned char *bIfGoOnline);
//
int EmvProcCLTrans_Api(unsigned char *pbGoOnline);
//
int EmvProcTransComplete_Api(unsigned char ucResult, unsigned char *RspCode, 
										 unsigned char *AuthCode, int AuthCodeLen, 
										 unsigned char *IAuthData, int IAuthDataLen, 
										 unsigned char *script, int ScriptLen);

//
unsigned char EmvGetPath_Api(void);
//
int EmvGetScriptResult_Api(unsigned char *Result, int *RetLen);
//
BOOL EmvIsMSMode_Api(void);
//
int EmvGetMSData_Api(char * track1, char *track2);
//
int  EmvGetBalance_Api(unsigned char* BcdBalance);
//
int EmvReadELoadLogRecord_Api(int RecordNo);
//
int EmvGetELoadLogItem_Api(unsigned short Tag, unsigned char *TagData, int *TagLen);
//
int EmvReadLogRecord_Api(int RecordNo);
//
int EmvGetLogItem_Api(unsigned short Tag, unsigned char *TagData, int *TagLen);

//
BOOL EmvNeedSignature_Api(void);
//
BOOL EmvNeedOnlinePin_Api(void);
//
void EmvGetParam_Api(EMV_PARAM *Param);
//
void EmvSetParam_Api(EMV_PARAM *Param);
//
void EmvSaveParam_Api(EMV_PARAM *Param);
//
int EmvSetTLV_Api(unsigned short Tag, unsigned char *Data, int len);
//
int EmvGetTLV_Api(unsigned short Tag, unsigned char *DataOut, int *OutLen);
//
int EmvAddCapk_Api(EMV_CAPK  *capk);
//
int  EmvGetCapk_Api(int Index, EMV_CAPK  *capk);
//
int EmvSearchCapk_Api(EMV_CAPK  *pCapk, const unsigned char *rid, unsigned char keyID);
//
int EmvDelCapk_Api(unsigned char KeyID, unsigned char *RID);
//
void EmvClearCapk_Api(void);
//
int EmvAddApp_Api(EMV_APPLIST *App);
//
void EmvClearApp_Api(void);
//
int EmvGetApp_Api(int Index, EMV_APPLIST *App);
//
int EmvDelApp_Api(unsigned char *AID, int AidLen);
//
int EmvAddCLApp_Api(EMV_CLAPPLIST *App);
//
int EmvDelCLApp_Api(unsigned char *AID, int AidLen);
//
int EmvGetCLApp_Api(int Index, EMV_CLAPPLIST *App);
//
int EmvSetIcCardType_Api(int Mode);
//
int EmvGetIcCardType_Api(void);
//
int EmvSaveLog_Api(char *FileName,int SaveNum);

//
int EmvAddBlackList_Api(const char *cardNo);
//
int EmvDelBlackList_Api(const char *cardNo);
//
void EmvClearBlacklist_Api(void);
//
int EmvGetEmvReleaseVer_Api(char *VerOut);

#endif

//�ǹ����ĺ���
int EmvSelectApp(unsigned long TransNo, int ReadLogFlag, int *pTryCnt);
//
int EmvInitApp(void);
//
void EMVProcRestric(void);
//
int EMVHolderVerify(void);
//
int EMVRiskManagement(void);
//
int EMVTermActAnalys(unsigned char *bIfGoOnline);

int IccCmd_GetData(unsigned char p2, unsigned char *DataOut, int *OutLen) ;
//
int IccCmd_GetDataEx(unsigned short tag, unsigned char *DataOut, int *OutLen) ; 


#endif

