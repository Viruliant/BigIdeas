/*
;* ^^^^^^^^^ comment the above line for the scheme version ^^^^^^^^^^
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
;*//* single-line Scheme-or-C-comment
;* multi-line-comment
;*/ /*C-code*/ /* comment
(display "\nThis is Scheme-Code")
;*//* _______________________________________________________________
;* 
;* "It's not the language that matters, it's the big ideas" -- Brian
;* Harvey 2013 he also gave the following Scheme/C code: *//*
;*//* Takes a BST and returns a list of the tree elements
;* between lower-bound upper-bound *//*

    (define (range bst low high)
    ;*/ List *range(BST *bst, int low, int high) {  /*
        (cond ((< (datum bst) low)
        ;*/ if (bst->datum < low) /*
            (range (right-branch bst) low high))
            ;*/ return ranget(bst->right, low, high); /*
            ((> (datum bst) high)
            ;*/ else if (bst—>datum > high) /*
            (range (left-branch bst) low high))
            ;*/ return range(bst->left, low, high); /*
            (else
            ;*/ else return /*
            (append (range (left-branch bst) low high)
            ;*/ append(range(bst->left, low, high), /*
                (cons (datum bst)
                ;*/ cons(bst->datum, /*
                    (range (right-branch bst) low high))))))
                    ;*/ range(bst->right, low, high))); } /*

;* from 3:35 to 9:55 in the video at
;* https://archive.org/details/ucberkeley_webcast_wt3Y3aXKQ0Y
;*//* _______________________________________________________________
;*
;* from 3:35 to 9:55 in the video at
;* https://archive.org/details/ucberkeley_webcast_wt3Y3aXKQ0Y
;* Courage is the middleground between foolhardiness and cowardice.
;* --Aristotle and Harvey
;*/

