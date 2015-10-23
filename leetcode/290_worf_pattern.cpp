/*************************************************************************
    > File Name: 290_worf_pattern.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Fri 23 Oct 2015 08:13:47 AM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<stdlib.h>
#include<queue>
#include<map>
using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		int len_p = pattern.size();
		map<char, int> m1;
		queue<int> qu;
		int count = 1;
		for(int i = 0; i < len_p; i++) {
			if (m1.find(pattern[i]) == m1.end()) {
				m1[pattern[i]] = count;
				count++;
			}
			qu.push(m1[pattern[i]]);
		}
		int len_s = str.size();
		int j = 0;
		map<string, int> m2;
		count = 1;

		for (int i = 0; i < len_s; i++) {
			
			if (str[i] == ' ') {
				string s = str.substr(j,i-j);
				j = i+1;
				
				if (m2.find(s) == m2.end()){
					m2[s] = count;
					count++;
				}
				if (m2[s] == qu.front()){
					qu.pop();
				}else
					return false;
			}
		}
		string s= str.substr(j,len_s+1-j);
		if (m2.find(s) == m2.end()){
			m2[s] = count;
		}
		if (m2[s] == qu.front())
			qu.pop();
		else
			return false;
		if (qu.empty())
			return true;
		return false;
	}
};

int main () {
	Solution s;
	cout << s.wordPattern("abba", "dog cat cat dog");
}

