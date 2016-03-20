/*************************************************************************
    > File Name: 1381_a*b.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年03月20日 星期日 12时00分37秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

string multiply(string a, int mod, int len) {
	for (int i = 0; i < len; i++)
		a += '0';
	string result;
	int temp = 0;
	for (int i = a.length()-1; i != -1; i--) {
		temp += (a[i]-'0')*mod;
		result = char(temp%10 + '0') + result;
		temp /= 10;
	}
	if (temp > 0) {
		result = char(temp + '0') + result;
	}
	cout << result << endl;
	return result;
}

string add (string a, string b) {
	int len = b.length() - a.length();
	for (int i = 0; i < len; i++) {
		a = '0' + a;
	}
	string result;
	int temp = 0;
	for (int i = b.length()-1; i != -1; i--) {
		temp += (b[i]-'0') + (a[i]-'0');
		result = char(temp%10 + '0') + result;
		temp /= 10;
	}
	if (temp > 0) {
		result = char(temp+'0') + result;
	}
	return result;
}

int main () {
	int t;
	cin >> t;
	while(t--) {
		string a; cin >> a;
		int b; cin >> b;
		int i = 0;
		string result = "0";
		while(b) {
			int mod = b%10;
			b /= 10;
			result = add(result, multiply(a,mod,i));
			i++;

		}
		i = 0;
		for (; i < result.length()-1; i++) {
			if (result[i] != '0')
				break;
		}

		cout << result.substr(i) << endl;
	}
}
