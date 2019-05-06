from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'HtoMuMu_ntuples'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = False

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'makeNtuple_cfg.py'
config.JobType.pyCfgParams = ['isData=False', 'doPreselection=True']

config.Data.inputDataset = '/GluGlu_HToMuMu_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM'
config.Data.inputDBS = 'global'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 10
config.Data.outLFNDirBase = '/store/user/abenagli/HMUMU/ntuples/mc_2016_v3/'
config.Data.publication = False
config.Data.outputDatasetTag = 'HtoMuMu_ntuples_v1'

config.Site.storageSite = 'T2_CH_CERN'
