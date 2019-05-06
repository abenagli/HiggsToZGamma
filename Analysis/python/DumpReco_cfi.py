import FWCore.ParameterSet.Config as cms

DumpReco = cms.EDAnalyzer(
    "DumpReco",
    ###---Input tags
    trgsTag = cms.untracked.InputTag("TriggerResults", "", "HLT"),
    trgPrescalesTag = cms.untracked.InputTag("patTrigger", "", ""),
    vtxTag = cms.untracked.InputTag("offlineSlimmedPrimaryVertices", "", ""),
    rhoAllTag = cms.untracked.InputTag("fixedGridRhoFastjetAll", "", ""),
    rhoCentralTag = cms.untracked.InputTag("fixedGridRhoFastjetCentral", "", ""),
    rhoCentralNeutralTag = cms.untracked.InputTag("fixedGridRhoFastjetCentralNeutral", "", ""),
    rhoCentralChargedPUTag = cms.untracked.InputTag("fixedGridRhoFastjetCentralChargedPileUp", "", ""),
    pfCandidatesTag = cms.untracked.InputTag("packedPFCandidates", "", ""),
    muonsTag = cms.untracked.InputTag("slimmedMuons", "", ""),
    electronsTag = cms.untracked.InputTag("slimmedElectrons", "", ""),
    photonsTag = cms.untracked.InputTag("slimmedPhotons", "", ""),
    jetsTag = cms.untracked.InputTag("slimmedJets", "", ""),
    jetsPuppiTag = cms.untracked.InputTag("slimmedJetsPuppi", "", ""),
    metsTag = cms.untracked.InputTag("slimmedMETs", "", ""),
    metsPuppiTag = cms.untracked.InputTag("slimmedMETsPuppi", "", ""),
    
    bDiscriminators = cms.untracked.vstring(
        'pfCombinedInclusiveSecondaryVertexV2BJetTags',
        'pfCombinedMVAV2BJetTags'
        ),
    
    ###---I/O options
    treeName = cms.untracked.string("reco_tree")
)
