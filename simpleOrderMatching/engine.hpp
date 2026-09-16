#include <vector>
#include <utility>
#include <map>
#include <string>

class MatchingEngine
{
    std::map<int, std::vector<std::pair<int, int>>> buyMap;
    std::map<int, std::vector<std::pair<int, int>>> sellMap;

    std::vector<std::string> processOrders(const std::vector<std::string> &commands);

    void processBuy(int id, int price, int quantity, std::vector<std::string> &outStream);
    void processSell(int id, int price, int quantity, std::vector<std::string> &outStream);
};