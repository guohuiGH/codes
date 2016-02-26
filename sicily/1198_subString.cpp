/*************************************************************************
    > File Name: 1198_subString.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年02月25日 星期四 11时08分50秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<string.h>

using namespace std;

bool compare(string a, string b) {
	return (a+b) < (b+a);
	int a_len = a.length(), b_len = b.length();
	if (a_len < b_len) {
		string temp = a;
		for (int i = a_len; i < b_len; i++) {
			stringstream st;
			st << a[a_len-1];
			temp += st.str();
		}

		return temp < b;
	}else {
		string temp = b;
		for (int i = b_len; i < a_len; i++) {
			stringstream st;
			st << b[b_len-1];
			temp += st.str();
		}

		return a < temp;
	}
}

int main () {
	int t;
	cin >> t;
	while (t) {
		int n;
		cin >> n;
		string temp;
		vector<string> ve;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			ve.push_back(temp);
		}
		sort(ve.begin(), ve.end(), compare);
		string result = "";
		for (int i = 0; i < n; i++) {
			result += ve[i];
		}
		cout << result;
		t--;
	}
	return 0;
}
