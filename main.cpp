#include <iostream>
#include <ostream>
#include <string>

int main()
{
    std::cout<< "Adınız Nedir? ";
    std::string str;
    std::getline(std::cin,str);
    std::cout<< "Selâmü Aleyküm "<< str<< '\n';
}

