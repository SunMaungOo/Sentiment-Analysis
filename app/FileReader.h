#ifndef FILE_READER_H

#define FILE_READER_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>	

class FileReader final{

    public:

    FileReader(const std::string& file_location,const bool& cache=true)
    :pfile{file_location},
    pcache{cache},
    pis_file_read{false}{
    }

    ~FileReader(){
        if(pfile.is_open()){
            pfile.close();
        }
    }

    std::vector<std::string> read_lines(){
    
        if(pcache && pis_file_read){
            return plines;
        }
        
        if(pfile.is_open()){

            std::string line;

            while(std::getline(pfile,line)){
                plines.push_back(line);    
            }
        }

        if(pcache){
            pis_file_read=true;
        }

        return plines;
    }

    private:

    std::fstream pfile;

    bool pcache;

    bool pis_file_read;

    std::vector<std::string> plines;

};


#endif