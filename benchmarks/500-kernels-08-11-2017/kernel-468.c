// --atomics 40 ---atomic_reductions ---fake_divergence ---inter_thread_comm -g 73,63,1 -l 73,3,1
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

__constant uint32_t permutations[10][219] = {
{169,147,203,197,119,94,161,26,47,201,107,127,2,114,3,4,173,186,122,87,115,199,174,164,100,177,109,99,90,41,144,195,27,167,204,46,193,56,71,37,175,40,36,38,187,156,1,68,58,72,134,218,21,84,149,22,67,43,42,192,24,206,148,31,172,63,139,211,200,97,75,104,78,118,132,6,121,10,140,8,125,143,130,208,44,153,93,217,85,155,55,65,154,53,14,159,129,163,162,135,116,160,136,7,179,13,19,81,82,131,101,124,117,86,70,76,166,111,74,105,103,88,150,210,190,157,83,79,171,198,54,25,176,152,0,98,137,16,12,69,202,30,32,194,9,205,39,28,170,34,213,120,185,66,189,91,191,133,142,214,165,113,61,182,207,89,106,23,50,77,29,18,11,158,51,17,102,57,112,181,145,188,80,73,15,59,138,64,49,123,95,141,151,216,33,5,183,48,212,168,110,108,178,209,126,35,128,146,92,180,96,215,196,62,52,184,60,45,20}, // permutation 0
{74,117,189,154,209,141,166,22,55,85,207,155,18,111,191,173,5,9,113,193,169,47,192,92,57,185,144,127,42,196,25,195,122,35,108,138,109,202,165,91,120,171,29,145,11,14,32,161,159,59,33,186,203,81,98,124,61,132,31,105,175,49,216,70,182,79,106,107,129,180,172,34,84,210,187,184,51,94,112,87,139,37,46,4,116,71,90,131,123,163,96,102,143,104,190,160,101,214,213,204,157,178,58,93,2,41,88,170,54,206,158,24,21,75,66,205,128,0,3,162,146,134,77,110,183,40,23,56,176,140,149,179,73,218,100,89,15,1,99,114,7,198,63,133,67,30,44,135,86,151,197,69,97,215,199,188,167,177,212,194,82,156,147,211,181,6,115,48,17,150,12,168,164,95,62,121,8,201,28,200,148,152,64,20,43,119,125,118,153,83,10,39,50,142,68,126,76,13,78,80,136,53,103,130,38,19,45,65,27,16,72,137,174,208,60,217,26,52,36}, // permutation 1
{90,51,82,84,2,195,198,111,0,39,152,80,101,12,192,143,36,129,112,74,109,189,14,193,23,217,167,72,50,130,47,128,76,154,200,202,19,107,131,83,144,88,91,153,164,59,132,20,105,203,56,65,73,147,113,15,26,213,168,115,210,93,185,179,110,194,158,218,181,44,21,61,145,55,135,177,97,118,95,171,184,64,1,212,70,77,6,165,146,155,139,206,204,45,71,46,160,116,208,18,5,137,7,176,127,30,67,169,178,37,13,96,211,31,197,10,117,94,58,136,4,8,201,33,148,133,92,172,89,141,159,102,149,196,191,214,98,190,16,120,150,103,126,52,187,124,180,41,207,174,9,32,57,162,81,38,161,186,122,27,157,215,199,75,175,106,216,125,11,86,119,123,173,54,17,134,163,3,78,42,60,69,40,22,99,205,100,108,85,87,28,24,156,182,43,62,121,68,48,142,63,114,209,183,53,104,25,29,34,138,151,49,66,79,35,166,140,170,188}, // permutation 2
{33,170,204,214,112,150,24,100,64,124,111,88,98,87,133,28,135,160,2,128,206,82,188,60,77,19,203,200,10,42,152,148,142,164,115,208,68,113,99,168,159,147,110,37,95,32,107,40,65,94,22,63,103,16,171,198,11,126,205,101,183,193,138,210,0,31,137,70,74,196,49,56,102,105,30,46,218,201,57,185,27,162,34,175,125,9,197,117,86,149,129,130,73,36,213,13,66,217,134,191,47,35,90,72,132,118,141,216,166,21,51,189,5,4,181,91,83,62,18,209,151,155,104,154,69,172,39,8,180,93,45,194,187,178,169,67,140,109,44,212,144,139,71,121,52,156,43,48,146,7,53,108,75,3,58,174,202,14,96,161,136,145,6,153,26,179,55,119,12,61,182,120,84,215,158,106,29,167,190,131,79,186,17,92,1,199,192,163,127,195,114,25,20,184,50,78,80,41,123,89,23,116,38,157,177,211,76,207,176,143,97,165,15,85,54,122,173,59,81}, // permutation 3
{185,142,78,190,130,24,50,110,115,17,40,90,102,79,47,114,77,26,27,34,132,144,49,87,146,54,68,209,107,18,207,177,167,152,153,124,218,85,165,151,64,98,14,63,202,194,94,48,211,57,180,173,181,111,147,83,73,192,125,186,138,9,134,105,15,89,1,39,30,204,37,196,123,162,203,93,170,41,71,158,104,216,182,42,205,66,96,3,136,118,70,195,4,148,178,169,198,159,106,72,171,5,208,88,126,166,16,187,61,75,212,44,82,45,67,188,19,183,11,46,217,2,139,184,127,32,200,108,10,119,81,23,206,179,103,140,174,191,43,117,141,28,189,145,193,135,13,157,29,97,52,120,213,137,143,20,65,161,129,133,60,164,6,21,35,172,113,116,91,112,149,76,100,92,55,154,163,36,215,33,31,51,155,58,25,84,214,69,80,95,12,109,86,156,176,38,121,59,131,101,53,99,197,150,8,160,168,128,175,199,74,7,0,201,22,210,56,62,122}, // permutation 4
{36,209,190,157,179,59,161,94,170,74,17,31,120,126,206,81,133,107,177,156,176,88,153,80,18,197,13,159,24,144,210,110,115,217,215,208,25,187,90,117,15,188,196,19,9,63,68,146,33,184,216,77,75,118,121,39,16,57,207,99,60,76,54,37,102,62,172,173,47,22,10,105,82,43,114,127,71,132,78,51,160,140,211,70,152,218,142,111,183,4,64,129,56,122,67,165,181,212,69,138,182,84,53,52,164,28,97,193,134,29,147,167,149,123,174,130,26,2,34,113,95,42,46,8,175,150,191,87,169,21,3,86,49,35,7,180,141,1,119,194,92,12,200,109,143,145,189,128,79,201,14,154,38,137,45,48,44,151,162,166,58,61,6,178,103,135,108,0,205,185,203,100,168,32,91,55,204,112,66,195,30,96,5,148,83,155,20,89,23,131,171,72,116,214,213,40,11,124,98,158,85,104,202,50,198,101,93,41,136,199,27,125,163,139,106,192,186,73,65}, // permutation 5
{143,90,150,82,48,190,57,49,50,159,152,185,201,113,196,181,154,124,25,34,125,167,17,139,54,38,43,193,122,67,163,62,23,202,84,120,156,16,200,176,96,94,166,59,93,130,110,217,64,205,169,177,158,211,33,40,32,80,138,102,53,74,210,197,65,209,157,63,218,58,31,170,27,141,29,81,77,151,198,26,121,100,66,140,12,212,75,8,37,91,183,213,192,147,70,146,174,194,203,199,165,9,171,41,153,144,61,145,92,208,135,204,116,172,18,99,86,13,97,215,134,149,119,60,132,133,39,71,187,10,51,207,7,108,30,123,195,180,188,126,1,162,148,131,45,68,128,73,127,182,35,36,20,42,136,22,175,161,179,216,85,178,117,76,118,206,189,191,87,46,164,107,24,19,160,173,155,55,142,115,98,103,101,5,47,186,114,3,44,83,168,11,89,137,2,69,111,4,56,109,28,112,184,129,79,95,72,214,15,52,78,105,21,104,106,14,0,6,88}, // permutation 6
{64,5,186,88,206,35,128,214,93,198,10,218,147,143,97,163,34,159,44,7,95,53,56,165,209,123,202,104,19,48,164,85,102,70,90,42,98,78,13,112,114,30,151,194,153,200,138,142,135,38,101,179,150,168,66,63,83,79,86,127,39,99,130,208,155,87,191,204,125,185,67,166,43,37,110,182,82,9,31,173,124,115,46,205,192,22,17,137,105,111,129,20,117,162,15,33,58,212,170,72,156,196,108,84,184,181,177,6,36,62,190,89,47,68,41,131,197,50,176,40,61,94,174,116,25,132,167,188,8,113,81,175,160,215,21,133,28,74,161,54,203,57,213,141,187,134,76,3,148,210,126,183,149,118,23,91,80,11,27,16,26,107,49,29,60,199,55,45,217,100,109,119,1,154,207,211,122,169,18,140,12,4,103,73,195,136,193,92,180,144,216,171,106,172,152,139,59,120,32,71,77,178,189,52,146,96,158,51,75,145,121,157,0,201,65,69,2,24,14}, // permutation 7
{114,184,30,82,43,189,0,41,34,126,33,210,207,157,84,77,197,81,6,128,27,172,26,199,205,186,140,39,113,76,217,132,134,79,213,203,142,37,169,42,10,120,106,179,155,9,24,174,151,139,144,28,119,3,159,102,122,209,94,11,185,53,20,36,98,51,63,191,147,13,138,40,85,160,127,52,46,80,171,71,22,70,154,62,129,107,181,19,200,58,167,65,153,14,158,15,31,92,103,123,216,91,86,5,35,105,38,95,72,96,88,175,161,48,178,182,192,110,131,193,29,4,25,87,188,201,8,115,97,67,108,170,136,17,66,204,49,148,73,124,1,56,173,89,162,141,211,137,176,54,150,117,23,190,198,18,83,180,145,118,177,215,149,99,195,214,143,55,100,196,50,218,168,125,64,206,109,60,101,45,212,44,133,90,78,208,130,156,194,163,61,59,187,111,202,93,47,57,164,165,104,112,183,135,116,146,166,7,16,12,75,74,2,21,68,152,69,121,32}, // permutation 8
{31,28,137,43,191,21,116,82,145,60,99,66,132,50,42,151,117,133,45,175,104,142,213,187,27,194,7,2,35,38,198,44,3,150,216,188,212,195,154,87,19,86,74,129,24,170,90,71,18,69,126,114,163,56,80,85,214,93,180,206,17,30,162,78,111,15,152,41,34,189,83,47,98,177,62,100,160,141,134,115,167,67,208,58,36,46,217,53,161,146,57,205,131,32,77,108,193,20,49,165,9,4,95,25,169,106,8,185,184,54,39,91,164,121,139,158,70,29,51,196,204,173,88,59,113,209,168,140,112,48,143,128,109,97,110,72,149,174,181,52,186,79,201,40,84,22,155,182,197,171,123,63,107,183,176,61,64,94,179,12,156,26,125,33,120,81,118,76,0,14,138,11,211,166,153,96,92,218,203,68,199,102,5,200,13,23,1,147,73,55,6,75,130,148,65,103,192,122,10,127,105,202,89,159,190,215,37,172,210,207,124,101,136,16,178,135,157,144,119} // permutation 9
};

// Seed: 2944179196

#include "CLSmith.h"

/* --- Struct/Union Declarations --- */
struct S5 {
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
uint32_t  func_1(struct S5 * p_3);


/* --- FUNCTIONS --- */
/* ------------------------------------------ */
/* 
 * reads :
 * writes:
 */
uint32_t  func_1(struct S5 * p_3)
{ /* block id: 4 */
    uint8_t l_2 = 0xC8L;
    return l_2;
}


__kernel void entry(__global ulong *result, __global volatile uint *g_atomic_input, __global volatile uint *g_special_values, __global volatile int *g_atomic_reduction, __global int *sequence_input, __global long *g_comm_values) {
    int i;
    __local volatile uint32_t l_atomic_reduction[1];
    if (get_linear_local_id() == 0)
        for (i = 0; i < 1; i++)
            l_atomic_reduction[i] = 0;
    __local int64_t l_comm_values[219];
    if (get_linear_local_id() == 0)
        for (i = 0; i < 219; i++)
            l_comm_values[i] = 1;
    struct S5 c_4;
    struct S5* p_3 = &c_4;
    struct S5 c_5 = {
        0, // p_3->v_collective
        sequence_input[get_global_id(0)], // p_3->global_0_offset
        sequence_input[get_global_id(1)], // p_3->global_1_offset
        sequence_input[get_global_id(2)], // p_3->global_2_offset
        sequence_input[get_local_id(0)], // p_3->local_0_offset
        sequence_input[get_local_id(1)], // p_3->local_1_offset
        sequence_input[get_local_id(2)], // p_3->local_2_offset
        sequence_input[get_group_id(0)], // p_3->group_0_offset
        sequence_input[get_group_id(1)], // p_3->group_1_offset
        sequence_input[get_group_id(2)], // p_3->group_2_offset
        (safe_add_func_uint32_t_u_u((safe_mul_func_uint32_t_u_u(get_linear_group_id(), 219)), permutations[0][get_linear_local_id()])), // p_3->tid
        l_atomic_reduction, // l_atomic_reduction
        g_atomic_reduction, // g_atomic_reduction
        l_comm_values, // l_comm_values
        g_comm_values, // g_comm_values
    };
    c_4 = c_5;
    barrier(CLK_LOCAL_MEM_FENCE | CLK_GLOBAL_MEM_FENCE);
    func_1(p_3);
    barrier(CLK_LOCAL_MEM_FENCE | CLK_GLOBAL_MEM_FENCE);
    uint64_t crc64_context = 0xFFFFFFFFFFFFFFFFUL;
    int print_hash_value = 0;
    transparent_crc(p_3->v_collective, "p_3->v_collective", print_hash_value);
    transparent_crc(p_3->l_comm_values[get_linear_local_id()], "p_3->l_comm_values[get_linear_local_id()]", print_hash_value);
    transparent_crc(p_3->g_comm_values[get_linear_group_id() * 219 + get_linear_local_id()], "p_3->g_comm_values[get_linear_group_id() * 219 + get_linear_local_id()]", print_hash_value);
    result[get_linear_global_id()] = crc64_context ^ 0xFFFFFFFFFFFFFFFFUL;
}