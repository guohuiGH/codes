/*************************************************************************
    > File Name: 1082_manager2.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Mon 02 May 2016 10:01:19 PM CST
 ************************************************************************/

#include<iostream>
#include<set>
#include<vector>
#include<queue>
using namespace std;


int main () {
	int maxProcess;
	bool first = true;
	while (cin >> maxProcess) {
		if (first)
			first = false;
		else
			cout << endl;
		int len;
		cin >> len;
		queue<int>query;
		vector<int>ve;
		int t;
		for (int i = 0; i < len; i++) {
			cin >> t;
			query.push(t);
		}
		set<int>s;
		char op;
		int rule = 1;
		while(cin >> op && op != 'e') {
			int cost;

			if (op == 'a') {
				cin >> cost;
				s.insert(cost);
			}else if (op == 'p') {
				cin >> cost;
				rule = cost;
			}else {
				if (rule == 2) {
					ve.push_back(*(--s.end()));
					s.erase(--s.end());
				}else {
					ve.push_back(*(s.begin()));
					s.erase(s.begin());
				}

			}
		}
		while(!query.empty()) {
			int index = query.front();
			query.pop();
			int size = ve.size();
			if (index <= size) {
				cout << ve[index-1] << endl;
			}else
				cout << "-1" << endl;
		}

	}
}
