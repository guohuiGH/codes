/*************************************************************************
    > File Name: 125_valid_palindrome.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Tue 27 Oct 2015 05:19:23 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		if (s=="")
			return true;
		string ps;
		for(int i = 0; i < s.size(); i++) {
			if (s[i] <= 'Z' && s[i]>='A')
				ps.push_back(s[i]+32);
			if (s[i] <= 'z' && s[i] >= 'a')
				ps.push_back(s[i]);
			if (s[i] <= '9' && s[i] >= '0')
				ps.push_back(s[i]);
		}
		int si = ps.size();
		int len = ps.size()/2;
		for (int i = 0; i < len; i++) {
			if (ps[i] != ps[si-1-i])
				return false;
		}
		return true;
	}
};

int main () {
	Solution s;
	cout << s.isPalindrome("race a car");
}
