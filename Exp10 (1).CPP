// 10 practical 
#include <iostream>
#include <cstring>
#define SIZE 20

using namespace std;

class StackExp {
    int top;
    char stk[SIZE];

public:
    StackExp() { top = -1; }

    void push(char x) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        stk[++top] = x;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return '\0';
        }
        return stk[top--];
    }

    bool isFull() { return top == SIZE - 1; }

    bool isEmpty() { return top == -1; }
};

bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

bool isWellParenthesized(const char* exp) {
    StackExp stack;

    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        // Push opening delimiters onto the stack
        if (ch == '(' || ch == '[' || ch == '{') {
            stack.push(ch);
        }
        // Check closing delimiters
        else if (ch == ')' || ch == ']' || ch == '}') {
            // If stack is empty or the pair doesn't match, it's invalid
            if (stack.isEmpty() || !isMatchingPair(stack.pop(), ch)) {
                return false;
            }
        }
    }

    // If stack is empty at the end, expression is well-parenthesized
    return stack.isEmpty();
}

int main() {
    char exp[SIZE];

    cout << "\n\t!! Parenthesis Checker..!!!!" << endl;
    cout << "Enter the expression to check whether it is well-parenthesized: ";
    cin >> exp;

    if (isWellParenthesized(exp)) {
        cout << "\nExpression is well-parenthesized.\n";
    } else {
        cout << "\nInvalid Expression or not well-parenthesized.\n";
    }

    return 0;
}
