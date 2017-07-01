.data # data section
space: .asciiz " "
.text # text section
.globl main # call main by SPIM

my_recursive_func:

addi $sp, $sp, -8
sw $ra, 4($sp)
sw $fp, 0($sp)
move $fp, $sp
lw $t0, 8($fp) #n


ble $t0, 0, exit #base case

li $v0, 1
move $a0, $t0 #print n
syscall

li $v0, 4
la $a0, space #print space
syscall


addi $t1 $t0 -2 #n-2
addi $sp $sp -4 #down stack
sw $t1 0($sp) #keep n


jal my_recursive_func #recur

addi $sp $sp 4 #up stack
lw $t0 8($fp) #load n
addi $t1, $t0, -3 #n-3
addi $sp, $sp, -4 # down stack
sw $t1 0($sp) #keep n


jal my_recursive_func #recur



addi $sp, $sp, 4 #up stack
lw $t0, 8($fp)
lw $ra, 4($fp)
lw $fp, 0($fp)
addi $sp, $sp, 8 

li $v0, 1
move $a0, $t0 #print n
syscall

li $v0, 4
la $a0, space #print space
syscall

jr $ra #call back


exit:

lw $ra, 4($fp)
lw $fp, 0($fp)
addi $sp, $sp, 8 # up stack
jr $ra # call back

main:
addi $sp, $sp, -4 # down stack
li $t0, 6 # n = 6
sw $t0, 0($sp) # save to stack
jal my_recursive_func # go to function
addi $sp, $sp, 4 # up stack
li $v0, 10 #END
syscall

