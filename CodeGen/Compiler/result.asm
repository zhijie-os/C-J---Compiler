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


    .data
    .align 2
L_1:    .space 4

   .text
   .globl main
main:
   # function setup
   move  $fp, $sp
   # ASSIGNMENT
   # Generate Number
   li    $a0, 1314
   la    $t0, L_1
   sw    $a0, 0($t0)
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Grab ID
   la    $t0, L_1
   lw    $a0, 0($t0)
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_0
   lw    $ra, 4($sp)
   addu  $sp, $sp, 4
   li    $v0,10
   syscall


   # Begin of Function Declaration
   .text
L_0:
   # function setup
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Grab ID
   lw    $a0, 4($fp)
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   printi
   lw    $ra, 4($sp)
   addu  $sp, $sp, 12
   lw    $fp, 0($sp)
   jr    $ra
   # End of Function Declaration


