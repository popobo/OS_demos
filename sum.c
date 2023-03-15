#include "thread.h"

#define N 100000000

/*volatile*/ long sum = 0;

void Tsum() {
  for (int i = 0; i < N; i++) {
    sum++;
    // asm volatile("" ::: "memory");
  }
}

int main() {
  create(Tsum);
  create(Tsum);
  join();
  printf("sum = %ld\n", sum);
}
