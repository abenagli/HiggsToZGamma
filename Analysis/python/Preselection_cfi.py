import FWCore.ParameterSet.Config as cms

Preselection = cms.EDFilter(
    "Preselection",
    ###---Input tags
    muonsTag = cms.untracked.InputTag("slimmedMuons", "", ""),
    electronsTag = cms.untracked.InputTag("slimmedElectrons", "", ""),
    ###---Flags
    doMuon = cms.bool(False),
    doElectron = cms.bool(False),
    ###---Cuts
    cut_pt1Min = cms.double(15.),
    cut_pt2Min = cms.double(7.),
    cut_mInvMin = cms.double(50.)
)
