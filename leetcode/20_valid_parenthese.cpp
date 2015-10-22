/*************************************************************************
    > File Name: 20_valid_parenthese.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Thu 22 Oct 2015 08:40:42 AM CST
 ************************************************************************/

#include<iostream>
#include<stack>
#include<map>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		int size = s.size();
		map<char,int> m;
		m['{'] = 1; m['}'] = 11;
		m['['] = 2; m[']'] = 12;
		m['('] = 3; m[')'] = 13;
		for (int i = 0; i < size; i++) {
			if (st.empty() || (m[st.top()] - m[s[i]])!= -10)
				st.push(s[i]);
			else {
				st.pop();
			}
		}

		if (st.empty())
			return true;
		return false;
	}
};

int main () {
	Solution s;
	cout << s.isValid(")(");
}
