#include<iostream>
#include<vector>
#include<fstream>
#include<string.h>

using namespace std;

int main(void){
    string line;
    string read;
    int row;
    int column;
    string num;
    int wordCount;
    vector <string> words;

    ifstream rsi("InputFile1.txt");

    if(rsi.is_open() == false){
        ofstream wsi("InputFile1.txt");
        wsi.close();
    }

    rsi.close();

    ifstream is("InputFile1.txt");
    ofstream os("OutputFile.txt");


    getline(is,num);


    for(int i = 0; i < num.length()-1;i++){
        if(num[i] == ' '){
            // num[count++] = num[i];
            num.erase(i,1);
        }
    }

    cout << num <<endl;


    // num[count] = '\0';

    // cout << num[0] << " " << num[1] << " " << num[2] << endl;
    // string str = "123";
    // int newNum = stoi(str);

    // cout << newNum <<endl;

    row = (stoi(num)%10);


    column = (stoi(num)/10)%10;

    cout << column <<endl;

    cout << row << endl;

    for(int i = 0; i < row+1;i++){
        getline(is,read);
        line += read;
    }

    for(int j = 0;j<line.length();j++){
        if(line[j] == ' '){
            line.erase(j, 1);
        }
    }

    getline(is,read);

    wordCount = stoi(read);

    cout <<endl << wordCount <<endl;

    for(int i = 0; i < wordCount;i++){
        getline(is,read);
        words.push_back(read);
    }

    for(int i = 0; i < words.size(); i++){
	    for(int j = 0; j < words[i].size(); j++){
		    if(words[i][j] == ' '){
			    words[i].erase(j, 1);
		    }
	    }
    }

    for(int i = 0; i < line.length();i++){
        cout << line[i];
    }

    cout << endl<<endl;

    for(int i = 0; i < words.size(); i++){
		    cout << words[i] <<endl;
            os << words[i] <<endl;
    }
}