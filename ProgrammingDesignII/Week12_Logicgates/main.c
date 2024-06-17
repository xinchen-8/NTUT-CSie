#include <stdio.h>
#define GATEVALUE(Gate) int(*GateValue)()

typedef struct _Gate {
int input1;
int input2;
GATEVALUE(Gate);
}Gate;

int GateORValue(Gate *gate) {
    return gate->input1 | gate->input2;
}
int GateANDValue(Gate *gate) {
    return gate->input1 & gate->input2;
}
int GateNOTValue(Gate *gate) {
    return !gate->input1;
}
int GateBUFFERValue(Gate *gate) {
    return gate->input1;
}

void CreateGate(Gate *obj, char type, int input1, int input2) {
    obj->input1 = input1;
    obj->input2 = input2;
    switch(type){
        case 'N': obj->GateValue = GateNOTValue; break;
        case 'B': obj->GateValue = GateBUFFERValue; break;
        case 'A': obj->GateValue = GateANDValue; break;
        case 'O': obj->GateValue = GateORValue; break;
    }
}

int main(){
    int x1, x2, x3;
    scanf("%d %d %d", &x1, &x2, &x3);

    char t1, t2, t3;
    scanf(" %c %c %c", &t1, &t2, &t3);

    Gate g1, g2, g3;
    CreateGate(&g1, t1, x1, 0);
    int y1 = g1.GateValue(&g1);

    CreateGate(&g2, t2, x2, y1);
    int y2 = g2.GateValue(&g2);
    
    CreateGate(&g3, t3, x3, y2);
    int y3 = g3.GateValue(&g3);

    printf("%d %d %d\n", y1, y2, y3);
    return 0;
}
