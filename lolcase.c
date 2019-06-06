#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 64

char flipChar(char c) {
  static int flip = 1;
  flip = !flip;

  if (c >= 'A' && c <= 'Z' && flip) {
    return c + ('z' - 'Z');
  }
  if (c >= 'a' && c <= 'z' && !flip) {
    return c - ('z' - 'Z');
  }

  return c;
}

void flipBuf(char* buffer, int cnt) {
  while (cnt--) {
    *buffer = flipChar(*buffer);
    buffer++;
  }
}

void flipStr(char* str) {
  while (*str) {
    *str = flipChar(*str);
    str++;
  }
}

int main(int argc, char** argv) {
  if (argc != 1) {
    argv++;
    argc--;
    while (argc--) {
      char* str = *(argv++);
      flipStr(str);
      printf("%s", str);
      if (argc) {
        printf(" ");
      }
    }

    return 0;
  }

  char* buffer = malloc(sizeof(char) * BUFFER_SIZE);
  int bytesRead = 0;

  while ((bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, stdin))) {
    flipBuf(buffer, bytesRead);

    fwrite(buffer, sizeof(char), bytesRead, stdout);
  }

  return 0;
}
