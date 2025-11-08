#include <bits/stdc++.h>
using namespace std;

// ! WITHOUT ASSOCIATIVITY
int getPrecedence(char c) {
    if(c == '-' || c == '+') return 1;
    
    return 2;
}

string convertWithoutAssoc(string &exp) {
    string postfix = "";
    int n = exp.length(), i = 0;
    stack<char> operand;

    while(i < n) {
        if(isdigit(exp[i])) {
            while(i < n && isdigit(exp[i])) {
                postfix.push_back(exp[i++]);
            }

            postfix.push_back(' ');
            continue;

        } else if(exp[i] != ' ') {
            // OPERAND
            while(!operand.empty() && getPrecedence(exp[i]) <= getPrecedence(operand.top())) {
                postfix.push_back(operand.top()); 
                postfix.push_back(' ');
                operand.pop();
            }

            operand.push(exp[i]);
        }

        i++;
    }

    while(!operand.empty()) {
        postfix.push_back(operand.top());
        operand.pop();
    }

    return postfix;
}
// ! ======================

// ! WITH ASSOCIATIVITY (SHUNTING YARD ALGORITHM)
int getOutStackPrecedence(char c) {
    if(c == '+' || c == '-') {
        return 1;
    } else if(c == '*' || c == '/') {
        return 3;
    } else if(c == '^') {
        return 6;
    }

    return 7; // '/'
}

int getInStackPrecedence(char c) {
    if(c == '+' || c == '-') {
        return 2;
    } else if(c == '*' || c == '/') {
        return 4;
    } else if(c == '^') {
        return 5;
    }

    return 0; // '/'
}

string convertWithAssoc(string &exp) {
    stack<char> operand;
    string postfix = "";
    int n = exp.length(), i = 0;

    while(i < n) {
        if(isdigit(exp[i])) {
            while(i < n && isdigit(exp[i])) {
                postfix.push_back(exp[i++]);
            }

            postfix.push_back(' ');
            continue;
        } else if(exp[i] != ' ') {
            if(exp[i] == ')') {
                while(!operand.empty() && operand.top() != '(') {
                    postfix.push_back(operand.top());
                    postfix.push_back(' ');
                    operand.pop();
                }
                
                operand.pop(); // menghapus buka kurung;
            } else {
                if(operand.empty() || getInStackPrecedence(operand.top()) < getOutStackPrecedence(exp[i])) {
                    operand.push(exp[i]);
                } else {
                    while(i < n && getInStackPrecedence(operand.top()) >= getOutStackPrecedence(exp[i])) {
                        postfix.push_back(operand.top());
                        postfix.push_back(' ');
                        operand.pop();
                    }

                    operand.push(exp[i]);
                }
            }
        }

        i++;
    }

    while(!operand.empty()) {
        postfix.push_back(operand.top());
        operand.pop();
    }

    return postfix;
}

int evalPostfix(string &postfix) {
    int i = 0, n = postfix.length();
    stack<int> s;

    while(i < n) {
        if(isdigit(postfix[i])) {
            int temp = 0;
            while(i < n && isdigit(postfix[i])) {
                temp = (temp * 10) + postfix[i] - '0';
                i++;
            }

            s.push(temp);
            continue;
        } else if(postfix[i] != ' ') {
            char operand = postfix[i];
            int secondNum = s.top(); s.pop();
            int firstNum  = s.top(); s.pop();

            if(operand == '+')      s.push(firstNum + secondNum);
            else if(operand == '-') s.push(firstNum - secondNum);
            else if(operand == '*') s.push(firstNum * secondNum);
            else if(operand == '/') s.push(firstNum / secondNum);
            else if(operand == '^') s.push(pow(firstNum, secondNum));
        }

        i++;
    }

    return s.top();
}

// ! ======================
int main() {
    string exp      = "64 + 4 - 7 * 8 / 9";
    string postfix1 = convertWithoutAssoc(exp);
    cout << evalPostfix(postfix1) << endl;

    string expAssoc = "87 + ((7 - 3) ^ 9 * 4 + 5)";
    string postfix2 = convertWithAssoc(expAssoc);
    cout << evalPostfix(postfix2) << endl;

    return 0;
}