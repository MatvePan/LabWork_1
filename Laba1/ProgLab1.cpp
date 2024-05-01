#include "iostream"
using namespace std;

struct Number{
    int data;
    Number* last;
    Number(int data):data(data), last(nullptr){};
};
struct Stack{
    Number* lest;
    Stack():lest(nullptr){};
    bool empty(){
        return lest==nullptr;
    }
    void Push(int data){
        Number* steck=new Number(data);
        if(empty()){
            lest=steck;
        }
        else{
            steck->last=lest;
            lest=steck;
        }
    }
    int Pop(){
        int num=lest->data;
        Number* del=lest;
        lest=lest->last;
        delete del;
        return num;
    }
};
int main(){
    bool mode=false; //true - режим с интерфейсом, falce - режим без
    if(mode)cout << "|====<Enter numbers for stack>====|\n";
    if(mode)cout << "|========<Stack's end - 0>========|\n";
    Stack dwarf;
    int number;
    while(cin >> number and number!=0){
        if(number>0){
            dwarf.Push(number);
        }
    }
    if(mode)cout << "|=========<Display stack>=========|\n";
    while(!dwarf.empty()){
        cout << dwarf.Pop() << "\n";
    }
    if(mode)cout << "|==============<Done>=============|\n";
}