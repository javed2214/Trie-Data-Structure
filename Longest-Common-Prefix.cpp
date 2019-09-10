// Program to Find Longest Common Prefix Using Trie Data Structure
// https://leetcode.com/problems/longest-common-prefix/
// https://www.techiedelight.com/longest-common-prefix-given-set-strings-using-trie/

#include<bits/stdc++.h>
using namespace std;

typedef struct TrieNode{

	unordered_map<char, TrieNode *> Map;
	bool isEndOfWord;

}TrieNode;

TrieNode *getNewTrieNode(){

	TrieNode *node = new TrieNode;
	node->isEndOfWord = false;

	return node;
}

TrieNode *insertWords(TrieNode *root, vector <string> &v){

	for(int i=0;i<v.size();i++){

		string s = v[i];
		if(root == NULL) root = getNewTrieNode();
		TrieNode *temp = root;
		for(auto it:s){
			if(temp->Map.find(it) == temp->Map.end()) temp->Map[it] = getNewTrieNode();
			temp = temp->Map[it];
		}
		temp->isEndOfWord = true;
	}
	return root;
}

string LCP(TrieNode *root){

	string s;
	TrieNode *node = root;

	while(node and !node->isEndOfWord and node->Map.size() == 1){

		auto it = node->Map.begin();
		s += it->first;
		node = it->second;
	}
	return s;
}

int main(){

	vector <string> v = {"coder", "coding", "codezen", "codeblocks"};
	TrieNode *root = NULL;
	root = insertWords(root, v);

	cout<<LCP(root);

	return 0;
}
