#include<fstream>
#include<iostream>
#include<string>

using namespace std;

class Rail{
   string name;
   
   
public:
	void enqueueU();
	void enqueueP();
	void waitingU();
	void waitingP();
	void cancelU();
	void cancelP();
};

void Rail::enqueueU(){
	ofstream ofile;
	int count_s=0;
	int count_c=0;
	ofile.open("bookingUzhavan.txt");
	for(int i=1;i<=2;i++){
		cout<<"This is S"<<i<<"coach in Uzhavan Express"<<endl;
		for(int j=1;j<=2;j++){

	cout<<"enter the name "<<endl;
	cin>>name;
	ofile<<name<<endl;
	++count_s;
	}
	
	if(count_s==2){
	cout<<"No more seats available in S"<<i<<"coach"<<endl;
	
	}
	++count_c;
	}
	if(count_c==2){
		cout<<"No more seats available in Uzhavan Express"<<endl;
		cout<<"Your seats will be allotted in Waiting list"<<endl;
	}

}
void Rail::waitingU(){
	ofstream ofile;
	int count_s=0;
	int count_c=0;
	ofile.open("waitingUzhavan.txt");
	for(int i=1;i<=2;i++){
		cout<<"This is S"<<i<<"coach in Uzhavan Express"<<endl;
		for(int j=1;j<=1;j++){

	cout<<"enter the name"<<endl;
	cin>>name;
	ofile<<name<<endl;
	++count_s;
	}
	
	if(count_s==1){
	cout<<"No more waiting seats available in S"<<i<<"coach"<<endl;
	
	}
	++count_c;
	}
	if(count_c==2){
		cout<<"No more waiting seats available in Uzhavan Express"<<endl;
		
	}

}

void Rail::enqueueP(){
	ofstream ofile;
	int count_s=0;
	int count_c=0;
	ofile.open("bookingPandiyan.txt");
	for(int i=1;i<=2;i++){
		cout<<"This is S"<<i<<"coach in Pandiyan Express"<<endl;
		for(int j=1;j<=2;j++){
	cout<<"enter the name "<<endl;
	cin>>name;
	ofile<<name<<endl;
	++count_s;
		}
		if(count_s==2){
		cout<<"No more seats available in S"<<i<<"coach"<<endl;
		}
		++count_c;
	}
	if(count_c==2){
			cout<<"No more seats available in Pandiyan Express"<<endl;
			cout<<"Your seats will be allotted in Waiting list"<<endl;
	}

}

void Rail::waitingP(){
	ofstream ofile;
	int count_s=0;
	int count_c=0;
	ofile.open("waitingPandiyan.txt");
	cout<<"WAITING LIST"<<endl;
	for(int i=1;i<=2;i++){
		cout<<"This is S"<<i<<"coach in Pandiyan Express"<<endl;
		for(int j=1;j<=1;j++){
	cout<<"enter the name"<<endl;
	cin>>name;
	ofile<<name<<endl;
	++count_s;
		}
		if(count_s==1){
		cout<<"No more waiting seats available in S"<<i<<"coach"<<endl;
		}
		++count_c;
	}
	if(count_c==2){
			cout<<"No more waiting seats available in Pandiyan Express"<<endl;
			
	}

}
void Rail::cancelU(){
	string line;
	ifstream filein("bookingUzhavan.txt");
	ofstream fileout("bookingUzhavanExpress.txt");
	ifstream file1in("waitingUzhavan.txt");
	ofstream file1out("waitingUzhavanExpress.txt");
	file1in>>name;
	string newName;
	newName=name;
	cout<<"enter the name to be cancelled"<<endl;
	cin>>name;
	string strTemp;
	while(filein>>strTemp){

		if(strTemp==name){
			strTemp=newName;
		}
		strTemp+="\n";
		fileout<<strTemp;

	}

	while(getline(file1in,line)){
		if(line!=newName){
			file1out<<line<<endl;
		}
	}
	fileout.close();
	filein.close();
	remove("bookingUzhavan.txt");
	rename("bookingUzhavanExpress.txt","bookingUzhavan.txt");
file1out.close();
file1in.close();
remove("waitingUzhavan.txt");
rename("waitingUzhavanExpress.txt","waitingUzhavan.txt");
	

}

void Rail::cancelP(){
	string line;
	ifstream filein("bookingPandiyan.txt");
	ofstream fileout("bookingPandiyanExpress.txt");
	ifstream file1in("waitingPandiyan.txt");
	ofstream file1out("waitingPandiyanExpress.txt");
	file1in>>name;
	string newName;
	newName=name;
	cout<<"enter the name to be cancelled"<<endl;
	cin>>name;
	string strTemp;
	while(filein>>strTemp){

		if(strTemp==name){
			strTemp=newName;
		}
		strTemp+="\n";
		fileout<<strTemp;

	}
	while(getline(file1in,line)){
		if(line!=newName){
			file1out<<line<<endl;
		}
	}
	fileout.close();
	filein.close();
	remove("bookingPandiyan.txt");
	rename("bookingPandiyanExpress.txt","bookingPandiyan.txt");
file1out.close();
file1in.close();
remove("waitingPandiyan.txt");
rename("waitingPandiyanExpress.txt","waitingPandiyan.txt");
	

	

	

}



int main(){
	
	string data;
	
     ifstream myfile ("RAILWAY RESERVATION.txt");

  if (myfile.is_open()){

    while (!myfile.eof()){
      getline (myfile,data);
      cout << data << endl;
    }
    myfile.close();
  }
Rail r1,r2;
int train_num;
int choice;
char name[100];
while(1){
	cout<<"select your train number"<<endl;
	cin>>train_num;
	
	if(train_num==121){
		do{
		cout<<"enter the choice"<<endl;
		cout<<"1. booking\n2.waiting\n3.cancelling"<<endl;
		cin>>choice;
		switch(choice){
	   case 1:
		   r1.enqueueU();
		   break;
		
		case 2:
			r1.waitingU();
			break;
		
		case 3:
			cout<<"enter the train number"<<endl;
			cin>>train_num;
			if(train_num==121){
				
				r1.cancelU();

			}
			break;
		}
		}while(choice!=0);
	}
	
	else if(train_num==212){
		do{
		cout<<"enter the choice"<<endl;
		cout<<"1. booking\n2.waiting\n3.cancelling"<<endl;
		cin>>choice;
		switch(choice){
		case 1:
			r2.enqueueP();
			break;
		case 2:
			r2.waitingP();
			break;
		case 3:
			if(train_num==212){
			r2.cancelP();
			}
			break;
		}
		}while(choice!=0);

}
	else {
		cout<<"nothing"<<endl;
	}
}
while(1);

}