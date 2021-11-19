#include "map.h"

#include <iostream>
#include "map.h"

#include <cstddef>
#include <filesystem>
#include <fstream>

using namespace std;
using namespace std::filesystem;

Map::Map() {
    
}

Map::Map(string path) {
    for (auto& file : directory_iterator(path)) {
        pair<size_t,size_t> index = getIndexFromFile(file.path());
        map[index.first][index.second] = MapCell(file.path());
    }
}

// Get the index where the corresponding cellMap should be in map[][]
pair<size_t,size_t> Map::getIndexFromFile(string path) {
    ifstream cell(path);

    string line = "";
    getline(cell, line);

    int row = stoi(line);

    getline(cell, line);
    int col = stoi(line);

    if (row < 0 || col < 0) {
        // handle error
    }

    return make_pair(row, col);
}
