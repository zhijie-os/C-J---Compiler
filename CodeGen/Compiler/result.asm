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
Label_0:
   # Evaluate a binary expression, return will be in $a0
   # ASSIGNMENT
   # Function Call Setup:getchar
   jal   getchar


   sw    $a0, 12($fp)

   sw    $a0, 0($sp)
   subu  $sp, $sp, 4
   # Generate Number: 0
   li    $a0, 0

   lw    $t0, 4($sp)
   addiu  $sp, $sp, 4
   sne    $a0, $t0,$a0 

   # WHILE BODY
   bne   $a0, 0, Label_1
   j Label_2
Label_1:
   # Function Call Setup:printc
   # Create Actuals
   subu  $sp, $sp, 4
   # Grab ID: i
   lw    $a0, 12($fp)
   # ID grabbed

   sw    $a0,4($sp)
   jal   printc


   j     Label_0
   # WHILE END
Label_2:

   lw     $fp, 4($sp)
   addiu  $sp, $sp, 4
   lw     $ra, 4($sp)
   addiu  $sp, $sp, 4
   addiu  $sp, $sp, 4
   li    $v0,10
   syscall


