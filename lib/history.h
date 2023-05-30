#include <iostream>
#include <stack>
#include <string>
using namespace std;

class stackHistory {
private:
    int size;
    stack<string> history;

public:
    stackHistory() {
        size = 0;
    }

    void push(const string& s) {
        history.push(s);
        size++;
    }

    void pop() {
        if (!history.empty()) {
            history.pop();
            size--;
        }
    }

    string get_top() {
        if (!history.empty()) {
            return history.top();
        }
        return "";
    }

    bool is_empty() {
        return history.empty();
    }

    void showHistory() {
        if (is_empty()) {
            cout << "      History is empty" << endl;
            cout << "  let's watch some videos!" << endl << endl << endl;
        }
        else {
            stack<string> tempStack = history;
            int count = 1;
            while (!tempStack.empty()) {
                cout << count << ". " << tempStack.top() << endl;
                tempStack.pop();
                count++;
            }
        }
    }

    void clearHistory() {
        while (!history.empty()) {
            history.pop();
        }
        size = 0;
        cout << "**History has been cleared**" << endl << endl << endl;
    }
};


