#ifndef _AES_H
#define _AES_H

#define AES_ENCRYPT     1
#define AES_DECRYPT     0

/* Because array size can't be a const in C, the following two are macros.
   Both sizes are in bytes. */
#define AES_MAXNR 14
#define AES_BLOCK_SIZE 16

struct aes_key_st {
    unsigned long rd_key[4 *(AES_MAXNR + 1)];
    int rounds;
};
typedef struct aes_key_st AES_KEY;

#define GETU32(pt) (((u32)(pt)[0] << 24) ^ ((u32)(pt)[1] << 16) ^ ((u32)(pt)[2] <<  8) ^ ((u32)(pt)[3]))
#define PUTU32(ct, st) { (ct)[0] = (u8)((st) >> 24); (ct)[1] = (u8)((st) >> 16); (ct)[2] = (u8)((st) >>  8); (ct)[3] = (u8)(st); }

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;

#define MAXKC   (256/32)
#define MAXKB   (256/8)
#define MAXNR   14

/* This controls loop-unrolling in aes.c */
#undef FULL_UNROLL

int AES_set_encrypt_key(const unsigned char *, const int, AES_KEY *);
int AES_set_decrypt_key(const unsigned char *, const int, AES_KEY *);

void AES_encrypt(const unsigned char *, unsigned char *, const AES_KEY *);
void AES_decrypt(const unsigned char *, unsigned char *, const AES_KEY *);



#endif /* !_AES_H */
