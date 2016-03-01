/*************************************************************************
    > File Name: 1007_to_and_fro.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Tue 01 Mar 2016 04:16:02 PM CST
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

int main () {
	int n;
	while(cin >> n && n) {
		string str;
		cin >> str;
		int column = round((double)str.length()/n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < column; j++) {
				
				if (j%2)
					cout << str[n-1-i+j*n];
				else
					cout << str[i+j*n];
			}
		}
		cout << endl;
	}
}
