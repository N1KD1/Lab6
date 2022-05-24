#pragma once
#include <algorithm>
#include <string>

struct node {
	int val;
	node* right;
	node* left;
	explicit node(int val) : val(val), right(nullptr), left(nullptr) {}
};

struct bi_tree
{
	node* root;
	bi_tree() : root(nullptr) {}
	bool is_empty() const;
	void add_node(int new_val, node *branch = nullptr);
	static node* delete_node(int key , node * layer);
	void clear(node* layer);
	static void tree2d(const std::string& prefix, const node* layer, bool isLeft );
	static void show(const node* layer);
	static int count_one_branch(const node* layer);
	static int count_even(const node* layer);
	static node* min_value_node(struct node* layer);
private:
	static node *branch_init(int new_val);
	
};
