/*************************************************************************
    > File Name: 278_first_bad_version.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Thu 29 Oct 2015 03:06:56 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

bool isBadVersion (int version) {
	if (version >= 1)
		return true;
	return false;
}
class Solution {
public:

	int binarySearch(int left, int mid, int right) {
		bool boolLeft;
		if (mid <=1)
			boolLeft = false;
		else
			boolLeft = isBadVersion(mid-1);
		bool boolRight = isBadVersion(mid);
		if (!boolLeft && boolRight)
			return mid;
		if (!boolRight) {
			int newMid = (right-mid)/2 + mid;
			return binarySearch(mid, newMid+1, right);
		}
		else {
			int newMid = (mid-left)/2 + left;
			return binarySearch(left, newMid, mid);
		}

	}
	int firstBadVersion (int n) {
		if (n==1)
			return 1;
		int mid = (n-1)/2 + 1;
		return binarySearch(1, mid, n);
	}
};

int main () {
	Solution s;
	cout << s.firstBadVersion(20);
}
