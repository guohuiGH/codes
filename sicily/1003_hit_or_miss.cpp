/*************************************************************************
    > File Name: 1003_hit_or_miss.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年04月19日 星期二 19时53分36秒
 ************************************************************************/

#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

int main () {
	int t;
	cin >> t;
	int k = t;
	while(t--) {
		int n;
		cin >> n;
		queue<int>qu[12];

		int temp;
		for (int i = 0; i < 52; i++) {
			cin >> temp;
			qu[0].push(temp);
		}

		int counter[11];
		//memset(counter,11,sizeof(int)*11);
		for (int i = 0; i < 11; i++)
			counter[i] = 0;

		int iter = 2000, it = 0;
		int last[11] = {0};
		while(it < iter) {
			for (int i = 0; i < n; i++) {
				int size = qu[i].size();
				if (size == 0)
					continue;
				counter[i]++;
				if (counter[i] > 13)
					counter[i] = 1;
				if (counter[i] == qu[i].front()) {

					qu[i+1].push(counter[i]);
					qu[i].pop();
					if (qu[i].empty()) {
						last[i] = counter[i];
					}

				}
				else {
					temp = qu[i].front();
					qu[i].pop();
					qu[i].push(temp);
				}
			}
			it++;
		}
		int size = qu[n].size();
		cout << "Case " << k-t << ":";

		if (size == 52) {
			for (int i = 0; i < n; i++)
				cout << " " << last[i];
		}else
			cout << " unwinnable";
		cout << endl;


	}
}
