/*
 * treeNode.hpp
 *
 *  Created on: Aug 30, 2022
 *      Author: jsaavedr
 */

#ifndef TREENODE_HPP_
#define TREENODE_HPP_

#include <string>
#include "treeList.hpp"
#include "Item.hpp"

namespace trees {

class TreeList;
class TreeNode {
private:
	TreeNode* parent;
	Item * data; //data can be of any type
	TreeList* children;
public:
	TreeNode();
	TreeNode(Item * val);
	void setParent(TreeNode* node);
	void setData(Item * val);
	void setChildren(TreeList* list);
	TreeNode* getParent();
	Item * getData();
	TreeList* getChildren();
	void printChildren();
	void del_ch();
	virtual ~TreeNode();
};

} /* namespace trees */

#endif /* TREENODE_HPP_ */
