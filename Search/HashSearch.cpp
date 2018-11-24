//
// Created by aSUSS on 2018/11/24.
//

#include "HashSearch.h"
#include "iostream"
int hash(int k) {
    int h;
    h = k % m;
    return h;
}

int HashSearch(HashTable ht, int K) {
    int h0;
    int i;
    int hi;

    h0 = hash(K);
    if (ht[h0] == NULLKEY) {
        return (-1);
    } else {
        if (ht[h0] == K) {
            return (h0);
        } else   /* 用线性探测再散列解决冲突 */
        {
            for (i = 1; i <= m - 1; i++) {
                hi = (h0 + i) % m;
                if (ht[hi] == NULLKEY) {
                    return (-1);
                } else {
                    if (ht[hi] == K) {
                        return (hi);
                    }
                }
            }
            return (-1);
        }
    }
}

int main() {
    HashTable ht = {0, 65, 15, 57, 34, 55, 23, 98, 67, 87, 89, 58, 36};
    HashTable ht2 = {0};
    for (int i = 0; i < m; ++i) {
        int k=ht[i];
        ht2[hash(k)]=k;
    }
    int x=HashSearch(ht2,34);
    printf("%d ",x);
}

