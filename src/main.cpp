#include "pch.h"

#include <signal.h>
#include "mkl.h"

#include "PardisoInterface.h"

////////////////////////////////////////////////////////////////////////////


void SoftwareInfo() {
    
    
    int DSECOND = dsecnd();

    int tcount = std::thread::hardware_concurrency();
    int ccount = std::thread::hardware_concurrency();
    int vsize = 4;


    

    std::string assetversion = std::string(ASSET_VERSIONSTRING);
    std::string osversion = std::string(ASSET_OS) + " " + std::string(ASSET_OSVERSION);

    std::string syscorecount = std::to_string(ccount);
    std::string systhreadcount = std::to_string(tcount);


    std::string compiler = std::string(ASSET_COMPILERSTRING) + std::string(" ") + std::string(ASSET_COMPILERVERSION);
    std::string pythonv = std::to_string(PY_MAJOR_VERSION) + "." + std::to_string(PY_MINOR_VERSION);
    std::string vecversion;
    if (vsize == 2) vecversion = "SSE - 128 bit - 2 doubles";
    else if (vsize == 4) vecversion = "AVX2 - 256 bit - 4 doubles";
    else if (vsize == 8) vecversion = "AVX512 - 512 bit - 8 doubles";

    
#ifdef __AVX2__
    Is avx 2 being enabled ?????
#endif
    
    
    
    fmt::print(fmt::fg(fmt::color::white), "{0:=^{1}}\n\n", "", 79);
    fmt::print(fmt::fg(fmt::color::royal_blue), " Software Version     : "); fmt::print(fmt::fg(fmt::color::white), assetversion); fmt::print("\n");
    fmt::print(fmt::fg(fmt::color::royal_blue), " Python   Version     : "); fmt::print(fmt::fg(fmt::color::white), pythonv); fmt::print("\n");
    
    fmt::print(fmt::fg(fmt::color::royal_blue), " System Core Count    : "); fmt::print(fmt::fg(fmt::color::white), syscorecount); fmt::print("\n");
    fmt::print(fmt::fg(fmt::color::royal_blue), " System Thread Count  : "); fmt::print(fmt::fg(fmt::color::white), systhreadcount); fmt::print("\n");
    fmt::print(fmt::fg(fmt::color::royal_blue), " Vectorization Mode   : "); fmt::print(fmt::fg(fmt::color::white), vecversion); fmt::print("\n");
    fmt::print(fmt::fg(fmt::color::royal_blue), " Linear Solver        : "); fmt::print(fmt::fg(fmt::color::white), "Intel MKL Pardiso"); fmt::print("\n");

    fmt::print(fmt::fg(fmt::color::royal_blue), " Compiled With        : "); fmt::print(fmt::fg(fmt::color::white), compiler); fmt::print("\n");
    fmt::print(fmt::fg(fmt::color::royal_blue), " Compiled On/For      : "); fmt::print(fmt::fg(fmt::color::white), osversion); fmt::print("\n");



    fmt::print(fmt::fg(fmt::color::white), "{0:=^{1}}\n\n", "", 79);


}

void signal_callback(int sig) {
    fmt::print(fmt::fg(fmt::color::red),
        "Interrupt signal [{0}] received, terminating program.\n\n\n\n\n\n\n\n",sig);
    exit(sig);
}

int main() {
   

    Eigen::PardisoLDLT<Eigen::SparseMatrix<double, Eigen::RowMajor>> m;

    

    return 0;
}



PYBIND11_MODULE(_depreltest, m) {


  signal(SIGINT, signal_callback);

  m.doc() = "DEPRELTEST";  // optional module docstring
  m.def("PyMain", &main);
  m.def("SoftwareInfo", &SoftwareInfo);


  

  
}
