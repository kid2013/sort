#include<stdio.h>
#include<assert.h>
#include<algorithm>
#include<stdlib.h>

using std::swap;

// A[p]...A[q-1]
template<typename T>
int partition(T A[], int p, int q){
  if(p >= (q-1)) return p;
  int i = p - 1;
  int k = q - 1;
  T pivot = A[k];
  for(int j = p; j < k; ++j){
    if(A[j] < pivot)
      swap(A[++i], A[j]);
    else if( A[j] == pivot){
      swap(A[--k], A[j--]); 
    }
  }
  if(k <= p){
    return p + ((q-p)>>1);
  }
  ++i;
  int t = q - 1;
  while((i < k) && (t >= k))
    swap(A[i++], A[t--]);
  return i;
}

//A[p]...A[q-1]
template<typename T>
void recursive_quicksort(T A[], int p, int q){
  while(p < (q-1)){  
    int m = partition(A, p, q);
    int M = p + ((q-p) >> 1);
    if(m < M){
      recursive_quicksort(A, p, m);
      p = m;	
    }
    else {
      recursive_quicksort(A, m, q);
      q = m;
    }
  }
  return; 
}

//A[0]...A[n-1]
template<typename T>
void Sort(T A[], int n){
  assert(n > 0);
  recursive_quicksort(A, 0, n);
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
