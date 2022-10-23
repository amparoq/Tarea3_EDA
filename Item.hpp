#include <string>

class Item{
    private:
        std::string nombre;
        int tipo;
    public:
        Item();
        Item(std::string nombre);
        Item(std::string nombre,int tipo);
        void setNombre(std::string nombre);
        void setTipo(int tipo);
        std::string getNombre();
        int getTipo();
};