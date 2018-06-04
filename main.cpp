#include <iostream>
#include <core/Scope.hxx>

int main(int, char**) {
    core::ScopeCardinal scope = ScopeCardinal::literal_;
    
    std::cout << "Hello, world!" << std::endl;

    return 0;
}
