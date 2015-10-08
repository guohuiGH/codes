/*************************************************************************
    > File Name: 263_ugly_number.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Thu 08 Oct 2015 10:54:49 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
	bool isUgly(int num) {
		if (num < 1)
			return false;
		while (true) {
			if (num == 1)
				return true;
			else if (num%2 == 0)
				num = num/2;
			else if (num %3 == 0)
				num = num /3;
			else if (num % 5 == 0)
				num = num /5;
			else
				return false;
		}
		return false;
	}
};
int main() {
	Solution s;
	cout << s.isUgly(21);
	return 0;
}
