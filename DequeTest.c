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
*/

float64_t average( Deque* deck ) {
    float64_t sum = 0.0;
    float64_t num = deck->size;
    for(DLLNode* tmp=deck->Start; tmp!=NULL; tmp=tmp->next){//->next or prev
        sum += (tmp->data);//do something with data
    }
    return sum/num;
}

float64_t popStart_average( Deque* deck ) {
    // DLLNode* temp = start;
    float64_t sum = 0.0;
    float64_t num = deck->size;
    while(deck->size > 0){
        sum += popStart(&deck);
    }
    return sum/num;
}

float64_t popEnd_average( Deque* deck ) {
    // DLLNode* temp = start;
    float64_t sum = 0.0;
    float64_t num = deck->size;
    while(deck->size > 0){
        sum += popEnd(&deck);
    }
    return sum/num;
}
 
/*
;*//* _______________________________________________________________
*/
int64_t main(int argc, char **argv){
    Deque* deck = NULL;
    pushEnd(2.0, &deck);
    pushEnd(3.0, &deck);
    pushEnd(4.0, &deck);
    pushEnd(5.0, &deck);
    pushStart(2.0, &deck);
    pushStart(3.0, &deck);
    pushStart(4.0, &deck);
    pushStart(5.0, &deck);

    printf("size of deck is %"PRIu64" \n ", deck->size);

    printf("Average of 2, 3, 4, 5 = ");
    print_f64(average(deck));
    printf("\n");
    printf("size of deck is %"PRIu64" \n ", deck->size);
    
    printf("Average of 2, 3, 4, 5 = ");
    print_f64(popStart_average(deck));
    // print_f64(popEnd_average(&deck));
    printf("\n");
    printf("size of deck is %"PRIu64" \n ", deck->size);

    return 0;
}
