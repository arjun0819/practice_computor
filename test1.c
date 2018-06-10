#include <stdio.h>

int main(void)
{
  int num, a = 11;

  a += a -= a * a;

  printf("%d\n", a);

  char c = 'A';
  int i = 1, j;

  j = !c && i++;
  printf("%d, %d\n", i, j);

  int l, f = 1, k = 2, g = 3;
  l = f > k && k + g;
  printf("%d", l);

  printf("\n");

  char x, y;
  scanf("x=%c, y=%c", &x, &y);
  printf("x=%c, y=%c\n", x, y);
  return 0;
}
