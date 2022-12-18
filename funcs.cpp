#include "funcs.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fstream;
using std::ifstream;

int StrToNum(char num){
    if (num=='0')return 0;
    else if (num=='1')return 1;
    else if (num=='2')return 2;
    else if (num=='3')return 3;
    else if (num=='4')return 4;
    else if (num=='5')return 5;
    else if (num=='6')return 6;
    else if (num=='7')return 7;
    else if (num=='8')return 8;
    else if (num=='9')return 9;
}

void CharMassToString( int len , char*mass[],string*answer){

    for(int i=0;i<len;i++){
        answer[i]=string(mass[i]);
    }
}

bool IsInMass( string * arr, string searched,const int length){
    for (int i=0;i<length;i++){
        if(searched==arr[i]) return true;
    }
    return false;
}

bool SetRej( int length, string *data,string &input, string &output,int &RejInput,int &RejOutput){
    enum sourceFrom{
        Unstated,
        File,
        Console
    };

    int lenFlags=4;
    string flags[lenFlags]={"--tofile","--fromfile","--toconsole","--fromconsole"};
    setlocale(LC_ALL, "Russian");
        if (length==1){
            //cout<<"Критическая ошибка: отсутствуют флаги\n";
            return true;
        }
        else{
            int nextInput=0,nextOutput=0;
            for (int i=0;i<length;i++){
                //cout<<"Обрабатываем"<<data[i];
                if(nextInput){
                        input=data[i];
                        nextInput=0;
                        continue;
                }
                else if(nextOutput){
                        output=data[i];
                        nextOutput=0;
                        continue;
                }
                else if (IsInMass(flags,data[i],lenFlags)) {
                    if (data[i]==flags[0]){
                        nextOutput=1;
                        RejOutput=sourceFrom::File;
                    }
                    else if(data[i]==flags[1]){
                        nextInput=1;
                        RejInput=sourceFrom::File;
                    }
                    else if(data[i]==flags[2]){
                        RejOutput=sourceFrom::Console;
                    }
                    else if(data[i]==flags[3]){
                        RejInput=sourceFrom::Console;
                    }
                }
        }
        return false;
    }
}

string readFromFile(string name){
    ifstream file;
    file.open(name);
    if (!file.is_open())return "Error";
    string data;
    getline(file,data);
    file.close();
    return data;
}

void squeezeData(string data,int&gender,int&day,int&month,int&year){
    if (((data[0])=='m')||((data[0])=='M')){
            gender=8;
    }
    else {
            gender=4;
    }
    int dots=0;
    day=0;
    month=0;
    year=0;
    for(int i=2;i<12;i++){
        switch(dots){
        case 0:
            if ((data[i])=='.'){
                dots+=1;
                continue;
            }
            day=day*10+StrToNum(data[i]);
            break;
        case 1:
            if ((data[i])=='.'){
                dots+=1;
                continue;
            }
            month=month*10+StrToNum(data[i]);
            break;
        case 2:
            year=year*10+StrToNum(data[i]);
            break;
        }
    }
};
int SumStrKrat(string data,int lenData){
    int answer=0;
    for (int i=0;i<lenData;i++){
        answer+=StrToNum(data[i])*(i+1);
    }
    return answer;
}
