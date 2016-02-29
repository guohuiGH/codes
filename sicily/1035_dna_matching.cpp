/*************************************************************************
    > File Name: 1035_dna_matching.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年02月29日 星期一 10时41分14秒
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<map>
using namespace std;

int main () {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		string temp;
		map<string,int>ma;
		
		for (int i = 0; i < n; i++) {
			cin >> temp;
			ma[temp]++;
		}
		map<string,int>::iterator it;
		map<string,int>::iterator jt;
		int result = 0;

		for (it = ma.begin(); it != ma.end(); it++) {
			for (jt = ma.begin(); jt!=ma.end(); jt++) {
				if (it->second && jt->second) {
					string st1 = it->first;
					string st2 = jt->first;
					int flag = 0;
					if (st1.length() == st2.length()) {
						for (int i= 0; i < st1.length(); i++) {
							int value = (int)st1[i] + st2[i];
							if (value==149 || value == 138) {
								flag = 1;
								continue;
							}else {
								flag = 0;
								break;
							}
						}
					}
					if (flag) {
						it->second--;
						jt->second--;
						result++;
					}
				}
			}
		}
		cout << result << endl;
		
	}
}

