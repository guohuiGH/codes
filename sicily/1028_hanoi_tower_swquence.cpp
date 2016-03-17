/*************************************************************************
    > File Name: 1028_hanoi_tower_swquence.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年03月17日 星期四 15时40分22秒
 ************************************************************************/

#include<iostream>
#include<limits.h>
#include<string.h>
using namespace std;

int mod(const string& str, int a) {
	int temp = 0;
	for (int i = 0; i < str.length(); i++) {
		temp = temp*10 + (str[i]-'0');
		temp %= a;
	}
	return temp;
}

string divs(const string& str, int a) {
	int temp = 0;
	char *ch = new char[str.length()];
	for (int i = 0; i < str.length(); i++) {
		temp = temp*10 + (str[i]-'0');
		ch[i] = temp/a + '0';
		temp %= a;
	}
	int i = 0;
	for (i = 0; i < str.length(); i++) {
		if (ch[i] != '0')
			break;
	}
	string s;
	for (;i < str.length(); i++) {
		s += ch[i];
	}
	delete[] ch;
	return s;
}

int solution(string str) {
	int result = 1;
	while (mod(str,2) == 0) {
		result++;
		str = divs(str,2);
	}
	return result;

}

int main () {
	int t;
	cin >> t;
	int n = t;
	while(t--) {
		string str;
		cin >> str;

		cout << "Case " << n-t << ": " << solution(str) << endl;
		if (t)
			cout << endl;
	}
}
