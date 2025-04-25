// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"
#include <string>
#include <vector>
TEST(Case1, TestOFF) {
    std::string state = "OFF";
    std::vector<std::string>  menu { "Hot chocolate", 
                                     "Berry tea",
                                     "Ouloong tea",
                                     "lavender coffee",
                                     "Double Espresso",
                                     "Americano" };
    std::vector<float>price { 3.0, 2.5, 3.0, 4.0, 4.5, 4.5 };
    Automata a1(menu, price);
    EXPECT_EQ(a1.getState(), state);
}
TEST(Case2, TestWAIT_1) {
    std::string state = "WAIT";
    std::vector<std::string>  menu{ "Hot chocolate",
                                    "Berry tea",
                                    "Ouloong tea",
                                    "lavender coffee",
                                    "Double Espresso",
                                    "Americano" };
    std::vector<float>price{ 3.0, 2.5, 3.0, 4.0, 4.5, 4.5 };


    Automata a1(menu, price);
    a1.on();
    a1.coin(5.0);
    a1.cancel();
    EXPECT_EQ(a1.getState(), state);
}
TEST(Case2, TestWAIT_2) {
    std::string state = "WAIT";
    std::vector<std::string>  menu{ "Hot chocolate",
                                    "Berry tea",
                                    "Ouloong tea",
                                    "lavender coffee",
                                    "Double Espresso",
                                    "Americano" };
    std::vector<float>price{ 3.0, 2.5, 3.0, 4.0, 4.5, 4.5 };

    Automata a1(menu, price);
    a1.on();
    a1.coin(5.0);
    a1.choice(4);
    a1.check();
    a1.cook();
    EXPECT_EQ(a1.getState(), state);
}
TEST(Case2, TestWAIT_3) {
    std::string state = "WAIT";
    std::vector<std::string>  menu{ "Hot chocolate",
                                    "Berry tea",
                                    "Ouloong tea",
                                    "lavender coffee",
                                    "Double Espresso",
                                    "Americano" };
    std::vector<float>price{ 3.0, 2.5, 3.0, 4.0, 4.5, 4.5 };

    Automata a1(menu, price);
    a1.on();
    a1.coin(5.0);
    a1.choice(4);
    a1.cancel();
    EXPECT_EQ(a1.getState(), state);
}
TEST(Case2, TestWAIT_4) {
    std::string state = "WAIT";
    std::vector<std::string>  menu{ "Hot chocolate",
                                    "Berry tea",
                                    "Ouloong tea",
                                    "lavender coffee",
                                    "Double Espresso",
                                    "Americano" };
    std::vector<float>price{ 3.0, 2.5, 3.0, 4.0, 4.5, 4.5 };

    Automata a1(menu, price);
    a1.on();
    a1.cook();

    EXPECT_EQ(a1.getState(), state);
}
TEST(Case3, TestACCEPT_1) {
    std::string state = "ACCEPT";
    std::vector<std::string>  menu{ "Hot chocolate",
                                    "Berry tea",
                                    "Ouloong tea",
                                    "lavender coffee",
                                    "Double Espresso",
                                    "Americano" };
    std::vector<float>price{ 3.0, 2.5, 3.0, 4.0, 4.5, 4.5 };

    Automata a1(menu, price);
    a1.on();
    a1.coin(1.0);
    a1.choice(4);
    a1.check();
    EXPECT_EQ(a1.getState(), state);
}
TEST(Case3, TestACCEPT_2) {
    std::string state = "ACCEPT";
    std::vector<std::string>  menu{ "Hot chocolate",
                                    "Berry tea",
                                    "Ouloong tea",
                                    "lavender coffee",
                                    "Double Espresso",
                                    "Americano" };
    std::vector<float>price{ 3.0, 2.5, 3.0, 4.0, 4.5, 4.5 };

    Automata a1(menu, price);
    a1.on();
    a1.coin(1.0);
    a1.coin(4.5);
    a1.choice(8);

    EXPECT_EQ(a1.getState(), state);
}
TEST(Case3, TestACCEPT_3) {
    std::string state = "ACCEPT";
    std::vector<std::string>  menu{ "Hot chocolate",
                                    "Berry tea",
                                    "Ouloong tea",
                                    "lavender coffee",
                                    "Double Espresso",
                                    "Americano" };
    std::vector<float>price{ 3.0, 2.5, 3.0, 4.0, 4.5, 4.5 };

    Automata a1(menu, price);
    a1.on();
    a1.coin(1.0);
    a1.coin(4.5);
    a1.cook();
    EXPECT_EQ(a1.getState(), state);
}
TEST(Case4, TestCOOK_1) {
    std::string state = "COOK";
    std::vector<std::string>  menu{ "Hot chocolate",
                                    "Berry tea",
                                    "Ouloong tea",
                                    "lavender coffee",
                                    "Double Espresso",
                                    "Americano" };
    std::vector<float>price{ 3.0, 2.5, 3.0, 4.0, 4.5, 4.5 };

    Automata a1(menu, price);
    a1.on();
    a1.coin(4.5);
    a1.choice(5);
    a1.check();


    EXPECT_EQ(a1.getState(), state);
}
TEST(Case4, TestCOOK_2) {
    std::string state = "COOK";
    std::vector<std::string>  menu{ "Hot chocolate",
                                    "Berry tea",
                                    "Ouloong tea",
                                    "lavender coffee",
                                    "Double Espresso",
                                    "Americano" };
    std::vector<float>price{ 3.0, 2.5, 3.0, 4.0, 4.5, 4.5 };

    Automata a1(menu, price);
    a1.on();
    a1.coin(4.5);
    a1.choice(5);
    a1.check();
    a1.cancel();


    EXPECT_EQ(a1.getState(), state);
}
TEST(Case5, TestCHECK_1) {
    std::string state = "CHECK";
    std::vector<std::string>  menu{ "Hot chocolate",
                                    "Berry tea",
                                    "Ouloong tea",
                                    "lavender coffee",
                                    "Double Espresso",
                                    "Americano" };
    std::vector<float>price{ 3.0, 2.5, 3.0, 4.0, 4.5, 4.5 };

    Automata a1(menu, price);
    a1.on();
    a1.coin(4.5);
    a1.choice(5);

    EXPECT_EQ(a1.getState(), state);
}
TEST(Case5, TestCHECK_2) {
    std::string state = "CHECK";
    std::vector<std::string>  menu{ "Hot chocolate",
                                    "Berry tea",
                                    "Ouloong tea",
                                    "lavender coffee",
                                    "Double Espresso",
                                    "Americano" };
    std::vector<float>price{ 3.0, 2.5, 3.0, 4.0, 4.5, 4.5 };

    Automata a1(menu, price);
    a1.on();
    a1.coin(4.5);
    a1.choice(5);
    a1.off();

    EXPECT_EQ(a1.getState(), state);
}
