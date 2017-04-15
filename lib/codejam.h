#include <fstream>
#include <string>

class codejam{
private:
	std::streambuf *clog_orig, *cerr_orig;
    std::string infile,outfile;
public:
	codejam(int argc, char** argv);
	void disable_clog();
	void disable_cerr();
	void enable_clog();
	void enable_cerr();
	~codejam();

	std::ifstream input_stream;
	std::ofstream output_stream;

    int exec();
    virtual int thread() = 0;
};
