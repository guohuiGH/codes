/*************************************************************************
    > File Name: 1438_shopaholic.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年03月16日 星期三 21时53分45秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a>b;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int*a = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a,a+n,cmp);
		int k = n/3;
		int sum = 0;
		for (int i = 0; i < k; i++)
			sum += a[i*3+2];

		cout << sum << endl;
		delete a;

	}
}
