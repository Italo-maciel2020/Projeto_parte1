#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <math.h>

using namespace std;

const int MAX = 30;
const int SMAX = 20;

//Construtor da classe
Sculptor::Sculptor(int _nx, int _ny, int _nz){

int i,j,k;

v = new Voxel**[nx];
for(i=0;i<_nx;i++){
   v[i] = new Voxel*[ny];
    for(j=0;j<_ny;j++){                                            //Aloca a matriz 3D (Voxel);
       v[i][j] = new Voxel[nz];
    }
}

}

//Destrutor da classe
Sculptor::~Sculptor(){
    int i,j;
    Voxel ***v;
    for(i=0;i<nx;i++){
     for(j=0;j<ny;j++){
         delete[] v[i][j];
    }
     delete[] v[i];
    }
    delete [] v;
 cout << "Encerrado." << endl;
}

// Construtor com argumentos - Recebe as dimensões do Voxel e as coordenadas do mesmo.
void Sculptor::setColor(float r, float g, float b, float alpha){
    int i,j,k;
    for(i=0;i<nx;i++){
        for(j=0;j<ny;j++){
            for(k=0;k<nz;k++){
               v[i][j][k].r=r;
               v[i][j][k].g=g;
               v[i][j][k].b=b;
               v[i][j][k].a=alpha;  // Chamada da função da classe Sculptor,inserir cor na matriz 3D.
            }
        }
    }
}

void Sculptor::putVoxel(int x, int y, int z)
{
    int i,j,k;
    for(i=0; i<=x; i++){
       for(j=0; j<=y; j++){
          for(k=0; k<=z; k++){
             v[x][y][z].isOn = true;
             v[x][y][z].r=r;
             v[x][y][z].g=g;
             v[x][y][z].b=b;
             v[x][y][z].a=a;
          }
       }
    }
}

void Sculptor::cutVoxel(int x, int y, int z){
    int i, j, k;
    for(i=0; i<=x; i++){
       for(j=0; j<=y; j++){
          for(k=0; k<=z; k++){
             v[i][j][k].r=r;
             v[i][j][k].g=g;
             v[i][j][k].b=b;
             v[i][j][k].a=a;
             v[i][j][k].isOn = false;
          }
       }
    }
 }

//Ativa vários vóxels dentro dos intervalos
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
   int x, y, z;
   for(x=x0; x<=x1; x++){
      for(y=y0; y<=y1; y++){
         for(z=z0; z<=z1; z++){
            v[x][y][z].isOn = true;
            v[x][y][z].r;
            v[x][y][z].g;
            v[x][y][z].b;
            v[x][y][z].a;
         }
      }
   }
   
}

//Desativa vários vóxels dentro do intervalo
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
   int i, j, k;
   for(i=x0; i<=x1; i++){
      for(j=y0; j<=y1; j++){
         for(k=z0; k<=z1; k++){
            v[i][j][k].r;
            v[i][j][k].g;
            v[i][j][k].b; 
            v[i][j][k].a;
            v[i][j][k].isOn = false;
         }
      }
   }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int i=0; i< xcenter; i++){
        for(int j=0; j< ycenter; j++){
            for(int k=0; k< zcenter; k++){
                //equacao da esfera
                if (((i-xcenter)*(i-xcenter)) + ((j-ycenter)*(j-ycenter)) + ((k-zcenter)*(k-zcenter)) <= ((radius)*(radius))){
                    v[i][j][k].isOn = true;
                    v[i][j][k].r;
                    v[i][j][k].g;
                    v[i][j][k].b;
                    v[i][j][k].a;
                }
            }
        }
    }        
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
   for(int i=0; i< xcenter; i++){
           for(int j=0; j< ycenter; j++){
               for(int k=0; k< zcenter; k++){
                   //equacao da esfera
                   if (((i-xcenter)*(i-xcenter)) + ((j-ycenter)*(j-ycenter)) + ((k-zcenter)*(k-zcenter)) <= ((radius)*(radius))){
                       v[i][j][k].isOn = true;
                       v[i][j][k].r;
                       v[i][j][k].g;
                       v[i][j][k].b;
                       v[i][j][k].a;
                   }
               }
           }
       }
   }


void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
   for(int i=0; i< xcenter; i++){
        for(int j=0; j< ycenter; j++){
            for(int k=0; k< zcenter; k++){
                //equacao da esfera
                if ((((i-xcenter)*(i-xcenter))/((float)((rx)*(rx)))) + ((((j-ycenter)*(j-ycenter)))/((float)((ry)*(ry)))) + ((((k-zcenter)*(k-zcenter)))/((float)((rz)*(rz)))) <=1.0){
                    v[i][j][k].isOn = true;
                    v[i][j][k].r;
                    v[i][j][k].g;
                    v[i][j][k].b;
                    v[i][j][k].a;
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int i=0; i< xcenter; i++){
        for(int j=0; j< ycenter; j++){
            for(int k=0; k< zcenter; k++){
                //equacao da esfera
                if ((((i-xcenter)*(i-xcenter))/((float)((rx)*(rx)))) + ((((j-ycenter)*(j-ycenter)))/((float)((ry)*(ry)))) + ((((k-zcenter)*(k-zcenter)))/((float)((rz)*(rz)))) <=1.0){
                    v[i][j][k].isOn = true;
                    v[i][j][k].r;
                    v[i][j][k].g;
                    v[i][j][k].b;
                    v[i][j][k].a;
                }
            }
        }
    }
}

void Sculptor::writeOFF(char *filename)
{
   int total, index,x,y,z; 
   ofstream arq;
   total = 0;
   arq.open(filename);
   f << "OFF\n";
   
   for(x=0; x<nx; x++){
      for(y-0; y<=ny; y++){
         for(z=0; z<=nz; z++){
            if(v[x][y][z].isOn == true){
               total++;
            }
         }
      }
   }
   f << total * (qnt_vértices) << " " << total * (qtd_faces) << " 0 \n;
    char nome_arq[SMAX],str_off[5]=".OFF";
   for(x=0; x<nx; x++){
      for(y-0; y<=ny; y++){
         for(z=0; z<=nz; z++){
            if(v[x][y][z].isOn == true){
               //aqui dentro vamos escrever os índices dos vértices do cubo
               f << x - lado << " " << y + lado << " " << z - lado << \n" << flush;
            }
         }
      }
   }
   
   for(x=0; x<nx; x++){
      for(y-0; y<=ny; y++){
         for(z=0; z<=nz; z++){
            if(v[x][y][z].isOn == true){
               //aqui escrevemos os índices das faces, pulando vértices de 8 em 8
               index = total*8;
            }
         }
      }
   }

    cout << "Insira o nome para o arquivo." << endl;
    cin.getline(nome_arq,SMAX);
    strcat(nome_arq,str_off);
    arq.open(nome_arq);
   
   arq.close;
}
