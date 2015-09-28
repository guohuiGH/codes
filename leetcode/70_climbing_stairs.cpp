/*************************************************************************
    > File Name: 70_climbing_stairs.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Mon 28 Sep 2015 08:01:48 PM CST
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
	//	if (n < 3)
	//		return n;
	//	else
	//		return climbStairs(n-1) + climbStairs(n-2);
		int *a = (int *)malloc((n+1)*sizeof(int));
		if (n < 3)
			return n;
		a[0] = 0;
		a[1] = 1;
		a[2] = 2;
		for (int i = 3; i <= n; i++)
			a[i] = a[i-1] + a[i-2];
		return a[n];
	}
};

int main () {
	Solution s;
	cout << s.climbStairs(10);
}
