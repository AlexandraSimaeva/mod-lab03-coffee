#include <iostream>
#include <vector>
#include <string>
class Automata
{
private:
	enum STATES { OFF, WAIT, ACCEPT, COOK, CHECK };
	float cash;
	std::vector<std::string> menu;
	std::vector<float> prices;
	STATES state;
	int drink_num;

public:
	Automata(std::vector<std::string> menu, std::vector<float> prices);
	std::string on();
	std::string off();
	void coin(float money);
	void etMenu();
	std::string getState();
	int choice(int drink);
	int check();
	void cancel();
	void cook();
	void finish();
};
 
