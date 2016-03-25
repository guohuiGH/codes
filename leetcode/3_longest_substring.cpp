/*************************************************************************
    > File Name: 3_longest_substring.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年03月25日 星期五 19时55分36秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int>hash;
		int j = 1;
		if (!s.size())
			return 0;
		hash[s[0]] = 1;
		int max = 1;
		for (int i = 0; i < s.size(); i++) {
			for (; j < s.size(); j++) {
				if (hash.find(s[j]) == hash.end()) {
					hash[s[j]] = 1;
				}else {
					break;
				}

			}
			hash.erase(s[i]);
			if (j-i > max)
				max = j-i;
		}
		return max;
	}
};

int main () {
	string str= "eceabcabcbb";
	Solution s;
	cout << s.lengthOfLongestSubstring(str);
}
