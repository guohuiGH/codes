/*************************************************************************
    > File Name: 1014_trie_tree.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Mon 21 Sep 2015 09:38:16 AM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<string.h>
using namespace std;

struct Node{
	char value;
	int count;
	Node *next[26];
};

void createNode(Node *root, string str) {
	int length = str.length();
	for(int i = 0; i < length; i++) {
		int index = str[i] - 'a';
		if (root->next[index] == NULL) {
			Node *temp;
			temp = new Node;
			temp->value = str[i];
			temp->count = 1;
			root->next[index] = temp;
			root = temp;
		}else {
			root->next[index]->count += 1;
			root = root->next[index];
		}
		
	}
}

int searchNode(Node *root, string str) {
	int length = str.length();
	for (int i = 0; i < length; i++) {
		int index = str[i] - 'a';
		if (root->next[index] == NULL)
			return 0;
		root = root->next[index];
	}
	return root->count;
}

int main(){
	int n;
	cin >> n;
	Node *root;
	
	root = new Node;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		createNode(root, str);
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		cout << searchNode(root, str) << endl;
	}
}
