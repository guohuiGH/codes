/*************************************************************************
    > File Name: 318_maximum_product_of_word_length.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年02月18日 星期四 15时37分27秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string>
using namespace std;

class Solution {
public:
	int maxProduct(vector<string>& words) {
		int size = words.size();
		int *data = (int*)malloc(sizeof(int)*size);
		for (int i = 0; i < size; i++) {
			string str = words[i];
			int bit = 0;
			for (int j = 0; j < str.length(); j++)
				bit = bit | (1 << (str[j]-'a'));
			data[i] = bit;
		}
		int max = 0;


		for (int i = 0; i < size; i++) {
			for (int j = i+1; j < size; j++) {
				
				int temp = words[i].length() * words[j].length();
				if (temp > max && ((data[i] & data[j]) == 0)) {
					max = temp;
				}
			}
		}
		return max;
	}
};

int main () {
	vector<string>ve;
	ve.push_back("abcw");
	ve.push_back("baz");
	ve.push_back("foo");
	ve.push_back("xtfn");
	Solution s;
	cout << s.maxProduct(ve);
	return 0;
}

