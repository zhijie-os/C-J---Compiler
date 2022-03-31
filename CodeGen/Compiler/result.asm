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


   .data
true_label:    .asciiz "true"
false_label:   .asciiz "false"
   .text
printb:
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   sw    $fp, 0($sp)
   subu  $sp, $sp,4
   move  $fp, $sp
   lw    $a0, 12($fp)
   beq   $a0, 0, Label_1
   Label_0:
   la    $a0, true_label
   j     Label_2
   Label_1:
   la    $a0, false_label
   Label_2:
   li    $v0, 4
   syscall
   lw     $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw     $ra, 4($sp)
   addiu  $sp, $sp, 4
   addiu  $sp, $sp, 4
   jr    $ra


   .data
   buffer:   .space 4
   .text
getchar:
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   sw    $fp, 0($sp)
   subu  $sp, $sp,4
   move  $fp, $sp
   la    $a0, buffer
   la    $a1, 2
   li    $v0, 8
   syscall
   lw    $a0, 0($a0)
   beq   $a0, 0, Label_3
   j     Label_4
Label_3:
   li    $a0, -1
Label_4:
   lw     $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw     $ra, 4($sp)
   addiu  $sp, $sp, 4
   jr    $ra
   # End of predefined functions


    .data
    .align 2
Label_5:    .space 4
   .text

   # Begin of Function Declaration: bar
   .text
Label_6:
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp,4
   sw    $fp, 0($sp)
   subu  $sp, $sp,4
   move  $fp, $sp
   # ASSIGNMENT
   # Generate Number: 12345
   li    $a0, 12345

   la    $t0, Label_5
   sw    $a0, 0($t0)

   lw    $fp, 4($sp)
   addiu $sp, $sp, 4
   lw    $ra, 4($sp)
   addiu $sp, $sp, 4
   addiu  $sp, $sp, 0
   jr    $ra
   # End of Function Declaration:bar


   .text
   .globl main
main:
   subu  $sp, $sp, 4
   # function setup
   sw    $ra, 0($sp)
   subu  $sp, $sp, 4
   sw    $fp, 0($sp)
   subu  $sp, $sp, 4
   move  $fp, $sp
   # Function Call Setup:bar
   # Create space for local variables
   jal   Label_6


   # Function Call Setup:printi
   # Create Actuals
   subu  $sp, $sp, 4
   # Grab ID: i
   la    $t0, Label_5
   lw    $a0, 0($t0)
   # ID grabbed

   sw    $a0,4($sp)
   jal   printi


   # ASSIGNMENT
   # Generate Boolean: False
   li    $a0, 0

   sw    $a0, 12($fp)

   # Function Call Setup:printb
   # Create Actuals
   subu  $sp, $sp, 4
   # Grab ID: i
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0,4($sp)
   jal   printb


   lw     $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw     $ra, 4($sp)
   addiu  $sp, $sp, 4
   addiu  $sp, $sp, 4
   li    $v0,10
   syscall


