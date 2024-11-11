#include "DSString.h"

/* 
 * Implement the functions defined in DSString.h. You may add more functions as needed
 * for the project. 
 *
 * Note that c-strings don's store an explicit length but use `\0` as the terminator symbol
 * but your class should store its length in a member variable. 
 * DDO NOT USE C-STRING FUNCTIONS <string.h> or <cstring>.
 */

DSString::DSString() {
    data = new char[1];
    len = 0;
    data[0] = '\0';
}
    //constructor that converts a cstring
    DSString::DSString(const char *x){
      len = 0;
      while(x[len] != '\0'){
      len++;
      }
      data = new char[len + 1];
      for(size_t i = 0; i < len; i++){
      data[i] = x[i];
      }
      data[len] = '\0';

    }
    //rule of three
    //copy constructor
    DSString::DSString(const DSString &data1){
      data = new char[data1.len+1];
      len = data1.len;
      for(size_t i = 0; i < len; i++) {
         data[i] = data1.data[i];
      }
      data[len] = '\0';
    }           
    //destructor
    DSString::~DSString(){
      delete[] data;
    }
    //assignment operator
    DSString &DSString::operator=(const DSString &data1){
      if(this != &data1){
         delete[] data;
         len = data1.len;
         data = new char[data1.len+1];
         for(size_t i = 0; i < len; i++){
            data[i] = data1.data[i];
         }
         data[len] = '\0';
      }
      return *this;
    }
    //return length
    size_t DSString::length() const {
      return len;
    }
    //return reference to the character
    char& DSString::operator[](size_t index){
      return data[index];
    }
    DSString DSString::operator+(const DSString &data1) const {
      DSString appendedString;
      appendedString.len = data1.len+len;
      appendedString.data = new char[appendedString.len+1];
      appendedString.data[appendedString.len] = '\0';
      for(size_t i = 0; i < len; i++){
         appendedString.data[i] = data[i];
      }
      for(size_t i = 0; i < data1.len; i++){
         appendedString.data[i+len] = data1.data[i];
      }
      appendedString.data[appendedString.len] = '\0';
      return appendedString;
    }
    //compare order of string
    bool DSString:: operator==(const DSString &data1) const {
      // check different sizes, if sizes are differet, not equal
      if(len != data1.len){
         return false;
      }
      //check if they are same letter
      for(size_t i = 0; i < len; i++){
         if(data[i] != data1.data[i]){
            return false;
            }
      }
      return true;
    }
    bool DSString:: operator<(const DSString &data1) const {
      bool less = false;
      for(size_t i = 0; i < len+1; i++){
         if(data[i] < data1.data[i]){
            return true;
         } else if(data[i] > data1.data[i]){
            return false;
         }
      }
      return less;
    }
    //tokenization function
    std::vector<DSString> DSString::tokenization(){
      std::vector<DSString> word;
      size_t start = 0;
      for(size_t i = 0; i < len; i++){
         if(!isalpha(data[i])){
            if(i > start){
               word.push_back(this->substring(start, i-start));
            }
            start = i+1;
         }
      }
      if(start != len){
         word.push_back(this->substring(start, len-start));
      }
      return word;
    }

    //return DSString object contains the certain (or requested) substring
    DSString DSString::substring(size_t start, size_t numChars) const{
      if(start >= len || start + numChars > len) {
         numChars = len - start;
      }
      DSString substring;
      substring.len = numChars;
      substring.data = new char[numChars + 1];
      for(size_t i = 0; i < numChars; i++){
         substring.data[i] = data[start + i];
      }
      substring.data[numChars] = '\0';
      return substring;
    }
    //return new string to all lowercase
      DSString DSString::toLower() const{
      DSString copy;
      copy.len = len;
      copy.data = new char[len +1];
      for(size_t i = 0; i < copy.len; i++) {
         if(data[i] >= 'A' && data[i] <= 'Z') {
            copy.data[i] = data[i] + ('a' - 'A');
         } else {
            copy.data[i] = data[i];
         }
      }
      copy.data[len] = '\0';
      return copy;
    }
    // return pointer
    char* DSString:: c_str() const{
      return data;
    }
    //print function 
    std::ostream &operator<<(std::ostream &out, const DSString &data1){
      out << data1.data;
      return out;
    }                 

