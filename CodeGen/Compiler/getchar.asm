.text
.globl main

main:
    li $t0, 10

    li $v0, 12
    syscall
    addiu $a0, $v0, 0

    li $v0, 1
    syscall 

    li $v0, 10
    syscall 

