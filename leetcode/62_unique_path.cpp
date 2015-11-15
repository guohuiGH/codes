/*************************************************************************
    > File Name: 62_unique_path.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Sun 15 Nov 2015 10:19:55 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int> > a;
		for (int i = 0; i < m; i++) {
			vector<int> t;
			for (int j = 0; j< n; j++) {
				t.push_back(1);
			}
			a.push_back(t);
		}
		int mt = min(m,n);
		for (int i = 1; i < mt; i++) {
			for (int j = 1; j < i; j++) {
				a[i][j] = a[i][j-1] + a[i-1][j];
				a[j][i] = a[j-1][i] + a[j][i-1];
			}
			a[i][i] = a[i-1][i] + a[i][i-1];
		}
		if (m== mt) {
			for (int i = mt; i < n; i++) {
				for (int j = 1; j < m; j++) {
					a[j][i] = a[j][i-1] + a[j-1][i];
				}
			}
		}else {
			for (int i = mt; i< m; i++) {
				for (int j = 1; j < n; j++) {
					a[i][j] = a[i-1][j] + a[i][j-1];
				}
			}
		}
		return a[m-1][n-1];
	}
};

int main () {
	Solution s;
	cout << s.uniquePaths(1,1);
}
