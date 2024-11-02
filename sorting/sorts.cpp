#include <iostream>
#include <vector>

typedef std::vector<int> nvec_t;
void selectionsort(nvec_t& vec);
void insertionsort(nvec_t& vec);
void printvec(nvec_t& vec);
void merge(nvec_t& vec, int left, int mid, int right);
void mergesortHelper(nvec_t& vec, int left, int right);
void mergesort(nvec_t& vec);
void quicksort(nvec_t& vec);
void quicksortHelper(nvec_t& vec, int left, int right);
int partition(nvec_t& vec, int left, int right);


int main() {
    nvec_t numbers = {1, 11, -1, 4, 5, 22, 2, 10, 4, 3, 82, 4, -19, -5};
    selectionsort(numbers);
    printvec(numbers);

    numbers = {1, 11, -1, 4, 5, 22, 2, 10, 4, 3, 82, 4, -19, -5};
    insertionsort(numbers);
    printvec(numbers);

    numbers = {1, 11, -1, 4, 5, 22, 2, 10, 4, 3, 82, 4, -19, -5};
    mergesort(numbers);
    printvec(numbers);

    numbers = {1, 11, -1, 4, 5, 22, 2, 10, 4, 3, 82, 4, -19, -5};
    quicksort(numbers);
    printvec(numbers);
    return 0;
}

void printvec(nvec_t& vec) {
    for (int el : vec) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

void selectionsort(nvec_t& vec) {
    int len = vec.size();
    for (int i = 0; i < len - 1; i++) {
        int min_ix = i;
        for (int j = i + 1; j < len; j++) {
            if (vec[j] < vec[min_ix]) {
                min_ix = j;
            }
        }
        int holder = vec[i];
        vec[i] = vec[min_ix];
        vec[min_ix] = holder;
    }
}

void insertionsort(nvec_t& vec) {
    int len = vec.size();
    for (int i = 1; i < len; i++) {
        int el = vec[i];
        int j = i - 1;
        while (j >= 0) {
            if (el < vec[j]) {
                vec[j + 1] = vec[j];
            } else {
                break;
            }
            j--;
        }
        vec[j + 1] = el;
    }
}

void mergesort(nvec_t& vec) {
    mergesortHelper(vec, 0, vec.size() - 1);
}

void mergesortHelper(nvec_t& vec, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergesortHelper(vec, left, mid);
        mergesortHelper(vec, mid + 1, right);
        merge(vec, left, mid, right);
    }
}

void merge(nvec_t& vec, int left, int mid, int right) {
    int n1 = mid - left + 1; // compute lengths
    int n2 = right - mid;
    int n = n1 + n2;
    nvec_t l1(n1); // copy vectors
    nvec_t l2(n2);
    for (int i = 0; i < n1; i++) {
        l1[i] = vec[left + i];
    }
    for (int i = 0; i < n2; i++) {
        l2[i] = vec[mid + 1 + i];
    }
    int p1 = 0, p2 = 0; // merge back into input
    while (p1 < n1 && p2 < n2) {
        if (l1[p1] < l2[p2]) {
            vec[left + p1 + p2] = l1[p1];
            p1++;
        } else {
            vec[left + p1 + p2] = l2[p2];
            p2++;
        }
    }
    if (p1 < n1) {
        while (p1 < n1) {
            vec[left + p1 + p2] = l1[p1];
            p1++;
        }
    } else if (p2 < n2) {
        while (p2 < n2) {
            vec[left + p1 + p2] = l2[p2];
            p2++;
        }
    }
}

void quicksort(nvec_t& vec) {
    quicksortHelper(vec, 0, vec.size() - 1);
}

void quicksortHelper(nvec_t& vec, int left, int right) {
    if (left < right) {
        int ix = partition(vec, left, right);
        quicksortHelper(vec, left, ix - 1);
        quicksortHelper(vec, ix + 1, right);
    }
}

int partition(nvec_t& vec, int left, int right) {
    int pivot = vec[right];
    int r = left, w = left;
    while (r <= right) {
        if (vec[r] < pivot) {
            int holder = vec[w];
            vec[w] = vec[r];
            vec[r] =holder;
            w++;
        }
        r++;
    }
    int holder = vec[w];
    vec[w] = pivot;
    vec[right] = holder;
    return w;
}