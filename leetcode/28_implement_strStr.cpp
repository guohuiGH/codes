/*************************************************************************
    > File Name: 28_implement_strStr.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Sun 25 Oct 2015 10:17:36 AM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		int len1 = haystack.size();
		int len2 = needle.size();
		if (len2>len1)
			return -1;
		if (len2 == 0 && len1 == 0)
			return 0;

		for (int i = 0; i <= len1-len2; i++) {
			string temp = haystack.substr(i,len2);
			if (temp == needle)
				return i;
		}
		return -1;
	}
};

int main (){
	Solution s;
	string a = "hello", b = "lo";
	cout << s.strStr(a,b);
}
