#include"Header.h"
#include<iostream>
using namespace std;

int main()
{
	int totalrules=0; //initially totalrules be 0
	int totalpackets=0; //initially totalpackets be 0
    readinput("E:/rules.txt",totalrules); //reading the rule file 
	readpacket("E:/packets.txt",totalpackets); //reading the packet file
    rulesapply(totalrules,totalpackets); //applying the rules to the packets
    output("E:/result.txt",totalpackets); //writing the output to the file
	cout<<"Total rules: "<<totalrules<<" Total packets: "<<totalpackets<<endl;
	cout<<"Rules have been applied to packets"<<endl;
	return 0;
}