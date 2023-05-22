#include <iostream>
#include <vector>
#include <omp.h>

void odd_even_sort(std::vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        #pragma omp parallel for shared(a) num_threads(4)
        for (int j = i%2; j < n-1; j += 2) {
            if (a[j] > a[j+1]) {
                std::swap(a[j], a[j+1]);
            }
        }
    }
}

int main() {
    std::vector<int> a = {7, 3, 5, 1, 9, 2, 6, 8, 4, 0};
    odd_even_sort(a);
    for (int x : a) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}
