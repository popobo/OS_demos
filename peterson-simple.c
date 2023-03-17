#include "thread.h"

#define A 1
#define B 2

atomic_int nested;
atomic_long count;

void critical_section() {
  long cnt __attribute__((unused)) = atomic_fetch_add(&count, 1);
  assert(atomic_fetch_add(&nested, 1) == 0);
  atomic_fetch_add(&nested, -1);
}

int volatile x = 0, y = 0, turn = A;

void TA() {
    while (1) {
        x = 1;                  /* PC=1 */
        turn = B;               /* PC=2 */
        while (y && turn == B); /* PC=3 */
        critical_section();     /* PC=4 */
        x = 0;
    }
}

void TB() {
  while (1) {
        y = 1;                  /* PC=1 */
        turn = A;               /* PC=2 */
        while (x && turn == A) ;/* PC=3 */
        critical_section();     /* PC=4 */
        y = 0;
  }
}

int main() {
  create(TA);
  create(TB);
}
