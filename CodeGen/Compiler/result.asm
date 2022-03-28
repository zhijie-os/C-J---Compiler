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


printb:
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


getchar:
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   li    $v0, 12
   syscall
   addiu  $a0, $v0, 0
   lw    $ra, 4($sp)
   addu  $sp, $sp, 8
   lw    $fp, 0($sp)
   jr    $ra
   # End of predefined functions


   # Begin of Function Declaration
   .text
L_0:
   # function setup
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   # ASSIGNMENT
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   jal   getchar
   sw    $a0, 4($fp)
   # Grab ID
   lw    $a0, 4($fp)
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID
   la    $t0, L_1
   lw    $a0, 0($t0)
   lw    $t0, 4($sp)
   addu  $sp, $sp, 4
   sne    $a0, $t0,$a0 
   beq   $a0, 0, L_2
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   subu  $sp, $sp, 4
   jal   L_0
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Grab ID
   lw    $a0, 4($fp)
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   printc
L_2:
   lw    $ra, 4($sp)
   addu  $sp, $sp, 12
   lw    $fp, 0($sp)
   jr    $ra
   # End of Function Declaration


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
   li    $a0, 10
   la    $t0, L_1
   sw    $a0, 0($t0)
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   subu  $sp, $sp, 4
   jal   L_0
   lw    $ra, 4($sp)
   addu  $sp, $sp, 4
   li    $v0,10
   syscall


