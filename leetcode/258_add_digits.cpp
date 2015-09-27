/*************************************************************************
    > File Name: 258_add_digits.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Fri 18 Sep 2015 06:31:26 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution{
public:
	int addDigits(int num) {
		while (num > 9) {
			int temp = 0;
			while(num) {
				temp += num%10;
				num = num/10; 
			}
			num = temp;
		}
		return num;
	}
};

int main() {
	Solution s;
	cout << s.addDigits(56);
	return 0;
}
