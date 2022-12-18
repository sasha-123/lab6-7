#include "MyClass.h"
#include <stdlib.h>
#include <cstdlib>


MiemPass::MiemPass(int gender,int day,int month,int year){
    if (gender==2 || gender==1){
        this->gender=gender*2;
    }
    else{
        this->gender=gender;
    }
    this->day=day;
    this->month=month;
    this->year=year;
    this->c=0;
}
string MiemPass::GenPass(){
    string pass="";
    string strday=day/10==0?"0"+to_string(this->day):to_string(this->day);
    string strmonth=month/10==0?"0"+to_string(this->month):to_string(this->month);
    pass=pass+to_string(this->gender)+to_string(this->year)+strmonth+strday;
    srand(time(NULL));
    int num=rand()%89999 +10000;
    pass+=to_string(num);
    int lennPass=pass.size();
    int summ=SumStrKrat(pass,lennPass);
    int c=0;
    while((summ+(lennPass+1)*c)%11!=0)c++;
    pass+=to_string(c);
    return pass;
}
void MiemPass::GetInfo(){
            std::cout<<"Data in "<<this<<" :"<<this->gender<<" "<<this->day<<" "<<this->month<<" "<<this->year<<" "<<this->c;
}

SauronPass::SauronPass(int gender,int day,int month,int year){
    if (gender==8 || gender==4){
        this->gender=gender/4;
    }
    else{
        this->gender=gender;
    }
    this->day=day;
    this->month=month;
    this->year=year;
    this->c=0;
}
string SauronPass::GenPass(){
    string pass="";
    string strday=day/10==0?"0"+to_string(this->day):to_string(this->day);
    string strmonth=month/10==0?"0"+to_string(this->month):to_string(this->month);
    pass=pass+to_string(this->gender)+to_string(this->year)+strmonth+strday;
    srand(time(NULL));
    int num=rand()%8999 +1000;
    pass+=to_string(num);
    int lennPass=pass.size();
    int summ=SumStrKrat(pass,lennPass);
    int c=0;
    while((summ+(lennPass+1)*c)%10!=0)c++;
    pass+=to_string(c);
    return pass;
}

Admin::Admin(){
    this->accessLevel=0;
}
Admin::Admin(int access){
    this->accessLevel=access;
}
string Admin::GivePassCard(Pass&procedure){
    return procedure.GenPass();
}
