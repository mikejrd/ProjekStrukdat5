// bikin stack isinya history video yg di play
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class stackHistory{
    private:
        int top;
        int size;
        string *arr;
        
    public:
    stackHistory(){
        top = -1;
        size = 0;
        arr = new string[size];
    }
    void push(string s){
        top++;
        size++;
        arr[top] = s;
    }
    void pop(){
        top--;
        size--;
    }
    string get_top(){
        return arr[top];
    }
    bool is_empty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
    void showHistory(){
        if (is_empty())
        {
            cout << "History is empty" << endl;
        }
        else{
            for(int i = 0; i < size; i++){
                cout << i+1 << ". " << arr[i] << endl;
            }
        }
    }
};
