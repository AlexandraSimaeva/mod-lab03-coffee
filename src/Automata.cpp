// Copyright 2025 AlexandraSimaeva
#include "Automata.h"
Automata::Automata(std::vector<std::string> menu1, std::vector<float> prices1) {
    cash = 0;
    state = OFF;
    for (int i = 0; i < menu1.size(); i++) {
		menu.push_back(menu1[i]);
		prices.push_back(prices1[i]);
	}
	drink_num = -1;

}
std::string Automata::on() {
    if (state == OFF) {
        state = WAIT;
        return("Choose drink\n");
    } else {
        return("Operation rejected, machine isn't off\n");
    }
}
std::string Automata::off() {
    if (state == WAIT) {
	    state = OFF;
	    return("Coffee machine is off\n");
	} else {
	    return("Operation rejected, machine can't be off during making drink\n");
	}
}
void Automata::etMenu() {
    std::cout << "MENU\n";
    for (int i = 0; i < menu.size(); i++) {
        std::cout << menu[i] << " - " << prices[i] << "\n";
    } 
    std::cout << std::endl;
}
void Automata::coin(float money) {
    if (state == WAIT) {
        cash += money;
        state = ACCEPT;
        std::cout << "Got " << money << " dollars\n" << std::endl;
    } else if (state == ACCEPT) {
	cash += money;
	std::cout << "Got " << money << " dollars\n";
	std::cout << "Current sum " << cash << " dollars\n" << std::endl;
    } else {
	std::cout << "Operation rejected, get away your money\n" << std::endl;
    }
}
std::string Automata::getState() {
    switch (state) {
	case OFF:
	    return  "OFF";
	    break;
	case WAIT:
	    return  "WAIT";
	    break;
	case ACCEPT:
	    return  "ACCEPT";
	    break;
	case CHECK:
	    return  "CHECK";
	    break;
	case COOK:
	    return  "COOK";
	    break;
	default:
	    return  "UNKNOWN STATE";
	    break;
    }

}
int Automata::choice(int drink) {
    if (state == ACCEPT) {
	drink_num = drink;
	if (drink >= 0 && drink < menu.size()) {
	    std::cout << "\nYour drink is " << menu[drink] << "\nStart cooking?" << std::endl;
	    state = CHECK;
	    return 1;
	} else {
	    std::cout << "\nWrong index of drink" << std::endl;
			return -1;
	}
    } else {
	std::cout << "\nOperation rejected, You can't now choose drink\n";
	return -2;
    }
}
int Automata::check() {
    if (state == CHECK) {
	if (cash < prices[drink_num]) {
	    state = ACCEPT;
	    std::cout << "\nNot enough money" << std::endl;
	    return -1;
        } else {
	    state = COOK;
	    return 1;
        }
    } else {
	std::cout << "\nOperation rejected, pay for the drink" << std::endl;
	return -2;
    }

}
void Automata::cook() {
    if (state == COOK) {
	std::cout << "\nMaking " << menu[drink_num] << std::endl;
	finish();
    } else {
	std::cout << "\nOperation rejected" << std::endl;
    }
}
void Automata::cancel() {
    if (state == CHECK || state == ACCEPT) {
	state = WAIT;
	std::cout << "\nGet back money" << std::endl;
	cash = 0;
	drink_num = -1;
    } else {
	std::cout << "\nOperation rejected" << std::endl;
    }
}
void Automata::finish() {
    if (state == COOK) {
	std::cout << "\nYour drink is done\n";
	cash -= prices[drink_num];
	if (cash > 0) {
	    std::cout << "\nGet back change" << cash << " dollars" << std::endl;
	}
	cash = 0;
	drink_num = -1;
	state = WAIT;
    } else {
	std::cout << "\nCan't be finished" << std::endl;
    }
}
