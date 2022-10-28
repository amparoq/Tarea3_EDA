#include "iostream"
#include "split.hpp"

// cuenta la cantidad de veces que el string sep aparece en input

int count_string(std::string input, std::string sep) {
  int count = 0;

  for (int i = 0; i < input.size(); i++){
    if (input.substr(i, sep.size()) == sep) count++;
  	}
  return count;
}


// realiza un split del string input de acuerdo al separador sep y devuelve 
// el substring correspondiente a la posición pos

std::string split(std::string input, std::string sep, int pos){

	if (pos > count_string(input, sep) || pos < 0){
		throw std::invalid_argument("position out of range");
	}

	std::string output = "";
	std::string resto = input;

	int i = 0;
	int size = -1;

	while(i < pos + 1){
		resto = resto.substr(size + 1);
		int aux = resto.find_first_of(sep);
		size = (aux == -1) ? resto.size(): aux ;
		output = resto.substr(0, size);
		i++;
	}
	return output;
}

// int main(int nargs, char** vargs){

//     std::string input = "/tmb/folder1/folder2";
//     std::cout << "input: " + input << std::endl; 

//     for(int i = 0; i < 4 ; i++){
//         std::string substring = split(input, "/", i);
//         std::cout << "pos " + std::to_string(i) + ": " + substring << std::endl;
//     }

//     // este debería mostrar un error

//     split(input, "/", 4);


//     return 0;
// }