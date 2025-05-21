#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Hàm tìm mảng hợp (Union) và giao (Intersection)
void findUnionAndIntersection(const vector<int> &A, const vector<int> &B) {
    set<int> unionSet;          // Tập hợp để lưu mảng hợp
    set<int> intersectionSet;   // Tập hợp để lưu mảng giao

    // Thêm tất cả phần tử của A vào tập hợp unionSet
    for (int num : A) {
        unionSet.insert(num);
    }

    // Thêm tất cả phần tử của B vào tập hợp unionSet
    // Nếu phần tử của B cũng có trong A, thêm vào intersectionSet
    for (int num : B) {
        if (unionSet.count(num)) {
            intersectionSet.insert(num);
        }
        unionSet.insert(num);
    }

    // In mảng hợp
    cout << "Union: ";
    for (int num : unionSet) {
        cout << num << " ";
    }
    cout << endl;

    // In mảng giao
    cout << "Intersection: ";
    for (int num : intersectionSet) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T; // Số lượng bộ test
    while (T--) {
        int n, m;
        cin >> n >> m; // Số phần tử của mảng A và B

        vector<int> A(n), B(m);

        // Nhập mảng A
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        // Nhập mảng B
        for (int i = 0; i < m; i++) {
            cin >> B[i];
        }

        // Tìm mảng hợp và giao
        findUnionAndIntersection(A, B);
    }

    return 0;
}