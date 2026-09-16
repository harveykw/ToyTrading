#include <vector>
#include <utility>
#include <map>
#include <string>
#include <deque>

class MatchingEngine
{
    std::map<int, std::deque<std::pair<int, int>>> buyMap;
    std::map<int, std::deque<std::pair<int, int>>> sellMap;

public:
    std::vector<std::string> processOrders(const std::vector<std::string> &commands);

    void processBuy(int id, int price, int quantity);
    void processSell(int id, int price, int quantity);

    void update(std::vector<std::string> &outStream);
};