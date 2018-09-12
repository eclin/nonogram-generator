#include "generator.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>

using namespace std;

void generate(int width, int height) {
  vector<vector<bool>> grid;
  vector<vector<int>> rowValues(height);
  vector<vector<int>> columnValues(width);

  int continuous = 0;
  srand(time(NULL));

  for (int i = 0; i < height; i++) {
    vector<bool> rowOfGrid;

    for (int j = 0; j < width; j++) {
      int val = rand() % 2;
      rowOfGrid.push_back(val);

      if (val == 0) {
        if (continuous != 0 || (j == width - 1 && continuous != 0)) {
          rowValues[i].push_back(continuous);
          continuous = 0;
        }
      } else {
        continuous++;
        if (j == width - 1){
          rowValues[i].push_back(continuous);
        }
      }
    }

    grid.push_back(rowOfGrid);
    continuous = 0;
  }

  for (int j = 0; j < width; j++) {
    for (int i = 0; i < height; i++) {
      if (grid[i][j] == 0) {
        if (continuous != 0 || (i == height-1 && continuous != 0)) {
          columnValues[j].push_back(continuous);
          continuous = 0;
        }
      } else {
        continuous++;
        if (i == height - 1) {
          columnValues[j].push_back(continuous);
        }
      }
    }
    continuous = 0;
  }

  // Print out the row arrays
  cout << "Rows:" << endl;
  for (int i = 0; i < rowValues.size(); i++) {
    cout <<"[";
    for (int j = 0; j < rowValues[i].size(); j++) {
      cout << rowValues[i][j] << " ";
    }
    cout << "]";
  }

  // Print out the column arrays
  cout << endl << "Columns:" << endl;
  for (int i = 0; i < columnValues.size(); i++) {
    cout << "[";
    for (int j = 0; j < columnValues[i].size(); j++) {
      cout << columnValues[i][j] << " ";
    }
    cout << "]";
  }

  // Print out the actual nonogram grid
  cout << endl << "Grid:" << endl;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cout << grid[i][j];
    }
    cout << endl;
  }


}
