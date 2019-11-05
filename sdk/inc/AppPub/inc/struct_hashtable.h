#ifndef _HASH_H_
#define _HASH_H_
#include "pub_define.h"
#include "pub\pub.h"
#define MAXLEN_TAG 3
#define MAXLEN_VAL 255


typedef struct{
	char tag[MAXLEN_TAG];
	short nOff;
	short nLen;
}HashData;

typedef struct   
{  
	HashData *elem;/**<Data elements store base addresses and dynamically allocate arrays  */
	int nCount; /**<Number of current data elements  */
	int nSizeindex; /**<hashsize[nSizeindex]For current capacity*/
	unsigned int (*Hash_Fun)(char *pszBuf);
}HashTable;  

LIB_EXPORT extern int InitHashTable(HashTable *hashtable,unsigned int (*Hash_Fun)(char *),int nSizeIndex);
LIB_EXPORT extern void DestroyHashTable(HashTable *hashtable);
LIB_EXPORT extern void RecreateHashTable(HashTable *hashtable); 
LIB_EXPORT extern int  InsertHash(HashTable *hashtable,HashData elem,YESORNO bOverride , int cTagLen);
LIB_EXPORT extern int FindHash(HashTable hashtable,char *key,int *nAddress);
LIB_EXPORT extern void TraverseHash(HashTable H,void(*Vi)(int,HashData));
LIB_EXPORT extern int  DeleteHash(HashTable *hashtable,char*szTag);
LIB_EXPORT extern void ClearHashTable(HashTable *hashtable);
#endif