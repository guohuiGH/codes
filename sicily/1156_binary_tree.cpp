/*************************************************************************
    > File Name: 1156_binary_tree.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Tue 01 Mar 2016 01:48:57 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

struct Node {
public:
	int left, right;
	string ch;
	bool isroot;

};

string preOrder(Node* node, int ind) {
	if (ind == 0)
		return "";
	int l = node[ind].left;
	int r = node[ind].right;

	return node[ind].ch + preOrder(node, l) + preOrder(node, r);
}

int main () {
	int N;
	while (cin >> N) {
		Node *node = new Node[1001];
		for (int i = 0; i < 1001; i++) {
			node[i].isroot = true;
		}
		int id, l, r;
		string c;
		vector<int>ve;
		for (int i = 0; i < N; i++) {
			cin >> id >> c >> l >> r;
			node[id].ch = c;
			node[id].left = l;
			node[id].right = r;
			node[l].isroot = false;
			node[r].isroot = false;
			ve.push_back(id);
		}

		int rootId = 0;
		for (int i = 0; i < N; i++) {
			if (node[ve[i]].isroot) {
				rootId = ve[i];
				break;
			}
		}

		string result = preOrder(node,rootId);
		cout << result << endl;
		//delete node;
		
	}
}
