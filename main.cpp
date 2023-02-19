#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>

// Использовался код с лекции
template <class ValueType>
class Heap {
private:
    std::vector<ValueType> vec_;

public:
    Heap() {
        vec_ = std::vector<ValueType>();
    }

    template <class Iterator>
    Heap(Iterator begin, Iterator end) {
        for (Iterator it = begin; it != end; ++it) {
            insert(*it);
        }
    }

    Heap(std::initializer_list<ValueType> lst) {
        for (const auto &val : lst) {
            insert(val);
        }
    }

    Heap(const Heap &other) {
        vec_ = std::vector<ValueType>(other.vec_);
    }

    Heap &operator=(const Heap &other) {
        if (this == &other) {
            return *this;
        }
        vec_ = std::vector<ValueType>(other.vec_);
        return *this;
    }

    Heap(Heap &&other) {
        this->vec_ = std::move(other.vec_);
    }
    Heap &operator=(Heap &&other) {
        if (this == &other) {
            return *this;
        }
        this->vec_ = std::move(other.vec_);
        return *this;
    }

    ~Heap() {
        vec_.clear();
    }

    size_t size() const {
        return vec_.size();
    }
    bool empty() const {
        return vec_.empty();
    }

    void insert(const ValueType &elem) {
        vec_.push_back(elem);
        int i = size() - 1;
        int parent = (i - 1) / 2;
        while (i > 0 && vec_[parent] > vec_[i]) {
            ValueType t = vec_[i];
            vec_[i] = vec_[parent];
            vec_[parent] = t;
            i = parent;
            parent = (i - 1) / 2;
        }
    }

    ValueType extract() {
        ValueType result = vec_[0];
        vec_[0] = vec_[size() - 1];
        vec_.pop_back();
        heapify(0);
        return result;
    }

    void heapify(int i) {
        int left_child;
        int right_child;
        int largest_child;
        for (;;) {
            left_child = 2 * i + 1;
            right_child = 2 * i + 2;
            largest_child = i;
            if (left_child < size() && vec_[largest_child] > vec_[left_child]) {
                largest_child = left_child;
            }
            if (right_child < size() && vec_[largest_child] > vec_[right_child]) {
                largest_child = right_child;
            }
            if (largest_child == i) {
                break;
            }
            ValueType temp = vec_[i];
            vec_[i] = vec_[largest_child];
            vec_[largest_child] = temp;
            i = largest_child;
        }
    }
};

class SpecialVector {
public:
    int size;
    std::vector<int> vec;
    SpecialVector(int s) {
        size = s;
    }

    void run(int i) {
        if (i == 1) {
            smallNumbers();
        } else if (i == 2) {
            bigNumbers();
        } else if (i == 4) {
            almostSorted();
        } else {
            cursed();
        }
    }

    void smallNumbers() {
        srand(time(nullptr));
        vec = std::vector<int>(size);
        for (int i = 0; i < size; ++i) {
            vec[i] = rand() % 6;
        }
    }

    void bigNumbers() {
        srand(time(nullptr));
        vec = std::vector<int>(size);
        for (int i = 0; i < size; ++i) {
            vec[i] = rand() % 4001;
        }
    }

    void almostSorted() {
        vec = std::vector<int>(size);
        for (int i = 0; i < size; ++i) {
            vec[i] = i;
        }
        for (int i = 0; i < size; i += 40) {
            vec[i] += 2;
        }
    }

    void cursed() {
        vec = std::vector<int>(size);
        for (int i = size; i != 0;) {
            vec[i] = size - i--;
        }
    }

    void print(int len) {
        if (len > size) {
            len = size;
        }
        for (int i = 0; i < len; ++i) {
            std::cout << vec[i] << " ";
            if (!(i % 40)) {
                std::cout << std::endl;
            }
        }
    }

    void print() {
        for (int i = 0; i < size; ++i) {
            std::cout << vec[i] << " ";
        }
    }
};

class Sort {
public:
    std::string type;
    int t;

    void setType(int i) {
        switch (i) {
            case 0:
                type = "selectionSort";
                break;
            case 1:
                type = "bubbleSort";
                break;
            case 2:
                type = "iverson1Sort";
                break;
            case 3:
                type = "iverson12Sort";
                break;
            case 4:
                type = "insertionSort";
                break;
            case 5:
                type = "binaryInsertionSort";
                break;
            case 6:
                type = "countSort";
                break;
            case 7:
                type = "radixSort";
                break;
            case 8:
                type = "mergeSort";
                break;
            case 9:
                type = "quickSort";
                break;
            case 10:
                type = "heapSort";
                break;
            case 11:
                type = "shellSortCiura";
                break;
            case 12:
                type = "shellSortShell";
                break;
        }
    }

    void run(int i, std::vector<int> vec) {
        switch (i) {
            case 0:
                selectionSort(vec);
                break;
            case 1:
                bubbleSort(vec);
                break;
            case 2:
                iverson1Sort(vec);
                break;
            case 3:
                iverson12Sort(vec);
                break;
            case 4:
                insertionSort(vec);
                break;
            case 5:
                binaryInsertionSort(vec);
                break;
            case 6:
                countSort(vec);
                break;
            case 7:
                radixSort(vec);
                break;
            case 8:
                mergeSort(vec);
                break;
            case 9:
                quickSort(vec);
                break;
            case 10:
                heapSort(vec);
                break;
            case 11:
                shellSortCiura(vec);
                break;
            case 12:
                shellSortShell(vec);
                break;
        }
    }

    void bubbleSort(std::vector<int> &vector) {
        for (int i = 0; i < vector.size(); i++) {
            for (int j = 0; j < vector.size() - 1; j++) {
                // Обмениваем элементы местами, если они не упорядочены
                if (vector[j] > vector[j + 1]) {
                    std::swap(vector[j], vector[j + 1]);
                }
            }
        }
    }

    void selectionSort(std::vector<int> &vector) {
        for (int i = 0; i < vector.size(); i++) {
            int min = i;
            for (int j = i + 1; j < vector.size(); j++) {
                // Ищем минимальный элемент в оставшейся части массива
                if (vector[j] < vector[min]) {
                    min = j;
                }
            }
            // "Опускаем" найденный минимальный элемент на текущую позицию
            std::swap(vector[i], vector[min]);
        }
    }

    void insertionSort(std::vector<int> &vector) {
        for (int i = 1; i < vector.size(); i++) {
            int j = i;
            // Опускаем новый элемент на нужную позицию в отсортированной части массива
            while (j > 0 && vector[j] < vector[j - 1]) {
                std::swap(vector[j], vector[j - 1]);
                j--;
            }
        }
    }

    void mergeSort(std::vector<int> &vector) {
        if (vector.size() <= 1) {
            return;
        }
        // Определяем середину массива
        int mid = vector.size() / 2;
        std::vector<int> left(vector.begin(), vector.begin() + mid);
        std::vector<int> right(vector.begin() + mid, vector.end());
        // Сортируем обе половины рекурсивно
        mergeSort(left);
        mergeSort(right);
        int i = 0, j = 0, k = 0;
        while (i < left.size() && j < right.size()) {
            // Берем меньший из двух передних элементов в отсортированных половинах
            // и помещаем его в результирующий массив
            if (left[i] < right[j]) {
                vector[k] = left[i];
                i++;
            } else {
                vector[k] = right[j];
                j++;
            }
            k++;
        }

        // Если в половинах остались элементы, то добавляем их в результирующий массив
        while (i < left.size()) {
            vector[k] = left[i];
            i++;
            k++;
        }
        while (j < right.size()) {
            vector[k] = right[j];
            j++;
            k++;
        }
    }

    void quickSort(std::vector<int> &vector) {
        // Вызываем добавочную функцию от границ исходного массива
        quickSortHelper(vector, 0, vector.size() - 1);
    }

    void quickSortHelper(std::vector<int> &vector, int left, int right) {
        if (left < right) {
            // Выбираем опорный элемент и рекурсивно сортируем
            // элементы слева и справа от него
            int pivot = quickSortPartitionHelper(vector, left, right);
            quickSortHelper(vector, left, pivot - 1);
            quickSortHelper(vector, pivot + 1, right);
        }
    }

    int quickSortPartitionHelper(std::vector<int> &vector, int left, int right) {
        int i = left, j = right;
        // Выбираем левый элемент в качестве опорного
        int pivot = vector[left];
        while (i < j) {
            // Ищем элемент, больший опорного
            while (pivot >= vector[i]) {
                i++;
            }
            // Ищем элемент, меньший или равный опорному
            while (pivot < vector[j]) {
                j--;
            }
            // Меняем их местами
            if (i < j) {
                std::swap(vector[i], vector[j]);
            }
        }
        // Меняем опорный элемент с элементом, на котором остановились
        std::swap(vector[left], vector[j]);
        return j;
    }

    void binaryInsertionSort(std::vector<int> &vector) {
        for (int i = 1; i < vector.size(); i++) {
            // Ищем место для вставки элемента с помощью бинарного поиска
            int left = 0, right = i - 1, mid;
            while (left <= right) {
                mid = (left + right) / 2;
                if (vector[i] < vector[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // Вставляем элемент в найденное место
            int temp = vector[i];
            for (int j = i; j > left; j--) {
                vector[j] = vector[j - 1];
            }
            vector[left] = temp;
        }
    }

    void heapSort(std::vector<int> &vector) {
        // Создаем кучу из исходного массива
        Heap<int> heap(vector.begin(), vector.end());
        // Извлекаем элементы из кучи
        for (int i = 0; i < vector.size(); ++i) {
            vector[i] = heap.extract();
        }
    }

    void radixSort(std::vector<int> &vector) {
        int max_elem = vector[0];
        // Находим максимальный элемент
        for (int i = 1; i < vector.size(); i++) {
            if (vector[i] > max_elem) {
                max_elem = vector[i];
            }
        }
        // Вызываем сортировку подсчетом для каждого разряда
        for (int radix = 1; max_elem / radix > 0; radix *= 256) {
            radixSortCountHelper(vector, radix);
        }
    }

    void radixSortCountHelper(std::vector<int> &vector, int radix) {
        std::vector<int> output(vector.size());
        std::vector<int> count(256);
        // Заполняем массив подсчетов нулями
        for (int i = 0; i < 256; ++i) {
            count[i] = 0;
        }
        // Выполняем подсчет количества элементов
        for (int i = 0; i < vector.size(); ++i) {
            ++count[(vector[i] / radix) % 256];
        }
        // Аккумулируем сумму
        for (int i = 1; i < 256; ++i) {
            count[i] += count[i - 1];
        }
        // Заполняем выходной массив
        for (int i = vector.size() - 1; i >= 0; --i) {
            output[count[(vector[i] / radix) % 256] - 1] = vector[i];
            --count[(vector[i] / radix) % 256];
        }

        for (int i = 0; i < vector.size(); ++i) {
            vector[i] = output[i];
        }
    }

    void countSort(std::vector<int> &v) {
        int max_elem = v[0];
        for (int i = 1; i < v.size(); ++i) {
            if (v[i] > max_elem) {
                max_elem = v[i];
            }
        }
        // count[i] - количество вхождений i в исходный массив
        std::vector<int> count(max_elem + 1, 0);
        for (int i = 0; i < v.size(); ++i) {
            ++count[v[i]];
        }
        // Заполняем выходной массив
        int ind = 0;
        for (int i = 0; i < max_elem + 1; ++i) {
            for (int j = 0; j < count[i]; ++j) {
                v[ind++] = i;
            }
        }
    }

    void shellSortCiura(std::vector<int> &vector) {
        // Последовательность Циура
        std::vector<int> gaps = {701, 301, 132, 57, 23, 10, 4, 1};
        for (const int &gap : gaps) {
            for (int i = gap; i < vector.size(); ++i) {
                // Запоминаем текущий элемент
                int temp = vector[i];
                int j = i;
                // Выполняем сортировку вставками
                while (j >= gap && vector[j - gap] > temp) {
                    vector[j] = vector[j - gap];
                    j -= gap;
                }
                // Приравниваем j-й элемент к запомненному
                vector[j] = temp;
            }
        }
    }

    void shellSortShell(std::vector<int> &vector) {
        // Последовательность Шелла
        for (int gap = vector.size() / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < vector.size(); ++i) {
                // Запоминаем текущий элемент
                int temp = vector[i];
                int j = i;
                // Выполняем сортировку вставками
                while (j >= gap && vector[j - gap] > temp) {
                    vector[j] = vector[j - gap];
                    j -= gap;
                }
                // Приравниваем j-й элемент к запомненному
                vector[j] = temp;
            }
        }
    }

    void iverson1Sort(std::vector<int> &vector) {
        for (int i = 0; i < vector.size(); i++) {
            // Подсчитываем количество обменов
            int swaps = 0;
            for (int j = 0; j < vector.size() - 1; j++) {
                // Обмениваем элементы местами, если они не упорядочены
                if (vector[j] > vector[j + 1]) {
                    std::swap(vector[j], vector[j + 1]);
                    ++swaps;
                }
            }
            // Если обменов не было, то массив отсортирован
            if (swaps == 0) {
                break;
            }
        }
    }

    void iverson12Sort(std::vector<int> &vector) {
        for (int i = 0; i < vector.size(); i++) {
            // Определяем границу, до которой нужно сортировать
            int bound = vector.size() - i - 1;
            int temp = 0;
            for (int j = 0; j < bound; j++) {
                // Обмениваем элементы местами, если они не упорядочены
                if (vector[j] > vector[j + 1]) {
                    std::swap(vector[j], vector[j + 1]);
                    temp = j + 1;
                }
            }
            if (temp == 0) {
                break;
            }
        }
    }
};

void test(int len, int step) {
    SpecialVector vector(len);
    std::ofstream out;
    out.open("results.txt", std::ios_base::app);
    for (int j = 0; j < 13; ++j) {
        Sort sort;
        sort.setType(j);
        out << sort.type << ";";
        for (int i = 1; i < 5; ++i) {
            out << "This is type " << i << ";";
            vector.run(i);
            for (int k = step; k <= len; k += step) {
                out << "Length:" << k << std::endl;
                for (int l = 0; l < 10; ++l) {
                    std::vector<int> temp(i);
                    for (int m = 0; m < i; ++m) {
                        temp[m] = vector.vec[m];
                    }
                    auto start = std::chrono::high_resolution_clock::now();
                    sort.run(i, temp);
                    auto elapsed = std::chrono::high_resolution_clock::now() - start;
                    int64_t nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                    out << nanoseconds << std::endl;
                }
            }
        }
    }
}

int main() {
    test(300, 50);
    test(4100, 100);
}
