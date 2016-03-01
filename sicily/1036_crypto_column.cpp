/*************************************************************************
    > File Name: 1036_crypto_column.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Tue 01 Mar 2016 06:23:42 PM CST
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

string keyword;

bool cmp(int a, int b) {
	return keyword[a] < keyword[b];
}

int main () {

	while (cin >> keyword && keyword != "THEEND") {
		string pto;
		cin >> pto;
		int len = keyword.length();
		int*a;
		a = new int[len];
		for (int i = 0; i < len; i++) {
			a[i] = i;
		}
		sort(a,a+keyword.length(),cmp);
		int *order = new int[len];
		for (int i = 0; i < len; i++) {
			order[a[i]] = i; 
		}
		int row = round(pto.length()/len);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < len; j++) {
				cout << pto[row*order[j]+i];
			}
		}
		cout << endl;
		delete[] a;
	}
}

