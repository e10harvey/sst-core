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

//#include <sst_config.h>
//#include <sst/core/rankInfo.h>

#include "CppUTest/TestHarness.h"
//#include "CppUTest/Test"
#include "CppUTest/CommandLineTestRunner.h"

//using namespace SST;

TEST_GROUP(Example)
{
    /* void setup()
    {
        int myrank = 0;
        RankInfo world_size(1, 1);
        RankInfo myRank(0, 0);

        Config cfg(world_size);
    }

    void teardown()
    {

    } */
};

TEST(Example, createComponent)
{
    FAIL("Fail me!");
}

int main(int argc, char **argv)
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}