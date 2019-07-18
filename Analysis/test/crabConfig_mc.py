from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'HtoZg_ntuples'
config.General.workArea = 'crab_projects_ele'
config.General.transferOutputs = True
config.General.transferLogs = False

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'makeNtuple_cfg.py'
config.JobType.pyCfgParams = ['isData=False', 'doPreselection=True' , 'doMuon=False' ,  'doElectron=True' ,'year=2017']

config.Data.inputDataset = '/RunIISummer16MiniAODv3/GluGluHToZG_M-125_13TeV_powheg_pythia8_CUETP8M1Up/MINIAODSIM'
config.Data.inputDBS = 'global'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 10
config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/phiSymmetry/Flavia/HtoZg/ele/'
config.Data.publication = False
config.Data.outputDatasetTag = 'HtoZg_ntuples_v2'

config.Site.storageSite = 'T2_CH_CERN'
