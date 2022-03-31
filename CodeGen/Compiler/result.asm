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
   beq   $a0, 0, Label_0
   j     Label_1
Label_0:
   li    $a0, -1
Label_1:
   lw     $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw     $ra, 4($sp)
   addiu  $sp, $sp, 4
   jr    $ra
   # End of predefined functions


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
   # WHILE TEST
Label_2:
   # Evaluate a binary expression, return will be in $a0
   # ASSIGNMENT
   # Function Call Setup:getchar
   jal   getchar


   sw    $a0, 12($fp)

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # unary arithmetic -
   # Generate Number: 1
   li    $a0, 1

   negu  $a0, $a0

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   sne    $a0, $t0,$a0 

   # WHILE BODY
   bne   $a0, 0, Label_3
   j Label_4
Label_3:
   # Function Call Setup:printc
   # Create Actuals
   subu  $sp, $sp, 4
   # Grab ID: i
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0,4($sp)
   jal   printc


   j     Label_2
   # WHILE END
Label_4:

   lw     $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw     $ra, 4($sp)
   addiu  $sp, $sp, 4
   addiu  $sp, $sp, 4
   li    $v0,10
   syscall


