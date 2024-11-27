#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;


void printVector(const vector<string>& vec, const string& label) {
    cout << label << ": [";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << "\"" << vec[i] << "\"";
        if (i < vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void bubbleSort(vector<string>& vec) {
    size_t n = vec.size();
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}


void removeDuplicates(vector<string>& vec) {
    if (vec.empty()) return;

    vector<string> uniqueVec;
    uniqueVec.push_back(vec[0]);

    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] != vec[i - 1]) {
            uniqueVec.push_back(vec[i]);
        }
    }

    vec = uniqueVec;
}

int main() {
  
    vector<string> inventory = {"apples", "bananas", "oranges", "pears"};
    

    vector<string> shipment = {"kiwis", "bananas", "grapes"};
    
 
    printVector(inventory, "Current Inventory");
    printVector(shipment, "Shipment");
    
 
    unordered_set<string> soldOutItems = {"apples", "oranges"};
    

    vector<string> updatedInventory;
    for (const string& item : inventory) {
        if (soldOutItems.find(item) == soldOutItems.end()) {
            updatedInventory.push_back(item);
        }
    }

    updatedInventory.insert(updatedInventory.end(), shipment.begin(), shipment.end());


    bubbleSort(updatedInventory);
    

    removeDuplicates(updatedInventory);


    printVector(vector<string>(soldOutItems.begin(), soldOutItems.end()), "Sold-out items");


    printVector(updatedInventory, "Updated Inventory");

    return 0;
}
