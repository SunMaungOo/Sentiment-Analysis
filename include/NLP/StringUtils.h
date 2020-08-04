#ifndef STRING_UTILS_H

#define STRING_UTILS_H

#include <string>
#include <memory>
#include <vector>
#include <unordered_set>

namespace NLP
{
    void string_lower(std::string& str);
    
    void string_left_trim(std::string& str);

    void string_right_trim(std::string& str);

    void string_trim(std::string& str);

    std::unique_ptr<std::vector<std::string>> string_split(const std::string& str, 
    const std::string& delimiter);

    bool string_is_white_space(const std::string& str);

    /**
    * Return:
    * Unique word in the sentence
    */
    std::unordered_set<std::string> extract_words(std::string& sentence);
}

#endif