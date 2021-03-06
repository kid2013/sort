#include<cstdio>
#include<algorithm>

using namespace std;

template<typename T>
void Sort(T A[], int n){
  bool flag = false;
  for(int i = n-1; i > 0; --i){
    if(flag) return;
    flag = true;
    for(int j = 0; j < i; ++j)
      if(A[j] > A[j+1]) {
	std::swap(A[j], A[j+1]);
	flag = false;
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
