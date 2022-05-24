#include "tree.h"
#include <iostream>

int main()
{
    bi_tree new_tree;
	int some_val=0;
    while(true)
    {
	    std::cout<<"Add new elem to the tree:\n>>>";
	    std::cin>>some_val;
        if(some_val == 0) break;
    	new_tree.add_node(some_val); 
    }
    bi_tree::show(new_tree.root);
    std::cout <<"Elements with one branch in tree: " << bi_tree::count_one_branch(new_tree.root) << std::endl <<"Even elements in tree: "<< bi_tree::count_even(new_tree.root)<< std::endl;
    new_tree.tree2d(">", new_tree.root, false);
    while (true)
    {
	    int key;
	    std::cout <<"Delete elem:\n>>>";
	    std::cin >> key;
        if(key == 999)
        {
	        new_tree.clear(new_tree.root);
	        std::cout<< new_tree.is_empty();
        }
        new_tree.delete_node(key, new_tree.root);
        new_tree.tree2d(">", new_tree.root, false);
    }
}
