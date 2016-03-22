bin_PROGRAMS= nTuple2Rivet
#lib_LTLIBRARIES=libNTR.la libInfo.la

#libNTR_la_SOURCES = \
#	pdf.cpp pdf.h \
#	NtupleInfo.h NtupleInfo.cpp \
#	EventReaderBase.cpp EventReaderBase.h \
#	weightFunctions.cpp weightFunctions.h \
#	nTupleReader.cpp nTupleReader.h


nTuple2Rivet_SOURCES = nTuple2Rivet.cpp

#include HepMC first because HepMC is also installed at the same 
#place as other libraries, but with the wrong version
AM_LDFLAGS =  $(NTUPLEREADER_LDFLAGS)
AM_LDFLAGS += $(RIVET_LDFLAGS)
AM_LDFLAGS += $(HEPMC_LDFLAGS)

AM_CXXFLAGS =  $(NTUPLEREADER_CXXFLAGS)
AM_CXXFLAGS += $(RIVET_CXXFLAGS)
AM_CXXFLAGS += $(HEPMC_CXXFLAGS)




nTuple2Rivet_LDADD = $(NTUPLEREADER_LIBS) $(RIVET_LIBS) $(HEPMC_LIBS)


#pkginclude_HEADERS = nTupleReader.h EventReaderBase.h NtupleInfo.h

