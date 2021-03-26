//Anuoluwakiitan Doherty
//Lab 8

/* random number generation code sourced from: https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution */


#include<iostream>
#include<random>
using namespace std;


int LinearIndx(int i, int j) {
    
    int bindex = int(i*(i+1)/2 + j);
    return bindex;
}

auto InverseIndx(int I) {
    int root = floor(sqrt(2 * I));
    if (root*root + root > 2*I)
        {root -=1;}
    int i = root;
    int j= int((2*I - (i*i + i))/2);
    
    auto first = std::make_tuple (i, j);
    return first;
}

void MatrixRun(int size) {
    
    //prepare random number generator
    std::random_device rd;  //obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, 1000);
    
    //Creation of A
    int n = size;

    int A[n][n];
    cout<<"N = " << n << "\n \n";
    cout<< "Matrix A: \n";
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            if (i>=j) {
                A[i][j] =  distrib(gen);
            }
            else {
                A[i][j] = 0;
            }
        }
    }
    
    //Printing first 20 values from A
    int counter = 0;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            if (i>=j) {
                printf("A[%d][%d] = %d  ", i, j, A[i][j]);
                counter +=1;
                if(counter == 20) {
                    break;
                }
            }
        }
        if(counter == 20) {
            break;
        }
    }
    cout<< "\n \n";

    
    //Creation of B
    int sizeB = (n + 1)*(n + 2)/2;
    int B[sizeB];
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            if (i>=j) {
                int bindex =  LinearIndx(i, j);
                B[bindex] = A[i][j];
            }
        }
    }
    
    //Printing values from B
    cout<< "Matrix B: \n";
    for (int i = 0; i<20; i++) {
        printf("B[%d] = %d  ", i, B[i]);
    }
    cout<< "\n \n";
  
    
    //Creation of C
    int C[n][n];
    counter = 0;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            C[i][j] = 0;
        }
    }
    for (int i = 0; i<sizeB; i++) {
        tuple<int, int> first;
        first = InverseIndx(i);
        C[std::get<0>(first)][std::get<1>(first)] = B[i];
    }
    
    //printing values from C
    cout<< "Matrix C: \n";
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            if (i>=j) {
                printf("C[%d][%d] = %d  ", i, j, C[i][j]);
                counter +=1;
            }
            if(counter == 20) {
                break;
            }
        }
        if(counter == 20) {
            break;
        }
    }
    cout<<"\n \n";
}

    //Main program to generate A, B, C for N= 8, 32, 128
    int main() {
    MatrixRun(8);
    MatrixRun(32);
    MatrixRun(128);
    return 0;

}




