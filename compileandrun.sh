#! /bin/bash
Rscript -e "system('./configure')"
cd src
make
cd ../
R --vanilla < test.r
