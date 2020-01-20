#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//function to convert character from DNA to RNA(finding complement)
char DNAbase_to_mRNAbase(char dna){

   if(toupper(dna)=='A') //if A the convert to U
       return 'U';
   else if(toupper(dna)=='T') //if T the convert to A
       return 'A';
   else if(toupper(dna)=='C') //if C the convert to G
       return 'G';
   else if(toupper(dna)=='G') //if G the convert to C
       return 'C';
   else //Else return space
       return ' ';
}


string DNA_to_mRNA(string input){
   string output="";//initialising output to empty string

   //below I provided two methods use that you feel comfortable
   /*for(char& c : input) {
       output=output+DNAbase_to_mRNAbase(c);
   }*/
   //looping through each value and converting character by character
   for(int i = 0; i < input.size(); ++i) {
       output=output+DNAbase_to_mRNAbase(input[i]);//adding converted to
   }
   //returning converted string
   return output;
}

void dictionary_read(ifstream &dict) {
    string key, value;
    dict.clear(); // reset error state
    dict.seekg(0); // return file pointer to the beginning
    while (dict >> key >> value) {
        cout << "key: " << key << endl;
        cout << "value: " << value << endl;
    }
}


//main function
int main(){
//open file dna.txt 
ifstream fin("dna2b.txt");
string strand;

//if there is problem in opening file print error message
if (fin.fail()) {
cerr << "File cannot be read, opened, or does not exist.\n";
exit(1);
}


//loop for each line untill end of file is reached
while(getline(fin, strand)) {
cout << DNA_to_mRNA(strand) << endl; //calling function to convert DNA to RNA
}

//closing file
fin.close();
return 0;
   
}

