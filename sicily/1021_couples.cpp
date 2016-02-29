/*************************************************************************
    > File Name: 1021_couples.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年02月29日 星期一 11时59分33秒
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

int main () {
	int N;
	while (cin >> N && N) {
		int *a = new int[2*N];
		int t1, t2;
		for (int i = 0; i < N; i++) {
			cin >> t1 >> t2;
			a[t1] = i;
			a[t2] = i;
		}
		stack<int>st;
		for (int i = 1; i <= 2*N; i++) {
			if (st.empty())
				st.push(i);
			else {
				if (a[st.top()] == a[i])
					st.pop();
				else
					st.push(i);
			}
		}
		if (st.empty())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		delete a;
	}
}
