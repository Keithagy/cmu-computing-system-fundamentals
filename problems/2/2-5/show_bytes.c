#include <stdint.h>
#include <stdio.h>

typedef uint8_t *byte_pointer;
void show_bytes_big_endian(byte_pointer start, int len) {
  for (int i = 0; i < len; i++) {
    printf(" %.2x", start[i]);
  }
  printf("\n");
}

int main() {
  int val = 0x87654321;
  byte_pointer valp = (byte_pointer)&val;
  show_bytes_big_endian(valp, 1);
  show_bytes_big_endian(valp, 2);
  show_bytes_big_endian(valp, 3);
  show_bytes_big_endian(valp, sizeof(int));
}
