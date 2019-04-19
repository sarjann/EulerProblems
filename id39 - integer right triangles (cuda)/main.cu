#include <iostream>
#include <math.h>
#include <algorithm>


#define N 1000

__global__ void add_vectors(int *inputs, int *outputs) {
    int num = inputs[threadIdx.x];
    int count = 0;
    for (int i = 0; i <= num; i++){
        for (int j = 0; j <= num - i; j++){
            int k = num - i - j;
                if (i*i + j*j - k*k == 0){
                    count += 1;
                }

        }
    }
    outputs[threadIdx.x] = count;
}

int main(void) {
    int *inputs;
    int *outputs;
    int *d_inputs;
    int *d_outputs;

    int size = N * sizeof(int);

    inputs = (int *)malloc(size);
    outputs = (int *)malloc(size);

    for (int i = 0; i < N; ++i){
        inputs[i] = i + 1;
    }


    cudaMalloc(&d_inputs, size);
    cudaMalloc(&d_outputs, size);

    cudaMemcpy(d_inputs, inputs, size, cudaMemcpyHostToDevice);

    add_vectors<<<1, N>>>(d_inputs, d_outputs);

    cudaMemcpy(outputs, d_outputs, size, cudaMemcpyDeviceToHost);

    cudaFree(d_inputs);
    cudaFree(d_outputs);

    for (int i = 0; i < 1000; ++i){
        std::cout << i + 1 << ": " << outputs[i] << std::endl;
    }

    std::cout << "------------" << std::endl;

    int max = 0;
    int num_max = 0;
    for (int i = 0; i < N; i++){
        if (outputs[i] > max) {
            max = outputs[i];
            num_max = i + 1;
        }
    }

    std::cout << max << std::endl;
    std::cout << num_max << std::endl;

    free(inputs);
    free(outputs);

    return 0;
}