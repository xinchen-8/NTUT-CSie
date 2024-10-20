.data
comma: .asciiz ","
.text
.globl main

main: #int main(){
    addi $sp, $sp, -400 #int x[100]->$s0; #int n->$s1;
    add $s0, $zero, $sp
    li $t0, 1 #x[0]=1;
    sw $t0, 0($s0)
    li $s2, 1 #for(int i=1->$s2; i<100; i++) x[i]=0;
    main_for1:
        slti $t0, $s2, 100
        beq $t0, $zero, main_for1_break
        sll $t0, $s2, 2
        add $t0, $t0, $s0
        addi $s2, $s2, 1
        j main_for1
    main_for1_break: #scanf("%d", &n);
        li $v0, 5
        syscall
        add $s1, $zero, $v0
        add $a0, $zero, $s1 #fact(n, x);
        add $a1, $zero, $s0
        jal fact
        add $a0, $zero, $s1 #print(n, x);
        add $a1, $zero, $s0
        jal print
    li $v0, 10 #return 0;}
    syscall

fact: #int fact (int n, int *x) {
    addi $sp, $sp, -8
    sw $s0, 0($sp)
    sw $s1, 4($sp)
    
    li $s0, 0 #int t=0->$s0;
    slti $t0, $a0, 2 #if (n < 2) {x[n] = t = 1; return t;}
    beq $t0, $zero, fact_else1
    li $s0, 1
    sll $t0, $a0, 2
    add $t0, $t0, $a1
    sw $s0, 0($t0)
    add $v0, $zero, $s0
    j return_main
    
    fact_else1: #else {x[n] = t = fact(n - 1, x) + fact(n - 2, x); return t;}}
        addi $sp, $sp, -12
        sw $a0, 0($sp)
        sw $a1, 4($sp)
        sw $ra, 8($sp)

        addi $a0, $a0, -2
        jal fact
        add $t0, $zero, $v0

        addi $sp, $sp, -4
        sw $t0, 0($sp)

        lw $a0, 4($sp)
        lw $a1, 8($sp)
        addi $a0, $a0, -1
        jal fact
        add $t1, $zero, $v0

        lw $t0, 0($sp)
        addi $sp, $sp, 4

        lw $a0, 0($sp)
        lw $a1, 4($sp)
        lw $ra, 8($sp)
        addi $sp, $sp, 12

        ##x[n] = t = $t0 + $t1
        add $s0, $t0, $t1
        sll $t0, $a0, 2
        add $t0, $t0, $a1
        sw $s0, 0($t0)
        add $v0, $zero, $s0

    return_main:
        lw $s0, 0($sp)
        lw $s1, 4($sp)
        addi $sp, $sp, 8
        jr $ra


print: #void print(int size, int *x) {
    addi $sp, $sp, -8
    sw $s0, 0($sp)
    sw $s1, 4($sp)
    li $s0, 0
    print_for1: #for (int i=0; i<size; i++) {
        slt $t0, $s0, $a0 
        beq $t0, $zero, print_for1_break
        add $t1, $zero, $a0
        
        sll $t0, $s0, 2 #printf("%d,",x[i]);}}
        add $t0, $t0, $a1
        lw $a0, 0($t0)
        li $v0, 1
        syscall
        la $a0, comma
        li $v0, 4
        syscall

        add $a0, $zero, $t1
        addi $s0, $s0, 1
        j print_for1
    
    print_for1_break:
        lw $s0, 0($sp)
        lw $s1, 4($sp)
        addi $sp, $sp, 8