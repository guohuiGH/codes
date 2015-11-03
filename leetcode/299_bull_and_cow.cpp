/*************************************************************************
    > File Name: 299_bull_and_cow.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Sat 31 Oct 2015 08:57:06 AM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<map>
#include<stdio.h>
using namespace std;

class Solution {
public:
	string getHint(string secret, string guess) {
		int count = 0;
		int size = secret.size();
		map<char,int> ma;

		for (int i = 0; i < size; i++) {
			ma[secret[i]]++;
		}
		int total = 0;
		for (int i = 0; i < size; i++) {
			if (ma[guess[i]] > 0) {
				ma[guess[i]]--;
				total++;
			}
		}
		for (int i = 0; i < size; i++) {
			if (secret[i] == guess[i])
				count++;
		}
		string result = "";
		char ch[100], ch2[100];
		sprintf(ch, "%d", count);
		sprintf(ch2, "%d",total- count);
		string a = string(ch), b = string(ch2);
		result = a + "A" + b + "B";
		return result;
	}
};

int main () {
	Solution s;
	cout << s.getHint("1807", "7812");
	return 0;
}
