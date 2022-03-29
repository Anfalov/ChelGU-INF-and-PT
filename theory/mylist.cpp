#include<iostream>
#include<list>

using namespace std;

struct node
{
	int value;
	node* left;
	node* right;
	node(int value = 0, node* left = NULL, node* right = NULL)
	{
		this->value = value;
		this->left = left;
		this->right = right;
	}
};

struct mylist {
	int size;
	node *begin, *end, *rbegin, *rend;
	mylist()
	{
		size = 0;
		begin = rbegin = rend = end = new node;
		end->left = end;
		end->right = end;
	}

	void insert(node* it, int value)
	{
		node* new_node = new node(value, it->left, it);
		it->left->right = new_node;
		it->left = new_node;
		if (it == begin)
			begin = new_node;
		if (it == end)
			rbegin = new_node;
		size++;
	}

	void erase(node* it)
	{
		if (it == end)
			throw invalid_argument("Can't erase end pointer");
		it->left->right = it->right;
		it->right->left = it->left;
		if (it == begin)
			begin = it->right;
		if (it == rbegin)
			rbegin = it->left;
		delete it;
		size--;
	}

	node* find(int value)
	{
		for (node* it = begin; it != end; it = it->right)
			if (it->value == value)
				return it;
		return end;
	}
};

int main()
{
	mylist ml;
	ml.insert(ml.begin, 1);
	ml.insert(ml.begin, 2);
	ml.insert(ml.end, 3);
	ml.insert(ml.end, 4);
	ml.insert(ml.rbegin, 5);
	cout << ml.find(3)->value << endl;
	for (auto it = ml.begin; it != ml.end; it = it->right)
		cout << it->value << " ";
	cout << endl;
	ml.erase(ml.begin->right);
	ml.erase(ml.rbegin);
	for (auto it = ml.begin; it != ml.end; it = it->right)
		cout << it->value << " ";
	cout << endl;
}
