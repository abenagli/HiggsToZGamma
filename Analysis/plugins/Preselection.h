#ifndef _PRESELECTION_
#define _PRESELECTION_

#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/EDFilter.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/Common/interface/Provenance.h"
#include "FWCore/ServiceRegistry/interface/Service.h"

#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Photon.h"
#include "DataFormats/PatCandidates/interface/Electron.h"

#include "TLorentzVector.h"
#include "DataFormats/Math/interface/deltaR.h"


class Preselection : public edm::EDFilter
{
public:
  explicit Preselection(const edm::ParameterSet& pSet);
  ~Preselection() {};
  
  //---utils
  
  //---methods
  virtual void beginJob() override {};
  virtual bool filter(edm::Event&, const edm::EventSetup&);
  virtual void endJob() override {};
  
  
private:
  int entry_;
  
  //---inputs
  edm::EDGetTokenT<pat::PhotonCollection>         photonsToken_;
  edm::Handle<pat::PhotonCollection>             photonsHandle_;
  edm::EDGetTokenT<pat::MuonCollection>         muonsToken_;
  edm::Handle<pat::MuonCollection>             muonsHandle_;
  edm::EDGetTokenT<pat::ElectronCollection> electronsToken_;
  edm::Handle<pat::ElectronCollection>     electronsHandle_;
  
  //---cuts
  bool doMuon_;
  bool doElectron_;
  
  //---cuts
  int cut_loose_;
  double cut_pt1Min_;
  double cut_pt2Min_;
  double cut_mInvMin_; 
  double cut_ptPho_;
  double cut_DR_;
};

//define this as a plug-in
DEFINE_FWK_MODULE(Preselection);

#endif
