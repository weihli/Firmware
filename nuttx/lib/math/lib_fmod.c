/*
 * Copyright (C) 2009-2011 Nick Johnson <nickbjohnson4224 at gmail.com>
 * 
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <apps/math.h>
#include <float.h>

/* If GCC/CLang builtins are available, use them */
#ifdef __GNUC__

float fmodf(float x, float div) {
	return __builtin_fmodf(x, div);
}

double fmod(double x, double div) {
	return __builtin_fmod(x, div);
}

long double fmodl(long double x, long double div) {
	return __builtin_fmodl(x, div);
}

#else

float fmodf(float x, float div) {
	float n0;

	x /= div;
	x = modff(x, &n0);
	x *= div;

	return x;
}

double fmod(double x, double div) {
	double n0;

	x /= div;
	x = modf(x, &n0);
	x *= div;

	return x;
}

long double fmodl(long double x, long double div) {
	long double n0;

	x /= div;
	x = modfl(x, &n0);
	x *= div;

	return x;
}

#endif
