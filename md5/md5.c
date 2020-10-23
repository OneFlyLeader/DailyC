#include "md5.h"
#include <string.h>

#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

#define RL(x, y) (((x) << (y)) | ((x) >> (32 - (y))))  //x向左循环移y位

#define PP(x) (x<<24)|((x<<8)&0xff0000)|((x>>8)&0xff00)|(x>>24)  //将x高低位互换,例如PP(aabbccdd)=ddccbbaa

#define FF(a, b, c, d, x, s, ac) a = b + (RL((a + F(b,c,d) + x + ac),s))
#define GG(a, b, c, d, x, s, ac) a = b + (RL((a + G(b,c,d) + x + ac),s))
#define HH(a, b, c, d, x, s, ac) a = b + (RL((a + H(b,c,d) + x + ac),s))
#define II(a, b, c, d, x, s, ac) a = b + (RL((a + I(b,c,d) + x + ac),s))

unsigned int A,B,C,D,a,b,c,d;
unsigned int x[16];
unsigned int flen[2];

void md5(){                 //MD5核心算法,供64轮
    a=A,b=B,c=C,d=D;
    /* Round 1 */
    FF (a, b, c, d, x[ 0],  7, 0xd76aa478); /**//* 1 */
    FF (d, a, b, c, x[ 1], 12, 0xe8c7b756); /**//* 2 */
    FF (c, d, a, b, x[ 2], 17, 0x242070db); /**//* 3 */
    FF (b, c, d, a, x[ 3], 22, 0xc1bdceee); /**//* 4 */
    FF (a, b, c, d, x[ 4],  7, 0xf57c0faf); /**//* 5 */
    FF (d, a, b, c, x[ 5], 12, 0x4787c62a); /**//* 6 */
    FF (c, d, a, b, x[ 6], 17, 0xa8304613); /**//* 7 */
    FF (b, c, d, a, x[ 7], 22, 0xfd469501); /**//* 8 */
    FF (a, b, c, d, x[ 8],  7, 0x698098d8); /**//* 9 */
    FF (d, a, b, c, x[ 9], 12, 0x8b44f7af); /**//* 10 */
    FF (c, d, a, b, x[10], 17, 0xffff5bb1); /**//* 11 */
    FF (b, c, d, a, x[11], 22, 0x895cd7be); /**//* 12 */
    FF (a, b, c, d, x[12],  7, 0x6b901122); /**//* 13 */
    FF (d, a, b, c, x[13], 12, 0xfd987193); /**//* 14 */
    FF (c, d, a, b, x[14], 17, 0xa679438e); /**//* 15 */
    FF (b, c, d, a, x[15], 22, 0x49b40821); /**//* 16 */

    /* Round 2 */
    GG (a, b, c, d, x[ 1],  5, 0xf61e2562); /**//* 17 */
    GG (d, a, b, c, x[ 6],  9, 0xc040b340); /**//* 18 */
    GG (c, d, a, b, x[11], 14, 0x265e5a51); /**//* 19 */
    GG (b, c, d, a, x[ 0], 20, 0xe9b6c7aa); /**//* 20 */
    GG (a, b, c, d, x[ 5],  5, 0xd62f105d); /**//* 21 */
    GG (d, a, b, c, x[10],  9, 0x02441453); /**//* 22 */
    GG (c, d, a, b, x[15], 14, 0xd8a1e681); /**//* 23 */
    GG (b, c, d, a, x[ 4], 20, 0xe7d3fbc8); /**//* 24 */
    GG (a, b, c, d, x[ 9],  5, 0x21e1cde6); /**//* 25 */
    GG (d, a, b, c, x[14],  9, 0xc33707d6); /**//* 26 */
    GG (c, d, a, b, x[ 3], 14, 0xf4d50d87); /**//* 27 */
    GG (b, c, d, a, x[ 8], 20, 0x455a14ed); /**//* 28 */
    GG (a, b, c, d, x[13],  5, 0xa9e3e905); /**//* 29 */
    GG (d, a, b, c, x[ 2],  9, 0xfcefa3f8); /**//* 30 */
    GG (c, d, a, b, x[ 7], 14, 0x676f02d9); /**//* 31 */
    GG (b, c, d, a, x[12], 20, 0x8d2a4c8a); /**//* 32 */

    /* Round 3 */
    HH (a, b, c, d, x[ 5],  4, 0xfffa3942); /**//* 33 */
    HH (d, a, b, c, x[ 8], 11, 0x8771f681); /**//* 34 */
    HH (c, d, a, b, x[11], 16, 0x6d9d6122); /**//* 35 */
    HH (b, c, d, a, x[14], 23, 0xfde5380c); /**//* 36 */
    HH (a, b, c, d, x[ 1],  4, 0xa4beea44); /**//* 37 */
    HH (d, a, b, c, x[ 4], 11, 0x4bdecfa9); /**//* 38 */
    HH (c, d, a, b, x[ 7], 16, 0xf6bb4b60); /**//* 39 */
    HH (b, c, d, a, x[10], 23, 0xbebfbc70); /**//* 40 */
    HH (a, b, c, d, x[13],  4, 0x289b7ec6); /**//* 41 */
    HH (d, a, b, c, x[ 0], 11, 0xeaa127fa); /**//* 42 */
    HH (c, d, a, b, x[ 3], 16, 0xd4ef3085); /**//* 43 */
    HH (b, c, d, a, x[ 6], 23, 0x04881d05); /**//* 44 */
    HH (a, b, c, d, x[ 9],  4, 0xd9d4d039); /**//* 45 */
    HH (d, a, b, c, x[12], 11, 0xe6db99e5); /**//* 46 */
    HH (c, d, a, b, x[15], 16, 0x1fa27cf8); /**//* 47 */
    HH (b, c, d, a, x[ 2], 23, 0xc4ac5665); /**//* 48 */

    /* Round 4 */
    II (a, b, c, d, x[ 0],  6, 0xf4292244); /**//* 49 */
    II (d, a, b, c, x[ 7], 10, 0x432aff97); /**//* 50 */
    II (c, d, a, b, x[14], 15, 0xab9423a7); /**//* 51 */
    II (b, c, d, a, x[ 5], 21, 0xfc93a039); /**//* 52 */
    II (a, b, c, d, x[12],  6, 0x655b59c3); /**//* 53 */
    II (d, a, b, c, x[ 3], 10, 0x8f0ccc92); /**//* 54 */
    II (c, d, a, b, x[10], 15, 0xffeff47d); /**//* 55 */
    II (b, c, d, a, x[ 1], 21, 0x85845dd1); /**//* 56 */
    II (a, b, c, d, x[ 8],  6, 0x6fa87e4f); /**//* 57 */
    II (d, a, b, c, x[15], 10, 0xfe2ce6e0); /**//* 58 */
    II (c, d, a, b, x[ 6], 15, 0xa3014314); /**//* 59 */
    II (b, c, d, a, x[13], 21, 0x4e0811a1); /**//* 60 */
    II (a, b, c, d, x[ 4],  6, 0xf7537e82); /**//* 61 */
    II (d, a, b, c, x[11], 10, 0xbd3af235); /**//* 62 */
    II (c, d, a, b, x[ 2], 15, 0x2ad7d2bb); /**//* 63 */
    II (b, c, d, a, x[ 9], 21, 0xeb86d391); /**//* 64 */

    A += a;
    B += b;
    C += c;
    D += d;
}

/**
 * 从src拷贝到dst，选择dstLen和srcLen中的最小值作为最终拷贝长度
 * 返回值为拷贝的长度
 * @param dst
 * @param src
 * @param dstLen
 * @param srcLen
 * @return 拷贝的长度
 */
int strCpy(char* dst, const char* src, const unsigned int dstLen, const unsigned int srcLen){
    int len = (srcLen < dstLen) ? srcLen : dstLen;
    for(int i = 0; i < len; i++){
        dst[i] = src[i];
    }
    return len;
}

/**
 * 计算MD5
 * @return
 */
void Md5(char* head, const unsigned int len, unsigned int* res){
    // 只能处理2G以内的文件
    if((len & 0x80000000) > 0) {
        res = NULL;
        return ;
    }

    A=0x67452301,B=0xefcdab89,C=0x98badcfe,D=0x10325476; //初始化链接变量(魔术数字)
    // 计算文件长度
    flen[1]=len / 0x20000000;
    flen[0]=(len % 0x20000000) * 8;

    int reserve = len;
    char* src = head;
    int writeLen = 0;
    memset(x, 0, 64);   //初始化x数组为0 512bit/8=64字节
    writeLen = strCpy((char*)x, src, 64, reserve);
    reserve -= writeLen;
    src += writeLen;

    for(int i = 0; i < len/64; i++){//循环运算直至文件结束
        md5();
        memset(x,0,64);
        writeLen = strCpy((char*)x, src, 64, reserve);
        reserve -= writeLen;
        src += writeLen;
    }
    ((char*)x)[len % 64]=128;  //文件结束补1,补0操作,128二进制即10000000
    if(len % 64 > 55) {
        md5();
        memset(x, 0, 64);
    }
    memcpy(x+14,flen,8);    //文件末尾加入原文件的bit长度
    md5();

    *(res) = PP(A);
    *(res+1) = PP(B);
    *(res+2) = PP(C);
    *(res+3) = PP(D);
}
