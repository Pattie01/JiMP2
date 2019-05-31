#include <iostream>
#include <vector>
#include <complex>

using std::vector;
using std::complex;

template<typename T>
T Mean(vector<T> values){
    int size = values.size();
    //std::cout << "SIZE: " << size << std::endl;
    T sum{};
    for(auto elem:values){
        sum+=elem;
    }
    return sum/size;
}

int main() {
    vector<int> int_vec{1,45,4,7,6};
    vector<double> double_vec{3.5,2.4,7.4,1.1};
    vector <complex<int>> com_vec{(2,3),(4,1),(5,3)};

    std::cout << Mean(int_vec) << std::endl;
    std::cout << Mean(double_vec) << std::endl;
    std::cout << Mean(com_vec) << std::endl;
    return 0;
}