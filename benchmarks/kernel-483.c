// --atomics 18 ---atomic_reductions ---fake_divergence ---inter_thread_comm -g 82,72,1 -l 1,9,1
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

__constant uint32_t permutations[10][9] = {
{5,7,8,1,0,2,6,4,3}, // permutation 0
{1,8,5,7,0,2,4,3,6}, // permutation 1
{1,5,8,4,3,2,7,0,6}, // permutation 2
{7,5,8,3,4,0,2,6,1}, // permutation 3
{1,3,0,7,8,2,5,6,4}, // permutation 4
{7,4,8,3,6,5,0,2,1}, // permutation 5
{1,0,2,3,6,5,7,4,8}, // permutation 6
{5,0,6,2,3,1,4,8,7}, // permutation 7
{8,7,5,2,1,4,3,0,6}, // permutation 8
{6,2,0,3,1,5,4,7,8} // permutation 9
};

// Seed: 1079206638

#include "CLSmith.h"

/* --- Struct/Union Declarations --- */
struct S1 {
    int32_t g_3;
    int32_t *g_5;
    int32_t ** volatile g_4;
    uint16_t g_11;
    uint16_t g_14[5][9];
    uint32_t v_collective;
    uint64_t global_0_offset;
    uint64_t global_1_offset;
    uint64_t global_2_offset;
    uint64_t local_0_offset;
    uint64_t local_1_offset;
    uint64_t local_2_offset;
    uint64_t group_0_offset;
    uint64_t group_1_offset;
    uint64_t group_2_offset;
    uint32_t tid;
    __local volatile uint32_t *l_atomic_reduction;
    __global volatile uint32_t *g_atomic_reduction;
    __local int64_t *l_comm_values;
    __global int64_t *g_comm_values;
};


/* --- FORWARD DECLARATIONS --- */
int16_t  func_1(struct S1 * p_15);


/* --- FUNCTIONS --- */
/* ------------------------------------------ */
/* 
 * reads : p_15->g_4 p_15->g_11 p_15->g_5 p_15->g_3 p_15->g_14
 * writes: p_15->g_5 p_15->g_11 p_15->g_14
 */
int16_t  func_1(struct S1 * p_15)
{ /* block id: 4 */
    int32_t *l_2 = &p_15->g_3;
    int32_t *l_6 = &p_15->g_3;
    int32_t *l_7 = &p_15->g_3;
    int32_t l_8 = (-8L);
    int32_t *l_9 = &p_15->g_3;
    int32_t *l_10[5][3];
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 3; j++)
            l_10[i][j] = &l_8;
    }
    (*p_15->g_4) = l_2;
    --p_15->g_11;
    p_15->g_14[1][6] &= (*p_15->g_5);
    return p_15->g_3;
}


__kernel void entry(__global ulong *result, __global volatile uint *g_atomic_input, __global volatile uint *g_special_values, __global volatile int *g_atomic_reduction, __global int *sequence_input, __global long *g_comm_values) {
    int i, j;
    __local volatile uint32_t l_atomic_reduction[1];
    if (get_linear_local_id() == 0)
        for (i = 0; i < 1; i++)
            l_atomic_reduction[i] = 0;
    __local int64_t l_comm_values[9];
    if (get_linear_local_id() == 0)
        for (i = 0; i < 9; i++)
            l_comm_values[i] = 1;
    struct S1 c_16;
    struct S1* p_15 = &c_16;
    struct S1 c_17 = {
        0L, // p_15->g_3
        &p_15->g_3, // p_15->g_5
        &p_15->g_5, // p_15->g_4
        65535UL, // p_15->g_11
        {{5UL,1UL,65529UL,1UL,5UL,5UL,1UL,65529UL,1UL},{5UL,1UL,65529UL,1UL,5UL,5UL,1UL,65529UL,1UL},{5UL,1UL,65529UL,1UL,5UL,5UL,1UL,65529UL,1UL},{5UL,1UL,65529UL,1UL,5UL,5UL,1UL,65529UL,1UL},{5UL,1UL,65529UL,1UL,5UL,5UL,1UL,65529UL,1UL}}, // p_15->g_14
        0, // p_15->v_collective
        sequence_input[get_global_id(0)], // p_15->global_0_offset
        sequence_input[get_global_id(1)], // p_15->global_1_offset
        sequence_input[get_global_id(2)], // p_15->global_2_offset
        sequence_input[get_local_id(0)], // p_15->local_0_offset
        sequence_input[get_local_id(1)], // p_15->local_1_offset
        sequence_input[get_local_id(2)], // p_15->local_2_offset
        sequence_input[get_group_id(0)], // p_15->group_0_offset
        sequence_input[get_group_id(1)], // p_15->group_1_offset
        sequence_input[get_group_id(2)], // p_15->group_2_offset
        (safe_add_func_uint32_t_u_u((safe_mul_func_uint32_t_u_u(get_linear_group_id(), 9)), permutations[0][get_linear_local_id()])), // p_15->tid
        l_atomic_reduction, // l_atomic_reduction
        g_atomic_reduction, // g_atomic_reduction
        l_comm_values, // l_comm_values
        g_comm_values, // g_comm_values
    };
    c_16 = c_17;
    barrier(CLK_LOCAL_MEM_FENCE | CLK_GLOBAL_MEM_FENCE);
    func_1(p_15);
    barrier(CLK_LOCAL_MEM_FENCE | CLK_GLOBAL_MEM_FENCE);
    uint64_t crc64_context = 0xFFFFFFFFFFFFFFFFUL;
    int print_hash_value = 0;
    transparent_crc(p_15->g_3, "p_15->g_3", print_hash_value);
    transparent_crc(p_15->g_11, "p_15->g_11", print_hash_value);
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 9; j++)
        {
            transparent_crc(p_15->g_14[i][j], "p_15->g_14[i][j]", print_hash_value);

        }
    }
    transparent_crc(p_15->v_collective, "p_15->v_collective", print_hash_value);
    transparent_crc(p_15->l_comm_values[get_linear_local_id()], "p_15->l_comm_values[get_linear_local_id()]", print_hash_value);
    transparent_crc(p_15->g_comm_values[get_linear_group_id() * 9 + get_linear_local_id()], "p_15->g_comm_values[get_linear_group_id() * 9 + get_linear_local_id()]", print_hash_value);
    result[get_linear_global_id()] = crc64_context ^ 0xFFFFFFFFFFFFFFFFUL;
}
