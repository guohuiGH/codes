/*************************************************************************
    > File Name: magic_box.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Tue 05 Apr 2016 02:17:02 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;

int main () {
	int x,yi,z;
	cin >> x >> yi >> z;
	int hash[20001] = {0};
	hash[x]++;
	hash[yi]++;
	hash[z]++;
	int xx = hash[x], yy = hash[yi], zz = hash[z];
	string seq;
	cin >> seq;
	int r = 0, y = 0, b = 0;
	int size = seq.size();
	int maxValue = 0,index = 0;
	for (int i = 0; i < size; i++) {
		if(seq[i] == 'R')
			r++;
		else if (seq[i] == 'Y')
			y++;
		else
			b++;
		int t1 = abs(r-y);
		int t2 = abs(b-y);
		int t3 = abs(r-b);

		hash[t1]--;
		hash[t2]--;
		hash[t3]--;
		if (!hash[x] && !hash[yi] && !hash[z]) {
			if (maxValue <= r+y+b) {
				maxValue = r+y+b;
			}
			index = i;
			r = 0; y = 0; b = 0;
		}
		hash[x] = xx; hash[yi] = yy; hash[z] = zz;
	}
	if (index == 0)
		cout << size << endl;
	else
	//cout << maxValue << endl << size-index-1 << endl;
		cout << max(maxValue,size-index-1) << endl;
}
