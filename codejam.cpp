#include <string>
#include <vector>
#include <iostream>
#include "codejam.h"


codejam::codejam(int argc, char** argv){
	clog_orig = std::clog.rdbuf();
	cerr_orig = std::cerr.rdbuf();
	std::vector<std::string> filenames;
	std::string outname;
	bool is_debug=false;
	for (int i = 1; i < argc; ++i)
		if (std::string(argv[i]).compare("--debug")==0) 
			is_debug = true;
		else if (std::string(argv[i]).compare("-o")==0){
			if (!(i < argc-1)) std::cerr << "No output file name!";
            else if (outfile.size()!=0) std::cerr << "No multiple output!";
            else outfile = std::string(argv[++i]);
		}else
			filenames.push_back(std::string(argv[i]));
	if (!is_debug) disable_clog();
    if (filenames.size()>1) {
        std::cerr << "No multiple input files!";
        throw std::ios_base::failure("Multiple Input Files");
    }
    else if (filenames.size()<1) {
        std::cerr << "No input files!";
        throw std::ios_base::failure("No Input File");
    }
    else infile = filenames[0];
    if (outfile.size()==0) outfile = "output.txt";
}

int codejam::exec(){
    int result=0;
    input_stream.open(infile);
    output_stream.open(outfile);
    size_t T;
    input_stream >> T;
    for (size_t i = 0; i < T; ++i){
        output_stream << "Case #" << i+1 << ": ";
        result |= (this->thread());
        output_stream << std::endl;
    }
    input_stream.close();
    output_stream.close();
    return result;
}

void codejam::disable_clog() {std::clog.rdbuf(0);}
void codejam::disable_cerr() {std::cerr.rdbuf(0);}
void codejam::enable_clog() {std::clog.rdbuf(clog_orig);}
void codejam::enable_cerr() {std::cerr.rdbuf(cerr_orig);}
codejam::~codejam() {
    //output_stream.close();
    //input_stream.close();
	enable_cerr(); enable_clog();
}

//void codejam::thread() {}
