#include<stdio.h>
#include<algorithm>

using std::swap;

inline int left(int i){
  return (i << 1) + 1;
}
inline int right(int i){
  return (i << 1) + 2;
}

template<typename T>
// N is heapsize
void max_heapify(T A[], int N, int i){
  int largest = i;
  int l = left(i);
  int r = right(i);
  if((l < N) && (A[largest] < A[l]))
    largest = l;
  if((r < N) && (A[largest] < A[r]))
    largest = r;
  if(largest != i){
    swap(A[largest], A[i]);
    max_heapify(A, N, largest);
  }
}

template<typename T>
void build_max_heap(T A[], int N){
  for(int i = (N >> 1); i >= 0; --i)
    max_heapify(A, N, i);
}

template<typename T>
void Sort(T A[], int N){
  build_max_heap(A, N);
  for(int i = N-1; i > 0; --i){
    swap(A[i], A[0]);
    max_heapify(A, i, 0);
  }
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
