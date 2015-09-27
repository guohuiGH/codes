/*************************************************************************
    > File Name: 168_excel_sheet_column_title.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Thu 24 Sep 2015 09:24:20 PM CST
 ************************************************************************/

#include<iostream>
#include<stack>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class Solution {
public:
	string converToTitle(int n) {
		string s = "";
		if (!n)
			return s;
		//char last = n % 26 + ;
		char temp ;
		stack<char>st;
		while (n > 0) {
			if (n%26){
				temp = n %26 -1 + 'A' ;
				n = n/26;
			}
			else {
				temp = 'Z';
				n = n/26 - 1;
			}
			st.push(temp);
		}
		while(!st.empty()) {
			
			s = s + st.top();
			st.pop();
		}
		return s;
	}
};

int main() {
	Solution s;
	cout << s.converToTitle(52);
}
