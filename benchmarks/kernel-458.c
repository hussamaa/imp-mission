// --atomics 69 ---atomic_reductions ---fake_divergence ---inter_thread_comm -g 60,54,2 -l 4,27,2
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

__constant uint32_t permutations[10][216] = {
{165,22,95,82,161,203,213,194,18,89,112,54,56,119,177,176,55,76,32,87,84,2,108,175,42,70,114,71,185,211,79,205,154,35,74,27,46,209,169,15,77,156,155,206,66,115,197,208,61,117,106,113,160,187,183,188,131,150,14,162,125,159,202,90,163,41,6,78,48,100,60,94,5,196,181,33,148,210,99,143,212,91,40,139,200,75,120,49,109,24,144,137,88,63,124,12,26,158,67,142,171,36,173,116,184,104,62,215,20,179,140,135,98,198,19,3,132,28,59,182,189,47,10,34,7,37,126,199,73,190,4,146,0,96,13,121,207,105,129,191,130,192,53,29,170,193,102,25,23,204,166,147,45,136,107,8,122,110,68,128,118,30,92,86,83,152,17,127,214,58,167,178,145,149,1,103,50,134,16,39,123,186,164,11,21,85,44,168,172,57,52,38,180,51,153,133,151,81,69,201,64,80,174,138,101,157,195,141,31,43,97,111,93,9,72,65}, // permutation 0
{103,5,158,108,134,58,104,177,136,79,78,116,94,206,76,212,71,1,28,160,49,42,24,26,118,164,195,141,169,69,9,77,95,6,2,102,185,19,15,202,123,29,40,100,175,33,174,138,82,52,44,189,144,181,105,150,128,11,213,0,45,22,162,124,43,117,65,196,61,139,64,204,132,149,41,210,120,135,167,152,157,73,13,186,188,27,16,7,18,191,145,75,91,109,200,88,53,8,37,92,50,146,121,72,115,199,179,178,140,168,46,166,214,148,10,208,156,126,194,30,107,161,74,32,155,172,211,85,182,96,112,98,159,21,183,35,190,97,171,119,87,4,106,114,127,63,101,111,143,12,137,153,57,192,83,203,209,131,147,23,110,130,56,81,31,55,70,122,34,38,90,80,151,39,198,184,54,60,25,84,165,17,154,48,66,215,3,36,86,68,133,201,187,129,205,51,62,47,59,89,176,99,170,163,207,125,113,14,193,67,173,197,180,142,93,20}, // permutation 1
{132,98,2,0,91,188,33,72,209,142,112,23,150,6,96,61,67,71,52,41,79,116,54,203,53,35,195,88,81,38,110,162,146,87,40,185,95,10,15,105,159,174,170,156,108,57,128,125,5,145,100,113,106,46,183,14,152,73,140,184,64,89,119,126,208,85,163,178,90,68,155,51,36,157,27,109,48,78,93,207,39,135,181,139,97,192,115,84,206,63,151,147,22,103,141,143,18,204,158,42,11,179,25,75,201,175,3,148,16,211,1,30,127,171,193,177,59,17,199,190,210,133,69,102,34,80,82,60,62,173,92,86,215,160,65,161,123,118,129,55,49,165,43,32,77,198,138,7,202,194,182,29,196,28,26,31,8,94,101,180,47,212,104,168,44,205,122,137,130,50,4,66,114,45,131,58,191,121,134,83,12,124,213,24,214,20,164,197,107,56,149,19,166,172,9,200,111,74,21,169,154,117,186,99,76,120,189,153,144,187,136,70,167,176,37,13}, // permutation 2
{182,56,164,191,96,180,69,0,169,19,55,158,85,118,10,1,70,173,181,136,126,203,183,113,211,48,60,46,212,210,66,156,37,35,119,133,8,53,51,116,101,131,159,171,177,163,82,33,59,150,114,67,74,97,213,188,38,215,198,195,95,124,148,185,122,98,110,134,68,102,80,26,57,109,106,174,142,84,45,187,63,3,105,201,20,62,197,202,186,168,157,147,15,172,132,32,103,153,154,27,11,41,139,111,39,112,108,4,73,31,6,90,175,81,14,121,214,208,43,209,49,170,72,99,152,190,100,83,160,5,143,145,137,204,128,117,78,79,12,18,86,127,123,129,193,7,178,184,21,30,138,205,36,65,61,179,58,104,130,42,146,50,40,44,25,75,89,141,13,125,199,88,192,24,135,17,92,162,144,34,140,23,2,77,52,28,93,161,165,94,155,64,54,151,166,87,29,176,189,107,22,47,16,167,206,115,76,207,149,120,196,71,200,194,91,9}, // permutation 3
{52,83,198,176,11,70,27,1,63,160,98,120,151,47,166,92,3,146,214,158,114,187,204,29,122,48,142,14,147,173,44,199,185,101,194,165,192,113,109,97,6,106,138,102,210,143,78,110,59,15,135,203,140,188,155,174,115,16,130,206,127,152,13,129,141,111,131,145,208,76,24,66,91,184,157,0,35,18,207,159,183,2,119,116,148,96,89,156,195,37,79,88,107,81,75,67,169,108,170,31,34,123,19,32,84,41,201,68,56,71,33,9,20,186,60,69,50,55,42,39,132,162,150,153,26,175,200,212,22,144,196,177,90,215,163,182,193,72,125,197,137,134,80,51,172,180,7,17,77,30,168,73,118,65,23,213,10,61,105,36,178,103,126,53,86,128,74,112,58,121,43,133,136,161,211,45,104,94,64,93,100,62,209,99,171,190,149,167,87,49,46,181,179,8,189,40,21,191,124,139,95,5,57,4,12,25,164,28,85,117,54,205,202,82,154,38}, // permutation 4
{207,120,109,73,114,89,19,136,160,201,83,53,145,192,110,99,156,206,3,214,51,35,26,164,127,167,5,15,29,100,49,111,117,138,173,194,75,62,152,213,144,129,174,122,141,204,82,6,125,27,166,170,22,197,179,45,78,135,81,116,104,108,169,176,191,55,168,47,37,1,33,105,107,121,59,130,30,187,202,2,7,43,211,209,80,17,149,189,161,25,150,66,98,60,74,95,77,134,63,119,52,185,143,215,118,157,28,155,131,112,40,24,165,0,139,85,175,158,124,137,65,162,13,186,14,193,103,8,11,140,20,38,39,88,212,208,198,79,210,91,4,184,32,34,115,180,50,84,183,142,68,41,16,200,48,93,46,21,18,148,205,86,132,133,61,9,67,72,171,58,92,101,42,71,76,44,182,178,23,36,203,147,196,12,190,188,159,113,106,70,154,195,126,181,90,31,94,56,54,69,57,96,123,172,87,128,151,97,163,10,153,64,199,177,102,146}, // permutation 5
{29,47,45,199,125,26,55,87,85,107,100,17,40,149,179,186,159,99,62,180,5,38,158,8,56,201,148,178,103,93,139,22,153,104,111,122,162,57,195,132,133,213,193,157,182,137,49,51,20,145,53,70,144,102,114,185,191,200,80,130,89,79,192,151,88,214,82,39,123,194,94,204,43,73,42,78,105,187,183,52,14,141,147,24,76,4,54,134,15,66,28,58,160,209,143,96,135,161,50,19,198,11,1,69,67,61,203,71,121,173,46,9,171,36,41,64,12,208,91,128,92,119,138,184,95,63,127,189,165,7,126,112,60,84,35,170,13,34,150,163,120,98,23,168,108,164,37,10,172,129,113,48,86,44,154,190,27,110,212,59,124,117,140,197,205,109,169,174,30,32,6,196,90,65,116,210,136,152,118,146,175,202,18,77,0,176,25,177,156,97,166,101,115,206,21,16,68,181,74,31,33,3,155,211,167,106,2,72,207,188,215,83,75,142,81,131}, // permutation 6
{161,195,196,147,85,148,158,20,21,111,136,27,60,67,114,121,209,134,10,35,92,113,212,145,171,169,155,186,45,3,33,153,23,204,94,132,141,5,78,91,184,71,126,51,210,73,135,191,146,82,4,11,142,116,143,133,173,211,57,164,167,178,152,159,96,58,72,118,139,119,97,65,215,63,103,49,172,24,108,166,12,34,104,150,66,31,163,197,189,165,87,110,16,213,106,127,137,168,180,6,50,38,76,39,208,59,95,90,40,8,203,100,17,19,74,77,75,9,93,120,26,162,14,177,185,15,117,2,83,206,170,79,188,123,182,193,115,29,112,53,28,174,201,183,62,122,41,81,1,88,160,198,68,36,214,156,107,7,187,199,0,202,192,80,205,69,70,61,176,179,13,131,46,64,48,32,200,151,25,52,124,54,105,140,102,130,55,43,22,157,125,138,47,194,128,86,109,99,18,84,129,175,37,44,98,181,56,154,144,30,190,101,89,42,149,207}, // permutation 7
{53,213,142,100,159,55,108,116,155,152,98,95,195,138,127,80,170,63,122,191,9,54,173,70,45,102,22,43,42,215,86,37,12,65,137,99,150,200,208,176,104,106,205,35,192,172,97,17,69,168,5,212,197,183,133,190,83,141,114,87,93,75,40,123,29,188,193,96,210,178,163,24,26,177,58,88,82,166,8,125,85,4,153,203,91,2,158,31,113,128,160,134,39,107,94,76,3,105,51,32,110,73,71,57,56,62,206,211,77,171,64,162,207,209,13,149,47,38,30,140,201,202,21,179,18,44,78,132,129,157,46,67,33,146,16,189,66,151,147,10,148,165,154,81,11,180,72,161,184,175,174,156,167,185,111,196,204,131,20,120,143,59,144,112,61,187,126,164,101,15,139,60,41,135,79,90,124,214,0,186,145,68,6,36,48,19,182,115,136,181,194,103,89,84,28,198,130,7,27,1,118,199,109,34,52,74,23,117,92,49,50,14,25,121,119,169}, // permutation 8
{6,80,163,99,129,72,100,31,191,4,82,164,110,53,75,171,184,126,104,146,66,78,131,105,27,202,39,136,79,186,67,69,198,65,114,165,153,148,22,111,119,214,183,44,94,12,120,211,93,92,18,213,52,192,21,135,181,155,97,151,140,132,71,113,123,195,127,54,161,116,157,196,73,76,57,61,51,154,158,112,64,17,83,193,90,14,194,150,118,11,187,9,201,34,180,5,91,89,38,189,174,200,30,106,204,130,15,49,35,206,95,46,188,81,3,156,170,37,86,102,40,205,139,58,169,207,84,203,2,7,141,33,210,77,133,103,62,197,25,166,60,121,107,175,125,74,68,209,88,145,47,215,172,85,190,128,45,162,59,32,19,41,160,138,108,168,28,43,212,137,185,176,199,143,182,8,20,70,1,63,159,42,179,134,87,152,173,96,177,48,50,10,178,56,101,23,122,98,124,36,16,142,109,117,167,144,147,29,149,55,208,13,24,115,0,26} // permutation 9
};

// Seed: 175775306

#include "CLSmith.h"
