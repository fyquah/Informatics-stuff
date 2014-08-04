#include <vector>
#include <cstring>
#include <iostream>

template <class T>
class BinarySearchTree
{
public:
	BinarySearchTree();
	void push(T object);
	bool find(T object);
	T top();
	T pop();
private:
	std::vector<T> container;
	std::vector<T> present;
};

BinarySearchTree::BinarySearchTree() {

}

void BinarySearchTree::push(const <T> & object) {
	long long node = 0;
	while(true){
		if(container.size() - 1 < node){ // need to do some resizing
			container.resize(node + 1 , 0);
			present.resize(node + 1 , false);
			present[node] = true;
		}

		if(container[node] == object){
			present[node] = true;
			return;
		}

		else if(container[node] > object)
			node = node * 2 + 2;
		else if(container[node] < object)
			node = node * 2 + 1;
	}	
	return;
}

bool BinarySearchTree::find(const T & object) {
	long long node = 0;
	while(true){
		if(container.size() - 1 < node)
			return false;

		if(container[node] == object){
			if(present[node]) return true;
			else return false;
		}

		else if(container[node] > object)
			node = node * 2 + 2;
		else if(container[node] < object)
			node = node * 2 + 1;
	}	
	return false;
}

T BinarySearchTree::top(){
	long long node = 0;
	try{
		if(container.size() == 0)
			throw "No contents!";
		while(true){
			if(node*2+2 + 1 > container.size())
				return container[node];
			else
				node = node * 2 + 2;
		}
	}
	catch(char * e) {
		std::cerr << e << std::endl;
	}
	
	
}