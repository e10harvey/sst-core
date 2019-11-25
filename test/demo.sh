#!/bin/bash
set -v
.././src/sst/core/sstunit
.././src/sst/core/sstunit -n badConfig
.././src/sst/core/sstunit -n goodConfig