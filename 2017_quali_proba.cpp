#include "include/codejam.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>


using namespace std;



class codejam2: public virtual codejam{
public:
	codejam2(int argc, char** argv): codejam(argc,argv){}
    void flip(string& str, size_t index, size_t size){
        for (size_t i = index; i < index+size; ++i){
            if (str[i] == '+') str[i] = '-';
            else str[i] = '+';
        }
    }
    virtual int thread(){
        string cakerow;
        size_t flipsize;
        codejam::input_stream >> cakerow >> flipsize;
        size_t result = 0, i;
        for (i = 0; i < cakerow.size()+1-flipsize; ++i){
            if (cakerow[i]=='-'){
                ++result;
                flip(cakerow,i,flipsize);
            }
        }
        for (; i < cakerow.size(); ++i){
            if (cakerow[i]=='-'){
                result=-1;
                break;
            }
        }
        if (result != -1) codejam::output_stream << result;
        else codejam::output_stream << "IMPOSSIBLE";
        return 0;
	}
};

int main(int argc, char** argv){
	codejam2 program(argc,argv);
    program.exec();
	return 0;
}
