#include "tree.h"
#include <iomanip>
#include <iostream>

bool bi_tree::is_empty() const // if root empty tree also empty
{
	return root == nullptr ? true: false;
}

void bi_tree::add_node(const int new_val, node* branch)
{
	if(branch == nullptr) /// if tree empty
	{
		branch = root; 
	}
	if(is_empty()) // if epmty
	{
		root = branch_init(new_val); //new element is root
	}
	else if(new_val < branch->val)  // if root exist and bigger than new elem
	{
		if(branch->left==nullptr) // and left branch empty
		{
			branch->left=branch_init(new_val); // then create new left branch
		}
		else // if branch not empty then move to that branch and try there
		{
			add_node(new_val,branch->left);
		}
	}
	else // if element bigger than root
	{
		if(branch->right==nullptr) // and right branch empty
		{
			branch->right=branch_init(new_val); //create new right branch
		}
		else // if branch not empty then move to that branch and try there
		{
			add_node(new_val,branch->right);
		}
	}
}

void bi_tree::delete_node(const int key, node* layer)
{
return;
}

void bi_tree::tree2d(const std::string& prefix, const node* layer, bool isLeft)
{
    if( layer != nullptr )
    {
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "*--" );
        std::cout << layer->val << std::endl;  // print the value of the node
        tree2d( prefix + (isLeft ? "|   " : "    "), layer->left, true);  // enter the next tree level - left and right branch
        tree2d( prefix + (isLeft ? "|   " : "    "), layer->right, false);
    }
}


void bi_tree::show(const node* layer) // symetric 
{
		if(layer == nullptr) return; // if branch empty do nothing
		show(layer->left); 
		std::cout<< layer->val<< std::endl;
		show(layer->right);
}

int bi_tree::count_one_branch(const node* layer) // how many branches with only one child
{
		if(layer == nullptr) return 0;
		if(layer->left != nullptr and layer->right== nullptr or layer->right!=nullptr and layer->left == nullptr)
		{
			return count_one_branch(layer->left) + count_one_branch(layer->right) + 1;
		}
			return count_one_branch(layer->left) + count_one_branch(layer->right);
}

int bi_tree::count_even(const node* layer) // how many even numbers
{
		if(layer == nullptr) return 0;
		if((layer->val/2 )*2==layer->val)
		{
			return count_even(layer->left) + count_even(layer->right) + 1;
		}
			return count_even(layer->left) + count_even(layer->right);
}

node* bi_tree::branch_init(const int new_val)
{
	const auto new_elem = new node(new_val);
	return new_elem;
}
