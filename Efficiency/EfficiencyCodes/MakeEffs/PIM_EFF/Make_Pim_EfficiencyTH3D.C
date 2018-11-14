#include "TROOT.h"
#include "TRint.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH3.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TChain.h"
#include "TVector3.h"
#include "TMath.h"
#include "TFile.h"
#include "TSystem.h"
#include "TGStatusBar.h"
#include "TSystem.h"
#include "TXMLEngine.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "TNtuple.h"
#include "TStyle.h"
#include "TGraphErrors.h"
#include "TGraph.h"
#include <cmath>
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <unistd.h>

#include "/u/home/mkunkel/G12_NECCESSITIES/g12_corrections/g12_corrections.hpp"

//#include "/Users/michaelkunkel/WORK/GIT_HUB/G12_Corrections/g12_corrections.hpp"

void Make_Pim_EfficiencyTH3D(){
	
  gStyle->SetPaintTextFormat("4.2f");
  
	TChain *ch1 = new TChain("Lep");
  ch1->Add("/volatile/clas/clasg12/mkunkel/EFFICIENCY/ROOT/DATA/PIM_EFF/ALL_HADDED/ALL_g12*.root");
  //ch1->Add("/volatile/clas/clasg12/mkunkel/EFFICIENCY/ROOT/MC/PIM_EFF/ALL_G12_Pim_Efficiency*");
  
  ch1->SetBranchStatus("*",0);
  ch1->SetBranchStatus("Pim_p",1);
  ch1->SetBranchStatus("Pim_phi",1);
  ch1->SetBranchStatus("Pim_theta",1);
  ch1->SetBranchStatus("Pull_Prob",1);
  ch1->SetBranchStatus("nPim",1);
  
  ch1->SetBranchStatus("Pim_Ptot_missing_fit",1);
  ch1->SetBranchStatus("Pim_theta_missing_fit",1);
  ch1->SetBranchStatus("Pim_phi_missing_fit",1);
  
  ch1->SetBranchStatus("P_tofKO",1);
  ch1->SetBranchStatus("Pip_tofKO",1);
  ch1->SetBranchStatus("Pim_tofKO",1);

  ch1->SetBranchStatus("P_fidpass",1);
  ch1->SetBranchStatus("Pip_fidpass",1);
  ch1->SetBranchStatus("Pim_fidpass",1);

  Double_t Pim_p, Pim_phi, Pim_theta, Pull_Prob;
  Int_t nPim;
  ch1->SetBranchAddress("Pim_p",&Pim_p);
  ch1->SetBranchAddress("Pim_phi",&Pim_phi);
  ch1->SetBranchAddress("Pim_theta",&Pim_theta);
  ch1->SetBranchAddress("Pull_Prob",&Pull_Prob);
  ch1->SetBranchAddress("nPim",&nPim);
  
	Double_t Pim_Ptot_missing_fit, Pim_theta_missing_fit, Pim_phi_missing_fit;
	
  ch1->SetBranchAddress("Pim_Ptot_missing_fit",&Pim_Ptot_missing_fit);
  ch1->SetBranchAddress("Pim_theta_missing_fit",&Pim_theta_missing_fit);
  ch1->SetBranchAddress("Pim_phi_missing_fit",&Pim_phi_missing_fit);
  
  Int_t P_tofKO, Pip_tofKO, Pim_tofKO;
  ch1->SetBranchAddress("P_tofKO",&P_tofKO);
  ch1->SetBranchAddress("Pip_tofKO",&Pip_tofKO);
  ch1->SetBranchAddress("Pim_tofKO",&Pim_tofKO);

  Int_t P_fidpass, Pip_fidpass, Pim_fidpass;
  ch1->SetBranchAddress("P_fidpass",&P_fidpass);
  ch1->SetBranchAddress("Pip_fidpass",&Pip_fidpass);
  ch1->SetBranchAddress("Pim_fidpass",&Pim_fidpass);
  
  TH3D *hmissing =new TH3D("hmissing","Reconstructed" ,25,0.1,4.35,25,0,100,60,-180,180);
  hmissing->SetXTitle("P [GeV] ");
  hmissing->SetYTitle("#theta [#circ] ");
  hmissing->SetZTitle("#phi [#circ] ");
  hmissing->Sumw2();
  
  TH3D *hdetect =new TH3D("hdetect","Detected" ,25,0.1,4.35,25,0,100,60,-180,180);
  hdetect->SetXTitle("P [GeV] ");
  hdetect->SetYTitle("#theta [#circ] ");
  hdetect->SetZTitle("#phi [#circ] ");
  hdetect->Sumw2();
  
  TH3D *hEff =new TH3D("hEff","Efficiency" ,25,0.1,4.35,25,0,100,60,-180,180);
  hEff->SetXTitle("P [GeV] ");
  hEff->SetYTitle("#theta [#circ] ");
  hEff->SetZTitle("#phi [#circ] ");
  hEff->Sumw2();
  
  Int_t nEvent = ch1->GetEntries();
  
  Int_t Npass =0;
  Int_t Nfail = 0;
  for( Int_t i = 0; i < nEvent ; i++){
    ch1->GetEntry(i);
    if(!(i%1000000)) std::cout << "\r done " << i << " out of " << nEvent << " ==> " << double(i)*100.0/double(nEvent) << "%" << flush;
    if(Pull_Prob>0.01){
      
      int Pim_fit_fidpass = 0;
      
      if(clas::g12::g12_NegParticle_fiducial_cuts(Pim_Ptot_missing_fit, Pim_theta_missing_fit, Pim_phi_missing_fit,"nominal")){Pim_fit_fidpass =1;}
      
      if (P_fidpass ==0 || Pip_fidpass ==0 || Pim_fit_fidpass ==0  || P_tofKO == 0 || Pip_tofKO == 0) {
        Nfail++;
        continue;
        
      }
      Npass++;
      hmissing->Fill(Pim_Ptot_missing_fit, Pim_theta_missing_fit, Pim_phi_missing_fit);
      if (nPim == 1 && Pim_fidpass == 1 && Pim_tofKO  == 1) {hdetect->Fill(Pim_p, Pim_theta,Pim_phi);}
      
    }
  }
  
  
  TCanvas *cZ_I_I = new TCanvas("I_I","I_I",800,800);
  cZ_I_I->cd();
  hEff->Divide(hdetect,hmissing);
  hEff->Draw();
  
  TFile fout("Efficiency_Plots3D_data_Pim.root","recreate");

  hmissing->Write();
  hdetect->Write();
  hEff->Write();
  
  fout.Close();
  cout<<Npass<<"  "<<Nfail<<"  "<<(float)Npass/((float)(Npass+Nfail))<<endl;
}
