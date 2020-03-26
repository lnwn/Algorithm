// 06-delete.cpp : 删除节点。
// 2020/03/26
// ? 难点在于删除节点后如何处理其子节点以保持二分搜索树性质
// 先考虑删除的是最小值和最大值
// 时间复杂度：O(logn)
// 只有左孩子/只有右孩子
// 删除左右都有孩子节点：Hubbard Deletion--用前驱/后继节点代替
// 后继节点--待删除节点的右子树中最小值对应的节点
// 前驱节点--待删除节点的左子树中最大值对应的节点
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

		Node(Node *node) {
			this->key = node->key;
			this->value = node->value;
			this->left = node->left;
			this->right = node->right;
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
		// x todo ~BST()
		destroy(root);
	}
	// 返回节点个数
	int size() {
		return count;
	}

	// 向树中插入一个新（key，value）
	void insert(Ke.y key, Value value) {
		root = insert(root, key, value);
	}

	bool contain(Key key) {
		return contain(root, key);
	}

	// 直接返回 node 没有将定义的数据结构进行隐藏
	// 返回 value 则前提是这个 value 已存在
	// 返回 value* ，node空时则返回空，否则返回 value
	Value* search(Node* node, Key key) {
		if (node == NULL)
			return NULL;
		if (key == node->key)
			return &(node->value);// 返回 vlaue 对应的地址
		else if (key < node->value)
			return search(node->left, key);
		else
			return search(node->right, key);
	}

	// 前序遍历
	void preOrder() {
		preOrder(root);
	}
	// 中序遍历
	void inOrder() {
		inOrder(root);
	}
	// 后序遍历
	void postOrder() {
		postOrder(root);
	}
	// 层序遍历
	void levelOrder() {
		queue<Node*> q;
		q.push(root);// 入队根节点
		while (!q.empty()) {
			Node *node = q.front();// 取队首元素
			q.pop();// 出队

			cout << node->key << endl;
			// 将其子节点入队
			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}
	}
	// 寻找最小的键值
	Key minimum() {
		assert(count != 0);
		Node* minNode = minimum(root);
		return minNode->key;
	}
	// 寻找最大的键值
	Key maximum() {
		assert(count != 0);
		Node* maxNode = maximum(root);
		return maxNode->key;
	}
	// 删除最小值所在节点
	void removeMin() {
		if (root)
			root = removeMin(root);
	}
	// 删除最大值所在节点
	void removeMax() {
		if (root)
			root = removeMax(root);
	}
	// 从二叉树中删除键值为 key 的节点
	void remove(Key, key) {
		root = remove(root, key);
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
	bool contain(Node* node, Key key) {
		if (node == NULL)
			return false;
		if (key == node->key)
			return true;
		else if (key < node->key)
			return contain(node->left, key);
		else
			return contain(node->right, key);
	}
	void preOrder(Node* node) {
		if (node != NULL) {
			cout << node->key << endl;
			preOrder(node->left);
			preOrder(node->right);
		}
	}
	void inOrder(Node* node) {
		if (node != NULL) {
			inOrder(node->left);
			cout << node->key << endl;
			inOrder(node->right);
		}
	}
	void postOrder(Node* node) {
		if (node != NULL) {
			postOrder(node->left);
			postOrder(node->right);
			cout << node->key << endl;
		}
	}
	void destroy(Node* node) {
		if (node != NULL) {
			destroy(node->left);
			destroy(node->right);
			delete node;
			count--;
		}
	}
	Node* minimum(Node* node) {
		if (node->left == NULL)
			return node;
		return minimum(node->left);
	}
	Node* maximum(Node* node) {
		if (node->right == NULL)
			return node;
		return minimum(node->right);
	}
	// 删除以 node 为根节点的二分搜索树的最小值所在节点
	// 返回删除节点后新的根（相对于原来以 node 为根节点的树）
	Node* removeMin(Node* node) {
		if (node->left == NULL) {
			Node* rightNode = node->right;
			delete node;
			count--;
			return rightNode;
		}
		node->left = removeMin(node->left);
		return node;
	}
	// 删除以 node 为根节点的二分搜索树的最小值所在节点
	// 返回删除节点后新的根（相对于原来以 node 为根节点的树）
	Node* removeMax(Node* node) {
		if (node->right == NULL) {
			Node* leftNode = node->left;
			delete node;
			count--;
			return leftNode;
		}
		node->right = removeMax(node->right);
		return node;
	}
	Node* remove(Node* node, Key key) {
		if (node == NULL)
			return NULL;
		if (key < node->key) {
			node->left = remove(node->left, key);
			return node;
		}
		else if (key > node->key) {
			node->right = remove(node->right, key);
			return node;
		}
		else {// key == node->key
			if (node->left == NULL) {
				Node *rightnode = node->key;
				delete node;
				count--;
				return rightNode;
			}
			if (node->right == NULL) {
				Node *leftNode = node->left;
				delete node;
				count--;
				return leftNode;
			}
			// node->left != NULL && node->right != NULL
			Node *successor = new Node(minimum(node->right));
			count++;

			successor->right = removeMin(node->right);
			successor->left = node->left;

			delete node;
			count--;

			return successor;
		}
	}
};
int main() {
	return 0;
}
