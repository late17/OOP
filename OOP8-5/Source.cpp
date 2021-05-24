#include <iostream>
#include<cstring> 
using namespace std;
const int N = 52;
static int sizeofarray;


class TicketStrategy
{
public:
	virtual ~TicketStrategy(){}
    virtual string maketype(int num)=0;
};

class PlazkartWay: public TicketStrategy
{
public:
    string maketype(int num) {
        if (num < 1 || num>52) {
            cout << "Wrong num for 'Plazkart'" << endl;
            exit(0);
        }
        string type;
        type = "Plazkart";
        if (num % 2 == 1) {
            type += " low";
        }
        else {
            type += " high";
        }
        if (num > 36) {
            type += " side";
        }
        else {
            type += " inner";
            if (num % 4 < 3) {
                type += " left";
            }
            else {
                type += " right";
            }
        }
        return type;
    }
};

class LuxWay: public TicketStrategy
{
public:
    string maketype(int num) {
        if (num < 1 || num>18) {
            cout << "Wrong num for 'Lux'" << endl;
            exit(0);
        }
        string type = "Lux";
        if (num % 2 == 1) {
            type += " right";
        }
        else {
            type += " left";
        }
        return type;
    }
};


class Ticket {
protected:
    string type;
    string owner;
    int wagon;
    int num;
    TicketStrategy* strategy;
public:
    void reset(string NewOwner, int NewWagon, int NewNum);
    void reset(Ticket* obj) { strategy = obj->strategy; reset(obj->owner, obj->wagon, obj->num);}
    Ticket() {}
    Ticket(string NewOwner, int NewWagon, int NewNum) { reset(NewOwner, NewWagon, NewNum); }
    Ticket (Ticket* obj){ 
        strategy = obj->strategy;
        reset(obj->owner, obj->wagon, obj->num); type = obj->Type(); 
    }

    string Owner() { return owner; }
    int Wagon() { return wagon; }
    int Num() { return num; }
    string Type() { return type; }

    void print();
    string maketype(int newnum) {
        return strategy->maketype(newnum);
    }

    void setStrategy(TicketStrategy* strategy_){
        strategy = strategy_;
        if (!this->type.empty()) {
            this->type = this->maketype(this->num);
        }
    }
};

void Ticket::reset(string owner, int wagon, int num) {
    this->owner = owner;
    this->num = num;
    this->wagon = wagon;
    this->type = strategy->maketype(num);
}
void Ticket::print() {
    cout << "\nOwner: " << owner;
    printf(", wagon: %d, num: %d, type of place: ", wagon, num);
    cout << type << endl;
}


class Plazkart : public Ticket {
public:
    Plazkart() { setStrategy(new PlazkartWay()); }
    Plazkart(string owner, int wagon, int num) { 
        setStrategy(new PlazkartWay());
        reset(owner, wagon, num);  
    }
    ~Plazkart() {}
};

class Lux : public Ticket {
public:
    Lux() { setStrategy(new LuxWay()); }
    Lux(string owner, int wagon, int num) {
        setStrategy(new LuxWay());
        reset(owner, wagon, num);
    }
    ~Lux() {}
};




static Ticket* tickets = new Ticket[N];


//getting tickets data
void EnterTickets() {
    string owner;
    char type;
    int wagon, num;
    cout << "Enter amount passengers (at most 52): ";
    cin >> sizeofarray;
    for (int i = 0; i < sizeofarray; i++) {
        cout << "Enter a name: ";
        cin >> owner;
        cout << "Type a wagon: ";
        cin >> wagon;
        cout << "Type a num: ";
        cin >> num;
        cout << "Enter the type lukc/plazkart (l/p): ";
        cin >> type;
        if (type == 'p') {
            Plazkart l(owner, wagon, num);
            tickets[i] = &l;
        }
        else if (type == 'l') {
            Lux l(owner, wagon, num);
            tickets[i] = &l;
        }
        else {
            cout << "Wrong entered type";
            exit(1);
        }
    }
}


void PrintTickets() {
    for (int i = 0; i < sizeofarray; i++) {
        tickets[i].print();
    }
}

void InsertionSort() {
    int j;
    Ticket key;
    for (int i = 1; i < sizeofarray; i++) {
        key.reset(&tickets[i]);
        j = i;
        while (j > 0 && key.Owner() < tickets[j - 1].Owner()) {
            tickets[j].reset(&tickets[j - 1]);
            j--;
        }
        tickets[j].reset(&key);
    }
}



int main() {
    EnterTickets();
    InsertionSort();
    tickets[0].print();
    tickets[0].setStrategy(new LuxWay);
    tickets[0].print();
    printf("\n\nAll Tickets:");
    PrintTickets();
    return 0;
}
/*
5
Sherlock
1
43
p
Kosa
1
12
l
Kish
1
50
p
Rolia
1
5
l
Asdf
1
2
p
*/

/*
1
Whatson
2
67
p
*/