#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

template<typename T>
// A[p]...A[m-1]  A[m]...A[q-1]
void merge(T A[], int p, int m, int q){
  int a = m - p;
  int b = q - m;
  int *L = (int *)malloc(sizeof(int)*a);
  assert( L != NULL);
  int *R = (int *)malloc(sizeof(int)*b);
  assert( R != NULL);
  for(int i = 0; i < a; ++i)
    L[i] = A[p+i];
  for(int j = 0; j < b; ++j)
    R[j] = A[m+j];
  int k = p, i = 0, j = 0;
  while((i < a) && (j < b)){
    if(L[i] <= R[j]) A[k++] = L[i++];
    else A[k++] = R[j++];
}
  while(i < a) A[k++] = L[i++];
  while(j < b) A[k++] = R[j++];
  free(L);
  free(R);
  return;
}

template<typename T>
// A[p]...A[q-1]
void recursive_merge(T A[], int p, int q){
  if(p < q-1){
    int m = p + ((q-p)>>1);
    recursive_merge(A, p, m);
    recursive_merge(A, m, q);
    merge(A, p, m, q);
  }
  return;
}

template<typename T>
//A[0]...A[n-1]
void Sort(T A[], int n){
  recursive_merge(A, 0, n);
  return;
}


int main(void){
  int A[] = {0, 1, 2, 0, 1, 4, 5, 12, 3 , 44, 4, 33, 33, 22, 22};
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
