/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */

#endif
// 1
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  /* XOR should set a bit if its operands satisfy neither of the two criteria:
   * - neither x nor y have the bit set
   * - both x and y have the bit set
   * */
  return (~(~x & ~y)) & (~(x & y));
}
/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  /* tmin is provided by 1, followed by zeroes for the rest of the 32-bit int.
   */
  return 1 << 31;
}
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  // works comparing x against tMax's bitfield via the XOR operator
  return !(x ^ 0x7fffffff);
}
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) { return !((x & 0xAAAAAAAA) ^ 0xAAAAAAAA); }
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) { return ~x + 1; }

/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0'
 * to '9') Example: isAsciiDigit(0x35) = 1. isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int lowerBound = x + (~0x30 + 1); // sign bit is 1 if x < 0x30
  int upperBound = 0x39 + (~x + 1); // sign bit is 1 if x > 0x39
  int sign = (lowerBound | upperBound) >>
             31; // extract sign bit; 1 if at least 1 of the above was
                 // negative (i.e., outside of range)
  return !sign;
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  // solution works because: LHS of expression
  // If x is 0, LHS evaluates to 0 while RHS evaluates to z
  // Else, LHS evalutes to y while RHS evalutes to 0
  int mask = ~(!!x) + 1; // if x == 0, mask is all `1`s; else, mask is all `0`s
  return (mask & y) | (~mask & z);
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */

int isLessOrEqual(int x, int y) {
  // key insight, if the signs are different, then x is smaller if its sign bit
  // is set (since that means it's negative), and smaller otherwise
  int signX = x >> 31;          // 0 or -1
  int signY = y >> 31;          // 0 or -1
  int diffSign = signX ^ signY; // -1 if signs differ, else 0

  /* same‑sign: safe to use sign of (x‑y) */
  int sameSignLess = ((x + (~y + 1)) >> 31) & ~diffSign;

  /* different‑sign: x negative ⇒ true */
  int diffSignLess = signX & diffSign;

  /* exactly equal */
  int equal = !(x ^ y); // already 0 / 1

  /* squeeze mask(s) to 0 / 1 and return */
  return !!(sameSignLess | diffSignLess | equal);
}
// 4
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x) {
  // key idea:  x | -x sets the sign bit to 1 UNLESS x is 0
  return ((x | (~x + 1)) >> 31) + 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  int signMask = x >> 31; // if neg, `1..1`, else `0..0`

  // flip bits of x if x is negative so we always look for first bit
  x = signMask ^ x;

  // use binary search to find first set bit
  int b16, b8, b4, b2, b1, b0;

  // remember we have made sign bit 0 through earlier normalization step
  // `isTop16BitsZero` has value 0 if top 16 bits are 0, else 1
  int isTop16BitsZero = !!(x >> 16);
  b16 = isTop16BitsZero << 4; // takes value 0 or 16
  x >>= b16; // shift x right by 0 if top 16 bits unset, or 16 otherwise

  b8 = !!(x >> 8) << 3; /* 0 or 8                      */
  x >>= b8;

  b4 = !!(x >> 4) << 2; /* 0 or 4                      */
  x >>= b4;

  b2 = !!(x >> 2) << 1; /* 0 or 2                      */
  x >>= b2;

  b1 = !!(x >> 1); /* 0 or 1                      */
  x >>= b1;

  b0 = x; /* 0 or 1 (now the LSB)        */

  /* Step 3: total bits found +1 for the sign bit                  */
  return b16 + b8 + b4 + b2 + b1 + b0 + 1;
}
// float
/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  unsigned expMask = 0x7f800000;
  unsigned signMask = 0x80000000;
  unsigned mantissaMask = ~(expMask | signMask);

  // first: check if `uf` is edge-case (exp is `1..1`)
  unsigned exp = uf & expMask;
  if (!(exp ^ expMask)) {
    return uf;
  }
  // second: check if `uf` is denormalized
  unsigned sign = uf & signMask;
  if (!exp) {
    unsigned nonSign = uf & ~signMask;
    return sign | (nonSign << 1);
  }
  // if we get here, `uf` is normalized; scale 2 by adding 1 to exp
  unsigned newExp = exp + (1 << 23);

  // if scalling results in `newExp` of `1..1` mantissa should be set to 0 to
  // encode +/-`inf`
  if (!(newExp ^ expMask)) {
    return sign | expMask;
  }
  unsigned mantissa = uf & mantissaMask;
  return sign | newExp | mantissa; // return result
}
/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  const unsigned EXP_MASK = 0x7f800000;
  const unsigned SIGN_MASK = 0x80000000;
  const unsigned FRAC_MASK = 0x007fffff;
  const unsigned INT_MIN_U = 0x80000000u;
  const unsigned INT_MAX_U = 0x7fffffffu;

  unsigned exp = uf & EXP_MASK;
  unsigned sign = uf & SIGN_MASK;

  /* 1.  NaN / ±∞  ----------------------------------------------------- */
  if (exp == EXP_MASK) /* all 1s in exponent field   */
  {
    unsigned frac = uf & FRAC_MASK;
    if (frac == 0) {
      // infinity
      return sign ? INT_MIN_U : INT_MAX_U; /*  –∞ ⇒ INT_MIN, +∞/NaN ⇒ MAX */
    }
    // NaN
    return 0;
  }
  /* 2.  Unbias the exponent                                            */
  int E = (int)(exp >> 23) - 127; /* true exponent              */
  if (E < 0)                      /* |f| < 1  (incl. denormals) */
    return 0;

  /* 3.  Overflow check (E ≥ 31 ⇒ |value| ≥ 2³¹) ----------------------- */
  if (E >= 31)                           /* cannot fit into 32‑bit int */
    return sign ? INT_MIN_U : INT_MAX_U; /* saturate ↑/↓ accordingly   */

  /* 4.  Build the integer value                                        */
  unsigned mant = (1 << 23) | (uf & FRAC_MASK);
  unsigned val = (E >= 23) ? mant << (E - 23) : mant >> (23 - E);

  /* 5.  Apply sign and return                                          */
  return sign ? -(int)val : (int)val;
}
/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  // denorm smallest E: -126
  // smallest non-zero float: (+/-1) * (2^-23) * 2^-126
  // i.e., +/-2^-149
  if (x < -149) {
    // too small to be represented as a denorm
    return 0;
  }
  if (x >= -149 && x < -126) {
    // can fit in denorm representation
    return (1 << (x + 149));
  }
  // values of x -126 and above require normalized representation
  // check if x overflows
  if (x > 127) {
    return 0x7f800000; // +inf
  }
  unsigned biasedExp = x + 127;
  return biasedExp << 23;
}
