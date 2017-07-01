.data # data section
arr_a: .word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19
arr_b: .word 0x7fffffff, 0x7ffffffe, 0x7ffffffd, 0x7ffffffc, 0x7ffffffb, 0x7ffffffa, 0x7ffffff9, 0x7ffffff8, 0x7ffffff7, 0x7ffffff6 
sum_a: .asciiz "Sum a = "
sum_b: .asciiz "Sum b = "
new_line: .asciiz "\n"

.text # text section

.globl main # call main by SPIM

main :

li $t0 , 0 # i
li $t1 , 0 # sum
la $t2 , arr_a # a[]
la $t3 , arr_b # b[]
  
for1:
   
lw $t4 , ($t2) #a[i]
add $t1 , $t1 , $t4 #sum+=a[i]
addi $t2 , $t2 , 4 #a[i+1]
addi $t0 , $t0 , 1 #i++
blt $t0 , 20 , for1 # i<20
 
li $v0, 4 
la $a0, sum_a
syscall # print "Sum a = "
     
li $v0, 1
move $a0, $t1
syscall  # print value sum

li $v0, 4 
la $a0, new_line
syscall # new line
      
li $t0 , 0 # i
li $t1 , 0 # sum

 
for2:   
lb $t5, 0($t3) #load b[i]
add $t1, $t1, $t5  # sum  += b[i]
addi $t3, $t3, 4  # b[i+1]
addi $t0, $t0, 1 # i++
blt $t0, 10, for2  # i < 10
  
li $v0, 4
la $a0, sum_b # print "Sum b = "
syscall
     
li $v0, 1
move $a0, $t1 # print sum b
syscall

li $v0, 4 
la $a0, new_line
syscall # new line
  
li $v0, 10
syscall
