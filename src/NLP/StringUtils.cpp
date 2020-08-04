#include "StringUtils.h"
#include <algorithm>
#include <functional>
#include <cctype>

namespace NLP
{
    void string_lower(std::string& str)
    {
        std::for_each(str.begin(),str.end(),[](char& c){
            c = tolower(c);
        });
    }

    void string_left_trim(std::string& str)
    {
        str.erase(str.begin(),std::find_if(str.begin(),str.end(),[](int c){
            return !std::isspace(c);   
        }));
    }

    void string_right_trim(std::string& str)
    {
        str.erase(std::find_if(str.rbegin(),str.rend(),[](int c){
            return !std::isspace(c);
        }).base(),str.end());
    }

    void string_trim(std::string& str)
    {
        string_left_trim(str);

        string_right_trim(str);
    }

    std::unique_ptr<std::vector<std::string>> string_split(const std::string& str, 
    const std::string& delimiter)
    {
        std::string input = str;

        using VecSize = std::vector<std::string>::size_type;

        auto ptr = std::make_unique<std::vector<std::string>>();

        VecSize pos = 0;

        std::string token;

        while ((pos=input.find(delimiter))!=std::string::npos){
            token = input.substr(0,pos);

            ptr->push_back(token);

            input.erase(0,pos+delimiter.length());
        }
        
        ptr->push_back(input);

        return ptr;
    }

    bool string_is_white_space(const std::string& str)
    {
        if(!str.empty() && str.at(0)!='\u0020'){        
            return false;
        }

        auto pos = std::find_if(str.cbegin(),str.cend(),[](const auto& c){
            return c=='\u0020';
        });

        return pos==str.cend();
    }

    std::unordered_set<std::string> extract_words(std::string& sentence)
    {
        auto words = std::unordered_set<std::string>{};
  
        if(string_is_white_space(sentence)){
            return words;
        }

        string_trim(sentence);
        
        string_lower(sentence);
        
        auto blocks = std::move(string_split(sentence,"\u0020"));
        
        //remove punction 
         
        blocks->erase(std::remove_if(blocks->begin(),blocks->end(),[](std::string& str){

            return str.length()==1 && (std::ispunct(str[0])!=0);

        }),blocks->end());
        

        
        words.insert(blocks->begin(),blocks->end());
        
        return words;
    }
}