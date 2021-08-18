/**
 * Ques 1 to 8 of Assignment 3.
 * Aakash Singla (1910990070), 14 August 2021
 * Assignment 3 - Bits and Bytes
 */


#include <stdio.h>

int bitAnd(int x, int y) {  
    return ~(~x | ~y);
}

int bitXor(int x, int y) {
    return ((~x & y) & ~(x & ~y));
}

int bitSign(int x) {
    return (x == 0) ? 0 : ((((x >> 31) & 1) == 1) ? -1 : 1);
}

int getByte(int x, int n) {
    return (x >> 8*n & 255);
}

int conditional(int x, int y, int z) {
  /* if x != 0, subtract 1 from 0 => 0xffffffff
   * else if x = 0, subtract 1 from 1 => 0x00000000
   */
  int mask = (!x + ~0x00);

  /* if x was non-zero, mask out z, 
   * if it was zero, mask out y 
   */
  return ((~mask) & z) | ((mask) & y);
}

int logicalShift(int x, int n) {
    return ((x >> n) & ~(((1 << 31) >> n) << 1));
}

int bang(int x) {
    int minus_x = ~x + 1;
    
    int bits = (minus_x | x) >> 31; /* -1 or 0 */
    return bits + 1;
}

int invert(int x, int p, int n) {
    return  x ^ (~(~0 << n) << p);
}

int main() {
    printf("%d", bitSign(-23));

    return 0;
}
