/*************************************************************************
    > File Name: 1027_mj_nowhere_to_hide.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年02月29日 星期一 11时45分51秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<string.h>
using namespace std;

int main () {
	int n;
	while(cin >> n && n) {
		map<string, string>id;
		map<string, string>mj;
		string st1, st2;
		for (int i = 0; i < n; i++) {
			cin >> st1 >> st2;
			if (id.find(st2) == id.end()) {
				id[st2] = st1;
			}else {
				mj[id[st2]] = st1;
			}
		}
		map<string, string>::iterator it;
		for (it = mj.begin(); it!=mj.end(); it++) {
			cout << it->second << " is the MaJia of " << it->first << endl;
		}

	}
}

