// echoDecHex.c
// Asks user to enter an unsigned integer in decimal
// and one in hexadecimal then echoes both in both formats.
// 2020-01-05: Bruno Silvano Costa

#include <stdio.h>
#include <stdint.h>

int main(void)
{
  uint32_t uInteger;
  uint32_t hexInteger;

  printf("Enter an unsigned decimal integer: ");
  scanf("%u", &uInteger);

  printf("Enter a bit pattern in hexadecimal: ");
  scanf("%x", &hexInteger);

  printf("\n");
  printf("%u is stored as %#010x\n", uInteger, uInteger);
  printf("and %#010x represents the unsigned decimal integer %d\n", hexInteger, hexInteger);

  return 0;
}
