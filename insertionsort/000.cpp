#include<stdio.h>

template<typename T>
void Sort(T A[], int n){
  for(int i = 1; i < n; ++i){
    T key = A[i];
    T j = i - 1;
    for(; j >= 0; --j){
      if( A[j] > key) A[j+1] = A[j];
      else break;
    }
    A[++j] = key;
  }
  return;
}


int main(void){
  int A[] = {0, 1, 2, 0, -1, -4, -5, 12, 3 , 44, -4, 33, 33, -22, 22};
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
