/*************************************************************************
    > File Name: 187_repeated_dna_sequence.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年03月26日 星期六 22时01分38秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		map<string,int>hash;
		vector<string> ve;
		string a = "";
		cout << a.length()-1 << endl;

		int tag = s.length() - 10;
		for (int i = 0; i < tag; i++){

			string temp = s.substr(i,10);

			hash[temp]++;
		}
		map<string, int>::iterator it;
		for (it = hash.begin(); it!= hash.end(); it++) {
			if (it->second > 1)
				ve.push_back(it->first);
		}
		return ve;
	}
};
int main () {
	Solution s;
	vector<string> v = s.findRepeatedDnaSequences("AAAAAAAAAAA");
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}
