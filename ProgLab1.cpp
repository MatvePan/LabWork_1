#include "iostream"
using namespace std;
typedef struct Dishes* stack;

struct Dishes{
    int data;
    stack next;
};
void Push(stack* stock, int data){
    auto now=(stack)malloc(sizeof(stack));
    now->data=data;
    now->next=*stock;
    *stock=now;
}
void Pop(stack* stock){
    stack f=(*stock)->next;
    free(*stock);
    *stock=f;
}
int main(){
    bool mode= true; //true - режим с интерфейсом, falce - режим без
    if(mode)cout << "|====<Enter numbers for stack>====|\n";
    if(mode)cout << "|========<Stack's end - 0>========|\n";
    stack dwarf;
    dwarf=nullptr;
    int number;
    cin >> number;
    while(number!=0){
        if(number>0){
            Push(&dwarf, number);
            cin >> number;
        }
    }
    if(mode)cout << "|=========<Display stack>=========|\n";
    while(dwarf){
        cout << dwarf->data << "\n";
        Pop(&dwarf);
    }
    if(mode)cout << "|==============<Done>=============|\n";
}