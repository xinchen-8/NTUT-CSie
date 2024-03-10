#include <stdio.h>


#define chesscolor 2    //1黑子 2白子
#define target_txt "a.txt" //溝通的txt檔案
#define mapsize 25

//檢視棋盤
void openMap(int localmap[mapsize][mapsize]){
    for(int i=0;i<mapsize;i++){
        for(int j=0;j<mapsize;j++){
            printf("%d ",localmap[i][j]);
        }
        printf("\n");
    }
}


////前三子的範圍外屏蔽

////黑子的禁子屏蔽


////棋盤座標格式轉換器

//writeBackServer


//writeChessBoard(主要判斷)



//讀取對方下棋位置並更新至本地棋盤
int readChess(int (*lmpptr)[mapsize]){
    FILE *fileptr = fopen(target_txt,"r");
    char buffer;
    int x,y;

    fscanf(fileptr, "%c\n %d %d", &buffer,&x,&y);
    printf("%c %d %d\n", buffer,x,y);

    if(buffer=='W'){
        //存至本地棋盤
        *(*(lmpptr+x)+y) = chesscolor ^ 3;
        

        return 1;
    }
    else return 0;

}

int main(){

    int time = chesscolor + 1;
    
    int localmap[mapsize][mapsize] = {0};
    int weightmap[mapsize][mapsize] = {0};
    int (*lmpptr)[mapsize] = localmap;
    int (*wmpptr)[mapsize] = weightmap;

    readChess(lmpptr);
    openMap(localmap);


    return 0;
}