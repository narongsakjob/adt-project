.data # data section
data: .word 132470, 324545, -4, 73245, 93245, 80324542, 244, 2, 66, 236, 327, -7, 236, 21544
space: .asciiz " "
.text # text section
.globl main # call main by SPIM


rec_insertion_sort:

addi $sp, $sp, -8 
sw $ra, 4($sp)
sw $fp, 0($sp)
move $fp, $sp
lw $t1, 8($fp)# load max value



ble $t1 1  return # base case

addi $t9 $t1 -1 # maxIndex - 1
addi $sp $sp -4 # donw stack
sw $t9 0($sp) #keep max index

jal rec_insertion_sort #recur


addi $sp $sp 4 #up stack
move $t8 $v0 #  x = keep return in $t8


li $t4 0 #key
li $t0 0 #i
la $t2, data #index data


sll $t9 $t8 2 #shift
add $t4 $t2 $t9 #index of array
lw $t4 0($t4) #load key = a[x]
 
addi $t0 $t8 -1 # i = x-1



start:

sll $t7 $t0 2 #shift
add $t7 $t2 $t7 #i
lw $t3 0($t7) # load data[i]

bge $t0 0 check # i >= 9

j end # if not while

check: 

bgt $t3 $t4 while # a[i] > key

j end # if not while

while:
sw  $t3, 4($t7) # a[i+!] = a[i]
addi $t0, $t0, -1 # i--

j start # go check while


end: 

sw $t4, 4($t7)
lw $ra, 4($fp)
lw $fp, 0($fp) 

addi $sp, $sp, 8 #up stack
addi $v0, $t8, 1 # return value x+1
jr $ra # return 



return:

lw $ra, 4($fp)
lw $fp, 0($fp)
addi $sp, $sp, 8
add $v0, $0, $t0 #return max Index
jr $ra #return
 
main:
 
 
li $t1 14 #n

addi $sp, $sp, -4 # down stack
sw $t1 0($sp)  # save n in stack
  
jal rec_insertion_sort # go function

addi $sp $sp 4 # up stack

li $t0 0  # i
li $t1 14 # n
la $t2 data # index data
for:
lw $t3 0($t2) # data[i]
addi $t2 $t2 4 # data[i+1]

li $v0 1 
move $a0 $t3 # print data[i]
syscall

li $v0 4
la $a0 space # print space
syscall

addi $t0 $t0 1 # i++

blt  $t0 $t1 for # i < n
 
li $v0, 10 # END
syscall
