/*************************************************************************
    > File Name: 1134_jimu.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年03月14日 星期一 20时32分21秒
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int has[10005];
int need[10005];

bool cmp(int a, int b) {
	return need[a] < need[b];
}
int main() {
	int n;
	long long int s;
	while (cin >> n >> s && n) {
		memset(has,0,sizeof(int)*10005);
		memset(need,0,sizeof(int)*10005);
		int *index = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> has[i] >> need[i];
			index[i] = i;
		}
		sort(index, index+n,cmp);
		int signal = 1;
		for (int i = 0; i < n; i++) {
			if (need[index[i]] <= s ) {
				s += has[index[i]];
			}else {
				cout << "NO" << endl;
				signal = 0;
				break;
			}
		}
		if (signal)
			cout << "YES" << endl;
		delete []index;
	}
}

