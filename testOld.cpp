#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

class WordCheck
{
private:
    vector<string> words;
    vector<int> wordsCount;
    vector<vector<string>> wordsPosition;
    string listNormal;
    string listReverse;
    int N;

public:
    WordCheck(vector<string> _words, string list, int _N){
        words = _words;
        listNormal = list;
        listReverse = string(list.rbegin(), list.rend());
        N = _N;
        vector<int> tempWordsCount(_words.size());
        vector<vector<string>> tempWordsPosition(_words.size());
        wordsCount = tempWordsCount;
        wordsPosition = tempWordsPosition;
    }

    ~WordCheck(){}

    void printWords(){
        for(int i = 0; i < words.size(); i++){
            cout << words[i] << "\t" << wordsCount[i] << endl;
        }
    }

    void matchWords(string * tempWords, int j){
        int count = 0;
        cout << j << "\t" << tempWords[0] << "\t" << tempWords[1]  << "\t" << words[j] << endl;
        for(int m = 0; m < 2; m++){
            if(tempWords[m] == words[j]){
                count++;
            }
        }
        wordsCount[j] += count;
    }

    void checkHorizontal(int i){
        string tempWords[2] = {};
        int W;
        for(int j = 0; j < words.size(); j++){
            W = words[j].size();
            if(i % N <= N - W){
                tempWords[0] = listNormal.substr(i, W);
                tempWords[1] = listReverse.substr(i, W);
                matchWords(tempWords, j);
            }
        }
    }
    
    void checkVertical(int i){
        int W;
        for(int j = 0; j < words.size(); j++){
            W = words[j].size();
            if(i + (W * N - N) < listNormal.size()){
                string tempWords[2];
                for(int k = 0; k < W; k++){
                    if(listNormal[i + (k * N)] == words[j][k] || listReverse[i + (k * N)] == words[j][k]){
                        tempWords[0] += listNormal[i + (k * N)];
                        tempWords[1] += listReverse[i + (k * N)];
                    } else{
                        break;
                    }
                }
                if(tempWords[0].length() == W){
                    matchWords(tempWords, j);
                }
            }
        }
    }

    void checkDiagonalRight(int i){
        int W;
        for(int j = 0; j < words.size(); j++){
            W = words[j].size();
            if(i + (N * W - W) < listNormal.size() && i % N <= N-W){
                string tempWords[2];
                for(int k = 0; k < W; k++){
                    if(listNormal[i + k * (N + 1)] == words[j][k] || listReverse[i + k * (N + 1)] == words[j][k]){
                        tempWords[0] += listNormal[i + k * (N + 1)];
                        tempWords[1] += listReverse[i + k * (N + 1)];
                    } else{
                        break;
                    }
                }
                if(tempWords[0].length() == W){
                    matchWords(tempWords, j);
                }
            }
        }
    }

    void checkDiagonalLeft(int i){
        int W;
        for(int j = 0; j < words.size(); j++){
            W = words[j].size();
            if((i + (W - 1) * (N - 1)) <= (listNormal.size() - W) && i % N >= W - 1){
                string tempWords[2];
                for(int k = 0; k < W; k++){
                    if(listNormal[i + k * (N - 1)] == words[j][k] || listReverse[i + k * (N - 1)] == words[j][k]){
                        tempWords[0] += listNormal[i + k * (N - 1)];
                        tempWords[1] += listReverse[i + k * (N - 1)];
                    } else{
                        break;
                    }
                }
                if(tempWords[0].length() == W){
                    matchWords(tempWords, j);
                }
            }
        }
    }

    void checkWords(){
        for(int i = 0; i < listNormal.size(); i++){
            cout << "i:\t" << i << "\nHORIZONTAL:" << endl;
            checkHorizontal(i);
            cout << "VERTICAL:" << endl;
            checkVertical(i);
            cout << "DIAGONAL RIGHT:" << endl;
            checkDiagonalRight(i);
            cout << "DIAGONAL LEFT:" << endl;
            checkDiagonalLeft(i);
        }
    }

    /*void checkWords(){
        vector<string> tempWords(2);
        for(int i = 0; i < listNormal.size(); i++){
            cout << "\ni:\t" << i << endl;
            for(int j = 0; j < words.size(); j++){
                cout << "\tj:\t" << j << endl;
                W = words[j].size();
                if(i % N <= N - W){
                    if(listNormal.substr(i, W) == words[j]){
                        wordsCount[j]++;
                        wordsPosition[j].push_back(to_string(i) + '-' + to_string(i + W - 1));
                    } else if(listReverse.substr(i, W) == words[j]){
                        wordsCount[j]++;
                        wordsPosition[j].push_back(to_string(i) + '-' + to_string(i + W - 1));
                    }
                    cout << "F: " << listNormal.substr(i, W) << "\t" << listReverse.substr(i, W) << endl;
                }
                if(i + (W * N - N) < listNormal.size()){
                    wordN = wordR = "";
                    for(int k = 0; k < W; k++){
                        if(listNormal[i + (k * N)] == words[j][k] || listReverse[i + (k * N)] == words[j][k]){
                            wordN += listNormal[i + (k * N)];
                            wordR += listReverse[i + (k * N)];
                        } else{
                            break;
                        }
                    }
                    if(wordN == words[j]){
                        wordsCount[j]++;
                    }
                    if(wordR == words[j]){
                        wordsCount[j]++;
                    }
                    cout << "D: " << wordN << "\t" << wordR << endl;
                }
                if(i + (N * W - W) < listNormal.size() && i % N <= N-W){
                    wordN = wordR = "";
                    for(int k = 0; k < W; k++){
                        if(listNormal[i + k * (N + 1)] == words[j][k] || listReverse[i + k * (N + 1)] == words[j][k]){
                            wordN += listNormal[i + k * (N + 1)];
                            wordR += listReverse[i + k * (N + 1)];
                        } else{
                            break;
                        }
                    }
                    if(wordN == words[j]){
                        wordsCount[j]++;
                    }
                    if(wordR == words[j]){
                        wordsCount[j]++;
                    }
                    cout << "R: " << wordN << "\t" << wordR << endl;
                }
                if((i + (W - 1) * (N - 1)) <= (listNormal.size() - W) && i % N >= W - 1){
                    wordN = wordR = "";
                    for(int k = 0; k < W; k++){
                        if(listNormal[i + k * (N - 1)] == words[j][k] || listReverse[i + k * (N - 1)] == words[j][k]){
                            wordN += listNormal[i + k * (N - 1)];
                            wordR += listReverse[i + k * (N - 1)];
                        } else{
                            break;
                        }
                    }
                    if(wordN == words[j]){
                        wordsCount[j]++;
                    }
                    if(wordR == words[j]){
                        wordsCount[j]++;
                    }
                    cout << "L: " << wordN << "\t" << wordR << endl;
                }
            }
            printWords();
        }
    }*/
};


int main(){
    // string list = "APPLEBAPSPLAAAPLELDPPLELAAPLESGODTAC";
    // vector<string> words = {"APPLE", "BALLS", "CAT", "DOG", "GOD", "APPLES", "ALPS", "PAPA", "GAP", "DAD", "SAD", "LEE"};
    string list = "FUNNYIRIMUKARACHDYEYERPRGCDRQLKQBGCAGHAOIDQJCRBQYGDJSWKAMDOIPFKARACHICDCDJFLYYSOFUNGQRUPOGKUCIQRLURE";

    vector<string> words = {"KARACHI","LOGIC","FUNNY"};
    int N = 10;
    WordCheck wcOB(words, list, N);
    // wcOB.printWords();
    wcOB.checkWords();
    wcOB.printWords();
}