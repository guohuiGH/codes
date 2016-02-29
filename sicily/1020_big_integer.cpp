/*************************************************************************
    > File Name: 1020_big_integer.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年02月29日 星期一 14时37分27秒
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

int main () {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		int*a  = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		string st;
		cin >> st;
		cout << "(";
		for (int i = 0; i < n; i++) {
			
			int bit = 0;
			for (int j = 0; j < st.length();) {
				while (bit < a[i]) {
					
					if (j < st.length())
						bit = bit*10 + (int) (st[j]-'0');
					else
						break;
					j++;
				}
				bit = bit%a[i];
			}
			if (i == 0)
				cout << bit;
			else
				cout << "," << bit;
		}
		cout << ")" << endl;
		delete a;
	}
}
