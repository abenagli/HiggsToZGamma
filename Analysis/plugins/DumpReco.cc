#include "HiggsToZGamma/Analysis/plugins/DumpReco.h"



DumpReco::DumpReco(const edm::ParameterSet& pSet) :
  trgsToken_               (consumes<edm::TriggerResults>        (pSet.getUntrackedParameter<edm::InputTag>("trgsTag"))),
  trgPrescalesToken_       (consumes<pat::PackedTriggerPrescales>(pSet.getUntrackedParameter<edm::InputTag>("trgPrescalesTag"))),
  vtxsToken_               (consumes<reco::VertexCollection>     (pSet.getUntrackedParameter<edm::InputTag>("vtxTag"))),
  rhoAllToken_             (consumes<double>                     (pSet.getUntrackedParameter<edm::InputTag>("rhoAllTag"))),
  rhoCentralToken_         (consumes<double>                     (pSet.getUntrackedParameter<edm::InputTag>("rhoCentralTag"))),
  rhoCentralNeutralToken_  (consumes<double>                     (pSet.getUntrackedParameter<edm::InputTag>("rhoCentralNeutralTag"))),
  rhoCentralChargedPUToken_(consumes<double>                     (pSet.getUntrackedParameter<edm::InputTag>("rhoCentralChargedPUTag"))),
  muonsToken_              (consumes<pat::MuonCollection>        (pSet.getUntrackedParameter<edm::InputTag>("muonsTag"))),
  electronsToken_          (consumes<pat::ElectronCollection>    (pSet.getUntrackedParameter<edm::InputTag>("electronsTag"))),
  photonsToken_            (consumes<pat::PhotonCollection>      (pSet.getUntrackedParameter<edm::InputTag>("photonsTag"))),
  jetsToken_               (consumes<pat::JetCollection>         (pSet.getUntrackedParameter<edm::InputTag>("jetsTag"))),
  jetsPuppiToken_          (consumes<pat::JetCollection>         (pSet.getUntrackedParameter<edm::InputTag>("jetsPuppiTag"))),
  metsToken_               (consumes<pat::METCollection>         (pSet.getUntrackedParameter<edm::InputTag>("metsTag"))),
  metsPuppiToken_          (consumes<pat::METCollection>         (pSet.getUntrackedParameter<edm::InputTag>("metsPuppiTag"))),
  bDiscriminators_                                               (pSet.getUntrackedParameter<std::vector<std::string> >("bDiscriminators"))
{
  //---TFileService for output ntuples
  if( !fs_ )
  {
    throw edm::Exception(edm::errors::Configuration, "TFile Service is not registered in cfg file");
  }
  
  outTree_ = RecoTree(pSet.getUntrackedParameter<std::string>("treeName").c_str(),"Reco tree for W > J/Psi D_s studies");
  entry_ = 0;
}



// ------------ method called for each event  ------------
void DumpReco::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  //---get input collections
  iEvent.getByToken(trgsToken_,trgsHandle_);
  iEvent.getByToken(trgPrescalesToken_,trgPrescalesHandle_);
  iEvent.getByToken(vtxsToken_,vtxsHandle_);
  iEvent.getByToken(rhoAllToken_,rhoAllHandle_);
  iEvent.getByToken(rhoCentralToken_,rhoCentralHandle_);
  iEvent.getByToken(rhoCentralNeutralToken_,rhoCentralNeutralHandle_);
  iEvent.getByToken(rhoCentralChargedPUToken_,rhoCentralChargedPUHandle_);
  iEvent.getByToken(muonsToken_,muonsHandle_);
  iEvent.getByToken(electronsToken_,electronsHandle_);
  iEvent.getByToken(photonsToken_,photonsHandle_);
  iEvent.getByToken(jetsToken_,jetsHandle_);
  iEvent.getByToken(jetsPuppiToken_,jetsPuppiHandle_);
  iEvent.getByToken(metsToken_,metsHandle_);
  iEvent.getByToken(metsPuppiToken_,metsPuppiHandle_);
  
  
  //---reset output
  outTree_.Reset();
  outTree_.entry = entry_;
  outTree_.event = iEvent.id().event();
  outTree_.lumi = iEvent.id().luminosityBlock();
  outTree_.run = iEvent.id().run(); 
  
  
  //---fill vertex information
  auto vtxs = *vtxsHandle_.product();
  outTree_.vtxs_n = vtxs.size();
  
  
  //--- fill rho information
  outTree_.rho_all = *rhoAllHandle_.product();
  outTree_.rho_central = *rhoCentralHandle_.product();
  outTree_.rho_centralNeutral = *rhoCentralNeutralHandle_.product();
  outTree_.rho_centralChargedPU = *rhoCentralChargedPUHandle_.product();
  
  
  //---fill trigger information
  const edm::TriggerNames& names = iEvent.triggerNames(*trgsHandle_);
  for(unsigned int i = 0; i < trgsHandle_->size(); ++i)
  {
    outTree_.trgs_name -> push_back( names.triggerName(i) );
    outTree_.trgs_pass -> push_back( trgsHandle_->accept(i) );
    outTree_.trgs_prescale -> push_back( trgPrescalesHandle_->getPrescaleForIndex(i) );
  }
  
  
  //---fill muon information
  for(auto &muon : *muonsHandle_)
  {
    outTree_.muons_pt       -> push_back( muon.pt() );
    outTree_.muons_eta      -> push_back( muon.eta() );
    outTree_.muons_phi      -> push_back( muon.phi() );
    outTree_.muons_energy   -> push_back( muon.energy() );
    outTree_.muons_charge   -> push_back( muon.charge() );
    outTree_.muons_vx       -> push_back( muon.vx() );
    outTree_.muons_vy       -> push_back( muon.vy() );
    outTree_.muons_vz       -> push_back( muon.vz() );
    outTree_.muons_dxy      -> push_back( muon.muonBestTrack()->dxy((*vtxsHandle_)[0].position()) );
    outTree_.muons_dxyErr   -> push_back( muon.muonBestTrack()->dxyError() );
    outTree_.muons_dz       -> push_back( muon.muonBestTrack()->dz((*vtxsHandle_)[0].position()) );
    outTree_.muons_dzErr    -> push_back( muon.muonBestTrack()->dzError() );
    outTree_.muons_isLoose  -> push_back( muon.isLooseMuon() );
    outTree_.muons_isMedium -> push_back( muon.isMediumMuon() );
    outTree_.muons_isTight  -> push_back( muon.isTightMuon((*vtxsHandle_)[0]) );
    outTree_.muons_trackIso -> push_back( muon.trackIso() );
    outTree_.muons_ecalIso  -> push_back( muon.ecalIso() );
    outTree_.muons_hcalIso  -> push_back( muon.hcalIso() );
    outTree_.muons_pfIsoChargedHadron   -> push_back( muon.pfIsolationR04().sumChargedHadronPt );
    outTree_.muons_pfIsoChargedParticle -> push_back( muon.pfIsolationR04().sumChargedParticlePt );
    outTree_.muons_pfIsoNeutralHadron   -> push_back( muon.pfIsolationR04().sumNeutralHadronEt );
    outTree_.muons_pfIsoPhoton          -> push_back( muon.pfIsolationR04().sumPhotonEt );
    outTree_.muons_pfIsoPU              -> push_back( muon.pfIsolationR04().sumPUPt );
    
    reco::TrackRef innerTrack = muon.innerTrack();
    // std::cout << "pt: " << muon.pt() << "   innerTrack: " << innerTrack.isNull() << std::endl;
    if( !innerTrack.isNull() )
      outTree_.muons_trackerLayersWithMeasurement -> push_back( muon.innerTrack()->hitPattern().trackerLayersWithMeasurement() );
    else
      outTree_.muons_trackerLayersWithMeasurement -> push_back( -1 );
  }
  
  
  
  //---fill electron information
  for(auto &electron : *electronsHandle_)
  {
    outTree_.electrons_pt       -> push_back( electron.pt() );
    outTree_.electrons_eta      -> push_back( electron.eta() );
    outTree_.electrons_phi      -> push_back( electron.phi() );
    outTree_.electrons_energy   -> push_back( electron.energy() );
    outTree_.electrons_charge   -> push_back( electron.charge() );
    outTree_.electrons_vx       -> push_back( electron.vx() );
    outTree_.electrons_vy       -> push_back( electron.vy() );
    outTree_.electrons_vz       -> push_back( electron.vz() );
    // outTree_.electrons_dxy      -> push_back( electron.electronBestTrack()->dxy((*vtxsHandle_)[0].position()) );
    // outTree_.electrons_dxyErr   -> push_back( electron.electronBestTrack()->dxyError() );
    // outTree_.electrons_dz       -> push_back( electron.electronBestTrack()->dz((*vtxsHandle_)[0].position()) );
    // outTree_.electrons_dzErr    -> push_back( electron.electronBestTrack()->dzError() );
    // outTree_.electrons_isLoose  -> push_back( electron.isLooseElectron() );
    // outTree_.electrons_isMedium -> push_back( electron.isMediumElectron() );
    // outTree_.electrons_isTight  -> push_back( electron.isTightElectron((*vtxsHandle_)[0]) );
    // outTree_.electrons_mva -> push_back( electron.userFloat("asdadsa") );
    outTree_.electrons_trackIso -> push_back( electron.trackIso() );
    outTree_.electrons_ecalIso  -> push_back( electron.ecalIso() );
    outTree_.electrons_hcalIso  -> push_back( electron.hcalIso() );
    // outTree_.electrons_pfIsoChargedHadron   -> push_back( electron.pfIsolationR04().sumChargedHadronPt );
    // outTree_.electrons_pfIsoChargedParticle -> push_back( electron.pfIsolationR04().sumChargedParticlePt );
    // outTree_.electrons_pfIsoNeutralHadron   -> push_back( electron.pfIsolationR04().sumNeutralHadronEt );
    // outTree_.electrons_pfIsoPhoton          -> push_back( electron.pfIsolationR04().sumPhotonEt );
    // outTree_.electrons_pfIsoPU              -> push_back( electron.pfIsolationR04().sumPUPt );
    
    // add electron variables
  }
  
  
  
  //---fill photon information
  for(auto &photon : *photonsHandle_)
  {
    outTree_.photons_pt       -> push_back( photon.pt() );
    outTree_.photons_eta      -> push_back( photon.eta() );
    outTree_.photons_phi      -> push_back( photon.phi() );
    outTree_.photons_energy   -> push_back( photon.energy() );
    outTree_.photons_charge   -> push_back( photon.charge() );
    outTree_.photons_vx       -> push_back( photon.vx() );
    outTree_.photons_vy       -> push_back( photon.vy() );
    outTree_.photons_vz       -> push_back( photon.vz() );
    // outTree_.photons_dxy      -> push_back( photon.photonBestTrack()->dxy((*vtxsHandle_)[0].position()) );
    // outTree_.photons_dxyErr   -> push_back( photon.photonBestTrack()->dxyError() );
    // outTree_.photons_dz       -> push_back( photon.photonBestTrack()->dz((*vtxsHandle_)[0].position()) );
    // outTree_.photons_dzErr    -> push_back( photon.photonBestTrack()->dzError() );
    // outTree_.photons_isLoose  -> push_back( photon.isLoosePhoton() );
    // outTree_.photons_isMedium -> push_back( photon.isMediumPhoton() );
    // outTree_.photons_isTight  -> push_back( photon.isTightPhoton((*vtxsHandle_)[0]) );
    outTree_.photons_trackIso -> push_back( photon.trackIso() );
    outTree_.photons_ecalIso  -> push_back( photon.ecalIso() );
    outTree_.photons_hcalIso  -> push_back( photon.hcalIso() );
    // outTree_.photons_pfIsoChargedHadron   -> push_back( photon.pfIsolationR04().sumChargedHadronPt );
    // outTree_.photons_pfIsoChargedParticle -> push_back( photon.pfIsolationR04().sumChargedParticlePt );
    // outTree_.photons_pfIsoNeutralHadron   -> push_back( photon.pfIsolationR04().sumNeutralHadronEt );
    // outTree_.photons_pfIsoPhoton          -> push_back( photon.pfIsolationR04().sumPhotonEt );
    // outTree_.photons_pfIsoPU              -> push_back( photon.pfIsolationR04().sumPUPt );
    
    // add photon variables
  }
  
  
  
  //---fill jets information
  auto jets = *jetsHandle_.product();
  for(auto &jet : *jetsHandle_)
  {
    if( jet.pt() < 20. ) continue;
    
    outTree_.jets_pt                -> push_back( jet.pt() );
    outTree_.jets_eta               -> push_back( jet.eta() );
    outTree_.jets_phi               -> push_back( jet.phi() );
    outTree_.jets_energy            -> push_back( jet.energy() );
    outTree_.jets_charge            -> push_back( jet.jetCharge() );
    outTree_.jets_numberOfDaughters -> push_back( jet.numberOfDaughters() );
    outTree_.jets_NHF               -> push_back( jet.neutralHadronEnergyFraction() );
    outTree_.jets_NEMF              -> push_back( jet.neutralEmEnergyFraction() );
    outTree_.jets_CHF               -> push_back( jet.chargedHadronEnergyFraction() );
    outTree_.jets_MUF               -> push_back( jet.muonEnergyFraction() );
    outTree_.jets_CEMF              -> push_back( jet.chargedEmEnergyFraction() );
    outTree_.jets_CM                -> push_back( jet.chargedMultiplicity() );
    outTree_.jets_NM                -> push_back( jet.neutralMultiplicity() );
    
    std::vector<float> bTagValues;
    for(const std::string& bDiscr : bDiscriminators_)
      bTagValues.push_back( jet.bDiscriminator(bDiscr) );
    outTree_.jets_bTag -> push_back( bTagValues );
  }
  
  
  //---fill puppi jets information
  auto jetsPuppi = *jetsPuppiHandle_.product();
  for(auto &jet : *jetsPuppiHandle_)
  {
    if( jet.pt() < 20. ) continue;
    
    outTree_.jets_puppi_pt                -> push_back( jet.pt() );
    outTree_.jets_puppi_eta               -> push_back( jet.eta() );
    outTree_.jets_puppi_phi               -> push_back( jet.phi() );
    outTree_.jets_puppi_energy            -> push_back( jet.energy() );
    outTree_.jets_puppi_charge            -> push_back( jet.jetCharge() );
    outTree_.jets_puppi_numberOfDaughters -> push_back( jet.numberOfDaughters() );
    outTree_.jets_puppi_NHF               -> push_back( jet.neutralHadronEnergyFraction() );
    outTree_.jets_puppi_NEMF              -> push_back( jet.neutralEmEnergyFraction() );
    outTree_.jets_puppi_CHF               -> push_back( jet.chargedHadronEnergyFraction() );
    outTree_.jets_puppi_MUF               -> push_back( jet.muonEnergyFraction() );
    outTree_.jets_puppi_CEMF              -> push_back( jet.chargedEmEnergyFraction() );
    outTree_.jets_puppi_CM                -> push_back( jet.chargedMultiplicity() );
    outTree_.jets_puppi_NM                -> push_back( jet.neutralMultiplicity() );
    
    std::vector<float> bTagValues;
    for(const std::string& bDiscr : bDiscriminators_)
      bTagValues.push_back( jet.bDiscriminator(bDiscr) );
    outTree_.jets_puppi_bTag -> push_back( bTagValues );
  }
  
  
  //---fill met information
  auto mets = *metsHandle_.product();
  for(auto &met : *metsHandle_)
  {
    outTree_.met_pt  = met.pt();
    outTree_.met_phi = met.phi();
    outTree_.met_sig = met.metSignificance();
  }
  
  
  //---fill puppi met information
  auto metsPuppi = *metsPuppiHandle_.product();
  for(auto &met : *metsPuppiHandle_)
  {
    outTree_.met_puppi_pt  = met.pt();
    outTree_.met_puppi_phi = met.phi();
    outTree_.met_puppi_sig = met.metSignificance();
  }
  
  
  outTree_.GetTTreePtr()->Fill();
  ++entry_;
}
