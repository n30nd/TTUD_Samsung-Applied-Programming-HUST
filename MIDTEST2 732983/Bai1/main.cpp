//Kiểm tra xâu biểu thức đúng hay không đúng thì ghi kết quả, sai thì hiện NOT_CORRECT
#include "bits/stdc++.h"
using namespace std;

int main() {
  string expression;
  cin >> expression;

  stack<int> st;
  for (int i = 0; i < expression.length(); i++) {
    if (isdigit(expression[i])) {
      st.push(expression[i] - '0');
    } else {
      int operand2 = st.top();
      st.pop();
      int operand1 = st.top();
      st.pop();

      if (expression[i] == '+') {
        st.push(operand1 + operand2);
      } else if (expression[i] == '*') {
        st.push(operand1 * operand2);
      } else {
        cout << "NOT_CORRECT" << endl;
        return 0;
      }
    }
  }

  int result = st.top();
  cout << result % ((int)10e9 + 7) << endl;

  return 0;
}
