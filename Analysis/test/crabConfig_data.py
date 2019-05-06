from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'HtoMuMu_ntuples'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = False

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'makeNtuple_cfg.py'
config.JobType.pyCfgParams = ['isData=True', 'doPreselection=True']

config.Data.inputDataset = '/SingleMuon/Run2016B-03Feb2017_ver2-v2/MINIAOD'
config.Data.inputDBS = 'global'
config.Data.splitting = 'LumiBased'
config.Data.unitsPerJob = 10
config.Data.lumiMask = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/ReReco/Final/Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt'
config.Data.outLFNDirBase = '/store/user/abenagli/HMUMU/ntuples/data_2016_v3/'
config.Data.publication = False
config.Data.outputDatasetTag = 'HtoMuMu_ntuples_v1'

config.Site.storageSite = 'T2_CH_CERN'
