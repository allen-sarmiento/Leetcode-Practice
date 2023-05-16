#include "MinStack.h"

using namespace std;

int main() {

    MinStack ms;

    ms.push(2147483646);
    ms.push(2147483646);
    ms.push(2147483647);
    ms.top();
    ms.pop();
    ms.getMin();
    ms.pop();
    ms.getMin();

    return 0;
}