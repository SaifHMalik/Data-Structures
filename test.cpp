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
    string wordN;
    string wordR;

    string listNormal;
    string listReverse;
    int N, W;

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

    void matchWords(vector<string> _tempWords){
        int count = 0;
        for(int m = 0; m < 2; m++){}
    }

    int checkHorizontal(int i, int j, int W){
        int count = 0;
        if(i % N <= N - W){
            if(listNormal.substr(i, W) == words[j]){
                count++;
            }
            if(listReverse.substr(i, W) == words[j]){
                count++;
            }
        }
        return count;
    }

    void checkHorizontal2(int i){
        int count = 0;
        for(int j = 0; j < words.size(); j++){
            if(listNormal.substr(i, W) == words[j]){
                count++;
            }
            if(listReverse.substr(i, W) == words[j]){
                count++;
            }
            wordsCount[j] += count;
        }
    }
    
    void checkVertical2(){
        int count = 0;
    }

    int checkVertical(int i, int j, vector<string> _tempWords){
        int count = 0;
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
    }

    void checkWords(){
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
    }
};


int main(){
    string list = "LYAADBURDSBUFDISKOFFYSPSS";
    vector<string> words = {"BURDS", "DRY", "FRA", "FUB", "LUFFS", "SIF", "SKOFF", "SODS", "SOU", "SURA"};
    int N = 5;
    WordCheck wcOB(words, list, N);
    wcOB.printWords();
    wcOB.checkWords();
    wcOB.printWords();
}
