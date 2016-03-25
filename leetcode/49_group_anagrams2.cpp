/*************************************************************************
    > File Name: 49_group_anagrams2.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年03月25日 星期五 16时50分14秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<string> > groupAnagrams(vector<string>& strs) {
		map<string, vector<string> >hash;
		vector<vector<string> > ve;
		for (int i = 0; i < strs.size(); i++) {
			string copy = strs[i];
			sort(s.begin(), s.end());
			if (hash.find(copy) == hash.end()) {
				vector<string> temp;
				temp.push_back(strs[i]);
				hash.push_back(temp);
			}else
				hash[copy].push_back(strs[i])
		}
		map<string, vector<string> >::iterator it;
		for (it = hash.begin(); it != hash.end(); it++) {
			sort(it->second.begin(), it->second.end());
			ve.push_back(it->second);
		}
		return ve;

	}
};
int main () {

}
