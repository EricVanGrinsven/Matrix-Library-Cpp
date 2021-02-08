#ifndef MATRIXMATH_H
#define MATRIXMATH_H
#include <vector>
#include <iostream>
#include "BrainMatrix.h"
        /*
        transpose operation
       
        function: transpose
        Perform math operation transpose on a matrix
        input: (vector<double>) a: input vector
        constraints: a.matrix must be non-empty
        return: (BrainMatrix) transposed matrix
        */
        BrainMatrix transpose(BrainMatrix& a);
        /*
        multiply operation
	function: matmul
        Perform math operation matrix multiplication between two vectors
        input: (BrainMatrix) a: input mat 1
               (BrainMatrix) b: input mat 2
        constraints: matrices must be non-empty && a.shape.first == b.shape.second
        return: (BrainMatrix) a*b matrix
        */
        
        BrainMatrix matmul(BrainMatrix& a, BrainMatrix& b);
#endif
