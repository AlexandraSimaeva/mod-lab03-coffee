// Copyright 2025 AlexandraSimaeva
#include "Automata.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> menu = { "Hot chocolate", 
                                    "Berry tea", 
                                    "Ouloong tea", 
                                    "lavender coffee", 
                                    "Double Espresso", 
                                    "Americano" };
    std::vector<float> prices = { 3.0, 2.5, 3.0, 4.0, 4.5, 4.5 };
    Automata a1(menu, prices);
    std::cout << a1.on();
    a1.etMenu();
    a1.coin(5.0);
    a1.cancel();
    a1.coin(4.5);
    std::cout << a1.choice(3);
    std::cout << a1.getState() << std::endl;
    std::cout << a1.check() << std::endl;
    a1.cook();
    return 0;
}
 

 
