/*
 * tree.cpp
 *
 *  Created on: Aug 31, 2022
 *      Author: jsaavedr
 */

#include "tree.hpp"
#include <iostream>
#include <sstream>
#include <vector>

namespace trees {

Tree::Tree(): root(nullptr) {

}

void Tree::setRoot(TreeNode* node){
	if (root == nullptr){
		root = node;
	}
}
void Tree::insert(TreeNode* child, TreeNode* parent){
	if (parent != nullptr){
		parent->getChildren()->insertFirst(child);
		child->setParent(parent);
	}
}

void Tree::insert(std::string val, std::string val_parent){
	TreeNode* parent = find(val_parent);
	if (parent != nullptr){
		Item * c = new Item(val);
		TreeNode* child = new TreeNode(c);
		insert(child, parent);
		std::cout << "insertado " << val << " in " << val_parent << " at " << parent << std::endl;
	}
}

TreeNode* Tree::find_rec(std::string val, TreeNode* node){
	TreeNode* ans = nullptr;
	if (node != nullptr){
		if (((node->getData())->getNombre()).compare(val) == 0){
			ans = node;
		}
		else{ // search in children
			TreeList* childrenList = node->getChildren();
			TreeListNode* ptr = childrenList->getHead();
			while (ptr!=nullptr && ans == nullptr){
				ans = find_rec(val, ptr->getData());
				ptr = ptr->getNext();
			}
		}
	}
	return ans;
}

TreeNode* Tree::find(std::string val){
	TreeNode* ans = find_rec(val, root);
	return ans;
}


void Tree::traverse_rec(TreeNode* node, int level){
	if (node != nullptr){
		std::cout << std::string(level*2, '-');
		std::cout<<(node->getData())->getNombre()<<std::endl;
		TreeList* childrenList = node->getChildren();
		TreeListNode* ptr = childrenList->getHead();
		while (ptr!=nullptr){
			traverse_rec(ptr->getData(), level + 1);
			ptr = ptr->getNext();
		}
	}
}

void Tree::traverse(TreeNode * node){
	traverse_rec(node, 1);
}

Tree::~Tree() {
	delete root;
}

std::string Tree::getUbicacion(TreeNode * node){
	trees::TreeNode * ptr = node;
	std::vector<std::string> car;
	std::stringstream j;
	while(ptr != nullptr){
		car.push_back((ptr->getData())->getNombre());
		ptr = ptr->getParent();
	}
	if ((car.size())-1 != 0){
		for (int i = (car.size())-1;i>=0;i--)
		{
			if(i != (car.size())-1){
				j<<car[i];
			}
			if(i != 0){
				j<<"/";
			}
		}
	}
	else
		j<<car[0];
	j<<"#";
	return j.str();
}

} /* namespace trees */
