/*************************************************************************
    > File Name: 96_unique_binary_search_tree.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Sat 07 Nov 2015 10:06:16 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
	int numTrees(int n) {
		int *a = new int[n+1];
		int i = 0;
		for (; i < 2; i++) {
			a[i] = 1;
		}
		
		for (; i < n+1; i++) {
			a[i] = 0;
			for (int j = 0; j < i; j++)
				a[i] += a[j]*a[i-j-1];
		}
		
		return a[n];
	}
};

int main () {
	Solution s;
	cout << s.numTrees(3);
	return 0;
}
