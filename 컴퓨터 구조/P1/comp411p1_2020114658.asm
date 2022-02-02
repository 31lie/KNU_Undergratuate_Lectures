# -------------------------------------------------------------------
# [KNU COMP411 Computer Architecture] Skeleton code for the 1st project (calculator)
# -------------------------------------------------------------------

.data
string: .space 500


.text	
# main
main:
	
	jal x1, test #functionality test, Do not modify!!
	
	#----TODO-------------------------------------------------------------
	#1. read a string from the console
	#2. perform arithmetic operations
	#3. print a string to the console to show the computation result
	#----------------------------------------------------------------------
	
re_calc:
	li a7, 8 	# Read a String from console
	la a0, string 	# a0 : address of input buffer
	li a1, 250	# a1 : maximum number of characters to read
	ecall
	
	# initialize
	li a1, 0
	li a2, 0
	li a3, 0
	
	la t0, string	# t0 : string pointer

# For first operand
main_part1:
	li t1, 48		# 48 : string -> int (ascii)
	lb t2, 0(t0)		# load byte for first character of string
	bge t2, t1, main_part2	# branch if t2 is first the first operand (unsigned number)
		
	li t1, 43		# 43 : ascii code for '+'
	beq t2, t1, go_add
	
	li t1, 45		# 45 : ascii code for '-'
	beq t2, t1, go_sub
	
	li t1, 42		# 42 : ascii code for '*'
	beq t2, t1, go_mul
	
	li t1, 47		# 45 : ascii code for '/'
	beq t2, t1, go_div
	
# Put right operand in a2 
# (ex. 451 -> 10*4 = 40 -> 40+5=45 -> 45*10=450 -> 450+1 = 451)
main_part2:
	li t1, 10
	#mul a2, a2, t1	
	# a2 *= 10 
	li t6, 9
	li t5, 0
	li t4, 0
	add t4, t4, a2		

mul_10_loop_1 : 
	add a2, a2, t4
	addi t5, t5, 1
	bne t5, t6, mul_10_loop_1

	lb t1, 0(t0)
	add a2, a2, t1
	addi a2, a2, -48
	addi t0, t0, 1		# move pointer
	j main_part1



# Put operation number in a1 for each case
go_add:
	li a1, 0
	j main_part3

go_sub:
	li a1, 1
	j main_part3

go_mul:
	li a1, 2
	j main_part3

go_div:
	li a1, 3
	j main_part3


# For second operand
main_part3:
	addi t0, t0, 1		# move pointer to next for passing operator
	lb t1, 0(t0)
	li t2, 10		# 10 : ascii code for '\n'
	beq t1, t2, print_string	# if t0 == '\n', that is when calc finishes, break
	
	# put right operand, same as the first operand
	#li t1, 10
	#mul a3, a3, t1
	li t6, 9
	li t5, 0
	li t4, 0
	add t4, t4, a3
	
mul_10_loop_2 : 
	add a3, a3, t4
	addi t5, t5, 1
	bne t5, t6, mul_10_loop_2

	lb t1, 0(t0)
	add a3, a3, t1
	addi a3, a3, -48
	j main_part3

# print String
print_string:
	la t0, string
	li t2, 10
	

	
main_part4:
	li a7, 11
	lb a0, 0(t0)
	ecall
	addi t0, t0, 1		# move to next
	lb t1, 0(t0)
	bne t1, t2, main_part4
	
	# print '='
	li a0, 61	# 61 : ascii code for '='
	li a7, 11
	ecall
	
	# go calculate
	jal x1, calc
	
	# Print result

	li a7, 1
	ecall
	
	li a0, 10
	li t6, 3
	# if div, print remainder
	bne a1, t6, pass_print_remainder
	li a0, 44
	li a7, 11
	ecall
	li t6, 0
	add a0, t6, a4
	li a7, 1
	ecall
	
pass_print_remainder:
	li a0, 10
	li a7, 11
	ecall
	
	# recalculate
	jal x1, re_calc
	
	# Exit (93) with code 0
        li a0, 0
        li a7, 93
        ecall
        ebreak


#----------------------------------
#name: calc
#func: performs arithmetic operation
#x11(a1): arithmetic operation (0: addition, 1:  subtraction, 2:  multiplication, 3: division)
#x12(a2): the first operand
#x13(a3): the second operand
#x10(a0): return value
#x14(a4): return value (remainder for division operation)
#----------------------------------
calc:
	
	add t6, a1, zero
	
	li t5, 0
	beq t5, t6, calc_add
	
	addi t5, t5, 1
	beq t5, t6, calc_sub
	
	addi t5, t5, 1
	beq t5, t6, calc_mul
	
	addi t5, t5, 1
	beq t5, t6, calc_div
	
calc_add:
	add a0, a2, a3
	
	j calc_return

calc_sub:
	neg t5, a3
	add a0, a2, t5

	j calc_return
	
calc_mul:
	li a0, 0
	addi t0, a2, 0			# a2 -> t0
	addi t2, a3, 0			# a3 -> t2
	
	addi t5, zero, 1		# t5 = 1
	
	li t3, 0			# t3 for repetition check			
	addi t4, zero, 32		# t4 for 32bit
	
mul_test:
	andi t6, t2, 1			# t6 for LSB
	beq t6, t5, mul_add		# if t5 == 1  
	j mul_pass
	
mul_add:
	add a0, t0, a0
	
mul_pass:
	slli t0, t0, 1
	srli t2, t2, 1
	addi t3, t3, 1
	
	beq t3, t4, calc_return
	j mul_test
	
calc_div:
	li a0, 0
	
	addi t3, a3, 0	# put t3 <- a3
	addi a4, a2, 0	# put a4 <- a2
	
	li t5, 17	# check for repetiton
	li t6, 0

	slli t3, t3, 16	# shift Divisor
	
	
div_test:
	neg t3, t3
	add a4, a4, t3
	neg t3, t3
	# if t2 >= 0
	bge a4, zero, div_bigger
	j div_smaller

div_bigger:
	slli a0, a0, 1
	addi a0, a0, 1
	j div_shift
	
div_smaller:
	# if t2 < 0, restore the origin value
	add a4, a4, t3
	slli a0, a0, 1
	
div_shift: 
	addi t6, t6, 1
	srli t3, t3, 1
	beq t5, t6, calc_return
	
	j div_test
	
calc_return:
	
	jalr x0, 0(x1)



.include "common.asm"
