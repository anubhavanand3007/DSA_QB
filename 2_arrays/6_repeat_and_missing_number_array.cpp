#include<bits/stdc++.h>
using namespace std;

vector<long long int> repeatedNumber(const vector<int> &A) {
    /*
        expectedSum = 1+2+3+...+n = n*(n+1)/2
        expectedSquareSum = 1^2 + 2^2 + 3^2 + n^2 = 1/6(n)(n+1)(2n+1)

        for expected: a,b,c,d but given: a,b,c,c ;
        expectedsum - sum = d-c;
        expectedsquaresum - squaresum = d^2 - c^2 = (d+c)(d-c);

        diff = expecteddsum - sum = d- c;
        summ = (expectedsquaresum - squaresum)/diff = d + c;

        d = (diff+summ)/2;
        c = (-diff+summ)/2

    */
    long long int n = A.size();
    long long int expectedSum;
    expectedSum = (n*(n+1))/2;
    long long int expectedSquareSum;
    expectedSquareSum = (n*(n+1)*(2*n+1))/6;
    long long int sum=0, squareSum=0;
    for(long long int i=0;i<n;i++){
        sum+=A[i];
        squareSum += pow(A[i],2);
    }

    long long int diff = expectedSum - sum;
    long long int summ = (expectedSquareSum - squareSum)/diff;

    long long int a = (diff+summ)/2;
    long long int b = (summ-diff)/2;

    return {b,a};
}

int solve(){
    vector<int> A = {1,2,2};
    repeatedNumber(A);
}

int main(){
    solve();
    return 0;
}