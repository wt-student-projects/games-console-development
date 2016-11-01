
#ifndef __STRUCTS_H_
#define __STRUCTS_H_

#include <math.h>

// size: 8 bytes
template<typename T>
struct point
{
  T x;
  T y;
};

// size: 8 bytes
template<typename T>
struct range
{
  T w;
  T h;  
};

// size: 16 bytes
template<typename T>
struct region
{
  T x, y, w, h;
};

// size: 64 bytes
struct image_task
{
  unsigned long long output;
  unsigned long long input;
  unsigned int components;
  unsigned int sections;
  region<int> work;
  range<int> size;
  char unused[16];
};

typedef unsigned char byte;

template<typename T>
T clamp(T min, T max, T v)
{
    return std::max(min, std::min(v, max));
}


#endif

