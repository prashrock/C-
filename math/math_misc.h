#ifndef _MATH_MISC_CPP
#define _MATH_MISC_CPP
#include <iostream>          /* std::cout                    */
#include <iomanip>           /* std::setw                    */
#include <cmath>             /* pow                          */
#include <cassert>           /* assert                       */
#include <algorithm>         /* std::max                     */
#include <vector>            /* std:vector                   */
#include <cstdint>           /* uint8_t                      */

/* In LE Machine order, we need to print in reverse order of *
 * computation.                                              */
template<typename T1=uint8_t>
static inline void bigint_print(std::vector<uint8_t> &bigint)
{
	/* unsigned typecast is required mainly for uint8_t type */
    for(int i = bigint.size()-1; i >= 0; i--)
		std::cout << unsigned(bigint[i]);
    std::cout << '\n';
}

/* Multiply a regular integer (unsigned/int/long/etc) to a   *
 * previously stored big-integer. This can even be 1         *
 * The result is stored in the input bigint itself           */
template<typename T1=uint8_t, typename T2=unsigned, unsigned base=10>
static inline void bigint_multiply(std::vector<T1> &res, T2 mul)
{
	unsigned i = 0, carry = 0;  /* Initialize carry and loop */
	for(i = 0; i < res.size(); ++i) {
		T2 prod = res[i] * mul + carry;
		res[i]  = prod % base;  /* Store last # in vector    */
		carry   = prod / base;  /* Update carry accordingly  */
	}
	/* Add Carry to end of result vector                     */
	while(carry) {
		res.push_back(carry % base);
		carry   = carry / base;
	}
}

/* Create & return a Bigint datatype given a regular integer */
template<typename T1=uint8_t, typename T2=unsigned>
static inline std::vector<T1> bigint(T2 val)
{
	std::vector<T1> v {1};
	bigint_multiply(v, val);
	return v;
}

/* Test code for bigint

void factorial(unsigned n)
{
	auto result = bigint(1);
	if(n == 0) cout << "0" << endl;
	else {
		while(n)
			bigint_multiply(result, n--);
		bigint_print(result);
	}
}
*/

#endif //_MATH_MISC_CPP
