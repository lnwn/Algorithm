// 02-insert.cpp : binary search tree - insert。
// 2020/03/22

// 插入的元素与待插入位置本身元素重合时，用新元素覆盖原元素
#include <iostream>

using namespace std;

// binary search tree
template<typename Key, typename Value>
class BST {

private:
	struct Node {
		Key key;
		Value value;
		Node *left;
		Node *right;

		Node(Key key, Value value) {
			this->key = key;
			this->value = value;
			this->left = this->right = NULL;
		}
	};

	Node *root;// 根节点
	int count;// 树中节点个数

public:
	// 构造函数，默认构造一棵空树
	BST() {
		root = NULL;
		count = 0;
	}
	// 析构函数
	~BST() {
		// todo ~BST()
	}
	// 返回节点个数
	int size() {
		return count;
	}
	// 向树中插入一个新（key，value）
	void insert(Ke.y key, Value value) {
		root = insert(root, key, value);
	}

private:
	// 使用递归算法
	// 返回插入新节点后二叉搜索树的根
	Node* insert(Node *node, Key key, Value value) {
		if (node == null) {
			count++;
			return new Node(key, value);
		}
		if (key == node->key)
			node->value = value;
		else if (key < node->key)
			node->left = insert(node->left, key, value);
		else
			node->right = insert(node->right, key, value);
		return node;
	}
};
int main() {
	return 0;
}