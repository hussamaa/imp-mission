// -g 83,92,1 -l 1,23,1
#define int64_t long
#define uint64_t ulong
#define int_least64_t long
#define uint_least64_t ulong
#define int_fast64_t long
#define uint_fast64_t ulong
#define intmax_t long
#define uintmax_t ulong
#define int32_t int
#define uint32_t uint
#define int16_t short
#define uint16_t ushort
#define int8_t char
#define uint8_t uchar

#define INT64_MIN LONG_MIN
#define INT64_MAX LONG_MAX
#define INT32_MIN INT_MIN
#define INT32_MAX INT_MAX
#define INT16_MIN SHRT_MIN
#define INT16_MAX SHRT_MAX
#define INT8_MIN CHAR_MIN
#define INT8_MAX CHAR_MAX
#define UINT64_MIN ULONG_MIN
#define UINT64_MAX ULONG_MAX
#define UINT32_MIN UINT_MIN
#define UINT32_MAX UINT_MAX
#define UINT16_MIN USHRT_MIN
#define UINT16_MAX USHRT_MAX
#define UINT8_MIN UCHAR_MIN
#define UINT8_MAX UCHAR_MAX

#define transparent_crc(X, Y, Z) transparent_crc_(&crc64_context, X, Y, Z)

#define VECTOR(X , Y) VECTOR_(X, Y)
#define VECTOR_(X, Y) X##Y

#ifndef NO_GROUP_DIVERGENCE
#define GROUP_DIVERGE(x, y) get_group_id(x)
#else
#define GROUP_DIVERGE(x, y) (y)
#endif

#ifndef NO_FAKE_DIVERGENCE
#define FAKE_DIVERGE(x, y, z) (x - y)
#else
#define FAKE_DIVERGE(x, y, z) (z)
#endif


// Seed: 626328093

#include "CLSmith.h"

/* --- Struct/Union Declarations --- */
struct S0 {
   uint16_t  f0;
   uint8_t  f1;
   uint32_t  f2;
};

struct S4 {
   volatile int16_t  f0;
   volatile int8_t  f1;
   volatile uint16_t  f2;
   volatile int32_t  f3;
   int64_t  f4;
   uint32_t  f5;
   uint8_t  f6;
   struct S0  f7;
};

struct S5 {
    struct S4 g_2;
};


/* --- FORWARD DECLARATIONS --- */
struct S4  func_1(struct S5 * p_3);


/* --- FUNCTIONS --- */
/* ------------------------------------------ */
/* 
 * reads : p_3->g_2
 * writes:
 */
struct S4  func_1(struct S5 * p_3)
{ /* block id: 4 */
    return p_3->g_2;
}


__kernel void entry(__global ulong *result) {
    int ;
    struct S5 c_4;
    struct S5* p_3 = &c_4;
    struct S5 c_5 = {
        {0x738DL,5L,65529UL,0L,1L,0UL,253UL,{0xFDBDL,253UL,0xDF7E4414L}}, // p_3->g_2
    };
    c_4 = c_5;
    barrier(CLK_LOCAL_MEM_FENCE | CLK_GLOBAL_MEM_FENCE);
    func_1(p_3);
    barrier(CLK_LOCAL_MEM_FENCE | CLK_GLOBAL_MEM_FENCE);
    uint64_t crc64_context = 0xFFFFFFFFFFFFFFFFUL;
    int print_hash_value = 0;
    transparent_crc(p_3->g_2.f0, "p_3->g_2.f0", print_hash_value);
    transparent_crc(p_3->g_2.f1, "p_3->g_2.f1", print_hash_value);
    transparent_crc(p_3->g_2.f2, "p_3->g_2.f2", print_hash_value);
    transparent_crc(p_3->g_2.f3, "p_3->g_2.f3", print_hash_value);
    transparent_crc(p_3->g_2.f4, "p_3->g_2.f4", print_hash_value);
    transparent_crc(p_3->g_2.f5, "p_3->g_2.f5", print_hash_value);
    transparent_crc(p_3->g_2.f6, "p_3->g_2.f6", print_hash_value);
    transparent_crc(p_3->g_2.f7.f0, "p_3->g_2.f7.f0", print_hash_value);
    transparent_crc(p_3->g_2.f7.f1, "p_3->g_2.f7.f1", print_hash_value);
    transparent_crc(p_3->g_2.f7.f2, "p_3->g_2.f7.f2", print_hash_value);
    result[get_linear_global_id()] = crc64_context ^ 0xFFFFFFFFFFFFFFFFUL;
}
