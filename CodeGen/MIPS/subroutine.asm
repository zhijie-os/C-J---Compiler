.text
.globl main

main:
    

    li $t0,1
    sw $t0,0($sp)
    subu $sp, $sp, 4

    li $t0,2
    sw $t0,0($sp)
    subu $sp, $sp, 4

    li $t0,2
    sw $t0,0($sp)
    subu $sp, $sp, 4

    li $a0,3
    jal loop_start


    addu $sp, $sp, 12

    li $v0, 10
    syscall 

loop_start:
    sw	 $ra, 0($sp)
    subu $sp, $sp, 4

    sw   $fp, 0($sp)
    subu $sp, $sp, 4

    li   $t0, 4
    mul  $t0, $t0, $a0

    move    $a0, $t0
    li      $v0, 1
    syscall

    addu $sp, $sp, 8
    lw  $ra, 0($sp)


    jr $ra
