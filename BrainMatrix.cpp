#include <iostream>
#include <stdexcept>
#include <vector>
#include "BrainMatrix.h"
using namespace std;

/*
        class: BrainMatrix
        Matrix object used to perform mathematical operations for BrainCorp
        constructor 1 input: (int) m: size 1 for mxn matrix
                             (int) n: size 2 for mxn matrix
                             Initializes zero-filled matrix of size mxn
        constructor 2 input: (vector<vector<double>>) matrix: input matrix
                             Initialize matrix of User's choice
*/
        // Constructor 1
BrainMatrix::BrainMatrix(int m, int n) : matrix(m, vector<double>(n,0)) {
	    if (m <= 0 || n <= 0) {
		throw " sizes must be integers > 0";
	    }
            shape.first = m;
            shape.second = n;
        }
        // Constructor 2
BrainMatrix::BrainMatrix(vector<vector<double> > mat) {
            matrix = mat;
            shape.first = matrix.size(); 
            shape.second = matrix.at(0).size();
        }
/*
	function: getShape
	Gives shape of matrix
	return: (int,int) pair for rowxcol shape.
*/
pair<int, int> BrainMatrix::getShape() {
	return shape;
}
/*
	function:getMatrix
	Gives matrix as a 2d vector
	return: (vector<vector<double>>) matrix values
 */
vector<vector<double> > BrainMatrix::getMatrix() {
	return matrix;
}
/*
	function: changeElement
	Replaces the previous value at matrix[i][j] to num
	input: (int) row: row you want to change
	       (int) col: col you want to change
	       (double) num: value you want to input into the location
	return: None
 */  
void BrainMatrix::changeElement(int row, int col, double num) {
	if (row < shape.first && col < shape.second) {
		matrix[row][col] = num;
	}
}


