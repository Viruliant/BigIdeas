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
;*/ #include "StackDeck.h" /*
;* iterators over data structures are better but we might need stdarg
;*  vaargs in order to accept command line args
;*//* _______________________________________________________________
;* gcc -O2 -m64 script2.c -o script2
;* gcc -m64 -O2 -std=gnu99 script2.c -o script2 && ./script2
;*//* _______________________________________________________________
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
;* Scheme-or-C-comment  *//*
;*//* _______________________________________________________________
*/

float64_t average( Stack* pile ) {
    float64_t sum = 0.0;
    float64_t num = pile->size;
    for(LLNode* tmp=pile->Start; tmp!=NULL; tmp=tmp->next){
        sum += tmp->data;
    }// linkedlist iteration
    return sum/num;
}

float64_t pop_average( Stack* pile ) {
    // LLNode* temp = start;
    float64_t sum = 0.0;
    float64_t num = pile->size;
    while(pile->size > 0){
        sum += popStack(pile);
    }
    return sum/num;
}

/*
;*//* _______________________________________________________________
*/
int64_t main() {
    Stack* pile = NULL;
    pushStackStart(9999.2, &pile);
    print_f64(popStack(pile));
    printf("size of pile is %"PRIu64" \n ", pile->size);

    pushStackStart(2.0, &pile);
    pushStackStart(3.0, &pile);
    pushStackStart(4.0, &pile);
    pushStackStart(5.0, &pile);

    printf("size of pile is %"PRIu64" \n ", pile->size);

    printf("Average of 2, 3, 4, 5 = ");
    print_f64(average(pile));
    printf("\n");
    printf("size of pile is %"PRIu64" \n ", pile->size);
    
    printf("Average of 2, 3, 4, 5 = ");
    print_f64(pop_average(pile));
    printf("\n");
    printf("size of pile is %"PRIu64" \n ", pile->size);

    return 0;}

///////////////////////////////////// the above code works an returns:
// size of pile is 4 
//  Average of 2, 3, 4, 5 = 3.500000000000000
// size of pile is 4 
//  Average of 2, 3, 4, 5 = 3.500000000000000
// size of pile is 0 

    //pile->size);//

