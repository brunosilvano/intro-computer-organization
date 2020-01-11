// decToBin.c
// Convert an unsigned decimal to binary
// 2020-01-06: Bruno Silvano Costa

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

void *itob(uint16_t decimal)
{
  uint8_t *binary = (uint8_t *)malloc(17 * sizeof(uint8_t));
  memset(binary, '0', 16);

  uint16_t quotient = decimal;
  size_t i = 15;
  uint16_t digit;
  do
  {
    digit = quotient % 2;
    quotient /= 2;
    binary[i] = '0' + digit;
    i--;
  } while (quotient != 0);

  return binary;
}

int main(void)
{
  uint16_t input;
  void *result = {0};

  while (1)
  {
    // Get user input
    printf("Enter an unsigned decimal: ");
    // scanf("%hu", &input);
    input = 11;

    // End program if user inputs 0
    if (input == 0)
      break;

    // Convert number to binary, as a string
    result = itob(input);

    printf("Binary: %s\n", result);
  }

  free((void *)result);

  return EXIT_SUCCESS;
}
