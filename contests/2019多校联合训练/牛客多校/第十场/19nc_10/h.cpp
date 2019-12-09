#include <bits/stdc++.h>
using namespace std;

typedef array<pair<int, int>, 5> molecule;
molecule isomer[] = {
    { { {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6} } }, // n-hexane
    { { {1, 3}, {2, 3}, {3, 4}, {4, 5}, {5, 6} } }, // 2-methylpentane
    { { {1, 4}, {2, 3}, {3, 4}, {4, 5}, {5, 6} } }, // 3-methylpentane
    { { {1, 4}, {2, 5}, {3, 4}, {4, 5}, {5, 6} } }, // 2,3-dimethylbutane
    { { {1, 4}, {2, 4}, {3, 4}, {4, 5}, {5, 6} } }, // 2,2-dimethylbutane
};

const char *name[] = {
    "n-hexane", "2-methylpentane", "3-methylpentane",
    "2,3-dimethylbutane", "2,2-dimethylbutane"
};

molecule canonicalize(molecule mol) {
    for (auto& p : mol) if (p.first > p.second) swap(p.first, p.second);
    sort(mol.begin(), mol.end());
    return mol;
}

map<molecule, int> moltype;

void init() {
    for (int i = 0; i < 5; i++) {
        molecule mol = isomer[i];
        int perm[7]; iota(perm + 1, perm + 7, 1);
        do {
            molecule cm = mol;
            for (auto& p : cm) {
                p.first = perm[p.first];
                p.second = perm[p.second];
            }
            moltype[canonicalize(cm)] = i;
        } while (next_permutation(perm + 1, perm + 7));
    }
}

int main() {
    init();
    int T; scanf("%d", &T);
    while (T--) {
        molecule mol;
        for (int i = 0; i < 5; i++)
            scanf("%d%d", &mol[i].first, &mol[i].second);
        puts(name[moltype.at(canonicalize(mol))]);
    }
    return 0;
}
