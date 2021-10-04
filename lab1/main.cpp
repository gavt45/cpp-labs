#include <iostream>
#include <iterator>
#include <boost/program_options.hpp>
#include <exception>
#include <string>

#include "HashCalc.h"

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::string;
using std::ifstream;
using std::runtime_error;
namespace po = boost::program_options;

int main(int ac, char** av){
    string filename, mode;
    ifstream file;
    po::options_description desc("Варианты запуска программы");

    try {
        desc.add_options()
                ("help,h", "вывести справочную информацию об использовании и завершить работу;")
                ("filename,f", po::value<string>()->required(), "посчитать переданный вариант хеша переданного файла;")
                ("mode,m", po::value<string>()->default_value("adler32"), "adler32 или sum64");

        po::variables_map vm;
        po::store(po::parse_command_line(ac, av, desc), vm);
        po::notify(vm);

        if (vm.count("help")) {
            cout << desc << "\n";
            return 0;
        }
        mode = vm["mode"].as<string>();
        if (mode != "adler32" && mode != "sum64")
            throw runtime_error("Mode should be adler32 or sum64");

        filename = vm["filename"].as<string>();

        file.open(filename, std::ios::binary);

        if (!file.is_open())
            throw runtime_error("File not found!");

        if (mode == "adler32"){
            uint32_t hash = HashCalc::adler32(file);

            cout << "Hash: 0x" << std::hex << hash << "\n";
        } else {
            uint64_t hash = HashCalc::sum64(file);

            cout << "Hash: 0x" << std::hex << hash << "\n";
        }

    } catch(exception& e) {
        cerr << "error: " << e.what() << "\n";
        cerr << "help: " << desc << "\n";
        return 1;
    } catch(...) {
        cerr << "Exception of unknown type!\n";
        return 1;
    }
    return 0;
}