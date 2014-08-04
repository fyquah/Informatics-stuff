#include <string>
#include <stack>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

struct Node{
	char character;
	int depth;
	int edges[26];
	int parent;
	Node(char c , int h , int p){
		character = c;
		depth = h;
		parent = p;
		for(int i = 0 ; i < 26 ; i++)
			edges[i] = -1;
	}
};

vector <int> event_memory;
vector <Node> trie_nodes;
string current_str = "";
int current_node = -1;
bool state_change = false;

void Init(){

}

void TypeLetter(char c){
	if(current_node == -1){
		trie_nodes.push_back(Node(c , 0 , -1));
		current_node = 0;
		current_str += c;
	}
	else {
		if(trie_nodes[current_node].edges[c - 'a'] == -1){ // create a new node
			trie_nodes.push_back(Node(c , trie_nodes[current_node].depth + 1 , current_node));
			trie_nodes[current_node].edges[c - 'a'] = trie_nodes.size() - 1;
			current_node = trie_nodes.size() - 1;
		}
		else {
			current_node = trie_nodes[current_node].edges[c - 'a'];
		}

		if(trie_nodes[current_node].depth >= current_str.length())
			current_str += c;
		else
			current_str[trie_nodes[current_node].depth] = c;
	}
	event_memory.push_back(current_node);
	state_change = true;
}

void UndoCommands(int U) {
	int old_event = event_memory[event_memory.size() -1 - U];
	event_memory.push_back(old_event);
	current_node = old_event;
	state_change = true;
}		


char GetLetter(int P) {
	if(state_change){ // update current_str
		current_str.resize(trie_nodes[current_node].depth + 1);
		int threshold = current_node;
		while(threshold != -1){
			current_str[trie_nodes[threshold].depth] = trie_nodes[threshold].character;
			threshold = trie_nodes[threshold].parent;
		}
		state_change = false;
	}
	
	return current_str[P];
}