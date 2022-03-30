   # Start of the predefined functions
   .text
halt:
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


printb:
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


getchar:
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   sw    $fp, 0($sp)
   subu  $sp, $sp,4
   move  $fp, $sp
   li    $v0, 12
   syscall
   move  $a0, $v0
   lw     $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw     $ra, 4($sp)
   addiu  $sp, $sp, 4
   jr    $ra
   # End of predefined functions


   # Begin of Function Declaration: foo
   .text
Label_0:
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
   # Grab ID: a
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: b
   lw    $a0, 16($fp)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   mul    $a0, $t0,$a0 

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: c
   lw    $a0, 20($fp)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   mul    $a0, $t0,$a0 

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Grab ID: d
   lw    $a0, 24($fp)
   # ID grabbed

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   mul    $a0, $t0,$a0 

   lw    $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu  $sp, $sp, 4
   addiu  $sp, $sp, 16
   jr    $ra

   lw    $fp, 4($sp)
   addiu $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu $sp, $sp, 4
   addiu  $sp, $sp, 16
   jr    $ra
   # End of Function Declaration:foo


    .data
    .align 2
Label_1:    .space 4
   .text

   # Begin of Function Declaration: bar
   .text
Label_2:
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   sw    $fp, 0($sp)
   subu  $sp, $sp,4
   move  $fp, $sp
   # RETURN
   # Function Call Setup:foo
   # Create space for local variables
   # Create Actuals
   subu  $sp, $sp, 4
   # Create Actuals
   subu  $sp, $sp, 4
   # Create Actuals
   subu  $sp, $sp, 4
   # Create Actuals
   subu  $sp, $sp, 4
   # Grab ID: a
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0,4($sp)
   # Grab ID: b
   lw    $a0, 16($fp)
   # ID grabbed

   sw    $a0,8($sp)
   # Grab ID: c
   lw    $a0, 20($fp)
   # ID grabbed

   sw    $a0,12($sp)
   # Evaluate a binary expression, return will be in $a0
   # Grab ID: d
   la    $t0, Label_1
   lw    $a0, 0($t0)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Generate Number: 3
   li    $a0, 3

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   subu    $a0, $t0,$a0 

   sw    $a0,16($sp)
   jal   Label_0


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
   # End of Function Declaration:bar


   # Begin of Function Declaration: baz
   .text
Label_3:
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   sw    $fp, 0($sp)
   subu  $sp, $sp,4
   move  $fp, $sp
   # ASSIGNMENT
   # Evaluate a binary expression, return will be in $a0
   # Grab ID: d
   la    $t0, Label_1
   lw    $a0, 0($t0)
   # ID grabbed

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Generate Number: 1
   li    $a0, 1

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   addu    $a0, $t0,$a0 

   la    $t0, Label_1
   sw    $a0, 0($t0)

   # RETURN
   # Grab ID: a
   lw    $a0, 12($fp)
   # ID grabbed

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
   # End of Function Declaration:baz


   .text
   .globl main
main:
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp, 4
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   move  $fp, $sp
   # ASSIGNMENT
   # Generate Number: 10
   li    $a0, 10

   la    $t0, Label_1
   sw    $a0, 0($t0)

   # Function Call Setup:printi
   # Create Actuals
   subu  $sp, $sp, 4
   # Function Call Setup:foo
   # Create space for local variables
   # Create Actuals
   subu  $sp, $sp, 4
   # Create Actuals
   subu  $sp, $sp, 4
   # Create Actuals
   subu  $sp, $sp, 4
   # Create Actuals
   subu  $sp, $sp, 4
   # Generate Number: 1
   li    $a0, 1

   sw    $a0,4($sp)
   # Function Call Setup:bar
   # Create space for local variables
   # Create Actuals
   subu  $sp, $sp, 4
   # Create Actuals
   subu  $sp, $sp, 4
   # Create Actuals
   subu  $sp, $sp, 4
   # Generate Number: 2
   li    $a0, 2

   sw    $a0,4($sp)
   # Function Call Setup:baz
   # Create space for local variables
   # Create Actuals
   subu  $sp, $sp, 4
   # Generate Number: 3
   li    $a0, 3

   sw    $a0,4($sp)
   jal   Label_3


   sw    $a0,8($sp)
   # Generate Number: 4
   li    $a0, 4

   sw    $a0,12($sp)
   jal   Label_2


   sw    $a0,8($sp)
   # Function Call Setup:bar
   # Create space for local variables
   # Create Actuals
   subu  $sp, $sp, 4
   # Create Actuals
   subu  $sp, $sp, 4
   # Create Actuals
   subu  $sp, $sp, 4
   # Generate Number: 5
   li    $a0, 5

   sw    $a0,4($sp)
   # Function Call Setup:baz
   # Create space for local variables
   # Create Actuals
   subu  $sp, $sp, 4
   # Generate Number: 6
   li    $a0, 6

   sw    $a0,4($sp)
   jal   Label_3


   sw    $a0,8($sp)
   # Generate Number: 7
   li    $a0, 7

   sw    $a0,12($sp)
   jal   Label_2


   sw    $a0,12($sp)
   # Function Call Setup:baz
   # Create space for local variables
   # Create Actuals
   subu  $sp, $sp, 4
   # Generate Number: 8
   li    $a0, 8

   sw    $a0,4($sp)
   jal   Label_3


   sw    $a0,16($sp)
   jal   Label_0


   sw    $a0,4($sp)
   jal   printi


   # Function Call Setup:prints
   # Create Actuals
   subu  $sp, $sp, 4
     .data
   str_Label_4: .asciiz "\n"
     .text
   la    $a0, str_Label_4

   sw    $a0,4($sp)
   jal   prints


   lw     $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw     $ra, 4($sp)
   addiu  $sp, $sp, 4
   addiu  $sp, $sp, 0
   li    $v0,10
   syscall


