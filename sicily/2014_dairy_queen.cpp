/*************************************************************************
    > File Name: 2014_dairy_queen.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Fri 10 Jun 2016 10:23:57 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int counter = 0;
void dfs(vector<int> &ve,  int left, int depth) {
	int size = ve.size();
	if (depth == size-1) {
		if (!(left%ve[depth]))
			counter++;
		return;
	}
	for (int i = 0; i <= left/ve[depth]; i++) {
		dfs(ve,left-ve[depth]*i,depth+1);
	}
}

int main () {
	int N, C;
	cin >> N >> C;
	vector<int>ve;
	for (int i = 0; i < C; i++) {
		int t; cin >> t;
		ve.push_back(t);
	}
	vector<int>color(C,0);
	dfs(ve, N, 0);
	cout << counter << endl;
}
