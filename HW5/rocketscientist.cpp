#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

float lbfs_to_Ns(float value_lbfs){
	// Function that converts input in lbf*s to a result in N*s.
	float value_Ns;
	value_Ns = value_lbfs * 4.4482216152605; // 1 lbf = 4.4482216152605 N
	return value_Ns;
}

float Ns_to_lbfs(float value_Ns){
	// Function that converts from N*s back to lbf*s.
	float value_lbfs;
	value_lbfs = value_Ns / 4.4482216152605;
	return value_lbfs;
}

int main(){
	
	// Start reading the data file.
	fstream readingdata;
	readingdata.open("valuesInLbf.dat");
	
	// Initializing some variables/strings/vectors needed in the code.
	string value;
	float input;
	vector<float> vec; // Vector that will have the strings in the data file converted to floats.
	
	// Counting the number of lines in the data file.
	/*int numlines = 0;
	string count;
	while(getline(readingdata,count)){
		++numlines;
	}
	cout << "Number of lines in the data file: " << numlines << endl;*/ //Gives 7, which is right!
	//Now that I konw that I can read the file correctly, I comment out the above, 
	//otherwise I won't be able to read through the file below.
	
	// Appending the data from the file, once converted to float type, to the vector.
	
	while (getline(readingdata,value)){
		const char * cdata = value.c_str();
		float input = strtof(cdata,0);
		float input_converted = lbfs_to_Ns(input);
		vec.push_back(input);
		vec.push_back(input_converted);
	}
		
	// Printing the vector to check that the above worked.
	/*for(int i=0; i < vec.size() ; i++){
		cout << vec.at(i) << " ";
	} */ // Works!
	
	//Writing some code to print the values in the vector in an organized manner.
	for(int i=0; i < vec.size(); i+=2){
		cout << "Value in lbf*s: " << vec.at(i) << ", value in N*s: " << vec.at(i+1) << endl;
	}
	
	//Start with the interactive part of the code:
	float value_Ns;
	float value_Ns2;
	cout << "Dear engineer in a control station! Give me a value in N*s. I will convert it to lbf*s." << endl;
	cin >> value_Ns;
	cout << value_Ns << " N*s is " << Ns_to_lbfs(value_Ns) << " lbf*s." << endl;
	AGAIN:
	cout << "Give another number (0 if you want to exit):" << endl;
	cin >> value_Ns2;
	if(value_Ns2 == 0){
		cout << "You decided to exit" << endl;
		return 0;
	}
	else{
		cout << value_Ns << " N*s is " << Ns_to_lbfs(value_Ns) << " lbf*s." << endl;
	}
	goto AGAIN;
	
}
