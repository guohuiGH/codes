/*************************************************************************
    > File Name: 232_implement_queue_using_stack.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Mon 28 Sep 2015 11:14:46 AM CST
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

class Queue {
public:
	stack<int> in;
	stack<int> out;
	void push(int x) {
		in.push(x);

	}
	void pop(void) {
		
		if (out.empty()){
			while(!in.empty()) {
				int t = in.top();
				out.push(t);
				in.pop();
			}
		}
		out.pop();
	}
	int peek(void) {

		if (out.empty()) {

			while(!in.empty()) {
				
				out.push(in.top());

				in.pop();
			}
		}
		return out.top();
	}
	bool empty(void) {
		return in.empty() && out.empty();
	}
};
int main() {
	Queue s;
	s.push(1);
	cout << s.peek();
	return 0;

}
