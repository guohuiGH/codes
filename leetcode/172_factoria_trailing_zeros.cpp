/*************************************************************************
    > File Name: 172_factoria_trailing_zeros.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Fri 16 Oct 2015 04:03:04 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
	int trailingZeroes(int n){
		if (n<=0)
			return 0;
		int count = 0;
		while(n) {
			n =n/5;
			count+=n;
		}
		return count;
	}
};
int main () {
	Solution s;
	cout << s.trailingZeroes(25);
}
