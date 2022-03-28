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
L_0:    .space 4

   .text
   .globl main
main:
   # function setup
   move  $fp, $sp
   # ASSIGNMENT
   # Generate Number
   li    $a0, 123
   la    $t0, L_0
   sw    $a0, 0($t0)
   # ASSIGNMENT
   # Generate Number
   li    $a0, 456
   sw    $a0, 4($fp)
   # ASSIGNMENT
   # Generate Number
   li    $a0, 789
   la    $t0, L_1
   sw    $a0, 0($t0)
   # ASSIGNMENT
   # ASSIGNMENT
   # ASSIGNMENT
   # Generate Number
   li    $a0, 42
   la    $t0, L_1
   sw    $a0, 0($t0)
   sw    $a0, 4($fp)
   la    $t0, L_0
   sw    $a0, 0($t0)
   # ASSIGNMENT
   # Generate Number
   li    $a0, 42
   sw    $a0, 8($fp)
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Grab ID
   la    $t0, L_0
   lw    $a0, 0($t0)
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   printi
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Grab ID
   lw    $a0, 8($fp)
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   printc
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Grab ID
   lw    $a0, 4($fp)
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   printi
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Grab ID
   lw    $a0, 8($fp)
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   printc
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Grab ID
   la    $t0, L_1
   lw    $a0, 0($t0)
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   printi
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Grab ID
   lw    $a0, 8($fp)
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   printc
   lw    $ra, 4($sp)
   addu  $sp, $sp, 12
   li    $v0,10
   syscall


    .data
    .align 2
L_1:    .space 4

