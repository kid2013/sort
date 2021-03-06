#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

const int N = 100;

void Sort(int A[], int n, int k = N){
  assert(n > 0);
  assert(k > 0);
  int *B = (int *)malloc(sizeof(int)*n);
  assert(B != NULL);
  int *C = (int *)malloc(sizeof(int)*(k+1));
  assert(C != NULL);
  memset(C, 0,  sizeof(int)*(k+1));
  for(int i = 0; i < n; ++i)
    ++C[A[i]];
  for(int i = 1; i <=k; ++i)
    C[i] += C[i-1];
  for(int i = n-1; i >= 0; --i){
    B[--C[A[i]]] = A[i];
  }
  memcpy(A, B, sizeof(int)*n);
  free(B);
  free(C);
  return;
}






int main(void){
  int A[] = {2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2};
  int sz = sizeof(A) / sizeof(A[0]);
  printf("the primitive array is:\n");
  for(int i = 0; i < sz; ++i)
    printf("%d ",A[i]);
  printf("\nthe sorted array is:\n");
  Sort(A, sz);
  for(int i = 0; i < sz; ++i)
    printf("%d ",A[i]);
  putchar('\n');
  return 0;
}
