/*
 * bitutil.cpp
 *
 *  Created on: 14/08/2012
 *      Author: mck
 */

#include "bitutil.h"

namespace hdt {

/** popcount array for uchars */
extern const unsigned char popcount_tab[256] = {
		0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
		1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
		1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
		2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
		1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
		2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
		2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
		3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8,
};

template<> bool bitgetHelper<4>(size_t *e, size_t p) { return (e[p/32] >> (p%32)) & 1; }
template<> bool bitgetHelper<8>(size_t *e, size_t p) { return (e[p/64] >> (p%64)) & 1; }

template<> void bitsetHelper<4>(size_t *e, size_t p) { e[p/32] |= (((size_t)1)<<(p%32)); }
template<> void bitsetHelper<8>(size_t *e, size_t p) { e[p/64] |= (((size_t)1)<<(p%64)); }

template<> void bitcleanHelper<4>(size_t *e, size_t p) { e[p/32] &= ~(((size_t)1)<<(p%32)); }
template<> void bitcleanHelper<8>(size_t *e, size_t p) { e[p/64] &= ~(((size_t)1)<<(p%64)); }

bool bitget(size_t *e, size_t p) { return bitgetHelper<sizeof(size_t)>(e, p); }
void bitset(size_t *e, size_t p) { bitsetHelper<sizeof(size_t)>(e, p); }
void bitclean(size_t *e, size_t p) { bitcleanHelper<sizeof(size_t)>(e, p); }
}
