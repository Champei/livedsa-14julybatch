#include <iostream>
#include <unordered_map>
using namespace std;

class node {
public:
	char ch;
	unordered_map<char, node*> h;
	bool isEnd;

	node(char c) {
		ch = c;
		isEnd = false;
	}
};

class Trie {
public:
	node* root;
	Trie() {
		root = new node('\0'); // Root node will store NULL character in it, kisi character ko
		// preference nhi de skte hai
	}

	void addWord(string word) {
		node* temp = root;

		for (int i = 0; i < word.size(); ++i)
		{
			char ch = word[i];

			if (temp->h.count(ch) == 1) {
				temp = temp->h[ch];
			}
			else {
				node* n = new node(ch);
				temp->h[ch] = n;
				temp = n;
			}
		}

		temp -> isEnd = true;
	}

	bool searchWord(string word) {
		node* temp = root;
		for (int i = 0; i < word.size(); ++i)
		{
			char ch = word[i];

			if (temp->h.count(ch) == 1) {
				temp = temp->h[ch];
			}
			else {
				return false;
			}
		}

		return temp->isEnd; // This must be true yaha pata chlega ki word end hota hai ya nahi hota
	}
};

int main() {

	Trie t;
	t.addWord("Hello");
	t.addWord("Her");
	t.addWord("Hey");
	t.addWord("Code");
	t.addWord("Coder");

	string key = "Code";
	if (t.searchWord(key)) cout << "Word Found\n";
	else cout << "Word Not Found\n";

	return 0;
}
















