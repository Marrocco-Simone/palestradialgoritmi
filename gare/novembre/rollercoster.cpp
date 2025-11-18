#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int N;
    cin >> N;

    vector<char> D(N);
    for (int i = 0; i < N; ++i){
        cin>>D[i] ;
    }
    int vel=0;      //contatore Velocita
    int hcount=0;   //contatore di h presenti nel percorso al momento
    int swap=0;     //Numero di elementi swappati
    bool imp=false;

    for(int i=0;i<N;i++){
        if(D[i]=='D'){
            vel+=9;
        }else if (D[i]=='U'){
            vel+=-11;
            
        }else if(D[i]=='B'){
            vel+=10;
        }else if(D[i]=='H'){
            hcount++;
        }

        while(vel<=0){
            if(hcount>0){
                hcount--;
                swap++;
                vel=vel+10;
            }else{
                imp=true;
                break;
            }
        }
        if(imp){
                break;
            }
    }
    if(imp) {
        cout<<"-1"<<endl;
    }else{
        cout<<swap<<endl;
    }
}