#include <iostream>

using namespace std;

template <typename T>
struct NodeTree
{
	T item;
	NodeTree<T>* left;
	NodeTree<T>* right;
};

template <typename T>
class Tree {
public:
	Tree() { // ����������� �� ���������
		tree->left = nullptr;
		tree->right = nullptr;
	}
	//TODO: ����������� � ����������, ����������� �����������, �������� =, �������� � Main

	//Tree(const T& item) { // ����������� � ����������
	//	NodeTree<T> tree = new NodeTree;
	//	Add(item, tree);
	//}

	//Tree(const Tree& object) { // ����������� �����������
	//	if (object == nullptr)
	//		return;

	//}

	//Tree& operator =(const Tree&) { // �������� ������������

	//}

	~Tree() { // ����������
		Clear();
	}

	void Add(T item, NodeTree<T>*& tree) { // ���������� ��������
		if (!tree) {
			tree = new NodeTree;
			tree->item = item;
			tree->left = nullptr;
			tree->right = nullptr;
		}
		else {
			if (tree->item > item)
				Add(item, tree->left);
			else
				Add(item, tree->right);
		}
	}

	void Print(NodeTree<T>* tree) { // ������ �����
		if (tree != nullptr) {
			cout << " " << tree->item;
			Print(tree->left);
			Print(tree->right);
		}
	}

	NodeTree<T>* Delete(NodeTree<T>*& tree, T item) { // �������� ��������
		if (tree == nullptr)
			return tree;
		if (item == tree->item) {
			NodeTree<T>* temp1;
			if (tree->right == nullptr)
				temp1 = tree->left;
			else {
				NodeTree<T>* temp2 = tree->left;
				if (temp2->left == nullptr)
				{
					temp2->left = tree->left;
					temp1 = temp2;
				}
				else {
					NodeTree<T>* temp3 = temp2->left;
					while (temp3->left != nullptr) {
						temp2 = temp3;
						temp3 = temp2->left;
					}
					temp2->left = temp3->right;
					temp3->left = tree->left;
					temp3->right = tree->right;
					temp1 = temp3;
				}
			}
			delete tree;
			return temp1;
		}
		else if (item < tree->item)
			tree->left = Delete(tree->left, item);
		else
			tree->right = Delete(tree->right, item);
	}

	void Clear(NodeTree<T>* tree) { // �������
		if (!tree)
			return;
		Clear(tree->left);
		Clear(tree->right);
		delete tree;
		return;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
};