// Exercise 2.16.2
// Modify the program in Exercise 2.16.1 so that after it reads the line typed on the keyboard, it replaces the ‘\n’ character with a NUL character.
// Now you have stored the input as a C-style string, and you can echo it with:
// printf("You entered:\n%s\n", aString);
// 2020-01-11: Bruno Silvano Costa

#include <unistd.h>
#include <stdio.h>

int main(void)
{
  char buffer[200];                           // input buffer
  char *pBuffer = buffer;

  write(STDOUT_FILENO, "Enter a line: ", 14);

  read(STDIN_FILENO, pBuffer, 1);
  while ((*pBuffer) != '\n')
    read(STDIN_FILENO, ++pBuffer, 1);
  *pBuffer = '\0';                            // change last char of sequence ('/n') to NUL char ('\0')

  write(STDOUT_FILENO, "You entered: ", 13);
  pBuffer = buffer;                           // reset pBuffer to its initial position
  printf("%s\n", pBuffer);

  return 0;
}
