#include <iostream>
#include <queue>
#include <vector>

enum class OrderType {
    BID,
    ASK
};

struct Order {
    int id;
    double price;
    OrderType orderType;
};

class OrderBook {
private:
    std::priority_queue<std::pair<double, int>> bidPrices;
    std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>> askPrices;

public:
    void submit(Order order) {
        if (order.orderType == OrderType::BID) {
            bidPrices.push({order.price, order.id});
        } else if (order.orderType == OrderType::ASK) {
            askPrices.push({order.price, order.id});
        }
    }

    double getBestBid() const {
        return !bidPrices.empty() ? bidPrices.top().first : -1;
    }
    double getBestAsk() const {
        return !askPrices.empty() ? askPrices.top().first : -1;
    }
};

int main() {
    OrderBook orderBook;

    Order order1 = {
        .id = 123,
        .price = 200.3,
        .orderType = OrderType::BID
    };
    Order order2 = {
        .id = 123,
        .price = 210.3,
        .orderType = OrderType::BID
    };
    Order order3 = {
        .id = 123,
        .price = 110.3,
        .orderType = OrderType::BID
    };

    orderBook.submit(order1);
    orderBook.submit(order2);
    orderBook.submit(order3);
    Order order4 = {
        .id = 123,
        .price = 200.3,
        .orderType = OrderType::ASK
    };
    Order order5 = {
        .id = 123,
        .price = 210.3,
        .orderType = OrderType::ASK
    };
    Order order6 = {
        .id = 123,
        .price = 110.3,
        .orderType = OrderType::ASK
    };
    orderBook.submit(order4);
    orderBook.submit(order5);
    orderBook.submit(order6);

    std::cout << orderBook.getBestBid() << std::endl;
    std::cout << orderBook.getBestAsk() << std::endl;
}
