/*************************************************************************
    > File Name: 1152_lucky_substring.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年03月26日 星期六 20时58分14秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<string.h>
#include<map>
using namespace std;

int main () {
	int fi[] = {1,2,3,5,8,13,21};
	int tag[27] = {0};
	for (int i = 0; i < 27; i++) {
		for (int j = 0; j < 7; j++) {
			if (fi[j] == i)
				tag[i] = 1;
		}
	}
	string str;
	cin >> str;
	int s[101][101];
	int recoder[26];
	map<string,int>result;
	for (int i = 0; i < str.length(); i++) {
		memset(recoder, 0, sizeof(int)*26);
		recoder[str[i]-'a'] = 1;
		s[i][i] = 1;
		result[str.substr(i,1)] = 1;
		for (int j = i+1; j < str.length(); j++) {
			int temp = str[j] - 'a';
			if (recoder[temp] == 1) {
				s[i][j] = s[i][j-1];
			}else {
				s[i][j] = s[i][j-1] + 1;
			}
			if (tag[s[i][j]]) 
				result[str.substr(i,j-i+1)] = 1;


			recoder[str[j]-'a'] = 1;
		}
	}

	map<string,int>::iterator it;
	for (it = result.begin(); it!= result.end(); it++) {
		cout << it->first << endl;
	}
}
