// Program to Print All the Contents of Trie Data Structure

#include<bits/stdc++.h>
using namespace std;

typedef struct TrieNode{
	unordered_map <char, TrieNode *> Map;
	bool isEndOfWord;
}TrieNode;

TrieNode *getTrieNode(){

	TrieNode *node=new TrieNode;
	node->isEndOfWord=false;

	return node;
}

TrieNode *insertString(TrieNode *root, vector <string> v){

	for(int i=0;i<v.size();i++){
		if(root==NULL)
			root=getTrieNode();
		TrieNode *temp=root;
		string str=v[i];
		for(int i=0;i<str.length();i++){
			char ch=str[i];
			if(temp->Map.find(ch)==temp->Map.end())
				temp->Map[ch]=getTrieNode();
			temp=temp->Map[ch];
		}
		temp->isEndOfWord=true;
	}
	return root;
}

void printWords(TrieNode *root, string str){

	if(root->isEndOfWord==true){
		cout<<str<<"\n";
		return;
	}
	unordered_map<char, TrieNode *>::iterator it;
	it=root->Map.begin();
	while(it!=root->Map.end()){
		str.push_back(it->first);
		printWords(it->second,str);
		str.erase(str.length()-1);
		it++;
	}
}

int main(){

	vector <string> v={"gate","fun","code","trie","tree"};
	TrieNode *root=NULL;
	root=insertString(root,v);

	string str;
	printWords(root,str);

	return 0;
}