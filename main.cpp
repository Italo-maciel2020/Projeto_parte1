#include <iostream>
#include <fstream>
#include <cstring>
#include "sculptor.h"

using namespace std;

int main()
{
  Sculptor m(2,2,2);
  float r,g,b,a;
  cout << "Insira entre os valores '0' a '1' para transparência da cor e presença da cor no Voxel";
  cin >> r >> g >> b >> a;
  m.setColor(r,g,b,a);
  int xa,ya,za;
  std::cout << "Insira as coordenadas referentes para ativar Voxel." << endl;
  cin >> xa >> ya >> za;
  m.putVoxel(xa,ya,za); // Ativar Voxel na posição determinada
  int xd,yd,zd;
  std::cout << "Insira as coordenadas referentes para desativar Voxel." << endl;
  cin >> xd >> yd >> zd;
  m.cutVoxel(xd,yd,zd); // Desativa Voxel na posição determinada
  return 0;

}
