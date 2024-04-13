#include <iostream>
#include <vector> 
using namespace std;

template <class t, class y=vector<t>>
struct Stack {
  y ctner;
  void push(t val) {
    ctner.push_back(val);
  }
  void pop() {
    ctner.pop_back();
  }
  t top(){
    return ctner.back();
  }
};
int main() {
  Stack<int> s;
  s.push(8);
  s.push(9);
  s.push(10);
  s.pop();
  for (int i = 0; i < s.ctner.size(); i++){
    cout << s.ctner[i] << endl;
  }
  cout<<s.top();
};