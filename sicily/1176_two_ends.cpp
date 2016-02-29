/*************************************************************************
    > File Name: 1176_two_ends.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年02月29日 星期一 16时50分50秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;

int state[1001][1001];
int find(int* a, int l, int r) {
	if (l > r)
		return 0;
	if (state[l][r])
		return state[l][r];
	int takeleft, takeright;
	if (a[l+1] >= a[r])
		takeleft = find(a,l+2,r) + a[l];
	else
		takeleft = find(a,l+1,r-1) + a[l];

	if (a[l] >= a[r-1])
		takeright = find(a, l+1, r-1) + a[r];
	else
		takeright = find(a, l, r-2) + a[r];
	return state[l][r] = max(takeleft, takeright); 
}

int main() {
	int n;
	int count = 1;
	while (cin >> n && n) {
		int *a = new int[n];
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum +=a[i];
		}
		memset(state, 0, sizeof(state));
		int big = find(a,0,n-1);
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n", count, big*2-sum);
		delete a;
		count++;
	}
}
