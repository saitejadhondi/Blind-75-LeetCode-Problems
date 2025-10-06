#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string str) {
        stack<char> st;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
                st.push(str[i]);
            } else {
                if (st.empty()) {
                    return false;
                }
                char ch = st.top();
                st.pop();
                if (!((str[i] == ')' && ch == '(') ||
                      (str[i] == ']' && ch == '[') ||
                      (str[i] == '}' && ch == '{'))) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {
    string s;
    cout << "Enter a string of brackets: ";
    cin >> s;

    Solution sol;
    bool result = sol.isValid(s);

    if (result)
        cout << "Valid\n";
    else
        cout << "Invalid\n";

    return 0;
}