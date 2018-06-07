#include <iostream>
#include <core/Scope.hxx>

int main(int, char**) {
    core::Scopes scope = core::Scopes::literal;
    
    std::cout << "Hello, world!" << std::endl;

    return 0;
}
