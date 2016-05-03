/*************************************************************************
    > File Name: 1052_candy_sharing_game.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年05月02日 星期一 14时05分24秒
 ************************************************************************/

#include<iostream>
using namespace std;


bool isEnd(int *a, int n) {
	for (int i = 0; i < n-1; i++) {
		if (a[i] != a[i+1])
			return false;
	}
	return true;
}

int main () {
	int n;
	while(cin >> n && n != 0) {
		int *a = new int[n];
		int *b = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		int counter = 0;
		while(!isEnd(a,n)) {
			b[0] = a[0]/2 + a[n-1]/2;
			if(b[0]%2 != 0)
				b[0] = b[0] + 1;
			for (int i = 1; i < n; i++) {

				b[i] = a[i-1]/2 + a[i]/2;
				if (b[i]%2!=0)
					b[i]++;
			}
			for (int i = 0; i < n; i++) {
				a[i] = b[i];
			}
			counter++;
				
		}
		cout << counter << " " << a[0] << endl;
	}
}
