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
            cout<<"Контакт №"<<i+1<<endl;
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
            cout<<"Контактов нет.\n";
            system("pause");
            goto p2;
        }
        else
        {
            cout<<"Введите номер контакта: ";
            cin>>n;
            if((n>directory->size())||(n<1))
            {
                cout<<"\nТакого контакта не существует.\n";
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
                    cout<<"Выберите действие:\n\n";
                    cout<<"1 — Изменить номер\n";
                    cout<<"2 — Изменить имя.\n";
                    cout<<"3 — Изменить организацию.\n";
                    cout<<"4 — Удалить контакт.\n";
                    cout<<"0 — Вернуться в Главное МЕНЮ.\n";
                    cout<<"Выберите:";
                    cin>>ans;
                    switch(ans)
                    {
                    case 0:
                        goto p2;
                    case 1:
                        system("cls");
                        cout<<"Введите новый номер: ";
                        cin>>tmp;
                        directory->at(n).set_number(tmp);
                        system("cls");
                        cout<<"Установлено!\n";
                        system("pause");
                        break;
                    case 2:
                        system("cls");
                        cout<<"Введите новое имя: ";
                        cin>>tmp;
                        directory->at(n).set_name(tmp);
                        system("cls");
                        cout<<"Установлено!\n";
                        system("pause");
                        break;
                    case 3:
                        system("cls");
                        cout<<"Введите новую организацию: ";
                        cin>>tmp;
                        directory->at(n).set_organization(tmp);
                        system("cls");
                        cout<<"Установлено!\n";
                        system("pause");
                        break;
                    case 4:
                        it=directory->begin()+n;
                        directory->erase(it);
                        system("cls");
                        cout<<"Контакт удалён!";
                        system("pause");
                        goto p2;
                    default:
                        system("cls");
                        cout<<"Неверный ввод.\n";
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
        cout<<"Контактов нет\n";
        system("pause");
        return;
    }
    while(1)
    {
        system("cls");
        cout<<"Поиск контактов:\n\n";
        cout<<"1 — по номеру\n";
        cout<<"2 — по имени.\n";
        cout<<"3 — по организации.\n";
        cout<<"0 — Вернуться в Главное МЕНЮ.\n";
        cout<<"Выберите:";
        cin>>ans;
        count=0;
        switch(ans)
        {
        case 0:
            system("cls");
            return;
        case 1:
            system("cls");
            cout<<"Введите номер: ";
            cin>>tmp;
            for(i=0; i<directory->size(); i++)
            {
                if(tmp==(directory->at(i).get_number().substr(0,tmp.length())))
                {
                    cout<<"Контакт №"<<i+1<<endl;
                    directory->at(i).get_contact();
                    cout<<endl;
                    count++;
                }

            }
            if (count==0)
            {
                system("cls");
                cout<<"Не найдено!\n";
                system("pause");
            }
            else system("pause");
            break;
        case 2:
            system("cls");
            cout<<"Введите имя: ";
            cin>>tmp;
            for(i=0; i<directory->size(); i++)
            {
                if(tmp==(directory->at(i).get_name().substr(0,tmp.length())))
                {
                    cout<<"Контакт №"<<i+1<<endl;
                    directory->at(i).get_contact();
                    cout<<endl;
                    count++;
                }

            }
            if (count==0)
            {
                system("cls");
                cout<<"Не найдено!\n";
                system("pause");
            }
            else system("pause");
            break;
        case 3:
            system("cls");
            cout<<"Введите организацию: ";
            cin>>tmp;
            for(i=0; i<directory->size(); i++)
            {
                if(tmp==(directory->at(i).get_organization().substr(0,tmp.length())))
                {
                    cout<<"Контакт №"<<i+1<<endl;
                    directory->at(i).get_contact();
                    cout<<endl;
                    count++;
                }

            }
            if (count==0)
            {
                system("cls");
                cout<<"Не найдено!\n";
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
        cout<<"Главное МЕНЮ\n\n";
        cout<<"1 — Показать все контакты.\n";
        cout<<"2 — Открыть контакт.\n";
        cout<<"3 — Поиск контактов.\n";
        cout<<"4 — Новый контакт.\n";
        cout<<"5 — Удалить все контакты.\n";
        cout<<"0 — Закрыть программу.\n";
        cout<<"Выберите: ";
        cin>>ans;
        switch(ans)
        {
        case 0:
            system("cls");
            cout<<"Закрытие...";
            goto p;
        case 1:
            system("cls");
            if(!ShowAll(directory)) cout<<"Контактов нет.\n";
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
            cout<<"Контакты удалены!\n";
            system("pause");
            system("cls");
            break;
        default:
            system("cls");
            cout<<"Неверный ввод.\n";
            system("pause");
            system("cls");
        }
    }
p:
    {}
}

#endif // MAINMENU_H_INCLUDED
