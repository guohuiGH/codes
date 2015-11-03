/*************************************************************************
    > File Name: 155_min_stack.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Wed 28 Oct 2015 11:10:15 AM CST
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

class MinStack {
public:
	stack<int>st1,st2;
	void push (int x) {
		st1.push(x);
		if (st2.empty() || x <= st2.top())
			st2.push(x);
	}
	void pop () {
		int t = st1.top();
		st1.pop();
		if (t == st2.top())
			st2.pop();
	}
	int top () {
		return st1.top();
	}
	int getMin() {
		return st2.top();
	}
};

int main () {
	MinStack st;
	st.push(2);st.push(0);st.push(3);
	st.push(1);
	cout << st.top() << endl;
	cout << st.getMin();
}
