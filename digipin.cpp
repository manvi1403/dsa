#include "digipin.h"
// Implement your code here

using namespace std;

// SOME HELPER FUNCTIONS DECLATIONS, WHICH MAY HELP YOU IMPLEMENT THE TASK

// Digipin symbols grid
array<array<char, 4>, 4> GRID = {{{'F', 'C', '9', '8'},
                                  {'J', '3', '2', '7'},
                                  {'K', '4', '5', '6'},
                                  {'L', 'M', 'P', 'T'}}};

// function to get the grid index corresponding to a Digipin symbols
pair<int, int> symbolToRC(char s)
{
    for (int r = 0; r < 4; ++r)
        for (int c = 0; c < 4; ++c)
            if (GRID[r][c] == s)
                return {r, c};
    return {0, 0};
}

void applyGridlineRules(double &lat, double &lon,
                        double latMin, double latMax,
                        double lonMin, double lonMax)
{
    // To handle coordinates coinciding with DIGIPIN Grid Lines
    // shift by 1e-12 in the correct direction according to the specification;
    

}

// TASK IS TO IMPLEMENT THE FOLLOWING TWO FUNCTIONS
pair<pair<double,double>, pair<double,double>>findsym(double &lat, double &lon, double latMin, double latMax,double lonMin, double lonMax,string& s){
    double r0,r1, r2, r3, r4;
    r1=(latMax+3*latMin)/4;
    r2=(2*latMax+2*latMin)/4;
    r3=(3*latMax+latMin)/4;
    r4=latMax;
    r0=latMin;
    double c0,c1, c2, c3, c4;
    c1=(lonMax+3*lonMin)/4;
    c2=(2*lonMax+2*lonMin)/4;
    c3=(3*lonMax+lonMin)/4;
    c4=lonMax;
    c0=lonMin;
    if((lon == c1 || lon == c2 || lon == c3) && (lat == r1 || lat==r2 || lat==r3)){
        s+='8';
        return {{c3,c4},{r3,r4}};
    }
    if(lon>=c0 && lon<c1 && lat>=r0 && lat < r1 ){
        s+='L';
        return {{c0,c1}, {r0,r1}};
    }
    if(lon>=c0 && lon<c1 && lat>=r1 && lat < r2 ){
        s+='K';
        return {{c0,c1}, {r1,r2}};
    };
    if(lon>=c0 && lon<c1 && lat>=r2 && lat < r3 ){
        s+='J';
        return {{c0,c1}, {r2,r3}};
    };
    if(lon>=c0 && lon<c1 && lat>=r3 && lat <= r4 ){
        s+='F';
        return {{c0,c1}, {r3,r4}};
    };
    if(lon>=c1 && lon<c2 && lat>=r0 && lat < r1){
        s+='M';
        return {{c1,c2}, {r0,r1}};
    }
    if(lon>=c1 && lon<c2 && lat>=r1 && lat < r2){
        s+='4';
        return {{c1,c2}, {r1,r2}};
    };
    if(lon>=c1 && lon<c2 && lat>=r2 && lat < r3){
        s+='3';
        return {{c1,c2}, {r2,r3}};
    };
    if(lon>=c1 && lon<c2 && lat>=r3 && lat <= r4){
        s+='C';
        return {{c1,c2}, {r3,r4}};
    };
    if(lon>=c2 && lon<c3 && lat>=r0 && lat < r1){
        s+='P';
        return {{c2,c3}, {r0,r1}};
    }
    if(lon>=c2 && lon<c3 && lat>=r1 && lat < r2){
        s+='5';
        return {{c2,c3}, {r1,r2}};
    };
    if(lon>=c2 && lon<c3 && lat>=r2 && lat < r3){
        s+='2';
        return {{c2,c3}, {r2,r3}};
    };
    if(lon>=c2 && lon<c3 && lat>=r3 && lat <= r4){
        s+='9';
        return {{c2,c3}, {r3,r4}};
    };
    if(lon>=c3 && lon<=c4 && lat>=r0 && lat < r1){
        s+='T';
        return {{c3,c4}, {r0,r1}};
    }
    if(lon>=c3 && lon<=c4 && lat>=r1 && lat < r2){
        s+='6';
        return {{c3,c4}, {r1,r2}};
    };
    if(lon>=c3 && lon<=c4 && lat>=r2 && lat < r3){
        s+='7';
        return {{c3,c4}, {r2,r3}};
    };
    if(lon>=c3 && lon<=c4 && lat>=r3 && lat <= r4){
        s+='8';
        return {{c3,c4}, {r3,r4}};
    };
    
}  
string Digipin::encode(double lat, double lon)
{
    // Implement to get Digipin from latitude and longitude values
    if(lat<2.5 || lat>38.5 || lon<63.5 || lon>99.5)return "-1";
    string s="";
    pair<pair<double,double>, pair<double,double>>a;
    a=findsym(lat,lon,2.5, 38.5, 63.5, 99.5,s);
    for(int i=1;i<10;i++){
        a=findsym(lat,lon,a.second.first, a.second.second,a.first.first,a.first.second,s);
    }
    
  return s;
}
pair<pair<double,double>, pair<double,double>>findbox(int r,int c,double latMin, double latMax,double lonMin, double lonMax){
    double r0,r1, r2, r3, r4;
    r1=(latMax+3*latMin)/4;
    r2=(2*latMax+2*latMin)/4;
    r3=(3*latMax+latMin)/4;
    r4=latMax;
    r0=latMin;
    double c0,c1, c2, c3, c4;
    c1=(lonMax+3*lonMin)/4;
    c2=(2*lonMax+2*lonMin)/4;
    c3=(3*lonMax+lonMin)/4;
    c4=lonMax;
    c0=lonMin;
    if(r==0 && c==0)return {{r4,r3},{c0,c1}};
    if(r==0 && c==1)return {{r4,r3},{c1,c2}};
    if(r==0 && c==2)return {{r4,r3},{c2,c3}};
    if(r==0 && c==3)return {{r4,r3},{c3,c4}};
    if(r==1 && c==0)return {{r3,r2},{c0,c1}};
    if(r==1 && c==1)return {{r3,r2},{c1,c2}};
    if(r==1 && c==2)return {{r3,r2},{c2,c3}};
    if(r==1 && c==3)return {{r3,r2},{c3,c4}};
    if(r==2 && c==0)return {{r2,r1},{c0,c1}};
    if(r==2 && c==1)return {{r2,r1},{c1,c2}};
    if(r==2 && c==2)return {{r2,r1},{c2,c3}};
    if(r==2 && c==3)return {{r2,r1},{c3,c4}};
    if(r==3 && c==0)return {{r1,r0},{c0,c1}};
    if(r==3 && c==1)return {{r1,r0},{c1,c2}};
    if(r==3 && c==2)return {{r1,r0},{c2,c3}};
    if(r==3 && c==3)return {{r1,r0},{c3,c4}};
    
}  
pair<double, double> Digipin::decode(string &code)
{
    // Implement to get the center of the bounding box
  double latCenter = 0;
  double lonCenter = 0;
//   pair<int,int>c=make_pair(0,0);
// for(int i=0;i<code.size();i++){
//     if(symbolToRC(code[i]) == c){
//         return make_pair(-1,-1);
//     }
// }
pair<int,int>a;
a=symbolToRC(code[0]);
pair<pair<double,double>, pair<double,double>>b;
b=findbox(a.first,a.second,2.5,38.5,63.5,99.5);
for(int i=1;i<code.size();i++){
    a=symbolToRC(code[i]);
    b=findbox(a.first,a.second,b.first.second,b.first.first,b.second.first,b.second.second);
}
latCenter=(b.first.second+b.first.first)/2;
lonCenter=(b.second.first+b.second.second)/2;
  return {latCenter, lonCenter}; // Return center of the cell
}
