
#include <string>
#include <iostream>

std::string filtrar_nombre(std::string path){
    int u = 0;
    int l = 0;
    while(u<path.size()){
        if(path[u] == '/'){
            l = u+1;
        }
        u++;
    }
    return path.substr(l);
}

int main(){
    std::string h;
    std::cin>>h;
    std::cout<<filtrar_nombre(h)<<std::endl;
    return 0;
}