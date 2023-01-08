#include <stdio.h>
#include <hip/hip_runtime.h>
#include <rccl/rccl.h>
#include <math.h>

#define NDEV 1

int main(int argc, char* argv[])
{
  ncclComm_t comms[NDEV];

  int size = 100;
  int devs[NDEV];
  for(int i = 0; i < NDEV; i++){
      devs[i] = i;
  }

  float* hsend = (float*) malloc(size * sizeof *hsend);
  float* hrecv = (float*) malloc(size * sizeof *hrecv);

  for (int i = 0; i < size; i++) {
    hsend[i] = 1.0f;
    hrecv[i] = 0.0f;
  }

  float* sendbuff[NDEV];
  float* recvbuff[NDEV];
  hipStream_t s[NDEV];
  for (int i = 0; i < NDEV; i++) {
    hipSetDevice(i);
    hipMalloc(sendbuff + i, size * sizeof(float));
    hipMalloc(recvbuff + i, size * sizeof(float));
    hipMemcpy(sendbuff[i], hsend, size * sizeof *hsend, hipMemcpyHostToDevice);
    hipMemcpy(recvbuff[i], hrecv, size * sizeof *hrecv, hipMemcpyHostToDevice);
    hipStreamCreate(s+i);
    hipDeviceSynchronize();
  }

  ncclCommInitAll(comms, NDEV, devs);

  ncclGroupStart();
  for (int i = 0; i < NDEV; i++)
    ncclAllReduce(&sendbuff[i][0], &recvbuff[i][0], size, ncclFloat, ncclSum,
        comms[i], s[i]);
  ncclGroupEnd();


  for (int i = 0; i < NDEV; i++) {
    hipSetDevice(i);
    hipStreamSynchronize(s[i]);
  }
 
  hipSetDevice(0);
  hipMemcpy(hrecv, recvbuff[0], size * sizeof *hrecv, hipMemcpyDeviceToHost);
  hipDeviceSynchronize();
  for (int i = 0; i < size; i++) {
    if(fabsf(NDEV * hsend[i] - hrecv[i]) > 0.001f){
        printf("At entry %i\n", i);
        printf("Expected %f\n", hsend[i]);
        printf("Received %f\n", hrecv[i]);
        return EXIT_FAILURE;
    }
  }
  printf("TESTS PASSED!\n");

  for (int i = 0; i < NDEV; i++) {
    hipSetDevice(i);
    hipFree(sendbuff[i]);
    hipFree(recvbuff[i]);
  }

  for(int i = 0; i < NDEV; ++i){
      ncclCommDestroy(comms[i]);
  }

  free(hsend);
  free(hrecv);
}
