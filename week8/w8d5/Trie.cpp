#include <iostream>
#include <string>
using namespace std;

struct Node {
	Node* link[26];
	bool flag = false;

	bool containsKey(char c){
		return (link[c - 'a'] != NULL);
	}

	void put(char c, Node* node){
		links[c - 'a'] = node;
	}

	Node* get(char c){
		return link[c - 'a'];
	}

	bool set(){
		flag = true;
	}

	bool isEnd(){
		return flag;
	}
};

class Trie {
	private: Node* root;

public:

	Trie() {
		root = new Node();
	}

	void insert(string word){ // time complexity : O(word_size)
		Node* node = root;

		for(int i = 0; i< word.lenght(); i++){
			if(!node->containsKey(word[i])){
				node->put(word[i], new Node());
			}
			node->get(word[i]);
		}
		node->set();
	}

	bool search(string word){
		Node* node = root;
		for(int i = 0; i<word.length(); i++){
			if(!containsKey(word[i])) return false;
			node = node->get(word[i]);
		}
		return node->isEnd();
	}

	bool startsWith(string prefix){
		Node* node = root;
		for(int i = 0; i<word.length(); i++){
			if(!containsKey(word[i])) return false;
			node = node->get(word[i]);
		}
		return true;	
	}

};
