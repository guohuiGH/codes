/*************************************************************************
    > File Name: 1259_sum_of_consecutive_primes.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年06月06日 星期一 17时14分36秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
#include<string.h>
using namespace std;

vector<int>table;

int main () {
	int tag[10001];
	memset(tag, 1, sizeof(tag));
	for (int i = 2; i <= 10000; i++) {
		if (tag[i])
			table.push_back(i);
		int j = i*2;
		while(j < 10001) {
			tag[j] = 0;
			j += i;
		}
		
	}
	int size = table.size();

	map<int,int> hash;
	vector<vector<int> >ve(size, vector<int>(size));
	for (int i = 0; i < table.size(); i++) {
		ve[i][i] = table[i];
		hash[ve[i][i]]++;
		for (int j = i+1; j < table.size(); j++) {
			ve[i][j] = ve[i][j-1] + table[j];
			hash[ve[i][j]]++;
		}
	}
	int n; 
	while (cin >> n && n != 0) {
		if (hash.find(n) == hash.end())
			cout << "0";
		else
			cout << hash[n];
		cout << endl;
	}
}
