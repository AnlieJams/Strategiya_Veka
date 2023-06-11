#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SortStrategy {

public:
    virtual void sort(std::vector<int>& arr) = 0;
};


class AscendingSortStrategy : public SortStrategy {
public:
    void sort(std::vector<int>& arr) override {
        std::sort(arr.begin(), arr.end());
    }
};


class DescendingSortStrategy : public SortStrategy {
public:
    void sort(std::vector<int>& arr) override {
        std::sort(arr.begin(), arr.end(), std::greater<int>());
    }
};


class SortContext {
private:
    SortStrategy* strategy;

public:
    SortContext(SortStrategy* strategy) : strategy(strategy) {}

    void setStrategy(SortStrategy* newStrategy) {
        strategy = newStrategy;
    }

    void performSort(std::vector<int>& arr) {
        strategy->sort(arr);
    }
};

int main() {
    setlocale(0, "");

    vector<int> numbers = { 7, 2, 5, 1, 666 };

   
    AscendingSortStrategy ascendingStrategy;
    DescendingSortStrategy descendingStrategy;

    
    SortContext ascendingContext(&ascendingStrategy);
    SortContext descendingContext(&descendingStrategy);

    
    ascendingContext.performSort(numbers);
    cout << "Сортировка по возрастанию: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Сортируем числа по убыванию
    descendingContext.performSort(numbers);
    cout << "Сортировка по убыванию: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
