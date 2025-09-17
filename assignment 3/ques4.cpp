#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3; 
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for(int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        
        if(isalnum(c)) {
            postfix += c;
        }
        
        else if(c == '(') {
            st.push(c);
        }
        
        else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop(); 
        }
        
        else if(isOperator(c)) {
            while(!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression \n";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression \n" << postfix << endl;

    return 0;
}
