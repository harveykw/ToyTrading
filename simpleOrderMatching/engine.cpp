#include "engine.hpp"
#include <sstream>

std::vector<std::string> processOrders(const std::vector<std::string> &commands)
{

    for (const auto &command : commands)
    {
        // delimit
        std::vector<std::string> parsedCommand{};
        std::istringstream stream(command);
        std::string word;

        while (stream >> word)
        {
            parsedCommand.push_back(word);
        }

        if (parsedCommand.front() == "ADD")
        {

            std::string type = parsedCommand.at(2);
            int id = stoi(parsedCommand.at(1));
            int price = stoi(parsedCommand.at(3));
            int quantity = stoi(parsedCommand.at(4));

            if (type == "BUY")
            {
            }

            if (type == "SELL")
            {
            }
        }

        if (parsedCommand.front() == "CANCEL")
        {
        }

        if (parsedCommand.front() == "QUERY")
        {
        }
    }
}