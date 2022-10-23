#include "Item.hpp"

Item::Item(){
    nombre = "";
    tipo = -1;
}

Item::Item(std::string nombre){
    this->nombre = nombre;
    this->tipo = -1;
}

Item::Item(std::string nombre, int tipo){
    this->nombre = nombre;
    this->tipo = tipo;
}

void Item::setNombre(std::string nombre){
    this->nombre = nombre;
}

void Item::setTipo(int tipo){
    this->tipo = tipo;
}

std::string Item::getNombre(){
    return nombre;
}

int Item::getTipo(){
    return tipo;
}