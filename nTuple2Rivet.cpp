#include "ntuplereader/nTupleReader.h"
#include "Rivet/AnalysisHandler.hh"
#include "Rivet/Tools/RivetPaths.hh"
#include "Rivet/Tools/Logging.hh"
#include <cmath>

int main(int argc,char *argv[]){


  int index;
  int c;
  std::string analysis("unset");
  std::string outfile("unset");
  opterr = 0;

  int nPoints=10000000000;

  
  while ((c = getopt (argc, argv, "a:o:n:")) != -1)
    switch (c)
      {
      case 'a':
	analysis=std::string(optarg);
        break;
      case 'o':
	outfile=std::string(optarg);
        break;
      case 'n':
        nPoints = std::stoi(optarg);
        break;
      case '?':
        if (optopt == 'n' || optopt == 'a' || optopt == 'o' )
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }


  if (analysis=="unset"){
    printf("Need an analysis! Please set it with the -a option");
    abort();
  }
  if (outfile=="unset"){
    outfile=analysis+".yoda";
  }


  printf ("will run with parameters :\n  analysis = %s, output file = %s, nPoints = %d\n",
          analysis.c_str(), outfile.c_str() , nPoints);





  
  Rivet::AnalysisHandler rivet;
  rivet.addAnalysis(analysis.c_str());
  if (rivet.analysisNames().size() != 1) {
    std::cerr << "No analysis " << argv[1] << " found! Try export RIVET_ANALYSIS_PATH=THEPATHWHEREYOUHAVETHEANALYSIS" << std::endl;
    return 1;
  }

  nTupleReader r;

  for (index = optind; index < argc; index++){
    printf ("nTuple file %s added!\n", argv[index]);
    r.addFile(argv[index]);
  }

  //  r.setPDF("CT10nlo.LHgrid");
  r.setPDF("MMHT2014nlo68cl");
  r.setCMSEnergy(7000);
  r.setColliderType(pp);


  long nE=0;

  while(r.nextEntry() && nE<nPoints){
    HepMC::GenEvent evt;
    r.fillHepMC(evt,r.getCrossSection(),r.getCrossSectionError());
    rivet.analyze(evt);
    nE++;
    if (nE%100==0){
      std::cout << nE << std::endl; 
    }
  }

  std::cout << "cross section:" <<  r.getCrossSection() << " +- " << r.getCrossSectionError() <<  std::endl;

  rivet.setCrossSection(r.getCrossSection());
  rivet.finalize();
  rivet.writeData(outfile);

  return 0;
 
}
