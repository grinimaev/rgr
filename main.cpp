#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iterator>
#include"contact.h"
#include"mainMenu.h"
using namespace std;

int main()
{
    setlocale(0,"");
    vector<contact> directory;
    readDirectory(&directory);
    mainMenu(&directory);
    saveDirectory(directory);

}
