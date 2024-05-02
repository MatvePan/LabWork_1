#include "iostream"
#include "cstring"
using namespace std;

struct Number {
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
    void Push(int data) {
        Number* steck=new Number(data);
        if (empty()){
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
    int Show(){
        return lest->data;
    }
};
int main(int args, char* argv[]) {
    bool mode=true; //true - режим с интерфейсом, false - режим без
    for(int i = 0; i < args; i++)
        if (_stricmp(argv[i], "false")==0)mode=false;
    if(mode)cout << "|====<Enter numbers for stack>====|\n";
    if(mode)cout << "|========<Stack's end - 0>========|\n";
    Stack dwarf;
    int number;
    while (cin >> number and number != 0) {
        dwarf.Push(number);
    }
    if(mode)cout << "|=========<Display stack>=========|\n";
    while(!dwarf.empty()){
        if(dwarf.Show()>0)
            cout << dwarf.Pop() << "\n";
        else
            dwarf.Pop();
    }
    if(mode)cout << "|==============<Done>=============|\n";
}