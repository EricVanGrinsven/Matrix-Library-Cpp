#include<iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include"BrainMatrix.h"
#include "MatrixMath.h"

using namespace std;
void testing();
void start();
void demo();
void interact();
int main () {

    start();
    return 0;
}

void start() {
	
    cout << "Welcome to BrainMatrix, the brand new high-performance linear algebra library.\nTo see a demo of this pristine piece of software, type Demo\nTo interact with the library, type Interact\nTo see testing, type Test\n to quit at any point, type q\n";
    bool validStr = false;
    while (!validStr) {
    	string str;
    	cin >> str;
   	 if (str.compare("Demo") == 0) {
		demo();
		validStr = true;
	 }
	 else if (str.compare("Interact") == 0) {
		interact();
		validStr = true;
	 }
	 else if (str.compare("Test") == 0) {
		testing();
		validStr = true;
	 }
	 else if (str.compare("q")) break;
	 else {
		cout << "Please type a valid response/n";
	 }


    }


}
void demo() {
    int m = 2;
    int n = 2;
    vector<vector<double> > a(m, vector<double>(n, 0));
    vector<vector<double> > b(m, vector<double>(n, 0));
    int count = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
                a[i][j] = count++;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
                b[i][j] = count++;
        }
    }
    BrainMatrix matA(a);
    BrainMatrix matB(b);
    cout << "Matrix A \n";
    cout << matA << "\n";
    cout << "Matrix B \n";
    cout << matB << "\n";
    matA = transpose(matA);
    cout << "A Transposed\n" << matA << "\n";
    matA = transpose(matA);
    cout << "A Transposed (Again) \n" << matA << "\n";
    BrainMatrix mat1 = matmul(matA, matB);
    cout << "A*B\n" << mat1 << "\n";
    mat1 = matmul(matB, matA);
    cout << "B*A\n" << mat1 << "\n";
    cout << "Thank you for viewing the demo\n";
}
void interact() {
	bool noErrors = true;
	cout << "Welcome to the interaction phase. \n";
	cout << "Choose the row size of Matrix A\n";
	int row;
	cin >> row;
        cout << "Choose the column size of Matrix A\n";
	int col;
	cin >> col;
	BrainMatrix A(row, col);
	for (int i = 0; i < row; i++) {
        	for (int j = 0; j < col; j++) {
                	A.changeElement(i,j,rand()%100);
        	}	
   	 }
	cout << "Choose the row size of Matrix B\n";
	cin >> row;
        cout << "Choose the column size of Matrix B\n";
	cin >> col;
	BrainMatrix  B(row, col);
	for (int i = 0; i < row; i++) {
        	for (int j = 0; j < col; j++) {
                	B.changeElement(i,j,rand()%100);
        	}	
   	 }

	cout << "We will fill in the elements of the array with random integers 0-100. To add your own inputs, you will need to purchase a paid copy [ or hire me ;) ].\n";
	cout << "A:\n" << A << "B:\n" << B;
	
	while (noErrors) {
		cout << "Choose Multiply or Transpose\n";
		string action;
		cin >> action;
		if (action.compare("Transpose") == 0) {
			cout << "Choose A or B\n";
			string choice;
			cin >> choice;
			if (choice.compare("A") == 0) {
				cout << transpose(A);
				continue;
			}
			if (choice.compare("B") == 0){
				cout << transpose(B);
				continue;
			}
			else break;
		
		}
		else if (action.compare("Multiply") == 0) {
			cout << "Choose A or B for the left matrix\n";
			string choice;
			cin >> choice;
			if (choice.compare("A") == 0) {
				cout << matmul(A,B);
				continue;
			}
			if (choice.compare("B") == 0) {
				cout << matmul(B,A);
				continue;
			}
			else break;

		}
		else break;	
	}

}


void testing() {
	cout << "Checking insertion of own vector matrix\n";
	vector<vector<double> > tmp(1, vector<double>(1, 0));
	BrainMatrix mat1(tmp);
	if (mat1.getMatrix()[0][0] == tmp[0][0]) {
		cout << "correct\n";
	}
	else cout << "ERROR";

	cout << "Checking element initialization to 0\n";
	BrainMatrix mat2(1,1);
	if (mat2.getMatrix()[0][0] == 0) {
		cout << "correct\n";
	}
	else cout << "ERROR";

	cout << "Checking matrix size\n";
	BrainMatrix mat3(1,1);
	if (mat3.getShape().first == 1 && mat3.getShape().second == 1) {
		cout << "correct\n";
	}
	else cout << "ERROR";
	/*
	cout << "Checking matrix max integer size for a vector\n";
	cout << "hi";
	BrainMatrix mat4(std::vector<vector<double> >::max_size(), std::vector<double>::max_size());
	if (mat4.getShape().first ==std::vector<vector<double> >::max_size()  && mat4.getShape().second == std::vector<double>::max_size()) {
		cout << "correct\n";
	}
	else cout << "ERROR";
	*/
	cout << "Checking transpose on 1x1 matrix\n";
	BrainMatrix mat5(1,1);
	mat5.changeElement(0,0,1);
	BrainMatrix temp = transpose(mat5);
	if (temp.getMatrix()[0][0] == 1) {
		cout << "correct\n";
	}
	else cout << "ERROR";

	cout << "Checking transpose on larger matrix where n != m\n";
	BrainMatrix mat6(100,150);
	int count = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 150; j++) {
			mat6.changeElement(i,j,++count);
		}
	}
	BrainMatrix mat7 = transpose(mat6);
	count = 0;
	bool mat7correct = true;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 150; j++) {
			if (mat7.getMatrix()[j][i] != ++count)
				mat7correct = false;
		}
	}
	if (!mat7correct) {
		cout << "ERROR\n";
	}
	else cout << "correct\n";

	cout << "Checking matrix multiplication on two 1x1 matrices\n";
	BrainMatrix mat8(1,1);
	BrainMatrix mat9(1,1);
	mat8.changeElement(0,0,1);
	mat9.changeElement(0,0,1);
	BrainMatrix mat10 = matmul(mat8, mat9);
	if (mat10.getMatrix()[0][0] == 1) {
		cout << "correct\n";
	}
	else cout << "ERROR";

cout << "Checking matrix multiplication on two matrices mxn and nxp.\n";
	BrainMatrix mat11(10,11);
	BrainMatrix mat12(11,12);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 11; j++) {
			mat11.changeElement(i,j,++count);
		}
	}
	count = 0;
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 12; j++) {
			mat12.changeElement(i,j,++count);
		}
	}
	bool mat13cor = true;
	BrainMatrix mat13 = matmul(mat11, mat12);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 12; j++) {
			double correct_val = 0;
			// use algorithm from online to check
			for (int k = 0; k < 11; k++) {
				correct_val += mat12.getMatrix()[k][j]*mat11.getMatrix()[i][k];	
			}
			if (mat13.getMatrix()[i][j] != correct_val)
				mat13cor = false;
		}
	}
	if (mat13cor) {
		cout << "correct\n";
	}
	else cout << "ERROR";

}
