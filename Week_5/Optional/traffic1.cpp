#include "traffic.h"
#include <bits/stdc++.h>
using namespace std;

int N,K;

int base_dist(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
}

// ตรวจว่าบริเวณซ้ายของ column x มี jam ไหม
bool has_jam_left(int x){
    int d = traffic_query(1,1,x,N);
    int expect = base_dist(1,1,x,N);
    return d>expect;
}

// หา column
int find_column(){
    int l=1,r=N;
    while(l<r){
        int mid=(l+r)/2;
        if(has_jam_left(mid))
            r=mid;
        else
            l=mid+1;
    }
    return l;
}

// ตรวจ row
bool has_jam_down(int y,int col){
    int d = traffic_query(col,1,col,y);
    int expect = base_dist(col,1,col,y);
    return d>expect;
}

// หา row
int find_row(int col){
    int l=1,r=N;
    while(l<r){
        int mid=(l+r)/2;
        if(has_jam_down(mid,col))
            r=mid;
        else
            l=mid+1;
    }
    return l;
}

void solve(){

    traffic_init(&N,&K);

    int col=find_column();
    int row=find_row(col);

    // ถนนแนวตั้ง
    int ax1=col, ay1=row;
    int ax2=col, ay2=row+1;

    // ถ้า K=1
    if(K==1){
        traffic_report(ax1,ay1,ax2,ay2,0,0,0,0);
        return;
    }

    // ---------- หาเส้นที่สอง ----------
    // trick: query ด้านตรงข้ามเมือง
    // jam อีกเส้นจะยังทำให้ distance เพิ่ม

    int col2=-1,row2=-1;

    for(int x=1;x<=N;x++){
        int d=traffic_query(x,1,x,N);
        if(d>base_dist(x,1,x,N) && x!=col){
            col2=x;
            break;
        }
    }

    for(int y=1;y<=N;y++){
        int d=traffic_query(col2,1,col2,y);
        if(d>base_dist(col2,1,col2,y)){
            row2=y;
            break;
        }
    }

    traffic_report(
        ax1,ay1,ax2,ay2,
        col2,row2,col2,row2+1
    );
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}