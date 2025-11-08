/* 
 * CS:APP Data Lab 
 * 
 * <author : @Lyfmt>
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
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  // 要求我实现异或运算，只能用非和与运算 
  // 思路 : 异或,两者取反则1,否则为0 
  // 这里就是要实现两者同时为1时如何取为0
  // 4 0100 
  /* 
      4  ~ 1011   0100          target 0001
      5    0101 ~ 1010   
      &  & 0001 & 0000
         ~ 1110 ~ 1111  
            & 1110 -> ~ 0001
  */
  int u = ~(x&~y);
  int v = ~(~x&y);
  return ~(u&v);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  /* 
  target 1000 0000 0000 0000
  我需要使用这些方法实现这个,那么,我先需要取得一些相近数
  由于我的操作空间在0-255 所以我最大可以取得的空间就在后8位
  由于位运算不论个数只算一次,所以我采用位运算
  */
  return 1<<31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  /* 
  target 1 / 0
  只有最大数才能拿1,最大数的特点在哪呢
  首项为0,其它全1
  这时想到 ! 不是0 的情况 全部是 0
  如何运用这个性质应该就是关键
  所以只要让最大值 -> 0 就可以解决
  为了避免-1的干扰,放弃使用+
  只有最大值和最大负值异或能全1,其它数和最大负值异或就不可能全一
  问题是如何得到最大负值
  上一题使用了位运算,这一题得想其它办法
  所以我们的问题不是要找最大负值,而是要找一个我们能获得的基准
  如果以-1为基准,最大值和-1
  0111 1111 1111 1111 1111 1111 1111 1111 ->
  1111 1111 1111 1111 1111 1111 1111 1111
  不妨想想如何通过这个求得0 xxxxx
  "遇事不决加一层"----lyfmt
  我们对0的转化导致无论如何,tmax和-1都是一样的
  对此,我们引入一个新条件,使得其中一个为真,另一个为假
  那就是使用 ! 对tmax+1 -> tmin 
  对 -1 +1 ->0
  所以将x先+1后直接!
  然后再~ 达美 !后返回boolean,所以我们直接使用异或即可
  这样我们除了-1都是1
  就排除了-1
  NB 
  */

  int y = x+1;
  int v = !y;
  int z = !(x+y+1);
  return v^z;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  /* 
  题目要求我们在每一个奇数的位上数为1
  那么我们只需要构造1010的循环即可 *最开始的一位是第零位*
  我们拥有的是0-255
  那么1010 1010溢出了,我们只能最大0111 1111 所以我们取0101 0101 这个是 1 + 4 + 16 + 64 = 85
  那么我们只需要先取反,然后左移次,加上169,再左移,加上刚刚的数 cost 5
  得到这个全鸡最小式,我们将x与之,如果x也全鸡,那么,得到的就还是最小式
  然后将其取反,和最小式异或,得-1
  再对-1取反求!即可

  tmax     0111 1111 1111 1111 1111 1111 1111 1111
x tmax&dao 0010 1010 1010 ... 
  ~x       1101 0101 0101
  ~x^dao   0111 1111 1111 ...
  -> +1    1000 0000 0000 ...
  */
  int dao = 170;
  int dao2 = (dao<<8)|dao;
  int dao3 = (dao2<<16)|dao2;
  int y = x&dao3;
  int z = (~y^dao3)+1;

  return !z;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  /* 
  返回负数,应该是不需要处理最大负值
  正数 0*2^m + ... -> 2^m -1 
  负数 -1*2^m +.... 
  那么正数加上负数就是 2^m
  如何模拟这个2^m呢 -> 0
  就拿-1 和 1来说 如何进行转化 
  取反后,两数相加为-1
  也就是取反后和原先差负一
  x+~x = -1
  x+ ~x +1 =0;
  ~x+1就是了
  */
  return ~x+1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  /* 
  是否表示ascii是吧
  先看0x30 -> 3*16+0 = 48 -> 32 + 16 0011 0000 
      0x39 -> 0011 1001
  这该如何是好
  有变化的是后4位,前28位固定
  既然要返回1 那就是使用经典的!
  那就要想办法转化成0
  我先判断前28位是否相同,再判断后4位?
  后4位如何判断
  也就是说,我需要想办法,只让这4位数
  实则不然,如果目光只局限于这4个数,就很难使用另一个性质,负数
  我将该数转化为负数和上下限相加,只要和下限相加为负,上限相加为正,即可达成
  这里就思考如何实现了
  比如1和-1,如果直接相加,正好是0,说明我们可以直接将两数相加
  那么~x+1即为负数
  接下来就是判断其正负,由于>>是算术右移,所以第一位会保持
  只要将第一位移动31次,就是-1或者0
  然后直接!,得0即说明相加后是负数,这里我们一正一负,感觉有点危险
  若比二者大,则双负,小则双正
  若相等,相加后一个是0,比如30,对30为0取1,对39为1取0
  比如39,对30为1取0
  ok,看起来没问题
  cao,忘记移位了
  好了,出现问题了,边缘情况,如果正好与之相加溢出,那很完美的溢出改变了第一位的符号,导致误判
  知道问题在哪了,现在想想如何解决
  加一层,排除这种情况,如何解决呢
  我日牛魔
  是不是可以先缩小范围,再进行判断
  将x也纳入范围,判断x的符号
  若为负,则得1,正则得0
  那么负情况就直接消去
  正数下会出现溢出吗
  如果正数很大,取负后加上仍然是负
  很小,比如1,一直逼近到47,发现都不会有问题,都是一起进位
  确实,正数不会出现进位问题,因为高位的1成功前进,所以不会有高位溢出
  如何表示好x的正数情况,如何让正数时为1
  */
   int x1 = ~x+1;
  int y = x1 + 47 ;
  int z = x1 + 57 ;
   x = x>>31;
   y = y>>31;
   z = z>>31;
   y +=1;
   z +=1;
   y = !y;
   z = !z;
   x = !x;
  return (y^z)&x;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  return 2;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  return 2;
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  return 2;
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
  return 0;
}
//float
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
  return 2;
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
  return 2;
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
    return 2;
}
