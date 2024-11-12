#include "SentimentClassifier.h"

#include "DSString.h"
// train
// predict
// test
SentimentClassifier::SentimentClassifier() {

}
void SentimentClassifier::train(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open training file: " << filename << std::endl;
        exit(1);
    }
    char* buffer = new char[1000];
    file.getline(buffer, 1000);
    while (!file.eof()) {
        // get sentiment
        int sentiment;
        file >> sentiment;
        file.getline(buffer, 1000, ',');
        if (sentiment != 0 && sentiment != 4) {
            break;
        }
        // not using colums
        file.getline(buffer, 1000, ',');
        file.getline(buffer, 1000, ',');
        file.getline(buffer, 1000, ',');
        file.getline(buffer, 1000, ',');
        // get tweet
        file.getline(buffer, 1000);
        DSString text = buffer;
        text = text.toLower();
        std::vector<DSString> word = text.tokenization();
        //not in word, insert word
        for(int i = 0; i < word.size(); i++){
            if (trainingMap.find(word[i]) == trainingMap.end()) {
                // word not found
                if (sentiment == 4) {
                    trainingMap[word[i]] = 1;
                } else {
                    trainingMap[word[i]] = -1;
                }
            } else {
                // word found
                if (sentiment == 4) {
                    trainingMap[word[i]]++;
                } else {
                    trainingMap[word[i]]--;
                }
            }
        }
        //if word already exist:
            //if sentiment is positive, add value of +1, and cout +1
            //if sentiment is negative, subtract -1 value, and add count +1
        
    }
    delete[] buffer;
    file.close();
}
void SentimentClassifier::test(const std::string& testfile) {
    std::ifstream testFile(testfile);
    if (!testFile.is_open()) {
        std::cerr << "Failed to open test file: " << testfile << '\n';
        exit(1);
    }
    char* buffer = new char[1000];
    testFile.getline(buffer, 1000);
    while (!testFile.eof()) {
        // get sentiment
        testFile.getline(buffer, 1000, ',');
        DSString id = buffer;
        if (id.length() == 0) {
            break;
        }
        //useless
        testFile.getline(buffer, 1000, ',');
        testFile.getline(buffer, 1000, ',');
        testFile.getline(buffer, 1000, ',');
        //read column
        testFile.getline(buffer, 1000);
        DSString testText = buffer;
        testText = testText.toLower();
        //tokenize
        std::vector<DSString> testWord = testText.tokenization();
        int value = 0;
        for(int i = 0; i < testWord.size(); i++){
            if (trainingMap.find(testWord[i]) != trainingMap.end()) {
                value += trainingMap[testWord[i]];
            }
        }
        if (value >= 0) {
            testingMap[id] = 4;
        } else if (value<0) {
            testingMap[id] = 0;
        }
    }
    delete[] buffer;
    testFile.close();
}
void SentimentClassifier::checking(const std::string& sentimentFile) {
    std::ifstream sentiFile(sentimentFile);
    if (!sentiFile.is_open()) {
        std::cerr << "Failed to open sentiment file: " << sentimentFile << '\n';
        exit(1);
    }
    char* buffer = new char[1000];
    sentiFile.getline(buffer, 1000);
    while (!sentiFile.eof()) {
        int sentiment;
        sentiFile >> sentiment;
        sentiFile.getline(buffer, 1000, ',');
        if (sentiment != 0 && sentiment != 4) {
            break;
        }
        sentiFile.getline(buffer, 1000);
        DSString id = buffer;
        int testSenti = testingMap.find(id)->second;
            if(testSenti != sentiment) {
            // if(testingMap.find(id)->second != sentiment) {
            // if(testingMap[id] != sentiment) {
                //insert to map only the wrong
                // check.insert(std::make_pair(id,sentiment));
                check[id] = testSenti;
                // check.insert(std::make_pair(id,sentiment));
            } 
    }
    delete[] buffer;
    sentiFile.close();
}
void SentimentClassifier::result(const std::string& resultFile){
    std::ofstream file1(resultFile);
    for (const std::pair<DSString, int>& itr : testingMap) {
        //save result to file1
        file1 << itr.second << "," << itr.first << '\n';
    }
    file1.close();
}
void SentimentClassifier::accuracy(const std::string&accuracyFile){
    float rate = 1 - ((float)check.size() / testingMap.size());
    std::ofstream file2(accuracyFile);
    file2 << std::fixed << std::setprecision(3) << rate << '\n';
    for(auto& pair: check){
        if(pair.second == 4){
            //save to file2
            file2 << pair.second << ", 0, " << pair.first << '\n';
        } else {
            //save to file2
            file2 << pair.second << ", 4, " << pair.first << '\n';
        }
    }
    file2.close();
}
