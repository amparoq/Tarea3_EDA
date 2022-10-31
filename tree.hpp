/*
 * tree.hpp
 *
 *  Created on: Aug 31, 2022
 *      Author: jsaavedr
 */

#ifndef TREE_HPP_
#define TREE_HPP_

#include "treeNode.hpp"
#include <string>

namespace trees {

class Tree {
private:
	TreeNode* root;
public:
	Tree();
	void setRoot(TreeNode* node);
	void insert(TreeNode* node, TreeNode* parent);
	void insert(std::string child, std::string parent);
	TreeNode* find_rec(std::string val, TreeNode* node);
	TreeNode* find(std::string val);
	TreeNode* find_dir_rec(std::string val, TreeNode* node);
	TreeNode* find_dir(std::string val);
	void delete_item(TreeNode * node);
	std::string getUbicacion(TreeNode *);
	void find_nombre_rec(std::string val, TreeNode* node, bool * en, TreeNode* node_i);
	void find_nombre(std::string val,std::string desde);
	void traverse_rec(TreeNode* node, int level);
	void traverse(TreeNode * node);
	TreeNode * find_path(std::string path);
	TreeNode * cd_find(std::string n, TreeNode * desde);
	virtual ~Tree();
};

} /* namespace trees */

#endif /* TREE_HPP_ */
