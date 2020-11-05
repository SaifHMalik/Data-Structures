#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <fstream>

using namespace std;


class Boogle{
private:
    vector<int> track;
    vector<int> newIndex;
    string list;
    vector<string> words;
    vector<int> wordsCount;
    vector<vector<vector<int>>> tracks;
    string word;
    string tempStr;
    int n, m;

public:
    Boogle(string _list, vector<string> _words, int _n, int _m){
        list = _list;
        words = _words;
        vector<int> tempWordsCount(words.size());
        wordsCount = tempWordsCount;
        vector<vector<vector<int>>> tempTracks(words.size());
        tracks = tempTracks;
        n = _n + 1;
        m = _m + 1;
    }

    void printTracks(){
        for(int i = 0; i < words.size(); i++){
            cout << "\nWORD: " << words[i];
            for(int j = 0; j < tracks[i].size(); j++){
                cout << endl;
                for(int k = 0; k < words[i].size(); k++){
                    cout << tracks[i][j][k] << " ";
                }
            }
        }
    }

    void saveTracks(){
        for(int i = 0; i < words.size(); i++){
            ofstream wos(words[i]+".txt");
            wos << words[i] << ": " << wordsCount[i] << endl;
            for(int j = 0; j < tracks[i].size(); j++){
                for(int k = 0; k < tracks[i][j].size(); k++){
                    wos << tracks[i][j][k] << " ";
                }
                wos << endl;
            }
        }
    }

    void printResult(){
        for(int i = 0; i < words.size(); i++){
            cout << endl << words[i] << "\t" << wordsCount[i];
        }
    }

    void saveResult(){
        ofstream wos("OutputFile1.txt");
        for(int i = 0; i < words.size();i++){
            for(int j = 0;j < words[i].length();j++){
                wos << words[i][j] << " ";
                if(j == words[i].length()-1) {
                    wos << (wordsCount[i] * 1000) << endl;
                }
            }
        }
    }

    void printTrack(){
        for(int i = 0; i < track.size(); i++){
            cout << track[i] << "\t";
        }
    }

    void printNewIndex(){
        for(int i = 0; i < newIndex.size(); i++){
            cout << newIndex[i] << "\t";
        }
    }

    bool checkTrack(int index){
        for(int i = 0; i < track.size(); i++){
            if(track[i] == index){
                return true;
            }
        }
        return false;
    }

    int searchLetter(int i, int nextIndex){
        if(newIndex.size() >= track.size()){
            newIndex.pop_back();
        }
        for(int j = nextIndex+1; j < 4; j++){
            if(i < n && j == 0){
                continue;
            } else if(i%n == 0 && j == 1){
                continue;
            } else if((i+1)%n == 0 && j == 2){
                continue;
            } else if(i >= (n*(m-1)) && j == 3){
                continue;
            } else{
                if(j == 0){
                    if(checkTrack(i-n)){
                        continue;
                    } else{
                        newIndex.push_back(j);
                        return i-n;
                    }
                } else if(j == 1){
                    if(checkTrack(i-1)){
                        continue;
                    } else{
                        newIndex.push_back(j);
                        return i-1;
                    }
                } else if(j == 2){
                    if(checkTrack(i+1)){
                        continue;
                    } else{
                        newIndex.push_back(j);
                        return i+1;
                    }
                } else if(j == 3){
                    if(checkTrack(i+n)){
                        continue;
                    } else{
                        newIndex.push_back(j);
                        return i+n;
                    }
                }
            }
        }
        return -1;
    }

    void Boogle_Boogle(){
        for(int listIndex = 0; listIndex < list.size(); listIndex++){
            for(int wordIndex = 0; wordIndex < words.size(); wordIndex++){
                tempStr = words[wordIndex];
                track.clear();
                newIndex.clear();
                word.clear();
                int nextIndex = -1;
                if(tempStr.find(list[listIndex]) >= 0 && tempStr.find(list[listIndex]) < tempStr.length()){
                    word.push_back(list[listIndex]);
                    track.push_back(listIndex);
                    tempStr.erase(tempStr.find(list[listIndex]), 1);
                    nextIndex = searchLetter(listIndex, nextIndex);
                    while(true){
                        if(nextIndex >= 0){
                            if(tempStr.find(list[nextIndex]) >= 0 && tempStr.find(list[nextIndex]) < tempStr.length()){
                                word.push_back(list[nextIndex]);
                                track.push_back(nextIndex);
                                tempStr.erase(tempStr.find(list[nextIndex]), 1);
                                if(word.length() != words[wordIndex].length()){
                                    nextIndex = searchLetter(nextIndex, -1);
                                } else{
                                    wordsCount[wordIndex] += 1;
                                    tracks[wordIndex].push_back(track);
                                    break;
                                }
                            } else{
                                nextIndex = searchLetter(track.back(), newIndex.back());
                            }
                        } else{
                            if(track.size() <= 1){
                                break;
                            } else{
                                tempStr.push_back(word.back());
                                word.pop_back();
                                track.pop_back();
                                nextIndex = searchLetter(track.back(), newIndex.back());
                            }
                        }
                    }
                }
            }    
        }
        printResult();
        saveResult();
    }

};


int main(void){
    string list;
    vector<string> words;;
    int n;
    int m;
    string read;
    string num;
    int wordCount;

    ifstream rsi("InputFile1.txt");

    if(rsi.is_open() == false){
        ofstream wsi("InputFile1.txt");
        wsi.close();
    }

    rsi.close();

    ifstream is("InputFile1.txt");

    getline(is,num);

    for(int i = 0; i < num.length()-1;i++){
        if(num[i] == ' '){
            num.erase(i,1);
        }
    }

    n = (stoi(num)%10);
    m = (stoi(num)/10)%10;

    for(int i = 0; i < n+1;i++){
        getline(is,read);
        list += read;
    }

    for(int j = 0;j<list.length();j++){
        if(list[j] == ' '){
            list.erase(j, 1);
        }
    }

    getline(is,read);
    wordCount = stoi(read);

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


    Boogle ob(list, words, n, m);
    ob.Boogle_Boogle();
    cout << "\nWould you like to save proof of output result? y/n: ";
    char ans = 'n';
    cin >> ans;
    if(tolower(ans) == 'y'){
        ob.saveTracks();
        ob.printTracks();
    }
}