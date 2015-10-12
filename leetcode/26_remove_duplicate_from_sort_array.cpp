/*************************************************************************
    > File Name: 26_remove_duplicate_from_sort_array.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Mon 12 Oct 2015 09:20:37 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int removeDuplicate(vector<int>&nums) {

		int size = nums.size();

		if (size<=1)
			return size;

		vector<int>::iterator it;
		for (it = nums.begin(); ; it++) {
			if (it+1 == nums.end())
				break;
			if ((it+1)!= nums.end() && *it == *(it+1)){
				nums.erase(it);
				it--;
			}

		}
		return nums.size();
	}
};

int main() {
		
	int a[3] = {1,1,2};
	vector<int> v(a, a+3);
	
	Solution s;
	s.removeDuplicate(v);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	return 0;
}
