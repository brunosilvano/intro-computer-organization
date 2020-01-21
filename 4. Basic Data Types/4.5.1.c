// Exercise 4.5.1
// Here is a program that simply reads characters from the keyboard until the user hits the enter (or return) key.
// Add code to the program so that it allows the user to enter up to a 32-bit integer in hexadecimal and converts the number to int format.
// Your algorithm should make use of the masking operation described above.
// The program should display the int in both hexadecimal and decimal format for the user.
// Assume that the user will not make mistakes.
// 2020-01-21: Bruno Silvano Costa

#include <stdio.h>
#include <unistd.h>

int main(void)
{
  int x;
  unsigned char aChar;

  printf("Enter an integer in hexadecimal: ");
  fflush(stdout);

  x = 0;
  read(STDIN_FILENO, &aChar, 1);
  while (aChar != '\n')
  {
    if (9 < aChar)
      aChar += 9;           // offset for chars above 9

    aChar = aChar & 0x0f;   // mask char to extract decimal value

    x = x << 4;             // make room for next digit
    x += (int)aChar;        // add digit to result

    read(STDIN_FILENO, &aChar, 1);
  }

  printf("You entered %#010x = %d (decimal)\n\n", x, x);

  return 0;
}
