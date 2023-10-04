#include <iostream>
#include <cassert>

int main() {
    // Test 1 : Vérifiez si l'addition de 2 et 3 est égale à 5
    assert(addition(2, 3) == 5);

    // Test 2 : Vérifiez si l'addition de -1 et 1 est égale à 0
    assert(addition(-1, 1) == 0);

    // Test 3 : Vérifiez si l'addition de 0 et 0 est égale à 0
    assert(addition(0, 0) == 0);

    std::cout << "Tous les tests ont réussi !" << std::endl;

    return 0;
}