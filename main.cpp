#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <sstream>
#include <algorithm>


/*GLOBAL FUNCTIONS*/

bool isPalindrome(std::string);
bool verifyRepeatedPalindrome(std::string);
void readFile();
std::string eraseSpecialChars(std::string);
std::string toLowerCase(std::string);
bool isPermutedPalindrome(std::string);

/*GLOBAL VARIABLES */

const std::regex regex ("[[:punct:]]");
std::smatch matches;
std::string chars(".,?!.:;_,!'\"-");
int numPalindromes = 0;
int numPermutedPalindromes = 0;

int main(int argc, char const *argv[])
{
     readFile();
   
    return 0;
}



void readFile(){

std::string file;
std::ifstream ist {file};
std::string temp;
std::vector<std::string> vec;

//the-tragedy-of-hamlet-by-w-shakspeare
//wikipedia-palindrome-article
ist.open("the-tragedy-of-hamlet-by-w-shakspeare", std::ifstream::in);
std::string word;


if(!ist.is_open()) return;

        while (ist >> word){
           bool match = std::regex_search(word, matches, regex);

                if ((match == true)) {
                        std::string newWord = eraseSpecialChars(word);
                        if(newWord.length() >= 3){
                            isPalindrome(newWord);
                            isPermutedPalindrome(newWord);
                        }

                }
                if(word.length() > 3){
                    isPalindrome(word);
                    isPermutedPalindrome(word);
                }
        }
        ist.close();

}

std::string eraseSpecialChars(std::string str){

std::string newStr;
    newStr.assign(str);

    for(int i = 0; i < str.length(); i++){
        for(int  j = 0; j < chars.length(); j++ ){
            if(str.at(i) == chars.at(j)){
                char c = str.at(i);
                newStr.erase(std::remove(newStr.begin(), newStr.end(), c), newStr.end());
            }
        }

    }

return newStr;
}

bool isPalindrome(std::string str){

    std::string aux = toLowerCase(str);
    bool flag = true;

    short strLength = aux.length();

    for(size_t i = 0; i < strLength; i++){
        if (aux.at(i) != aux.at(strLength - i - 1)) {
            flag = false;
            break;
        }
    }
    if(flag){
         std::cout << aux << " is The Palindrome #" << ++numPalindromes << "\n";
    }

return flag;
}

std::string toLowerCase(std::string str){
 
  std::string aux("");
    std::for_each(str.begin(), str.end(), [](char & c){
            c = ::tolower(c);
    });
    aux.assign(str);

 return aux;
}
bool isPermutedPalindrome(std::string palindrome){

bool flag;
short count;
short times = 0;
short ctime = 0;
short numPalindrome = 0;

std::string str = toLowerCase(palindrome);
if(str.length() % 2 == 0){
    count =  str.length() / 2;
}else{
    count =  ((str.length() - 1) / 2);
}

for (size_t i = 0; i < str.length(); i++) {
    for (size_t k = 0; k < str.length(); k++){
        if(str.at(i) == str.at(k)){
           ctime++;      
        }
    }  
    if(ctime > 1){
        times++;
        ctime = 0;
    }  
    ctime = 0;
}
times = times / 2;

if(count != times ){
    flag = false;   
}else {
    flag = true;   
     std::cout << str << " is The permuted palindrome #" << ++numPermutedPalindromes << "\n";
}

return flag;
}