from crabConfig_mc import config

if __name__ == '__main__':

    from CRABAPI.RawCommand import crabCommand
    from CRABClient.ClientExceptions import ClientException
    from httplib import HTTPException

    # We want to put all the CRAB project directories from the tasks we submit here into one common directory.
    # That's why we need to set this parameter (here or above in the configuration file, it does not matter, we will not overwrite it).
    config.General.workArea = 'crab_projects_ele'
    
    def submit(config):
        print "\nsubmitting task " +str(config.General.requestName) + "..."
        try:
            crabCommand('submit', config = config)
        except HTTPException as hte:
            print "HTTPException -- Failed submitting task: %s" % (hte.headers)
        except ClientException as cle:
            print "ClientException -- Failed submitting task: %s" % (cle)
    
    #############################################################################################
    ## From now on that's what users should modify: this is the a-la-CRAB2 configuration part. ##
    #############################################################################################
    config.General.requestName = 'HtoZg_ntuples_GluGluHToZG_ZToLL_M-125_13TeV_powheg_pythia8_2017'
    config.Data.inputDataset = '/GluGluHToZG_ZToLL_M-125_13TeV_powheg_pythia8/RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/MINIAODSIM'
    config.Data.unitsPerJob = 10
    submit(config)



    '''### 2016
    config.General.requestName = 'HtoZg_ntuples_GluGluHToZG_M-125_13TeV_powheg_pythia8_CUETP8M1Up'
    config.Data.inputDataset = '/GluGluHToZG_M-125_13TeV_powheg_pythia8_CUETP8M1Up/RunIISummer16MiniAODv3-PUMoriond17_94X_mcRun2_asymptotic_v3-v2/MINIAODSIM'
    config.Data.unitsPerJob = 10
    submit(config)

    config.General.requestName = 'HtoZg_ntuples_VBFHToZG_M-125_13TeV_powheg_pythia8'
    config.Data.inputDataset = '/VBFHToZG_M-125_13TeV_powheg_pythia8/RunIISummer16MiniAODv3-PUMoriond17_94X_mcRun2_asymptotic_v3_ext1-v2/MINIAODSIM'
    config.Data.unitsPerJob = 10
    submit(config)
    
    config.General.requestName = 'HtoZg_ntuples_WplusH_HToZG_WToAll_M125_13TeV_powheg_pythia8' 
    config.Data.inputDataset = '/WplusH_HToZG_WToAll_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv3-PUMoriond17_94X_mcRun2_asymptotic_v3-v1/MINIAODSIM'
    config.Data.unitsPerJob = 10
    submit(config)

    config.General.requestName = 'HtoZg_ntuples_WminusH_HToZG_WToAll_M125_13TeV_powheg_pythia8'
    config.Data.inputDataset = '/WminusH_HToZG_WToAll_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv3-PUMoriond17_94X_mcRun2_asymptotic_v3-v1/MINIAODSIM'
    config.Data.unitsPerJob = 10
    submit(config)
   
    config.General.requestName = 'HtoZg_ntuples_ZH_HToZG_ZToAll_M-125_13TeV_powheg_pythia8'
    config.Data.inputDataset = '/ZH_HToZG_ZToAll_M-125_13TeV_powheg_pythia8/RunIISummer16MiniAODv3-PUMoriond17_94X_mcRun2_asymptotic_v3-v1/MINIAODSIM'
    config.Data.unitsPerJob = 10
    submit(config)
   
    
    config.General.requestName = 'HtoZg_ntuples_ttHToZG_M125_13TeV_powheg_pythia8'
    config.Data.inputDataset = '/ttHToZG_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv3-PUMoriond17_94X_mcRun2_asymptotic_v3-v1/MINIAODSIM'
    config.Data.unitsPerJob = 10
    submit(config)
    
    #bkg
  
    config.General.requestName = 'HtoZg_ntuples_ZGTo2LG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8'
    config.Data.inputDataset = '/ZGTo2LG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISummer16MiniAODv3-PUMoriond17_94X_mcRun2_asymptotic_v3_ext1-v1/MINIAODSIM'
    config.Data.unitsPerJob = 10
    submit(config)
  
    config.General.requestName = 'HtoZg_ntuples_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8'
    config.Data.inputDataset = '/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv3-PUMoriond17_94X_mcRun2_asymptotic_v3_ext1-v2/MINIAODSIM'
    config.Data.unitsPerJob = 10
    submit(config)
    '''
  

#/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_CUETP8M1Up/RunIISummer16MiniAODv3-PUMoriond17_94X_mcRun2_asymptotic_v3-v2
#/ttHToZG_M125_13TeV_powheg_pythia8_CUETP8M1Up/RunIISummer16MiniAODv3-PUMoriond17_94X_mcRun2_asymptotic_v3-v2/MINIAODSIM
#ZH_HToZG_ZToAll_M-125_13TeV_powheg_pythia8_CUETP8M1Up/RunIISummer16MiniAODv3-PUMoriond17_94X_mcRun2_asymptotic_v3-v2/MINIAODSIM
#/WminusH_HToZG_WToAll_M125_13TeV_powheg_pythia8_CUETP8M1Up/RunIISummer16MiniAODv3-PUMoriond17_94X_mcRun2_asymptotic_v3-v2/MINIAODSIM
#/VBFHToZG_M-125_13TeV_powheg_pythia8_CUETP8M1Up/RunIISummer16MiniAODv3-PUMoriond17_94X_mcRun2_asymptotic_v3-v2/MINIAODSIM'
    
