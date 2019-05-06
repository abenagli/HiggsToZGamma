from crabConfig_mc import config

if __name__ == '__main__':

    from CRABAPI.RawCommand import crabCommand
    from CRABClient.ClientExceptions import ClientException
    from httplib import HTTPException

    # We want to put all the CRAB project directories from the tasks we submit here into one common directory.
    # That's why we need to set this parameter (here or above in the configuration file, it does not matter, we will not overwrite it).
    config.General.workArea = 'crab_projects'
    
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
    
    config.General.requestName = 'HMuMu_ntuples_GluGlu_HToMuMu_M125_13TeV_powheg_pythia8'
    config.Data.inputDataset = '/GluGlu_HToMuMu_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM'
    config.Data.unitsPerJob = 10
    submit(config)
    
    config.General.requestName = 'HMuMu_ntuples_VBF_HToMuMu_M125_13TeV_powheg_pythia8'
    config.Data.inputDataset = '/VBF_HToMuMu_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM'
    config.Data.unitsPerJob = 10
    submit(config)
    
    config.General.requestName = 'HMuMu_ntuples_WPlusH_HToMuMu_M125_13TeV_powheg_pythia8'
    config.Data.inputDataset = '/WPlusH_HToMuMu_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM'
    config.Data.unitsPerJob = 10
    submit(config)
    
    config.General.requestName = 'HMuMu_ntuples_WMinusH_HToMuMu_M125_13TeV_powheg_pythia8'
    config.Data.inputDataset = '/WMinusH_HToMuMu_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM'
    config.Data.unitsPerJob = 10
    submit(config)
    
    config.General.requestName = 'HMuMu_ntuples_ZH_HToMuMu_M125_13TeV_powheg_pythia8'
    config.Data.inputDataset = '/ZH_HToMuMu_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM'
    config.Data.unitsPerJob = 10
    submit(config)
    
    config.General.requestName = 'DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8'
    config.Data.inputDataset = '/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext2-v1/MINIAODSIM'
    config.Data.unitsPerJob = 10
    submit(config)
    
    config.General.requestName = 'TTJets_DiLept_TuneCUETP8M1_13TeV-madgraphMLM-pythia8'
    config.Data.inputDataset = '/TTJets_DiLept_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM'
    config.Data.unitsPerJob = 10
    submit(config)
    
    config.General.requestName = 'TTJets_DiLept_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_bis'
    config.Data.inputDataset = '/TTJets_DiLept_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1/MINIAODSIM'
    config.Data.unitsPerJob = 10
    submit(config)
    
    config.General.requestName = 'ST_tW_top_5f_NoFullyHadronicDecays_13TeV-powheg'
    config.Data.inputDataset = '/ST_tW_top_5f_NoFullyHadronicDecays_13TeV-powheg_TuneCUETP8M1/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM'
    config.Data.unitsPerJob = 10
    submit(config)
    
    config.General.requestName = 'ST_tW_top_5f_NoFullyHadronicDecays_13TeV-powheg_bis'
    config.Data.inputDataset = '/ST_tW_top_5f_NoFullyHadronicDecays_13TeV-powheg_TuneCUETP8M1/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1/MINIAODSIM'
    config.Data.unitsPerJob = 10
    submit(config)
    
    config.General.requestName = 'ST_tW_antitop_5f_NoFullyHadronicDecays_13TeV-powheg'
    config.Data.inputDataset = '/ST_tW_antitop_5f_NoFullyHadronicDecays_13TeV-powheg_TuneCUETP8M1/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM'
    config.Data.unitsPerJob = 10
    submit(config)
    
    config.General.requestName = 'ST_tW_antitop_5f_NoFullyHadronicDecays_13TeV-powheg_bis'
    config.Data.inputDataset = '/ST_tW_antitop_5f_NoFullyHadronicDecays_13TeV-powheg_TuneCUETP8M1/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1/MINIAODSIM'
    config.Data.unitsPerJob = 10
    submit(config)
    
    config.General.requestName = 'WWTo2L2Nu_13TeV-powheg'
    config.Data.inputDataset = '/WWTo2L2Nu_13TeV-powheg/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM'
    config.Data.unitsPerJob = 10
    submit(config)
    
    config.General.requestName = 'WZTo3LNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8'
    config.Data.inputDataset = '/WZTo3LNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM'
    config.Data.unitsPerJob = 10
    submit(config)
    
    config.General.requestName = 'WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8'
    config.Data.inputDataset = '/WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM'
    config.Data.unitsPerJob = 10
    submit(config)
    
    config.General.requestName = 'ZZTo2L2Nu_13TeV_powheg_pythia8'
    config.Data.inputDataset = '/ZZTo2L2Nu_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM'
    config.Data.unitsPerJob = 10
    submit(config)
    
    config.General.requestName = 'ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8'
    config.Data.inputDataset = '/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM'
    config.Data.unitsPerJob = 10
    submit(config)
    
    config.General.requestName = 'ZZTo4L_13TeV-amcatnloFXFX-pythia8'
    config.Data.inputDataset = '/ZZTo4L_13TeV-amcatnloFXFX-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1/MINIAODSIM'
    config.Data.unitsPerJob = 10
    submit(config)
    
