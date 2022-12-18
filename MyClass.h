#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "funcs.h"

using std::string;
using std::to_string;
using std::rand;
using std::srand;
using std::time;

class Pass{
public:
    virtual string GenPass()=0;
};
class MiemPass:public Pass{
    public:
        string GenPass() override;
        MiemPass(int gender,int day,int month,int year);
        void GetInfo();
    protected:
        int day;
        int month;
        int year;
        int gender;
        int c;
        string pass;
};
class SauronPass:public Pass{
    public:
        string GenPass() override;
        SauronPass(int gender,int day,int month,int year);
    protected:
        int day;
        int month;
        int year;
        int gender;
        int c;
        string pass;
};
class Admin{
public:
    Admin();
    Admin(int access);
    string GivePassCard(Pass&procedure);
private :
    int accessLevel;
};
