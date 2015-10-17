/*************************************************************************
    > File Name: 9_palindrome_number.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Sat 17 Oct 2015 01:41:18 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x<0)
			return false;
		int temp = x, y;
		while(temp) {
			y = y*10 + temp%10;
			temp = temp/10;
		}
		return(y == x);
	}
};
int main () {
	Solution s;
	cout << s.isPalindrome(2332);
	return 0;
}
