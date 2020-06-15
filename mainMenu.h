#ifndef MAINMENU_H_INCLUDED
#define MAINMENU_H_INCLUDED

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iterator>
#include"contact.h"
using namespace std;

void saveDirectory(const vector<contact> directory)
{
    ofstream fout("directory.txt", ios_base::trunc);
    for(int i=0; i<directory.size(); i++)
    {
        fout<<directory[i];
    }
    fout.close();
}

void readDirectory(vector<contact> *directory)
{
    vector<contact> temp;
    contact tmp;
    ifstream fin ("directory.txt");
    while(!fin.eof())
    {

        fin>>tmp;
        if(fin.eof()) break;
        temp.push_back(tmp);
    }
    directory->clear();
    if(!temp.empty())directory->insert(directory->begin(), temp.begin(), temp.end());
    fin.close();
}

bool ShowAll(vector<contact> *directory)
{
    if (directory->size()==0) return false;
    else
    {
        for(int i=0; i<directory->size(); i++)
        {
            cout<<"������� �"<<i+1<<endl;
            directory->at(i).get_contact();
            cout<<endl;
        }
        return true;
    }
}

void OpenContact(vector<contact> *directory)
{
    int n,ans;
    string tmp;
    vector<contact>::iterator it;
    while(1)
    {
        if(!ShowAll(directory))
        {
            cout<<"��������� ���.\n";
            system("pause");
            goto p2;
        }
        else
        {
            cout<<"������� ����� ��������: ";
            cin>>n;
            if((n>directory->size())||(n<1))
            {
                cout<<"\n������ �������� �� ����������.\n";
                system("pause");
                system("cls");
            }
            else
            {
                n--;
                while(1)
                {
                    system("cls");
                    directory->at(n).get_contact();
                    cout<<"�������� ��������:\n\n";
                    cout<<"1 � �������� �����\n";
                    cout<<"2 � �������� ���.\n";
                    cout<<"3 � �������� �����������.\n";
                    cout<<"4 � ������� �������.\n";
                    cout<<"0 � ��������� � ������� ����.\n";
                    cout<<"��������:";
                    cin>>ans;
                    switch(ans)
                    {
                    case 0:
                        goto p2;
                    case 1:
                        system("cls");
                        cout<<"������� ����� �����: ";
                        cin>>tmp;
                        directory->at(n).set_number(tmp);
                        system("cls");
                        cout<<"�����������!\n";
                        system("pause");
                        break;
                    case 2:
                        system("cls");
                        cout<<"������� ����� ���: ";
                        cin>>tmp;
                        directory->at(n).set_name(tmp);
                        system("cls");
                        cout<<"�����������!\n";
                        system("pause");
                        break;
                    case 3:
                        system("cls");
                        cout<<"������� ����� �����������: ";
                        cin>>tmp;
                        directory->at(n).set_organization(tmp);
                        system("cls");
                        cout<<"�����������!\n";
                        system("pause");
                        break;
                    case 4:
                        it=directory->begin()+n;
                        directory->erase(it);
                        system("cls");
                        cout<<"������� �����!";
                        system("pause");
                        goto p2;
                    default:
                        system("cls");
                        cout<<"�������� ����.\n";
                        system("pause");
                        system("cls");
                    }
                }
            }
        }
    }
p2:
    {}
}

void AddContact(vector<contact> *directory)
{
    contact temp;
    temp.set_contact();
    directory->push_back(temp);
    system("cls");
}

void SearchingContacts (vector<contact> *directory)
{
    int ans,i,count;
    string tmp;
    if (directory->empty())
    {
        system("cls");
        cout<<"��������� ���\n";
        system("pause");
        return;
    }
    while(1)
    {
        system("cls");
        cout<<"����� ���������:\n\n";
        cout<<"1 � �� ������\n";
        cout<<"2 � �� �����.\n";
        cout<<"3 � �� �����������.\n";
        cout<<"0 � ��������� � ������� ����.\n";
        cout<<"��������:";
        cin>>ans;
        count=0;
        switch(ans)
        {
        case 0:
            system("cls");
            return;
        case 1:
            system("cls");
            cout<<"������� �����: ";
            cin>>tmp;
            for(i=0; i<directory->size(); i++)
            {
                if(tmp==(directory->at(i).get_number().substr(0,tmp.length())))
                {
                    cout<<"������� �"<<i+1<<endl;
                    directory->at(i).get_contact();
                    cout<<endl;
                    count++;
                }

            }
            if (count==0)
            {
                system("cls");
                cout<<"�� �������!\n";
                system("pause");
            }
            else system("pause");
            break;
        case 2:
            system("cls");
            cout<<"������� ���: ";
            cin>>tmp;
            for(i=0; i<directory->size(); i++)
            {
                if(tmp==(directory->at(i).get_name().substr(0,tmp.length())))
                {
                    cout<<"������� �"<<i+1<<endl;
                    directory->at(i).get_contact();
                    cout<<endl;
                    count++;
                }

            }
            if (count==0)
            {
                system("cls");
                cout<<"�� �������!\n";
                system("pause");
            }
            else system("pause");
            break;
        case 3:
            system("cls");
            cout<<"������� �����������: ";
            cin>>tmp;
            for(i=0; i<directory->size(); i++)
            {
                if(tmp==(directory->at(i).get_organization().substr(0,tmp.length())))
                {
                    cout<<"������� �"<<i+1<<endl;
                    directory->at(i).get_contact();
                    cout<<endl;
                    count++;
                }

            }
            if (count==0)
            {
                system("cls");
                cout<<"�� �������!\n";
                system("pause");
            }
            else system("pause");
            break;

        }
    }
}

void mainMenu(vector<contact> *directory)
{
    while(1)
    {
        int ans;
        cout<<"������� ����\n\n";
        cout<<"1 � �������� ��� ��������.\n";
        cout<<"2 � ������� �������.\n";
        cout<<"3 � ����� ���������.\n";
        cout<<"4 � ����� �������.\n";
        cout<<"5 � ������� ��� ��������.\n";
        cout<<"0 � ������� ���������.\n";
        cout<<"��������: ";
        cin>>ans;
        switch(ans)
        {
        case 0:
            system("cls");
            cout<<"��������...";
            goto p;
        case 1:
            system("cls");
            if(!ShowAll(directory)) cout<<"��������� ���.\n";
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            OpenContact(directory);
            system("cls");
            break;
        case 3:
            system("cls");
            SearchingContacts(directory);
            system("cls");
            break;
        case 4:
            system("cls");
            AddContact(directory);
            break;
        case 5:
            system("cls");
            directory->clear();
            cout<<"�������� �������!\n";
            system("pause");
            system("cls");
            break;
        default:
            system("cls");
            cout<<"�������� ����.\n";
            system("pause");
            system("cls");
        }
    }
p:
    {}
}

#endif // MAINMENU_H_INCLUDED
