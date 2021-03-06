#include "sdk_print.h"
#include "pub/osl/inc/osl_print.h"
#include "pub/osl/inc/osl_filedef.h"
#include "pub\tracedef.h"


const char  raw[] ={
	0X42, 0X4D, 0X1E, 0X11, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X3E, 0X00, 0X00, 0X00, 0X28, 0X00, 
	0X00, 0X00, 0XB4, 0X00, 0X00, 0X00, 0XB4, 0X00, 0X00, 0X00, 0X01, 0X00, 0X01, 0X00, 0X00, 0X00, 
	0X00, 0X00, 0XE0, 0X10, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 
	0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0XFF, 0XFF, 0XFF, 0X00, 0X00, 0X00, 
	0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 
	0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 
	0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 
	0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 
	0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X90, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 
	0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X03, 0XFC, 
	0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 
	0X00, 0X08, 0X12, 0X20, 0X00, 0X00, 0X01, 0X98, 0X02, 0X00, 0XC2, 0X41, 0X02, 0X82, 0X28, 0X00, 
	0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X01, 0X00, 0X00, 0X00, 0X00, 0X03, 0X58, 
	0X90, 0XAA, 0X00, 0XA8, 0X62, 0X28, 0X92, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 
	0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X01, 0XAC, 0X6D, 0X80, 0XC2, 0X06, 0X20, 0X44, 0X20, 0X00, 
	0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X03, 0XDC, 
	0X20, 0X82, 0X04, 0X04, 0X00, 0X04, 0X20, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 
	0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X01, 0XA8, 0X2A, 0XAC, 0X84, 0XDA, 0X52, 0XBA, 0X9A, 0X00, 
	0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X04, 0X80, 0X00, 0X00, 0X03, 0X98, 
	0X00, 0X00, 0X00, 0X80, 0X40, 0X20, 0X40, 0X00, 0X2A, 0X9A, 0X69, 0XA6, 0X69, 0XA6, 0X69, 0XA6, 
	0X69, 0XA6, 0X9E, 0XEA, 0XA0, 0X00, 0X01, 0XFC, 0X08, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 
	0X7F, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0X01, 0X68, 
	0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X3F, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 
	0X3F, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0X00, 0X00, 
	0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X3F, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 
	0X7F, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFB, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFB, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XEF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XCF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X9F, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XBF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFE, 0XBF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFC, 0X7F, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFC, 0X7F, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF9, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFA, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF1, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XE9, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XE3, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XE3, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X9B, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X87, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X97, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X8F, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X97, 0XFF, 
	0XFF, 0XFF, 0XDF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X07, 0XFF, 0XFF, 0XF8, 0X00, 0XBF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFE, 0XAF, 0XFF, 
	0XFF, 0X80, 0X00, 0X07, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X6F, 0XFF, 0XFF, 0X00, 0X00, 0X03, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFE, 0X0F, 0XFF, 
	0XF8, 0X00, 0X00, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFE, 0X5F, 0XFF, 0XF8, 0X00, 0X00, 0X00, 0X3F, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFE, 0X1F, 0XFF, 
	0XE0, 0X00, 0X00, 0X00, 0X1F, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFE, 0XCF, 0XFF, 0XC0, 0X00, 0X00, 0X00, 0X0F, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFD, 0X1F, 0XFF, 
	0X80, 0X00, 0X00, 0X00, 0X07, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFC, 0X1F, 0XFF, 0X00, 0X01, 0XFC, 0X00, 0X03, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFE, 0XAF, 0XFE, 
	0X00, 0X1F, 0XFF, 0XC0, 0X01, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFC, 0X1F, 0XFC, 0X00, 0X7F, 0XFF, 0XF8, 0X00, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFD, 0X5F, 0XF8, 
	0X01, 0XFF, 0XFF, 0XFE, 0X00, 0X7F, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFC, 0X0F, 0XF8, 0X07, 0XFF, 0XFF, 0XFF, 0X00, 0X7F, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFE, 0XAF, 0XF8, 
	0X0F, 0XFF, 0XFF, 0XFF, 0XC0, 0X3F, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFC, 0X8F, 0XE0, 0X1E, 0X03, 0XFF, 0XFF, 0XE0, 0X1F, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XE7, 0XFE, 0X3F, 0XE0, 
	0X7C, 0X00, 0XFF, 0XFF, 0XF8, 0X1F, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFD, 0X0F, 0XE0, 0XF0, 0X00, 0X7F, 0XFF, 0XF8, 0X0F, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XEF, 0XFC, 0X6F, 0XC1, 
	0XF0, 0X00, 0X3F, 0XFD, 0XFC, 0X0F, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XEF, 0XFE, 0X2F, 0XC1, 0XE0, 0X00, 0X1F, 0XFD, 0XFE, 0X07, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF7, 0XFC, 0X87, 0X87, 
	0XC0, 0X00, 0X1F, 0XFC, 0XFE, 0X07, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF7, 0XFC, 0X27, 0X87, 0XC0, 0X00, 0X0F, 0XFD, 0XFF, 0X83, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XE7, 0XFF, 0XA7, 0X0F, 
	0XC0, 0X00, 0X4F, 0XF9, 0X7F, 0X83, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF7, 0XFE, 0X0F, 0X0F, 0X80, 0X00, 0X0F, 0XFC, 0XFF, 0X83, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF3, 0XFE, 0X62, 0X1F, 
	0X80, 0X00, 0X07, 0XF9, 0X3F, 0XC3, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF3, 0XFE, 0X0B, 0X3F, 0X80, 0X00, 0X27, 0XF1, 0X7F, 0XE1, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF3, 0XFF, 0X62, 0X3F, 
	0X80, 0X00, 0X27, 0XF2, 0X9F, 0XF1, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF1, 0XFF, 0X02, 0X7F, 0X80, 0X00, 0X27, 0XF1, 0X3F, 0XF0, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF3, 0XFF, 0XB8, 0X7F, 
	0X80, 0X00, 0X27, 0XE2, 0XAF, 0XF1, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF8, 0XFF, 0X44, 0X7F, 0X80, 0X00, 0X27, 0XE3, 0X9F, 0XF8, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0XFF, 0X10, 0XFF, 
	0X80, 0X00, 0X67, 0XD4, 0X2F, 0XF8, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF8, 0X7F, 0XA0, 0XFF, 0X80, 0X00, 0X47, 0XED, 0X9F, 0XFC, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFC, 0X7F, 0XE9, 0XFF, 
	0X80, 0X00, 0XCF, 0X84, 0X67, 0XFC, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFC, 0X7F, 0XC1, 0XFF, 0XC0, 0X01, 0XCF, 0X8D, 0X97, 0XFC, 0X7F, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFC, 0X3F, 0XC9, 0XFF, 
	0XC0, 0X01, 0X9F, 0X8E, 0X2F, 0XFC, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFE, 0X1F, 0XE9, 0XFF, 0XE0, 0X03, 0X1F, 0X1F, 0XAB, 0XFE, 0X7F, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFC, 0X4F, 0XF3, 0XFF, 
	0XE3, 0XAE, 0X3E, 0X1F, 0X4F, 0XFE, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFE, 0X1F, 0XF3, 0XFF, 0XF0, 0XFC, 0X3E, 0X1E, 0X53, 0XFE, 0X7F, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X07, 0XFB, 0XFF, 
	0XF8, 0X00, 0XF8, 0X3F, 0XA7, 0XFE, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X03, 0XFB, 0XFF, 0XFE, 0X01, 0XF9, 0X3F, 0X57, 0XFE, 0X7F, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X81, 0XFF, 0XFF, 
	0XFF, 0X87, 0XF0, 0X7F, 0X27, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X80, 0XFF, 0XFF, 0XFF, 0XFF, 0XE0, 0X7F, 0XAB, 0XFE, 0X7F, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XC4, 0X7F, 0XFF, 
	0XFF, 0XFF, 0X84, 0XFF, 0X57, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XC8, 0X3F, 0XFF, 0XFF, 0XFF, 0X91, 0XFF, 0XA9, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XE2, 0X1F, 0XFF, 
	0XFF, 0XFE, 0X01, 0XFF, 0X97, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X47, 0XFF, 0XFF, 0XFA, 0X05, 0XFF, 0X6B, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF4, 0X01, 0XFF, 
	0XFF, 0XE0, 0X07, 0XFF, 0X97, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF8, 0X20, 0X7F, 0XFF, 0XC1, 0X07, 0XFF, 0XC7, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFC, 0X08, 0X06, 
	0X78, 0X00, 0X1F, 0XFF, 0X97, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X02, 0X02, 0X02, 0X04, 0X1F, 0XFF, 0X27, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X40, 0X80, 
	0X10, 0X11, 0X7F, 0XFF, 0XD7, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X84, 0X28, 0X08, 0X60, 0XFF, 0XFF, 0X8B, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XE0, 0X02, 
	0X80, 0X01, 0XFF, 0XFF, 0X6F, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0X12, 0X03, 0XFF, 0XFF, 0XD7, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFD, 0X08, 
	0X00, 0X1F, 0XFF, 0XFF, 0X2F, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XA0, 0X00, 0X7F, 0XFF, 0XFF, 0X2F, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XE4, 
	0X93, 0XFF, 0XFF, 0XFE, 0XDF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X6F, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFE, 0X9F, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFE, 0X1F, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFE, 0X7F, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFD, 0X7F, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFE, 0XBF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFE, 0X7F, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XF9, 0X7F, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFA, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XF5, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFB, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XF1, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XEF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XE7, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XCF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XBF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0X7F, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFE, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFE, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 
	0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XF0, 0X00, 

};


void creat_bmp()
{
	int fp;
	fp = mf_file_open("data\\test.bmp", FILE_CREAT_FLAG, FILE_WRITE_MODE);
	mf_file_write(fp, raw, sizeof(raw));
	mf_file_close(fp);
}

void sdk_print()
{
	int ret ; 

	creat_bmp();
	// Prompt is printing
	xgui_BeginBatchPaint();			
	xgui_ClearDC();
	xgui_TextOut_Win_Center("printing...");
	xgui_EndBatchPaint();


	osl_print_add(osl_print_align(0));						// Set left alignment
	osl_print_add(osl_print_cn_font_size(1));				// Set Chinese 16 dot matrix font
	osl_print_add(osl_print_cn_font_zoom(1 ,2));			// Set Chinese magnification
	osl_print_add("test1");									// Set the print content


	osl_print_add(osl_print_align(1));						// Set center alignment
	osl_print_add(osl_print_cn_font_size(1));				// Set English font
	osl_print_add(osl_print_cn_font_zoom(1 ,2));			// Set English magnification
	osl_print_add("test1");									// Set the print content

	osl_print_add(osl_print_align(1));						// Set center alignment
	osl_print_add(osl_print_img("data\\test.bmp"));			// Set bmp file printing
	osl_print_add(osl_print_row_space(100));				// Set the paper to go 100 points
	ret = osl_print_write(osl_print_get());					// Output to printer
	APP_TRACE( "osl_print_write: %d", ret );
	if(ret == -1)
	{
		xgui_messagebox_show( "Print" , "No paper" , "" , "confirm" , 0);
	}         
	osl_print_free();										// Release print buffer
}

