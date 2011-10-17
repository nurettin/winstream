#include <iostream>
#include <string>

int main()
{
    std::cout<< "Adınız Nedir? ";
    std::string ad;
    std::getline(std::cin, ad);
    std::cout<< "Merhaba "<< ad<< '\n';
    return 0;
}

