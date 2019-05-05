#!/usr/bin/env bash
/usr/local/cuda-10.0/bin/nvcc main.cu -o main
chmod +x main
./main
rm main