// https://practice.geeksforgeeks.org/problems/trie-insert-and-search/0/?category[]=Trie&page=1&query=category[]Triepage1
// medium
// Trie

#include <bits/stdc++.h>
using namespace std;
const int ALPHABET_SIZE = 26; 

class TrieNode {
    public:
    TrieNode* children[ALPHABET_SIZE];
    bool endOfWord;
};

TrieNode* getNode() {
    TrieNode *node = new TrieNode();
    node->endOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        node->children[i] = NULL;
    return node;
}

void insert(TrieNode *r, string word) {
    TrieNode *root = r; 
    for(int i=0; i<word.size(); i++) {
        int index = word[i] - 'a';
        if(root->children[index] == NULL) {
            root->children[index] = getNode();
        }
        root = root->children[index];
    }
    root->endOfWord = true;
}

int search(TrieNode *r, string word) {
    TrieNode *root = r; 
    for(int i=0; i<word.size(); i++) {
        int index = word[i] - 'a';
        if(root->children[index] == NULL)
        return 0;
        root = root->children[index];
    }
    if(root != NULL && root->endOfWord)
    return 1;
    return 0;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    TrieNode* root = getNode();
	    for(int i=0; i<n; i++) {
	        string s;
	        cin>>s;
	        insert(root, s);
	    }
	    string str;
	    cin>>str;
	    cout<<search(root, str)<<endl;
	} 
	return 0;
}