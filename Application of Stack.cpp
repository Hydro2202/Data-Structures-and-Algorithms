
#include <iostream>

#include <stack>

#include <cctype>  

#include <string>

#include <algorithm>  

#include <cmath>   



using namespace std;




int precedence(char op) {

    if (op == '+' || op == '-') {

        return 1;

    }

    if (op == '*' || op == '/') {

        return 2;

    }

    if (op == '^') {

        return 3;

    }

    return 0;

}




int applyOp(int a, int b, char op) {

    switch (op) {

        case '+': return a + b;

        case '-': return a - b;

        case '*': return a * b;

        case '/': return a / b;

        case '^': return pow(a, b);

    }

    return 0;

}



string infixToPostfix(const string& expression) {

    stack<char> operators;

    string postfix = "";

    

    for (int i = 0; i < expression.length(); i++) {

        char c = expression[i];

        

        

        if (isdigit(c)) {

            postfix += c;

        }

       

        else if (c == '(') {

            operators.push(c);

        }

        

        else if (c == ')') {

            while (!operators.empty() && operators.top() != '(') {

                postfix += operators.top();

                operators.pop();

            }

            operators.pop();  

        }

        

        else {

            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {

                postfix += operators.top();

                operators.pop();

            }

            operators.push(c);

        }

    }

    

    

    while (!operators.empty()) {

        postfix += operators.top();

        operators.pop();

    }

    

    return postfix;

}




string infixToPrefix(const string& expression) {

    stack<char> operators;

    string prefix = "";

    string expr = expression;



    

    reverse(expr.begin(), expr.end());



    

    for (int i = 0; i < expr.length(); i++) {

        if (expr[i] == '(') {

            expr[i] = ')';

        } else if (expr[i] == ')') {

            expr[i] = '(';

        }

    }



   

    for (int i = 0; i < expr.length(); i++) {

        char c = expr[i];



        

        if (isdigit(c)) {

            prefix += c;

        }

       

        else if (c == '(') {

            operators.push(c);

        }

        

        else if (c == ')') {

            while (!operators.empty() && operators.top() != '(') {

                prefix += operators.top();

                operators.pop();

            }

            operators.pop();  

        }

        

        else {

            while (!operators.empty() && precedence(operators.top()) > precedence(c)) {

                prefix += operators.top();

                operators.pop();

            }

            operators.push(c);

        }

    }



    

    while (!operators.empty()) {

        prefix += operators.top();

        operators.pop();

    }



   

    reverse(prefix.begin(), prefix.end());



    return prefix;

}



int evaluatePostfix(const string& postfix) {

    stack<int> values;

    

    for (int i = 0; i < postfix.length(); i++) {

        char c = postfix[i];

        

        

        if (isdigit(c)) {

            values.push(c - '0');  

        }

        

        else {

            int val2 = values.top();

            values.pop();

            int val1 = values.top();

            values.pop();

            values.push(applyOp(val1, val2, c));

        }

    }

    

    

    return values.top();

}



int main() {

    string expression;

    

    

    cout << "Enter an infix expression: ";

    cin >> expression;



    

    string postfix = infixToPostfix(expression);

    cout << "Postfix Expression: " << postfix << endl;



    

    string prefix = infixToPrefix(expression);

    cout << "Prefix Expression: " << prefix << endl;

    

    

    int result = evaluatePostfix(postfix);

    cout << "Result: " << result << endl;

    

    return 0;

}
