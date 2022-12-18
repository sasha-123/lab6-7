#include <string>
#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void CharMassToString( int, char*[],string*);
bool SetRej(int,string*,string&,string&,int &,int &);
bool IsInMass(string&,string,int);
string readFromFile(string);
void squeezeData(string,int&,int&,int&,int&);
int StrToNum(char);
int SumStrKrat(string,int );
