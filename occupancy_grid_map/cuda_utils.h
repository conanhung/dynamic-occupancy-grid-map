#pragma once

#include "cuda_runtime.h"
#include <stdio.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

#define CHECK_ERROR(ans) { checkError((ans), __FILE__, __LINE__); }


__device__ void checkError(cudaError_t code, const char* file, int line)
{
	if (code != cudaSuccess)
	{
		printf("GPU Kernel Error: %s %s %d\n", cudaGetErrorString(code), file, line);
	}
}

static inline int divUp(int total, int grain)
{
	return (total + grain - 1) / grain;
}