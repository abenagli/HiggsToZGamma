#include "HiggsToZGamma/Analysis/plugins/Preselection.h"



Preselection::Preselection(const edm::ParameterSet& pSet) :
  photonsToken_( consumes<pat::PhotonCollection>        (pSet.getUntrackedParameter<edm::InputTag>("photonsTag")) ),
  muonsToken_( consumes<pat::MuonCollection>        (pSet.getUntrackedParameter<edm::InputTag>("muonsTag")) ),
  electronsToken_( consumes<pat::ElectronCollection>(pSet.getUntrackedParameter<edm::InputTag>("electronsTag")) ),
  doMuon_(pSet.getParameter<bool>("doMuon")),
  doElectron_(pSet.getParameter<bool>("doElectron")),
  cut_pt1Min_(pSet.getParameter<double>("cut_pt1Min")),
  cut_pt2Min_(pSet.getParameter<double>("cut_pt2Min")),
  cut_mInvMin_(pSet.getParameter<double>("cut_mInvMin")),
  cut_ptPho_(pSet.getParameter<double>("cut_ptPho")),
  cut_DR_(pSet.getParameter<double>("cut_DR"))

{}



// ------------ method called for each event  ------------
bool Preselection::filter(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  //---get input collections
  iEvent.getByToken(photonsToken_, photonsHandle_);
  iEvent.getByToken(muonsToken_, muonsHandle_);
  iEvent.getByToken(electronsToken_, electronsHandle_);
  auto photons = *photonsHandle_.product();
  auto muons = *muonsHandle_.product();
  auto electrons = *electronsHandle_.product();

  
  //---muon information
  int nGoodCombs = 0;

  if( doMuon_ )
  {

      for(unsigned int it1 = 0; it1 < muons.size(); ++it1)
      {
        auto muon1 = muons.at(it1);
      
        float pt1 = muon1.pt();
        int charge1 = muon1.charge();


        if( pt1 < cut_pt1Min_ ) continue;

      
        for(unsigned int it2 = it1+1; it2 < muons.size(); ++it2)
        {
          auto muon2 = muons.at(it2);
        
          float pt2 = muon2.pt();
          int charge2 = muon2.charge();

          if( charge1*charge2 == 1 ) continue;
          if( pt2 < cut_pt2Min_ ) continue;

        
          TLorentzVector mu1;
          mu1.SetPtEtaPhiM(muon1.pt(),muon1.eta(),muon1.phi(),muon1.mass());
          TLorentzVector mu2;
          mu2.SetPtEtaPhiM(muon2.pt(),muon2.eta(),muon2.phi(),muon2.mass());
        
          if( (mu1+mu2).M() < cut_mInvMin_ ) continue;  
          for(unsigned int it = 0; it < photons.size(); ++it)
          {
            auto photon = photons.at(it);
            float ptPho = photon.pt();
            if( ptPho < cut_ptPho_ ) continue;
            float DR = reco::deltaR(muon1.eta(), muon1.phi(), photon.eta(), photon.phi());
            if (DR < cut_DR_ ) continue;
            DR = reco::deltaR(muon2.eta(), muon2.phi(), photon.eta(), photon.phi());
            if (DR < cut_DR_ ) continue;
            ++nGoodCombs;
        }
      }
    }       
  }
  
  if( doElectron_ )
  {


    for(unsigned int it1 = 0; it1 < electrons.size(); ++it1)
    {
      auto electron1 = electrons.at(it1);
      
      float pt1 = electron1.pt();
      int charge1 = electron1.charge();

      if( pt1 < cut_pt1Min_ ) continue;



      
      for(unsigned int it2 = it1+1; it2 < electrons.size(); ++it2)
      {
        auto electron2 = electrons.at(it2);
        float pt2 = electron2.pt();
        int charge2 = electron2.charge();

        
        if( charge1*charge2 == 1 ) continue;
        if( pt2 < cut_pt2Min_ ) continue;

     
        TLorentzVector ele1;
        ele1.SetPtEtaPhiM(electron1.pt(),electron1.eta(),electron1.phi(),electron1.mass());
        TLorentzVector ele2;
        ele2.SetPtEtaPhiM(electron2.pt(),electron2.eta(),electron2.phi(),electron2.mass());
        
        if( (ele1+ele2).M() < cut_mInvMin_ ) continue;   
        for(unsigned int it = 0; it < photons.size(); ++it)
        {
          auto photon = photons.at(it);
          float ptPho = photon.pt();
          if( ptPho < cut_ptPho_ ) continue;   
          float DR = reco::deltaR(electron1.eta(), electron1.phi(), photon.eta(), photon.phi());
          if (DR < cut_DR_ ) continue;
          DR = reco::deltaR(electron2.eta(), electron2.phi(), photon.eta(), photon.phi());
          if (DR < cut_DR_ ) continue;
        
          ++nGoodCombs;
        }
      }
    }
  }


 return bool(nGoodCombs);
}
