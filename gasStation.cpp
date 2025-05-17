#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int totalGas = 0, totalCost = 0, tank = 0, startIndex = 0;

    for (int i = 0; i < gas.size(); i++) {
        totalGas += gas[i];
        totalCost += cost[i];
        tank += gas[i] - cost[i];

        if (tank < 0) { 
            startIndex = i + 1; 
            tank = 0; 
        }
    }

    if (totalGas < totalCost) return -1;  
    return startIndex;  
}

int main() {
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    int result = canCompleteCircuit(gas, cost);
    if (result == -1)
        cout << "It is not possible to complete the circuit." << endl;
    else
        cout << "The starting gas station index is: " << result << endl;

    return 0;
}
