#ifndef _RECO__TREE
#define _RECO__TREE

#include "ExternalTools/DynamicTTree/interface/DynamicTTreeBase.h"



//---Define the TTree branches
#define DYNAMIC_TREE_NAME RecoTree

#define DATA_TABLE                  \
  DATA(int, entry)                  \
  DATA(int, event)                  \
  DATA(int, lumi)                   \
  DATA(int, run)                    \
  DATA(int, vtxs_n)                 \
  DATA(float, rho_all)              \
  DATA(float, rho_central)          \
  DATA(float, rho_centralNeutral)   \
  DATA(float, rho_centralChargedPU) \
  DATA(float, met_pt)               \
  DATA(float, met_phi)              \
  DATA(float, met_sig)              \
  DATA(float, met_puppi_pt)         \
  DATA(float, met_puppi_phi)        \
  DATA(float, met_puppi_sig)        \
  
#define DATA_CLASS_TABLE                                          \
  DATA(std::vector<std::string>, trgs_name)                       \
  DATA(std::vector<int>, trgs_pass)                               \
  DATA(std::vector<int>, trgs_prescale)                           \
  DATA(std::vector<float>, muons_pt)                              \
  DATA(std::vector<float>, muons_eta)                             \
  DATA(std::vector<float>, muons_phi)                             \
  DATA(std::vector<float>, muons_energy)                          \
  DATA(std::vector<int>,   muons_charge)                          \
  DATA(std::vector<float>, muons_vx)                              \
  DATA(std::vector<float>, muons_vy)                              \
  DATA(std::vector<float>, muons_vz)                              \
  DATA(std::vector<float>, muons_dxy)                             \
  DATA(std::vector<float>, muons_dxyErr)                          \
  DATA(std::vector<float>, muons_dz)                              \
  DATA(std::vector<float>, muons_dzErr)                           \
  DATA(std::vector<float>, muons_isLoose)                         \
  DATA(std::vector<float>, muons_isMedium)                        \
  DATA(std::vector<float>, muons_isTight)                         \
  DATA(std::vector<float>, muons_trackIso)                        \
  DATA(std::vector<float>, muons_ecalIso)                         \
  DATA(std::vector<float>, muons_hcalIso)                         \
  DATA(std::vector<float>, muons_pfIsoChargedHadron)              \
  DATA(std::vector<float>, muons_pfIsoChargedParticle)            \
  DATA(std::vector<float>, muons_pfIsoNeutralHadron)              \
  DATA(std::vector<float>, muons_pfIsoPhoton)                     \
  DATA(std::vector<float>, muons_pfIsoPU)                         \
  DATA(std::vector<int>,   muons_trackerLayersWithMeasurement)    \
  DATA(std::vector<float>, electrons_pt)                              \
  DATA(std::vector<float>, electrons_eta)                             \
  DATA(std::vector<float>, electrons_phi)                             \
  DATA(std::vector<float>, electrons_energy)                          \
  DATA(std::vector<int>,   electrons_charge)                          \
  DATA(std::vector<float>, electrons_vx)                              \
  DATA(std::vector<float>, electrons_vy)                              \
  DATA(std::vector<float>, electrons_vz)                              \
  DATA(std::vector<float>, electrons_dxy)                             \
  DATA(std::vector<float>, electrons_dxyErr)                          \
  DATA(std::vector<float>, electrons_dz)                              \
  DATA(std::vector<float>, electrons_dzErr)                           \
  DATA(std::vector<float>, electrons_trackIso)                        \
  DATA(std::vector<float>, electrons_ecalIso)                         \
  DATA(std::vector<float>, electrons_hcalIso)                         \
  DATA(std::vector<float>,   electrons_MVAID)                         \
  DATA(std::vector<float>,   electrons_EnergyPreCorr)                 \
  DATA(std::vector<float>,   electrons_EnergyErrPreCorr)              \
  DATA(std::vector<float>,   electrons_EnergyPostCorr)                \
  DATA(std::vector<float>,   electrons_EnergyErrPostCorr)                \
  DATA(std::vector<float>,   electrons_R9)                          \
  DATA(std::vector<float>,   electrons_sieie)                \
  DATA(std::vector<float>,   electrons_full5x5_R9)                          \
  DATA(std::vector<float>,   electrons_full5x5_sieie)               \
  DATA(std::vector<float>, photons_pt)                              \
  DATA(std::vector<float>, photons_eta)                             \
  DATA(std::vector<float>, photons_phi)                             \
  DATA(std::vector<float>, photons_energy)                          \
  DATA(std::vector<int>,   photons_charge)                          \
  DATA(std::vector<float>, photons_vx)                              \
  DATA(std::vector<float>, photons_vy)                              \
  DATA(std::vector<float>, photons_vz)                              \
  DATA(std::vector<float>, photons_trackIso)                        \
  DATA(std::vector<float>, photons_ecalIso)                         \
  DATA(std::vector<float>, photons_hcalIso)                         \
  DATA(std::vector<float>,   photons_MVAID)                         \
  DATA(std::vector<float>,   photons_EnergyPreCorr)                 \
  DATA(std::vector<float>,   photons_EnergyErrPreCorr)              \
  DATA(std::vector<float>,   photons_EnergyPostCorr)                \
  DATA(std::vector<float>,   photons_EnergyErrPostCorr)                \
  DATA(std::vector<float>,   photons_pixelSeedVeto)                \
  DATA(std::vector<float>,   photons_electronVeto)                \
  DATA(std::vector<float>,   photons_R9)                          \
  DATA(std::vector<float>,   photons_sieie)                \
  DATA(std::vector<float>,   photons_full5x5_R9)                          \
  DATA(std::vector<float>,   photons_full5x5_sieie)               \
  DATA(std::vector<float>, jets_pt)                               \
  DATA(std::vector<float>, jets_eta)                              \
  DATA(std::vector<float>, jets_phi)                              \
  DATA(std::vector<float>, jets_energy)                           \
  DATA(std::vector<float>, jets_charge)                           \
  DATA(std::vector<float>, jets_numberOfDaughters)                \
  DATA(std::vector<float>, jets_NHF)                              \
  DATA(std::vector<float>, jets_NEMF)                             \
  DATA(std::vector<float>, jets_CHF)                              \
  DATA(std::vector<float>, jets_MUF)                              \
  DATA(std::vector<float>, jets_CEMF)                             \
  DATA(std::vector<int>,   jets_CM)                               \
  DATA(std::vector<int>,   jets_NM)                               \
  DATA(std::vector<std::vector<float> >, jets_bTag)               \
  DATA(std::vector<float>, jets_puppi_pt)                         \
  DATA(std::vector<float>, jets_puppi_eta)                        \
  DATA(std::vector<float>, jets_puppi_phi)                        \
  DATA(std::vector<float>, jets_puppi_energy)                     \
  DATA(std::vector<int>,   jets_puppi_charge)                     \
  DATA(std::vector<int>,   jets_puppi_numberOfDaughters)          \
  DATA(std::vector<float>, jets_puppi_NHF)                        \
  DATA(std::vector<float>, jets_puppi_NEMF)                       \
  DATA(std::vector<float>, jets_puppi_CHF)                        \
  DATA(std::vector<float>, jets_puppi_MUF)                        \
  DATA(std::vector<float>, jets_puppi_CEMF)                       \
  DATA(std::vector<int>,   jets_puppi_CM)                         \
  DATA(std::vector<int>,   jets_puppi_NM)                         \
  DATA(std::vector<std::vector<float> >, jets_puppi_bTag)

#include "ExternalTools/DynamicTTree/interface/DynamicTTreeInterface.h"

#endif
