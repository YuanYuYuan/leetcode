#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<vector<string>> readCsv(string filePath) {
    fstream file;
    file.open(filePath);

    vector<string> row{};
    vector<vector<string>> data{};
    string line;
    while (getline(file, line)) {
        row.clear();
        istringstream temp(line);
        string word;
        while (getline(temp, word, ',')) {
            row.push_back(word);
        }
        data.push_back(row);
    }
    file.close();
    return data;
}

int main() {
    vector<vector<string>> data = readCsv("./example.csv");
    for (auto line: data) {
        for (auto word: line) {
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}
