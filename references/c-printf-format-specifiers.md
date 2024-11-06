# C printf format specifiers

Basic Format: `%[flags][width][.precision][length]specifier`

Specifiers:

```
%d or %i    - Signed decimal integer
%u          - Unsigned decimal integer
%o          - Unsigned octal
%x          - Unsigned hexadecimal (lowercase)
%X          - Unsigned hexadecimal (uppercase)
%f          - Decimal floating point
%F          - Same as %f
%e          - Scientific notation (lowercase)
%E          - Scientific notation (uppercase)
%g          - Use %f or %e, whichever is shorter
%G          - Use %F or %E, whichever is shorter
%a          - Hexadecimal floating point (lowercase)
%A          - Hexadecimal floating point (uppercase)
%c          - Single character
%s          - String
%p          - Pointer address
%%          - Print a literal %
```

Flags:

```
-           - Left-justify (right justification is default)
+           - Force sign (+ or -) for numbers
(space)     - Insert space before positive number
#           - Add prefix: 0 for octal, 0x for hex
0           - Pad with leading zeros instead of spaces
```

Width:

```
number      - Minimum number of characters to print
*           - Width is given as additional argument
```

Precision:

```
.number     - For integers: minimum digits to print
              For float: decimal places after point
              For strings: maximum characters to print
.*          - Precision is given as additional argument
```

Length Modifiers:

```
h           - short int (e.g., %hd)
hh          - signed char (e.g., %hhd)
l           - long int (e.g., %ld)
ll          - long long int (e.g., %lld)
j           - intmax_t (e.g., %jd)
z           - size_t (e.g., %zd)
t           - ptrdiff_t (e.g., %td)
L           - long double (e.g., %Lf)
```

Common Examples:

```c
printf("%d", 42);           // Simple integer: "42"
printf("%6d", 42);          // Width 6: "    42"
printf("%-6d", 42);         // Left-justified: "42    "
printf("%06d", 42);         // Zero-padded: "000042"
printf("%+d", 42);          // Show sign: "+42"
printf("%.2f", 3.14159);    // Two decimal places: "3.14"
printf("%10.2f", 3.14159);  // Width 10, 2 decimals: "      3.14"
printf("%x", 255);          // Hex: "ff"
printf("%#x", 255);         // Hex with prefix: "0xff"
printf("%08x", 255);        // Zero-padded hex: "000000ff"
printf("%.4s", "Hello");    // First 4 chars: "Hell"
printf("%*d", 5, 42);       // Width as argument: "   42"
```

Common Uses:

1. Debugging: `printf("x = %d\n", x);`
2. Formatting tables: `printf("%-10s %10d\n", name, value);`
3. Floating-point precision: `printf("%.2f\n", price);`
4. Memory addresses: `printf("%p\n", ptr);`
5. Hex dumps: `printf("%02X ", byte);`

Would you like me to elaborate on any of these format specifiers or provide more specific examples?
