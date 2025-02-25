// g++ main.cpp -o main

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> leftColumn;
vector<int> rightColumn;

void load_tasks_from_txt() {
		// Function variables
		string filename = "data.txt";

		// Open file
		ifstream file(filename);
    if (!file.is_open()) {          
      cerr << "Error opening file\n";
      return;  
    }
    
    int left, right;

    // Read the file line by line
    while (file >> left >> right) {
        leftColumn.push_back(left);
        rightColumn.push_back(right);
    }

    file.close();
}

void sort_arrays() {
    sort(leftColumn.begin(), leftColumn.end());
    sort(rightColumn.begin(), rightColumn.end());
}



int main(){
    load_tasks_from_txt();
    sort_arrays();  

    int res = 0;
    int simu = 0;

    for (int i = 0; i < leftColumn.size(); i++){
        res = res + abs(leftColumn[i] - rightColumn[i]);

        int counts = count(rightColumn.begin(), rightColumn.end(), leftColumn[i]);

        simu = simu + (leftColumn[i] * counts);

    }

    cout << "ans: " << res << endl;
    cout << "simu: " << simu << endl;

    return 0;
}

