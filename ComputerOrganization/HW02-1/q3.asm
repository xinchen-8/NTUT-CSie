.data
.text
.globl main
main: #int main() {
    addi $sp, $sp, -20 #int array[5]->$s0;
    add $s0, $zero, $sp
    li $s1, 0 #int i=0->$s1
    main_for1: #for (int i = 0; i < 5; i++){scanf("%d", &array[i]);}
        slti $t0, $s1, 5
        beq $t0, $zero, main_for1_break
        li $v0, 5
        syscall
        sll $t0, $s1, 2
        add $t0, $t0, $s0
        sw $v0, 0($t0)
        addi $s1, $s1, 1
        j main_for1
    main_for1_break:
        add $a0, $zero, $s0 #selectionSort(array, 5);
        li $a1, 5
        jal selectionsort

    li $s1, 0 #i->$s1
    main_for2: #for (int i = 0; i < 5; i++) {
        slti $t0, $s1, 5
        beq $t0, $zero, main_for2_break

        add $t0, $zero, $a0
        sll $t1, $s1, 2
        add $t1, $t1, $t0
        lw $a0, 0($t1)
        li $v0, 1 #printf("%d\n", array[i]);}
        syscall
        li $a0, 0xA
        li $v0, 0xB
        syscall
        add $a0, $zero, $t0

        addi $s1, $s1, 1
        j main_for2
    main_for2_break:
    li $v0, 10#return 0;}
    syscall

selectionsort: #void selectionSort(int array[], int n) {
    addi $sp, $sp, -8
    sw $s0, 0($sp)
    sw $s1, 4($sp)

    li $s0, 0 #i->$s0
    selectionsort_for1: #for (int i=0; i<n-1; i++) {
    
        add $s2, $zero, $s0 #int min_idx = i->$s2;
        addi $t0, $a1, -1
        slt $t0, $s0, $t0
        beq $t0, $zero, selectionsort_for1_break
        
        addi $s1, $s0, 1 #j->i+1
        selectionsort_for2: #for (int j=i+1; j<n; j++) {
            slt $t0, $s1, $a1
            beq $t0, $zero, selectionsort_for2_break

            sll $t0, $s2, 2 #if (array[j] < array[min_idx])
            add $t0, $t0, $a0
            lw $t1, 0($t0)
            sll $t2, $s1, 2
            add $t2, $t2, $a0
            lw $t3, 0($t2)

            slt $t0, $t3, $t1 
            beq $t0, $zero, selectionsort_else1
            add $s2, $zero, $s1 #{ min_idx = j;}
            selectionsort_else1:

            addi $s1, $s1, 1
            j selectionsort_for2
            selectionsort_for2_break: #}

            sll $t0, $s2, 2 #int temp->$s3 = array[min_idx];
            add $t0, $t0, $a0
            lw $s3, 0($t0)

            sll $t1, $s0, 2 #array[min_idx] = array[i];
            add $t1, $t1, $a0
            lw $t2, 0($t1)
            sw $t2, 0($t0)
            sw $s3, 0($t1) #array[i] = temp;}}

        addi $s0, $s0, 1
        j selectionsort_for1
    selectionsort_for1_break:

    lw $s0, 0($sp)
    lw $s1, 4($sp)
    addi $sp, $sp, 8
    jr $ra
