/**
 * \file aes.h
 *
 * \brief AES block cipher
 *
 *  Copyright (C) 2006-2014, Brainspark B.V.
 *
 *  This file is part of PolarSSL (http://www.polarssl.org)
 *  Lead Maintainer: Paul Bakker <polarssl_maintainer at polarssl.org>
 *
 *  All rights reserved.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
#ifndef PUB_AES_H
#define PUB_AES_H

/* padlock.c and aesni.c rely on these values! */
#define AES_ENCRYPT     1
#define AES_DECRYPT     0

#define POLARSSL_ERR_AES_INVALID_KEY_LENGTH                -0x0020  /**< Invalid key length. */
#define POLARSSL_ERR_AES_INVALID_INPUT_LENGTH              -0x0022  /**< Invalid data input length. */


#ifdef __cplusplus
extern "C" {
#endif

#include "pub\pub.h"

	/**
	* @brief ִ��AES�㷨���ı��ӽ���
	* @param int mode ���ͣ�����AES_ENCRYPT������AES_DECRYPT
	* @param In	�����ܴ�ָ��
	* @param Out �������ָ��
	* @param datalen �����ܴ��ĳ��ȣ�����Ϊ16�ı��� ͬʱOut�Ļ�������СӦ���ڻ��ߵ���datalen
	* @param Key ��Կ(��Ϊ16λ,24λ,32λ)֧��3��Կ
	* @param keylen ��Կ���ȣ����24λ���ֽ����Զ��ü�
	* @return �Ƿ���ܳɹ� 0���ܳɹ� <0 ����ʧ��
	*/
LIB_EXPORT int pub_aes_crypt_ecb(char*sin,unsigned int datalen, const char*skey,const unsigned char keylen, int mode,char*sout);


#ifdef __cplusplus
}
#endif

#else

#endif  

