/*************************************************************************
    > File Name: 219_blub_switcher.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Mon 28 Dec 2015 08:42:00 PM CST
 ************************************************************************/

#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
	int bulbSwitch(int n) {
		if (n==1)
			return n;
		else
			return sqrt(n);
	}
};
int main() {
	Solution s;
	cout << s.bulbSwitch(9);
	return 0;
}
