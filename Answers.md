# Assignment 2: Answers

**Complete this document, commit your changes to Github and submit the repository URL to Canvas.** Keep your answers short and precise.

Your Name:

Used free extension: [ ] 24 hrs or [ ] 48 hrs

[ ] Early submission (48 hrs)

[ ] Bonus work. Describe: ...

Place [x] for what applies.


## UML Diagram

Add your UML class diagram here.

Replace the following image with your diagram. You can draw it by hand and take a photo.
![UML Class Diagram](UML_class.png)

## Answers

1. How do you train the model and how do you classify a new tweet? Give a short description of the main steps.

    > The code reads the file line by line and uses a buffer to separate the data by commas, focusing specifically on extracting the sentiment and tweet columns. For each line, I then tokenized the tweet text into individual words. If the sentiment value is 4 ( positive sentiment), I increase the count for each word by 1. If the sentiment is 0 (negative sentiment), I decrease the count by 1. These values are stored in a map and vector, allowing efficient access and manipulation of word sentiment scores for later use in the classification process.

2. How long did your code take for training and what is the time complexity of your training implementation (Big-Oh notation)? Remember that training includes reading the tweets, breaking it into words, counting, ... Explain why you get this complexity (e.g., what does `N` stand for and how do your data structures/algorithms affect the complexity).

   > k = size of trainingMap, m = # of words in tweet; n = # of tweets in file. So, it will be O(n*m*log(k))

3. How long did your code take for classification and what is the time complexity of your classification implementation (Big-Oh notation)? Explain why.

   > a = # of tweets in testing file; b = size of testingMap; c = number of words in testword. So, it will be O(a*c*log(b))

4. What accuracy did your algorithm achieve on the provides training and test data? 

   > My accuracy: 61%

   The TA will run your code on Linux and that accuracy value will be used to determine your grade.

5. What were the changes that you made that improved the accuracy the most?
   
   > I made all words to lowercase so that variations of the same word in different cases ("Happy" vs. "happy") are treated as the same word

6. How do you know that you use proper memory management? I.e., how do you know that you do not have
   a memory leak?

   > I check memory leak by using 'valgrind' in terminal.

6. What was the most challenging part of the assignment?

   > Creating algorithms for training and testing was challenging.