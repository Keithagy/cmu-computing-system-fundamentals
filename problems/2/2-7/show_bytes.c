#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
  int i;
  for (i = 0; i < len; i++) {
    printf(" %.2x", start[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  const char *s = argv[1];
  show_bytes((byte_pointer)s, strlen(s) + 1);
}
