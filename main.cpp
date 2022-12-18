#include <iostream>
#include <fstream>
#include <string>
#include <ostream>
#include "funcs.h"
#include "MyClass.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::ofstream;

int main(int argc, char* argv[]){
    //блок чтени€ флагов
    enum sourceFrom{
        Unstated,
        File,
        Console
    };
    setlocale(LC_ALL, "Russian");
    string data[argc];
    string input,output;
    int RejInput=sourceFrom::Unstated,RejOutput=sourceFrom::Unstated;

    CharMassToString(argc,argv,data);
    bool EnterError=SetRej(argc,data,input,output,RejInput,RejOutput);
    if(EnterError){
        cout<<" ритическа€ ошибка : отсутствие флагов";
        return 0;
    }
    //блок чтени€ флагов
    //блок чтени€ данных
    string passData;
    if (RejInput==Unstated || RejOutput==Unstated){
        cout<<" ритическа€ ошибка : не указан поток ввода/вывода"<<endl;
        return 0;
    }
    if(RejInput==sourceFrom::Console){
        getline(cin,passData);
    }
    else if(RejInput==sourceFrom::File){
        passData=readFromFile(input);
        if (passData=="Error"){
            cout<<" ритическа€ ошибка : не удалось открыть файл дл€ чтени€"<<endl;
            return 0;
        }
    }
    //cout<<passData<<endl;
    int gender=0,day=0,month=0,year=0;
    squeezeData(passData,gender,day,month,year);
    //cout<<gender<<"\n"<<day<<"\n"<<month<<"\n"<<year<<"\n";
    //cout<<output<<" "<<input<<" "<<RejOutput<<" "<<RejInput<<endl;
    //блок чтени€ данных

    //блок генерации пропуска
    SauronPass pass1(gender,day,month,year);
    MiemPass pass2(gender,day,month,year);
    Admin head(1);
    string saruman=head.GivePassCard(pass1);
    string miem=head.GivePassCard(pass2);
    //блок генерации пропуска

    //блок выведени€
    if (RejOutput==Console){
        cout<<"¬аш пропуск в ћ»Ёћ: "<<miem<<endl;
        cout<<"¬аш пропуск в Ём√э“”” им. —арумана: "<<saruman<<endl;
    }
    else if(RejOutput==File){
        ofstream fout;
        //cout<<endl;
        //ofstream fout;
        //cout<<output<<endl;
        fout.open(output);
        if(!fout.is_open()){
            cout<<" ритическа€ ошибка: не удалось открыть файл дл€ записи"<<endl;
        }
        else {
                fout<<"¬аш пропуск в ћ»Ёћ: "<<miem<<endl;
                fout<<"¬аш пропуск в Ём√э“”” им. —арумана: "<<saruman<<endl;
                cout<<"ƒанные записаны"<<"\n";
        }
        fout.close();
    }
    else cout<<" ритическа€ ошибка : не указан поток ввода/вывода";
    //блок выведени€
    return 0;
}
