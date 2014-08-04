#include <vector>
#include <cstring>
#include <string>

class Vertex
{
public:
	int words;
	int prefixes;
	int index;
	char character;
	int edges[256];
	bool is_word;

	Vertex(const int & i){
		index = i;
		words = 0;
		prefixes = 0;
		is_word = false;
		character = 0;
		memset(edges , -1 , sizeof(edges));
	}
};

class Trie
{
public:
	std::vector <Vertex> all_vertices;
	// void addWord(string & word , const int & cur);
	void addWord(std::string & word , std::vector<Vertex>::iterator node);
	const bool findWord(std::string & word , const Vertex & node);
	const int countPrefix(std::string & word , const Vertex & node);
public:
	int size(){
		return all_vertices[0].words;
	}
	Trie();
	// void addWord(string word){ addWord(word , 0); }
	void addWord(std::string word){ addWord(word , all_vertices.begin()); }
	const bool findWord(std::string word){ return findWord(word , all_vertices[0]); }
	const int countPrefix(std::string word){ return countPrefix(word , all_vertices[0]); }
};

Trie::Trie(){
	all_vertices.push_back(Vertex(0));
}

void Trie::addWord(std::string & word , std::vector<Vertex>::iterator node){
	node->words++;
	if(word.length() == 0){
		node->is_word = true;
		return;
	}
	int new_index;
	if(node->edges[word[0]] == -1){
		new_index = all_vertices.size();
		node->edges[word[0]] = new_index;
		all_vertices.push_back(Vertex(new_index));
		all_vertices[new_index].character = word[0];
	}

	else
		new_index = node->edges[word[0]];

	word.erase(word.begin());
	addWord(word , all_vertices.begin() + new_index);
}

// void Trie::addWord(string & word , const int & cur){
// 	if(word.length() == 0){
// 		all_vertices[cur].is_word = true;
// 		all_vertices[cur].words++;
// 		return;
// 	}
// 	int new_index;
// 	if(all_vertices[cur].edges[word[0]] == -1){
// 		all_vertices.push_back(Vertex(all_vertices.size()));
// 		new_index = all_vertices.size()-1;
// 		all_vertices[cur].edges[word[0]] = new_index;
// 	}
// 	else
// 		new_index = all_vertices[cur].edges[word[0]];

// 	all_vertices[cur].words++;

// 	word.erase(word.begin());
// 	addWord(word , new_index);
// }

const int Trie::countPrefix(std::string & word , const Vertex & node){
	if(word.length() == 0)
		return node.words;

	int new_index;

	if(node.edges[word[0]] == -1)
		return 0;
	else {
		new_index = node.edges[word[0]];
		word.erase(word.begin());
		return countPrefix(word , all_vertices[new_index]);
	}

}

const bool Trie::findWord(std::string & word , const Vertex & node){
	if(word.length() == 0)
		return node.is_word;
	int new_index;
	if(node.edges[word[0]] == -1)
		return false;
	else{
		new_index = node.edges[word[0]];
		word.erase(word.begin());
		return findWord(word , all_vertices[new_index]);
	}
}
