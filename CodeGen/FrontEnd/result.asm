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
   subu  $sp, $sp, 12
   lw    $fp, 0($sp)
   jr    $ra


prints:
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   lw    $a0, 8($fp)
   li    $v0, 4
   syscall
   lw    $ra, 4($sp)
   subu  $sp, $sp, 12
   lw    $fp, 0($sp)
   jr    $ra
printc:
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   lw    $a0, 8($fp)
   li    $v0, 11
   syscall
   lw    $ra, 4($sp)
   subu  $sp, $sp, 12
   lw    $fp, 0($sp)
   jr    $ra
   .text
   .globl main
main:
   # function setup
   move  $fp, $sp
   # ASSIGNMENT
   # Generate Number
   li    $a0,3
   sw    $a0, 4($fp)
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
   addu  $sp, $sp, 8
   li    $v0,10
   syscall
