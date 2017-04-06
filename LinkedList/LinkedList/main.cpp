#include <iostream>

using namespace std;

// ------------------------------------
// Node
// ------------------------------------ 
template <class N>
class Node {
public:
	Node(N val= 0) {
		this->value = val;
		this->next = NULL;
		this->prev = NULL;
	}
	~Node() {
		delete next;
		delete prev;
	}
	void setNext(Node * const n) { this->next = n; }
	void setPrev(Node * const n) { this->prev = n; }
	Node * getNext() const { return this->next; }
	Node * getPrev() const { return this->prev; }
	void setValue(N val) { this->value = val; }
	N getValue() const { return this->value; }

private:
	Node * next;
	Node * prev;
	N value;
};

// ------------------------------------
// List
// ------------------------------------ 
template <class L>
class List {
public:
	List() {
		this->root = NULL;
		this->tail = NULL;
		this->size = 0;
	}
	~List() {}
	List& insertNode(L val) {
		Node<L> * temp = new Node<L>;
		temp->setValue(val);

		if (!root) {
			this->root = temp;
		}
		else {
			this->root->setNext(temp);
		}

		this->tail = temp;
		temp->setNext(this->root);

		this->size++;
		return *this;
	}
	int getSize() { return this->size; }
	Node<L>* getRoot() const { return this->root; }
	Node<L>* getTail() const { return this->tail; }

	void print() {
		Node<L> * temp = this->root;
		int count = this->size;

		while (count) {
			cout << temp->getValue() << " ";
			temp = temp->getNext();
			count--;
		}

		cout << endl;
	}
private:
	Node<L>* root;
	Node<L>* tail;
	int size;
};


void main() {
	List<int> lst;

	lst.insertNode(1).insertNode(2);

	lst.print();
};