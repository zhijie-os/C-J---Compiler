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
   addiu  $a0, $v0, 0
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 8
   lw    $fp, 0($sp)
   jr    $ra
   # End of predefined functions


    .data
    .align 2
L_0:    .space 4

    .data
    .align 2
L_1:    .space 4

    .data
    .align 2
L_2:    .space 4

   # Begin of Function Declaration
   .text
L_3:
   # function setup
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_8: .asciiz "evaluated A\n"
     .text
   la    $a0, str_L_8
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Grab ID
   la    $t0, L_0
   lw    $a0, 0($t0)
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 8
   lw    $fp, 0($sp)
   jr    $ra
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 8
   lw    $fp, 0($sp)
   jr    $ra
   # End of Function Declaration


   # Begin of Function Declaration
   .text
L_4:
   # function setup
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_9: .asciiz "evaluated B\n"
     .text
   la    $a0, str_L_9
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Grab ID
   la    $t0, L_1
   lw    $a0, 0($t0)
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 8
   lw    $fp, 0($sp)
   jr    $ra
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 8
   lw    $fp, 0($sp)
   jr    $ra
   # End of Function Declaration


   # Begin of Function Declaration
   .text
L_5:
   # function setup
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_10: .asciiz "evaluated C\n"
     .text
   la    $a0, str_L_10
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Grab ID
   la    $t0, L_2
   lw    $a0, 0($t0)
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 8
   lw    $fp, 0($sp)
   jr    $ra
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 8
   lw    $fp, 0($sp)
   jr    $ra
   # End of Function Declaration


   # Begin of Function Declaration
   .text
L_6:
   # function setup
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   # ASSIGNMENT
   # Grab ID
   lw    $a0, 4($fp)
   la    $t0, L_0
   sw    $a0, 0($t0)
   # ASSIGNMENT
   # Grab ID
   lw    $a0, 8($fp)
   la    $t0, L_1
   sw    $a0, 0($t0)
   # ASSIGNMENT
   # Grab ID
   lw    $a0, 12($fp)
   la    $t0, L_2
   sw    $a0, 0($t0)
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_11: .asciiz "if ((A && B) || C) {...} else {...}, with A="
     .text
   la    $a0, str_L_11
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Grab ID
   la    $t0, L_0
   lw    $a0, 0($t0)
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   printb
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_12: .asciiz " B="
     .text
   la    $a0, str_L_12
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Grab ID
   la    $t0, L_1
   lw    $a0, 0($t0)
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   printb
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_13: .asciiz " C="
     .text
   la    $a0, str_L_13
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Grab ID
   la    $t0, L_2
   lw    $a0, 0($t0)
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   printb
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_14: .asciiz "\n"
     .text
   la    $a0, str_L_14
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   jal   L_3
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   jal   L_4
   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   and    $a0, $t0,$a0 
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   jal   L_5
   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   or    $a0, $t0,$a0 
   beq   $a0, 1, L_15
L_16:
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_18: .asciiz "else-part executed\n"
     .text
   la    $a0, str_L_18
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   b     L_17
L_15:
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_19: .asciiz "if-part executed\n"
     .text
   la    $a0, str_L_19
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
L_17:
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 20
   lw    $fp, 0($sp)
   jr    $ra
   # End of Function Declaration


   # Begin of Function Declaration
   .text
L_7:
   # function setup
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   # ASSIGNMENT
   # Grab ID
   lw    $a0, 4($fp)
   la    $t0, L_0
   sw    $a0, 0($t0)
   # ASSIGNMENT
   # Grab ID
   lw    $a0, 8($fp)
   la    $t0, L_1
   sw    $a0, 0($t0)
   # ASSIGNMENT
   # Grab ID
   lw    $a0, 12($fp)
   la    $t0, L_2
   sw    $a0, 0($t0)
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_20: .asciiz "x = (A && !B) || C, with A="
     .text
   la    $a0, str_L_20
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Grab ID
   la    $t0, L_0
   lw    $a0, 0($t0)
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   printb
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_21: .asciiz " B="
     .text
   la    $a0, str_L_21
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Grab ID
   la    $t0, L_1
   lw    $a0, 0($t0)
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   printb
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_22: .asciiz " C="
     .text
   la    $a0, str_L_22
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Grab ID
   la    $t0, L_2
   lw    $a0, 0($t0)
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   printb
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_23: .asciiz "\n"
     .text
   la    $a0, str_L_23
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # ASSIGNMENT
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   jal   L_3
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   jal   L_4
   xori  $a0, $a0,1
   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   and    $a0, $t0,$a0 
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   jal   L_5
   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   or    $a0, $t0,$a0 
   sw    $a0, 16($fp)
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_24: .asciiz "x="
     .text
   la    $a0, str_L_24
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Grab ID
   lw    $a0, 16($fp)
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   printb
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_25: .asciiz "\n"
     .text
   la    $a0, str_L_25
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 24
   lw    $fp, 0($sp)
   jr    $ra
   # End of Function Declaration


   .text
   .globl main
main:
   # function setup
   move  $fp, $sp
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   # Create Actuals
   li    $a0, 0
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 0
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 0
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_6
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_26: .asciiz "\n"
     .text
   la    $a0, str_L_26
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   # Create Actuals
   li    $a0, 1
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 0
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 0
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_6
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_27: .asciiz "\n"
     .text
   la    $a0, str_L_27
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   # Create Actuals
   li    $a0, 0
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 1
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 0
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_6
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_28: .asciiz "\n"
     .text
   la    $a0, str_L_28
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   # Create Actuals
   li    $a0, 1
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 1
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 0
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_6
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_29: .asciiz "\n"
     .text
   la    $a0, str_L_29
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   # Create Actuals
   li    $a0, 0
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 0
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 1
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_6
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_30: .asciiz "\n"
     .text
   la    $a0, str_L_30
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   # Create Actuals
   li    $a0, 1
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 0
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 1
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_6
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_31: .asciiz "\n"
     .text
   la    $a0, str_L_31
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   # Create Actuals
   li    $a0, 0
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 1
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 1
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_6
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_32: .asciiz "\n"
     .text
   la    $a0, str_L_32
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   # Create Actuals
   li    $a0, 1
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 1
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 1
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_6
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_33: .asciiz "\n"
     .text
   la    $a0, str_L_33
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 0
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 0
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 0
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_7
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_34: .asciiz "\n"
     .text
   la    $a0, str_L_34
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 1
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 0
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 0
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_7
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_35: .asciiz "\n"
     .text
   la    $a0, str_L_35
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 0
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 1
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 0
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_7
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_36: .asciiz "\n"
     .text
   la    $a0, str_L_36
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 1
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 1
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 0
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_7
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_37: .asciiz "\n"
     .text
   la    $a0, str_L_37
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 0
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 0
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 1
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_7
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_38: .asciiz "\n"
     .text
   la    $a0, str_L_38
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 1
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 0
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 1
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_7
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_39: .asciiz "\n"
     .text
   la    $a0, str_L_39
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 0
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 1
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 1
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_7
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_40: .asciiz "\n"
     .text
   la    $a0, str_L_40
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 1
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 1
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   li    $a0, 1
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_7
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 4
   li    $v0,10
   syscall


