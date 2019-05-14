import FWCore.ParameterSet.Config as cms
import os

#------------
# Var parsing
#------------
from FWCore.ParameterSet.VarParsing import VarParsing
options = VarParsing('Analysis')

options.register(
    'isData',
    'False',
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "data flag")
options.register(
    'doPreselection',
    'True',
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "preselection flag")
options.register(
    'doMuon',
    'False',
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "muon preselection flag")
options.register(
    'doElectron',
    'False',
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "electron preselection flag")
options.register(
    'year',
    '2016',
    VarParsing.multiplicity.singleton,
    VarParsing.varType.string,
    "data taking year")

options.parseArguments()


#---------------
# My definitions
#---------------
sourceTag = "PoolSource" # for global runs
inputTagRaw = "source"   # for global runs


#-----------------------------------
# Standard CMSSW Imports/Definitions
#-----------------------------------
import FWCore.ParameterSet.Config as cms
process = cms.Process('Analysis')


#-----------
# Log output
#-----------
process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.threshold = 'DEBUG'
process.MessageLogger.cerr.FwkReport.reportEvery = 1
process.options = cms.untracked.PSet(
    wantSummary = cms.untracked.bool(True),
    SkipEvent = cms.untracked.vstring('ProductNotFound'),
    )



#-----------------
# Files to process
#-----------------
process.load("Configuration.StandardSequences.GeometryDB_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
from Configuration.AlCa.GlobalTag import GlobalTag
if options.year is '2016':
    process.GlobalTag.globaltag = '94X_dataRun2_v10'
if options.year is '2017':
    process.GlobalTag.globaltag = '94X_dataRun2_v11'
if options.year is '2018':
    process.GlobalTag.globaltag = '102X_dataRun2_Sep2018ABC_v2'

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
    )
process.source = cms.Source(
    sourceTag,
    skipEvents = cms.untracked.uint32(0),
    fileNames = cms.untracked.vstring(
        # MC signal 2016
        'file:/tmp/abenagli/8E7DBB6B-5F3C-E911-89C4-0242AC130002.root'
        #'/store/mc/RunIISummer16MiniAODv3/GluGluHToZG_M-125_13TeV_powheg_pythia8_CUETP8M1Down/MINIAODSIM/PUMoriond17_94X_mcRun2_asymptotic_v3-v2/120000/8E7DBB6B-5F3C-E911-89C4-0242AC130002.root'
        )
    )


#--------------
# Output ntuple
#--------------
process.TFileService = cms.Service(
    "TFileService", 
    fileName = cms.string("ntuple.root"),
    closeFileFast = cms.untracked.bool(True)
    )


#------------------------------
# Ntuple Sequences Definition
#------------------------------
process.load('HiggsToZGamma.Analysis.Preselection_cfi')
process.load('HiggsToZGamma.Analysis.DumpReco_cfi')
if not options.isData:
    process.load('HiggsToZGamma.Analysis.DumpPU_cfi')
    process.load('HiggsToZGamma.Analysis.DumpGenParticles_cfi')

process.ntupleSequence = cms.Sequence()

if options.isData is False:
    process.ntupleSequence += process.DumpPU

if options.doPreselection is True:
    if options.doMuon is True:
        print "### doing muon"
        process.Preselection.doMuon = cms.bool(True)
    if options.doElectron is True:
        print "### doing electron"
        process.Preselection.doElectron = cms.bool(True)
    process.ntupleSequence += process.Preselection

process.ntupleSequence += process.DumpReco

if options.isData is False:
    process.ntupleSequence += process.DumpGenParticles
    process.DumpGenParticles.verbosity = cms.bool(False)



#----------------------------
# Ele/Photon ID
#----------------------------
from RecoEgamma.EgammaTools.EgammaPostRecoTools import setupEgammaPostRecoSeq

egammaIDString = ''
if options.year == '2016' :
    egammaIDString = '2016-Legacy'
if options.year == '2017' :
    egammaIDString = '2017-Nov17ReReco'
if options.year == '2018' :
    egammaIDString = '2018-Prompt'

setupEgammaPostRecoSeq(
    process,
    runEnergyCorrections=False, #corrections by default are fine so no need to re-run
    era=egammaIDString
)



#----------------------------
# Paths/Sequences Definitions
#----------------------------
process.p = cms.Path(
    process.egammaPostRecoSeq+
    process.ntupleSequence
)
