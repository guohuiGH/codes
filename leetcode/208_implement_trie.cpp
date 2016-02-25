/*************************************************************************
    > File Name: 208_implement_trie.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年02月22日 星期一 20时12分45秒
 ************************************************************************/

#include<iostream>
using namespace std;
class TrieNode {
public:
	TrieNode() {
		for (int i = 0; i < 26; i++) {
			next[i] = NULL;
		}
		isWord = false;
		//TrieNode(char x):ch(x),next(NULL){}
	}
	
	char ch;
	TrieNode *next[26];
	bool isWord;
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}
	void insert(string word) {
		int size = word.length();
		TrieNode* temp = root;
		for(int i = 0; i < size; i++) {
			int index = word[i] - 'a';
			if (temp->next[index] == NULL) {
				TrieNode* node = new TrieNode();	
				node->ch = word[i];
				temp->next[index] = node;

			}
			temp = temp->next[index];
		}
		temp->isWord = true;
	}

	bool search (string word) {
		int size = word.length();
		TrieNode *temp = root;
		for (int i = 0; i < size; i++) {
			int index = word[i] - 'a';
			
			if (temp->next[index] == NULL)
				return false;
			temp = temp->next[index];

		}
		if (temp->isWord)
			return true;
		
		return false;
	}
	bool startsWith(string prefix) {
		int size = prefix.length();
		TrieNode *temp = root;
		for (int i = 0; i < size; i++) {
			int index = prefix[i] - 'a';
			if (temp->next[index] == NULL)
				return false;
			temp = temp->next[index];
		}
		return true;
	}
private:
	TrieNode * root;
};

int main () {
	Trie trie;
	trie.insert("somestring");
	trie.insert("abc");

	cout << trie.search("abc");
	cout << trie.search("ab");
	
	trie.insert("ab");
	cout << trie.search("ab");
	cout << trie.startsWith("so");
}
