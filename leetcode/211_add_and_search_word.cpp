/*************************************************************************
    > File Name: 211_add_and_search_word.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年02月24日 星期三 16时23分55秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

class TrieNode{

public:
	TrieNode () {
		for (int i = 0;i < 26; i++) {
			next[i] = NULL;
		}
		isWord = false;
		position = -1;
	}

	char ch;
	TrieNode* next[26];
	bool isWord;
	int position;

};

class WordDictionary {
public: TrieNode* root;

public:
	WordDictionary() {
		root = new TrieNode();
	}
	void addWord(string word) {
		int size = word.length();
		TrieNode* temp = root;
		for (int i = 0; i < size; i++) {
			int index = word[i] - 'a';
			if (temp->next[index] == NULL) {
				TrieNode* node = new TrieNode();
				node->ch = word[i];
				node->position = i;
				temp->next[index] = node;
			}
			temp = temp->next[index];
		}
		temp->isWord = true;
	}

	bool search(string word) {
		int size = word.length();
		stack<TrieNode*> st;
		st.push(root);
		while (!st.empty()){
			TrieNode* node = st.top();
			st.pop();
			int ch_po = node->position;
			if (ch_po == size-1 && node->isWord)
				return true;
			if (ch_po>=size-1)
				continue;
			char target = word[ch_po+1];
			if (target == '.') {

				for (int i = 0; i < 26; i++) {
					if (node->next[i]) {
						st.push(node->next[i]);
					}
				}
				
			}else {
				int new_index = target - 'a';
				if (node->next[new_index]) {
					st.push(node->next[new_index]);
				}
			}
		}
		return false;
	}
};

int main () {
	WordDictionary wd;
	wd.addWord("bad");
	wd.addWord("cad");
	wd.addWord("adfad");
	cout << wd.search(".") << endl;
	//cout << wd.search(".") << wd.search(".") << endl;

}
