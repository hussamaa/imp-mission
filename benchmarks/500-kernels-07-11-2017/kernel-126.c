// -g 14,8,9 -l 1,4,1
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


// Seed: 692548934

#include "CLSmith.h"

/* --- Struct/Union Declarations --- */
struct S1 {
    int32_t g_4;
    volatile uint32_t g_6;
};


/* --- FORWARD DECLARATIONS --- */
int32_t  func_1(struct S1 * p_9);


/* --- FUNCTIONS --- */
/* ------------------------------------------ */
/* 
 * reads : p_9->g_4 p_9->g_6
 * writes: p_9->g_4 p_9->g_6
 */
int32_t  func_1(struct S1 * p_9)
{ /* block id: 4 */
    uint32_t l_2 = 0UL;
    int32_t *l_3[1];
    int64_t l_5 = (-7L);
    int i;
    for (i = 0; i < 1; i++)
        l_3[i] = &p_9->g_4;
    l_5 = (4UL > l_2);
    for (p_9->g_4 = 0; (p_9->g_4 >= 0); p_9->g_4 -= 1)
    { /* block id: 8 */
        int i;
        l_3[p_9->g_4] = l_3[p_9->g_4];
        p_9->g_6--;
    }
    return p_9->g_4;
}


__kernel void entry(__global ulong *result) {
    int ;
    struct S1 c_10;
    struct S1* p_9 = &c_10;
    struct S1 c_11 = {
        0x38C08872L, // p_9->g_4
        7UL, // p_9->g_6
    };
    c_10 = c_11;
    barrier(CLK_LOCAL_MEM_FENCE | CLK_GLOBAL_MEM_FENCE);
    func_1(p_9);
    barrier(CLK_LOCAL_MEM_FENCE | CLK_GLOBAL_MEM_FENCE);
    uint64_t crc64_context = 0xFFFFFFFFFFFFFFFFUL;
    int print_hash_value = 0;
    transparent_crc(p_9->g_4, "p_9->g_4", print_hash_value);
    transparent_crc(p_9->g_6, "p_9->g_6", print_hash_value);
    result[get_linear_global_id()] = crc64_context ^ 0xFFFFFFFFFFFFFFFFUL;
}
