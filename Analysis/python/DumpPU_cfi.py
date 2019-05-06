import FWCore.ParameterSet.Config as cms

DumpPU = cms.EDAnalyzer(
    "DumpPU",
    ###---Input tags
    puInfoTag = cms.untracked.InputTag("slimmedAddPileupInfo", "", ""),
    
    ###---I/O options
    treeName = cms.untracked.string("PU_tree")
)
