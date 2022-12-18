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
    //���� ������ ������
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
        cout<<"����������� ������ : ���������� ������";
        return 0;
    }
    //���� ������ ������
    //���� ������ ������
    string passData;
    if (RejInput==Unstated || RejOutput==Unstated){
        cout<<"����������� ������ : �� ������ ����� �����/������"<<endl;
        return 0;
    }
    if(RejInput==sourceFrom::Console){
        getline(cin,passData);
    }
    else if(RejInput==sourceFrom::File){
        passData=readFromFile(input);
        if (passData=="Error"){
            cout<<"����������� ������ : �� ������� ������� ���� ��� ������"<<endl;
            return 0;
        }
    }
    //cout<<passData<<endl;
    int gender=0,day=0,month=0,year=0;
    squeezeData(passData,gender,day,month,year);
    //cout<<gender<<"\n"<<day<<"\n"<<month<<"\n"<<year<<"\n";
    //cout<<output<<" "<<input<<" "<<RejOutput<<" "<<RejInput<<endl;
    //���� ������ ������

    //���� ��������� ��������
    SauronPass pass1(gender,day,month,year);
    MiemPass pass2(gender,day,month,year);
    Admin head(1);
    string saruman=head.GivePassCard(pass1);
    string miem=head.GivePassCard(pass2);
    //���� ��������� ��������

    //���� ���������
    if (RejOutput==Console){
        cout<<"��� ������� � ����: "<<miem<<endl;
        cout<<"��� ������� � ������� ��. ��������: "<<saruman<<endl;
    }
    else if(RejOutput==File){
        ofstream fout;
        //cout<<endl;
        //ofstream fout;
        //cout<<output<<endl;
        fout.open(output);
        if(!fout.is_open()){
            cout<<"����������� ������: �� ������� ������� ���� ��� ������"<<endl;
        }
        else {
                fout<<"��� ������� � ����: "<<miem<<endl;
                fout<<"��� ������� � ������� ��. ��������: "<<saruman<<endl;
                cout<<"������ ��������"<<"\n";
        }
        fout.close();
    }
    else cout<<"����������� ������ : �� ������ ����� �����/������";
    //���� ���������
    return 0;
}
