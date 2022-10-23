/*
 * treeNode.cpp
 *
 *  Created on: Aug 30, 2022
 *      Author: jsaavedr
 */

#include "treeNode.hpp"
#include <iostream>

namespace trees {

TreeNode::TreeNode(): parent(nullptr), data(new Item()), children(new TreeList()) {
}

TreeNode::TreeNode(Item * val): parent(nullptr), data(val), children(new TreeList()) {
}

void TreeNode::setParent(TreeNode* node){
	parent = node;
}
void TreeNode::setData(Item * val){
		data = val;
}
void TreeNode::setChildren(TreeList* list){
	children = list;
}
TreeNode* TreeNode::getParent(){
	return parent;
}
Item * TreeNode::getData(){
	return data;
}
TreeList* TreeNode::getChildren(){
	return children;
}

TreeNode::~TreeNode() {
	//action when a treeNode is deleted
	//delete the descendants only
	if (children != nullptr){
		delete children;
	}
}

void TreeNode::printChildren(){
	TreeListNode * ptr = children->getHead();
	while(ptr != nullptr){
		std::cout<<((ptr->getData())->getData())->getNombre()<<" ";
		ptr = ptr->getNext();
	}
	std::cout<<std::endl;
}

} /* namespace trees */
