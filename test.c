#!/run/current-system/sw/bin/tcc -run
 /*
;* ^^^^^^^^^ comment the above line for the scheme version ^^^^^^^^^^
;*//* _______________________________________________________________
;*    Copyright (c) 2023 Roy Pfund
;*
;* Licensed under the Apache License, Version 2.0 (the  "License");
;* you may not use this file except in compliance with the License.
;* You may obtain a copy of the License at
;*
;*     http://www.apache.org/licenses/LICENSE-2.0
;*
;* Unless required by applicable  law  or  agreed  to  in  writing,
;* software distributed under the License is distributed on an  "AS
;* IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,  either
;* express or implied. See the License for  the  specific  language
;* governing permissions and limitations under the License.
;*//* _______________________________________________________________
;*/ #include "zalloc.h" /* for zalloc() assert stdlib
;*/ #include "float_t.h" /* 8-bits  16-bits  32-bits   64-bits
;*  includes stdint.h // uint8_t uint16_t uint32_t  uint64_t
;*  math.h inttypes.h // int8_t  int16_t  int32_t   int64_t
;*  stdio.h and gives // XXXXXX  XXXXXXX  float32_t float64_t
;*  functions print_f64(x) print_f64p(&x) print_f32(x) print_f32p(&x)
;*//* _______________________________________________________________
;* gcc -O2 -m64 test.c -o test
;* gcc -m64 -O2 -std=gnu99 test.c -o test && ./test
;*
*/

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif  // STDLIB_H

#ifndef STDARG_H
#define STDARG_H
#include <stdarg.h>
#endif  // STDARG_H

/*
;*//* _______________________________________________________________
*/
int64_t main(int argc, char **argv){// *argv++ is *((char **)(argv++))
    argv++; while (*argv) printf("%s\n", *argv++); argv = argv - argc;

    return 0;
}
