#include<iostream>
#include<iomanip>
#include"Spannungsteiler.h"
using namespace std;

int main(void){

  Spannungsteiler st = Spannungsteiler();
  st.setSerie(Spannungsteiler::E6);
  st.setCur(0.4);
  st.setVol1(12.0);
  st.setVol2(10);
  st.doCalc();
  cout<<fixed << setprecision(1) << "Resistor1: " << st.getRes1() << endl;
  cout<<fixed << setprecision(1) <<"Resistor2: " << st.getRes2() << endl;
  return 0;
}
