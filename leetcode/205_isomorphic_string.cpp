/*************************************************************************
    > File Name: 205_isomorphic_string.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Sat 24 Oct 2015 09:10:00 PM CST
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s == "" && t == "")
			return true;
		int len1 = s.size();
		int len2 = s.size();
		if (len1 != len2)
			return false;
		map<char,char> ms, mt;
		for (int i = 0; i < len1; i++) {
			if (ms.find(s[i]) == ms.end())
				ms[s[i]] = t[i];
			else if (ms[s[i]] != t[i])
				return false;
			if (mt.find(t[i]) == mt.end())
				mt[t[i]] = s[i];
			else if (mt[t[i]] != s[i])
				return false;
		}
		return true;

	}
};

int main () {
	Solution s;
	cout << s.isIsomorphic("ab", "aa");
}
