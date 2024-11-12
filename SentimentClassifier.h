#ifndef SENTIMENTCLASSIFIER_H
#define SENTIMENTCLASSIFIER_H
#include "DSString.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <map>
#include <iomanip>
class SentimentClassifier
{
    private:
        std::map<DSString, int> trainingMap;
        std::map<DSString, int> testingMap; 
        std::map<DSString, int> check;
    public:
    std::vector<DSString> tweet;
    SentimentClassifier();
    void train(char* filename);
    void test(char* testfile);
    void checking(char* sentimentFile);
    void result(char* resultFile);
    void accuracy(char* accuracyFile);
};
#endif
