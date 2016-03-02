/*************************************************************************
    > File Name: 1443_printer_queue.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年03月02日 星期三 20时31分34秒
 ************************************************************************/

#include<iostream>
#include<list>
using namespace std;

int findBiggest (list<int>ll, int* a) {
	list<int>::iterator it;
	int big = ll.front();
	for (it = ll.begin(); it != ll.end(); it++) {
		if (a[big] < a[*it])
			big = *it;
	}
	return big;
}

int main () {
	int N;
	cin >> N;
	for (int t = 0; t < N; t++) {
		int n,m;
		cin >> n >> m;
		int *a = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		list<int> li;
		for (int i = 0; i < n; i++) {
			if (a[i] >= a[m])
				li.push_back(i);
		}
		int result = 0;
		while(true) {
			int big = findBiggest(li, a);
			while (big != li.front()) {
				int temp = li.front();
				li.pop_front();
				li.push_back(temp);
			}

			result++;
			if (big == m)
				break;
			li.pop_front();
		}
		cout << result << endl;
		


	}
}
