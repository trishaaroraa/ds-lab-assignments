#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int operate(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;  
        case '*': return a * b;
        case '/': return a / b;  
        case '^': {
            int res = 1;
            for(int i=0; i<b; i++) res *= a;
            return res;
        }
        default: return 0;
    }
}

int evaluatePostfix(string postfix) {
    stack<int> st;

    for(int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if(c == ' ') continue;

        if(isdigit(c)) {
            st.push(c - '0'); 
        } 
        else if(isalpha(c)) {
            cout << "Enter value for " << c << ": ";
            int val;
            cin >> val;
            st.push(val);
        }
        
        else {
            if(st.size() < 2) {
                cout << "Invalid postfix expression \n";
                return -1;
            }
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int result = operate(a, b, c);
            st.push(result);
        }
    }
    if(st.size() != 1) {
        cout << "Invalid postfix expression!\n";
        return -1;
    }

    return st.top();
}

int main() {
    string postfix;
    cout << "Enter a postfix expression\n";
    getline(cin, postfix);

    int result = evaluatePostfix(postfix);
    cout << "Result \n" << result << endl;

    return 0;
}
