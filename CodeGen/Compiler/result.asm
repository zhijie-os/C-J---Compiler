   # Start of the predefined functions
   .text
halt:
   li    $v0, 10
   syscall
   .data
   .align 4
   div_by_zero: .asciiz "Exception: div by zero......
"
   .text
div0:
   la    $a0, div_by_zero
   li    $v0, 4
   syscall
   li    $v0, 10
   syscall
   .text
printi:
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   sw    $fp, 0($sp)
   subu  $sp, $sp,4
   move  $fp, $sp
   lw    $a0, 12($fp)
   li    $v0, 1
   syscall
   lw     $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw     $ra, 4($sp)
   addiu  $sp, $sp, 4
   addiu  $sp, $sp, 4
   jr    $ra


prints:
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   sw    $fp, 0($sp)
   subu  $sp, $sp,4
   move  $fp, $sp
   lw    $a0, 12($fp)
   li    $v0, 4
   syscall
   lw     $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw     $ra,  4($sp)
   addiu  $sp, $sp, 4
   addiu  $sp, $sp, 4
   jr    $ra


printc:
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   sw    $fp, 0($sp)
   subu  $sp, $sp,4
   move  $fp, $sp
   lw    $a0, 12($fp)
   li    $v0, 11
   syscall
   lw     $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw     $ra, 4($sp)
   addiu  $sp, $sp, 4
   addiu  $sp, $sp, 4
   jr    $ra


   .data
   .align 4
true_label:    .asciiz "true"
false_label:   .asciiz "false"
   .text
printb:
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   sw    $fp, 0($sp)
   subu  $sp, $sp,4
   move  $fp, $sp
   lw    $a0, 12($fp)
   beq   $a0, 0, Label_1
   Label_0:
   la    $a0, true_label
   j     Label_2
   Label_1:
   la    $a0, false_label
   Label_2:
   li    $v0, 4
   syscall
   lw     $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw     $ra, 4($sp)
   addiu  $sp, $sp, 4
   addiu  $sp, $sp, 4
   jr    $ra


   .data
   .align 4
   buffer:   .space 4
   .text
getchar:
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   sw    $fp, 0($sp)
   subu  $sp, $sp,4
   move  $fp, $sp
   la    $a0, buffer
   la    $a1, 2
   li    $v0, 8
   syscall
   lw    $a0, 0($a0)
   beq   $a0, 0, Label_3
   j     Label_4
Label_3:
   li    $a0, -1
Label_4:
   lw     $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw     $ra, 4($sp)
   addiu  $sp, $sp, 4
   jr    $ra
   # End of predefined functions


   .text
   .globl main
main:
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp, 4
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   move  $fp, $sp
   # Function Call Setup:init
   # Create space for local variables
   jal   Label_43


   # Function Call Setup:parser
   # Create space for local variables
   subu  $sp, $sp, 4
   jal   Label_17


   lw     $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw     $ra, 4($sp)
   addiu  $sp, $sp, 4
   addiu  $sp, $sp, 0
   li    $v0,10
   syscall


    .data
    .align 4
Label_5:    .space 4
   .text

    .data
    .align 4
Label_6:    .space 4
   .text

   # Begin of Function Declaration: getc
   .text
Label_7:
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   sw    $fp, 0($sp)
   subu  $sp, $sp,4
   move  $fp, $sp
   # Grab ID: _havechar
   la    $t0, Label_5
   lw    $a0, 0($t0)
   # ID grabbed

   # Generate IF block: Label_45
   bne   $a0, 0, Label_44
   j     Label_45
   Label_44:
   # ASSIGNMENT
   # Generate Boolean: False
   li    $a0, 0

   la    $t0, Label_5
   sw    $a0, 0($t0)

   # RETURN
   # Grab ID: _char
   la    $t0, Label_6
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 4
   addiu  $sp, $sp, 0
   jr    $ra

Label_45:

   # RETURN
   # Function Call Setup:getchar
   jal   getchar


   lw    $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 4
   addiu  $sp, $sp, 0
   jr    $ra

   lw    $fp, 4($sp)
   addiu $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu $sp, $sp, 4
   addiu  $sp, $sp, 0
   jr    $ra
   # End of Function Declaration:getc


   # Begin of Function Declaration: ungetc
   .text
Label_8:
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   sw    $fp, 0($sp)
   subu  $sp, $sp,4
   move  $fp, $sp
   # Grab ID: _havechar
   la    $t0, Label_5
   lw    $a0, 0($t0)
   # ID grabbed

   # Generate IF block: Label_47
   bne   $a0, 0, Label_46
   j     Label_47
   Label_46:
   # Function Call Setup:prints
   # Create Actuals
   subu  $sp, $sp, 4
     .data
     .align 4
   str_Label_48: .asciiz "Internal error: too many ungets!\n"
     .text
   la    $a0, str_Label_48

   sw    $a0,4($sp)
   jal   prints


   # Function Call Setup:halt
   jal   halt


Label_47:

   # ASSIGNMENT
   # Generate Boolean: True
   li    $a0, 1

   la    $t0, Label_5
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Grab ID: ch
   lw    $a0, 12($fp)
   # ID grabbed

   la    $t0, Label_6
   sw    $a0, 0($t0)

   lw    $fp, 4($sp)
   addiu $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu $sp, $sp, 4
   addiu  $sp, $sp, 4
   jr    $ra
   # End of Function Declaration:ungetc


    .data
    .align 4
Label_9:    .space 4
   .text

    .data
    .align 4
Label_10:    .space 4
   .text

    .data
    .align 4
Label_11:    .space 4
   .text

   # Begin of Function Declaration: peek
   .text
Label_12:
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   sw    $fp, 0($sp)
   subu  $sp, $sp,4
   move  $fp, $sp
   # Grab ID: _havetoken
   la    $t0, Label_9
   lw    $a0, 0($t0)
   # ID grabbed

   # Generate IF block: Label_50
   bne   $a0, 0, Label_49
   j     Label_50
   Label_49:
   # RETURN
   # Grab ID: _token
   la    $t0, Label_10
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 4
   addiu  $sp, $sp, 0
   jr    $ra

Label_50:

   # ASSIGNMENT
   # Generate Boolean: True
   li    $a0, 1

   la    $t0, Label_9
   sw    $a0, 0($t0)

   # RETURN
   # ASSIGNMENT
   # Function Call Setup:scanner
   # Create space for local variables
   subu  $sp, $sp, 4
   jal   Label_14


   la    $t0, Label_10
   sw    $a0, 0($t0)

   lw    $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 4
   addiu  $sp, $sp, 0
   jr    $ra

   lw    $fp, 4($sp)
   addiu $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu $sp, $sp, 4
   addiu  $sp, $sp, 0
   jr    $ra
   # End of Function Declaration:peek


   # Begin of Function Declaration: match
   .text
Label_13:
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   sw    $fp, 0($sp)
   subu  $sp, $sp,4
   move  $fp, $sp
   # Evaluate a binary expression, return will be in $a0
   # Function Call Setup:peek
   # Create space for local variables
   jal   Label_12


   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: expect
   lw    $a0, 12($fp)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   sne    $a0, $t0,$a0 

   # Generate IF block: Label_52
   bne   $a0, 0, Label_51
   j     Label_52
   Label_51:
   # Function Call Setup:prints
   # Create Actuals
   subu  $sp, $sp, 4
     .data
     .align 4
   str_Label_53: .asciiz "Error: expected "
     .text
   la    $a0, str_Label_53

   sw    $a0,4($sp)
   jal   prints


   # Function Call Setup:printc
   # Create Actuals
   subu  $sp, $sp, 4
   # Grab ID: expect
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0,4($sp)
   jal   printc


   # Function Call Setup:prints
   # Create Actuals
   subu  $sp, $sp, 4
     .data
     .align 4
   str_Label_54: .asciiz "\n"
     .text
   la    $a0, str_Label_54

   sw    $a0,4($sp)
   jal   prints


   # Function Call Setup:halt
   jal   halt


Label_52:

   # ASSIGNMENT
   # Generate Boolean: False
   li    $a0, 0

   la    $t0, Label_9
   sw    $a0, 0($t0)

   lw    $fp, 4($sp)
   addiu $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu $sp, $sp, 4
   addiu  $sp, $sp, 4
   jr    $ra
   # End of Function Declaration:match


   # Begin of Function Declaration: scanner
   .text
Label_14:
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   sw    $fp, 0($sp)
   subu  $sp, $sp,4
   move  $fp, $sp
   # WHILE TEST
Label_55:
   # Function Call Setup:isspace
   # Create space for local variables
   # Create Actuals
   subu  $sp, $sp, 4
   # ASSIGNMENT
   # Function Call Setup:getc
   # Create space for local variables
   jal   Label_7


   sw    $a0, 12($fp)

   sw    $a0,4($sp)
   jal   Label_16


   # WHILE BODY
   bne   $a0, 0, Label_56
   j Label_57
Label_56:
   j     Label_55
   # WHILE END
Label_57:

   # Evaluate a binary expression, return will be in $a0
   # Grab ID: ch
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: EOF
   la    $t0, Label_21
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   # Generate IF block: Label_59
   bne   $a0, 0, Label_58
   j     Label_59
   Label_58:
   # RETURN
   # Grab ID: TK_EOF
   la    $t0, Label_22
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 4
   addiu  $sp, $sp, 4
   jr    $ra

Label_59:

   # Evaluate a binary expression, return will be in $a0
   # Grab ID: ch
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: ASCII_NL
   la    $t0, Label_42
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   # Generate IF block: Label_61
   bne   $a0, 0, Label_60
   j     Label_61
   Label_60:
   # RETURN
   # Grab ID: TK_EOLN
   la    $t0, Label_23
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 4
   addiu  $sp, $sp, 4
   jr    $ra

Label_61:

   # Evaluate a binary expression, return will be in $a0
   # Grab ID: ch
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: ASCII_PLUS
   la    $t0, Label_33
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   # Generate IF block: Label_63
   bne   $a0, 0, Label_62
   j     Label_63
   Label_62:
   # RETURN
   # Grab ID: TK_ADD
   la    $t0, Label_25
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 4
   addiu  $sp, $sp, 4
   jr    $ra

Label_63:

   # Evaluate a binary expression, return will be in $a0
   # Grab ID: ch
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: ASCII_MINUS
   la    $t0, Label_34
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   # Generate IF block: Label_65
   bne   $a0, 0, Label_64
   j     Label_65
   Label_64:
   # RETURN
   # Grab ID: TK_SUB
   la    $t0, Label_26
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 4
   addiu  $sp, $sp, 4
   jr    $ra

Label_65:

   # Evaluate a binary expression, return will be in $a0
   # Grab ID: ch
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: ASCII_STAR
   la    $t0, Label_35
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   # Generate IF block: Label_67
   bne   $a0, 0, Label_66
   j     Label_67
   Label_66:
   # RETURN
   # Grab ID: TK_MUL
   la    $t0, Label_27
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 4
   addiu  $sp, $sp, 4
   jr    $ra

Label_67:

   # Evaluate a binary expression, return will be in $a0
   # Grab ID: ch
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: ASCII_SLASH
   la    $t0, Label_36
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   # Generate IF block: Label_69
   bne   $a0, 0, Label_68
   j     Label_69
   Label_68:
   # RETURN
   # Grab ID: TK_DIV
   la    $t0, Label_28
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 4
   addiu  $sp, $sp, 4
   jr    $ra

Label_69:

   # Evaluate a binary expression, return will be in $a0
   # Grab ID: ch
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: ASCII_LPAREN
   la    $t0, Label_37
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   # Generate IF block: Label_71
   bne   $a0, 0, Label_70
   j     Label_71
   Label_70:
   # RETURN
   # Grab ID: TK_LPAREN
   la    $t0, Label_29
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 4
   addiu  $sp, $sp, 4
   jr    $ra

Label_71:

   # Evaluate a binary expression, return will be in $a0
   # Grab ID: ch
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: ASCII_RPAREN
   la    $t0, Label_38
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   # Generate IF block: Label_73
   bne   $a0, 0, Label_72
   j     Label_73
   Label_72:
   # RETURN
   # Grab ID: TK_RPAREN
   la    $t0, Label_30
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 4
   addiu  $sp, $sp, 4
   jr    $ra

Label_73:

   # Function Call Setup:isdigit
   # Create space for local variables
   # Create Actuals
   subu  $sp, $sp, 4
   # Grab ID: ch
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0,4($sp)
   jal   Label_15


   # Generate IF block: Label_75
   bne   $a0, 0, Label_74
   j     Label_75
   Label_74:
   # ASSIGNMENT
   # Generate Number: 0
   li    $a0, 0

   la    $t0, Label_11
   sw    $a0, 0($t0)

   # WHILE TEST
Label_76:
   # Function Call Setup:isdigit
   # Create space for local variables
   # Create Actuals
   subu  $sp, $sp, 4
   # Grab ID: ch
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0,4($sp)
   jal   Label_15


   # WHILE BODY
   bne   $a0, 0, Label_77
   j Label_78
Label_77:
   # ASSIGNMENT
   # Evaluate a binary expression, return will be in $a0
   # Evaluate a binary expression, return will be in $a0
   # Grab ID: attr
   la    $t0, Label_11
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
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: ASCII_0
   la    $t0, Label_31
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   subu    $a0, $t0,$a0 

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   addu    $a0, $t0,$a0 

   la    $t0, Label_11
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Function Call Setup:getc
   # Create space for local variables
   jal   Label_7


   sw    $a0, 12($fp)

   j     Label_76
   # WHILE END
Label_78:

   # Function Call Setup:ungetc
   # Create space for local variables
   # Create Actuals
   subu  $sp, $sp, 4
   # Grab ID: ch
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0,4($sp)
   jal   Label_8


   # RETURN
   # Grab ID: TK_NUMBER
   la    $t0, Label_24
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 4
   addiu  $sp, $sp, 4
   jr    $ra

Label_75:

   # Function Call Setup:prints
   # Create Actuals
   subu  $sp, $sp, 4
     .data
     .align 4
   str_Label_79: .asciiz "Error: invalid character.\n"
     .text
   la    $a0, str_Label_79

   sw    $a0,4($sp)
   jal   prints


   # Function Call Setup:halt
   jal   halt


   lw    $fp, 4($sp)
   addiu $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu $sp, $sp, 4
   addiu  $sp, $sp, 4
   jr    $ra
   # End of Function Declaration:scanner


   # Begin of Function Declaration: isdigit
   .text
Label_15:
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   sw    $fp, 0($sp)
   subu  $sp, $sp,4
   move  $fp, $sp
   # RETURN
   # Evaluate a binary expression, return will be in $a0
   # Evaluate a binary expression, return will be in $a0
   # Grab ID: ch
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: ASCII_0
   la    $t0, Label_31
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   sge    $a0, $t0,$a0 

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Evaluate a binary expression, return will be in $a0
   # Grab ID: ch
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: ASCII_9
   la    $t0, Label_32
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   sle    $a0, $t0,$a0 

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   and    $a0, $t0,$a0 

   lw    $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 4
   addiu  $sp, $sp, 4
   jr    $ra

   lw    $fp, 4($sp)
   addiu $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu $sp, $sp, 4
   addiu  $sp, $sp, 4
   jr    $ra
   # End of Function Declaration:isdigit


   # Begin of Function Declaration: isspace
   .text
Label_16:
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   sw    $fp, 0($sp)
   subu  $sp, $sp,4
   move  $fp, $sp
   # RETURN
   # Evaluate a binary expression, return will be in $a0
   # Evaluate a binary expression, return will be in $a0
   # Evaluate a binary expression, return will be in $a0
   # Grab ID: ch
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: ASCII_SPACE
   la    $t0, Label_39
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Evaluate a binary expression, return will be in $a0
   # Grab ID: ch
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: ASCII_TAB
   la    $t0, Label_40
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
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: ASCII_CR
   la    $t0, Label_41
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   or    $a0, $t0,$a0 

   lw    $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 4
   addiu  $sp, $sp, 4
   jr    $ra

   lw    $fp, 4($sp)
   addiu $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu $sp, $sp, 4
   addiu  $sp, $sp, 4
   jr    $ra
   # End of Function Declaration:isspace


   # Begin of Function Declaration: parser
   .text
Label_17:
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   sw    $fp, 0($sp)
   subu  $sp, $sp,4
   move  $fp, $sp
   # WHILE TEST
Label_80:
   # Evaluate a binary expression, return will be in $a0
   # Function Call Setup:peek
   # Create space for local variables
   jal   Label_12


   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: TK_EOF
   la    $t0, Label_22
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   sne    $a0, $t0,$a0 

   # WHILE BODY
   bne   $a0, 0, Label_81
   j Label_82
Label_81:
   # ASSIGNMENT
   # Function Call Setup:E
   # Create space for local variables
   subu  $sp, $sp, 4
   subu  $sp, $sp, 4
   subu  $sp, $sp, 4
   jal   Label_18


   sw    $a0, 12($fp)

   # Function Call Setup:match
   # Create space for local variables
   # Create Actuals
   subu  $sp, $sp, 4
   # Grab ID: TK_EOLN
   la    $t0, Label_23
   lw    $a0, 0($t0)
   # ID grabbed

   sw    $a0,4($sp)
   jal   Label_13


   # Function Call Setup:prints
   # Create Actuals
   subu  $sp, $sp, 4
     .data
     .align 4
   str_Label_83: .asciiz " = "
     .text
   la    $a0, str_Label_83

   sw    $a0,4($sp)
   jal   prints


   # Function Call Setup:printi
   # Create Actuals
   subu  $sp, $sp, 4
   # Grab ID: result
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0,4($sp)
   jal   printi


   # Function Call Setup:prints
   # Create Actuals
   subu  $sp, $sp, 4
     .data
     .align 4
   str_Label_84: .asciiz "\n"
     .text
   la    $a0, str_Label_84

   sw    $a0,4($sp)
   jal   prints


   j     Label_80
   # WHILE END
Label_82:

   lw    $fp, 4($sp)
   addiu $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu $sp, $sp, 4
   addiu  $sp, $sp, 4
   jr    $ra
   # End of Function Declaration:parser


   # Begin of Function Declaration: E
   .text
Label_18:
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   sw    $fp, 0($sp)
   subu  $sp, $sp,4
   move  $fp, $sp
   # ASSIGNMENT
   # Function Call Setup:T
   # Create space for local variables
   subu  $sp, $sp, 4
   subu  $sp, $sp, 4
   subu  $sp, $sp, 4
   jal   Label_19


   sw    $a0, 12($fp)

   # WHILE TEST
Label_85:
   # Evaluate a binary expression, return will be in $a0
   # Evaluate a binary expression, return will be in $a0
   # Function Call Setup:peek
   # Create space for local variables
   jal   Label_12


   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: TK_ADD
   la    $t0, Label_25
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Evaluate a binary expression, return will be in $a0
   # Function Call Setup:peek
   # Create space for local variables
   jal   Label_12


   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: TK_SUB
   la    $t0, Label_26
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   or    $a0, $t0,$a0 

   # WHILE BODY
   bne   $a0, 0, Label_86
   j Label_87
Label_86:
   # Function Call Setup:match
   # Create space for local variables
   # Create Actuals
   subu  $sp, $sp, 4
   # ASSIGNMENT
   # Function Call Setup:peek
   # Create space for local variables
   jal   Label_12


   sw    $a0, 20($fp)

   sw    $a0,4($sp)
   jal   Label_13


   # ASSIGNMENT
   # Function Call Setup:T
   # Create space for local variables
   subu  $sp, $sp, 4
   subu  $sp, $sp, 4
   subu  $sp, $sp, 4
   jal   Label_19


   sw    $a0, 16($fp)

   # Evaluate a binary expression, return will be in $a0
   # Grab ID: token
   lw    $a0, 20($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: TK_ADD
   la    $t0, Label_25
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   # Generate IF-ELSE block: Label_88, Label_89, Label_90
   bne   $a0, 1, Label_89
   j     Label_88
Label_89:
   # ASSIGNMENT
   # Evaluate a binary expression, return will be in $a0
   # Grab ID: l
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: r
   lw    $a0, 16($fp)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   subu    $a0, $t0,$a0 

   sw    $a0, 12($fp)

   j     Label_90
Label_88:
   # ASSIGNMENT
   # Evaluate a binary expression, return will be in $a0
   # Grab ID: l
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: r
   lw    $a0, 16($fp)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   addu    $a0, $t0,$a0 

   sw    $a0, 12($fp)

Label_90:

   j     Label_85
   # WHILE END
Label_87:

   # RETURN
   # Grab ID: l
   lw    $a0, 12($fp)
   # ID grabbed

   lw    $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 4
   addiu  $sp, $sp, 12
   jr    $ra

   lw    $fp, 4($sp)
   addiu $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu $sp, $sp, 4
   addiu  $sp, $sp, 12
   jr    $ra
   # End of Function Declaration:E


   # Begin of Function Declaration: T
   .text
Label_19:
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   sw    $fp, 0($sp)
   subu  $sp, $sp,4
   move  $fp, $sp
   # ASSIGNMENT
   # Function Call Setup:F
   # Create space for local variables
   subu  $sp, $sp, 4
   subu  $sp, $sp, 4
   jal   Label_20


   sw    $a0, 12($fp)

   # WHILE TEST
Label_91:
   # Evaluate a binary expression, return will be in $a0
   # Evaluate a binary expression, return will be in $a0
   # Function Call Setup:peek
   # Create space for local variables
   jal   Label_12


   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: TK_MUL
   la    $t0, Label_27
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Evaluate a binary expression, return will be in $a0
   # Function Call Setup:peek
   # Create space for local variables
   jal   Label_12


   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: TK_DIV
   la    $t0, Label_28
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   or    $a0, $t0,$a0 

   # WHILE BODY
   bne   $a0, 0, Label_92
   j Label_93
Label_92:
   # Function Call Setup:match
   # Create space for local variables
   # Create Actuals
   subu  $sp, $sp, 4
   # ASSIGNMENT
   # Function Call Setup:peek
   # Create space for local variables
   jal   Label_12


   sw    $a0, 20($fp)

   sw    $a0,4($sp)
   jal   Label_13


   # ASSIGNMENT
   # Function Call Setup:F
   # Create space for local variables
   subu  $sp, $sp, 4
   subu  $sp, $sp, 4
   jal   Label_20


   sw    $a0, 16($fp)

   # Evaluate a binary expression, return will be in $a0
   # Grab ID: token
   lw    $a0, 20($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: TK_MUL
   la    $t0, Label_27
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   # Generate IF-ELSE block: Label_94, Label_95, Label_96
   bne   $a0, 1, Label_95
   j     Label_94
Label_95:
   # ASSIGNMENT
   # Evaluate a binary expression, return will be in $a0
   # Grab ID: l
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: r
   lw    $a0, 16($fp)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   bne   $a0, 0, Label_97
   j     div0
   Label_97:
   div    $a0, $t0,$a0 

   sw    $a0, 12($fp)

   j     Label_96
Label_94:
   # ASSIGNMENT
   # Evaluate a binary expression, return will be in $a0
   # Grab ID: l
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: r
   lw    $a0, 16($fp)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   mul    $a0, $t0,$a0 

   sw    $a0, 12($fp)

Label_96:

   j     Label_91
   # WHILE END
Label_93:

   # RETURN
   # Grab ID: l
   lw    $a0, 12($fp)
   # ID grabbed

   lw    $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 4
   addiu  $sp, $sp, 12
   jr    $ra

   lw    $fp, 4($sp)
   addiu $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu $sp, $sp, 4
   addiu  $sp, $sp, 12
   jr    $ra
   # End of Function Declaration:T


   # Begin of Function Declaration: F
   .text
Label_20:
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   sw    $fp, 0($sp)
   subu  $sp, $sp,4
   move  $fp, $sp
   # ASSIGNMENT
   # Function Call Setup:peek
   # Create space for local variables
   jal   Label_12


   sw    $a0, 16($fp)

   # Evaluate a binary expression, return will be in $a0
   # Grab ID: token
   lw    $a0, 16($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: TK_LPAREN
   la    $t0, Label_29
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   # Generate IF-ELSE block: Label_98, Label_99, Label_100
   bne   $a0, 1, Label_99
   j     Label_98
Label_99:
   # Evaluate a binary expression, return will be in $a0
   # Grab ID: token
   lw    $a0, 16($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: TK_SUB
   la    $t0, Label_26
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   # Generate IF-ELSE block: Label_101, Label_102, Label_103
   bne   $a0, 1, Label_102
   j     Label_101
Label_102:
   # Evaluate a binary expression, return will be in $a0
   # Grab ID: token
   lw    $a0, 16($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: TK_NUMBER
   la    $t0, Label_24
   lw    $a0, 0($t0)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   seq    $a0, $t0,$a0 

   # Generate IF-ELSE block: Label_104, Label_105, Label_106
   bne   $a0, 1, Label_105
   j     Label_104
Label_105:
   # Function Call Setup:prints
   # Create Actuals
   subu  $sp, $sp, 4
     .data
     .align 4
   str_Label_107: .asciiz "Error: expected factor.\n"
     .text
   la    $a0, str_Label_107

   sw    $a0,4($sp)
   jal   prints


   # Function Call Setup:halt
   jal   halt


   j     Label_106
Label_104:
   # Function Call Setup:match
   # Create space for local variables
   # Create Actuals
   subu  $sp, $sp, 4
   # Grab ID: TK_NUMBER
   la    $t0, Label_24
   lw    $a0, 0($t0)
   # ID grabbed

   sw    $a0,4($sp)
   jal   Label_13


   # ASSIGNMENT
   # Grab ID: attr
   la    $t0, Label_11
   lw    $a0, 0($t0)
   # ID grabbed

   sw    $a0, 12($fp)

Label_106:

   j     Label_103
Label_101:
   # Function Call Setup:match
   # Create space for local variables
   # Create Actuals
   subu  $sp, $sp, 4
   # Grab ID: TK_SUB
   la    $t0, Label_26
   lw    $a0, 0($t0)
   # ID grabbed

   sw    $a0,4($sp)
   jal   Label_13


   # ASSIGNMENT
   # unary arithmetic -
   # Function Call Setup:F
   # Create space for local variables
   subu  $sp, $sp, 4
   subu  $sp, $sp, 4
   jal   Label_20


   negu  $a0, $a0

   sw    $a0, 12($fp)

Label_103:

   j     Label_100
Label_98:
   # Function Call Setup:match
   # Create space for local variables
   # Create Actuals
   subu  $sp, $sp, 4
   # Grab ID: TK_LPAREN
   la    $t0, Label_29
   lw    $a0, 0($t0)
   # ID grabbed

   sw    $a0,4($sp)
   jal   Label_13


   # ASSIGNMENT
   # Function Call Setup:E
   # Create space for local variables
   subu  $sp, $sp, 4
   subu  $sp, $sp, 4
   subu  $sp, $sp, 4
   jal   Label_18


   sw    $a0, 12($fp)

   # Function Call Setup:match
   # Create space for local variables
   # Create Actuals
   subu  $sp, $sp, 4
   # Grab ID: TK_RPAREN
   la    $t0, Label_30
   lw    $a0, 0($t0)
   # ID grabbed

   sw    $a0,4($sp)
   jal   Label_13


Label_100:

   # RETURN
   # Grab ID: result
   lw    $a0, 12($fp)
   # ID grabbed

   lw    $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 4
   addiu  $sp, $sp, 8
   jr    $ra

   lw    $fp, 4($sp)
   addiu $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu $sp, $sp, 4
   addiu  $sp, $sp, 8
   jr    $ra
   # End of Function Declaration:F


    .data
    .align 4
Label_21:    .space 4
   .text

    .data
    .align 4
Label_22:    .space 4
   .text

    .data
    .align 4
Label_23:    .space 4
   .text

    .data
    .align 4
Label_24:    .space 4
   .text

    .data
    .align 4
Label_25:    .space 4
   .text

    .data
    .align 4
Label_26:    .space 4
   .text

    .data
    .align 4
Label_27:    .space 4
   .text

    .data
    .align 4
Label_28:    .space 4
   .text

    .data
    .align 4
Label_29:    .space 4
   .text

    .data
    .align 4
Label_30:    .space 4
   .text

    .data
    .align 4
Label_31:    .space 4
   .text

    .data
    .align 4
Label_32:    .space 4
   .text

    .data
    .align 4
Label_33:    .space 4
   .text

    .data
    .align 4
Label_34:    .space 4
   .text

    .data
    .align 4
Label_35:    .space 4
   .text

    .data
    .align 4
Label_36:    .space 4
   .text

    .data
    .align 4
Label_37:    .space 4
   .text

    .data
    .align 4
Label_38:    .space 4
   .text

    .data
    .align 4
Label_39:    .space 4
   .text

    .data
    .align 4
Label_40:    .space 4
   .text

    .data
    .align 4
Label_41:    .space 4
   .text

    .data
    .align 4
Label_42:    .space 4
   .text

   # Begin of Function Declaration: init
   .text
Label_43:
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   sw    $fp, 0($sp)
   subu  $sp, $sp,4
   move  $fp, $sp
   # ASSIGNMENT
   # unary arithmetic -
   # Generate Number: 1
   li    $a0, 1

   negu  $a0, $a0

   la    $t0, Label_21
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Generate Number: 48
   li    $a0, 48

   la    $t0, Label_31
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Generate Number: 57
   li    $a0, 57

   la    $t0, Label_32
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Generate Number: 43
   li    $a0, 43

   la    $t0, Label_33
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Generate Number: 45
   li    $a0, 45

   la    $t0, Label_34
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Generate Number: 42
   li    $a0, 42

   la    $t0, Label_35
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Generate Number: 47
   li    $a0, 47

   la    $t0, Label_36
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Generate Number: 40
   li    $a0, 40

   la    $t0, Label_37
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Generate Number: 41
   li    $a0, 41

   la    $t0, Label_38
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Generate Number: 32
   li    $a0, 32

   la    $t0, Label_39
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Generate Number: 9
   li    $a0, 9

   la    $t0, Label_40
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Generate Number: 13
   li    $a0, 13

   la    $t0, Label_41
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Generate Number: 10
   li    $a0, 10

   la    $t0, Label_42
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Generate Number: 256
   li    $a0, 256

   la    $t0, Label_22
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Generate Number: 257
   li    $a0, 257

   la    $t0, Label_24
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Grab ID: ASCII_PLUS
   la    $t0, Label_33
   lw    $a0, 0($t0)
   # ID grabbed

   la    $t0, Label_25
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Grab ID: ASCII_MINUS
   la    $t0, Label_34
   lw    $a0, 0($t0)
   # ID grabbed

   la    $t0, Label_26
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Grab ID: ASCII_STAR
   la    $t0, Label_35
   lw    $a0, 0($t0)
   # ID grabbed

   la    $t0, Label_27
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Grab ID: ASCII_SLASH
   la    $t0, Label_36
   lw    $a0, 0($t0)
   # ID grabbed

   la    $t0, Label_28
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Grab ID: ASCII_LPAREN
   la    $t0, Label_37
   lw    $a0, 0($t0)
   # ID grabbed

   la    $t0, Label_29
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Grab ID: ASCII_RPAREN
   la    $t0, Label_38
   lw    $a0, 0($t0)
   # ID grabbed

   la    $t0, Label_30
   sw    $a0, 0($t0)

   # ASSIGNMENT
   # Grab ID: ASCII_NL
   la    $t0, Label_42
   lw    $a0, 0($t0)
   # ID grabbed

   la    $t0, Label_23
   sw    $a0, 0($t0)

   lw    $fp, 4($sp)
   addiu $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu $sp, $sp, 4
   addiu  $sp, $sp, 0
   jr    $ra
   # End of Function Declaration:init


