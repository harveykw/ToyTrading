#include "engine.hpp"
#include <sstream>

void MatchingEngine::processBuy(int id, int price, int quantity)
{
    this->buyMap[price].push_back({id, quantity});
}

void MatchingEngine::processSell(int id, int price, int quantity)
{
    this->sellMap[price].push_back({id, quantity});
}

void MatchingEngine::update(std::vector<std::string> &outStream)
{

    /*
        Matching priority is given to:

        1. People willing to sell the lowest
        2. People willing to buy the highest

    */

    auto itSell = this->sellMap.begin();
    auto itBuy = this->buyMap.rbegin();

    while (itSell != this->sellMap.end() && itBuy != this->buyMap.rend())
    {

        int sellPrice{itSell->first};
        std::deque<std::pair<int, int>> &sellData = itSell->second;

        int buyPrice{itBuy->first};
        std::deque<std::pair<int, int>> &buyData = itBuy->second;

        // Match not made: Lowest sell greater than greatest buy
        if (sellPrice > buyPrice)
            break;

        if (sellData.empty())
            ++itSell;

        if (buyData.empty())
            ++itBuy;

        // Match made, reduce the neccesary quantities

        while ((!sellData.empty() && !buyData.empty()))
        {
            auto [sellID, sellQuantity] = sellData.front();
            auto [buyID, buyQuantity] = buyData.front();

            if (sellQuantity == buyQuantity)
            {
                sellData.pop_front();
                buyData.pop_front();
            }

            if (sellQuantity > buyQuantity)
            {
                buyData.pop_front();
                sellData.front().second -= buyQuantity;
            }

            if (sellQuantity < buyQuantity)
            {
                sellData.pop_front();
                buyData.front().second -= sellQuantity;
            }

            outStream.push_back(
                "TRADE " + std::to_string(buyID) + ' ' + std::to_string(sellID) + ' ' + std::to_string((sellID < buyID) ? sellPrice : buyPrice) + ' ' + std::to_string(std::min(buyQuantity, sellQuantity)));
        }
    }
}

std::vector<std::string> MatchingEngine::processOrders(const std::vector<std::string> &commands)
{

    std::vector<std::string> outputStream{};

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
                processBuy(id, price, quantity);

            if (type == "SELL")
                processSell(id, price, quantity);

            update(outputStream);
        }

        if (parsedCommand.front() == "CANCEL")
        {
        }

        if (parsedCommand.front() == "QUERY")
        {
        }
    }

    return outputStream;
}
