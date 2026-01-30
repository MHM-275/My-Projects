#pragma once
#include <iostream>
#include<string>
#include<fstream>
using namespace std;
struct Rules  //Structure for rules
{
	int rulenumber;
	string appliedTo;
	string IP_protocol;
	string decision;
};
Rules rules[50];

struct Packets  //Structure for packets
{
	string SRC ;
	string DST ;
	string PRO ;
	string data ;
	string decision ;
	int rulenumber;
};
Packets packets[50];



void readinput(string filename, int& countrules) //Reading the input file where all the rules are stored
{
    ifstream infile(filename);
    if (!infile)
    {
        cout << "Error opening file" << endl;
        return;
    }
    while (!infile.eof())
    {
        infile >> rules[countrules].rulenumber;
        infile >> rules[countrules].appliedTo;
        infile >> rules[countrules].IP_protocol;
        infile >> rules[countrules].decision;
        countrules++;
    }
    infile.close();
}



string removesubstring(string mainStr, string toRemove) //Removing the substring from the string t
{
    int pos = mainStr.find(toRemove) + toRemove.length(); // position of the substring to be removed
    mainStr.erase(0, pos); // removing the substring from the main string 
    return mainStr; // returning the resultant string
}



//Reading the packet file where all the packets are stored and storing them in the packets structure
//Also removing the substring from the string
void readpacket(string filename, int& countpackets) //Reading the packet file where all the packets are stored
{
ifstream packetFile(filename);  

 if (!packetFile) {
    cout << "File not opened";
 }
 else 
 {
    string data;
    char ch;
    while(packetFile >> ch) //Reading the file character by character

    {
        if(ch == '[')  //Checking for the '[' character
        {
            getline(packetFile, data, ';');  //Reading the data till the ';' character
            packets[countpackets].SRC = removesubstring(data, "SRC:"); //Removing the SRC from the string and storing it in the packet.SRC structure
            getline(packetFile, data, ';'); //Reading the data till the ';' character
            packets[countpackets].DST = removesubstring(data, "DST:"); //Removing the DST from the string and storing it in the packet.DST structure
            getline(packetFile, data, ';'); //Reading the data till the ';' character 
            packets[countpackets].PRO = removesubstring(data, "PRO:"); //Removing the PRO from the string and storing it in the packet.PRO structure
            getline(packetFile, data, ']'); //Reading the data till the ']' character
            packets[countpackets].data = data; //Storing the data in the packet.data structure
            ch = ' '; 
            countpackets++; //Incrementing the countpackets to store the next packet
        }
    }
 }
  packetFile.close(); 
}


//Applying the rules to the packets and storing the decision and rulenumber in the packets structure
//each packet is compared with all the rules 
//if the rule is applicable to the packet then the decision and rulenumber is stored in the packets structure

void rulesapply(int totalrules,int totalpackets) //Function to apply the rules to the packets
{
 for (int i = 0; i < totalpackets; i++) { 
    for (int j = 0; j < totalrules; j++) { 
        if (rules[j].appliedTo == "SRC") {
            if (packets[i].SRC == rules[j].IP_protocol) { //Comparing the packet.SRC with the rules.IP_protocol
                packets[i].rulenumber = rules[j].rulenumber; //if the rule is applicable to the packet then the rulenumber is stored in the packets structure
                packets[i].decision = rules[j].decision; //if the rule is applicable to the packet then the decision is stored in the packets structure
                break;
            }
        }
        else if (rules[j].appliedTo == "DST") {  
            if (packets[i].DST == rules[j].IP_protocol) { //Comparing the packet.DST with the rules.IP_protocol
                packets[i].rulenumber = rules[j].rulenumber; //if the rule is applicable to the packet then the rulenumber is stored in the packets structure
                packets[i].decision = rules[j].decision; //if the rule is applicable to the packet then the decision is stored in the packets structure
                break;
            }
        }
        else if (rules[j].appliedTo == "PRO") {
            if (packets[i].PRO == rules[j].IP_protocol) {  //Comparing the packet.PRO with the rules.IP_protocol
                packets[i].rulenumber = rules[j].rulenumber; //if the rule is applicable to the packet then the rulenumber is stored in the packets structure
                packets[i].decision = rules[j].decision; //if the rule is applicable to the packet then the decision is stored in the packets structure
                break;
            }
        }
        else
        {
            cout << "None of the rule is applicable to rule " << i + 1 << endl; 
        }
    }       
  }
}

//Writing the output to the file 
void output(string filename, int totalpackets)
{
    ofstream result(filename);
    if(!result) 
    {
       cout << "File not opened";
    }
    else 
    {
       for (int i = 0; i < totalpackets; i++) 
       {
        result << "SRC " << packets[i].SRC << "  "; 
        result << "DST " << packets[i].DST << "  ";
        result << "PRO " << packets[i].PRO << "  ";
        result << packets[i].decision << "  ";
        result << packets[i].rulenumber << endl;            
       }
    }
}