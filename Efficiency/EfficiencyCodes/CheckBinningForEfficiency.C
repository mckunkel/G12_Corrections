#include <fstream>
#include <cmath>
#include <iostream>
#include <unistd.h>
#include <vector>
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TH2F.h"
#include "TF1.h"
#include "TMath.h"
#include "TString.h"
#include "TSystem.h"
#include "TFile.h"
#include "TROOT.h"
#include "TChain.h"
#include <TVector3.h>
#include "TLorentzVector.h"
#include "TRandom.h"
#include "TGenPhaseSpace.h"
#include "TCanvas.h"

#include "/Volumes/Mac_Storage/Work_Codes/GIT_HUB/G12_Corrections/g12_corrections.hpp"

void CheckBinningForEfficiency(){
  
  Double_t Rad2Deg = 180.0/TMath::Pi();
  
  
  TH2D *Positive =new TH2D("Positive","Positive" ,50,-100,100,50,-100,100);
  TH2D *Negative =new TH2D("Negative","Negative" ,50,-100,100,50,-100,100);
  
  TH2D *PositiveFidCut =new TH2D("PositiveFidCut","PositiveFidCut" ,50,-100,100,50,-100,100);
  TH2D *NegativeFidCut =new TH2D("NegativeFidCut","NegativeFidCut" ,50,-100,100,50,-100,100);
  
  TH2D *NegativeFidCutWPosFidCut =new TH2D("NegativeFidCutWPosFidCut","NegativeFidCutWPosFidCut" ,50,-100,100,50,-100,100);

  
  TLorentzVector target(0.0, 0.0, 0.0, 0.938);
  //(Momentum, Energy units are Gev/C, GeV)
  Double_t masses[3] = { 0.938, 0.139, 0.139 };
  TGenPhaseSpace event;
  
  TH2F *h2 = new TH2F("h2","h2",50,1.1,5.8, 50,1.1,5.8);
  
  TF1 f("f1","1/x",1,5.5);
  TH1D *histo = new TH1D("histo","test",100,0,10);
  Int_t nentries = 100000000;
  for (Int_t j=0;j<nentries;j++) {
    if(!(j%0.1*nentries)) std::cout << "\r done " << j << " out of " << nentries << " ==> " << double(j)*100.0/double(nentries) << "%" << flush;
    if(j== nentries) std::cout << " DONE" << endl;

    double x = f.GetRandom();
    histo->Fill(x);
    TLorentzVector beam(0.0, 0.0, x, x);
    TLorentzVector W = beam + target;

    event.SetDecay(W, 3, masses);
    
    Double_t weight = event.Generate();
    TLorentzVector *pProton = event.GetDecay(0);
    TLorentzVector *pPip = event.GetDecay(1);
    TLorentzVector *pPim = event.GetDecay(2);
    TLorentzVector pPPip = *pProton + *pPip;
    TLorentzVector pPPim = *pProton + *pPim;
    
    Int_t Pip_geofid = clas::g12::g12_PosParticle_fiducial_cuts(pPip->Rho(), pPip->Theta()*Rad2Deg, pPip->Phi()*Rad2Deg,"nominal");
    Int_t Pim_geofid = clas::g12::g12_NegParticle_fiducial_cuts(pPim->Rho(), pPim->Theta()*Rad2Deg, pPim->Phi()*Rad2Deg,"nominal");

    Positive->Fill(pPip->Theta()*Rad2Deg*sin(pPip->Phi()),pPip->Theta()*Rad2Deg*cos(pPip->Phi()));
    Negative->Fill(pPim->Theta()*Rad2Deg*sin(pPim->Phi()),pPim->Theta()*Rad2Deg*cos(pPim->Phi()));
    
    if (Pip_geofid) {
      PositiveFidCut->Fill(pPip->Theta()*Rad2Deg*sin(pPip->Phi()),pPip->Theta()*Rad2Deg*cos(pPip->Phi()));
    }
    if (Pim_geofid) {
      NegativeFidCut->Fill(pPim->Theta()*Rad2Deg*sin(pPim->Phi()),pPim->Theta()*Rad2Deg*cos(pPim->Phi()));
    }
    if (Pim_geofid && Pip_geofid) {
      NegativeFidCutWPosFidCut->Fill(pPim->Theta()*Rad2Deg*sin(pPim->Phi()),pPim->Theta()*Rad2Deg*cos(pPim->Phi()));
    }

    h2->Fill(pPPip.M2() ,pPPim.M2() ,weight);
  }
  TCanvas *can1 = new TCanvas("can1","can1",800,1000);
  can1->Divide(1,2);
  can1->cd(1);
  histo->Draw();
  can1->cd(2);
  h2->Draw("colz");
  
  TFile fout("Binning.root","recreate");
  Positive->Write();
  PositiveFidCut->Write();
  Negative->Write();
  NegativeFidCut->Write();
  NegativeFidCutWPosFidCut->Write();
  
}


