#include <iostream>
#include <string>
#include <stack>
using namespace std;

int calculate(string s) {
    stack<int> st;
    int curr = 0;
    char lastop = '+';
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (isdigit(c)) {
            curr = curr * 10 + (c - '0');
        }
        if ((!isdigit(c) && c != ' ') || i == s.length() - 1) {
            if (lastop == '+') {
                st.push(curr);
            } else if (lastop == '-') {
                st.push(-curr);
            } else if (lastop == '*') {
                int top = st.top();
                st.pop();
                st.push(top * curr);
            } else if (lastop == '/') {
                int top = st.top();
                st.pop();
                st.push(top / curr);
            }
            lastop = c;
            curr = 0;
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
