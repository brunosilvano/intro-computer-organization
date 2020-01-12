// Exercise 2.16.3
// Write a C program that prompts the user to enter a line of text on the keyboard then echoes the entire line.
// The program should continue echoing each line until the user responds to the prompt by not entering any text and hitting the return key.
// Your program should have two functions, writeStr and readLn, in addition to the main function.
// The text string itself should be stored in a char array in main. Both functions should operate on NUL-terminated text strings.
//
// - writeStr takes one argument, a pointer to the string to be displayed, and it returns the number of characters actually displayed.
// It uses the write system call function to write characters to the screen.
//
// -readLn takes two arguments, one that points to the char array where the characters are to be stored and
// one that specifies the maximum number of characters to store in the char array.
// Additional keystrokes entered by the user should be read from the OS input buffer and discarded.
// readLn should return the number of characters actually stored in the char array. It should not store the newline character ‘\n’.
// It uses the read system call function to read characters from the keyboard.
//
// 2020-01-11: Bruno Silvano Costa

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// Helper functions
size_t writeStr(char *str);
size_t readLn(char *pDestination, size_t maxChars);

// Main
int main(void)
{
  char buffer[10];          // input buffer
  char *pBuffer = buffer;
  size_t nReadChars = -1;   // number of read chars

  // Prompt user for input until empty text is given
  while (nReadChars)
  {
    write(STDOUT_FILENO, "Enter a line: ", 14);
    nReadChars = readLn(pBuffer, (sizeof(buffer) / sizeof(buffer[0])) - 1);

    // Echo the input line to the user
    write(STDOUT_FILENO, "You entered: ", 13);
    writeStr(buffer);
  }

  return 0;
}

// Print a string
// Uses the `write` system call function.
// Returns the number of printed chars.
size_t writeStr(char *str)
{
  size_t strLength = strlen(str);
  char newlineChar = '\n';

  write(STDOUT_FILENO, str, strLength);   // print input string
  write(STDOUT_FILENO, &newlineChar, 1);  // print newline char

  return strLength;
}

// Read a line from user input and store it in an array
// Uses the `read` system call function.
// Returns the number of stored chars.
size_t readLn(char *pDestination, size_t maxChars)
{
  size_t nChars = 0;
  char buffer;

  read(STDIN_FILENO, &buffer, 1);
  while (buffer != '\n')
  {
    if (++nChars <= maxChars)
      *(pDestination++) = buffer;

    read(STDIN_FILENO, &buffer, 1);
  }

  *pDestination = '\0';   // switch last char to NUL char

  return nChars;
}
