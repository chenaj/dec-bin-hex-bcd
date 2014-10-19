/* 
Angela Chen
CIS 310 Fall 2012 
Professor Yoon
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 

using namespace std;

#define MAX 255

template <typename T>  //converter for the string values so we can better work with them
  string NumberToString ( T Number )
 {
     ostringstream ss;
     ss << Number;
     return ss.str();
 }

string binary(int i)
{
	// Binary (base 2)
	int tmp = i;
	string binary="0000\t0000";
	for(int n = 8; n >= 0; n--)
	{
		if(n == 4)
		{
			binary[n]=' '; //space for readability
		}
		else
		{
			binary[n]=(tmp%2) + 48; //base of 2
			tmp = tmp/2;  //base of 2
		}
	}
	return binary;
}

string hex(int i)
{
	// Hex (base 16)
	int tmp = i;
	string hex="00";
	for(int n = 1; n >= 0; n--)  //max of 255 can only hold 2 hex digits
	{
		int remain = tmp%16;
		if(remain > 9)
		{
			hex[n] = remain + 55; //make letters A-F for 10-15 on base of 16
		}
		else
		{
			hex[n]=remain + 48; 
		}
		tmp = tmp/16;
	}
	return hex;
}

string bcd(int i)
{
	string bcd = "0000 0000 0000"; //default string to build the string size
	string tmp = NumberToString(i); //convert the number to a string
	if(tmp.length() == 1)  //pad 0's where needed
	{
		string hold = "00" + tmp;
		tmp = hold;
	}
	if (tmp.length() == 2)
	{
		string hold = "0" + tmp;
		tmp = hold;
	}
	for(int n = 0; n < 3; n++) //for each number,
	{
		int k = tmp[n] - 48; //convert value to an int and hold it
		for(int j = 3; j >= 0; j--) //for each of the 4 numbers in the bit,
		{
			int pos = 4 * (n + 1) + (1 * n) - 1; //find the position in the string we are working with
			pos -= (3 - j);
			bcd[pos] = k % 2 + 48; //convert and write the value to the string pos
			k = k / 2;  //divide by the base of 2 for binary
		}
	}
	return bcd;
}


void main()
{

	ofstream file;
	file.open("output.txt");

	file << "Dec\tBinary\t\tHex\tBCD\n";

	for(int i = 0; i <= MAX; i++)
	{
		int tmp;

		//Decimal value
		file << i << "\t";

		//get binary of decimal
		file << binary(i) << "\t";

		//get hex
		file << hex(i) << "\t";

		//get bcd
		file << bcd(i) << endl;

	}
	system("pause");
}
