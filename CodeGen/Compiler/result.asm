   # Start of the predefined functions
   .text
halt:
   li    $v0, 10
   syscall
   .text
printi:
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   lw    $a0, 4($fp)
   li    $v0, 1
   syscall
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 12
   lw    $fp, 0($sp)
   jr    $ra


prints:
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   lw    $a0, 4($fp)
   li    $v0, 4
   syscall
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 12
   lw    $fp, 0($sp)
   jr    $ra


printc:
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   lw    $a0, 4($fp)
   li    $v0, 11
   syscall
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 12
   lw    $fp, 0($sp)
   jr    $ra


printb:
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   lw    $a0, 4($fp)
   li    $v0, 1
   syscall
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 12
   lw    $fp, 0($sp)
   jr    $ra


getchar:
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   li    $v0, 12
   syscall
   move  $a0, $v0
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 8
   lw    $fp, 0($sp)
   jr    $ra
   # End of predefined functions


   .text
   .globl main
main:
   # function setup
   move  $fp, $sp
   # Function Call Setup:init
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   jal   L_38


   # Function Call Setup:parser
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   subu  $sp, $sp, 4
   jal   L_12


   lw    $ra, 4($sp)
   addiu  $sp, $sp, 4
   li    $v0,10
   syscall


    .data
    .align 2
L_0:    .space 4
   .text

    .data
    .align 2
L_1:    .space 4
   .text

   # Begin of Function Declaration: getc
   .text
L_2:
   # function setup
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   # Grab ID: _havechar
   la    $t0, L_0
   lw    $a0, 0($t0)
   # ID grabbed

   # Generate IF block: L_39
   beq   $a0, 0, L_39
   # ASSIGNMENT
   # Generate Boolean: False
   li    $a0, 0

   la    $t0, L_0
   sw    $a0, 0($t0)

   # RETURN
   # Grab ID: _char
   la    $t0, L_1
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $ra, 4($sp)
   addiu  $sp, $sp, 8
   lw    $fp, 0($sp)
   jr    $ra

L_39:

   # RETURN
   # Function Call Setup:getchar
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   jal   getchar


   lw    $ra, 4($sp)
   addiu  $sp, $sp, 8
   lw    $fp, 0($sp)
   jr    $ra

   lw    $ra, 4($sp)
   addiu  $sp, $sp, 8
   lw    $fp, 0($sp)
   jr    $ra
   # End of Function Declaration:getc


   # Begin of Function Declaration: ungetc
   .text
L_3:
   # function setup
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   # Grab ID: _havechar
   la    $t0, L_0
   lw    $a0, 0($t0)
   # ID grabbed

   # Generate IF block: L_40
   beq   $a0, 0, L_40
   # Function Call Setup:prints
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_41: .asciiz "Internal error: too many ungets!\n"
     .text
   la    $a0, str_L_41

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints


   # Function Call Setup:halt
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   jal   halt


L_40:

   # ASSIGNMENT
   # Generate Boolean: True
   li    $a0, 1

   la    $t0, L_0
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Grab ID: ch
   lw    $a0, 4($fp)
   # ID grabbed

   la    $t0, L_1
   sw    $a0, 0($t0)

   lw    $ra, 4($sp)
   addiu  $sp, $sp, 12
   lw    $fp, 0($sp)
   jr    $ra
   # End of Function Declaration:ungetc


    .data
    .align 2
L_4:    .space 4
   .text

    .data
    .align 2
L_5:    .space 4
   .text

    .data
    .align 2
L_6:    .space 4
   .text

   # Begin of Function Declaration: peek
   .text
L_7:
   # function setup
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   # Grab ID: _havetoken
   la    $t0, L_4
   lw    $a0, 0($t0)
   # ID grabbed

   # Generate IF block: L_42
   beq   $a0, 0, L_42
   # RETURN
   # Grab ID: _token
   la    $t0, L_5
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $ra, 4($sp)
   addiu  $sp, $sp, 8
   lw    $fp, 0($sp)
   jr    $ra

L_42:

   # ASSIGNMENT
   # Generate Boolean: True
   li    $a0, 1

   la    $t0, L_4
   sw    $a0, 0($t0)

   # RETURN
   # ASSIGNMENT
   # Function Call Setup:scanner
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   subu  $sp, $sp, 4
   jal   L_9


   la    $t0, L_5
   sw    $a0, 0($t0)

   lw    $ra, 4($sp)
   addiu  $sp, $sp, 8
   lw    $fp, 0($sp)
   jr    $ra

   lw    $ra, 4($sp)
   addiu  $sp, $sp, 8
   lw    $fp, 0($sp)
   jr    $ra
   # End of Function Declaration:peek


   # Begin of Function Declaration: match
   .text
L_8:
   # function setup
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   # Evaluate a binary expression, return will be in $a0
   # Function Call Setup:peek
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   jal   L_7


   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: expect
   lw    $a0, 4($fp)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   sne    $a0, $t0,$a0 

   # Generate IF block: L_43
   beq   $a0, 0, L_43
   # Function Call Setup:prints
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_44: .asciiz "Error: expected "
     .text
   la    $a0, str_L_44

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints


   # Function Call Setup:printc
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Grab ID: expect
   lw    $a0, 4($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   printc


   # Function Call Setup:prints
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_45: .asciiz "\n"
     .text
   la    $a0, str_L_45

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints


   # Function Call Setup:halt
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   jal   halt


L_43:

   # ASSIGNMENT
   # Generate Boolean: False
   li    $a0, 0

   la    $t0, L_4
   sw    $a0, 0($t0)

   lw    $ra, 4($sp)
   addiu  $sp, $sp, 12
   lw    $fp, 0($sp)
   jr    $ra
   # End of Function Declaration:match


   # Begin of Function Declaration: scanner
   .text
L_9:
   # function setup
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   # Generate WHILE block: L_46, L_47, L_48
   # WHILE TEST
L_46:
   # Function Call Setup:isspace
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   # Create Actuals
   # ASSIGNMENT
   # Function Call Setup:getc
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   jal   L_2


   sw    $a0, 8($fp)

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_11


   # WHILE BODY
   beq   $a0, 0, L_48
L_47:
   b     L_46
   # WHILE END
L_48:

   # Evaluate a binary expression, return will be in $a0
   # Grab ID: ch
   lw    $a0, 4($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: EOF
   la    $t0, L_16
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   # Generate IF block: L_49
   beq   $a0, 0, L_49
   # RETURN
   # Grab ID: TK_EOF
   la    $t0, L_17
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $ra, 4($sp)
   addiu  $sp, $sp, 8
   lw    $fp, 0($sp)
   jr    $ra

L_49:

   # Evaluate a binary expression, return will be in $a0
   # Grab ID: ch
   lw    $a0, 4($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: ASCII_NL
   la    $t0, L_37
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   # Generate IF block: L_50
   beq   $a0, 0, L_50
   # RETURN
   # Grab ID: TK_EOLN
   la    $t0, L_18
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $ra, 4($sp)
   addiu  $sp, $sp, 8
   lw    $fp, 0($sp)
   jr    $ra

L_50:

   # Evaluate a binary expression, return will be in $a0
   # Grab ID: ch
   lw    $a0, 4($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: ASCII_PLUS
   la    $t0, L_28
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   # Generate IF block: L_51
   beq   $a0, 0, L_51
   # RETURN
   # Grab ID: TK_ADD
   la    $t0, L_20
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $ra, 4($sp)
   addiu  $sp, $sp, 8
   lw    $fp, 0($sp)
   jr    $ra

L_51:

   # Evaluate a binary expression, return will be in $a0
   # Grab ID: ch
   lw    $a0, 4($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: ASCII_MINUS
   la    $t0, L_29
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   # Generate IF block: L_52
   beq   $a0, 0, L_52
   # RETURN
   # Grab ID: TK_SUB
   la    $t0, L_21
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $ra, 4($sp)
   addiu  $sp, $sp, 8
   lw    $fp, 0($sp)
   jr    $ra

L_52:

   # Evaluate a binary expression, return will be in $a0
   # Grab ID: ch
   lw    $a0, 4($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: ASCII_STAR
   la    $t0, L_30
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   # Generate IF block: L_53
   beq   $a0, 0, L_53
   # RETURN
   # Grab ID: TK_MUL
   la    $t0, L_22
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $ra, 4($sp)
   addiu  $sp, $sp, 8
   lw    $fp, 0($sp)
   jr    $ra

L_53:

   # Evaluate a binary expression, return will be in $a0
   # Grab ID: ch
   lw    $a0, 4($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: ASCII_SLASH
   la    $t0, L_31
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   # Generate IF block: L_54
   beq   $a0, 0, L_54
   # RETURN
   # Grab ID: TK_DIV
   la    $t0, L_23
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $ra, 4($sp)
   addiu  $sp, $sp, 8
   lw    $fp, 0($sp)
   jr    $ra

L_54:

   # Evaluate a binary expression, return will be in $a0
   # Grab ID: ch
   lw    $a0, 4($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: ASCII_LPAREN
   la    $t0, L_32
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   # Generate IF block: L_55
   beq   $a0, 0, L_55
   # RETURN
   # Grab ID: TK_LPAREN
   la    $t0, L_24
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $ra, 4($sp)
   addiu  $sp, $sp, 8
   lw    $fp, 0($sp)
   jr    $ra

L_55:

   # Evaluate a binary expression, return will be in $a0
   # Grab ID: ch
   lw    $a0, 4($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: ASCII_RPAREN
   la    $t0, L_33
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   # Generate IF block: L_56
   beq   $a0, 0, L_56
   # RETURN
   # Grab ID: TK_RPAREN
   la    $t0, L_25
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $ra, 4($sp)
   addiu  $sp, $sp, 8
   lw    $fp, 0($sp)
   jr    $ra

L_56:

   # Function Call Setup:isdigit
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   # Create Actuals
   # Grab ID: ch
   lw    $a0, 4($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_10


   # Generate IF block: L_57
   beq   $a0, 0, L_57
   # ASSIGNMENT
   # Generate Number: 0
   li    $a0, 0

   la    $t0, L_6
   sw    $a0, 0($t0)

   # Generate WHILE block: L_58, L_59, L_60
   # WHILE TEST
L_58:
   # Function Call Setup:isdigit
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   # Create Actuals
   # Grab ID: ch
   lw    $a0, 4($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_10


   # WHILE BODY
   beq   $a0, 0, L_60
L_59:
   # ASSIGNMENT
   # Evaluate a binary expression, return will be in $a0
   # Evaluate a binary expression, return will be in $a0
   # Grab ID: attr
   la    $t0, L_6
   lw    $a0, 0($t0)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Generate Number: 10
   li    $a0, 10

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   mul    $a0, $t0,$a0 

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Evaluate a binary expression, return will be in $a0
   # Grab ID: ch
   lw    $a0, 4($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: ASCII_0
   la    $t0, L_26
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   subu    $a0, $t0,$a0 

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   addu    $a0, $t0,$a0 

   la    $t0, L_6
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Function Call Setup:getc
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   jal   L_2


   sw    $a0, 8($fp)

   b     L_58
   # WHILE END
L_60:

   # Function Call Setup:ungetc
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   # Create Actuals
   # Grab ID: ch
   lw    $a0, 4($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_3


   # RETURN
   # Grab ID: TK_NUMBER
   la    $t0, L_19
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $ra, 4($sp)
   addiu  $sp, $sp, 8
   lw    $fp, 0($sp)
   jr    $ra

L_57:

   # Function Call Setup:prints
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_61: .asciiz "Error: invalid character.\n"
     .text
   la    $a0, str_L_61

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints


   # Function Call Setup:halt
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   jal   halt


   lw    $ra, 4($sp)
   addiu  $sp, $sp, 12
   lw    $fp, 0($sp)
   jr    $ra
   # End of Function Declaration:scanner


   # Begin of Function Declaration: isdigit
   .text
L_10:
   # function setup
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   # RETURN
   # Evaluate a binary expression, return will be in $a0
   # Evaluate a binary expression, return will be in $a0
   # Grab ID: ch
   lw    $a0, 4($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: ASCII_0
   la    $t0, L_26
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   sge    $a0, $t0,$a0 

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Evaluate a binary expression, return will be in $a0
   # Grab ID: ch
   lw    $a0, 4($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: ASCII_9
   la    $t0, L_27
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   sle    $a0, $t0,$a0 

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   and    $a0, $t0,$a0 

   lw    $ra, 4($sp)
   addiu  $sp, $sp, 12
   lw    $fp, 0($sp)
   jr    $ra

   lw    $ra, 4($sp)
   addiu  $sp, $sp, 12
   lw    $fp, 0($sp)
   jr    $ra
   # End of Function Declaration:isdigit


   # Begin of Function Declaration: isspace
   .text
L_11:
   # function setup
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   # RETURN
   # Evaluate a binary expression, return will be in $a0
   # Evaluate a binary expression, return will be in $a0
   # Evaluate a binary expression, return will be in $a0
   # Grab ID: ch
   lw    $a0, 4($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: ASCII_SPACE
   la    $t0, L_34
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Evaluate a binary expression, return will be in $a0
   # Grab ID: ch
   lw    $a0, 4($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: ASCII_TAB
   la    $t0, L_35
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   or    $a0, $t0,$a0 

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Evaluate a binary expression, return will be in $a0
   # Grab ID: ch
   lw    $a0, 4($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: ASCII_CR
   la    $t0, L_36
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   or    $a0, $t0,$a0 

   lw    $ra, 4($sp)
   addiu  $sp, $sp, 12
   lw    $fp, 0($sp)
   jr    $ra

   lw    $ra, 4($sp)
   addiu  $sp, $sp, 12
   lw    $fp, 0($sp)
   jr    $ra
   # End of Function Declaration:isspace


   # Begin of Function Declaration: parser
   .text
L_12:
   # function setup
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   # Generate WHILE block: L_62, L_63, L_64
   # WHILE TEST
L_62:
   # Evaluate a binary expression, return will be in $a0
   # Function Call Setup:peek
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   jal   L_7


   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: TK_EOF
   la    $t0, L_17
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   sne    $a0, $t0,$a0 

   # WHILE BODY
   beq   $a0, 0, L_64
L_63:
   # ASSIGNMENT
   # Function Call Setup:E
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   subu  $sp, $sp, 4
   subu  $sp, $sp, 4
   subu  $sp, $sp, 4
   jal   L_13


   sw    $a0, 8($fp)

   # Function Call Setup:match
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   # Create Actuals
   # Grab ID: TK_EOLN
   la    $t0, L_18
   lw    $a0, 0($t0)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_8


   # Function Call Setup:prints
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_65: .asciiz " = "
     .text
   la    $a0, str_L_65

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints


   # Function Call Setup:printi
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Grab ID: result
   lw    $a0, 4($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   printi


   # Function Call Setup:prints
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_66: .asciiz "\n"
     .text
   la    $a0, str_L_66

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints


   b     L_62
   # WHILE END
L_64:

   lw    $ra, 4($sp)
   addiu  $sp, $sp, 12
   lw    $fp, 0($sp)
   jr    $ra
   # End of Function Declaration:parser


   # Begin of Function Declaration: E
   .text
L_13:
   # function setup
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   # ASSIGNMENT
   # Function Call Setup:T
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   subu  $sp, $sp, 4
   subu  $sp, $sp, 4
   subu  $sp, $sp, 4
   jal   L_14


   sw    $a0, 8($fp)

   # Generate WHILE block: L_67, L_68, L_69
   # WHILE TEST
L_67:
   # Evaluate a binary expression, return will be in $a0
   # Evaluate a binary expression, return will be in $a0
   # Function Call Setup:peek
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   jal   L_7


   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: TK_ADD
   la    $t0, L_20
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Evaluate a binary expression, return will be in $a0
   # Function Call Setup:peek
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   jal   L_7


   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: TK_SUB
   la    $t0, L_21
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   or    $a0, $t0,$a0 

   # WHILE BODY
   beq   $a0, 0, L_69
L_68:
   # Function Call Setup:match
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   # Create Actuals
   # ASSIGNMENT
   # Function Call Setup:peek
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   jal   L_7


   sw    $a0, 16($fp)

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_8


   # ASSIGNMENT
   # Function Call Setup:T
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   subu  $sp, $sp, 4
   subu  $sp, $sp, 4
   subu  $sp, $sp, 4
   jal   L_14


   sw    $a0, 12($fp)

   # Evaluate a binary expression, return will be in $a0
   # Grab ID: token
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: TK_ADD
   la    $t0, L_20
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   # Generate IF-ELSE block: L_70, L_71, L_72
   beq   $a0, 1, L_70
L_71:
   # ASSIGNMENT
   # Evaluate a binary expression, return will be in $a0
   # Grab ID: l
   lw    $a0, 4($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: r
   lw    $a0, 8($fp)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   subu    $a0, $t0,$a0 

   sw    $a0, 8($fp)

   b     L_72
L_70:
   # ASSIGNMENT
   # Evaluate a binary expression, return will be in $a0
   # Grab ID: l
   lw    $a0, 4($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: r
   lw    $a0, 8($fp)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   addu    $a0, $t0,$a0 

   sw    $a0, 8($fp)

L_72:

   b     L_67
   # WHILE END
L_69:

   # RETURN
   # Grab ID: l
   lw    $a0, 4($fp)
   # ID grabbed

   lw    $ra, 4($sp)
   addiu  $sp, $sp, 8
   lw    $fp, 0($sp)
   jr    $ra

   lw    $ra, 4($sp)
   addiu  $sp, $sp, 20
   lw    $fp, 0($sp)
   jr    $ra
   # End of Function Declaration:E


   # Begin of Function Declaration: T
   .text
L_14:
   # function setup
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   # ASSIGNMENT
   # Function Call Setup:F
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   subu  $sp, $sp, 4
   subu  $sp, $sp, 4
   jal   L_15


   sw    $a0, 8($fp)

   # Generate WHILE block: L_73, L_74, L_75
   # WHILE TEST
L_73:
   # Evaluate a binary expression, return will be in $a0
   # Evaluate a binary expression, return will be in $a0
   # Function Call Setup:peek
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   jal   L_7


   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: TK_MUL
   la    $t0, L_22
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Evaluate a binary expression, return will be in $a0
   # Function Call Setup:peek
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   jal   L_7


   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: TK_DIV
   la    $t0, L_23
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   or    $a0, $t0,$a0 

   # WHILE BODY
   beq   $a0, 0, L_75
L_74:
   # Function Call Setup:match
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   # Create Actuals
   # ASSIGNMENT
   # Function Call Setup:peek
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   jal   L_7


   sw    $a0, 16($fp)

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_8


   # ASSIGNMENT
   # Function Call Setup:F
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   subu  $sp, $sp, 4
   subu  $sp, $sp, 4
   jal   L_15


   sw    $a0, 12($fp)

   # Evaluate a binary expression, return will be in $a0
   # Grab ID: token
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: TK_MUL
   la    $t0, L_22
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   # Generate IF-ELSE block: L_76, L_77, L_78
   beq   $a0, 1, L_76
L_77:
   # ASSIGNMENT
   # Evaluate a binary expression, return will be in $a0
   # Grab ID: l
   lw    $a0, 4($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: r
   lw    $a0, 8($fp)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   div    $a0, $t0,$a0 

   sw    $a0, 8($fp)

   b     L_78
L_76:
   # ASSIGNMENT
   # Evaluate a binary expression, return will be in $a0
   # Grab ID: l
   lw    $a0, 4($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: r
   lw    $a0, 8($fp)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   mul    $a0, $t0,$a0 

   sw    $a0, 8($fp)

L_78:

   b     L_73
   # WHILE END
L_75:

   # RETURN
   # Grab ID: l
   lw    $a0, 4($fp)
   # ID grabbed

   lw    $ra, 4($sp)
   addiu  $sp, $sp, 8
   lw    $fp, 0($sp)
   jr    $ra

   lw    $ra, 4($sp)
   addiu  $sp, $sp, 20
   lw    $fp, 0($sp)
   jr    $ra
   # End of Function Declaration:T


   # Begin of Function Declaration: F
   .text
L_15:
   # function setup
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   # ASSIGNMENT
   # Function Call Setup:peek
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   jal   L_7


   sw    $a0, 12($fp)

   # Evaluate a binary expression, return will be in $a0
   # Grab ID: token
   lw    $a0, 8($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: TK_LPAREN
   la    $t0, L_24
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   # Generate IF-ELSE block: L_79, L_80, L_81
   beq   $a0, 1, L_79
L_80:
   # Evaluate a binary expression, return will be in $a0
   # Grab ID: token
   lw    $a0, 8($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: TK_SUB
   la    $t0, L_21
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   # Generate IF-ELSE block: L_82, L_83, L_84
   beq   $a0, 1, L_82
L_83:
   # Evaluate a binary expression, return will be in $a0
   # Grab ID: token
   lw    $a0, 8($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: TK_NUMBER
   la    $t0, L_19
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   # Generate IF-ELSE block: L_85, L_86, L_87
   beq   $a0, 1, L_85
L_86:
   # Function Call Setup:prints
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_88: .asciiz "Error: expected factor.\n"
     .text
   la    $a0, str_L_88

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints


   # Function Call Setup:halt
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   jal   halt


   b     L_87
L_85:
   # Function Call Setup:match
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   # Create Actuals
   # Grab ID: TK_NUMBER
   la    $t0, L_19
   lw    $a0, 0($t0)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_8


   # ASSIGNMENT
   # Grab ID: attr
   la    $t0, L_6
   lw    $a0, 0($t0)
   # ID grabbed

   sw    $a0, 8($fp)

L_87:

   b     L_84
L_82:
   # Function Call Setup:match
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   # Create Actuals
   # Grab ID: TK_SUB
   la    $t0, L_21
   lw    $a0, 0($t0)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_8


   # ASSIGNMENT
   # unary arithmetic -
   # Function Call Setup:F
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   subu  $sp, $sp, 4
   subu  $sp, $sp, 4
   jal   L_15


   negu  $a0, $a0

   sw    $a0, 8($fp)

L_84:

   b     L_81
L_79:
   # Function Call Setup:match
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   # Create Actuals
   # Grab ID: TK_LPAREN
   la    $t0, L_24
   lw    $a0, 0($t0)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_8


   # ASSIGNMENT
   # Function Call Setup:E
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   subu  $sp, $sp, 4
   subu  $sp, $sp, 4
   subu  $sp, $sp, 4
   jal   L_13


   sw    $a0, 8($fp)

   # Function Call Setup:match
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   # Create Actuals
   # Grab ID: TK_RPAREN
   la    $t0, L_25
   lw    $a0, 0($t0)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_8


L_81:

   # RETURN
   # Grab ID: result
   lw    $a0, 4($fp)
   # ID grabbed

   lw    $ra, 4($sp)
   addiu  $sp, $sp, 8
   lw    $fp, 0($sp)
   jr    $ra

   lw    $ra, 4($sp)
   addiu  $sp, $sp, 16
   lw    $fp, 0($sp)
   jr    $ra
   # End of Function Declaration:F


    .data
    .align 2
L_16:    .space 4
   .text

    .data
    .align 2
L_17:    .space 4
   .text

    .data
    .align 2
L_18:    .space 4
   .text

    .data
    .align 2
L_19:    .space 4
   .text

    .data
    .align 2
L_20:    .space 4
   .text

    .data
    .align 2
L_21:    .space 4
   .text

    .data
    .align 2
L_22:    .space 4
   .text

    .data
    .align 2
L_23:    .space 4
   .text

    .data
    .align 2
L_24:    .space 4
   .text

    .data
    .align 2
L_25:    .space 4
   .text

    .data
    .align 2
L_26:    .space 4
   .text

    .data
    .align 2
L_27:    .space 4
   .text

    .data
    .align 2
L_28:    .space 4
   .text

    .data
    .align 2
L_29:    .space 4
   .text

    .data
    .align 2
L_30:    .space 4
   .text

    .data
    .align 2
L_31:    .space 4
   .text

    .data
    .align 2
L_32:    .space 4
   .text

    .data
    .align 2
L_33:    .space 4
   .text

    .data
    .align 2
L_34:    .space 4
   .text

    .data
    .align 2
L_35:    .space 4
   .text

    .data
    .align 2
L_36:    .space 4
   .text

    .data
    .align 2
L_37:    .space 4
   .text

   # Begin of Function Declaration: init
   .text
L_38:
   # function setup
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   # ASSIGNMENT
   # unary arithmetic -
   # Generate Number: 1
   li    $a0, 1

   negu  $a0, $a0

   la    $t0, L_16
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Generate Number: 48
   li    $a0, 48

   la    $t0, L_26
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Generate Number: 57
   li    $a0, 57

   la    $t0, L_27
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Generate Number: 43
   li    $a0, 43

   la    $t0, L_28
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Generate Number: 45
   li    $a0, 45

   la    $t0, L_29
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Generate Number: 42
   li    $a0, 42

   la    $t0, L_30
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Generate Number: 47
   li    $a0, 47

   la    $t0, L_31
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Generate Number: 40
   li    $a0, 40

   la    $t0, L_32
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Generate Number: 41
   li    $a0, 41

   la    $t0, L_33
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Generate Number: 32
   li    $a0, 32

   la    $t0, L_34
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Generate Number: 9
   li    $a0, 9

   la    $t0, L_35
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Generate Number: 13
   li    $a0, 13

   la    $t0, L_36
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Generate Number: 10
   li    $a0, 10

   la    $t0, L_37
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Generate Number: 256
   li    $a0, 256

   la    $t0, L_17
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Generate Number: 257
   li    $a0, 257

   la    $t0, L_19
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Grab ID: ASCII_PLUS
   la    $t0, L_28
   lw    $a0, 0($t0)
   # ID grabbed

   la    $t0, L_20
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Grab ID: ASCII_MINUS
   la    $t0, L_29
   lw    $a0, 0($t0)
   # ID grabbed

   la    $t0, L_21
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Grab ID: ASCII_STAR
   la    $t0, L_30
   lw    $a0, 0($t0)
   # ID grabbed

   la    $t0, L_22
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Grab ID: ASCII_SLASH
   la    $t0, L_31
   lw    $a0, 0($t0)
   # ID grabbed

   la    $t0, L_23
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Grab ID: ASCII_LPAREN
   la    $t0, L_32
   lw    $a0, 0($t0)
   # ID grabbed

   la    $t0, L_24
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Grab ID: ASCII_RPAREN
   la    $t0, L_33
   lw    $a0, 0($t0)
   # ID grabbed

   la    $t0, L_25
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Grab ID: ASCII_NL
   la    $t0, L_37
   lw    $a0, 0($t0)
   # ID grabbed

   la    $t0, L_18
   sw    $a0, 0($t0)

   lw    $ra, 4($sp)
   addiu  $sp, $sp, 8
   lw    $fp, 0($sp)
   jr    $ra
   # End of Function Declaration:init


