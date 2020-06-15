#ifndef CONTACT_H_INCLUDED
#define CONTACT_H_INCLUDED

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

class contact
{
private:
    string number;
    string name;
    string organization;
public:
    contact():contact("NoNumber","NoName","NoOrganization") {}
    contact(const string number, const string name, const string organization)
    {
        set_number(number);
        set_name(name);
        set_organization(organization);
    }
    void set_number(const string number)
    {
        this->number=number;
    }
    void set_name(const string name)
    {
        this->name=name;
    }
    void set_organization(const string organization)
    {
        this->organization=organization;
    }
    const string get_number() const
    {
        return number;
    }
    const string get_name() const
    {
        return name;
    }
    const string get_organization() const
    {
        return organization;
    }
    void set_contact()
    {
        string tmp;
        cout<<"Введите номер: ";
        cin>>tmp;
        set_number(tmp);
        cout<<"Введите имя: ";
        cin>>tmp;
        set_name(tmp);
        cout<<"Введите организацию: ";
        cin>>tmp;
        set_organization(tmp);
    }
    void get_contact()
    {
        cout<<"Номер: "<<get_number();
        cout<<"\nИмя: "<<get_name();
        cout<<"\nОрганизация: "<<get_organization()<<endl;
    }
    friend std::ostream& operator<< (std::ostream &out1, const contact &_contact)
    {
        return out1<<_contact.get_number()<<endl<<_contact.get_name()<<endl<<_contact.get_organization()<<endl;
    }
    friend std::istream& operator>> (std::istream &in1, contact &_contact)
    {
        string temp;
        in1>>temp;
        _contact.set_number(temp);
        in1>>temp;
        _contact.set_name(temp);
        in1>>temp;
        _contact.set_organization(temp);
        return in1;
    }

};


#endif // CONTACT_H_INCLUDED
