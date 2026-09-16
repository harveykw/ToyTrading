
#include "engine.cpp"
#include <iostream>

int main(int argc, char *argv[])
{

    MatchingEngine engine{};

    std::vector<std::string> test{
        "ADD 1 BUY 100 10",
        "ADD 2 BUY 101 5",
        "ADD 3 SELL 100 8"};

    std::vector<std::string> results = engine.processOrders(test);

    for (const auto &line : results)
    {
        std::cout << line << '\n';
    }

    return 0;
}