#include "tree.hpp"
#include "treeList.hpp"
#include "treeListNode.hpp"
#include "treeNode.hpp"
#include <iostream>
#include <sstream>

int main(){
    trees::Tree treeSO;
    Item * root = new Item("/",1);
    trees::TreeNode * r = new trees::TreeNode(root);
    treeSO.setRoot(r);
    // treeSO.insert("hola","/");
    // treeSO.insert("gr","hola");
    // std::cout<<treeSO.getUbicacion("gr")<<std::endl;
    std::cout<<"¡Bienvenido a TreeSO!"<<std::endl;
    std::cout<<"¡Autores: Cristobal Van Der Meer y Amparo Quiroz!"<<std::endl;
    std::string opcion1 = "";
    std::string opcion2 = "";
    std::string opcion3 = "";
    trees::TreeNode * ubicacion = r;
    trees::TreeNode * ubicacion2;
    trees::TreeNode * ubica = r;
    bool instruccion_valida = true;
    while(opcion1.compare("exit")!=0){
        std::cout<<treeSO.getUbicacion(ubicacion);
        std::cin>>opcion1;
        if(opcion1.compare("cd")==0){
            std::cin>>opcion2;
            if(opcion2.compare("..")==0){
                if(ubicacion->getParent()!=nullptr){
                    ubicacion = ubicacion->getParent();
                }
                else{
                    std::cout<<"La carpeta especificada / es la última y, por tanto, no se puede ir más atrás"<<std::endl;
                }
            }
            else{
                if(opcion2.compare(".")!=0){
                    ubica = treeSO.find_path(opcion2);
                    if(ubica!=nullptr){
                        if(((ubica->getData())->getTipo())==0)
                            std::cout<<"El archivo específicado no es una carpeta"<<std::endl;
                        else
                            ubicacion = ubica;
                    }
                    else
                        std::cout<<"No existe la carpeta especificada"<<std::endl;
                }
            }
        }
        if(opcion1.compare("ls")==0){
            std::cin>>opcion2;
            if(opcion2.compare(".")!=0){
                if(opcion2.compare("..")!=0)
                    ubica = treeSO.find_path(opcion2);
                else
                    ubica = ubica->getParent();
            }
            else
                ubica = ubicacion;
            if(ubica!=nullptr){
                if(((ubica->getData())->getTipo())==0)
                    std::cout<<"El archivo específicado no es una carpeta"<<std::endl;
                else
                    ubica->printChildren();
            }
            else
                std::cout<<"No existe la carpeta especificada"<<std::endl;
        }
        if(opcion1.compare("mkdir")==0){
            std::cin>>opcion2;
            Item * newItem = new Item(opcion2,1);
            trees::TreeNode * newNode = new trees::TreeNode(newItem);
            treeSO.insert(newNode,ubicacion);
        }
        if(opcion1.compare("mkfile")==0){
            std::cin>>opcion2;
            std::cin>>opcion3;
            if(opcion2.compare(".")==0){
                Item * newItem = new Item(opcion3,0);
                trees::TreeNode * newNode = new trees::TreeNode(newItem);
                if((ubicacion->getData())->getTipo() != 0)
                    treeSO.insert(newNode,ubicacion);
                else
                    std::cout<<"No se puede crear un archivo dentro de otro archivo"<<std::endl;
            }
            if(opcion2.compare("..")==0){
                if(ubicacion->getParent()!=nullptr){
                    Item * newItem = new Item(opcion3,0);
                    trees::TreeNode * newNode = new trees::TreeNode(newItem);
                    if(((ubicacion->getParent())->getData())->getTipo() != 0)
                        treeSO.insert(newNode,ubicacion->getParent());
                    else
                        std::cout<<"No se puede crear un archivo dentro de otro archivo"<<std::endl;
                }
                else
                    std::cout<<"La carpeta especificada / es la última y, por tanto, no se puede ir más atrás"<<std::endl;
            }
            if(opcion2.compare(".")!=0 && opcion2.compare("..")!=0)
            {    
                ubica = treeSO.find_path(opcion2);
                std::cout<<ubica->getData()->getNombre()<<std::endl;
                if(ubica!= nullptr){
                    Item * newItem = new Item(opcion3,0);
                    trees::TreeNode * newNode = new trees::TreeNode(newItem);
                    if((ubica->getData())->getTipo() != 0)
                        treeSO.insert(newNode,ubica);
                    else
                        std::cout<<"No se puede crear un archivo dentro de otro archivo"<<std::endl;
                }
                else
                    std::cout<<"No existe la carpeta específicada"<<std::endl;
            }
        }
        if(opcion1.compare("tree")==0){
            std::cin>>opcion2;
            if(opcion2.compare(".")==0){
                if((ubicacion->getData())->getTipo()!=0)
                    treeSO.traverse(ubicacion);
                else
                    std::cout<<"El nombre seleccionado es un archivo"<<std::endl;
            }
            if(opcion2.compare("..")==0){
                if(ubicacion->getParent()!=nullptr)
                    treeSO.traverse(ubicacion->getParent());
                else
                    std::cout<<"La carpeta especificada / es la última y, por tanto, no se puede ir más atrás"<<std::endl;
            }
            if(opcion2.compare(".")!=0 && opcion2.compare("..")!=0){
                ubica = treeSO.find_path(opcion2);
                if(ubica!=nullptr){
                    if((ubica->getData())->getTipo()!=0)
                        treeSO.traverse(ubica);
                    else
                        std::cout<<"El nombre seleccionado es un archivo"<<std::endl;
                }
                else
                    std::cout<<"No existe la carpeta/archivo especificado"<<std::endl;
            }
        }
        if(opcion1.compare("rm")==0){
            std::cin>>opcion2;
            if (opcion2.compare("/") != 0){
                if(opcion2.compare(".")==0){
                    ubica = ubicacion;
                    ubicacion = ubicacion->getParent();
                }
                if(opcion2.compare("..")==0){
                    if (ubicacion->getParent() != nullptr){
                        ubica = ubicacion->getParent();
                        if (ubica->getParent() != nullptr)
                            ubicacion = ubica->getParent();
                        else
                            std::cout<<"La carpeta que se intentó borrar es la principal, esta acción no está permitida"<<std::endl;
                    }
                    else
                        std::cout<<"La carpeta que se intentó borrar es la principal, esta acción no está permitida"<<std::endl;
                }
                if(opcion2.compare(".")!=0 && opcion2.compare("..")!=0)
                    ubica = treeSO.find_path(opcion2);
                if (ubica != nullptr){
                //archivo
                    if((ubica->getData())->getTipo()==0){
                        ((ubica->getParent())->getChildren())->remove(ubica);
                    }
                    else{
                        ubicacion2 = ubicacion;
                        ubicacion = r;
                        treeSO.delete_item(ubica);
                        if(treeSO.find_path((ubicacion2->getData())->getNombre()) == nullptr || ubicacion2 == ubica){
                            ubicacion = ubica->getParent();
                        }
                        else{
                            ubicacion = ubicacion2;
                        }
                        ((ubica->getParent())->getChildren())->remove(ubica);
                    }
                }
                else
                    std::cout<<"No se encontró la carpeta/archivo especificado"<<std::endl;
            }
            else
                std::cout<<"La carpeta que se intentó borrar es la principal, esta acción no está permitida"<<std::endl;
        }
        if(opcion1.compare("find")==0){
            std::cin>>opcion2;
            std::cin>>opcion3;
            if((opcion2.compare("."))==0){
                treeSO.find_nombre(((ubicacion->getData())->getNombre()),opcion3);
            }
            if((opcion2.compare(".."))==0){
                if(ubicacion->getParent() != nullptr)
                    treeSO.find_nombre((((ubicacion->getParent())->getData())->getNombre()),opcion3);
                else
                    std::cout<<"La carpeta especificada / es la última y, por tanto, no se puede ir más atrás"<<std::endl;
            }
            if(opcion2.compare(".")!=0 && opcion2.compare("..")!=0)
                treeSO.find_nombre(opcion2,opcion3);
        }
        if(opcion1.compare("cd")!=0 && opcion1.compare("ls")!=0 && opcion1.compare("mkdir")!=0 && opcion1.compare("mkfile")!=0 && opcion1.compare("tree")!=0 && opcion1.compare("rm")!=0 && opcion1.compare("find")!=0 && opcion1.compare("exit")!=0){
            std::cout<<"Esa función no existe"<<std::endl;
        }
    } 
    return 0;
    //crear funcion delete en tree
    //deja de imprimir toda las direcciones de antes
}