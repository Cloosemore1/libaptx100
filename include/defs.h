#pragma once

using _BYTE  = unsigned char;
using _WORD  = unsigned short;
using _DWORD = unsigned int;
using _QWORD = unsigned long long;

#define LOBYTE(x)   BYTE_AT(x, 0)
#define HIBYTE(x)   BYTE_AT(x, 1)

#define BYTE1(x)    BYTE_AT(x, 1)
#define BYTEn(x,n)  BYTE_AT(x, (n))

#define LOWORD(x)   WORD_AT(x, 0)
#define HIWORD(x)   WORD_AT(x, 2)

#define LODWORD(x)  DWORD_AT(x, 0)
#define HIDWORD(x)  DWORD_AT(x, 4)

#define SLOBYTE(x)  static_cast<int8_t>(LOBYTE(x))
#define SHIBYTE(x)  static_cast<int8_t>(HIBYTE(x))

#define SLOWORD(x)  static_cast<int16_t>(LOWORD(x))
#define SHIWORD(x)  static_cast<int16_t>(HIWORD(x))

#define SLODWORD(x) static_cast<int32_t>(LODWORD(x))
#define SHIDWORD(x) static_cast<int32_t>(HIDWORD(x))

#define BYTEn(x,n) BYTE_AT(x, (n))

#define __PAIR64__(hi, lo) ((uint64_t)(uint32_t)(hi) << 32 | (uint64_t)(uint32_t)(lo))
