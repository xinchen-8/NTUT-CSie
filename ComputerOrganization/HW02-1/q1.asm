.data
underweight:  .asciiz "underweight\n"
overweight:  .asciiz "overweight\n"
endl: .asciiz "\n"

.text
.globl main
main:
#int height->$s0, weight->$s1, bmi->$s2;
loop:
  li  $v0, 5 #scanf("%d", &height);
  syscall
  add $s0, $zero, $v0

  #if (height == -1)
  #break;
  li  $t0, -1
  beq $s0, $t0, exit_program
 
  li  $v0, 5 #scanf("%d", &weight);
  syscall
  add $s1, $zero, $v0

#bmi = calculateBMI(height, weight);
  add $a0, $zero, $s0
  add $a1, $zero, $s1
  jal calculate_BMI
  add $s2, $zero, $v0

#printResult(bmi);
  add $a0, $zero, $s2
  jal print_result
  j loop

# int calculateBMI(int height, int weight) {
#  int bmi = (weight * 10000) / (height * height);
#  return bmi;
# }

calculate_BMI:
  addi  $sp, $sp, -8
  sw  $s0, 0($sp)
  sw  $s1, 4($sp)

  mult  $a0, $a0			
  mflo	$t0

  li  $t1, 10000
  mult  $a1, $t1
  mflo  $t1

  div $t1, $t0
  mflo $s0
  add $v0, $zero, $s0

  lw  $s0, 0($sp)
  lw  $s1, 4($sp)
  addi  $sp, $sp, 8
  jr  $ra

# void printResult (int bmi) {
#  if (bmi <= 17)
#  printf("%s", "underweight\n");
#  else if (bmi >= 25)
#  printf("%s", "overweight\n");
#  else
#  printf("%d\n", bmi);
# }

print_result:
  addi $sp, $sp, -12
  sw $s0, 0($sp)
  sw $s1, 4($sp)
  sw $s2, 8($sp)

  li $t0, 17
  slt $t1, $t0, $a0
  bne $t1, $zero, print_else25

  la  $a0, underweight
  li  $v0, 4
  syscall
  j print_end

print_else25:
  li  $t0, 25
  slt $t1, $a0, $t0
  bne $t1, $zero, print_else

  la  $a0, overweight
  li  $v0, 4
  syscall
  j print_end

print_else:
  li  $v0, 1
  syscall
  la  $a0, endl
  li  $v0, 4
  syscall

print_end:
  lw  $s0, 0($sp)
  lw  $s1, 4($sp)
  lw  $s2, 8($sp)
  jr  $ra
  
exit_program:
 li $v0, 10 #return 0;
 syscall 