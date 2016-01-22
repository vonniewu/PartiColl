#include <numeric>

constexpr int blocksize = 100;

__global__ void fillStuff(int *in) {
	in[threadIdx.x] = threadIdx.x;
}

__global__ void runStuff(int *in, int *out) {
	out[threadIdx.x] = in[threadIdx.x] * 2;
}

long runFill() {
	dim3 block{blocksize, 1};
	dim3 grid{1, 1};

	int *in, *out;

	cudaMalloc((void**)&in, blocksize * sizeof(int));
	cudaMalloc((void**)&out, blocksize * sizeof(int));

	fillStuff<<<grid, block>>>(in);
	runStuff<<<grid, block>>>(in, out);

	int result[blocksize];

	cudaMemcpy(result, out, blocksize, cudaMemcpyHostToDevice);

	cudaFree(in);
	cudaFree(out);
	
	return std::accumulate(result, result + blocksize, static_cast<long>(0));
}
