/*************************************************************************
> File Name: 88_merge_sorted_array.cpp
> Author: guohui
> Mail: guohui1029@foxmail.com
> Created Time: Mon 19 Oct 2015 09:20:17 AM CST
************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void merge(vector<int>&nums1, int m, vector<int>& nums2, int n) {
		vector<int>::iterator it;
		int j = 0;
		int size = nums1.size();
		for (int i = 0; i < size - m; i++)
			nums1.pop_back();
		
		for (it = nums1.begin(); it != nums1.end()&& j < n; it++) {
			if (*it > nums2[j]) {
				it = nums1.insert(it, nums2[j]);
				j++;
			}
		}
		
		while (j < n) {
			nums1.push_back(nums2[j]);
			j++;
		}
	}
};

int main() {
	int a[4] = { 1,0};
	int b[2] = { 2 };
	vector<int> v1(a, a+2);
	vector<int> v2(b, b + 1);
	Solution s;
	s.merge(v1, 1, v2, 1);
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << endl;
	}
	return 1;
}
