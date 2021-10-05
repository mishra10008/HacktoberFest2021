#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
    Item(int value, int weight) {
        this->value = value;
        this->weight - weight;
    }
};

bool cmp(struct Item a, struct Item b) {
    double r1 = (double) a.value/(double) a.weight;
    double r2 = (double) b.value/(double) b.weight;
    return r1 > r2;
}

double fracknap(int w, struct Item arr[], int n) {
    sort(arr,arr+n,cmp);

    int currweight = 0;
    double finalval = 0.0;

    for (int i = 0; i < n; i++) {
        if (currweight + arr[i].weight <= w) {
            currweight += arr[i].weight;
            finalval += arr[i].value;
        }

        else {
            int rem = w - currweight;
            finalval += arr[i].value * (rem/arr[i].weight);
            break;
        }
    }
    return finalval;
}

int main() {
    int W = 50; 
    Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
 
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<fracknap(W,arr,n);
    return 0;
}