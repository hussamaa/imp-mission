// --atomics 22 ---atomic_reductions ---fake_divergence ---inter_thread_comm -g 40,78,3 -l 2,39,3
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

__constant uint32_t permutations[10][234] = {
{4,95,41,13,211,218,60,194,42,33,136,17,88,5,96,68,62,166,9,15,54,135,39,36,223,130,206,158,120,161,196,153,185,176,73,198,143,69,65,11,103,35,104,140,97,152,115,162,170,163,16,81,21,29,110,187,145,0,50,72,177,213,105,151,227,216,173,25,123,92,37,220,174,141,113,47,18,117,181,61,203,229,164,172,6,71,44,64,179,45,209,224,87,75,169,127,214,146,85,139,23,150,225,114,217,124,63,122,116,76,182,180,77,190,82,154,94,168,121,106,55,144,118,222,188,148,59,38,48,186,7,155,86,230,83,2,210,183,20,43,111,171,200,90,228,132,212,98,126,147,100,93,34,205,32,24,80,129,102,31,108,119,142,201,91,133,74,208,28,19,26,157,134,193,3,159,184,189,40,67,219,58,167,191,215,8,27,149,199,165,89,138,99,233,53,70,112,51,1,78,221,30,57,125,226,14,202,10,84,137,156,56,232,66,12,192,195,204,197,128,160,49,231,101,46,79,175,109,207,131,178,22,52,107}, // permutation 0
{231,46,80,85,133,115,220,158,182,12,153,154,6,219,71,221,132,222,61,195,163,205,24,169,112,94,74,1,230,109,66,213,113,194,21,5,122,143,168,183,60,11,38,138,198,78,223,226,47,29,62,15,63,57,192,42,32,162,127,167,186,214,142,92,34,51,33,48,229,50,137,201,216,56,232,27,170,130,146,40,102,37,224,124,128,150,67,199,165,100,20,119,118,200,72,86,68,131,193,180,179,185,45,105,172,36,157,75,30,218,41,191,9,81,18,87,65,99,188,31,159,184,35,83,89,77,43,123,8,88,204,206,4,209,97,207,171,28,189,210,233,22,178,175,64,134,17,14,208,156,190,82,111,104,19,145,44,120,126,129,0,161,149,155,217,73,96,93,177,203,110,70,55,144,164,26,53,76,106,135,69,141,114,13,212,125,10,59,79,225,202,228,39,173,197,101,52,16,227,211,116,215,166,181,98,107,23,91,84,121,151,49,160,58,103,174,7,90,148,117,136,25,196,140,187,139,3,2,54,147,152,95,176,108}, // permutation 1
{84,150,5,145,111,116,101,161,222,54,146,98,128,204,221,35,57,66,94,155,148,133,227,40,177,207,157,200,224,0,108,130,170,68,82,131,217,76,195,6,144,212,165,216,166,29,175,52,12,147,50,124,8,18,213,156,226,199,39,187,96,80,196,159,182,23,56,233,107,2,27,17,151,87,112,89,99,72,79,42,19,139,179,53,218,86,137,95,13,90,167,32,78,174,214,71,232,122,77,31,121,186,67,172,220,113,14,158,140,88,229,97,33,206,192,138,223,55,197,194,61,104,142,48,168,70,193,219,102,36,188,105,141,171,64,117,91,152,20,154,126,173,11,118,34,160,127,30,164,58,103,92,162,45,115,25,135,211,225,114,49,21,46,83,41,7,143,208,69,44,75,1,100,110,136,231,190,62,178,201,65,203,38,22,163,228,215,85,59,125,198,4,37,134,205,9,149,189,210,10,3,123,119,184,183,191,15,180,43,209,153,106,28,202,109,176,129,132,230,63,24,47,169,51,74,81,185,26,60,120,181,16,93,73}, // permutation 2
{30,118,33,80,56,66,39,172,222,123,88,168,119,223,77,50,70,79,141,116,231,78,140,62,127,189,120,233,73,149,87,14,48,192,196,68,181,61,18,164,207,198,183,21,104,125,65,202,194,74,84,203,108,52,232,43,100,155,221,206,93,136,46,64,128,213,130,23,204,173,36,54,4,16,102,92,99,6,160,201,215,83,177,35,216,111,101,22,137,170,58,1,29,12,182,2,211,89,174,199,41,186,15,210,26,193,184,85,175,37,94,131,229,227,153,40,13,220,217,8,90,180,67,103,60,166,139,115,188,5,226,151,145,190,195,124,96,11,47,28,208,114,109,117,197,98,69,113,165,179,10,45,178,19,161,20,9,91,163,169,71,57,187,53,75,167,230,95,44,32,143,51,105,146,82,122,171,110,152,156,159,38,27,121,72,0,59,133,200,212,55,138,132,176,3,205,76,129,219,214,224,25,112,135,106,225,158,157,126,97,63,218,42,24,162,31,86,209,228,142,191,7,49,107,150,81,185,34,144,154,147,148,17,134}, // permutation 3
{220,230,24,78,172,71,113,190,128,61,80,21,199,39,20,150,87,225,223,140,205,43,158,28,215,134,84,219,107,48,139,213,156,29,212,31,162,117,7,218,149,92,56,118,224,75,98,68,189,66,228,89,164,15,200,70,137,166,196,50,131,100,216,141,186,193,206,231,73,109,171,38,0,124,41,94,65,59,17,229,26,91,203,74,208,214,105,226,217,195,44,85,127,135,23,197,120,191,143,157,211,96,55,112,177,227,32,114,13,125,136,174,192,178,201,119,181,53,77,179,187,152,33,51,108,183,102,138,6,110,142,170,159,47,132,14,25,3,133,69,101,63,2,165,79,10,97,57,182,37,176,160,27,72,233,122,121,76,209,90,99,188,148,103,93,145,154,163,49,95,168,5,194,42,232,1,144,202,147,115,175,106,198,153,130,82,19,155,180,221,46,4,104,36,126,116,54,34,210,185,60,167,16,86,45,8,161,22,207,30,204,58,67,18,64,151,83,222,81,35,123,111,129,173,146,12,184,52,9,62,88,40,169,11}, // permutation 4
{191,229,60,194,68,228,200,37,104,137,208,28,213,151,72,93,212,120,124,53,63,146,43,36,69,117,179,0,18,66,57,202,143,203,230,178,71,225,29,55,127,98,80,189,25,54,196,170,149,92,67,10,112,42,110,31,91,6,131,150,164,222,2,163,206,107,126,123,176,198,168,154,40,138,21,182,56,181,111,41,192,26,193,3,144,14,48,184,79,17,221,103,157,141,142,199,73,209,11,51,4,15,153,148,218,207,118,74,89,114,121,33,116,115,96,214,161,85,24,109,105,223,173,90,59,139,166,22,78,8,188,108,16,220,83,113,174,155,50,82,156,99,5,27,65,52,102,20,172,76,94,70,77,128,140,75,190,45,61,122,134,211,216,183,125,187,132,205,171,232,169,175,226,133,130,88,158,160,64,159,152,210,215,167,233,177,219,84,145,44,46,87,224,231,97,101,119,147,39,217,162,34,32,49,185,47,58,204,129,201,19,23,62,135,165,180,227,186,35,30,13,86,1,9,81,106,100,12,197,195,38,7,95,136}, // permutation 5
{201,7,97,8,88,172,71,47,180,155,130,10,148,131,32,95,81,51,21,163,85,197,232,212,0,93,144,72,13,228,192,101,202,153,31,196,149,40,226,147,137,44,1,25,64,24,200,215,127,175,120,23,136,191,19,116,48,77,98,171,210,73,39,143,151,52,104,37,57,94,115,211,36,92,17,58,75,27,9,224,34,219,225,110,35,3,133,216,60,165,2,177,124,99,218,129,146,141,86,135,128,26,194,55,80,227,83,222,56,213,6,145,22,38,91,230,14,122,167,207,16,54,193,107,66,190,30,156,118,189,62,221,214,50,164,18,11,209,183,181,53,158,161,152,15,43,111,139,61,162,132,126,174,33,79,103,45,84,187,185,205,113,20,63,188,74,89,112,142,106,150,138,178,199,233,182,168,173,179,28,223,100,166,203,76,69,105,134,176,59,41,78,184,204,108,154,82,46,119,109,208,96,70,102,49,186,114,160,67,217,42,220,4,157,123,229,125,121,170,159,231,68,195,198,29,117,169,65,12,90,5,87,206,140}, // permutation 6
{113,102,210,95,177,11,151,60,158,17,33,29,110,96,58,41,166,168,120,171,184,111,182,55,218,47,181,75,195,20,155,206,67,136,191,146,86,137,68,45,160,83,65,116,13,37,112,72,28,57,18,126,173,9,216,175,69,0,205,40,105,6,232,225,196,201,138,5,139,107,70,199,190,179,156,51,180,62,214,30,148,217,36,88,159,215,170,198,106,188,56,61,150,149,209,92,115,71,119,135,165,8,178,157,94,24,108,186,1,77,133,82,81,91,43,174,228,204,16,213,101,230,109,12,76,4,142,19,127,200,185,227,164,38,34,229,197,169,52,100,90,49,53,74,87,54,59,192,141,161,128,23,211,189,50,219,176,202,122,79,140,44,63,35,231,162,99,97,89,39,145,31,194,134,104,144,130,226,224,208,117,25,222,3,163,98,26,123,221,223,143,21,183,207,93,22,84,2,131,114,233,85,66,14,152,220,121,153,118,167,125,129,15,73,154,132,32,42,187,147,172,103,203,80,124,48,64,10,212,78,46,7,27,193}, // permutation 7
{220,19,190,61,204,72,131,20,39,63,114,78,199,207,133,99,154,77,206,200,179,0,105,120,50,124,34,173,76,195,102,119,52,209,181,85,183,222,2,218,122,33,215,229,3,62,71,68,60,175,58,7,40,17,43,74,213,159,118,88,184,231,96,1,75,90,185,182,187,208,132,216,100,97,36,79,111,178,66,5,83,153,26,134,196,157,84,150,233,186,160,4,95,59,138,42,41,28,155,92,232,202,135,226,11,48,156,140,94,108,125,14,146,38,210,89,91,13,205,174,31,225,70,104,171,136,109,21,126,22,65,167,117,228,144,227,166,149,82,16,214,113,115,169,193,106,110,163,189,194,180,137,81,93,123,197,80,203,151,23,172,12,127,224,192,139,37,211,165,141,47,44,164,67,221,18,87,86,51,212,170,46,56,129,15,219,230,8,107,27,147,69,177,176,168,161,53,143,64,158,24,9,223,57,121,35,188,73,98,148,142,6,54,162,128,152,101,45,130,201,116,30,10,217,32,191,25,49,55,103,29,112,198,145}, // permutation 8
{87,187,105,182,124,32,129,119,125,147,199,39,208,59,211,226,220,186,178,224,152,127,82,228,26,114,130,17,77,99,55,202,196,102,193,53,95,216,36,150,89,0,222,94,115,191,60,93,8,80,223,159,34,156,103,19,69,158,108,176,110,28,18,210,206,229,92,138,49,7,38,171,183,184,10,117,204,75,179,83,197,212,16,12,132,3,221,118,51,131,15,24,231,50,233,23,153,148,174,192,2,122,149,201,195,96,48,91,189,11,137,41,218,217,100,56,104,13,215,232,37,71,146,14,214,209,142,6,43,180,68,151,128,181,1,136,64,205,177,35,207,133,225,76,173,139,47,165,213,160,33,101,172,81,29,111,97,63,44,140,4,203,5,58,194,167,46,169,135,121,66,70,21,185,30,154,40,134,20,144,84,62,126,98,27,166,162,22,163,52,175,143,161,67,170,61,65,123,157,57,230,79,74,42,85,107,168,120,86,113,155,198,164,106,45,219,72,141,78,9,227,73,25,54,109,90,88,31,116,188,112,145,200,190} // permutation 9
};

// Seed: 3095339498

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
int32_t  func_1(struct S5 * p_3);


/* --- FUNCTIONS --- */
/* ------------------------------------------ */
/* 
 * reads :
 * writes:
 */
int32_t  func_1(struct S5 * p_3)
{ /* block id: 4 */
    int32_t l_2 = 0x1ADB2BC4L;
    return l_2;
}


__kernel void entry(__global ulong *result, __global volatile uint *g_atomic_input, __global volatile uint *g_special_values, __global volatile int *g_atomic_reduction, __global int *sequence_input, __global long *g_comm_values) {
    int i;
    __local volatile uint32_t l_atomic_reduction[1];
    if (get_linear_local_id() == 0)
        for (i = 0; i < 1; i++)
            l_atomic_reduction[i] = 0;
    __local int64_t l_comm_values[234];
    if (get_linear_local_id() == 0)
        for (i = 0; i < 234; i++)
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
        (safe_add_func_uint32_t_u_u((safe_mul_func_uint32_t_u_u(get_linear_group_id(), 234)), permutations[0][get_linear_local_id()])), // p_3->tid
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
    transparent_crc(p_3->g_comm_values[get_linear_group_id() * 234 + get_linear_local_id()], "p_3->g_comm_values[get_linear_group_id() * 234 + get_linear_local_id()]", print_hash_value);
    result[get_linear_global_id()] = crc64_context ^ 0xFFFFFFFFFFFFFFFFUL;
}
