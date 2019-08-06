#ifndef __PAYPASS_RRP__
#define __PAYPASS_RRP__

#include "define.h"
#include "pub/pub.h"

//RRPָ�ƬӦ������
typedef struct 
{
	uchar ucRRP_Entropy[4];
	uchar ucRRP_MinTimeAPDU[2];
	uchar ucRRP_MaxTimeAPDU[2];
	uchar ucRRP_EstimatedTimeRADDU[2];
}RRP_RESP_DATA;

int paypass_rrp_proc(char *pUnNumber,RRP_RESP_DATA *pRespData,int *piTakenTime);

#endif

