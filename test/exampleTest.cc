// Copyright 2009-2019 NTESS. Under the terms
// of Contract DE-NA0003525 with NTESS, the U.S.
// Government retains certain rights in this software.
// 
// Copyright (c) 2009-2019, NTESS
// All rights reserved.
// 
// This file is part of the SST software package. For license
// information, see the LICENSE file in the top level directory of the
// distribution.

#include <sst_config.h>
#include <sst/core/rankInfo.h>
#include <sst/core/config.h>

#include "CppUTest/TestHarness.h"
//#include "CppUTest/Test"
#include "CppUTest/CommandLineTestRunner.h"

using namespace SST;
using namespace SST::Core;

int myrank = 0;
RankInfo world_size;
RankInfo myRank;
// LEAKS in libcxx Config cfg;

TEST_GROUP(Example)
{
     void setup()
    {
        world_size = RankInfo(1, 1);
        myRank = RankInfo(0, 0);
    }

    void teardown()
    {
        world_size.~RankInfo();
        myRank.~RankInfo();
    }
};

TEST(Example, badConfig)
{
    Config cfg(world_size);
    CHECK(cfg.getNumThreads() < 0);
    CHECK_EQUAL(cfg.getNumRanks(), 0);
}

TEST(Example, goodConfig)
{
    Config cfg(world_size);
    CHECK(cfg.getNumThreads() > 0);
    CHECK_EQUAL(cfg.getNumRanks(), world_size.rank);
}

int main(int argc, char **argv)
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}