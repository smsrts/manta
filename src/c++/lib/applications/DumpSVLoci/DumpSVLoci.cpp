// -*- mode: c++; indent-tabs-mode: nil; -*-
//
// Manta
// Copyright (c) 2013 Illumina, Inc.
//
// This software is provided under the terms and conditions of the
// Illumina Open Source Software License 1.
//
// You should have received a copy of the Illumina Open Source
// Software License 1 along with this program. If not, see
// <https://github.com/downloads/sequencing/licenses/>.
//

///
/// \author Chris Saunders
///

#include "DumpSVLoci.hh"
#include "DSLOptions.hh"

#include "manta/SVLocusSet.hh"

#include <iostream>



static
void
runDSL(const DSLOptions& opt) {

    SVLocusSet set;

    set.load(opt.graphFilename.c_str());

    std::ostream& os(std::cout);
    if(opt.region.empty())
    {
        set.dump(os);
    }
    else
    {
#if 0
        int ref,beg,end;
        bam_parse_region(_bfp->header, region, &ref, &beg, &end); // parse the region

        set.dumpRegion(os);
#endif
    }
}



void
DumpSVLoci::
runInternal(int argc, char* argv[]) const {

    DSLOptions opt;

    parseDSLOptions(*this,argc,argv,opt);
    runDSL(opt);
}