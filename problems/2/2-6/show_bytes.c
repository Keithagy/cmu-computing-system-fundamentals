#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void show_binary(void *data, int length_bytes) {
  int *value = (int *)data;

  int total_bits = length_bytes * 8;
  int bit_position = 0;
  for (int _ = 0; bit_position < total_bits; bit_position++) {
    if (bit_position != 0 && bit_position % 8 == 0) {
      printf(" | ");
    } else if (bit_position != 0 && bit_position % 4 == 0) {
      printf(" ");
    }
    printf("%d", *value & (1 << (total_bits - bit_position - 1)) ? 1 : 0);
  }
  printf(" (%d bits)", bit_position);
}
void show_int(int x) {
  printf("%d as hex: 0x%.8x", x, x);
  printf("\n");

  printf("%d as binary: ", x);
  show_binary(&x, sizeof(int));
  printf("\n");
}
void show_float(float x) {
  // take x's address and cast it as a pointer to good ol int instead
  // This allows you to "de-interpret" the sign-bit, exponent, and mantissa
  int *p = (int *)&x;
  printf("%f as hex: 0x%.8x", x, *p);
  printf("\n");
  printf("%f as binary: ", x);
  show_binary(&x, sizeof(float));
  printf("\n");
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Error: Missing argument\n");
    return 1;
  }

  char *endptr;
  int number = (int)strtol(argv[1], &endptr, 0);
  // base 0 means strtol will auto-detect:
  // - base 16 if string starts with "0x" or "0X"
  // - base 8 if string starts with "0"
  // - base 10 otherwise

  if (*endptr != '\0') {
    printf("Error: Invalid number format\n");
    return 1;
  }
  show_int(number);
  show_float(number);
}
