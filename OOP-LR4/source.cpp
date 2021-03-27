#include <iostream>
#include<time.h>
#include <cmath>
#include<cstring> 
const int N=52;
static int size;
using namespace std; 

class Ticket {      
  protected:
    int wagon;        
    string owner;
  public:           
    Ticket(){}
    Ticket(int wagon, string owner){
      this->wagon = wagon;
      this->owner = owner;
    }
    ~Ticket(){}
};

class Plazkart : public Ticket {
  private:
    int num;
    string type;
  public:
  void Reset(string owner, int wagon, int num);
  void Reset(Plazkart* obj);
  Plazkart(){}

  Plazkart(int wagon, int num, string owner){
      Reset(owner, wagon, num);
  } 

  string Owner(){return this->owner;}
  string Type(){return this->type;}
  int Num(){return num;}
  int Wagon(){return wagon;}
  void print();
};

static Plazkart tickets[N];

//reset plazkart info
void Plazkart::Reset(string owner, int wagon, int num){
  if (num>52 || num <1){
        printf("Error 'Plazkart num error input'");
        exit(0);
      } else if(num>36){
        type = "side";
      } else {
        type = "inner";
      }
  this->owner = owner;
  this->wagon = wagon;
  this->num = num;
}
void Plazkart::Reset(Plazkart *obj){
  Reset(obj->Owner(), obj->Wagon(), obj->Num());
}

//print Plazkart data
void Plazkart::print(){
  printf("\nOwner: ");
  cout << owner;
  printf(", wagon: %d, num: %d, type of place: ", wagon,num);
  cout << type;
}


//getting tickets data
void EnterTickets(){
  string name;
  int wagon, num;
  cout << "Enter amount passengers (at most 52): ";
  cin >> size;
  for (int i=0; i<size;i++){
    cout << "Enter a name: ";
    cin >> name;
    cout << "Type a wagon: ";
    cin >> wagon;
    cout << "Type a num: ";
    cin >> num;
    tickets[i].Reset(name, wagon, num);
  }
}

//printting tickets array  
void PrintTickets(){
  for (int i =0; i<size;i++){
    tickets[i].print();
  }
}


void InsertionSort() {
	int j;
	Plazkart key;
	for (int i = 1; i < size; i++) {
		key.Reset(&tickets[i]);
		j = i;
		while (j > 0 && key.Owner().compare(tickets[j-1].Owner())) {
			tickets[j].Reset(&tickets[j - 1]);
			j--;
		}
		tickets[j].Reset(&key);
	}
}


int main(){
  EnterTickets();
  InsertionSort();
  PrintTickets();
  return 0;
}


/*
5
Vergun
1
43
Kosa
1
2
Kish
1
50
Rolia
1
5
Asdf
1
2
*/