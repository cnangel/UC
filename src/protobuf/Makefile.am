# $Id: Makefile.am,v 1.0.0-0 2014/10/11 22:07:14 Cnangel Exp $

AUTOMAKE_OPTIONS				= foreign 

EXTRA_DIST						= $(wildcard ${top_srcdir}/src/protobuf/*.proto)
OBJECTS							= $(patsubst ${top_srcdir}/src/protobuf/%.proto,${top_srcdir}/src/interface/%.pb.cc,$(EXTRA_DIST))

${top_srcdir}/src/interface/%.pb.cc : %.proto
	protoc --proto_path=/usr/local/include:/usr/include -I$(srcdir) $< --cpp_out ${top_srcdir}/src/interface

all: $(OBJECTS)

CLEANFILES						= $(wildcard ${top_srcdir}/src/interface/*.pb.h ${top_srcdir}/src/interface/*.pb.cc)
