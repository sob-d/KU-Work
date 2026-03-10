#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        int count[100] = {0};
        int age;

        for (int i = 0; i < n; ++i) {
            scanf("%d", &age);
            count[age]++;
        }

        bool first = true;
        for (int i = 1; i < 100; ++i) {
            for (int j = 0; j < count[i]; ++j) {
                if (!first) printf(" ");
                printf("%d", i);
                first = false;
            }
        }
        printf("\n");
    }
    return 0;
}