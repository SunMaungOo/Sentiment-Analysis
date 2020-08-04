#include "NLP.h"
#include "MemoryDb.h"
#include "FileReader.h"
#include "CLI11.hpp"
#include "FileDb.h"
#include "StringUtils.h"

#include <iostream>
#include <filesystem>
#include <memory>
#include <fstream>
#include <string>

FileDb create_database(const std::string& pos_location,
const std::string& neg_location)
{
    FileReader pos_reader{pos_location};

    std::vector<std::string> pos_lines = std::move(pos_reader.read_lines());

    FileReader neg_reader{neg_location};

    std::vector<std::string> neg_lines = std::move(neg_reader.read_lines());

    FileDb db{pos_lines,neg_lines};

    return db;
}

void interactive_mode(NLP::NLP& nlp)
{
    std::cout << "Type !q to exit the program" << "\n";

    std::string user_input = "";

    while(true){

        user_input.clear();

        std::cout << "Sentence : ";

        std::getline(std::cin,user_input);

        if(user_input=="!q"){
            break;
        }

        NLP::string_trim(user_input);

        if(!NLP::string_is_white_space(user_input)){

            auto prob = nlp.analysis(user_input);

            std::cout << "Positive:" << std::get<0>(prob) << " %\n";
            std::cout << "Negative:" << std::get<1>(prob) << " %\n";
            std::cout << "==============\n";
        }

    }
}

int main(int argc,char ** argv)
{ 
    std::cout << "Welcome to sentiment analysis program develop by Sun Maung Oo" << "\n";

    CLI::App app{"Sentiment Analysis"};

    std::string pos_location = "";

    std::string neg_location = "";

    bool is_interactive_mode = true;

    bool is_pipe_mode = false;

    std::string data = "";

    app.add_option("--pos",pos_location,"Location to file which have positive review")
    ->required()
    ->check(CLI::ExistingFile);
    app.add_option("--neg",neg_location,"Location to file which have negative review")
    ->required()
    ->check(CLI::ExistingFile);

    try{
        app.parse(argc,argv);
    }catch(const CLI::ParseError &e){

        std::cerr << "ERROR";

        return app.exit(e);
    }

    FileDb db = std::move(create_database(pos_location,neg_location));

    NLP::NLP nlp{&db};

    interactive_mode(nlp);

}