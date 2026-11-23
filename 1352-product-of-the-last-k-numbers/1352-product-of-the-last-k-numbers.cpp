class ProductOfNumbers {
public:
    vector<int> number;
    ProductOfNumbers() {
        
    }
    void add(int num) {
        number.push_back(num);
    }
    int getProduct(int k) {
        int accu = accumulate(number.begin() + (number.size() - k), number.end(), 1, multiplies<int>());
        return accu;
    }
};
