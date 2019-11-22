# -*- Makefile -*-
#
#

CC = $(MPICC)
CXX = $(MPICXX)
LIBCPPUTEST=/usr/local/lib/libCppUTest.a

AM_CPPFLAGS =  \
	-DTIXML_USE_STL \
	-DSST_BUILDING_CORE=1 \
	$(BOOST_CPPFLAGS) \
	$(ZOLTAN_CPPFLAGS) \
	$(PYTHON_CPPFLAGS) \
	$(LTDLINCL)

bin_PROGRAMS = exampleTest
	
exampleTest_SOURCES = \
	exampleTest.cc

exampleTest_LDADD = \
	$(LIBCPPUTEST)
