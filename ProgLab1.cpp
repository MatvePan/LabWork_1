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
    cout << "|====<Enter numbers for stack>====|\n";
    cout << "|========<Stack's end - 0>========|\n";
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
    cout << "|=========<Display stack>=========|\n";
    while(dwarf){
        cout << dwarf->data << "\n";
        Pop(&dwarf);
    }
    cout << "|==============<Done>=============|\n";
}