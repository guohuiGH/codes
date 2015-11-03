/*************************************************************************
    > File Name: 38_count_and_say.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Sat 24 Oct 2015 11:27:43 AM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		if (n < 1)
			return "";
		string s = "1";
		for (int i = 1; i <n; i++) {
			int len = s.size();
			int count[10] = {0};
			string temp;
			count[int(s[0]-'0')]++;
			for (int j = 1; j < len; j++) {
				if (s[j] != s[j-1]) {
					char t = count[int(s[j-1]-'0')] + '0';
					temp.push_back(t);
					temp.push_back(s[j-1]);
					count[int(s[j-1]-'0')] = 0;
				}
				count[int(s[j]-'0')]++;
			}
			char t = count[int (s[len-1]-'0')] + '0';
			temp.push_back(t);
			temp.push_back(s[len-1]);
			s = temp;
		}
		return s;
	}
};

int main () {
	Solution s;
	cout << s.countAndSay(5);
}
