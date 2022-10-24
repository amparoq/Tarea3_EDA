#include "tree.hpp"
#include "treeList.hpp"
#include "treeListNode.hpp"
#include "treeNode.hpp"
#include <iostream>
#include <sstream>

std::string filtrar_nombre(std::string path){
    int u = 0;
    int l = 0;
    if(path.compare("/")!=0){
       while(u<path.size()){
        if(path[u] == '/'){
            l = u+1;
        }
        u++;
    } 
    }
    else{
        return path;
    }
    return path.substr(l);
}

int main(){
    trees::Tree treeSO;
    Item * root = new Item("/");
    trees::TreeNode * r = new trees::TreeNode(root);
    treeSO.setRoot(r);
    // treeSO.insert("hola","/");
    // treeSO.insert("gr","hola");
    // std::cout<<treeSO.getUbicacion("gr")<<std::endl;
    std::cout<<"¡Bienvenido a TreeSO!"<<std::endl;
    std::cout<<"¡Autores: Cristobal Van Der Meer y Amparo Quiroz!"<<std::endl;
    std::string opcion1 = "";
    std::string opcion2 = "";
    trees::TreeNode * ubicacion = r;
    trees::TreeNode * ubica = r;
    while(opcion1.compare("exit")!=0){
        std::cout<<treeSO.getUbicacion(ubicacion);
        std::cin>>opcion1;
        if(opcion1.compare("cd")==0){
            std::cin>>opcion2;
            if(opcion2.compare("..")==0)
                ubicacion = ubicacion->getParent();
            else{
                ubica = treeSO.find(opcion2);
                if(((ubica->getData())->getTipo())==0)
                    std::cout<<"El archivo específicado no es una carpeta"<<std::endl;
                else
                    ubicacion = ubica;
            }
        }
        if(opcion1.compare("ls")==0){
            std::cin>>opcion2;
            opcion2 = filtrar_nombre(opcion2);
            if(opcion2.compare(".")!=0)
                ubica = treeSO.find(opcion2);
            if(((ubica->getData())->getTipo())==0)
                std::cout<<"El archivo específicado no es una carpeta"<<std::endl;
            else
                ubica->printChildren();
        }
        if(opcion1.compare("mkdir")==0){
            std::cin>>opcion2;
            Item * newItem = new Item(opcion2,1);
            trees::TreeNode * newNode = new trees::TreeNode(newItem);
            treeSO.insert(newNode,ubicacion);
        }
        if(opcion1.compare("mkfile")==0){
            std::cin>>opcion2;
            Item * newItem = new Item(opcion2,0);
            trees::TreeNode * newNode = new trees::TreeNode(newItem);
            treeSO.insert(ubicacion,newNode);
        }
        if(opcion1.compare("tree")==0){
            if(opcion2.compare(".")==0)
                treeSO.traverse(ubicacion);
            else
                ubica = treeSO.find(opcion2);
                treeSO.traverse(ubica);
        }
        if(opcion1.compare("rm")==0){
            ubica = treeSO.find(opcion2);
            //archivo
            if((ubica->getData())->getTipo()==0){
                delete ubica;
            }
            else{
                //ver como eliminar una carpeta y sus hijos
            }
        }
        if(opcion1.compare("find")==0){
            
        }
        // treeSO.traverse();
    } 
    return 0;
    //crear funcion delete en tree
    //anteponerse a que puede no encontrar la carpeta o archivo (en ese caso debe avisar no hacer segmentation fault)
}