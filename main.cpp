#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;
#include <stack>
char reverseBrace(char c){
    if (c == ')')
        return '(';
    return (c == '}' ? '{' : '[');
}

int main() {
    Stack<int>st;
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(i);
        }

        else if (s[i] == ')' || s[i] == '}' || s[i] == ']'){
            if(st.isEmpty()){
                cout << i + 1;
                return 0;
            }
            else if (s[st.top()] == reverseBrace(s[i])){
                st.pop();
            }

            else {
                cout << i + 1;
                return 0;
            }
        }
    }
    if (!st.isEmpty()){
        cout << st.top() + 1;
        return 0;
    }
    cout << "Success";
    return 0;
}