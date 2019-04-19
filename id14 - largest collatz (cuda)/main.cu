#include <iostream>
#include <math.h>
#include <algorithm>


#define N 1000
#define N_MAX 1000000

__global__ void add_vectors(int *inputs, long *outputs) {
    int i = inputs[threadIdx.x];
    int max = i + N;

    while (i < max){
        int length = 1;
        long start = i;

        if (start == 0){
            start = 1;
        }

        while (start != 1){
            if (start % 2 == 0){
                start = start / 2;
            }
            else{
                start = 3 * start + 1;
            }
            length += 1;
        }
        outputs[i] = length;
        i += 1;
    }
}

int main(void) {
    int *inputs;
    long *outputs;
    int *d_inputs;
    long *d_outputs;

    int size = N * sizeof(int);
    int size_max = N_MAX * sizeof(long);

    inputs = (int *)malloc(size);
    outputs = (long *)malloc(size_max);

    for (int i = 0; i < N; ++i){
        inputs[i] = N*i;
    }


    cudaMalloc(&d_inputs, size);
    cudaMalloc(&d_outputs, size_max);

    cudaMemcpy(d_inputs, inputs, size, cudaMemcpyHostToDevice);

    add_vectors<<<1, N>>>(d_inputs, d_outputs);

    cudaMemcpy(outputs, d_outputs, size_max, cudaMemcpyDeviceToHost);

    cudaFree(d_inputs);
    cudaFree(d_outputs);

//    for (int i = 0; i < 10000; ++i){
//        std::cout << outputs[i] << std::endl;
//    }

    std::cout << "------------" << std::endl;

    long max = 0;
    int ind_max = 0;
    for (int i = 0; i < N_MAX + 1; i++){
        if (outputs[i] > max) {
            max = outputs[i];
            ind_max = i;
        }
    }

    std::cout << max << std::endl;
    std::cout << ind_max << std::endl;

    free(inputs);
    free(outputs);

    return 0;
}