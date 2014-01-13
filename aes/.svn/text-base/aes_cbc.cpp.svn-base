/**
 * @file aes_cbc.cpp
 * @brief The core encrypt routine
 * @author sxkj26
 * @version v1.0.0
 * @date 2014-01-11
 */
#include "aes.h"
#include "modes.h"

void AES_cbc_encrypt(const unsigned char *in, unsigned char *out,
		     size_t len, const AES_KEY *key,
		     unsigned char *ivec, const int enc) {

	if (enc)
		CRYPTO_cbc128_encrypt(in,out,len,key,ivec,(block128_f)AES_encrypt);
	else
		CRYPTO_cbc128_decrypt(in,out,len,key,ivec,(block128_f)AES_decrypt);
}
