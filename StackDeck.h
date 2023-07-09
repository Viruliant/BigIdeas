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
;*//* _______________________________________________________________
;*/ #include "zalloc.h" /* for zalloc() assert stdlib
;*/ #include "float_t.h" /* 8-bits  16-bits  32-bits   64-bits
;*  includes stdint.h // uint8_t uint16_t uint32_t  uint64_t
;*  math.h inttypes.h // int8_t  int16_t  int32_t   int64_t
;*  stdio.h and gives // XXXXXX  XXXXXXX  float32_t float64_t
;*  functions print_f64(x) print_f64p(&x) print_f32(x) print_f32p(&x)
;*//* _______________________________________________________________
*/

#ifndef STDARG_H
#define STDARG_H
#include <stdarg.h>
#endif  // STDARG_H

typedef float64_t word;

/*
;*//* ___________________________________________________________Stack
*/
typedef struct _LLNode {
    word data;
    struct _LLNode* next;
} LLNode;

typedef struct _Stack {
    uint64_t size;
    LLNode* Start;
    LLNode* End;
} Stack;

word popStack(Stack* pile);
void pushStackStart(word x, Stack** pile);
void pushStackEnd(word x, Stack** pile);
/*
;*//* ___________________________________________________________Deque
*/

typedef struct _DLLNode {
    word data;
    struct _DLLNode* next;
    struct _DLLNode* prev;
} DLLNode;

typedef struct _Deque {
    uint64_t size;
    DLLNode* Start;
    DLLNode* End;
} Deque;

void pushStart(word x, Deque** deck);
void pushEnd(word x, Deque** deck);
word popStart(Deque** deck);
word popEnd(Deque** deck);
// make a new deck by pushing a value to it, after it is made push will always return the same deck.
// Deque* deck = pushStart(value, &deck); // load a value onto a new deck
// pushEnd(value, &deck); // load a value onto a existing deck
// popStart(&deck); popEnd(&deck); // both return a value
// make sure "deck->size" > 0  before you pop or segfault
// A stack only push() and pop() from the start, there's no pushEnd() popEnd().

// for(DLLNode* tmp=deck->Start; tmp!=NULL; tmp=tmp->next){
//     sum += (tmp->data);//do something with data
// }
// deques can be traversed bottom to top with prev starting from End to go backwards


/*
;*//* ___________________________________________________________Stack
*/
inline LLNode* New_LLNode( word* data, LLNode* next ) {
    LLNode* new_LLNode = (LLNode*)zalloc(sizeof(LLNode));
    new_LLNode->data = *data;
    new_LLNode->next = next;
    return new_LLNode;
}
inline Stack* New_Stack() { //new empty pile // if (*pile == NULL) *pile = New_Stack();
    Stack* pile = (Stack*)zalloc(sizeof(Stack));
    pile->size = 0; pile->Start = NULL; pile->End = NULL;
    return pile;
}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^Helper Functions
word popStack(Stack* pile){
    assert(pile != NULL); // can't pop if stack isn't there
    assert(pile->size > 0); // can't pop from empty stack
    LLNode* tmp = pile->Start;
    word data_buf = tmp->data;
    (pile->Start) = (pile->Start)->next;
    free(tmp);
    (pile->size)--;
    return data_buf;
}

void pushStackStart(word x, Stack** pile) {
    if ((*pile) == NULL) *pile = New_Stack();
    LLNode* new_start = New_LLNode(&x, (*pile)->Start);
    (*pile)->Start = new_start;
    (*pile)->size++;
}

void pushStackEnd(word x, Stack** pile) {
    if (*pile == NULL) *pile = New_Stack();
    LLNode* new_end = New_LLNode(&x, NULL);
    ((*pile)->End)->next = new_end;
    (*pile)->End = new_end;
    (*pile)->size++;
}

// deleteStack(word x, Stack** pile){
//     for(LLNode* tmp=(*pile)->Start; tmp!=NULL; tmp=tmp->next){
//         LLNode* delete = tmp;
//         tmp=tmp->next
//         free(tmp);
//         sum += (tmp->data);//do something with data
//     }
// }

/*
;*//* ___________________________________________________________Deque
*/

inline DLLNode* New_DLLNode( word* data, DLLNode* next, DLLNode* prev ) {
    DLLNode* new_DLLNode = (DLLNode*)zalloc(sizeof(DLLNode));
    new_DLLNode->data = (*data);
    new_DLLNode->next = next;
    new_DLLNode->prev = prev;
    return new_DLLNode;
}

inline Deque* New_Deque() { //new empty deck // if (*deck == NULL) *deck = New_Deque();
    Deque* deck = (Deque*)zalloc(sizeof(Deque));
    deck->size = 0;
    deck->Start = NULL;
    deck->End = NULL;
    return deck;
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^Helper Functions

void pushStart(word x, Deque** deck) {
    if (*deck == NULL) *deck = New_Deque();
    // DLLNode* new_start = New_DLLNode(&x, (*deck)->Start, NULL);
    // (*deck)->Start = new_start;
    (*deck)->Start = New_DLLNode(&x, (*deck)->Start, NULL);
    (*deck)->size++;
    if ((*deck)->size > 1){
        (((*deck)->Start)->next)->prev = (*deck)->Start;
    } else (*deck)->End = (*deck)->Start;//top=bot if size=1
}

void pushEnd(word x, Deque** deck) {
    if (*deck == NULL) *deck = New_Deque();
    (*deck)->End = New_DLLNode(&x, NULL, (*deck)->End);
    (*deck)->size++;
    if ((*deck)->size > 1){
        (((*deck)->End)->prev)->next = (*deck)->End;
    } else (*deck)->Start = (*deck)->End;// top=bot if size =1
}

word popStart(Deque** deck){
    DLLNode* tmp = (*deck)->Start;
    (*deck)->Start = tmp->next;
    word data_buf = tmp->data;
    free(tmp); // tmp = NULL; // good practice to set pointer NULL after free
    ((*deck)->size)--;
    if((*deck)->size == 1) (*deck)->End = (*deck)->Start;// top=bot if size =1
    return data_buf;
}

word popEnd(Deque** deck){
    DLLNode* tmp = (*deck)->End;
    (*deck)->End = tmp->prev;
    word data_buf = tmp->data;
    free(tmp);
    ((*deck)->size)--;
    if((*deck)->size == 1) (*deck)->Start = (*deck)->End;// top=bot if size =1
    return data_buf;
}

/*
;*//* _______________________________________________________________
*/
