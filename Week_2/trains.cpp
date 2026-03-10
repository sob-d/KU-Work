#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int id;
    Node* next;
    Node(int v) : id(v), next(nullptr) {}
};

struct Platform {
    Node *head, *tail;
    Platform() : head(nullptr), tail(nullptr) {}
};

Platform platforms[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> M;

    for (int k = 0; k < M; k++) {
        char type;
        cin >> type;

        if (type == 'N') {
            int x, i;
            cin >> x >> i;
            Node* newNode = new Node(x);
            if (platforms[i].head == nullptr) {
                platforms[i].head = platforms[i].tail = newNode;
            } else {
                platforms[i].tail->next = newNode;
                platforms[i].tail = newNode;
            }
        } 
        else if (type == 'M') {
            int i, j;
            cin >> i >> j;
            if (platforms[i].head != nullptr) {
                if (platforms[j].head == nullptr) {
                    platforms[j].head = platforms[i].head;
                    platforms[j].tail = platforms[i].tail;
                } else {
                    platforms[j].tail->next = platforms[i].head;
                    platforms[j].tail = platforms[i].tail;
                }

                platforms[i].head = platforms[i].tail = nullptr;
            }
        }
    }

    for (int i = 1; i <= 100000; i++) {
        Node* curr = platforms[i].head;
        while (curr != nullptr) {
            cout << curr->id << "\n";
            curr = curr->next;
        }
    }

    return 0;
}