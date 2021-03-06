#pragma once

#include "Particle.h"
#include "Tags.h"

#include <stdint.h>


class Tau: public Particle{
public:
    
  enum tag { /* for future use (more b-taggers, etc.) */ };
  
  
  // see https://twiki.cern.ch/twiki/bin/view/CMSPublic/SWGuidePFTauID
  // "Tau ID 2014 (Preparation for Run II)"
  // for those which are "binary" for most variables below. The names correspond to the strings used in PAT, not necessarily to
  // the names used in the twiki page above (e.g. 'by...Rejection' has the name 'against...' here). See at the end of this file for a list
  // of variable names in miniAOD.
  enum bool_id {
      againstElectronVLooseMVA5, againstElectronLooseMVA5, againstElectronMediumMVA5, againstElectronTightMVA5, againstElectronVTightMVA5, 
      againstMuonLoose3, againstMuonTight3,
      decayModeFinding, decayModeFindingNewDMs,
      byLooseCombinedIsolationDeltaBetaCorr3Hits, byMediumCombinedIsolationDeltaBetaCorr3Hits, byTightCombinedIsolationDeltaBetaCorr3Hits,
      byVLooseIsolationMVA3newDMwoLT, byLooseIsolationMVA3newDMwoLT, byMediumIsolationMVA3newDMwoLT, byTightIsolationMVA3newDMwoLT, byVTightIsolationMVA3newDMwoLT, byVVTightIsolationMVA3newDMwoLT,
      byVLooseIsolationMVA3newDMwLT, byLooseIsolationMVA3newDMwLT, byMediumIsolationMVA3newDMwLT, byTightIsolationMVA3newDMwLT, byVTightIsolationMVA3newDMwLT, byVVTightIsolationMVA3newDMwLT,
      byLoosePileupWeightedIsolation3Hits, byMediumPileupWeightedIsolation3Hits, byTightPileupWeightedIsolation3Hits
  };
  
  bool get_bool(bool_id i) const {
      return (id_bits & (uint64_t(1) << static_cast<uint64_t>(i)));
  }
  
  void set_bool(bool_id i, bool value) {
      if(value){
          id_bits |= uint64_t(1) << static_cast<uint64_t>(i);
      }
      else{
          id_bits &= ~(uint64_t(1) << static_cast<uint64_t>(i));
      }
  }
  
  // some non-bool values ('raw'):
  float byCombinedIsolationDeltaBetaCorrRaw3Hits() const { return m_byCombinedIsolationDeltaBetaCorrRaw3Hits; }
  float byIsolationMVA3newDMwLTraw() const { return m_byIsolationMVA3newDMwLTraw; }
  float byIsolationMVA3newDMwoLTraw() const { return m_byIsolationMVA3newDMwoLTraw; }
  
  float chargedIsoPtSum() const { return m_chargedIsoPtSum; }
  float neutralIsoPtSum() const { return m_neutralIsoPtSum; }
  float puCorrPtSum() const { return m_puCorrPtSum; }
  

  /* float byLoosePileupWeightedIsolation3Hits() const { return m_byLoosePileupWeightedIsolation3Hits; }  */
  /* float byMediumPileupWeightedIsolation3Hits() const { return m_byMediumPileupWeightedIsolation3Hits; }  */
  /* float byTightPileupWeightedIsolation3Hits() const { return m_byTightPileupWeightedIsolation3Hits; }  */
  float byPileupWeightedIsolationRaw3Hits() const { return m_byPileupWeightedIsolationRaw3Hits; } 
  float neutralIsoPtSumWeight() const { return m_neutralIsoPtSumWeight; }
  float footprintCorrection() const { return m_footprintCorrection; }
  float photonPtSumOutsideSignalCone() const { return m_photonPtSumOutsideSignalCone; }
  

 

  int decayMode() const { return m_decayMode; }
  
  void set_byCombinedIsolationDeltaBetaCorrRaw3Hits(float value){ m_byCombinedIsolationDeltaBetaCorrRaw3Hits = value; }
  void set_byIsolationMVA3newDMwoLTraw(float value) { m_byIsolationMVA3newDMwoLTraw = value; }
  void set_byIsolationMVA3newDMwLTraw(float value) { m_byIsolationMVA3newDMwLTraw = value; }

  void set_chargedIsoPtSum(float value) { m_chargedIsoPtSum = value; }
  void set_neutralIsoPtSum(float value) { m_neutralIsoPtSum = value; }
  void set_puCorrPtSum(float value) { m_puCorrPtSum = value; }
  
  void set_decayMode(int value){ m_decayMode = value; }

  
  /* void set_byLoosePileupWeightedIsolation3Hits(float value) { m_byLoosePileupWeightedIsolation3Hits = value;}  */
  /* void set_byMediumPileupWeightedIsolation3Hits(float value) { m_byMediumPileupWeightedIsolation3Hits = value; }  */
  /* void set_byTightPileupWeightedIsolation3Hits(float value){ m_byTightPileupWeightedIsolation3Hits = value; }  */

  void set_byPileupWeightedIsolationRaw3Hits(float value) { m_byPileupWeightedIsolationRaw3Hits = value;} 
  void set_neutralIsoPtSumWeight(float value) { m_neutralIsoPtSumWeight = value;}
  void set_footprintCorrection(float value) { m_footprintCorrection = value;}
  void set_photonPtSumOutsideSignalCone(float value) { m_photonPtSumOutsideSignalCone = value;}
  


  float get_tag(tag t) const { return tags.get_tag(static_cast<int>(t)); }
  void set_tag(tag t, float value) { return tags.set_tag(static_cast<int>(t), value); }
  
  
  Tau(){
      id_bits = 0;
      m_byCombinedIsolationDeltaBetaCorrRaw3Hits = 0;
      m_byIsolationMVA3newDMwoLTraw = 0;
      m_byIsolationMVA3newDMwLTraw = 0;
      m_chargedIsoPtSum = 0;
      m_neutralIsoPtSum = 0;
      m_puCorrPtSum = 0;
      m_neutralIsoPtSumWeight = 0;
      m_footprintCorrection = 0;
      m_photonPtSumOutsideSignalCone = 0;
      m_byPileupWeightedIsolationRaw3Hits = 0;
      m_decayMode = 0;
  }

private:
    // save the bool-like id variables in an uint64_t as single bits;
    // the bit positions correspond to the int-converted values of the enum bool_id.
    uint64_t id_bits;
    
    float m_byCombinedIsolationDeltaBetaCorrRaw3Hits;
    float m_byIsolationMVA3newDMwoLTraw;
    float m_byIsolationMVA3newDMwLTraw;
    float m_chargedIsoPtSum;
    float m_neutralIsoPtSum;
    float m_puCorrPtSum;
    
    /* float m_byLoosePileupWeightedIsolation3Hits;  */
    /* float m_byMediumPileupWeightedIsolation3Hits; */
    /* float m_byTightPileupWeightedIsolation3Hits;  */
    float m_byPileupWeightedIsolationRaw3Hits; 
    float m_neutralIsoPtSumWeight;
    float m_footprintCorrection;
    float m_photonPtSumOutsideSignalCone;
    
    
    int m_decayMode;
  
    Tags tags;
};

/*
 tau id variables available on Run II 2015 MINIAOD v2:

The available IDs are: 'againstElectronLooseMVA5' 'againstElectronMVA5category' 'againstElectronMVA5raw' 'againstElectronMediumMVA5' 'againstElectronTightMVA5' 'againstElectronVLooseMVA5' 'againstElectronVTightMVA5' 'againstMuonLoose3' 'againstMuonTight3' 'byCombinedIsolationDeltaBetaCorrRaw3Hits' 'byIsolationMVA3newDMwLTraw' 'byIsolationMVA3oldDMwLTraw' 'byLooseCombinedIsolationDeltaBetaCorr3Hits' 'byLooseIsolationMVA3newDMwLT' 'byLooseIsolationMVA3oldDMwLT' 'byLoosePileupWeightedIsolation3Hits' 'byMediumCombinedIsolationDeltaBetaCorr3Hits' 'byMediumIsolationMVA3newDMwLT' 'byMediumIsolationMVA3oldDMwLT' 'byMediumPileupWeightedIsolation3Hits' 'byPhotonPtSumOutsideSignalCone' 'byPileupWeightedIsolationRaw3Hits' 'byTightCombinedIsolationDeltaBetaCorr3Hits' 'byTightIsolationMVA3newDMwLT' 'byTightIsolationMVA3oldDMwLT' 'byTightPileupWeightedIsolation3Hits' 'byVLooseIsolationMVA3newDMwLT' 'byVLooseIsolationMVA3oldDMwLT' 'byVTightIsolationMVA3newDMwLT' 'byVTightIsolationMVA3oldDMwLT' 'byVVTightIsolationMVA3newDMwLT' 'byVVTightIsolationMVA3oldDMwLT' 'chargedIsoPtSum' 'decayModeFinding' 'decayModeFindingNewDMs' 'footprintCorrection' 'neutralIsoPtSum' 'neutralIsoPtSumWeight' 'photonPtSumOutsideSignalCone' 'puCorrPtSum' 

*/
