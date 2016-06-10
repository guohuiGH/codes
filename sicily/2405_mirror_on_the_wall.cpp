/*************************************************************************
    > File Name: 2405_mirror_on_the_wall.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Thu 09 Jun 2016 06:18:53 PM CST
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>

using namespace std;

int main () {
	string str;
	while (cin >> str && str != "#") {
		string temp = str;
		reverse(temp.begin(), temp.end());
		int hash[26] = {0};
		hash[int('i'-'a')] = 1; hash[int('o'-'a')]=1;
		hash[int('v'-'a')] = 1; hash[int('x'-'a')] = 1;
		hash[int('w'-'a')] = 1;
		int tag = 1;
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] == 'b')
				temp[i] = 'd';
			else if (temp[i] == 'd')
				temp[i] = 'b';
			else if (temp[i] == 'p')
				temp[i] = 'q';
			else if (temp[i] == 'q')
				temp[i] = 'p';
			else if (hash[int(temp[i]-'a')] == 0) {
				cout << "INVALID" << endl;
				tag = 0;
				break;
			}
		}
		
		if (tag)
			cout << temp << endl;
	}
}
