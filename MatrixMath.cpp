#include <iostream>
#include <vector>
#include <stdexcept>
#include "BrainMatrix.h"
#include "MatrixMath.h"
        /*
        function: transpose
        Perform math operation transpose on a matrix
        input: (vector<double>) a: input vector
        constraints: a.matrix must be non-empty
        return: (BrainMatrix) transposed matrix
        */
        BrainMatrix transpose(BrainMatrix& a) {
            // initialize matrix with opposite shape
            vector<vector<double> > b(a.getShape().second, vector<double>(a.getShape().first));
            // perform transpose (swap [i][j] to [j][i]) O(n*m)
            for (int i = 0; i < a.getShape().first; i++) {
                for (int j = 0; j < a.getShape().second; j++) {
                    b[j][i] = a.getMatrix()[i][j];
                }
            }
            return BrainMatrix(b);
        }
        /*
        function: matmul
        Perform math operation matrix multiplication between two vectors
        input: (BrainMatrix) a: input mat 1
               (BrainMatrix) b: input mat 2
        constraints: matrices must be non-empty && a.shape.first == b.shape.second
        return: (BrainMatrix) a*b matrix
        */
        BrainMatrix matmul(BrainMatrix& a, BrainMatrix& b) {
	    if (a.getShape().second != b.getShape().first) {
		throw invalid_argument("A.col must equal B.row");
	    }
	    int shape = a.getShape().second;
            vector<vector<double> > c(a.getShape().first, vector<double>(b.getShape().second, 0));

            for (int i = 0; i < a.getShape().first; i++) {
                for (int j = 0; j < b.getShape().second; j++) {
		    for (int k = 0; k < shape; k++) {
                    	c[i][j] += a.getMatrix()[i][k] * b.getMatrix()[k][j];
		    }
                }
            }
	    BrainMatrix mat(c);
            return mat;
        }
