/* Display multiple representations of integer numbers:
 * - Hexadecimal (8 digits)
 * - Signed decimal
 * - Unsigned decimal
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Determines if the input string contains float markers (./e/E) */
static bool is_float_format(const char *str) {
  for (int i = 0; str[i]; i++) {
    if (str[i] == '.' || str[i] == 'e' || str[i] == 'E')
      return true;
  }
  return false;
}

/* Determines if the input string contains hex markers (x/X) */
static bool is_hex_format(const char *str) {
  for (int i = 0; str[i]; i++) {
    if (str[i] == 'x' || str[i] == 'X')
      return true;
  }
  return false;
}

/* Extract hex/decimal value from string. Returns true if successful. */
static bool get_num_val(const char *input_str, unsigned *result) {
  char *endp;
  /* Reject floating point numbers */
  if (is_float_format(input_str)) {
    return false;
  }

  /* Convert string to number */
  long long int value = strtoll(input_str, &endp, 0);

  /* Check if number fits in 32 bits */
  long long int upper_bits = value >> 31;
  if (!result || (upper_bits != 0 && upper_bits != -1 && upper_bits != 1)) {
    return false;
  }

  *result = (unsigned)value;
  return true;
}

/* Display a number in hex, signed decimal, and unsigned decimal formats */
void show_int(unsigned value) {
  printf("Hex = 0x%.8x,\tSigned = %d,\tUnsigned = %u\n", value, (int)value,
         value);
}

void usage(char *fname) {
  printf("Usage: %s val1 val2 ...\n", fname);
  printf("Values may be given in hex or decimal\n");
  exit(0);
}

int main(int argc, char *argv[]) {
  int i;
  unsigned uf;
  if (argc < 2) {
    usage(argv[0]);
  }

  for (i = 1; i < argc; i++) {
    const char *input_str = argv[i];
    if (get_num_val(input_str, &uf)) {
      show_int(uf);
    } else {
      printf("Error: '%s' is not a valid 32-bit integer\n", input_str);
    }
  }
  return 0;
}
