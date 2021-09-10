#include <iostream>
#include <fstream>
#include <string>
#include<conio.h>
using namespace std;
class Ticket
{
    string station;
    int price;
    string dt;

public:
    void setDate();
    void getValue();
    void bookTicket();
    void priceChecking();
};
void Ticket::getValue()
{
    ifstream in("ticket.txt");
    cout << "Enter the station name: ";
    cin.ignore();
    getline(cin, station);
    string chk;
    while (in.eof() == 0)
    {
        getline(in, chk);
        if (chk == station)
        {
            in >> price;
            in.close();
            return;
        }
    }
    cout << "Wrong Station name!!\n";
}
void Ticket::bookTicket()
{
    getValue();
    ofstream out("printTicket.txt");
    int a;
    cout << "How many: ";
    cin >> a;
    out << "\t\t\tFROM DUM DUM to " << station << endl
        << "\t\t\ton date " << dt << endl
        << "\t\t\t\t"<< a<<" Adults\n\n\n \t\t\t\ttotal price " << a * price << endl;
    cout << "\t\t\tcollect price: " << a * price << endl;
    cout << "::::::::Ticket Ready print it:::::::\n";
    out.close();
}
void Ticket::setDate()
{
    cout << "Set Date: ";
    cin.ignore();
    cin >> dt;
}
void Ticket::priceChecking()
{
    getValue();
    cout << "::::::Price for " << station << " is " << price << endl;
}
int main()
{
    Ticket tk;
    cout << "\t\t\tMenus\n1:::::SetDate\n2:::::priceChecking\n3:::::bookTicket\n4:::::Exit\n\n\n";
    while(true){
        cout << "\t\t\t\tmake choice:: ";
        int n;cin >> n;
        if(n == 1)
            tk.setDate();
        if(n == 2)
            tk.priceChecking();
        if(n == 3)
            tk.bookTicket();
        if(n == 4)
            exit(1);
    }
    return 0;
}