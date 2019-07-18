from crabConfig_data import config

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
    '''
    config.General.requestName = 'DoubleMuon_Run2016B-17Jul2018_ver2-v1'
    config.Data.inputDataset = '/DoubleMuon/Run2016B-17Jul2018_ver2-v1/MINIAOD'
    config.Data.unitsPerJob = 100
    submit(config)
    
    config.General.requestName = 'DoubleMuon_Run2016C-17Jul2018-v1'
    config.Data.inputDataset = '/DoubleMuon/Run2016C-17Jul2018-v1/MINIAOD'
    config.Data.unitsPerJob = 100
    submit(config)
    
    config.General.requestName = 'DoubleMuon_Run2016D-17Jul2018-v1'
    config.Data.inputDataset = '/DoubleMuon/Run2016D-17Jul2018-v1/MINIAOD'
    config.Data.unitsPerJob = 100
    submit(config)
    
    config.General.requestName = 'DoubleMuon_Run2016E-17Jul2018-v1'
    config.Data.inputDataset = '/DoubleMuon/Run2016E-17Jul2018-v1/MINIAOD'
    config.Data.unitsPerJob = 100
    submit(config)
    
    config.General.requestName = 'DoubleMuon_Run2016F-17Jul2018-v1'
    config.Data.inputDataset = '/DoubleMuon/Run2016F-17Jul2018-v1/MINIAOD'
    config.Data.unitsPerJob = 100
    submit(config)
    
    config.General.requestName = 'DoubleMuon_Run2016G-17Jul2018-v1'
    config.Data.inputDataset = '/DoubleMuon/Run2016G-17Jul2018-v1/MINIAOD'
    config.Data.unitsPerJob = 100
    submit(config)
    
    config.General.requestName = 'DoubleMuon_Run2016H-17Jul2018-v1'
    config.Data.inputDataset = '/DoubleMuon/Run2016H-17Jul2018-v1/MINIAOD'
    config.Data.unitsPerJob = 100
    submit(config)
    
    
    '''
    config.General.requestName = 'DoubleEG_Run2016B-17Jul2018_ver2-v1'
    config.Data.inputDataset = '/DoubleEG/Run2016B-17Jul2018_ver2-v1/MINIAOD'
    config.Data.unitsPerJob = 100
    submit(config)
    
    config.General.requestName = 'DoubleEG_Run2016C-17Jul2018-v1'
    config.Data.inputDataset = '/DoubleEG/Run2016C-17Jul2018-v1/MINIAOD'
    config.Data.unitsPerJob = 100
    submit(config)
    
    config.General.requestName = 'DoubleEG_Run2016D-17Jul2018-v1'
    config.Data.inputDataset = '/DoubleEG/Run2016D-17Jul2018-v1/MINIAOD'
    config.Data.unitsPerJob = 100
    submit(config)
    
    config.General.requestName = 'DoubleEG_Run2016E-17Jul2018-v1'
    config.Data.inputDataset = '/DoubleEG/Run2016E-17Jul2018-v1/MINIAOD'
    config.Data.unitsPerJob = 100
    submit(config)
    
    config.General.requestName = 'DoubleEG_Run2016F-17Jul2018-v1'
    config.Data.inputDataset = '/DoubleEG/Run2016F-17Jul2018-v1/MINIAOD'
    config.Data.unitsPerJob = 100
    submit(config)
    
    config.General.requestName = 'DoubleEG_Run2016G-17Jul2018-v1'
    config.Data.inputDataset = '/DoubleEG/Run2016G-17Jul2018-v1/MINIAOD'
    config.Data.unitsPerJob = 100
    submit(config)
    
    config.General.requestName = 'DoubleEG_Run2016H-17Jul2018-v1'
    config.Data.inputDataset = '/DoubleEG/Run2016H-17Jul2018-v1/MINIAOD'
    config.Data.unitsPerJob = 100
    submit(config)
      
    
    
