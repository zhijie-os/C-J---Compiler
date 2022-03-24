















   .data
   .align 2
_havechar:    .space 4

   .data
   .align 2
_char:    .space 4

   .data
   .align 2
_havetoken:    .space 4

   .data
   .align 2
_token:    .space 4

   .data
   .align 2
attr:    .space 4

   .data
   .align 2
EOF:    .space 4

   .data
   .align 2
TK_EOF:    .space 4

   .data
   .align 2
TK_EOLN:    .space 4

   .data
   .align 2
TK_NUMBER:    .space 4

   .data
   .align 2
TK_ADD:    .space 4

   .data
   .align 2
TK_SUB:    .space 4

   .data
   .align 2
TK_MUL:    .space 4

   .data
   .align 2
TK_DIV:    .space 4

   .data
   .align 2
TK_LPAREN:    .space 4

   .data
   .align 2
TK_RPAREN:    .space 4

   .data
   .align 2
ASCII_0:    .space 4

   .data
   .align 2
ASCII_9:    .space 4

   .data
   .align 2
ASCII_PLUS:    .space 4

   .data
   .align 2
ASCII_MINUS:    .space 4

   .data
   .align 2
ASCII_STAR:    .space 4

   .data
   .align 2
ASCII_SLASH:    .space 4

   .data
   .align 2
ASCII_LPAREN:    .space 4

   .data
   .align 2
ASCII_RPAREN:    .space 4

   .data
   .align 2
ASCII_SPACE:    .space 4

   .data
   .align 2
ASCII_TAB:    .space 4

   .data
   .align 2
ASCII_CR:    .space 4

   .data
   .align 2
ASCII_NL:    .space 4

  .text
  .globl main

main:
  li  $v0,10
  syscall

