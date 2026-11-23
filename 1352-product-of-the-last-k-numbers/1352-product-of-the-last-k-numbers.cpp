class ProductOfNumbers {
public:
    vector<int> number;
    int n;
    ProductOfNumbers() {
        number.clear();
        n = 0;
    }
    void add(int num) {
        number.push_back(num);
    }
    int getProduct(int k) {
        int prod = 1;
        int n = number.size();
        for(int i = n-k; i<n; i++){
            prod *= number[i];
        }
        return prod;
    }
};

// Brute force : 
// class ProductOfNumbers {
// public:
//     vector<int> number;
//     ProductOfNumbers() {
        
//     }
//     void add(int num) {
//         number.push_back(num);
//     }
//     int getProduct(int k) {
//         int accu = accumulate(number.begin() + (number.size() - k), number.end(), 1, multiplies<int>());
//         return accu;
//     }
// };
