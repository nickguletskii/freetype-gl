/* ============================================================================
 * Freetype GL - A C OpenGL Freetype engine
 * Platform:    Any
 * WWW:         https://github.com/rougier/freetype-gl
 * ----------------------------------------------------------------------------
 * Copyright 2011,2012 Nicolas P. Rougier. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY NICOLAS P. ROUGIER ''AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL NICOLAS P. ROUGIER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are
 * those of the authors and should not be interpreted as representing official
 * policies, either expressed or implied, of Nicolas P. Rougier.
 * ============================================================================
 */
#include <string.h>
#include "platform.h"

#if defined(_WIN32) || defined(_WIN64)

#include <math.h>

#if !defined(_MSC_VER) || _MSC_VER < 1800
double round (double v)
{
	return (v > 0.0) ? floor(v + 0.5) : ceil(v - 0.5);
}
#endif // _MSC_VER < 1800
#endif
size_t ftgl_strnlen(const char *str, size_t n)
{
    size_t i = 0;
    for(; i < n && str[i]; i++);
    return i;
}
char* ftgl_strndup(const char *str, size_t n) {
	size_t len = ftgl_strnlen(str, n);
	char *new_str = (char*) malloc(len + 1);

	if (new_str == NULL) {
		return NULL;
	}

	new_str[len] = '\0';
	return (char*) memcpy(new_str, str, len);
}
char* ftgl_strdup(const char *str) {
	size_t len = strlen(str) + 1;
	void *new_str = malloc(len);

	if (new_str == NULL){
		return NULL;
	}

	return (char*) memcpy(new_str, str, len);
}
