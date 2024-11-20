.data
space: .asciiz " "
.text
.globl main
main: #int main(){
    addi $sp, $sp, -36 #int A[3][3]->$s0;
    add $s0, $zero, $sp
    addi $sp, $sp, -36 #int transposeOfA1[3][3]->s1;
    add $s1, $zero, $sp
    addi $sp, $sp, -36 #int transposeOfA2[3][3]->$s2;
    add $s2, $zero, $sp
    add $s3, $zero, $s0 #int *ptrA->$s3  = &A[0][0];
    add $s4, $zero, $s2 #int *ptrTA2->$s4  = &transposeOfA2[0][0];

    add $a0, $zero, $s0
    jal inputmatrix #inputMatrix(A);

    add $a0, $zero, $s0
    add $a1, $zero, $s1
    li $a2, 3
    jal transposematrixa1 #transposeMatrixA1(A, transposeOfA1, 3);

    add $a0, $zero, $s3
    add $a1, $zero, $s4
    li $a2, 3
    jal transposematrixa2 #transposeMatrixA2(ptrA, ptrTA2, 3);

    add $a0, $zero, $s1
    jal outputmatrix #outputMatrix(transposeOfA1);

    add $a0, $zero, $s2
    jal outputmatrix #outputMatrix(transposeOfA2);
    
    li $v0, 10
    syscall #return 0;}


inputmatrix: #void inputMatrix(int A[3][3]) {
    addi $sp, $sp, -8
    sw $s0, 0($sp)
    sw $s1, 4($sp)

    li $s0, 0 #i<-$s0
    inputmatrix_for1: #for (int i = 0; i < 3; i++) {
        slti $t0, $s0, 3
        beq $t0, $zero, inputmatrix_for1_break
            
            li $s1, 0 #j<-$s1
            inputmatrix_for2: #for (int j = 0; j < 3; j++) {
                slti $t0, $s1, 3
                beq $t0, $zero, inputmatrix_for2_break
                    
                    li $v0, 5 #scanf("%d", &A[i][j]);
                    syscall

                    li $t0, 3
                    mult $t0, $s0
                    mflo $t0
                    add $t1, $t0, $s1
                    sll $t0, $t1, 2
                    add $t0, $t0, $a0
                    sw $v0, 0($t0)

                addi $s1, $s1, 1 #}
                j inputmatrix_for2
            inputmatrix_for2_break:
        
        addi $s0, $s0, 1 #}
        j inputmatrix_for1
    inputmatrix_for1_break:
    lw $s0, 0($sp)#}
    lw $s1, 4($sp)
    addi $sp, $sp, 8
    jr $ra


transposematrixa1: #void transposeMatrixA1(int A[3][3], int T[3][3], int size) {
    addi $sp, $sp, -8
    sw $s0, 0($sp)
    sw $s1, 4($sp)
    
    li $s0, 0 #i<-$s0
    transposematrixa1_for1: #for (int i = 0; i < size; i++) {
        slt $t0, $s0, $a2
        beq $t0, $zero, transposematrixa1_for1_break

        li $s1, 0 #j<-$s1
        transposematrixa1_for2: #for (int j = 0; j < size; j++) {
            slt $t0, $s1, $a2
            beq $t0, $zero, transposematrixa1_for2_break
            
                li $t2, 3 #T[j][i] = A[i][j];
                mult $t2, $s0
                mflo $t0
                add $t0, $t0, $s1
                sll $t1, $t0, 2
                add $t1, $t1, $a0
                lw $t0, 0($t1)

                li $t2, 3
                mult $t2, $s1
                mflo $t1
                add $t1, $t1, $s0
                sll $t2, $t1, 2
                add $t2, $t2, $a1
                sw $t0, 0($t2)

            addi $s1, $s1, 1
            j transposematrixa1_for2
        transposematrixa1_for2_break: #}

        addi $s0, $s0, 1
        j transposematrixa1_for1
    transposematrixa1_for1_break: #}
    lw $s0, 0($sp) #}
    lw $s1, 4($sp)
    addi $sp, $sp, 8
    jr $ra

transposematrixa2: #void transposeMatrixA2(int *B, int *T, int size) {
    addi $sp, $sp, -12
    sw $s0, 0($sp)
    sw $s1, 4($sp)
    sw $s2, 8($sp)

    #int *ptrB<-$s0, *ptrT<-$s1, i<-$s2;
    add $s0, $zero, $a0
    add $s1, $zero, $a1
    li $s2, 1
    transposematrixa2_for1: #for (ptrB=B, ptrT=T, i = 1; ptrB<(B + (size*size)); ptrB++) {
        mult $a2, $a2
        mflo $t0
        sll $t1, $t0, 2
        add $t1, $t1, $a0
        slt $t0, $s0, $t1
        beq $t0, $zero, transposematrixa2_for1_break

        lw $t0, 0($s0) #*ptrT = *ptrB;
        sw $t0, 0($s1)
        
        slt $t0, $s2, $a2 #if (i < size) {
        beq $t0, $zero, transposematrixa2_else1
        
            sll $t0, $a2, 2
            add $s1, $s1, $t0 #ptrT += size;
            addi $s2, $s2, 1 #i++;}

        j transposematrixa2_endif1
        transposematrixa2_else1: #else {
            
            addi $t0, $a2, -1 #ptrT -= (size * (size - 1) - 1);
            mult $t0, $a2
            mflo $t0
            addi $t0, $t0, -1
            sll $t1, $t0, 2
            sub $s1, $s1, $t1
            li $s2, 1 #i = 1;}

        transposematrixa2_endif1:
        addi $s0, $s0, 4
        j transposematrixa2_for1
    transposematrixa2_for1_break: #}

    lw $s0, 0($sp)#}
    lw $s1, 4($sp)
    lw $s2, 8($sp)
    addi $sp, $sp, 12
    jr $ra

outputmatrix: #void outputMatrix(int A[3][3]) {
    addi $sp, $sp, -8
    sw $s0, 0($sp)
    sw $s1, 4($sp)

    li $s0, 0 #i<-$s0
    outputmatrix_for1: #for (int i = 0; i < 3; i++) {
        slti $t0, $s0, 3
        beq $t0, $zero, outputmatrix_for1_break
        
        li $s1, 0
        outputmatrix_for2: #for (int j = 0; j < 3; j++) {
            slti $t0, $s1, 3
            beq $t0, $zero, outputmatrix_for2_break

                add $t0, $zero, $a0 #printf("%d ", A[i][j]);
                li $t1, 3
                mult $s0, $t1
                mflo $t1
                add $t2, $t1, $s1
                sll $t1, $t2, 2
                add $t1, $t1, $t0
                lw $a0, 0($t1) 
                li $v0, 1
                syscall
                la $a0, space
                li $v0, 4
                syscall
                add $a0, $zero, $t0

            addi $s1, $s1, 1#}
            j outputmatrix_for2
        outputmatrix_for2_break:

        add $t0, $zero, $a0 #printf("\n");
        li $a0, 0xA
        li $v0, 0xB
        syscall
        add $a0, $zero, $t0
        
        addi $s0, $s0, 1 #}
        j outputmatrix_for1
    outputmatrix_for1_break:
    lw $s0, 0($sp)#}
    lw $s1, 4($sp)
    addi $sp, $sp, 8
    jr $ra
