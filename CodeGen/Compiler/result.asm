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
   # Create Actuals
     .data
   str_L_3: .asciiz "\n(it's ok if the following aren't 0/false)\n"
     .text
   la    $a0, str_L_3
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_4: .asciiz "\tlocal int default value: "
     .text
   la    $a0, str_L_4
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
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
     .data
   str_L_5: .asciiz "\n"
     .text
   la    $a0, str_L_5
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_6: .asciiz "\tlocal boolean default value: "
     .text
   la    $a0, str_L_6
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
   # Grab ID
   lw    $a0, 8($fp)
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   printb
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_7: .asciiz "\n"
     .text
   la    $a0, str_L_7
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # ASSIGNMENT
   # Generate Number
   li    $a0, 123
   sw    $a0, 4($fp)
   # ASSIGNMENT
   li    $a0, 1
   sw    $a0, 8($fp)
   lw    $ra, 4($sp)
   addu  $sp, $sp, 8
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
   # Create Actuals
     .data
   str_L_8: .asciiz "global int default value: "
     .text
   la    $a0, str_L_8
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
   jal   printi
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_9: .asciiz "\n"
     .text
   la    $a0, str_L_9
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   # Create Actuals
     .data
   str_L_10: .asciiz "global boolean default value: "
     .text
   la    $a0, str_L_10
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
   str_L_11: .asciiz "\n"
     .text
   la    $a0, str_L_11
   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   jal   prints
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   jal   L_2
   # Function Call Setup
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   jal   L_2
   lw    $ra, 4($sp)
   addu  $sp, $sp, 4
   li    $v0,10
   syscall


