#include<bits/stdc++.h>
using namespace std;


int N = 64;
int matriz[64][64];
vector<vector<int> > cropped;

void crop(){
    int top=65, bottom=-1, left=64, right=-1;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            if(matriz[i][j]==1){
                top = min(top, i);
                bottom = max(bottom, i);
                left = min(left, j);
                right = max(right, j);
            }
        }
    }
    int h = right-left+1;
    int v = bottom-top+1;

    cropped.resize(v);
    for (int i = 0; i < v; ++i){
        cropped[i].resize(h);
    }
    for (int i = top; i < bottom+1; ++i){
        for (int j = left; j < right+1; ++j){
            cropped[i-top][j-left] = matriz[i][j];
        }
    }
}

void print_cropped(){
    for (int i = 0; i < cropped.size(); ++i){
        for (int j = 0; j < cropped[i].size(); ++j){
            cout << cropped[i][j];
        }
        cout << endl;
    }
}

void print(){
    for (int i = 0; i < 64 ; ++i){
        for (int j = 0; j < 64; ++j){
            cout << matriz[i][j];
        }
        cout << endl;
    }
}

int _count_cropped(int f1, int c1, int f2, int c2){
    int count = 0;
    for (int i = f1; i < f2+1; ++i)
        for (int j = c1; j < c2+1; ++j)
            if(cropped[i][j]==1)
                count++;
    return count;
}

int count_cropped(){
    return _count_cropped(0,0, cropped.size()-1, cropped[0].size()-1);
}


bool arriba_y_medio(int x){
    int m = cropped[0].size()/2;
    int c = _count_cropped(0,m-3,cropped.size()/3,m+3);
    return c > x;
}

bool arriba_y_izquierda(int x){
    int c = _count_cropped(0,0,cropped.size()/3,cropped.size()/3);
    return c > x;
}

bool arriba_y_derecha(int x){
    int c = _count_cropped(0,cropped.size()/3*2,cropped.size()/3,cropped.size()-1);
    return c > x;
}

bool medio_y_medio(int x){
    int m = cropped[0].size()/2;
    int c = _count_cropped(m-8,m-8,m+7,m+7);
    return c > x;
}

bool abajo_y_medio(int x){
    int m = cropped[0].size()/2;
    int c = _count_cropped(cropped.size()/3*2,m-3,cropped.size()-1,m+3);
    return c > x;
}

bool abajo_y_izquierda(int x){
    int c = _count_cropped(cropped.size()-10,0,cropped.size()-1,10);
    return c > x;
}

bool abajo_y_derecha(int x){
    int c = _count_cropped(cropped.size()-10,cropped[0].size()-10,cropped.size()-1,cropped[0].size()-1);
    return c > x;
}


bool casi_medio_y_izquierda(int x){
    int m = cropped.size()/2;
    int c = _count_cropped(m-7,0,m,cropped[0].size()/3);
    return c > x;
}

bool casi_medio_y_derecha(int x){
    int m = cropped.size()/2;
    int c = _count_cropped(m,cropped[0].size()/3*2,m+7,cropped[0].size()-1);
    return c > x;
}


int swaps(){
    int m = cropped.size()/2;
    int color = cropped[0][0];
    int s=0;
    for (int i = 0; i < cropped[0].size(); ++i){
        if(cropped[m][i]!=color){
            s++;
            color=cropped[m][i];
        }
    }
    return s;
}

void pintar(int x, int y){
    if(x<0 || 63<x || y<0 || 63<y){
        
    } else {
        if(matriz[x][y]==0){
            matriz[x][y]=2;

            pintar(x-1,y-1);
            pintar(x,y-1);
            pintar(x+1,y-1);

            pintar(x-1,y);
            pintar(x+1,y);

            pintar(x-1,y+1);
            pintar(x,y+1);
            pintar(x+1,y+1);
        }
    }
}

pair<int,int> find_zero(){
    for (int i = 0; i < 64; ++i){
        for (int j = 0; j < 64; ++j){
            if(matriz[i][j]==0){
                return make_pair(i,j);
            }
        }
    }
    return make_pair(-1,-1);
}

vector<pair<int, int> > count_zeros(){
    vector<pair<int, int> > zeros;
    int count = 0;
    for(;;){
        pair<int,int> find = find_zero();
        if(find.first==-1 && find.second==-1)
            break;
        count++;
        zeros.push_back(find);
        pintar(find.first, find.second);
    }
    return zeros;
}

bool check_0(){
    return cropped.size() < 16;
}

bool check_1(){
    return cropped[0].size() < 16;
}

bool check_2(){
    return !arriba_y_medio(5) && abajo_y_medio(16);
}

bool check_3(){
    return !abajo_y_medio(5) && arriba_y_medio(16);
}

bool check_4(){
    return !casi_medio_y_izquierda(5) && !casi_medio_y_derecha(5);
}

bool check_6(){
    return !medio_y_medio(0) && abajo_y_medio(16) && casi_medio_y_izquierda(16) && casi_medio_y_derecha(16);
}

bool check_7(){
    int c = swaps();
    return c > 5;
}



int main(){
    
    int x;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            cin >> matriz[i][j];
        }
    }

    for (int i = 0; i < 64; ++i){
        pintar(0,i);
        pintar(63,i);
        pintar(i,0);
        pintar(i,63);
    }

    vector<pair<int, int> > zeros = count_zeros();
    if(zeros.size()==1){
        cout << 5 << endl;
    } else if(zeros.size()==2){
        pair<int, int> uno = zeros[0];
        pair<int, int> dos = zeros[1];
        if (abs(uno.first - dos.first) < 10){
            cout << 8 << endl;
        } else {
            cout << 9 << endl;
        }
    } else {
        crop();
        if(check_0())
            cout << 0 << endl;
        else if(check_1())
            cout << 1 << endl;
        else if(check_7())
            cout << 7 << endl;
        else if(check_6())
            cout << 6 << endl;
        else if(check_2())
            cout << 2 << endl;
        else if(check_3())
            cout << 3 << endl;
        else if(check_4())
            cout << 4 << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}
