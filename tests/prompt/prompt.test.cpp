#include <iostream>
#include <cassert>

int main() {
    int a = 5;
    int b = 6;
    assert(a == b && "a n'est pas égal à b");
    std::cout << "Tous les tests ont réussi !" << std::endl;
    return 0;
}