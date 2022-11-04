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
#include "split.hpp"

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

void Tree::delete_item(TreeNode * node){
	if (node != nullptr){
		TreeList* childrenList = node->getChildren();
		TreeListNode* ptr = childrenList->getHead();
		while (ptr!=nullptr){
			delete_item(ptr->getData());
			ptr = ptr->getNext();
		}
		node->del_ch();
	}
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

//para el caso de que sea dentro hasta dentro de otras carpetas
void Tree::find_nombre_rec(std::string val, TreeNode* node, bool * encontrado,TreeNode * node_i){
	if (node != nullptr){
		if (((node->getData())->getNombre()).compare(val) == 0){
			if(node != node_i){
				if((node->getData())->getTipo() == 1)
					std::cout<<"Carpeta de nombre "<<(node->getData())->getNombre()<<" encontrada en "<<((node->getParent())->getData())->getNombre()<<std::endl;
				else
					std::cout<<"Archivo de nombre "<<(node->getData())->getNombre()<<" encontrado en "<<((node->getParent())->getData())->getNombre()<<std::endl;
				*encontrado = true;
			}
		}
		TreeList* childrenList = node->getChildren();
		TreeListNode* ptr = childrenList->getHead();
		while (ptr!=nullptr){
			find_nombre_rec(val, ptr->getData(),encontrado,node_i);
			ptr = ptr->getNext();
		}

	}
}

void Tree::find_nombre(TreeNode * desde,std::string val){
	bool en = false;
	TreeNode * des = desde;
	if (des != nullptr){
		if ((des->getData())->getTipo() == 0){
			std::cout<<"El lugar de busqueda es un archivo, debe ser una carpeta"<<std::endl;
			en = true;
		}
		else{
			find_nombre_rec(val,des,&en,des);
		}
	}
	else
		std::cout<<"Carpeta "<<desde<<" no encontrada"<<std::endl;
	if (en == false){
		std::cout<<"No se encontró "<<val<<" en "<<(desde->getData())->getNombre()<<std::endl;
	}
}

TreeNode * Tree::find_path(std::string path){
	trees::TreeNode * ptr = root;
	for(int i = 1; i<count_string(path,"/")+1;i++){
		std::string substr = split(path,"/",i);
		trees::TreeList * ch = ptr->getChildren();
		if(path.compare("/") == 0){
			return root;
		}
		if (ch != nullptr){
			trees::TreeListNode * chN = ch->getHead();
			if(chN == nullptr){
				return nullptr;
			}
			while(chN != nullptr){
				if((((chN->getData())->getData())->getNombre()).compare(substr)==0){
					ptr = chN->getData();
				}
				chN = chN->getNext();
			}
		}
		else
			return nullptr;
		if (((ptr->getData())->getNombre()).compare(substr)!=0){
			return nullptr;
		}
	}
	if(count_string(path,"/")==0){
		return find(path);
	}
	return ptr;
}

TreeNode * Tree::cd_find(std::string n, TreeNode * desde){
	TreeList* children = desde->getChildren();
	TreeNode * ans = nullptr;
	if(children != nullptr){
		TreeListNode* ptr = children->getHead();
		while(ptr != nullptr){
			if((((ptr->getData())->getData())->getNombre()).compare(n)==0)
				ans = ptr->getData();
			ptr = ptr->getNext();
		}
	}
	return ans;
}

} /* namespace trees */
