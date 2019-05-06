#ifndef _DUMP_GEN_PARTICLES_
#define _DUMP_GEN_PARTICLES_

#include "HiggsToZGamma/Analysis/interface/ParticleNames.h"
#include "HiggsToZGamma/Analysis/interface/GenTree.h"

#include <iostream>

#include "TLorentzVector.h"

#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/Common/interface/Provenance.h"
#include "FWCore/ServiceRegistry/interface/Service.h"

#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "DataFormats/Common/interface/RefToBase.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/MET.h"
#include "DataFormats/PatCandidates/interface/PackedTriggerPrescales.h"

#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"



class DumpGenParticles : public edm::EDAnalyzer
{
public:
  explicit DumpGenParticles(const edm::ParameterSet&);
  ~DumpGenParticles();
  
private:
  
  //---methods
  virtual void beginJob() override {};
  virtual void analyze(edm::Event const&, edm::EventSetup const&) override;
  virtual void endJob() override {};
  
  const reco::GenParticle* IsDecayed(const reco::GenParticle*);
  void GetFinalStateDaughters(const reco::GenParticle* particle, std::vector<const reco::GenParticle*>& daughters);
    
  //---inputs
  edm::Handle<reco::GenParticleCollection>     genParticlesHandle_;
  edm::EDGetTokenT<reco::GenParticleCollection> genParticlesToken_;
  edm::Handle<edm::View<reco::GenJet> >             genJetsHandle_;
  edm::EDGetTokenT<edm::View<reco::GenJet> >         genJetsToken_;
  edm::EDGetTokenT<std::vector<PileupSummaryInfo> >   puInfoToken_;
  edm::Handle<std::vector<PileupSummaryInfo> >       puInfoHandle_;
  bool verbosity_;
  
  //---outputs
  edm::Service<TFileService> fs_;
  GenTree outTree_;
  
  int entry_;
  std::vector<const reco::GenParticle*> resonances_;
  std::map<const reco::GenParticle*,std::vector<const reco::GenParticle*> > resonanceDaughters_;
  std::map<const reco::GenParticle*,std::map<const reco::GenParticle*, std::vector<const reco::GenParticle*> > > resonanceDaughters2_;
};

std::ostream& operator<<(std::ostream& os,const reco::GenParticle* particle);

//define this as a plug-in
DEFINE_FWK_MODULE(DumpGenParticles);

#endif
