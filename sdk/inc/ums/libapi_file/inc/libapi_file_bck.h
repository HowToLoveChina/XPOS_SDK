#ifndef __LIBAPI_FILE_HEADER__
#define __LIBAPI_FILE_HEADER__


#include "def.h"

/*************************************************************************************
��    Ȩ������ħ�����ӿƼ����޹�˾
��	 �ߣ�yangjy
��    �ܣ�2.2.9.3	��ȡ�ļ���ģ��汾��(UFile_GetModuleVer)
�����������
���������pszVer   ģ��汾��
��    �أ��ɹ�����ģ��汾�ų���
		UFILE_FAIL   =-1,           //ʧ��
��	 ע: ��
*************************************************************************************/
int UFile_GetModuleVer(char *pszVer);

/*************************************************************************************
��    Ȩ������ħ�����ӿƼ����޹�˾
��	 �ߣ�yangjy
��    �ܣ�2.2.9.4	����ļ��Ƿ���ڣ�UFile_Check��
���������FileName���ļ���, ��NULL�������16���ֽ�
		iFileLocation: �洢λ�ã��μ�enum FILELOCATION
�����������
��    �أ�UFILE_NO_EXIST       = -12,             //ָ�����ļ�������
		UFILE_PARAERROR      = -11��            //������
		UFILE_SUCCESS        =  0               //�ļ������ɹ�
��	 ע: ��
*************************************************************************************/
int UFile_Check(cchar *FileName, int iFileLocation);

/*************************************************************************************
��    Ȩ������ħ�����ӿƼ����޹�˾
��	 �ߣ�yangjy
��    �ܣ�2.2.9.5	�ļ���/������UFile_OpenCreate��
���������FileName�����ļ���, ��NULL�������16���ֽ�
		iFileLocation: �洢λ�ã��μ�enum FILELOCATION
		Flag�����ļ���ʽ, ȡֵ�ο�FileFlags����
		RecSize���ļ���¼��С������ר�ã�
		RecSize = 0,������ ��ʽ�ļ����ı��ļ�
		RecSize = 1�������� �Ƕ�����¼��TLV���ļ�
		8<=RecSize<=4090 �����򿪶�����¼�ļ�
���������Fh���ļ����
��    �أ�UFILE_NO_EXIST       = -12,             //ָ�����ļ�������
		UFILE_PARAERROR      = -11��            //������
		UFILE_OPEN_FAIL  	= -2,              //�򿪴���
		UFILE_FAIL			= -1,              //�ļ�����ʧ��
		UFILE_SUCCESS        =  0               //�ļ������ɹ�
��	 ע: �����´������ļ�RecSize�������ã�
		���ڴ��Ѵ������ļ���Ӧ����RecSize������
*************************************************************************************/
int UFile_OpenCreate(cchar *FileName, int iFileLocation, int Flag, FILE_HANDLE *fh, int RecSize);

/*************************************************************************************
��    Ȩ������ħ�����ӿƼ����޹�˾
��	 �ߣ�yangjy
��    �ܣ�2.2.9.6	�ļ���ȡ��UFile_Read��
���������handle����ȡ���ļ����
		size����ȡ�����ݴ�С
���������buffer����������
��    �أ��ļ���ȡ�ɹ�������ֵ����ʵ�ʶ�ȡ�����ֽ���
		UFILE_PARAERROR      = -11��            //������
		UFILE_READ_FAIL		= -5,              //������
		UFILE_FAIL			= -1,              //�ļ�����ʧ��
��	 ע: ��
*************************************************************************************/
int UFile_Read(FILE_HANDLE handle, char *buffer, int size);

/*************************************************************************************
��    Ȩ������ħ�����ӿƼ����޹�˾
��	 �ߣ�yangjy
��    �ܣ�2.2.9.7	�ļ�д�루UFile_Write��
���������handle����ȡ���ļ����
		size����д������ݴ�С
		buffer����д�������
�����������
��    �أ��ļ�д��ɹ�������ֵ����ʵ��д����ֽ���
		UFILE_PARAERROR      = -11��            //������
		UFILE_WRITE_FAIL		= -4,              //д����
		UFILE_FAIL			= -1,              //�ļ�����ʧ��
��	 ע: ��
*************************************************************************************/
int UFile_Write(FILE_HANDLE handle, char *buffer, int size);

/*************************************************************************************
��    Ȩ������ħ�����ӿƼ����޹�˾
��	 �ߣ�yangjy
��    �ܣ�2.2.9.8	��λ�ļ�ָ�루UFile_Lseek��
���������handle���ļ����
		offset��ƫ����
		origin����ʼλ�ã��ο�FileSeekFlags����
�����������
��    �أ�UFILE_PARAERROR      = -11��            //������
		UFILE_SEEK_FAIL	   = -6,              //��λ�ļ�ָ�����
		UFILE_SUCCESS        =  0
��	 ע: ��
*************************************************************************************/
long UFile_Lseek(FILE_HANDLE handle, long offset, int origin);

/*************************************************************************************
��    Ȩ������ħ�����ӿƼ����޹�˾
��	 �ߣ�yangjy
��    �ܣ�2.2.9.9	ɾ���ļ���¼��UFile_Delete��
���������handle���ļ����
		size��ɾ�����ļ��ֽ���
�����������
��    �أ�UFILE_PARAERROR      = -11��            //������
		UFILE_DELETE_FAIL	= -7,              //ɾ���ļ���¼����
		UFILE_SUCCESS        =  0    
��	 ע: ɾ���ľ���λ����File_Lseek()��������
*************************************************************************************/
int UFile_Delete(FILE_HANDLE handle, uint size);

/*************************************************************************************
��    Ȩ������ħ�����ӿƼ����޹�˾
��	 �ߣ�yangjy
��    �ܣ�2.2.9.10	�ر��ļ���UFile_Close��
���������andle���ļ����
�����������
��    �أ�UFILE_PARAERROR      = -11��            //������
		UFILE_CLOSE_FAIL		= -8,              //�ر��ļ�����
		UFILE_FAIL			= -1,              //�ļ�����ʧ��
		UFILE_SUCCESS        =  0              //�ļ������ɹ�
��	 ע: ��
*************************************************************************************/
int UFile_Close(FILE_HANDLE handle);

/*************************************************************************************
��    Ȩ������ħ�����ӿƼ����޹�˾
��	 �ߣ�yangjy
��    �ܣ�2.2.9.11	ɾ���ļ���UFile_Remove��
���������fileName���ļ���, ��NULL�������16���ֽ�
		iFileLocation: �洢λ�ã��μ�enum FILELOCATION
�����������
��    �أ�UFILE_NO_EXIST       = -12,             //ָ�����ļ�������
		UFILE_PARAERROR      = -11��            //������
		UFILE_FAIL			= -1,              //�ļ�����ʧ��
		UFILE_SUCCESS        =  0              //�ļ������ɹ�
��	 ע: ��
*************************************************************************************/
int UFile_Remove(cchar *filename, int iFileLocation);

/*************************************************************************************
��    Ȩ������ħ�����ӿƼ����޹�˾
��	 �ߣ�yangjy
��    �ܣ�2.2.9.12	�������ļ���UFile_Rename��
���������oldname�����ļ���
		iFileLocation: �洢λ�ã��μ�enum FILELOCATION
		newname�����ļ���
�����������
��    �أ�UFILE_NO_EXIST       = -12,             //ָ�����ļ�������
		UFILE_PARAERROR      = -11��            //������
		UFILE_FAIL			= -1,              //�ļ�����ʧ��
		UFILE_SUCCESS        =  0              //�ļ������ɹ�
��	 ע: ��
*************************************************************************************/
int UFile_Rename(cchar *oldname, int iFileLocation, cchar *newname);

/*************************************************************************************
��    Ȩ������ħ�����ӿƼ����޹�˾
��	 �ߣ�yangjy
��    �ܣ�2.2.9.13	����ļ���UFile_Clear��
���������FileName���ļ���, ��NULL�������16���ֽ�
		iFileLocation: �洢λ�ã��μ�enum FILELOCATION
�����������
��    �أ�UFILE_NO_EXIST       = -12,             //ָ�����ļ�������
		UFILE_PARAERROR      = -11��            //������
		UFILE_FAIL			= -1,              //�ļ�����ʧ��
		UFILE_SUCCESS        =  0              //�ļ������ɹ�
��	 ע: ��
*************************************************************************************/
int UFile_Clear(cchar *FileName, int iFileLocation);

/*************************************************************************************
��    Ȩ������ħ�����ӿƼ����޹�˾
��	 �ߣ�yangjy
��    �ܣ�2.2.9.14	ȡ�ļ�ϵͳʣ��ռ䣨UFile_GetFreeSpace��
���������drive������������("I:"��"F:")
		�������������Ӧ���Դ˲���
�����������
��    �أ��ɹ�������ʣ��ռ䵥λK
		ʧ�ܣ�UFILE_FAIL			= -1,              //�ļ�����ʧ��
��	 ע: ��
*************************************************************************************/
long UFile_GetFreeSpace(cchar *drive);

/*************************************************************************************
��    Ȩ������ħ�����ӿƼ����޹�˾
��	 �ߣ�yangjy
��    �ܣ�2.2.9.15	ȡ�ļ���¼������UFile_GetNumberOfRecords��
���������FileName���ļ�����
		iFileLocation: �洢λ�ã��μ�enum FILELOCATION
		Record_Len��������¼����
�����������
��    �أ��ɹ������ؼ�¼����
		ʧ�ܣ�UFILE_PARAERROR      = -11��            //������
		UFILE_FAIL			= -1,              //�ļ�����ʧ��
��	 ע: ��
*************************************************************************************/
int UFile_GetNumberOfRecords(cchar *FileName, int iFileLocation, int Record_Len);

/*************************************************************************************
��    Ȩ������ħ�����ӿƼ����޹�˾
��	 �ߣ�yangjy
��    �ܣ�2.2.9.16	׷���ļ���¼��UFile_AppendRecord��
���������FileName���ļ���, ��NULL�������16���ֽ�
		iFileLocation: �洢λ�ã��μ�enum FILELOCATION
		Record����¼����
		Record_Len����¼���ݵĳ���
�����������
��    �أ�UFILE_PARAERROR      = -11��            //������
		UFILE_FAIL			= -1,              //�ļ�����ʧ��
		UFILE_SUCCESS        =  0              //�ļ������ɹ�
��	 ע: ���籣��
���ļ�ĩβ�����һ��������¼�ļ������ļ�������ʱ���Զ��������ļ�
*************************************************************************************/
int UFile_AppendRecord(cchar *FileName, int iFileLocation, char *Record, int Record_Len);

/*************************************************************************************
��    Ȩ������ħ�����ӿƼ����޹�˾
��	 �ߣ�yangjy
��    �ܣ�2.2.9.17	���������Ų�ѯ��¼��UFile_GetRecordByIndex��
���������FileName���ļ�����
		iFileLocation: �洢λ�ã��μ�enum FILELOCATION
		Record_Len����¼����
		Record_Index ����¼����(��0��ʼ)
���������Record����¼����
��    �أ�UFILE_NO_EXIST       = -12,             //ָ�����ļ�������
		UFILE_PARAERROR      = -11��            //������
		UFILE_NO_RECORD		= -10,             //��¼δ�ҵ�
		UFILE_READ_FAIL		= -5,              //������
		UFILE_OPEN_FAIL  	= -2,              //�򿪴���
		UFILE_FAIL			= -1,              //�ļ�����ʧ��
		UFILE_SUCCESS        =  0              //�ļ������ɹ�
��	 ע: ��
*************************************************************************************/
int UFile_GetRecordByIndex(cchar *FileName, int iFileLocation, void *Record, int Record_Len, int Record_Index);

/*************************************************************************************
��    Ȩ������ħ�����ӿƼ����޹�˾
��	 �ߣ�yangjy
��    �ܣ�2.2.9.18	��ѯ��¼��UFile_GetRecord��
���������FileName���ļ�����
		iFileLocation: �洢λ�ã��μ�enum FILELOCATION
		Record_Len����¼����
		Condtion����ѯ�������ο�DBSearCond�ṹ
���������Record����¼����
��    �أ�UFILE_NO_EXIST       = -12,             //ָ�����ļ�������
		UFILE_PARAERROR      = -11��            //������
		UFILE_NO_RECORD		= -10,             //��¼δ�ҵ�
		UFILE_READ_FAIL		= -5,              //������
		UFILE_OPEN_FAIL  	= -2,              //�򿪴���
		UFILE_FAIL			= -1,              //�ļ�����ʧ��
		UFILE_SUCCESS        =  0              //�ļ������ɹ�
��	 ע: ��
*************************************************************************************/
int UFile_GetRecord(cchar *FileName, int iFileLocation, void *Record, int Record_Len, DBSEARCOND *Condtion);

/*************************************************************************************
��    Ȩ������ħ�����ӿƼ����޹�˾
��	 �ߣ�yangjy
��    �ܣ�2.2.9.19	���¼�¼��UFile_UpdateRecord��ͨ��������������һ����¼
���������FileName���ļ�����
		iFileLocation: �洢λ�ã��μ�enum FILELOCATION
		Record����¼����
		Record_Len����¼����
		Condtion����ѯ�������ο�DBSearCond�ṹ
���������Record����¼����
��    �أ�UFILE_NO_EXIST       = -12,             //ָ�����ļ�������
		UFILE_PARAERROR      = -11��            //������
		UFILE_NO_RECORD		= -10,             //��¼δ�ҵ�
		UFILE_READ_FAIL		= -5,              //������
		UFILE_WRITE_FAIL		= -4,              //д����
		UFILE_OPEN_FAIL  	= -2,              //�򿪴���
		UFILE_FAIL			= -1,              //�ļ�����ʧ��
		UFILE_SUCCESS        =  0              //�ļ������ɹ�
��	 ע: ���籣��,Record�������Ҳ�ǳ��Ρ������ɹ�������£�Record�����������䡣
*************************************************************************************/
int UFile_UpdateRecord(cchar *FileName, int iFileLocation, void *Record, int Record_Len, DBSEARCOND *Condtion);

/*************************************************************************************
��    Ȩ������ħ�����ӿƼ����޹�˾
��	 �ߣ�yangjy
��    �ܣ�2.2.9.20	���������Ÿ��¼�¼��UFile_UpdateRecordByIndex��
���������FileName���ļ�����
		iFileLocation: �洢λ�ã��μ�enum FILELOCATION
		Record����¼����
		Record_Len����¼����
		Index�� ��¼������
���������Record����¼����
��    �أ�UFILE_NO_EXIST       = -12,             //ָ�����ļ�������
		UFILE_PARAERROR      = -11��            //������
		UFILE_NO_RECORD		= -10,             //��¼δ�ҵ�
		UFILE_READ_FAIL		= -5,              //������
		UFILE_WRITE_FAIL		= -4,              //д����
		UFILE_OPEN_FAIL  	= -2,              //�򿪴���
		UFILE_FAIL			= -1,              //�ļ�����ʧ��
		UFILE_SUCCESS        =  0              //�ļ������ɹ�
��	 ע: ���籣��,Record�������Ҳ�ǳ��Ρ������ɹ�������£�Record�����������䡣
*************************************************************************************/
int UFile_UpdateRecordByIndex(cchar *FileName, int iFileLocation, void *Record, int Record_Len, uint Index);

/*************************************************************************************
��    Ȩ������ħ�����ӿƼ����޹�˾
��	 �ߣ�yangjy
��    �ܣ�2.2.9.21	ɾ����¼��UFile_DeleteRecord��ͨ������ɾ������һ����¼
���������FileName���ļ�����
		iFileLocation: �洢λ�ã��μ�enum FILELOCATION
		Record_Len����¼����
		Condtion����ѯ�������ο�DBSearCond�ṹ
�����������
��    �أ�UFILE_NO_EXIST       = -12,             //ָ�����ļ�������
		UFILE_PARAERROR      = -11��            //������
		UFILE_NO_RECORD		= -10,             //��¼δ�ҵ�
		UFILE_DELETE_FAIL	= -7,              //ɾ���ļ���¼����
		UFILE_OPEN_FAIL  	= -2,              //�򿪴���
		UFILE_FAIL			= -1,              //�ļ�����ʧ��
		UFILE_SUCCESS        =  0              //�ļ������ɹ�
��	 ע: ���籣��
*************************************************************************************/
int UFile_DeleteRecord(cchar *FileName, int iFileLocation, int Record_Len, DBSEARCOND *Condtion);

/*************************************************************************************
��    Ȩ������ħ�����ӿƼ����޹�˾
��	 �ߣ�yangjy
��    �ܣ�2.2.9.22	����������ɾ����¼��UFile_DeleteRecordByIndex��
���������FileName���ļ�����
		iFileLocation: �洢λ�ã��μ�enum FILELOCATION
		Record_Len����¼����
		Index�� ��¼������
�����������
��    �أ�UFILE_NO_EXIST       = -12,             //ָ�����ļ�������
		UFILE_PARAERROR      = -11��            //������
		UFILE_NO_RECORD		= -10,             //��¼δ�ҵ�
		UFILE_DELETE_FAIL	= -7,              //ɾ���ļ���¼����
		UFILE_OPEN_FAIL  	= -2,              //�򿪴���
		UFILE_FAIL			= -1,              //�ļ�����ʧ��
		UFILE_SUCCESS        =  0              //�ļ������ɹ�
��	 ע: ���籣��
*************************************************************************************/
int UFile_DeleteRecordByIndex(cchar *FileName, int iFileLocation, int Record_Len, uint Index);

/*************************************************************************************
��    Ȩ������ħ�����ӿƼ����޹�˾
��	 �ߣ�yangjy
��    �ܣ�2.2.9.23	��һ���ı���UFile_ReadLine)ͬʱ֧�� \r \n����(������������Ӧ���������з�)
���������pFile���ļ�handle
		LineBuffSize�������С
���������pLineBuff	����ȡ���ı�����
��    �أ��ɹ������ݳ���
		UFILE_PARAERROR      = -11��            //������
		UFILE_READ_FAIL		= -5,              //������
		UFILE_FAIL			= -1,              //�ļ�����ʧ��
��	 ע: ����ı��ļ����ӵ�ǰλ�ö�ȡһ�����ݣ�����ת����һ�С�
*************************************************************************************/
int UFile_ReadLine(FILE_HANDLE pFile, char *pLineBuff,uint LineBuffSize);

/*************************************************************************************
��    Ȩ������ħ�����ӿƼ����޹�˾
��	 �ߣ�yangjy
��    �ܣ�2.2.9.24	��ȡ�Ƕ�����¼��UFile_ReadTLV�����Ƕ�����¼TLV����IC��TVL��ʽһ��
���������FileName: �ļ�����
		iFileLocation: �洢λ�ã��μ�enum FILELOCATION
		FldID: ��ǩ(Tag)
���������Data: ����(Value)
		DataLen: ����(length)
��    �أ�UFILE_NO_EXIST       = -12,             //ָ�����ļ�������
		UFILE_PARAERROR      = -11��            //������
		UFILE_NO_RECORD		= -10,             //��¼δ�ҵ�
		UFILE_READ_FAIL		= -5,              //������
		UFILE_OPEN_FAIL  	= -2,              //�򿪴���
		UFILE_FAIL			= -1,              //�ļ�����ʧ��
		UFILE_SUCCESS        =  0              //�ļ������ɹ�
��	 ע: ��ȡTLV��ʽ�ļ�¼
*************************************************************************************/
int UFile_ReadTLV(char *FileName, int iFileLocation, uint FldID, char *Data, uint *DataLen);

/*************************************************************************************
��    Ȩ������ħ�����ӿƼ����޹�˾
��	 �ߣ�yangjy
��    �ܣ�2.2.9.25	д�Ƕ������ݣ�UFile_WriteTLV��
���������FileName���ļ�����
		iFileLocation: �洢λ�ã��μ�enum FILELOCATION
		FldID����ǩ(Tag)
		Data������(Value)
		DataLen������(length)
�����������
��    �أ�UFILE_NO_EXIST       = -12,             //ָ�����ļ�������
		UFILE_PARAERROR      = -11��            //������
		UFILE_WRITE_FAIL		= -4,              //д����
		UFILE_OPEN_FAIL  	= -2,              //�򿪴���
		UFILE_FAIL			= -1,              //�ļ�����ʧ��
		UFILE_SUCCESS        =  0              //�ļ������ɹ�
��	 ע: ��
*************************************************************************************/
int UFile_WriteTLV(char *FileName, int iFileLocation, uint FldID, char *Data, uint *DataLen);

/*************************************************************************************
��    Ȩ������ħ�����ӿƼ����޹�˾
��	 �ߣ�yangjy
��    �ܣ�2.2.9.26	ɾ���Ƕ�����¼��UFile_DeleteTLV��
���������FileName���ļ�����
		iFileLocation: �洢λ�ã��μ�enum FILELOCATION
		FldID����ǩ(Tag)
�����������
��    �أ�UFILE_NO_EXIST       = -12,             //ָ�����ļ�������
		UFILE_PARAERROR      = -11��            //������
		UFILE_NO_RECORD		= -10,             //��¼δ�ҵ�
		UFILE_DELETE_FAIL	= -7,              //ɾ���ļ���¼����
		UFILE_OPEN_FAIL  	= -2,              //�򿪴���
		UFILE_FAIL			= -1,              //�ļ�����ʧ��
		UFILE_SUCCESS        =  0              //�ļ������ɹ�
��	 ע: ��
*************************************************************************************/
int UFile_DeleteTLV(char *FileName, int iFileLocation, uint FldID);




int UFile_GetLength(cchar *FileName, int iFileLocation);


#endif /*__LIBAPI_FILE_HEADER__*/
