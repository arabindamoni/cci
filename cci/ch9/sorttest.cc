#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <new>
#include <ctime>
using namespace std;

bool comp1(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}

bool comp2(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

bool equal(pair<int,int> a, pair<int,int> b){
    return (a.first==b.first) && (a.second==b.second);
}

int max(int a,int b){ return (a > b)? a:b;}

// largest common subsequence
int LCS(vector<pair<int,int> > s1, vector<pair<int,int> > s2,int i,int j,int *mat){    
    if(i<0 || j<0) return 0;
    if(*(mat+i*s1.size()+j)) return *(mat+i*s1.size()+j);
    int a=0;
    if(equal(s1[i],s2[j])) a=1;;
    *(mat+i*s1.size()+j) = a + max(LCS(s1,s2,i,j-1,mat),LCS(s1,s2,i-1,j,mat));
    return *(mat+i*s1.size()+j);
}


void printarr(vector<pair<int,int> > s){
    for (int a=0;a<s.size();a++) {
        std::cout <<"("<< s[a].first <<","<<s[a].second << ") ";
    } 
    cout << endl;
}

void printmatrix(int *mat,int i,int j){
    for(int a=0;a<i;a++){
        for(int b=0;b<j;b++){
            cout << *(mat+i*a+b)<<"  ";
        }
        cout << endl;
    }
    cout << endl;
}

void initmatrix(int *mat,int i,int j,int value){
    for(int a=0;a<i;a++){
        for(int b=0;b<j;b++){
            *(mat+i*a+b) =value;
        }
    }
}

int main(){
    clock_t start = clock();
    int size =25;
    srand(time(0));
    vector<pair<int,int> > s1(size);        
    for(int i=0;i<size;i++){
        s1[i].first = rand()%200;
        s1[i].second = rand()%200;
    }
    vector<pair<int,int> > s2(s1);
    printarr(s1);
    std::sort(s1.begin(), s1.end(), comp1);
    printarr(s1);

    std::sort(s2.begin(), s2.end(), comp2);
    printarr(s2);

    int *mat = new int[s1.size()*s2.size()];    
    initmatrix(mat,s1.size(),s2.size(),0);
    cout << LCS(s1,s2,s1.size()-1,s2.size()-1,mat);
    std::cout << '\n';         
    printmatrix(mat,s1.size(),s2.size());
    cout << "Execution time: "<<(clock() - start)/(double)1000000 <<" seconds"<<endl;
}