#include <iostream>

template <class T>
class dynamicArray{
    T *_dynamic_array;
    int _array_size;
public:
    dynamicArray() = default;
    dynamicArray(int size);
    ~dynamicArray() {delete[] _dynamic_array; };
    T &operator[] (int index){ return _dynamic_array[index];};
    T findMax();
    void showArray();
    int getSize();
};

template <class T>
dynamicArray<T>::dynamicArray(int size) {
    _array_size = size;
    _dynamic_array = new T[_array_size];
}

template <class T>
T dynamicArray<T>::findMax() {
    T maxElem = _dynamic_array[0];
    for (int i = 0; i < _array_size-1 ; ++i) {
        if(maxElem < _dynamic_array[i+1]){
            maxElem = _dynamic_array [i+1];
        }
    }
    return maxElem;
}

template <class T>
void dynamicArray<T>::showArray() {
    std::cout << "ARRAY" << std::endl;
    for (int i = 0; i < _array_size; ++i) {
        std::cout << _dynamic_array[i] << " ";
    }
    std::cout << std::endl;
}

template <class T>
int dynamicArray<T>::getSize() {
    return this->_array_size;
}

int main() {
    dynamicArray<int> dym_array1{7};

    for (int i = 0; i < dym_array1.getSize(); ++i) {
        dym_array1[i] = i+10;
    }
    dym_array1.showArray();

    std::cout << "Max elem : " << dym_array1.findMax() << std::endl;

    dynamicArray<double> dym_array2{4};
    for (int k = 0; k < dym_array2.getSize(); ++k) {
        std::cout << "Enter a value: ";
        std::cin >> dym_array2[k];
    }
    dym_array2.showArray();

    std::cout << "Max elem : " << dym_array2.findMax() << std::endl;

    return 0;
}