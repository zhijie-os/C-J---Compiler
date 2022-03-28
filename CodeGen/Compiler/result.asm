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


   # Begin of Function Declaration
   .text
L_0:
   # function setup
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   # Grab ID
   lw    $a0, 4($fp)
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID
   lw    $a0, 8($fp)
   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   mul    $a0, $t0,$a0 
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID
   lw    $a0, 12($fp)
   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   mul    $a0, $t0,$a0 
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID
   lw    $a0, 16($fp)
   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   mul    $a0, $t0,$a0 
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 24
   lw    $fp, 0($sp)
   jr    $ra
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 24
   lw    $fp, 0($sp)
   jr    $ra
   # End of Function Declaration


    .data
    .align 2
L_1:    .space 4

   # Begin of Function Declaration
   .text
L_2:
   # function setup
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   # Create Actuals
   # Grab ID
   la    $t0, L_1
   lw    $a0, 0($t0)
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Generate Number
   li    $a0, 3
   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   subu    $a0, $t0,$a0 
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Grab ID
   lw    $a0, 12($fp)
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Grab ID
   lw    $a0, 8($fp)
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Grab ID
   lw    $a0, 4($fp)
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_0
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 20
   lw    $fp, 0($sp)
   jr    $ra
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 20
   lw    $fp, 0($sp)
   jr    $ra
   # End of Function Declaration


   # Begin of Function Declaration
   .text
L_3:
   # function setup
   move  $fp, $sp
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   # ASSIGNMENT
   # Grab ID
   la    $t0, L_1
   lw    $a0, 0($t0)
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Generate Number
   li    $a0, 1
   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   addu    $a0, $t0,$a0 
   la    $t0, L_1
   sw    $a0, 0($t0)
   # Grab ID
   lw    $a0, 4($fp)
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 12
   lw    $fp, 0($sp)
   jr    $ra
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 12
   lw    $fp, 0($sp)
   jr    $ra
   # End of Function Declaration


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
   # Create Actuals
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   # Create Actuals
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   # Create Actuals
   # Generate Number
   li    $a0, 8
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_3
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   # Create Actuals
   # Generate Number
   li    $a0, 7
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   # Create Actuals
   # Generate Number
   li    $a0, 6
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_3
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Generate Number
   li    $a0, 5
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_2
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   # Create Actuals
   # Generate Number
   li    $a0, 4
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create space for local variables
   # Create Actuals
   # Generate Number
   li    $a0, 3
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_3
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Generate Number
   li    $a0, 2
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_2
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Generate Number
   li    $a0, 1
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   L_0
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   printi
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_4: .asciiz "\n"
     .text
   la    $a0, str_L_4
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 4
   li    $v0,10
   syscall


