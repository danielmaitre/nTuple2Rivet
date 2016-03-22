#include "nTupleReader.h"
#include "Rivet/AnalysisHandler.hh"
#include "Rivet/Tools/RivetPaths.hh"
#include "Rivet/Tools/Logging.hh"
#include <cmath>

int main(int argc,char *argv[]){

  Rivet::AnalysisHandler rivet;
  rivet.addAnalysis(argv[1]);
  if (rivet.analysisNames().size() != 1) {
    std::cerr << "No analysis " << argv[1] << " found! Try export RIVET_ANALYSIS_PATH=THEPATHWHEREYOUHAVETHEANALYSIS" << std::endl;
    return 1;
  }

  nTupleReader r;

  for (int ii=2;ii<argc;ii++){
    r.addFile(argv[ii]);
  }

  //  r.setPDF("CT10nlo.LHgrid");
  r.setPDF("MMHT2014nlo68cl");
  r.setCMSEnergy(7000);
  r.setColliderType(pp);


  long nE=0;

  while(r.nextEntry()){
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
  rivet.writeData(std::string(argv[1])+".yoda");

  return 0;
 
}
