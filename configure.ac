AC_INIT([nTuple2Rivet], [0.1], [maitreda@durham.ac.uk])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AM_DISABLE_STATIC
AC_PROG_CXX
m4_ifdef([AM_PROG_AR],[AM_PROG_AR])
AC_PROG_LIBTOOL


AC_CONFIG_FILES([
    Makefile
])


AC_ARG_WITH([hepmc-path], [AS_HELP_STRING([--with-hepmc-path],
          [location of the hepmc installation])],
          [use_hepmc_path=true
          AC_SUBST([HEPMC_CXXFLAGS], ["-I$with_hepmc_path/include -DUSE_HEPMC"])
	      AC_SUBST([HEPMC_LDFLAGS], ["-L$with_hepmc_path/lib/ -lHepMC -Wl,-rpath -Wl,$with_hepmc_path"])
	      ])
AM_CONDITIONAL([USE_HEPMC], [test "x$use_hepmc_path" == "xtrue" ])


AC_ARG_WITH([rivet-path], [AS_HELP_STRING([--with-rivet-path],
          [location of the rivet installation])],
          [AC_SUBST([RIVET_CXXFLAGS], ["`$with_rivet_path/bin/rivet-config --cppflags`"])
	      AC_SUBST([RIVET_LDFLAGS], ["`$with_rivet_path/bin/rivet-config --ldflags`"])
	      AC_SUBST([RIVET_LIBS], ["`$with_rivet_path/bin/rivet-config --libs`"])
	      ])


oldCPPFLAGS=$CPPFLAGS 
CPPFLAGS="$CPPFLAGS $RIVET_CXXFLAGS"
AC_LANG([C++])
AC_HEADER_STDC
AC_CHECK_HEADERS([Rivet/AnalysisHandler.hh],[],[AC_ERROR([Need Rivet headers, please specifiy the path to the Rivet installation with the --with-rivet-path option.])])
CPPFLAGS=$oldCPPFLAGS

AM_CONDITIONAL([USE_RIVET], [test "x$use_rivet_path" == "xtrue" ])



AC_ARG_WITH([root-path], [AS_HELP_STRING([--with-root-path],
          [location of the root installation])],
          [],
          [with_root_path=yes])

AS_IF([test "x$with_root_path" != xyes],
          [AC_SUBST([ROOT_CXXFLAGS], ["`$with_root_path/bin/root-config --cflags`"])
	   AC_SUBST([ROOT_LDFLAGS], ["`$with_root_path/bin/root-config --libs`"])
	   AC_SUBST([ROOTCINT], ["`$with_root_path/bin/root-config --prefix`/bin/rootcint"])
	   ROOTINCDIR=`$with_root_path/bin/root-config --incdir`
	  ],
          [AC_SUBST([ROOT_CXXFLAGS], [`root-config --cflags`])
	   AC_SUBST([ROOT_LDFLAGS], ["`root-config --libs`"])
	   AC_SUBST([ROOTCINT], ["`root-config --prefix`/bin/rootcint"])
	   ROOTINCDIR=`root-config --incdir`
])


AC_ARG_WITH([ntuplereader-path], [AS_HELP_STRING([--with-ntuplereader-path],
          [location of the ntuplereader installation])],
          [use_ntuplereader_path=true])

AS_IF([test "x$use_ntuplereader_path" == xtrue],
          [AC_SUBST([NTUPLEREADER_CXXFLAGS], ["`${with_ntuplereader_path}/bin/nTupleReader-config --cxxflags`"])
	  NTUPLEREADER_CPPFLAGS=`${with_ntuplereader_path}/bin/nTupleReader-config --cppflags`
	    AC_SUBST([NTUPLEREADER_CPPFLAGS], ["$NTUPLEREADER_CPPFLAGS"])
	    
	   AC_SUBST([NTUPLEREADER_LDFLAGS], ["`${with_ntuplereader_path}/bin/nTupleReader-config --libs`"])
	   AC_SUBST([NTUPLEREADER_LIBS], ["`${with_ntuplereader_path}/bin/nTupleReader-config --libs`"])
	  ],
          [AC_SUBST([NTUPLEREADER_CXXFLAGS], [`nTupleReader-config --cxxflags`])
	  AC_SUBST([NTUPLEREADER_CPPFLAGS], [`nTupleReader-config --cppflags`])
	   AC_SUBST([NTUPLEREADER_LDFLAGS], ["`nTupleReader-config --libs`"])
	   AC_SUBST([NTUPLEREADER_LIBS], ["`nTupleReader-config --libs`"])
	   
])




oldCPPFLAGS=$CPPFLAGS
CPPFLAGS="$CPPFLAGS $NTUPLEREADER_CXXFLAGS $ROOTINCDIR"
echo $CPPFLAGS
echo $NTUPLEREADER_CXXFLAGS
echo $ROOTINCDIR
AC_LANG([C++])
AC_HEADER_STDC
AC_CHECK_HEADERS([ntuplereader/nTupleReader.h],[],[AC_ERROR([Need nTupleReader headers, please specifiy the path to the nTupleReader installation with the --with-ntuplereader-path option.])])
CPPFLAGS=$oldCPPFLAGS




AC_SUBST([AM_CPPFLAGS])


if test "x$use_hepmc_path" = "xtrue" ; then 
	echo "Use hepmc path: $with_hepmc_path" 
fi

if test x$pythoninterface = xtrue ; then
	echo "Use python interface"
fi






AC_OUTPUT
