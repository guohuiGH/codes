/*************************************************************************
    > File Name: 225_implement_stack_using_queue.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Mon 28 Sep 2015 08:48:40 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

class Stack {
public:
	queue<int>qu, temp;
	void push(int x) {
		qu.push(x);
	}
	void change1() {
		while(qu.size()>1) {
			temp.push(qu.front());
			qu.pop();
		}
	}
	void change2() {

		while(temp.size()>1) {
			qu.push(temp.front());
			temp.pop();
		}
	}
	void pop() {
		change1();
		if (!qu.empty()){
			qu.pop();
			return;
		}
		change2();
		if (!temp.empty()){
			temp.pop();
			return;
		}
	}
	int  top() {
		change1();
		if (!qu.empty()){
			return qu.front();
		}
		change2();
		if (!temp.empty()){
			int t = temp.front();
			temp.pop();
			qu.push(t);
			return t;
		}
	}
	bool empty() {
		if (temp.empty() && qu.empty())
			return true;
		return false;
	}
};

int main () {
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout << s.top();
	s.pop(); cout << s.top()<< endl;
	s.pop();cout << s.top() << endl;
	s.pop();cout << s.empty() << endl;
}
