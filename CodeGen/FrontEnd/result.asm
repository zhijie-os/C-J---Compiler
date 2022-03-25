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

getc:
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp, 4
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   li    $t0, 4
   mul   $t0, $t0,0
   addu  $t0, $t0, 8
   addu  $fp, $sp, $t0
   li    $t0, 4
   mul   $t0, $t0,0
   subu  $fp, $sp, $t0


   # function teardown
   lw    $ra,0($fp)
   move  $t0, $fp
   lw    $ra, 0($fp)
   move  $sp, $t0
   jr    $ra

ungetc:
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp, 4
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   li    $t0, 4
   mul   $t0, $t0,1
   addu  $t0, $t0, 8
   addu  $fp, $sp, $t0
   li    $t0, 4
   mul   $t0, $t0,0
   subu  $fp, $sp, $t0


   # function teardown
   lw    $ra,4($fp)
   move  $t0, $fp
   lw    $ra, 4($fp)
   move  $sp, $t0
   jr    $ra

peek:
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp, 4
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   li    $t0, 4
   mul   $t0, $t0,0
   addu  $t0, $t0, 8
   addu  $fp, $sp, $t0
   li    $t0, 4
   mul   $t0, $t0,0
   subu  $fp, $sp, $t0


   # function teardown
   lw    $ra,0($fp)
   move  $t0, $fp
   lw    $ra, 0($fp)
   move  $sp, $t0
   jr    $ra

match:
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp, 4
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   li    $t0, 4
   mul   $t0, $t0,1
   addu  $t0, $t0, 8
   addu  $fp, $sp, $t0
   li    $t0, 4
   mul   $t0, $t0,0
   subu  $fp, $sp, $t0


   # function teardown
   lw    $ra,4($fp)
   move  $t0, $fp
   lw    $ra, 4($fp)
   move  $sp, $t0
   jr    $ra

scanner:
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp, 4
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   li    $t0, 4
   mul   $t0, $t0,0
   addu  $t0, $t0, 8
   addu  $fp, $sp, $t0
   li    $t0, 4
   mul   $t0, $t0,1
   subu  $fp, $sp, $t0


   # function teardown
   lw    $ra,0($fp)
   move  $t0, $fp
   lw    $ra, 0($fp)
   move  $sp, $t0
   jr    $ra

isdigit:
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp, 4
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   li    $t0, 4
   mul   $t0, $t0,1
   addu  $t0, $t0, 8
   addu  $fp, $sp, $t0
   li    $t0, 4
   mul   $t0, $t0,0
   subu  $fp, $sp, $t0


   # function teardown
   lw    $ra,4($fp)
   move  $t0, $fp
   lw    $ra, 4($fp)
   move  $sp, $t0
   jr    $ra

isspace:
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp, 4
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   li    $t0, 4
   mul   $t0, $t0,1
   addu  $t0, $t0, 8
   addu  $fp, $sp, $t0
   li    $t0, 4
   mul   $t0, $t0,0
   subu  $fp, $sp, $t0


   # function teardown
   lw    $ra,4($fp)
   move  $t0, $fp
   lw    $ra, 4($fp)
   move  $sp, $t0
   jr    $ra

parser:
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp, 4
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   li    $t0, 4
   mul   $t0, $t0,0
   addu  $t0, $t0, 8
   addu  $fp, $sp, $t0
   li    $t0, 4
   mul   $t0, $t0,1
   subu  $fp, $sp, $t0


   # function teardown
   lw    $ra,0($fp)
   move  $t0, $fp
   lw    $ra, 0($fp)
   move  $sp, $t0
   jr    $ra

E:
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp, 4
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   li    $t0, 4
   mul   $t0, $t0,0
   addu  $t0, $t0, 8
   addu  $fp, $sp, $t0
   li    $t0, 4
   mul   $t0, $t0,3
   subu  $fp, $sp, $t0


   # function teardown
   lw    $ra,0($fp)
   move  $t0, $fp
   lw    $ra, 0($fp)
   move  $sp, $t0
   jr    $ra

T:
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp, 4
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   li    $t0, 4
   mul   $t0, $t0,0
   addu  $t0, $t0, 8
   addu  $fp, $sp, $t0
   li    $t0, 4
   mul   $t0, $t0,3
   subu  $fp, $sp, $t0


   # function teardown
   lw    $ra,0($fp)
   move  $t0, $fp
   lw    $ra, 0($fp)
   move  $sp, $t0
   jr    $ra

F:
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp, 4
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   li    $t0, 4
   mul   $t0, $t0,0
   addu  $t0, $t0, 8
   addu  $fp, $sp, $t0
   li    $t0, 4
   mul   $t0, $t0,2
   subu  $fp, $sp, $t0


   # function teardown
   lw    $ra,0($fp)
   move  $t0, $fp
   lw    $ra, 0($fp)
   move  $sp, $t0
   jr    $ra

init:
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp, 4
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   li    $t0, 4
   mul   $t0, $t0,0
   addu  $t0, $t0, 8
   addu  $fp, $sp, $t0
   li    $t0, 4
   mul   $t0, $t0,0
   subu  $fp, $sp, $t0


   # function teardown
   lw    $ra,0($fp)
   move  $t0, $fp
   lw    $ra, 0($fp)
   move  $sp, $t0
   jr    $ra

