/*************************************************************************
    > File Name: 3980_binary_to_decimal.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Thu 09 Jun 2016 05:56:32 PM CST
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<string>
using namespace std;

int main () {
	int t; cin >> t;
	while(t--) {

	
		string str;
		cin >> str;
		int sum = 0;
		int base = 1;
		for (int i = str.size()-1; i >=0; i--) {
			sum += int(str[i]-'0') * base;
			base *=2;
		}
		cout << sum << endl;
	}
}
