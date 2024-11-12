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
    void train(const std::string& filename);
    void test(const std::string& testfile);
    void checking(const std::string& sentimentFile);
    void result(const std::string& resultFile);
    void accuracy(const std::string& accuracyFile);
};

#endif
