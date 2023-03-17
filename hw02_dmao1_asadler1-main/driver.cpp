#include <iostream>
#include <cstdlib>
#include <random>
#include <vector>
#include <chrono>
#include "point.h"
#include "closestpair.h"
using namespace std;

#define GRIDSIZE 40000001

void usage() {
    cout << "Usage: driver A N [S]" << endl;
    cout << "  A=0 brute, A=1 divide/conquer, A=2 extra" << endl;
    cout << "  N=number of points (N >= 2)" << endl;
    cout << "  S=integer random seed (optional)" << endl;
    exit(-1);
}


void validate(const vector<Point>& data, const Point& p) {
    bool found = false;
    for (unsigned int j=0; j < data.size(); j++) {
        if (data[j].x == p.x && data[j].y == p.y) {
            found = true;
            break;
        }
    }

    if (!found)
        cout << "ERROR: reported point " << p.x << "," << p.y << " not in original data set" << endl;
}

int main(int argc, char* argv[]) {
    if (argc < 3)
        usage();
    int A = atoi(argv[1]);
    if (A < 0 || A > 2)
        usage();
    int N = atoi(argv[2]);
    if (N < 2)
        usage();
    long S;
    if (argc > 3) 
        S = atol(argv[3]);
    else {
        S = time(NULL);
        cout << "Seed = " << S << endl;
    }

    mt19937 mt_rand(S);

    vector<Point> data(N);
    for (int j=0; j < N; j++) {
        data[j].x = mt_rand() % GRIDSIZE;
    }
    for (int j=0; j < N; j++) {
        data[j].y = mt_rand() % GRIDSIZE;
    }

    Outcome ans;
    auto begin = chrono::steady_clock::now();
    switch (A) {
    case 0:
        ans = brute(data);
        break;
    case 1:
        ans = efficient(data);
        break;
    case 2:
        ans = extra(data);
        break;
    }
    auto end = chrono::steady_clock::now();

    cout << "minimum distance squared reported as " << ans.dsq << endl;
    cout << "achieved by points " << ans.p.x << "," << ans.p.y << " and " << ans.q.x << "," << ans.q.y << endl;
    cout << "elapsed time: " << chrono::duration<double, milli> (end-begin).count() << " ms" << endl;

    validate(data, ans.p);
    validate(data, ans.q);
}


