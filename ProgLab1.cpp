#include "iostream"
using namespace std;
typedef struct Dishes* stack;
void menu();
bool marker1=false;
bool marker2=true;

struct Dishes{
    int data;
    stack next;
};
void Push(stack* stock, int data){
    stack now=(stack)malloc(sizeof(stack));
    now->data=data;
    now->next=*stock;
}
void Pop(stack* stock){
    stack f=(*stock)->next;
    free(*stock);
    *stock=f;
}
int GetData(stack* stock){
    stack got=(*stock);
    return got->data;
}
void Add(stack* stock){
    int number;
    cout << "Enter stack's numbers. Stack's end - 0\n";
    while(cin >> number and number!=0){
        Push(stock, number);
    }
    marker1=true;
    menu();
}
void Read(stack* stock){
    int exit;
    int fit = sizeof(stock);
    cout << "!!!==<THIS PROCEDURE DELETE STACK>==!!!\n";
    cout << "|==<1. Exit to menu>===<2. Continue>==|\n";
    cin >> exit;
    switch (exit){
        case 1:
            menu();
            break;
        case 2:
            if(marker1){
                while(fit){
                    cout << GetData(stock) << "\n";
                    fit--;
                    Pop(stock);
                }
                cout << "|===============<Done>================|\n";
                marker1=false;
                menu();
            }
            else{
                cout << "|=====<Stack didn't create>=====|\n";
                menu();
            }
            break;
        default:
            cout << "|======<Incorrect options>======|\n";
            menu();
    }
}
void AnalogPop(stack* stock){
    int col;
    cout << "|==<Enter quantity for delete>==|\n";
    cout << "|==========<0-nothing>==========|\n";
    cin >> col;
    while(col){
        Pop(stock);
    }
    cout << "|===========<Deleted>===========|\n";
    menu();
}
void menu(){
    int mode;
    stack* dwarf;
    if(marker2){
        dwarf=nullptr;
    }
    marker2=false;
    cout << "\n";
    cout << "|===========<OPTIONS>===========|\n";
    cout << "|========<1. Read stack>========|\n";
    cout << "|========<2. Add number>========|\n";
    cout << "|========<3. Pop number>========|\n";
    cout << "|===========<0. Exit>===========|\n";
    cout << "|===<Enter number for select>===|\n";
    cin >> mode;
    switch (mode){
        case 1:
            Read(dwarf);
            break;
        case 2:
            Add(dwarf);
            break;
        case 3:
            AnalogPop(dwarf);
            break;
        case 0:
            break;
        default:
            cout << "|======<Incorrect options>======|\n";
            menu();
    }
}
int main(){
    menu();
}