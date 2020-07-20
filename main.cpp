#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#define dim 90
using namespace std;
string stombola=  "\t+++++++++\n\t+TOMBOLA+\t\n\t+++++++++\n\n";
int num[dim];
string suff= "Estrarre?\n";
string tombolone[3][3][2][5];
bool ambo=false,terno=false,quaterna=false,cinquina=false,tombola=false;
int ran,n=0,a=1;
string caract="+ ";
void punti(int i,int x){
    int c=0;
    for(int j=0;j<3;j++)
    for(int y=0;y<5;y++){
        if(tombolone[i][j][x][y]!=caract){
            c++;
            for(int z=0;z<5;z++){
                if(z==y)
                    continue;
                else if(tombolone[i][j][x][z]!=caract)
                    c++;
            }
        }else
            c=0;
        if(c==2&&ambo==false){
            suff="AMBO\n"+suff;
            ambo=true;
            c=0;
        }
        if(c==3&&terno==false){
            suff="TERNO\n"+suff;
            terno=true;
            c=0;
        }
        if(c==4&&quaterna==false){
            suff="QUATERNA\n"+suff;
            quaterna=true;
            c=0;
        }
        if(c==5&&cinquina==false){
            suff="CINQUINA\n"+suff;
            cinquina=true;
            c=0;
        }
        c=0;
    }
    for(int j=0;j<3;j++)
    for(int y=0;y<5;y++){
        if(tombolone[i][j][x][y]!=caract){
            c++;
            if(c==15){
                suff="TOMBOLA\n"+suff;
                tombola=true;
            }
        }else
            c=0;
    }
}

void print_tombola(){
    for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
    for(int x=0;x<2;x++){
    for(int y=0;y<5;y++){
        cout <<tombolone[i][j][x][y]<<" ";
    }
        cout << "\t";
    }
        cout << endl;
    }
        cout << endl;
    }
}
int main(){

    srand((unsigned)time(0));
    system("color d0");
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    for(int x=0;x<2;x++)
    for(int y=0;y<5;y++)
        tombolone[i][j][x][y]=caract;

    while(n<dim){
        if(tombola==true){break;}
        cout << stombola;
        print_tombola();
        cout << "Estratto >> "<<ran<<endl;
        cout << suff;
        getchar();
        system("cls");

            ran=(rand()%dim)+1;
            for(int i=0;i<dim;i++)
                if(ran==num[i]){
                    i=-1;
                    ran=(rand()%dim)+1;
                }

            for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
            for(int x=0;x<2;x++)
            for(int y=0;y<5;y++){
                if(a==ran)
                    if(ran<10)
                        tombolone[i][j][x][y]=to_string(ran)+" ";
                    else
                        tombolone[i][j][x][y]=to_string(ran);
            a++;
                        }
            for(int x=0;x<2;x++)
            for(int i=0;i<3;i++)
                punti(i,x);

            a=1;
            num[n]=ran;
            n++;
    }

    cout << stombola;
    print_tombola();
    cout << suff;
    system("pause");
}
