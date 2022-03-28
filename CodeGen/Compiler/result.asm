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
   # Generate Number
   li    $a0, 0
   sw    $a0, 4($fp)
   # WHILE TEST
L_0:
   # Grab ID
   lw    $a0, 4($fp)
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Generate Number
   li    $a0, 10
   lw    $t0, 4($sp)
   addu  $sp, $sp, 4
   slt    $a0, $t0,$a0 
   # WHILE BODY
   beq   $a0, 0, L_2
L_1:
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Grab ID
   lw    $a0, 4($fp)
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   printi
   # ASSIGNMENT
   # Grab ID
   lw    $a0, 4($fp)
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Generate Number
   li    $a0, 1
   lw    $t0, 4($sp)
   addu  $sp, $sp, 4
   addu    $a0, $t0,$a0 
   sw    $a0, 4($fp)
   b     L_0
   # WHILE END
L_2:
   lw    $ra, 4($sp)
   addu  $sp, $sp, 8
   li    $v0,10
   syscall


