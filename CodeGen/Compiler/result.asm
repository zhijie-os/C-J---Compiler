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
   addu  $sp, $sp, 12
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
   addu  $sp, $sp, 12
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
   addu  $sp, $sp, 12
   lw    $fp, 0($sp)
   jr    $ra
   # End of predefined functions


   .text
   .globl main
main:
   # function setup
   move  $fp, $sp
   # ASSIGNMENT
   li    $a0, 1
   sw    $a0, 4($fp)
   beq   $a0, 1, L_0
L_1:
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_3: .asciiz "False"
     .text
   la    $a0, str_L_3
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   b     L_2
L_0:
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_4: .asciiz "True"
     .text
   la    $a0, str_L_4
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
L_2:
   lw    $ra, 4($sp)
   addu  $sp, $sp, 8
   li    $v0,10
   syscall


