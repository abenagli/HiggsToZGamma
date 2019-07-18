from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'HtoZg_ntuples'
config.General.workArea = 'crab_projects_ele'
config.General.transferOutputs = True
config.General.transferLogs = False

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'makeNtuple_cfg.py'
config.JobType.pyCfgParams = ['isData=True', 'doPreselection=True', 'doMuon=False' ,  'doElectron=True' ,'year=2016']

config.Data.inputDataset = '/SingleMuon/Run2016B-03Feb2017_ver2-v2/MINIAOD'
config.Data.inputDBS = 'global'
config.Data.splitting = 'LumiBased'
config.Data.unitsPerJob = 10
config.Data.lumiMask = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/ReReco/Final/Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt'
config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/phiSymmetry/Flavia/HtoZg/ele/'
config.Data.publication = False
config.Data.outputDatasetTag = 'HtoZg_ntuples_v2'

config.Site.storageSite = 'T2_CH_CERN'
