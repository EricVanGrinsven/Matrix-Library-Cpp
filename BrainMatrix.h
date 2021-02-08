#ifndef BRAINMATRIX_H
#define BRAINMATRIX_H
#include <iostream>
#include <vector>
using namespace std;
/*
        class: Matrix
        Matrix object used to perform mathematical operations for BrainCorp
        constructor 1 input: (int) m: size 1 for mxn matrix
                             (int) n: size 2 for mxn matrix
                             Initializes zero-filled matrix of size mxn
        constructor 2 input: (vector<vector<double>>) matrix: input matrix
                             Initialize matrix of User's choice
*/
class BrainMatrix {
private:
        vector<vector<double> > matrix;
        pair<int, int> shape;
public:
        BrainMatrix(int m, int n);
        BrainMatrix(vector<vector<double> > mat);
/*
	function: getShape
	Gives shape of matrix
	return: (int,int) pair for rowxcol shape.
*/
	pair<int, int> getShape();
/*
	function:getMatrix
	Gives matrix as a 2d vector
	return: (vector<vector<double>>) matrix values
 */

	vector<vector<double> > getMatrix();
/*
	function: changeElement
	Replaces the previous value at matrix[i][j] to num
	input: (int) row: row you want to change
	       (int) col: col you want to change
	       (double) num: value you want to input into the location
	return: None
 */  
	void changeElement(int row, int col, double num);
/*
 * Simple print function to make the output readable.  allows you to easily print a BrainMatrix.
 */
	friend ostream& operator<<(std::ostream &strm, const BrainMatrix &mat) {
		for (int i = 0; i < mat.shape.first; i++) {
			for (int j = 0; j < mat.shape.second; j++) {
				strm << mat.matrix[i][j];
				strm << " ";
			}
			strm << "\n";
		}
        return strm;
	}
};

#endif
