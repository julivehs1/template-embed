// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include "stringify.h"

const char* a = "te\\s\"to";



void singleMapping(std::ofstream& out, std::ifstream& in, const std::string variable){
    out << "const char* " << variable << " = \"\"\n";

    if(in.is_open()){
        std::string line;
        while(std::getline(in, line)){
            out << "\t" << "\"" << stringify(line);
            if(!in.eof()){
                out << "\\n";
            }
            out << "\"" << "\n";
        }
    }
    out << "\t" << ";" << "\n";
    out << "\n";
}


int main (int argc, char *argv[]) {
    if (argc > 1) {
        //Make it
        std::ofstream header_file;
        header_file.open(argv[1]);
        std::string include_guard = makeIncludeGuard(std::filesystem::path(argv[1]));
        header_file << "#ifndef " << include_guard << "\n";
        header_file << "#define " << include_guard << "\n";
        header_file << "\n";

        for(int i = 2; i < argc; i++){
            std::string current = argv[i];
            std::size_t pos = current.find("=");
            std::string variable = current.substr(0, pos);
            std::string filename = current.substr(pos + 1);

            std::ifstream file(filename);
            singleMapping(header_file, file, variable);
            file.close();
        }

        header_file << "#endif // " << include_guard << "\n";
        header_file.close();
    }
}