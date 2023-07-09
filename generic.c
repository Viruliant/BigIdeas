#!/run/current-system/sw/bin/tcc -run
 /*
;* ^^^^^^^^^ comment the above line for the scheme version ^^^^^^^^^^
;*//* _______________________________________________________________
;*
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
;*
;*//* _______________________________________________________________
;*/ #include "float_t.h" /* 8-bits  16-bits  32-bits   64-bits
;*  includes stdint.h // uint8_t uint16_t uint32_t  uint64_t
;*  math.h inttypes.h // int8_t  int16_t  int32_t   int64_t
;*  stdio.h and gives // XXXXXX  XXXXXXX  float32_t float64_t
;*  functions print_f64(x) print_f64p(&x) print_f32(x) print_f32p(&x)
;*  
;*/ #include "StackDeck.h" /*
;* iterators over data structures are better but we might need stdarg
;*  vaargs in order to accept command line args
;*//* _______________________________________________________________
;* gcc -O2 -m64 script2.c -o script2
;* gcc -m64 -O2 -std=gnu99 script2.c -o script2 && ./script2
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
// Stringizing operator (#) the stringize operator, turns the argument
// it precedes into a quoted string.
// #define makstr(s) #s
//     printf(makstr(geeksforgeeks));

// Token-pasting operator (##)
// provides a way to concatenate actual arguments during macro expansion. 
// If a parameter in the replacement text is adjacent to a ##, the 
// parameter is replaced by the actual argument, the ## and surrounding 
// white space are removed, and the result is re-scanned
/* 
float32_t float64_t int8_t int16_t int32_t int64_t 

uint8_t uint16_t uint32_t uint64_t

;* https://levelup.gitconnected.com/using-templates-and-generics-in-c-968da223154d
;* Generics are syntax components of a programming language that can
;* be reused for different types of objects.
*/

// #define FOREACH(arr, fn) \ 
//          for (size_t _ind = 0; 
//               _ind < sizeof(arr) / sizeof(arr[0]); 
//               _ind++) { \ 
//        fn(arr[_ind]); \ 
// }
// 
// #define FIELD_EQ(type, field) \
//          int FIELD_EQ_##type(const type* _obj1, const type* _obj2) \
//          {  \
//             return _obj1->field == _obj2->field; \
//          }
// 
// with this template "FIELD_EQ(point_t, x)" and "FIELD_EQ(foo_t, x)" 
// would actually produce FIELD_EQ_point_t and FIELD_EQ_foo_t 
// respectively. We can create the same function for multiple types 
// without explicitly writing out those functions multiple times.
// 
// #define OBJECT_START(name) \ 
//             struct name { \ 
//                   OBJECT_HEAD; 
// 
// #define OBJECT_END(name) }; \ 
//            typedef struct name name

/*
;*//* _______________________________________________________________
*/

int64_t main(int argc, char **argv){// *argv++ is *((char **)(argv++))
//  argv++; while (*argv) printf("%s\n", *argv++); argv = argv - argc;

/* 
float32_t float64_t int8_t int16_t int32_t int64_t 

uint8_t uint16_t uint32_t uint64_t
*/
    return 0;
}
