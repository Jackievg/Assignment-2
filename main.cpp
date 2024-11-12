#include <iostream>
#include "SentimentClassifier.h"

int main(int argc, char** argv)
{  
    std::cout << "I will be a sentiment analyzer!" << std::endl;
    SentimentClassifier sc;
    sc.train(argv[1]);
    sc.test(argv[2]);
    sc.checking(argv[3]);
    sc.result(argv[4]);
    sc.accuracy(argv[5]);
    return 0;
}