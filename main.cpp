#include <iostream>
#include <string>
#include <list>
#include "HashTbls.h"
#include "hashint.h"
#include "volunteer.h"
#include "client.h"
#include "HashClient.h"
#include "HashVolunteer.h"
using namespace std;

int main()
{
    HashTbls<hashint,int> table(3);
    table.print();
    table.HashInsert(hashint,6);
    table.HashInsert(hashint,2);
    table.HashInsert(hashint,0);
    table.print();
    table.HashSearch(hashint, 6);
    table.HashSearch(hashint, 0);
    table.HashDelete(hashint, 6);
    table.print();



    /*char ch;
    volunteer v;
    client c;
    list<volunteer*> lst;
    HashTbls ht;

    cout << "Hash Tables\n";
    do
    {
        cout << "\nChoose one of the following" << endl;
        cout << "n: New volunteer" << endl;
        cout << "d: Del a volunteer " << endl;
        cout << "c: New client" << endl;
        cout << "l: Add a connection volunteer-client " << endl;
        cout << "*: Print volunteers that helped a client " << endl;
        cout << "i: Print clients that were helped by a voluneer " << endl;
        cin >> ch;
        switch (ch)
        {
            case 'n':cin >> v; ht.addVolunteer(v);  break;
            case 'd':cin >> v.name; ht.delVolunteer(v);  break;
            case 'c': cin >> c; ht.addClient(c); break;
            case 'l': cout << "enter volunteer name and client phone ";  cin >> v.name >> c.phone; ht.addVolunteerToClient(v,c); break;
            case '*': cout << "enter client phone ";  cin >> c.phone; ht.listOfVolunteers(c); break;
            case 'i': cout << "enter volunteer name ";  cin >> v.name; ht.listOfClients(v); break;
            case 'e':cout << "bye "; break;
            default: cout << "Error ";  break;
        }
    } while (ch != 'e');*/

    return 0;
}
