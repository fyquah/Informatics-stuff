#include <vector>

class BinaryIndexTree
{
public:
	BinaryIndexTree(int n);
	void set(int index , int value);
	int get(int index);
	int size(){
		return this->tree.size();
	}
private:
	std::vector<int> tree;
	std::vector<int> container;

};

BinaryIndexTree::BinaryIndexTree(int n){
	tree.clear();
	container.clear();
	container.resize(n , 0);
	tree.resize(n , 0);
}

void BinaryIndexTree::set(int index , int value){
	int temp = container[index];
	container[index] = value;	
	value -= temp;
	index++;
	while(index <= this->size()){
		tree[index-1] += value;
		index += (index) & (-index);
	}
}

int BinaryIndexTree::get(int index){
	int sum = 0;
	index++;
	while(index > 0){
		sum += tree[index-1];
		index -= (index) & (-index);
	}
	return sum;
}

// #include <cstring>

// template <class T>
// class BinaryIndexTree
// {
// public:
// 	BinaryIndexTree(const int & n);
// 	int get(const int &index);
// 	void set();
// 	int size(){
// 		return number_of_elements;
// 	}
// 	void push();
// private:
// 	int * container;
// 	int number_of_elements;
// 	int allocated_size;
// };

// template <class T>
// BinaryIndexTree<T>::BinaryIndexTree(const int & n){
// 	allocated_size = n * 2;
// 	number_of_elements = n;
// 	container = new <T>[allocated_size];
// 	memset(container , 0 , allocated_size * sizeof(<T>));
// }

// template <class T>
// BinaryIndexTree<T>::get(const int &index){
// 	while(index >= 0){

// 	}
// }