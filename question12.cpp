#include <iostream>
#include <string>
#include <stack>
using namespace std;

int calculate(string s) {
    stack<int> st;
    int currentNumber = 0;
    char lastOperator = '+';
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        // Build the current number
        if (isdigit(c)) {
            currentNumber = currentNumber * 10 + (c - '0');
        }
        // If we encounter an operator or reach the end of the string
        if ((!isdigit(c) && c != ' ') || i == s.length() - 1) {
            if (lastOperator == '+') {
                st.push(currentNumber);
            } else if (lastOperator == '-') {
                st.push(-currentNumber);
            } else if (lastOperator == '*') {
                int top = st.top();
                st.pop();
                st.push(top * currentNumber);
            } else if (lastOperator == '/') {
                int top = st.top();
                st.pop();
                st.push(top / currentNumber);
            }
            lastOperator = c;
            currentNumber = 0;
        }
    }
    int result = 0;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    return result;
}

int main() {
    string s1 = "3+2*2";
    cout << calculate(s1) << endl; 
    string s2 = "3/2";
    cout << calculate(s2) << endl;  
    string s3 = "3+5/2";
    cout << calculate(s3) << endl; 
    
    return 0;
}
