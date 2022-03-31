.data
char:   .space 4        # Need 2 because of the null byte at the end (I think)

.text
main:

        li $v0, 8               # System call code for read_string
        la $a0, char    # a0 is the address of the space
        la $a1, 2               # a1 is the length that needs to be read/stored
        syscall         # Call read_string

        lw $a0, 0($a0)
        li $v0, 1               # Print string
        syscall

        li $v0, 10
        syscall
