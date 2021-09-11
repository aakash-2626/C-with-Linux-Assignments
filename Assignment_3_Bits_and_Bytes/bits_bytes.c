/**
 * Ques 1 to 8 of Assignment 3.
 * Aakash Singla (1910990070), 14 August 2021
 * Assignment 3 - Bits and Bytes
 */

/*
/* bitAnd - x & y using only ~ and |
/* Example bitAnd(6, 5) = 4
/* Legal ops:  ~ |  
/* Max ops: 8
*/

// AB = (A' + B')'
int bitAnd(int x, int y) {  
    return ~(~x | ~y);
}


/*
/* bitXor - x ^ y using only ~ and &
/* Example bitXor(4, 5) = 1
/* Legal ops:  ~ &  
/* Max ops: 14
*/

// A^B = AB' + BA'
//     = ((AB')' (BA')')'         (A + B = (A'B')')
int bitXor(int x, int y) {
    return ~(~(~x & y) & ~(x & ~y));
}


/*
* sign - return 1 if positive, 0 if zero, and -1 if negative
* Examples: sign(130) = 1, sign(-23) = -1
* Legal ops: ! ~ & ^ | + << >>
* Max ops : 10
*/
int bitSign(int x) {
    int mask = (!x + ~(0x00));
    int msb = (x >> 31) & 1;
    int msb_mask = (!msb + ~(0x00));
    return (msb_mask) | (~msb_mask & (mask & 1));
}

/*
* getByte - extract byte n from word x
* Examples: getByte(0x12345678, 1)  = 0x56
* Legal ops: ! ~ & ^| + << >>
* Max ops: 6
*/
int getByte(int x, int n) {
    return (x >> 8*n & 255);
}


/* logicalShift - shift x to the right by n, using a logical shift
*  can assume that 0 <=n<=31
*  examples: logicalShift(0x87654321, 4) = 0x8765432
*  Legal ops:  ~ & ^ | + << >>
*  Max ops: 20
*/
int logicalShift(int x, int n) {
    return ((x >> n) & ~(((1 << 31) >> n) << 1));
}


/*
* conditional - same as x ? y : z
* example conditional (2, 4, 5) = 4
* ! ~ & ^ | + << >>
* Max ops: 16
*/
int conditional(int x, int y, int z) {
  /* if x != 0, subtract 1 from 0 => 0xffffffff
   * else if x = 0, subtract 1 from 1 => 0x00000000
   */
  int mask = (!x + ~0x00);

  /* if x was non-zero, mask out z, 
   * if it was zero, mask out y 
   */
  return ((mask) & y) | ((~mask) & z);
}


/* bang - Compute !x without using !
*  Examples: bang(3)=0, bang(0)=1
*  Legal ops: ~ & ^ | + << >>
*  Max ops: 12
*/ 
int bang(int x) {
    int minus_x = ~x + 1;
    return ((minus_x | x) >> 31) + 1;
}


/* 
/* Return x with the n bits that begin at position p inverted (i.e. turn 0 into 1 and vice versa)
/* and the rest left unchanged. Consider the indices of x to begin with the /* lower -order bit   numbered
/* Legal ops: ~ & ^ | << >>
/* as zero
*/
int invert(int x, int p, int n) {
    return  x ^ (~(~0 << n) << p);
}
