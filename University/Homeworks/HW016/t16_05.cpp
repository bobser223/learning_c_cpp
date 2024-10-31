//
// Created by Volodymyr Avvakumov on 29.10.2024.
//
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
//#include "University/course_project/dict/HashDict.h"
//#include "University/course_project/dict/LinkedList_dict.h"


#include "../../course_project/dict/LinkedList_dict.h"
#include "../../course_project/dict/HashDict.h"

class Word{
protected:
    std::string curr_word;
    std::string word;
    std::string prefix;
    std::string root; // корінь
    std::string suffix;
    std::string ending;
public:
    explicit Word(std::string wrd): word(wrd), curr_word(wrd) {};
    explicit Word(char* wrd): word(wrd), curr_word(wrd) {};
    // fixme word = sum, curr = word;
    Word(std::string prefix, std::string root, std::string suffix, std::string ending): prefix(prefix), root(root), suffix(suffix), ending(ending){};
    Word(char* prefix,char* root, char* suffix, char* ending ){
      this -> prefix = prefix;
      this -> root = root;
      this -> suffix = suffix;
      this -> ending = ending;
    };
    // fixme end
    Word()= default;
    ~Word()= default;

    std::string getWord(){
        return this ->word;
    }

    std::string getPrefix() const{
        return prefix;
    }

    std::string getRoot() const{
        return prefix;
    }

    std::string getSuffix() const{
        return suffix;
    }

    std::string getEnding() {
        return ending;
    }

    void setWord(std::string wrd){
        this ->word = wrd;
    }

    void setPrefix(std::string pref){
        this->prefix = pref;
    }

    void setRoot(std::string rt){
        this->root = rt;
    }

    void setSuffix(std::string suff){
        this->suffix = suff;
    }

    void setEnding (std::string end){
        this->ending = end;
    }

    virtual void reset(){
        curr_word = word;
    }

};

class Verb:public Word{
private:
    bool plural_var = false;
    bool possessive_var = false;

    std::string forms[5];
//    HashDict<std::string, std::string> irregulars_1;
//    HashDict<std::string, std::string> irregulars_2;
    HashDict<std::string, std::array<std::string, 2>> irregulars;
public:
    Verb(std::string wrd):Word(wrd){
        readFileToDict("irregular.txt", irregulars);
    };
    Verb(char* wrd):Word(wrd){
        readFileToDict("irregular.txt", irregulars);
    };


    std::string base(){
        return forms[0];
    }

    void plural(){
        plural_var = true;
    }

    std::string pastSimple(){
        if (irregulars.is_in(Word::word)){
            curr_word = irregulars[word][0];
            return curr_word;
        }

        ending = "ed";
        curr_word = add_ed(this->word);
        return curr_word;
    }

    std::string pastParticiple(){
        if (irregulars.is_in(Word::word)){
            curr_word = irregulars[word][1];
            return curr_word;
        }

        ending = "ed";
        curr_word = add_ed(this->word);
        return curr_word;
    }

    std::string presentParticiple(){
        ending = "ing";
        curr_word = word + ending;
        return curr_word;
    }

    std::string personSingularPresent(){
        if (plural_var){
            ending = "";
            curr_word = word;
            return curr_word;
        }

        ending = "es";
        curr_word = word + ending;
        return curr_word;
    }

    virtual void reset() override{
        curr_word = word;
        plural_var = false;
        possessive_var = false;
    }
private:
    static std::string add_ed(const std::string& word_){
        if (word_[word_.size() -1] == 'e'){
            return word_.substr(0, word_.size() - 1) + "ed";
        }
        return word_ + "ed";
    }

    static void readFileToDict(const char* filename, HashDict<std::string, std::array<std::string, 2>>& dict){
        std::fstream f(filename, std::ios::in);
        if (!f.is_open()) {
            std::cerr << "Cannot open file: " << filename << std::endl;
            return;
        }

        std::string line;
        while (std::getline(f, line)) {
            std::istringstream ss(line);

            std::string key;
            if (!(ss >> key)) {
                continue;
            }

            std::array<std::string, 2> values;

            if (!(ss >> values[0] >> values[1])) {
                std::cerr << "Invalid line format in file: " << line << std::endl;
                continue;
            }


            dict.add(key, values);
        }
    }


};

class Nominative : public Word {
private:
    bool plural_var = false;
    bool possessive_var = false;

public:
    explicit Nominative(std::string wrd) : Word(wrd) {}

    std::string plural() {
        if (!plural_var) {
            if (word.back() == 's' || word.back() == 'x' || word.back() == 'z' ||
                (word.size() > 1 && word[word.size() - 2] == 'c' && word.back() == 'h') ||
                (word.size() > 1 && word[word.size() - 2] == 's' && word.back() == 'h')) {
                ending = "es";
            } else if (word.back() == 'y' && !isVowel(word[word.size() - 2])) {
                curr_word = word.substr(0, word.size() - 1) + "ies";
                plural_var = true;
                return curr_word;
            } else if (word.back() == 'o') {
                ending = "es";
            } else if (word.size() > 1 && (word.substr(word.size() - 2) == "fe" || word.back() == 'f')) {
                curr_word = (word.back() == 'f') ? word.substr(0, word.size() - 1) + "ves" : word.substr(0, word.size() - 2) + "ves";
                plural_var = true;
                return curr_word;
            } else {
                ending = "s";
            }
            curr_word = word + ending;
            plural_var = true;
        }
        return curr_word;
    }

    std::string singular() {
        if (plural_var) {
            curr_word = word;
            plural_var = false;
        }
        return curr_word;
    }

    std::string possessive() {
        if (!possessive_var) {
            possessive_var = true;
            if (plural_var) {
                ending = "'";
                curr_word += ending;
            } else {
                ending = "'s";
                curr_word += ending;
            }
        }
        return curr_word;
    }

    virtual void reset() override {
        curr_word = word;
        plural_var = false;
        possessive_var = false;
    }

private:
    static bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};

class Adjective : public Word {
public:
    explicit Adjective(std::string wrd) : Word(wrd) {}

    std::string positive() {
        return word;
    }

    std::string comparative() {
        return "more " + word;
    }

    std::string superlative() {
        return "most " + word;
    }

    virtual void reset() override {
        curr_word = word;
    }
};



int main(){
    Verb v("be");
    std::cout << v.getWord() << std::endl;
    std::cout << v.pastParticiple() << std::endl;
    Verb v2("move");
    std::cout << v2.getWord() << std::endl;
    std::cout << v2.pastParticiple() << std::endl;
    Verb v3("go");
    std::cout << v3.getWord() << std::endl;
    std::cout << v3.pastParticiple() << std::endl;
    v3.plural();
    std::cout << v3.personSingularPresent() << std::endl;
    v3.reset();
    std::cout << v3.personSingularPresent() << std::endl;
    Nominative n1("house");
    std::cout << n1.getWord() << std::endl;
    std::cout << n1.plural() << std::endl;

    return 0;
}