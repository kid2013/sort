#include<iostream>
#include<algorithm>

using namespace std;

template<typename T>
void Sort(T A[], int n){
  for(int i = n-1; i > 0; --i){
    int idx = 0;
    for(int j = 1; j <=i; ++j){
      if(A[idx] < A[j]){
	idx = j;
      }
      std::iter_swap(A+i, A+idx);
    }
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
