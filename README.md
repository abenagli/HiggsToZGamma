# Higgs to Z gamma analysis
Code to produce ntuples for the analysis of H > Zg decays

## Setup
   ```
   cmsrel CMSSW_10_5_0
   cd CMSSW_10_5_0/src
   cmsenv
   git cms-init
   git cms-addpkg
   git clone -b CMSSW git@github.com:abenagli/DynamicTTree.git ExternalTools/DynamicTTree/
   git clone git@github.com:abenagli/HiggsToZGamma.git
   scram b -j 8
   ```
