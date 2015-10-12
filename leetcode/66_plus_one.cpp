/*************************************************************************
    > File Name: 26_plus_one.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Mon 12 Oct 2015 10:42:31 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> plusOne(vector<int>&digits) {
		int i = digits.size()-1;
		if (i<0)
			return digits;
		digits[i]++;
		while(i>=0) {
			if (digits[i]<=9) {
				return digits;
			}else {
				digits[i] = 0;
				if (i!=0)
					digits[i-1]++;
			}
			i--;
		}
		if (digits[i]==0)
			digits.insert(digits.begin(),1);
		return digits;
	}
};
int main () {
	Solution s;
	int a[]={9,9};
	vector<int> v(a, a+2);
	s.plusOne(v);
	for (int i = 0; i < v.size(); i++)
		cout << v[i];
	return 0;
}
