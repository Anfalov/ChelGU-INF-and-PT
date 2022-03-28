#include<iostream>
#include<string>

using namespace std;

struct node {
	string value;
	node* left;
	node* right;
	node(string value = "", node* left = NULL, node* right = NULL)
	{
		this->value = value;
		this->left = left;
		this->right = right;
	}
};

struct mylist {
	node* begin, * end, * rbegin, * rend;
	int size;

	mylist()
	{
		begin = rbegin = rend = end = new node;
		end->left = end;
		end->right = end;
		size = 0;
	}

	void insert(node* it, string value)
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
			throw invalid_argument("Can't erase end");
		it->left->right = it->right;
		it->right->left= it->left;
		if (begin == it)
			begin = it->right;
		if (rbegin == it)
			rbegin = it->left;
		delete it;
		size--;
	}

	node* find(string value)
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
	int n;
	cin >> n;
	string name, com;
	for (int i = 0; i < n; i++)
	{
		cin >> com;
		if (com == "Run")
		{
			cin.get();
			getline(cin, name);
			ml.insert(ml.begin, name);
		}
		else
		{
			int count = ((com.size() - 3) / 4) % ml.size;
			auto it = ml.begin;
			for (int j = 0; j < count; j++)
				it = it->right;
			ml.insert(ml.begin, it->value);
			ml.erase(it);
		}
		cout << ml.begin->value << endl;
	}
}
