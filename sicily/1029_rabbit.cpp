/*************************************************************************
    > File Name: 1029_rabbit.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年03月19日 星期六 17时15分56秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

string add(string a, string b) {
	string result = "";
	int len = a.length() - b.length();
	for (int i = 0; i < len; i++) {
		b = '0' + b;
	}
	int temp = 0;
	for (int i = a.length()-1; i != -1; i--) {
		temp += (a[i]-'0') + (b[i]-'0');
		if (temp >= 10) {
			result = (char('0' + temp-10)) + result;
			temp = 1;
		}else {
			result = (char('0' + temp)) + result;
			temp = 0;
		}
	}
	if (temp == 1)
		result = '1' + result;
	return result;

}

int main () {
	int m, d;
	while(cin >> m >> d && (m!=0&&d!=0)) {
		vector<string> ve;
		ve.push_back("1");
		for (int i = 1; i <= d; i++) {
			if ((i-m) < 0)
				ve.push_back(add(ve[i-1], "1"));
			else
				ve.push_back(add(ve[i-1],ve[i-m]));
		}
		cout <<  ve.back() << endl;
	}
}
