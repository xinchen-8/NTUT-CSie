#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
char data;
struct node_s *right, *left;
} tree_t;
typedef tree_t* btree;

btree create_IPtree(char *Infix, char *Prefix, int Istart, int Iend, int *Pindex){
    if(Istart > Iend) return NULL; 
    
    btree node = (btree)malloc(sizeof(tree_t));
    node->data = Prefix[*Pindex];
    node->left = node->right = NULL;
    (*Pindex)++;

    if(Istart == Iend) return node;
    else{ // Istart < Iend
        int index = Istart;
        while(Infix[index] != Prefix[*Pindex-1]) index++;
        node->left = create_IPtree(Infix, Prefix, Istart, index-1, Pindex);
        node->right = create_IPtree(Infix, Prefix, index+1, Iend, Pindex);
        return node;
    }
}

btree create_IOtree(char *Infix, char *Postfix, int Istart, int Iend, int *Oindex){// Oindex is the last
    if(Istart > Iend) return NULL; 
    
    btree node = (btree)malloc(sizeof(tree_t));
    node->data = Postfix[*Oindex];
    node->left = node->right = NULL;
    (*Oindex)--;

    if(Istart == Iend) return node;
    else{ // Istart < Iend
        int index = Istart;
        while(Infix[index] != Postfix[*Oindex+1]) index++;
        node->right = create_IOtree(Infix, Postfix, index+1, Iend, Oindex);
        node->left = create_IOtree(Infix, Postfix, Istart, index-1, Oindex);
        return node;
    }
}

void print_Ltree(btree Tree){
    btree queue[100];
    int start = 0, end = 0;
    queue[end++] = Tree;
    while (start < end) {
        btree current = queue[start++];
        printf("%c", current->data);
        if (current->left) queue[end++] = current->left;
        if (current->right) queue[end++] = current->right;
    }
    printf("\n");
}

int main(){
    char mode[2], tree_string[2][21];
    for(int i=0; i<2; i++){
        scanf(" %c ", mode+i);
        scanf(" %s", tree_string[i]);
    }

    btree Tree = NULL;
    int InfixIndex = (mode[0]=='I')? 0:1;

    if(mode[1-InfixIndex]=='P'){
        int Index = 0;
        Tree = create_IPtree(tree_string[InfixIndex], tree_string[1-InfixIndex], 0, strlen(tree_string[InfixIndex])-1, &Index);
    }
    else{
        int Index = strlen(tree_string[InfixIndex])-1;
        Tree = create_IOtree(tree_string[InfixIndex], tree_string[1-InfixIndex], 0, strlen(tree_string[InfixIndex])-1, &Index);
    }
    print_Ltree(Tree);

    return 0;
}