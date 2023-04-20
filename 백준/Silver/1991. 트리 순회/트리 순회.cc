#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using namespace std;
/*
class NODE {
public:
	NODE* left;
	NODE* right;
	char ch;
	NODE() {
		left = NULL;
		right = NULL;
		ch = ' ';
	}
	NODE(char ch) {
		this->ch = ch;
		left = NULL;
		right = NULL;
	}
};


class BI_TREE {
	public:
	NODE* root;
	BI_TREE() {
		root = NULL;
	}
	BI_TREE(NODE* rt)
	{
		root = rt;
	}

	NODE* seek_node(char ch, NODE * node) {
		NODE* ret_node;
		if (node->ch == ch) {
			return node;
		}
		else {
			ret_node = seek_node(ch, node->left);
			if (ret_node != NULL) return ret_node;
			ret_node = seek_node(ch, node->right);
			if (ret_node != NULL) return ret_node;
		}
		return NULL;
	}

	void connect_left(char ch, NODE* child) {
		NODE * parent_node = seek_node(ch, root);
		parent_node->left = child;
	}

	void connect_right(char ch, NODE* child) {
		NODE* parent_node = seek_node(ch, root);
		parent_node->left = child;
	}

	void preorder() {
		pre_order(root);
	}
	void inorder() {
		in_order(root);
	}
	void postorder() {
		post_order(root);
	}

	void pre_order(NODE * root) {
		if (root == NULL)
			return;
		pre_order(root->left);
		cout << root->ch << " ";
		pre_order(root->right);
	}
	void in_order(NODE* root) {
		if (root == NULL)
			return;
		cout << root->ch << " ";
		in_order(root->left);
		in_order(root->right);
	}
	void post_order(NODE* root) {
		if (root == NULL)
			return;
		in_order(root->left);
		in_order(root->right);
		cout << root->ch << " ";
	}
};
*/
typedef struct TREE {
	char ch='.';
	char left='.';
	char right='.';
}NODE;

NODE N[26];

void postorder(int root) {

	if (N[root].left != '.')
	postorder(N[root].left-'A');
	if (N[root].right != '.')
	postorder(N[root].right-'A');
	cout << N[root].ch;
}

void inorder(int root) {
	if (N[root].left != '.')
	inorder(N[root].left-'A');
	cout << N[root].ch;
	if (N[root].right != '.')
	inorder(N[root].right-'A');
}

void preorder(int root) {
	cout << N[root].ch;
	if(N[root].left!='.')
	preorder(N[root].left-'A');
	if (N[root].right != '.')
	preorder(N[root].right-'A');
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		char n1, n2, n3;
		cin >> n1 >> n2>>n3;
		N[n1 - 'A'].ch = n1;
		N[n1 - 'A'].left = n2;
		N[n1 - 'A'].right = n3;
	}

	preorder(0);
	cout << "\n";
	inorder(0);
	cout << "\n";
	postorder(0);
	cout << "\n";
	return 0;
}