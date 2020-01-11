// Exercise 2.16.1
// Modify the program in  so that it prompts the user to enter an entire line, reads the line, then echoes the entire line.
// Read only one byte at a time from the keyboard.
// 2020-01-11: Bruno Silvano Costa

#include <unistd.h>

int main(void)
{
  char buffer[200];                           // input buffer
  char *pBuffer = buffer;

  write(STDOUT_FILENO, "Enter a line: ", 14);

  // Read user input, char by char, and store it into buffer
  read(STDIN_FILENO, pBuffer, 1);
  while ((*pBuffer) != '\n')
    read(STDIN_FILENO, ++pBuffer, 1);

  // Echo the input line to the user
  write(STDOUT_FILENO, "You entered: ", 13);
  pBuffer = buffer;                           // reset pBuffer to its initial position
  while ((*pBuffer) != '\n')
    write(STDOUT_FILENO, pBuffer++, 1);
  write(STDOUT_FILENO, pBuffer, 1);           // write last char of sequence, i.e. '\n' (newline)

  return 0;
}
