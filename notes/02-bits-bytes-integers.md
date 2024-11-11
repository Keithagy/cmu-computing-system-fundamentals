# Bits, Bytes and Integers

## Binary representation and relationship to hexadecimal

- 1 hex is 4 bits. A byte is 8 bits. So, 2 hexes is a byte.
- Notice that here you actually don't have a blocks of 4.
- If the total number of bits is not a multiple of 4, you should make the leftmost group be the one with fewer than 4 bits, effectively padding the number with leading zeros. Then you translate each group of bits into the corresponding hex digit.
- When a value of x is a power of 2, that is x = 2^n for some non-negative integer n, especially easy to represent in hex.
  - hex 0 is binary 0000.
  - Binary repr of a power of 2^n is just 1, followed by n zeros.
  - E.g. decimal 2048 is 2^11. Binary is 1, followed by 11 zeroes. Hex is 0x800

## Key bitwise operators derive from Boolean algebra

Bit manipulations lie at the heart of many low-level programming techniques

- Ints are usually 32 bits, even on 64-bit machine

### Example: Representing & manipulating sets

Consider the number 76543210

- Suppose you encode the presence of each digit with one bit out of a sequence of 8 bits.
- The set {0,3,5,6} is described by `01101001`.
- The set {0,2,4,6} is described by `01010101`.
  You can then find the intersection of these two sets with the AND operator, the union with the OR operator.
  The XOR operator gives you the symmetric difference and NOT operator gives you the complement of a set.
- Symmetric difference between sets A and B: set of elements in A, or in B, but not in either.

## Bitwise and Logical operators are distinct

- !0x41 => 0x00
- !0x00 => 0x01
- ~0x00 => 0xff (assuming unsigned)
- 0x69 && 0x55 => 0x01
- p && \*p (avoids null pointer access)

## Shift operators

- For right shift: difference between logical shift (fill left with 0's) and arithmetic shift (replicate most significant bit on left)
- E.g. 10100010
  - Log. >> 2 => 00101000
  - Arith. >>2 => 11101000
- Shifting by word size (e.g. 8 bits / 1 byte) or greater, OR shifting by negative value, is _undefined behavior_

## Numeric Ranges / Integer Encodings

- Unsigned Values
  - 10110 is 22
  - 16 + 4 + 2 = 22
- Two's Complement Values
  - Most significant bit has a negative value
  - 10110 is -10.
  - -16 + 4 + 2 = -10

Considering the case where you have 16 bits:

- Unsigned:
  - Minimum is 0, `00000000 00000000` => 0
  - Maximum is 65535, `11111111 11111111` => ( 2^w ) - 1
- Two's Complement:
  - Minimum is -32768, `10000000 00000000` => -(2^(w-1))
  - Maximum is 32767, `01111111 11111111` => ( 2^(w-1) ) - 1
  - -1 is `11111111 11111111`

When there is a mix of unsigned and signed in a single expression, the signed values implicitly cast (i.e the same bit pattern is reinterpreted) to unsigned

- Result: i32 max > i32 min, but i32 max U < i32 min (since i32 min is read as an unsigned bit pattern, the leading bit is read not as negative, which makes it larger that i32 max)

Numbers are laid out this way so that addition, subtraction and multiplication work the same way whether it's unsigned or laid out as two's complement.

## Endianess

- Big endian stores the most significant byte first, so that you can read a number from left to right the way you do most other things (text, decimal numbers)
- Little endian stores the least significant byte first, so that you can read a byte sequence from least significant byte to largest, the way you think about numbers (ones, tens, hundreds, and so on)
- Most of the time, when we read bit sequences (e.g. on bitwisecmd), they are represented in big-endian

## Pointer casting

- In C, a common technique to manipulate bit patterns directly is to take pointers to values, and then recast the pointers as pointers to an `uint8_t`, so that you can then print out the binary representation of that value (in hexadecimal form).
- You can

## Compiled executable encoding

- Binary code is seldom portable across different combinations of machine and OS.
- When thinking about platform compatibility, you're thinking about platform in terms of OS + instruction architecture.

## Addition + Multiplication in binary

- Signed (two's complement) vs unsigned can be reasoned about in the same way
- Signed might require one more bit than the size of the operands, but with multiplication you might need up to twice the size of the operands (because you might be squaring)
- In both cases, you just discard the extra bits in order to keep your word size.
- When you do this truncation (just discard the extraneous bits), and you combine that with the fact that the MSB in two's complement denotes a negative number, you can get signed multiplication giving numbers that overflow in unpredictable directions.

### Multiply / Divide by powers of 2 via bitwise left / right shift operator

When you want to divide by a power of 2, you can use the right-shift

- `u >> k` gives `u / 2^k`
- With unsigned numbers you use logical shift, whilst with signed numbers you use arithmetic shift
- Use addition of a bias term first to help with rounding errors
  - decimal -6 is 0b1010
  - divide by 2 gives decimal -3, which should be 0b1101 (arithmetic shift words)
  - but if you right-shift 0b1101 (-3), you get 0b1110, which is -2 (not -1, which is what you'd get if you divide and truncate the decimal)
  - This right bit loses information, the rules of division say you should always round toward zero, not towards +/- infinity.
  - So, if you first add a bias:
    - -6 / 2 = 0b1010 >> 0b1011 (add bias) >> 0b1101 (correct)
    - -3 / 2 = 0b1101 >> 0b1110 (add bias) >> 0b1111 (correct, -1)

### Negating a binary number (using two's complement representation)

Negate the number, then add one to it.

- -6 is 0b1010
- Negating that gives you 0b0101
- Adding one gives you 0b0110 (correctly, 4 + 2 = 6)
- Be wary of C's behavior of implicitly casting signed to unsigned if they clash in usage!
- Generally, you want to test your code on Tmin and Tmax to make sure you handle overflow correctly.

## Eyeballing the size of binary numbers

- 2 ^ 10 = 1024, which is roughly 10 ^ 3
- 2 ^ 20 ~= 10 ^ 6
- 2 ^ 30 ~= 10 ^ 9
- 2 ^ 40 ~= 10 ^ 12

## Things to remember

- Integer division rounds toward zero, but arithmetic shift on negative signed bitwise numbers rounds toward -infinity
- `x & (x-1)` clears the rightmost set bit of x
- Test for boundaries on signed integers
- Remember potential implicit casting of signed to unsigned
