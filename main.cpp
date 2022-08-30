#include <iostream>
#include "vector"
#include "sstream"

enum note
{
    DO  = 1U<<0,
    RE  = 1U<<1,
    MI  = 1U<<2,
    FA  = 1U<<3,
    SOL = 1U<<4,
    LA  = 1U<<5,
    SI  = 1U<<6
};

int melody[12] ;

std::stringstream istream;

std::string notes_to_string(){
    std::string result="";
    for(int i=0;i<12;++i){
        if(melody[i] & DO)  result+=" DO";
        if(melody[i] & RE)  result+=" RE";
        if(melody[i] & MI)  result+=" MI";
        if(melody[i] & FA)  result+=" FA";
        if(melody[i] & SOL) result+=" SOL";
        if(melody[i] & LA)  result+=" LA";
        if(melody[i] & SI)  result+=" SI";
        result+= "\n";
    }
    return result;
}

bool correctNotes(std::string str){
    for(int i=0;i<str.size();++i){
        if(str[i]>'7'||str[i]<'1') return false;
        str[i]-=1;
    }
    return true;
}

int input_accord(){
    std::string input = "";
    int result=0;
    bool notCorrect=true;
    do {
        std::cout << "Input notes [1..7]:";
        std::cin >> input;
        notCorrect=!correctNotes(input);
        if (notCorrect) { std::cout << "Not correct. Try again\n" ; }
    }while (notCorrect);
    for (int i=0;i<input.size();++i){
        result|=1<<(input[i]-49);
    }
    return result;
}

void inputMelody(){
    for (int i=0;i<12;++i){
        melody[i]=input_accord();
    }
}

int main() {
    inputMelody();
    std::cout << notes_to_string();
}
