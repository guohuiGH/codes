/*************************************************************************
    > File Name: 242_valid_anagram.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Sun 27 Sep 2015 04:49:16 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	bool isAnagram(string s, string t) {
		int count[26] = {0};
		for (int i = 0; i < s.length(); i++) {
			count[int(s[i]-'a')]++;
		}
		for (int i = 0; i < t.length(); i++) {
			count[int(t[i]-'a')]--;
		}
		for (int i = 0; i < 26; i++) {

			if (count[i])
				return false;
		}
		return true;
	}
};


int main() {
	Solution s;
	cout << s.isAnagram("abc", "cba");
	return 0;
}
