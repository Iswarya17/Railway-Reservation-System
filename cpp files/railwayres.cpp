#include<fstream>
#include<iostream>

using namespace std;

int main(){
	char data[100];
ofstream file;
file.open("railreserve.txt");
cin.getline(data,100);
file<<data<<endl;

file.close();

ifstream iff;
iff.open("railreserve.txt");
iff>>data;
cout<<data;
iff.close();

while(1);
}
