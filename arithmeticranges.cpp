#include <iostream> 
using namespace std;
long long apCeiling(long long first, long long step, long long x) {
    long long index = ((x - first + (step - 1)) / step);
    return first + index * step;
}
long long apFloor(long long first, long long step, long long x) {
    long long index = ((x - first) / step);
    return first + index * step;
}
long long countApValues(long long seqFirst, long long seqLast, long long step, long long intervalFirst, long long intervalLast)
{
    if (intervalFirst >= seqLast || seqFirst >= intervalLast)
        return 0;                          // if neither are in the interval (hasn't started or already finished)
    if (intervalLast > seqLast)
        intervalLast = seqLast; //
    if (intervalFirst < seqFirst)
        intervalFirst = seqFirst;
    long long right = apFloor(seqFirst, step, intervalLast - 1);
    long long left = apCeiling(seqFirst, step, intervalFirst);
    return (right - left) / step + 1;
}
int main() {
    long long step, first, last;
    cin >> first >> last >> step;
    long long sum = (last-first - 1) / step ;
    long long currPower = 1;
    for (int i = 1; i <= 18; i++) {
        long long x = countApValues(first, last, step, currPower, currPower * 10);
        sum += x * i;
        currPower *= 10;
    }
    cout << sum;
}

