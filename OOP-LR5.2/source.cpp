#include <iostream>
#include<time.h>
#include <cmath>
#include<cstring> 
using namespace std; 
const int N=52;
static int sizeofarray;

class Ticket {  
  protected:
    string type;
    string owner;
    int wagon;   
    int num;
  public:
    Ticket(){}
    virtual ~Ticket(){}
    string Owner(){return owner;}
    int Wagon(){return wagon;}
    int Num(){return num;}
    string Type(){return type;}
    Ticket(Ticket* obj){reset(obj->Owner(), obj->Wagon(), obj->Num()); type = obj->Type();}
    Ticket(string owner, int wagon, int num){reset(owner, wagon, num);}
    virtual void maketype(int num){type = "???";};
    void print();
    void reset(string owner, int wagon, int num);
    void reset(Ticket* obj){reset(obj->owner, obj->wagon, obj->num); type = obj->Type();}
};
void Ticket::reset(string owner, int wagon, int num){
    this->owner=owner;
    this->num= num;
    this->wagon = wagon;
}
void Ticket::print(){
  cout << "\nOwner: " << owner;
  printf(", wagon: %d, num: %d, type of place: ", wagon,num);
  cout << type <<endl;
}

class Plazkart : public Ticket{
   public:
    ~Plazkart(){}
    void checknum(int num);
    virtual void maketype(int num);
    Plazkart(string owner, int wagon, int num):Ticket(owner, wagon, num){checknum(num); maketype(num);} 
    Plazkart(Ticket* obj):Ticket(obj->Owner(), obj->Wagon(), obj->Num()){checknum(num); maketype(num);}
};
void Plazkart::checknum(int num){
    if (num<1||num>52){
        cout<<"Wrong num for 'Plazkart'"<<endl;
        exit(0);
    }
}
void Plazkart::maketype(int num){
  this->type = "Plazkart";
  if (num%2==1){
    type += " low";
  } else {
    type += " high";
  }
  if (num>36){
    type += " side";
  } else {
    type += " inner";
    if (num%4<3){
      type += " left";
    } else{
      type += " right";
    }
  }
}

class Lux : public Ticket{
   public:
    ~Lux(){}
    void checknum(int num);
    virtual void maketype(int num);
    Lux(string owner, int wagon, int num):Ticket(owner, wagon, num){checknum(num); maketype(num);} 
    Lux(Ticket* obj):Ticket(obj->Owner(), obj->Wagon(), obj->Num()){checknum(num); maketype(num);}
};
void Lux::checknum(int num){
    if (num<1||num>18){
        cout<<"Wrong num for 'Lux'"<<endl;
        exit(0);
    }
}
void Lux::maketype(int num){
  this->type = "Lux";
  if (num%2==1){
    type += " right";
  } else {
    type += " left";
  }
}





static Ticket* tickets = new Ticket[N];


//getting tickets data
void EnterTickets(){
  string owner;
  char type;
  int wagon, num;
  cout << "Enter amount passengers (at most 52): ";
  cin >> sizeofarray;
  for (int i=0; i<sizeofarray;i++){
    cout << "Enter a name: ";
    cin >> owner;
    cout << "Type a wagon: ";
    cin >> wagon;
    cout << "Type a num: ";
    cin >> num;
    cout << "Enter the type lukc/plazkart (l/p): ";
    cin>>type;
    if (type=='p'){
        Plazkart l(owner, wagon, num);
        tickets[i] = &l; 
    } else if (type=='l'){
        Lux l(owner, wagon, num);
        tickets[i]=&l;
    } else{
      cout << "Wrong entered type";
      exit(1);
    }
  }
}

//printting tickets array  
void PrintTickets(){
  for (int i =0; i<sizeofarray;i++){
    tickets[i].print();
  }
}

void InsertionSort() {
	int j;
	Ticket key;
	for (int i = 1; i < sizeofarray; i++) {
		key.reset(&tickets[i]);
		j = i;
		while (j > 0 && key.Owner()<tickets[j-1].Owner()) {
		    tickets[j].reset(&tickets[j - 1]);
			j--;
		}
		tickets[j].reset(&key);
	}
}



int main(){
    EnterTickets();
    InsertionSort();
    PrintTickets();
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