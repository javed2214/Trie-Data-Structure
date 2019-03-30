// Trie Data Structure Implementation

#include<bits/stdc++.h>
using namespace std;

typedef struct TrieNode{
	unordered_map <char,TrieNode *> Map;
	bool isEndOfWord;
}TrieNode;

TrieNode *getNewTrieNode(){

	TrieNode *node=new TrieNode;
	node->isEndOfWord=false;

	return node;
}

TrieNode *insertString(TrieNode *root, vector <string> v){

	for(int i=0;i<v.size();i++){
		string str=v[i];
		if(root==NULL)
			root=getNewTrieNode();
		TrieNode *temp=root;
		for(int i=0;i<str.length();i++){
			char ch=str[i];
			if(temp->Map.find(ch)==temp->Map.end())
				temp->Map[ch]=getNewTrieNode();
			temp=temp->Map[ch];
		}
		temp->isEndOfWord=true;
	}
	return root;
}

bool searchWord(TrieNode *root, string str){

	if(root==NULL) return false;
	TrieNode *temp=root;
	for(int i=0;i<str.length();i++){
		temp=temp->Map[str[i]];
		if(temp==NULL) return false;
	}
	return temp->isEndOfWord;
}

int main(){

	vector <string> v={"gate","fun","code","trie","tree"};
	TrieNode *root=NULL;
	root=insertString(root,v);

	if(searchWord(root,"gate")) cout<<"gate: "<<"Found!";
	else cout<<"gate: "<<"Not Found!";

	cout<<"\n";

	if(searchWord(root,"coder")) cout<<"coder: "<<"Found!";
	else cout<<"coder: "<<"Not Found!";

	return 0;
}