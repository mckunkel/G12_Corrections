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


TVector3 MatchTracks(TVector3, TVector3, TVector3, TVector3, Double_t*, Int_t*);


void Make_Pip_Efficiency(){
	
  gStyle->SetPaintTextFormat("4.2f");
  
	TChain *ch1 = new TChain("Lep");
  ch1->Add("/volatile/clas/clasg12/mkunkel/EFFICIENCY/ROOT/DATA/PIP_EFF/HADDED/ALL_g12*.root");
  //ch1->Add("/volatile/clas/clasg12/mkunkel/EFFICIENCY/ROOT/MC/PIP_EFF/ALL_G12_Pip_Efficiency*");
  
  Double_t Pip_p, Pip_phi, Pip_theta, Pull_Prob;
  Int_t nPip;
  ch1->SetBranchAddress("Pip_p",&Pip_p);
  ch1->SetBranchAddress("Pip_phi",&Pip_phi);
  ch1->SetBranchAddress("Pip_theta",&Pip_theta);
  ch1->SetBranchAddress("Pull_Prob",&Pull_Prob);
  ch1->SetBranchAddress("nPip",&nPip);
  
	Double_t Pip_Ptot_missing_fit, Pip_theta_missing_fit, Pip_phi_missing_fit;
	
  ch1->SetBranchAddress("Pip_Ptot_missing_fit",&Pip_Ptot_missing_fit);
  ch1->SetBranchAddress("Pip_theta_missing_fit",&Pip_theta_missing_fit);
  ch1->SetBranchAddress("Pip_phi_missing_fit",&Pip_phi_missing_fit);
  
  Double_t P_vz, P_vx, P_vy, Pim_vz, Pim_vx, Pim_vy;
  ch1->SetBranchAddress("P_vz",&P_vz);
  ch1->SetBranchAddress("P_vy",&P_vy);
  ch1->SetBranchAddress("P_vx",&P_vx);
  ch1->SetBranchAddress("Pim_vz",&Pim_vz);
  ch1->SetBranchAddress("Pim_vy",&Pim_vy);
  ch1->SetBranchAddress("Pim_vx",&Pim_vx);
  
  Double_t P_Ptot_fit, P_px_fit, P_py_fit, P_pz_fit, P_phi_fit, P_theta_fit, Pim_Ptot_fit, Pim_px_fit, Pim_py_fit, Pim_pz_fit, Pim_phi_fit ,Pim_theta_fit;
  ch1->SetBranchAddress("P_Ptot_fit",&P_Ptot_fit);
  ch1->SetBranchAddress("P_px_fit",&P_px_fit);
  ch1->SetBranchAddress("P_py_fit",&P_py_fit);
  ch1->SetBranchAddress("P_pz_fit",&P_pz_fit);
  ch1->SetBranchAddress("P_phi_fit",&P_phi_fit);
  ch1->SetBranchAddress("P_theta_fit",&P_theta_fit);
  
  ch1->SetBranchAddress("Pim_Ptot_fit",&Pim_Ptot_fit);
  ch1->SetBranchAddress("Pim_px_fit",&Pim_px_fit);
  ch1->SetBranchAddress("Pim_py_fit",&Pim_py_fit);
  ch1->SetBranchAddress("Pim_pz_fit",&Pim_pz_fit);
  ch1->SetBranchAddress("Pim_phi_fit",&Pim_phi_fit);
  ch1->SetBranchAddress("Pim_theta_fit",&Pim_theta_fit);
  
  Int_t P_tofKO, Pip_tofKO, Pim_tofKO;
  ch1->SetBranchAddress("P_tofKO",&P_tofKO);
  ch1->SetBranchAddress("Pip_tofKO",&Pip_tofKO);
  ch1->SetBranchAddress("Pim_tofKO",&Pim_tofKO);
  

  Int_t P_fidpass, Pip_fidpass, Pim_fidpass;
  
  ch1->SetBranchAddress("P_fidpass",&P_fidpass);
  ch1->SetBranchAddress("Pip_fidpass",&Pip_fidpass);
  ch1->SetBranchAddress("Pim_fidpass",&Pim_fidpass);
  

  TH2D *hmissing_I_I =new TH2D("hmissing_I_I","Reconstructed at -110. < z < -105. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hmissing_I_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_I_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_I_I->Sumw2();
  TH2D *hdetect_I_I =new TH2D("hdetect_I_I","Detected at -110. < z < -105. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hdetect_I_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_I_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_I_I->Sumw2();
  TH2D *hEff_I_I =new TH2D("hEff_I_I","Efficiency at -110. < z < -105. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hEff_I_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_I_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_I_I->Sumw2();
  
  TH2D *hmissing_I_II =new TH2D("hmissing_I_II","Reconstructed at -110. < z < -105. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hmissing_I_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_I_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_I_II->Sumw2();
  TH2D *hdetect_I_II =new TH2D("hdetect_I_II","Detected at -110. < z < -105. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hdetect_I_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_I_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_I_II->Sumw2();
  TH2D *hEff_I_II =new TH2D("hEff_I_II","Efficiency at -110. < z < -105. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hEff_I_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_I_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_I_II->Sumw2();
  
  TH2D *hmissing_I_III =new TH2D("hmissing_I_III","Reconstructed at -110. < z < -105. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hmissing_I_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_I_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_I_III->Sumw2();
  TH2D *hdetect_I_III =new TH2D("hdetect_I_III","Detected at -110. < z < -105. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hdetect_I_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_I_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_I_III->Sumw2();
  TH2D *hEff_I_III =new TH2D("hEff_I_III","Efficiency at -110. < z < -105. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hEff_I_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_I_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_I_III->Sumw2();
  
  TH2D *hmissing_I_IV =new TH2D("hmissing_I_IV","Reconstructed at -110. < z < -105. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hmissing_I_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_I_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_I_IV->Sumw2();
  TH2D *hdetect_I_IV =new TH2D("hdetect_I_IV","Detected at -110. < z < -105. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hdetect_I_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_I_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_I_IV->Sumw2();
  TH2D *hEff_I_IV =new TH2D("hEff_I_IV","Efficiency at -110. < z < -105. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hEff_I_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_I_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_I_IV->Sumw2();
  
  TH2D *hmissing_I_V =new TH2D("hmissing_I_V","Reconstructed at -110. < z < -105. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hmissing_I_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_I_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_I_V->Sumw2();
  TH2D *hdetect_I_V =new TH2D("hdetect_I_V","Detected at -110. < z < -105. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hdetect_I_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_I_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_I_V->Sumw2();
  TH2D *hEff_I_V =new TH2D("hEff_I_V","Efficiency at -110. < z < -105. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hEff_I_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_I_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_I_V->Sumw2();
  
  TH2D *hmissing_I_VI =new TH2D("hmissing_I_VI","Reconstructed at -110. < z < -105. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hmissing_I_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_I_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_I_VI->Sumw2();
  TH2D *hdetect_I_VI =new TH2D("hdetect_I_VI","Detected at -110. < z < -105. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hdetect_I_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_I_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_I_VI->Sumw2();
  TH2D *hEff_I_VI =new TH2D("hEff_I_VI","Efficiency at -110. < z < -105. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hEff_I_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_I_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_I_VI->Sumw2();
  
  TH2D *hmissing_I_VII =new TH2D("hmissing_I_VII","Reconstructed at -110. < z < -105. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hmissing_I_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_I_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_I_VII->Sumw2();
  TH2D *hdetect_I_VII =new TH2D("hdetect_I_VII","Detected at -110. < z < -105. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hdetect_I_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_I_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_I_VII->Sumw2();
  TH2D *hEff_I_VII =new TH2D("hEff_I_VII","Efficiency at -110. < z < -105. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hEff_I_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_I_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_I_VII->Sumw2();
  
  TH2D *hmissing_I_VIII =new TH2D("hmissing_I_VIII","Reconstructed at -110. < z < -105. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hmissing_I_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_I_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_I_VIII->Sumw2();
  TH2D *hdetect_I_VIII =new TH2D("hdetect_I_VIII","Detected at -110. < z < -105. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hdetect_I_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_I_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_I_VIII->Sumw2();
  TH2D *hEff_I_VIII =new TH2D("hEff_I_VIII","Efficiency at -110. < z < -105. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hEff_I_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_I_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_I_VIII->Sumw2();
  
  TH2D *hmissing_II_I =new TH2D("hmissing_II_I","Reconstructed at -105. < z < -100. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hmissing_II_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_II_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_II_I->Sumw2();
  TH2D *hdetect_II_I =new TH2D("hdetect_II_I","Detected at -105. < z < -100. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hdetect_II_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_II_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_II_I->Sumw2();
  TH2D *hEff_II_I =new TH2D("hEff_II_I","Efficiency at -105. < z < -100. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hEff_II_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_II_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_II_I->Sumw2();
  
  TH2D *hmissing_II_II =new TH2D("hmissing_II_II","Reconstructed at -105. < z < -100. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hmissing_II_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_II_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_II_II->Sumw2();
  TH2D *hdetect_II_II =new TH2D("hdetect_II_II","Detected at -105. < z < -100. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hdetect_II_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_II_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_II_II->Sumw2();
  TH2D *hEff_II_II =new TH2D("hEff_II_II","Efficiency at -105. < z < -100. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hEff_II_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_II_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_II_II->Sumw2();
  
  TH2D *hmissing_II_III =new TH2D("hmissing_II_III","Reconstructed at -105. < z < -100. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hmissing_II_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_II_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_II_III->Sumw2();
  TH2D *hdetect_II_III =new TH2D("hdetect_II_III","Detected at -105. < z < -100. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hdetect_II_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_II_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_II_III->Sumw2();
  TH2D *hEff_II_III =new TH2D("hEff_II_III","Efficiency at -105. < z < -100. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hEff_II_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_II_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_II_III->Sumw2();
  
  TH2D *hmissing_II_IV =new TH2D("hmissing_II_IV","Reconstructed at -105. < z < -100. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hmissing_II_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_II_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_II_IV->Sumw2();
  TH2D *hdetect_II_IV =new TH2D("hdetect_II_IV","Detected at -105. < z < -100. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hdetect_II_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_II_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_II_IV->Sumw2();
  TH2D *hEff_II_IV =new TH2D("hEff_II_IV","Efficiency at -105. < z < -100. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hEff_II_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_II_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_II_IV->Sumw2();
  
  TH2D *hmissing_II_V =new TH2D("hmissing_II_V","Reconstructed at -105. < z < -100. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hmissing_II_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_II_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_II_V->Sumw2();
  TH2D *hdetect_II_V =new TH2D("hdetect_II_V","Detected at -105. < z < -100. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hdetect_II_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_II_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_II_V->Sumw2();
  TH2D *hEff_II_V =new TH2D("hEff_II_V","Efficiency at -105. < z < -100. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hEff_II_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_II_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_II_V->Sumw2();
  
  TH2D *hmissing_II_VI =new TH2D("hmissing_II_VI","Reconstructed at -105. < z < -100. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hmissing_II_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_II_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_II_VI->Sumw2();
  TH2D *hdetect_II_VI =new TH2D("hdetect_II_VI","Detected at -105. < z < -100. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hdetect_II_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_II_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_II_VI->Sumw2();
  TH2D *hEff_II_VI =new TH2D("hEff_II_VI","Efficiency at -105. < z < -100. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hEff_II_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_II_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_II_VI->Sumw2();
  
  TH2D *hmissing_II_VII =new TH2D("hmissing_II_VII","Reconstructed at -105. < z < -100. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hmissing_II_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_II_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_II_VII->Sumw2();
  TH2D *hdetect_II_VII =new TH2D("hdetect_II_VII","Detected at -105. < z < -100. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hdetect_II_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_II_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_II_VII->Sumw2();
  TH2D *hEff_II_VII =new TH2D("hEff_II_VII","Efficiency at -105. < z < -100. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hEff_II_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_II_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_II_VII->Sumw2();
  
  TH2D *hmissing_II_VIII =new TH2D("hmissing_II_VIII","Reconstructed at -105. < z < -100. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hmissing_II_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_II_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_II_VIII->Sumw2();
  TH2D *hdetect_II_VIII =new TH2D("hdetect_II_VIII","Detected at -105. < z < -100. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hdetect_II_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_II_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_II_VIII->Sumw2();
  TH2D *hEff_II_VIII =new TH2D("hEff_II_VIII","Efficiency at -105. < z < -100. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hEff_II_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_II_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_II_VIII->Sumw2();
  
  TH2D *hmissing_III_I =new TH2D("hmissing_III_I","Reconstructed at -100. < z < -95. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hmissing_III_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_III_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_III_I->Sumw2();
  TH2D *hdetect_III_I =new TH2D("hdetect_III_I","Detected at -100. < z < -95. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hdetect_III_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_III_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_III_I->Sumw2();
  TH2D *hEff_III_I =new TH2D("hEff_III_I","Efficiency at -100. < z < -95. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hEff_III_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_III_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_III_I->Sumw2();
  
  TH2D *hmissing_III_II =new TH2D("hmissing_III_II","Reconstructed at -100. < z < -95. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hmissing_III_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_III_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_III_II->Sumw2();
  TH2D *hdetect_III_II =new TH2D("hdetect_III_II","Detected at -100. < z < -95. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hdetect_III_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_III_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_III_II->Sumw2();
  TH2D *hEff_III_II =new TH2D("hEff_III_II","Efficiency at -100. < z < -95. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hEff_III_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_III_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_III_II->Sumw2();
  
  TH2D *hmissing_III_III =new TH2D("hmissing_III_III","Reconstructed at -100. < z < -95. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hmissing_III_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_III_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_III_III->Sumw2();
  TH2D *hdetect_III_III =new TH2D("hdetect_III_III","Detected at -100. < z < -95. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hdetect_III_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_III_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_III_III->Sumw2();
  TH2D *hEff_III_III =new TH2D("hEff_III_III","Efficiency at -100. < z < -95. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hEff_III_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_III_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_III_III->Sumw2();
  
  TH2D *hmissing_III_IV =new TH2D("hmissing_III_IV","Reconstructed at -100. < z < -95. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hmissing_III_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_III_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_III_IV->Sumw2();
  TH2D *hdetect_III_IV =new TH2D("hdetect_III_IV","Detected at -100. < z < -95. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hdetect_III_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_III_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_III_IV->Sumw2();
  TH2D *hEff_III_IV =new TH2D("hEff_III_IV","Efficiency at -100. < z < -95. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hEff_III_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_III_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_III_IV->Sumw2();
  
  TH2D *hmissing_III_V =new TH2D("hmissing_III_V","Reconstructed at -100. < z < -95. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hmissing_III_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_III_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_III_V->Sumw2();
  TH2D *hdetect_III_V =new TH2D("hdetect_III_V","Detected at -100. < z < -95. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hdetect_III_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_III_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_III_V->Sumw2();
  TH2D *hEff_III_V =new TH2D("hEff_III_V","Efficiency at -100. < z < -95. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hEff_III_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_III_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_III_V->Sumw2();
  
  TH2D *hmissing_III_VI =new TH2D("hmissing_III_VI","Reconstructed at -100. < z < -95. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hmissing_III_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_III_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_III_VI->Sumw2();
  TH2D *hdetect_III_VI =new TH2D("hdetect_III_VI","Detected at -100. < z < -95. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hdetect_III_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_III_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_III_VI->Sumw2();
  TH2D *hEff_III_VI =new TH2D("hEff_III_VI","Efficiency at -100. < z < -95. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hEff_III_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_III_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_III_VI->Sumw2();
  
  TH2D *hmissing_III_VII =new TH2D("hmissing_III_VII","Reconstructed at -100. < z < -95. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hmissing_III_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_III_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_III_VII->Sumw2();
  TH2D *hdetect_III_VII =new TH2D("hdetect_III_VII","Detected at -100. < z < -95. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hdetect_III_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_III_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_III_VII->Sumw2();
  TH2D *hEff_III_VII =new TH2D("hEff_III_VII","Efficiency at -100. < z < -95. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hEff_III_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_III_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_III_VII->Sumw2();
  
  TH2D *hmissing_III_VIII =new TH2D("hmissing_III_VIII","Reconstructed at -100. < z < -95. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hmissing_III_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_III_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_III_VIII->Sumw2();
  TH2D *hdetect_III_VIII =new TH2D("hdetect_III_VIII","Detected at -100. < z < -95. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hdetect_III_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_III_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_III_VIII->Sumw2();
  TH2D *hEff_III_VIII =new TH2D("hEff_III_VIII","Efficiency at -100. < z < -95. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hEff_III_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_III_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_III_VIII->Sumw2();
  
  TH2D *hmissing_IV_I =new TH2D("hmissing_IV_I","Reconstructed at -95. < z < -90. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hmissing_IV_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_IV_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_IV_I->Sumw2();
  TH2D *hdetect_IV_I =new TH2D("hdetect_IV_I","Detected at -95. < z < -90. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hdetect_IV_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_IV_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_IV_I->Sumw2();
  TH2D *hEff_IV_I =new TH2D("hEff_IV_I","Efficiency at -95. < z < -90. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hEff_IV_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_IV_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_IV_I->Sumw2();
  
  TH2D *hmissing_IV_II =new TH2D("hmissing_IV_II","Reconstructed at -95. < z < -90. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hmissing_IV_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_IV_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_IV_II->Sumw2();
  TH2D *hdetect_IV_II =new TH2D("hdetect_IV_II","Detected at -95. < z < -90. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hdetect_IV_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_IV_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_IV_II->Sumw2();
  TH2D *hEff_IV_II =new TH2D("hEff_IV_II","Efficiency at -95. < z < -90. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hEff_IV_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_IV_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_IV_II->Sumw2();
  
  TH2D *hmissing_IV_III =new TH2D("hmissing_IV_III","Reconstructed at -95. < z < -90. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hmissing_IV_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_IV_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_IV_III->Sumw2();
  TH2D *hdetect_IV_III =new TH2D("hdetect_IV_III","Detected at -95. < z < -90. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hdetect_IV_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_IV_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_IV_III->Sumw2();
  TH2D *hEff_IV_III =new TH2D("hEff_IV_III","Efficiency at -95. < z < -90. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hEff_IV_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_IV_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_IV_III->Sumw2();
  
  TH2D *hmissing_IV_IV =new TH2D("hmissing_IV_IV","Reconstructed at -95. < z < -90. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hmissing_IV_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_IV_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_IV_IV->Sumw2();
  TH2D *hdetect_IV_IV =new TH2D("hdetect_IV_IV","Detected at -95. < z < -90. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hdetect_IV_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_IV_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_IV_IV->Sumw2();
  TH2D *hEff_IV_IV =new TH2D("hEff_IV_IV","Efficiency at -95. < z < -90. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hEff_IV_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_IV_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_IV_IV->Sumw2();
  
  TH2D *hmissing_IV_V =new TH2D("hmissing_IV_V","Reconstructed at -95. < z < -90. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hmissing_IV_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_IV_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_IV_V->Sumw2();
  TH2D *hdetect_IV_V =new TH2D("hdetect_IV_V","Detected at -95. < z < -90. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hdetect_IV_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_IV_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_IV_V->Sumw2();
  TH2D *hEff_IV_V =new TH2D("hEff_IV_V","Efficiency at -95. < z < -90. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hEff_IV_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_IV_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_IV_V->Sumw2();
  
  TH2D *hmissing_IV_VI =new TH2D("hmissing_IV_VI","Reconstructed at -95. < z < -90. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hmissing_IV_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_IV_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_IV_VI->Sumw2();
  TH2D *hdetect_IV_VI =new TH2D("hdetect_IV_VI","Detected at -95. < z < -90. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hdetect_IV_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_IV_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_IV_VI->Sumw2();
  TH2D *hEff_IV_VI =new TH2D("hEff_IV_VI","Efficiency at -95. < z < -90. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hEff_IV_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_IV_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_IV_VI->Sumw2();
  
  TH2D *hmissing_IV_VII =new TH2D("hmissing_IV_VII","Reconstructed at -95. < z < -90. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hmissing_IV_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_IV_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_IV_VII->Sumw2();
  TH2D *hdetect_IV_VII =new TH2D("hdetect_IV_VII","Detected at -95. < z < -90. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hdetect_IV_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_IV_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_IV_VII->Sumw2();
  TH2D *hEff_IV_VII =new TH2D("hEff_IV_VII","Efficiency at -95. < z < -90. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hEff_IV_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_IV_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_IV_VII->Sumw2();
  
  TH2D *hmissing_IV_VIII =new TH2D("hmissing_IV_VIII","Reconstructed at -95. < z < -90. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hmissing_IV_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_IV_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_IV_VIII->Sumw2();
  TH2D *hdetect_IV_VIII =new TH2D("hdetect_IV_VIII","Detected at -95. < z < -90. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hdetect_IV_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_IV_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_IV_VIII->Sumw2();
  TH2D *hEff_IV_VIII =new TH2D("hEff_IV_VIII","Efficiency at -95. < z < -90. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hEff_IV_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_IV_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_IV_VIII->Sumw2();
  
  TH2D *hmissing_V_I =new TH2D("hmissing_V_I","Reconstructed at -90. < z < -85. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hmissing_V_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_V_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_V_I->Sumw2();
  TH2D *hdetect_V_I =new TH2D("hdetect_V_I","Detected at -90. < z < -85. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hdetect_V_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_V_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_V_I->Sumw2();
  TH2D *hEff_V_I =new TH2D("hEff_V_I","Efficiency at -90. < z < -85. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hEff_V_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_V_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_V_I->Sumw2();
  
  TH2D *hmissing_V_II =new TH2D("hmissing_V_II","Reconstructed at -90. < z < -85. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hmissing_V_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_V_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_V_II->Sumw2();
  TH2D *hdetect_V_II =new TH2D("hdetect_V_II","Detected at -90. < z < -85. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hdetect_V_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_V_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_V_II->Sumw2();
  TH2D *hEff_V_II =new TH2D("hEff_V_II","Efficiency at -90. < z < -85. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hEff_V_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_V_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_V_II->Sumw2();
  
  TH2D *hmissing_V_III =new TH2D("hmissing_V_III","Reconstructed at -90. < z < -85. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hmissing_V_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_V_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_V_III->Sumw2();
  TH2D *hdetect_V_III =new TH2D("hdetect_V_III","Detected at -90. < z < -85. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hdetect_V_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_V_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_V_III->Sumw2();
  TH2D *hEff_V_III =new TH2D("hEff_V_III","Efficiency at -90. < z < -85. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hEff_V_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_V_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_V_III->Sumw2();
  
  TH2D *hmissing_V_IV =new TH2D("hmissing_V_IV","Reconstructed at -90. < z < -85. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hmissing_V_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_V_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_V_IV->Sumw2();
  TH2D *hdetect_V_IV =new TH2D("hdetect_V_IV","Detected at -90. < z < -85. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hdetect_V_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_V_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_V_IV->Sumw2();
  TH2D *hEff_V_IV =new TH2D("hEff_V_IV","Efficiency at -90. < z < -85. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hEff_V_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_V_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_V_IV->Sumw2();
  
  TH2D *hmissing_V_V =new TH2D("hmissing_V_V","Reconstructed at -90. < z < -85. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hmissing_V_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_V_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_V_V->Sumw2();
  TH2D *hdetect_V_V =new TH2D("hdetect_V_V","Detected at -90. < z < -85. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hdetect_V_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_V_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_V_V->Sumw2();
  TH2D *hEff_V_V =new TH2D("hEff_V_V","Efficiency at -90. < z < -85. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hEff_V_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_V_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_V_V->Sumw2();
  
  TH2D *hmissing_V_VI =new TH2D("hmissing_V_VI","Reconstructed at -90. < z < -85. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hmissing_V_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_V_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_V_VI->Sumw2();
  TH2D *hdetect_V_VI =new TH2D("hdetect_V_VI","Detected at -90. < z < -85. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hdetect_V_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_V_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_V_VI->Sumw2();
  TH2D *hEff_V_VI =new TH2D("hEff_V_VI","Efficiency at -90. < z < -85. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hEff_V_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_V_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_V_VI->Sumw2();
  
  TH2D *hmissing_V_VII =new TH2D("hmissing_V_VII","Reconstructed at -90. < z < -85. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hmissing_V_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_V_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_V_VII->Sumw2();
  TH2D *hdetect_V_VII =new TH2D("hdetect_V_VII","Detected at -90. < z < -85. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hdetect_V_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_V_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_V_VII->Sumw2();
  TH2D *hEff_V_VII =new TH2D("hEff_V_VII","Efficiency at -90. < z < -85. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hEff_V_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_V_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_V_VII->Sumw2();
  
  TH2D *hmissing_V_VIII =new TH2D("hmissing_V_VIII","Reconstructed at -90. < z < -85. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hmissing_V_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_V_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_V_VIII->Sumw2();
  TH2D *hdetect_V_VIII =new TH2D("hdetect_V_VIII","Detected at -90. < z < -85. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hdetect_V_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_V_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_V_VIII->Sumw2();
  TH2D *hEff_V_VIII =new TH2D("hEff_V_VIII","Efficiency at -90. < z < -85. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hEff_V_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_V_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_V_VIII->Sumw2();
  
  TH2D *hmissing_VI_I =new TH2D("hmissing_VI_I","Reconstructed at -85. < z < -80. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hmissing_VI_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_VI_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_VI_I->Sumw2();
  TH2D *hdetect_VI_I =new TH2D("hdetect_VI_I","Detected at -85. < z < -80. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hdetect_VI_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_VI_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_VI_I->Sumw2();
  TH2D *hEff_VI_I =new TH2D("hEff_VI_I","Efficiency at -85. < z < -80. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hEff_VI_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_VI_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_VI_I->Sumw2();
  
  TH2D *hmissing_VI_II =new TH2D("hmissing_VI_II","Reconstructed at -85. < z < -80. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hmissing_VI_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_VI_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_VI_II->Sumw2();
  TH2D *hdetect_VI_II =new TH2D("hdetect_VI_II","Detected at -85. < z < -80. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hdetect_VI_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_VI_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_VI_II->Sumw2();
  TH2D *hEff_VI_II =new TH2D("hEff_VI_II","Efficiency at -85. < z < -80. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hEff_VI_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_VI_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_VI_II->Sumw2();
  
  TH2D *hmissing_VI_III =new TH2D("hmissing_VI_III","Reconstructed at -85. < z < -80. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hmissing_VI_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_VI_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_VI_III->Sumw2();
  TH2D *hdetect_VI_III =new TH2D("hdetect_VI_III","Detected at -85. < z < -80. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hdetect_VI_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_VI_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_VI_III->Sumw2();
  TH2D *hEff_VI_III =new TH2D("hEff_VI_III","Efficiency at -85. < z < -80. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hEff_VI_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_VI_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_VI_III->Sumw2();
  
  TH2D *hmissing_VI_IV =new TH2D("hmissing_VI_IV","Reconstructed at -85. < z < -80. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hmissing_VI_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_VI_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_VI_IV->Sumw2();
  TH2D *hdetect_VI_IV =new TH2D("hdetect_VI_IV","Detected at -85. < z < -80. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hdetect_VI_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_VI_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_VI_IV->Sumw2();
  TH2D *hEff_VI_IV =new TH2D("hEff_VI_IV","Efficiency at -85. < z < -80. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hEff_VI_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_VI_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_VI_IV->Sumw2();
  
  TH2D *hmissing_VI_V =new TH2D("hmissing_VI_V","Reconstructed at -85. < z < -80. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hmissing_VI_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_VI_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_VI_V->Sumw2();
  TH2D *hdetect_VI_V =new TH2D("hdetect_VI_V","Detected at -85. < z < -80. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hdetect_VI_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_VI_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_VI_V->Sumw2();
  TH2D *hEff_VI_V =new TH2D("hEff_VI_V","Efficiency at -85. < z < -80. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hEff_VI_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_VI_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_VI_V->Sumw2();
  
  TH2D *hmissing_VI_VI =new TH2D("hmissing_VI_VI","Reconstructed at -85. < z < -80. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hmissing_VI_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_VI_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_VI_VI->Sumw2();
  TH2D *hdetect_VI_VI =new TH2D("hdetect_VI_VI","Detected at -85. < z < -80. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hdetect_VI_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_VI_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_VI_VI->Sumw2();
  TH2D *hEff_VI_VI =new TH2D("hEff_VI_VI","Efficiency at -85. < z < -80. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hEff_VI_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_VI_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_VI_VI->Sumw2();
  
  TH2D *hmissing_VI_VII =new TH2D("hmissing_VI_VII","Reconstructed at -85. < z < -80. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hmissing_VI_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_VI_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_VI_VII->Sumw2();
  TH2D *hdetect_VI_VII =new TH2D("hdetect_VI_VII","Detected at -85. < z < -80. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hdetect_VI_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_VI_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_VI_VII->Sumw2();
  TH2D *hEff_VI_VII =new TH2D("hEff_VI_VII","Efficiency at -85. < z < -80. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hEff_VI_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_VI_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_VI_VII->Sumw2();
  
  TH2D *hmissing_VI_VIII =new TH2D("hmissing_VI_VIII","Reconstructed at -85. < z < -80. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hmissing_VI_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_VI_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_VI_VIII->Sumw2();
  TH2D *hdetect_VI_VIII =new TH2D("hdetect_VI_VIII","Detected at -85. < z < -80. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hdetect_VI_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_VI_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_VI_VIII->Sumw2();
  TH2D *hEff_VI_VIII =new TH2D("hEff_VI_VIII","Efficiency at -85. < z < -80. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hEff_VI_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_VI_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_VI_VIII->Sumw2();
  
  TH2D *hmissing_VII_I =new TH2D("hmissing_VII_I","Reconstructed at -80. < z < -75. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hmissing_VII_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_VII_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_VII_I->Sumw2();
  TH2D *hdetect_VII_I =new TH2D("hdetect_VII_I","Detected at -80. < z < -75. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hdetect_VII_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_VII_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_VII_I->Sumw2();
  TH2D *hEff_VII_I =new TH2D("hEff_VII_I","Efficiency at -80. < z < -75. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hEff_VII_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_VII_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_VII_I->Sumw2();
  
  TH2D *hmissing_VII_II =new TH2D("hmissing_VII_II","Reconstructed at -80. < z < -75. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hmissing_VII_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_VII_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_VII_II->Sumw2();
  TH2D *hdetect_VII_II =new TH2D("hdetect_VII_II","Detected at -80. < z < -75. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hdetect_VII_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_VII_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_VII_II->Sumw2();
  TH2D *hEff_VII_II =new TH2D("hEff_VII_II","Efficiency at -80. < z < -75. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hEff_VII_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_VII_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_VII_II->Sumw2();
  
  TH2D *hmissing_VII_III =new TH2D("hmissing_VII_III","Reconstructed at -80. < z < -75. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hmissing_VII_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_VII_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_VII_III->Sumw2();
  TH2D *hdetect_VII_III =new TH2D("hdetect_VII_III","Detected at -80. < z < -75. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hdetect_VII_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_VII_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_VII_III->Sumw2();
  TH2D *hEff_VII_III =new TH2D("hEff_VII_III","Efficiency at -80. < z < -75. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hEff_VII_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_VII_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_VII_III->Sumw2();
  
  TH2D *hmissing_VII_IV =new TH2D("hmissing_VII_IV","Reconstructed at -80. < z < -75. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hmissing_VII_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_VII_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_VII_IV->Sumw2();
  TH2D *hdetect_VII_IV =new TH2D("hdetect_VII_IV","Detected at -80. < z < -75. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hdetect_VII_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_VII_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_VII_IV->Sumw2();
  TH2D *hEff_VII_IV =new TH2D("hEff_VII_IV","Efficiency at -80. < z < -75. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hEff_VII_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_VII_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_VII_IV->Sumw2();
  
  TH2D *hmissing_VII_V =new TH2D("hmissing_VII_V","Reconstructed at -80. < z < -75. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hmissing_VII_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_VII_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_VII_V->Sumw2();
  TH2D *hdetect_VII_V =new TH2D("hdetect_VII_V","Detected at -80. < z < -75. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hdetect_VII_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_VII_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_VII_V->Sumw2();
  TH2D *hEff_VII_V =new TH2D("hEff_VII_V","Efficiency at -80. < z < -75. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hEff_VII_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_VII_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_VII_V->Sumw2();
  
  TH2D *hmissing_VII_VI =new TH2D("hmissing_VII_VI","Reconstructed at -80. < z < -75. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hmissing_VII_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_VII_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_VII_VI->Sumw2();
  TH2D *hdetect_VII_VI =new TH2D("hdetect_VII_VI","Detected at -80. < z < -75. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hdetect_VII_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_VII_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_VII_VI->Sumw2();
  TH2D *hEff_VII_VI =new TH2D("hEff_VII_VI","Efficiency at -80. < z < -75. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hEff_VII_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_VII_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_VII_VI->Sumw2();
  
  TH2D *hmissing_VII_VII =new TH2D("hmissing_VII_VII","Reconstructed at -80. < z < -75. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hmissing_VII_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_VII_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_VII_VII->Sumw2();
  TH2D *hdetect_VII_VII =new TH2D("hdetect_VII_VII","Detected at -80. < z < -75. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hdetect_VII_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_VII_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_VII_VII->Sumw2();
  TH2D *hEff_VII_VII =new TH2D("hEff_VII_VII","Efficiency at -80. < z < -75. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hEff_VII_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_VII_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_VII_VII->Sumw2();
  
  TH2D *hmissing_VII_VIII =new TH2D("hmissing_VII_VIII","Reconstructed at -80. < z < -75. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hmissing_VII_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_VII_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_VII_VIII->Sumw2();
  TH2D *hdetect_VII_VIII =new TH2D("hdetect_VII_VIII","Detected at -80. < z < -75. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hdetect_VII_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_VII_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_VII_VIII->Sumw2();
  TH2D *hEff_VII_VIII =new TH2D("hEff_VII_VIII","Efficiency at -80. < z < -75. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hEff_VII_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_VII_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_VII_VIII->Sumw2();
  
  TH2D *hmissing_VIII_I =new TH2D("hmissing_VIII_I","Reconstructed at -75. < z < -70. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hmissing_VIII_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_VIII_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_VIII_I->Sumw2();
  TH2D *hdetect_VIII_I =new TH2D("hdetect_VIII_I","Detected at -75. < z < -70. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hdetect_VIII_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_VIII_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_VIII_I->Sumw2();
  TH2D *hEff_VIII_I =new TH2D("hEff_VIII_I","Efficiency at -75. < z < -70. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hEff_VIII_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_VIII_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_VIII_I->Sumw2();
  
  TH2D *hmissing_VIII_II =new TH2D("hmissing_VIII_II","Reconstructed at -75. < z < -70. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hmissing_VIII_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_VIII_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_VIII_II->Sumw2();
  TH2D *hdetect_VIII_II =new TH2D("hdetect_VIII_II","Detected at -75. < z < -70. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hdetect_VIII_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_VIII_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_VIII_II->Sumw2();
  TH2D *hEff_VIII_II =new TH2D("hEff_VIII_II","Efficiency at -75. < z < -70. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hEff_VIII_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_VIII_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_VIII_II->Sumw2();
  
  TH2D *hmissing_VIII_III =new TH2D("hmissing_VIII_III","Reconstructed at -75. < z < -70. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hmissing_VIII_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_VIII_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_VIII_III->Sumw2();
  TH2D *hdetect_VIII_III =new TH2D("hdetect_VIII_III","Detected at -75. < z < -70. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hdetect_VIII_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_VIII_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_VIII_III->Sumw2();
  TH2D *hEff_VIII_III =new TH2D("hEff_VIII_III","Efficiency at -75. < z < -70. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hEff_VIII_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_VIII_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_VIII_III->Sumw2();
  
  TH2D *hmissing_VIII_IV =new TH2D("hmissing_VIII_IV","Reconstructed at -75. < z < -70. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hmissing_VIII_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_VIII_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_VIII_IV->Sumw2();
  TH2D *hdetect_VIII_IV =new TH2D("hdetect_VIII_IV","Detected at -75. < z < -70. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hdetect_VIII_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_VIII_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_VIII_IV->Sumw2();
  TH2D *hEff_VIII_IV =new TH2D("hEff_VIII_IV","Efficiency at -75. < z < -70. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hEff_VIII_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_VIII_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_VIII_IV->Sumw2();
  
  TH2D *hmissing_VIII_V =new TH2D("hmissing_VIII_V","Reconstructed at -75. < z < -70. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hmissing_VIII_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_VIII_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_VIII_V->Sumw2();
  TH2D *hdetect_VIII_V =new TH2D("hdetect_VIII_V","Detected at -75. < z < -70. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hdetect_VIII_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_VIII_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_VIII_V->Sumw2();
  TH2D *hEff_VIII_V =new TH2D("hEff_VIII_V","Efficiency at -75. < z < -70. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hEff_VIII_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_VIII_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_VIII_V->Sumw2();
  
  TH2D *hmissing_VIII_VI =new TH2D("hmissing_VIII_VI","Reconstructed at -75. < z < -70. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hmissing_VIII_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_VIII_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_VIII_VI->Sumw2();
  TH2D *hdetect_VIII_VI =new TH2D("hdetect_VIII_VI","Detected at -75. < z < -70. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hdetect_VIII_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_VIII_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_VIII_VI->Sumw2();
  TH2D *hEff_VIII_VI =new TH2D("hEff_VIII_VI","Efficiency at -75. < z < -70. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hEff_VIII_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_VIII_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_VIII_VI->Sumw2();
  
  TH2D *hmissing_VIII_VII =new TH2D("hmissing_VIII_VII","Reconstructed at -75. < z < -70. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hmissing_VIII_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_VIII_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_VIII_VII->Sumw2();
  TH2D *hdetect_VIII_VII =new TH2D("hdetect_VIII_VII","Detected at -75. < z < -70. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hdetect_VIII_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_VIII_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_VIII_VII->Sumw2();
  TH2D *hEff_VIII_VII =new TH2D("hEff_VIII_VII","Efficiency at -75. < z < -70. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hEff_VIII_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_VIII_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_VIII_VII->Sumw2();
  
  TH2D *hmissing_VIII_VIII =new TH2D("hmissing_VIII_VIII","Reconstructed at -75. < z < -70. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hmissing_VIII_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hmissing_VIII_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hmissing_VIII_VIII->Sumw2();
  TH2D *hdetect_VIII_VIII =new TH2D("hdetect_VIII_VIII","Detected at -75. < z < -70. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hdetect_VIII_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hdetect_VIII_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hdetect_VIII_VIII->Sumw2();
  TH2D *hEff_VIII_VIII =new TH2D("hEff_VIII_VIII","Efficiency at -75. < z < -70. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hEff_VIII_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hEff_VIII_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hEff_VIII_VIII->Sumw2();
  
  
  TH1D *hfit_p = new TH1D("hfit_p","Reconstructed #pi^{-} Momenta",100,0.0,4.3);
  TH1D *hdetect_p = new TH1D("hdetect_p","Detected #pi^{-} Momenta",100,0.0,4.3);
  TH1D *hEff_p = new TH1D("hEff_p","Efficiency of #pi^{-} Momenta",100,0.0,4.3);
  hEff_p->Sumw2();
  
  TH1D *hfit_phi = new TH1D("hfit_phi","Reconstructed #pi^{-} #phi",380,-190.,190);
  TH1D *hdetect_phi = new TH1D("hdetect_phi","Detected #pi^{-} #phi",380,-190.,190);
  TH1D *hEff_phi = new TH1D("hEff_phi","Efficiency of #pi^{-} #phi",380,-190.,190);
  hEff_phi->Sumw2();
  
  TH1D *hfit_theta = new TH1D("hfit_theta","Reconstructed #pi^{-} #theta",100,0.,190.0);
  TH1D *hdetect_theta = new TH1D("hdetect_theta","Detected #pi^{-} #theta",100,0.,190.);
  TH1D *hEff_theta = new TH1D("hEff_theta","Efficiency of #pi^{-} #theta",100,0.,190.);
  hEff_theta->Sumw2();
  
  TH1D *hzvert = new TH1D("hzvert","Calcualetd MVRT",100,-140,-50);
  
  Int_t nEvent = ch1->GetEntries();
  
  TLorentzVector vP, vPim;
  TVector3 vertex3_P, vertex3_Pim;
  
  Double_t M_P = 0.938272;   //Proton
  Double_t M_Pi = 0.139570;  //Pion
  
  
  Int_t Npass =0;
  Int_t Nfail = 0;
  for( Int_t i = 0; i < nEvent ; i++){
    ch1->GetEntry(i);
    if(!(i%1000000)) std::cout << "\r done " << i << " out of " << nEvent << " ==> " << double(i)*100.0/double(nEvent) << "%" << flush;
    if(Pull_Prob>0.01){
      
      int Pip_fit_fidpass = 0;
      if(clas::g12::g12_PosParticle_fiducial_cuts(Pip_Ptot_missing_fit, Pip_theta_missing_fit, Pip_phi_missing_fit,"nominal")){Pip_fit_fidpass =1;}
      
      if (P_fidpass ==0 || Pim_fidpass ==0 || Pip_fit_fidpass ==0 || P_tofKO == 0 || Pim_tofKO == 0) {
        Nfail++;
        continue;
        
      }
      Npass++;
      Double_t E_P = sqrt(M_P*M_P + P_Ptot_fit*P_Ptot_fit);
      Double_t E_Pim = sqrt(M_Pi*M_Pi + Pim_Ptot_fit*Pim_Ptot_fit);
      vP.SetPxPyPzE(P_px_fit,P_py_fit,P_pz_fit,E_P);
      vPim.SetPxPyPzE(Pim_px_fit,Pim_py_fit,Pim_pz_fit,E_Pim);
      vertex3_P.SetXYZ(P_vx, P_vy, P_vz);
      vertex3_Pim.SetXYZ(Pim_vx, Pim_vy, Pim_vz);
      
      Int_t PPimStat; Double_t PPimDist;
      TVector3 PPimMid = MatchTracks(vertex3_Pim, vPim.Vect(), vertex3_P, vP.Vect(), &PPimDist, &PPimStat);
      if (PPimStat == -1) {
        continue;
      }
      //Double_t PPip_Midx = PPipMid.X();
      //Double_t PPip_Midy = PPipMid.Y();
      Double_t PPim_Midz = PPimMid.Z();
      
      hzvert->Fill(PPim_Midz);
      
      
      if (PPim_Midz <= -105. && PPim_Midz > -110. ){
        
        if (Pip_Ptot_missing_fit <= 0.5 && Pip_Ptot_missing_fit > 0. ) {
          hmissing_I_I->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_I_I->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 0.75 && Pip_Ptot_missing_fit > 0.5 ) {
          hmissing_I_II->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_I_II->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 1. && Pip_Ptot_missing_fit > 0.75 ) {
          hmissing_I_III->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_I_III->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 1.5 && Pip_Ptot_missing_fit > 1. ) {
          hmissing_I_IV->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_I_IV->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 2. && Pip_Ptot_missing_fit > 1.5 ) {
          hmissing_I_V->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_I_V->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 2.5 && Pip_Ptot_missing_fit > 2. ) {
          hmissing_I_VI->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_I_VI->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 3. && Pip_Ptot_missing_fit > 2.5 ) {
          hmissing_I_VII->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_I_VII->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 5. && Pip_Ptot_missing_fit > 3. ) {
          hmissing_I_VIII->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_I_VIII->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
      }
      
      if (PPim_Midz <= -100. && PPim_Midz > -105. ){
        
        if (Pip_Ptot_missing_fit <= 0.5 && Pip_Ptot_missing_fit > 0. ) {
          hmissing_II_I->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_II_I->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 0.75 && Pip_Ptot_missing_fit > 0.5 ) {
          hmissing_II_II->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_II_II->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 1. && Pip_Ptot_missing_fit > 0.75 ) {
          hmissing_II_III->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_II_III->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 1.5 && Pip_Ptot_missing_fit > 1. ) {
          hmissing_II_IV->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_II_IV->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 2. && Pip_Ptot_missing_fit > 1.5 ) {
          hmissing_II_V->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_II_V->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 2.5 && Pip_Ptot_missing_fit > 2. ) {
          hmissing_II_VI->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_II_VI->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 3. && Pip_Ptot_missing_fit > 2.5 ) {
          hmissing_II_VII->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_II_VII->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 5. && Pip_Ptot_missing_fit > 3. ) {
          hmissing_II_VIII->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_II_VIII->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
      }
      
      if (PPim_Midz <= -95. && PPim_Midz > -100. ){
        
        if (Pip_Ptot_missing_fit <= 0.5 && Pip_Ptot_missing_fit > 0. ) {
          hmissing_III_I->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_III_I->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 0.75 && Pip_Ptot_missing_fit > 0.5 ) {
          hmissing_III_II->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_III_II->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 1. && Pip_Ptot_missing_fit > 0.75 ) {
          hmissing_III_III->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_III_III->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 1.5 && Pip_Ptot_missing_fit > 1. ) {
          hmissing_III_IV->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_III_IV->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 2. && Pip_Ptot_missing_fit > 1.5 ) {
          hmissing_III_V->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_III_V->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 2.5 && Pip_Ptot_missing_fit > 2. ) {
          hmissing_III_VI->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_III_VI->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 3. && Pip_Ptot_missing_fit > 2.5 ) {
          hmissing_III_VII->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_III_VII->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 5. && Pip_Ptot_missing_fit > 3. ) {
          hmissing_III_VIII->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_III_VIII->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
      }
      
      if (PPim_Midz <= -90. && PPim_Midz > -95. ){
        
        if (Pip_Ptot_missing_fit <= 0.5 && Pip_Ptot_missing_fit > 0. ) {
          hmissing_IV_I->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_IV_I->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 0.75 && Pip_Ptot_missing_fit > 0.5 ) {
          hmissing_IV_II->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_IV_II->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 1. && Pip_Ptot_missing_fit > 0.75 ) {
          hmissing_IV_III->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_IV_III->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 1.5 && Pip_Ptot_missing_fit > 1. ) {
          hmissing_IV_IV->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_IV_IV->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 2. && Pip_Ptot_missing_fit > 1.5 ) {
          hmissing_IV_V->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_IV_V->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 2.5 && Pip_Ptot_missing_fit > 2. ) {
          hmissing_IV_VI->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_IV_VI->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 3. && Pip_Ptot_missing_fit > 2.5 ) {
          hmissing_IV_VII->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_IV_VII->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 5. && Pip_Ptot_missing_fit > 3. ) {
          hmissing_IV_VIII->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_IV_VIII->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
      }
      
      if (PPim_Midz <= -85. && PPim_Midz > -90. ){
        
        if (Pip_Ptot_missing_fit <= 0.5 && Pip_Ptot_missing_fit > 0. ) {
          hmissing_V_I->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_V_I->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 0.75 && Pip_Ptot_missing_fit > 0.5 ) {
          hmissing_V_II->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_V_II->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 1. && Pip_Ptot_missing_fit > 0.75 ) {
          hmissing_V_III->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_V_III->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 1.5 && Pip_Ptot_missing_fit > 1. ) {
          hmissing_V_IV->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_V_IV->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 2. && Pip_Ptot_missing_fit > 1.5 ) {
          hmissing_V_V->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_V_V->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 2.5 && Pip_Ptot_missing_fit > 2. ) {
          hmissing_V_VI->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_V_VI->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 3. && Pip_Ptot_missing_fit > 2.5 ) {
          hmissing_V_VII->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_V_VII->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 5. && Pip_Ptot_missing_fit > 3. ) {
          hmissing_V_VIII->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_V_VIII->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
      }
      
      if (PPim_Midz <= -80. && PPim_Midz > -85. ){
        
        if (Pip_Ptot_missing_fit <= 0.5 && Pip_Ptot_missing_fit > 0. ) {
          hmissing_VI_I->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_VI_I->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 0.75 && Pip_Ptot_missing_fit > 0.5 ) {
          hmissing_VI_II->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_VI_II->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 1. && Pip_Ptot_missing_fit > 0.75 ) {
          hmissing_VI_III->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_VI_III->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 1.5 && Pip_Ptot_missing_fit > 1. ) {
          hmissing_VI_IV->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_VI_IV->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 2. && Pip_Ptot_missing_fit > 1.5 ) {
          hmissing_VI_V->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_VI_V->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 2.5 && Pip_Ptot_missing_fit > 2. ) {
          hmissing_VI_VI->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_VI_VI->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 3. && Pip_Ptot_missing_fit > 2.5 ) {
          hmissing_VI_VII->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_VI_VII->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 5. && Pip_Ptot_missing_fit > 3. ) {
          hmissing_VI_VIII->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_VI_VIII->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
      }
      
      if (PPim_Midz <= -75. && PPim_Midz > -80. ){
        
        if (Pip_Ptot_missing_fit <= 0.5 && Pip_Ptot_missing_fit > 0. ) {
          hmissing_VII_I->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_VII_I->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 0.75 && Pip_Ptot_missing_fit > 0.5 ) {
          hmissing_VII_II->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_VII_II->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 1. && Pip_Ptot_missing_fit > 0.75 ) {
          hmissing_VII_III->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_VII_III->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 1.5 && Pip_Ptot_missing_fit > 1. ) {
          hmissing_VII_IV->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_VII_IV->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 2. && Pip_Ptot_missing_fit > 1.5 ) {
          hmissing_VII_V->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_VII_V->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 2.5 && Pip_Ptot_missing_fit > 2. ) {
          hmissing_VII_VI->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_VII_VI->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 3. && Pip_Ptot_missing_fit > 2.5 ) {
          hmissing_VII_VII->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_VII_VII->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 5. && Pip_Ptot_missing_fit > 3. ) {
          hmissing_VII_VIII->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_VII_VIII->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
      }
      
      if (PPim_Midz <= -70. && PPim_Midz > -75. ){
        
        if (Pip_Ptot_missing_fit <= 0.5 && Pip_Ptot_missing_fit > 0. ) {
          hmissing_VIII_I->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_VIII_I->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 0.75 && Pip_Ptot_missing_fit > 0.5 ) {
          hmissing_VIII_II->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_VIII_II->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 1. && Pip_Ptot_missing_fit > 0.75 ) {
          hmissing_VIII_III->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_VIII_III->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 1.5 && Pip_Ptot_missing_fit > 1. ) {
          hmissing_VIII_IV->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_VIII_IV->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 2. && Pip_Ptot_missing_fit > 1.5 ) {
          hmissing_VIII_V->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_VIII_V->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 2.5 && Pip_Ptot_missing_fit > 2. ) {
          hmissing_VIII_VI->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_VIII_VI->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 3. && Pip_Ptot_missing_fit > 2.5 ) {
          hmissing_VIII_VII->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_VIII_VII->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
        if (Pip_Ptot_missing_fit <= 5. && Pip_Ptot_missing_fit > 3. ) {
          hmissing_VIII_VIII->Fill(Pip_theta_missing_fit*sin(Pip_phi_missing_fit*TMath::Pi()/180.),Pip_theta_missing_fit*cos(Pip_phi_missing_fit*TMath::Pi()/180.));
          if (nPip == 1 && Pip_fidpass == 1 && Pip_tofKO  == 1) {hdetect_VIII_VIII->Fill(Pip_theta*sin(Pip_phi*TMath::Pi()/180.),Pip_theta*cos(Pip_phi*TMath::Pi()/180.));}
        }
        
      }
      
      
      hfit_p->Fill(Pip_Ptot_missing_fit);
      hfit_phi->Fill(Pip_phi_missing_fit);
      hfit_theta->Fill(Pip_theta_missing_fit);
      
      if (nPip ==1 && Pip_fidpass==1) {
        hdetect_p->Fill(Pip_p);
        hdetect_phi->Fill(Pip_phi);
        hdetect_theta->Fill(Pip_theta);
        
      }
    }
  }
  
  TCanvas *c2 = new TCanvas("c2","c2");
  c2->cd();
  hEff_p->Divide(hdetect_p,hfit_p);
  hEff_p->Draw();
  
  
  TCanvas *c3 = new TCanvas("c3","c3");
  c3->cd();
  hEff_theta->Divide(hdetect_theta,hfit_theta);
  hEff_theta->Draw();
  
  
  TCanvas *c4 = new TCanvas("c4","c4");
  c4->cd();
  hEff_phi->Divide(hdetect_phi,hfit_phi);
  hEff_phi->Draw();
  
  TCanvas *cvert = new TCanvas("cvert","cvert");
  cvert->cd();
  hzvert->Draw();
  
  
  TCanvas *cZ_I_I = new TCanvas("I_I","I_I",800,800);
  cZ_I_I->cd();
  hEff_I_I->Divide(hdetect_I_I,hmissing_I_I);
  hEff_I_I->Draw("colz text");
  
  TCanvas *cZ_I_II = new TCanvas("I_II","I_II",800,800);
  cZ_I_II->cd();
  hEff_I_II->Divide(hdetect_I_II,hmissing_I_II);
  hEff_I_II->Draw("colz text");
  
  TCanvas *cZ_I_III = new TCanvas("I_III","I_III",800,800);
  cZ_I_III->cd();
  hEff_I_III->Divide(hdetect_I_III,hmissing_I_III);
  hEff_I_III->Draw("colz text");
  
  TCanvas *cZ_I_IV = new TCanvas("I_IV","I_IV",800,800);
  cZ_I_IV->cd();
  hEff_I_IV->Divide(hdetect_I_IV,hmissing_I_IV);
  hEff_I_IV->Draw("colz text");
  
  TCanvas *cZ_I_V = new TCanvas("I_V","I_V",800,800);
  cZ_I_V->cd();
  hEff_I_V->Divide(hdetect_I_V,hmissing_I_V);
  hEff_I_V->Draw("colz text");
  
  TCanvas *cZ_I_VI = new TCanvas("I_VI","I_VI",800,800);
  cZ_I_VI->cd();
  hEff_I_VI->Divide(hdetect_I_VI,hmissing_I_VI);
  hEff_I_VI->Draw("colz text");
  
  TCanvas *cZ_I_VII = new TCanvas("I_VII","I_VII",800,800);
  cZ_I_VII->cd();
  hEff_I_VII->Divide(hdetect_I_VII,hmissing_I_VII);
  hEff_I_VII->Draw("colz text");
  
  TCanvas *cZ_I_VIII = new TCanvas("I_VIII","I_VIII",800,800);
  cZ_I_VIII->cd();
  hEff_I_VIII->Divide(hdetect_I_VIII,hmissing_I_VIII);
  hEff_I_VIII->Draw("colz text");
  
  TCanvas *cZ_II_I = new TCanvas("II_I","II_I",800,800);
  cZ_II_I->cd();
  hEff_II_I->Divide(hdetect_II_I,hmissing_II_I);
  hEff_II_I->Draw("colz text");
  
  TCanvas *cZ_II_II = new TCanvas("II_II","II_II",800,800);
  cZ_II_II->cd();
  hEff_II_II->Divide(hdetect_II_II,hmissing_II_II);
  hEff_II_II->Draw("colz text");
  
  TCanvas *cZ_II_III = new TCanvas("II_III","II_III",800,800);
  cZ_II_III->cd();
  hEff_II_III->Divide(hdetect_II_III,hmissing_II_III);
  hEff_II_III->Draw("colz text");
  
  TCanvas *cZ_II_IV = new TCanvas("II_IV","II_IV",800,800);
  cZ_II_IV->cd();
  hEff_II_IV->Divide(hdetect_II_IV,hmissing_II_IV);
  hEff_II_IV->Draw("colz text");
  
  TCanvas *cZ_II_V = new TCanvas("II_V","II_V",800,800);
  cZ_II_V->cd();
  hEff_II_V->Divide(hdetect_II_V,hmissing_II_V);
  hEff_II_V->Draw("colz text");
  
  TCanvas *cZ_II_VI = new TCanvas("II_VI","II_VI",800,800);
  cZ_II_VI->cd();
  hEff_II_VI->Divide(hdetect_II_VI,hmissing_II_VI);
  hEff_II_VI->Draw("colz text");
  
  TCanvas *cZ_II_VII = new TCanvas("II_VII","II_VII",800,800);
  cZ_II_VII->cd();
  hEff_II_VII->Divide(hdetect_II_VII,hmissing_II_VII);
  hEff_II_VII->Draw("colz text");
  
  TCanvas *cZ_II_VIII = new TCanvas("II_VIII","II_VIII",800,800);
  cZ_II_VIII->cd();
  hEff_II_VIII->Divide(hdetect_II_VIII,hmissing_II_VIII);
  hEff_II_VIII->Draw("colz text");
  
  TCanvas *cZ_III_I = new TCanvas("III_I","III_I",800,800);
  cZ_III_I->cd();
  hEff_III_I->Divide(hdetect_III_I,hmissing_III_I);
  hEff_III_I->Draw("colz text");
  
  TCanvas *cZ_III_II = new TCanvas("III_II","III_II",800,800);
  cZ_III_II->cd();
  hEff_III_II->Divide(hdetect_III_II,hmissing_III_II);
  hEff_III_II->Draw("colz text");
  
  TCanvas *cZ_III_III = new TCanvas("III_III","III_III",800,800);
  cZ_III_III->cd();
  hEff_III_III->Divide(hdetect_III_III,hmissing_III_III);
  hEff_III_III->Draw("colz text");
  
  TCanvas *cZ_III_IV = new TCanvas("III_IV","III_IV",800,800);
  cZ_III_IV->cd();
  hEff_III_IV->Divide(hdetect_III_IV,hmissing_III_IV);
  hEff_III_IV->Draw("colz text");
  
  TCanvas *cZ_III_V = new TCanvas("III_V","III_V",800,800);
  cZ_III_V->cd();
  hEff_III_V->Divide(hdetect_III_V,hmissing_III_V);
  hEff_III_V->Draw("colz text");
  
  TCanvas *cZ_III_VI = new TCanvas("III_VI","III_VI",800,800);
  cZ_III_VI->cd();
  hEff_III_VI->Divide(hdetect_III_VI,hmissing_III_VI);
  hEff_III_VI->Draw("colz text");
  
  TCanvas *cZ_III_VII = new TCanvas("III_VII","III_VII",800,800);
  cZ_III_VII->cd();
  hEff_III_VII->Divide(hdetect_III_VII,hmissing_III_VII);
  hEff_III_VII->Draw("colz text");
  
  TCanvas *cZ_III_VIII = new TCanvas("III_VIII","III_VIII",800,800);
  cZ_III_VIII->cd();
  hEff_III_VIII->Divide(hdetect_III_VIII,hmissing_III_VIII);
  hEff_III_VIII->Draw("colz text");
  
  TCanvas *cZ_IV_I = new TCanvas("IV_I","IV_I",800,800);
  cZ_IV_I->cd();
  hEff_IV_I->Divide(hdetect_IV_I,hmissing_IV_I);
  hEff_IV_I->Draw("colz text");
  
  TCanvas *cZ_IV_II = new TCanvas("IV_II","IV_II",800,800);
  cZ_IV_II->cd();
  hEff_IV_II->Divide(hdetect_IV_II,hmissing_IV_II);
  hEff_IV_II->Draw("colz text");
  
  TCanvas *cZ_IV_III = new TCanvas("IV_III","IV_III",800,800);
  cZ_IV_III->cd();
  hEff_IV_III->Divide(hdetect_IV_III,hmissing_IV_III);
  hEff_IV_III->Draw("colz text");
  
  TCanvas *cZ_IV_IV = new TCanvas("IV_IV","IV_IV",800,800);
  cZ_IV_IV->cd();
  hEff_IV_IV->Divide(hdetect_IV_IV,hmissing_IV_IV);
  hEff_IV_IV->Draw("colz text");
  
  TCanvas *cZ_IV_V = new TCanvas("IV_V","IV_V",800,800);
  cZ_IV_V->cd();
  hEff_IV_V->Divide(hdetect_IV_V,hmissing_IV_V);
  hEff_IV_V->Draw("colz text");
  
  TCanvas *cZ_IV_VI = new TCanvas("IV_VI","IV_VI",800,800);
  cZ_IV_VI->cd();
  hEff_IV_VI->Divide(hdetect_IV_VI,hmissing_IV_VI);
  hEff_IV_VI->Draw("colz text");
  
  TCanvas *cZ_IV_VII = new TCanvas("IV_VII","IV_VII",800,800);
  cZ_IV_VII->cd();
  hEff_IV_VII->Divide(hdetect_IV_VII,hmissing_IV_VII);
  hEff_IV_VII->Draw("colz text");
  
  TCanvas *cZ_IV_VIII = new TCanvas("IV_VIII","IV_VIII",800,800);
  cZ_IV_VIII->cd();
  hEff_IV_VIII->Divide(hdetect_IV_VIII,hmissing_IV_VIII);
  hEff_IV_VIII->Draw("colz text");
  
  TCanvas *cZ_V_I = new TCanvas("V_I","V_I",800,800);
  cZ_V_I->cd();
  hEff_V_I->Divide(hdetect_V_I,hmissing_V_I);
  hEff_V_I->Draw("colz text");
  
  TCanvas *cZ_V_II = new TCanvas("V_II","V_II",800,800);
  cZ_V_II->cd();
  hEff_V_II->Divide(hdetect_V_II,hmissing_V_II);
  hEff_V_II->Draw("colz text");
  
  TCanvas *cZ_V_III = new TCanvas("V_III","V_III",800,800);
  cZ_V_III->cd();
  hEff_V_III->Divide(hdetect_V_III,hmissing_V_III);
  hEff_V_III->Draw("colz text");
  
  TCanvas *cZ_V_IV = new TCanvas("V_IV","V_IV",800,800);
  cZ_V_IV->cd();
  hEff_V_IV->Divide(hdetect_V_IV,hmissing_V_IV);
  hEff_V_IV->Draw("colz text");
  
  TCanvas *cZ_V_V = new TCanvas("V_V","V_V",800,800);
  cZ_V_V->cd();
  hEff_V_V->Divide(hdetect_V_V,hmissing_V_V);
  hEff_V_V->Draw("colz text");
  
  TCanvas *cZ_V_VI = new TCanvas("V_VI","V_VI",800,800);
  cZ_V_VI->cd();
  hEff_V_VI->Divide(hdetect_V_VI,hmissing_V_VI);
  hEff_V_VI->Draw("colz text");
  
  TCanvas *cZ_V_VII = new TCanvas("V_VII","V_VII",800,800);
  cZ_V_VII->cd();
  hEff_V_VII->Divide(hdetect_V_VII,hmissing_V_VII);
  hEff_V_VII->Draw("colz text");
  
  TCanvas *cZ_V_VIII = new TCanvas("V_VIII","V_VIII",800,800);
  cZ_V_VIII->cd();
  hEff_V_VIII->Divide(hdetect_V_VIII,hmissing_V_VIII);
  hEff_V_VIII->Draw("colz text");
  
  TCanvas *cZ_VI_I = new TCanvas("VI_I","VI_I",800,800);
  cZ_VI_I->cd();
  hEff_VI_I->Divide(hdetect_VI_I,hmissing_VI_I);
  hEff_VI_I->Draw("colz text");
  
  TCanvas *cZ_VI_II = new TCanvas("VI_II","VI_II",800,800);
  cZ_VI_II->cd();
  hEff_VI_II->Divide(hdetect_VI_II,hmissing_VI_II);
  hEff_VI_II->Draw("colz text");
  
  TCanvas *cZ_VI_III = new TCanvas("VI_III","VI_III",800,800);
  cZ_VI_III->cd();
  hEff_VI_III->Divide(hdetect_VI_III,hmissing_VI_III);
  hEff_VI_III->Draw("colz text");
  
  TCanvas *cZ_VI_IV = new TCanvas("VI_IV","VI_IV",800,800);
  cZ_VI_IV->cd();
  hEff_VI_IV->Divide(hdetect_VI_IV,hmissing_VI_IV);
  hEff_VI_IV->Draw("colz text");
  
  TCanvas *cZ_VI_V = new TCanvas("VI_V","VI_V",800,800);
  cZ_VI_V->cd();
  hEff_VI_V->Divide(hdetect_VI_V,hmissing_VI_V);
  hEff_VI_V->Draw("colz text");
  
  TCanvas *cZ_VI_VI = new TCanvas("VI_VI","VI_VI",800,800);
  cZ_VI_VI->cd();
  hEff_VI_VI->Divide(hdetect_VI_VI,hmissing_VI_VI);
  hEff_VI_VI->Draw("colz text");
  
  TCanvas *cZ_VI_VII = new TCanvas("VI_VII","VI_VII",800,800);
  cZ_VI_VII->cd();
  hEff_VI_VII->Divide(hdetect_VI_VII,hmissing_VI_VII);
  hEff_VI_VII->Draw("colz text");
  
  TCanvas *cZ_VI_VIII = new TCanvas("VI_VIII","VI_VIII",800,800);
  cZ_VI_VIII->cd();
  hEff_VI_VIII->Divide(hdetect_VI_VIII,hmissing_VI_VIII);
  hEff_VI_VIII->Draw("colz text");
  
  TCanvas *cZ_VII_I = new TCanvas("VII_I","VII_I",800,800);
  cZ_VII_I->cd();
  hEff_VII_I->Divide(hdetect_VII_I,hmissing_VII_I);
  hEff_VII_I->Draw("colz text");
  
  TCanvas *cZ_VII_II = new TCanvas("VII_II","VII_II",800,800);
  cZ_VII_II->cd();
  hEff_VII_II->Divide(hdetect_VII_II,hmissing_VII_II);
  hEff_VII_II->Draw("colz text");
  
  TCanvas *cZ_VII_III = new TCanvas("VII_III","VII_III",800,800);
  cZ_VII_III->cd();
  hEff_VII_III->Divide(hdetect_VII_III,hmissing_VII_III);
  hEff_VII_III->Draw("colz text");
  
  TCanvas *cZ_VII_IV = new TCanvas("VII_IV","VII_IV",800,800);
  cZ_VII_IV->cd();
  hEff_VII_IV->Divide(hdetect_VII_IV,hmissing_VII_IV);
  hEff_VII_IV->Draw("colz text");
  
  TCanvas *cZ_VII_V = new TCanvas("VII_V","VII_V",800,800);
  cZ_VII_V->cd();
  hEff_VII_V->Divide(hdetect_VII_V,hmissing_VII_V);
  hEff_VII_V->Draw("colz text");
  
  TCanvas *cZ_VII_VI = new TCanvas("VII_VI","VII_VI",800,800);
  cZ_VII_VI->cd();
  hEff_VII_VI->Divide(hdetect_VII_VI,hmissing_VII_VI);
  hEff_VII_VI->Draw("colz text");
  
  TCanvas *cZ_VII_VII = new TCanvas("VII_VII","VII_VII",800,800);
  cZ_VII_VII->cd();
  hEff_VII_VII->Divide(hdetect_VII_VII,hmissing_VII_VII);
  hEff_VII_VII->Draw("colz text");
  
  TCanvas *cZ_VII_VIII = new TCanvas("VII_VIII","VII_VIII",800,800);
  cZ_VII_VIII->cd();
  hEff_VII_VIII->Divide(hdetect_VII_VIII,hmissing_VII_VIII);
  hEff_VII_VIII->Draw("colz text");
  
  TCanvas *cZ_VIII_I = new TCanvas("VIII_I","VIII_I",800,800);
  cZ_VIII_I->cd();
  hEff_VIII_I->Divide(hdetect_VIII_I,hmissing_VIII_I);
  hEff_VIII_I->Draw("colz text");
  
  TCanvas *cZ_VIII_II = new TCanvas("VIII_II","VIII_II",800,800);
  cZ_VIII_II->cd();
  hEff_VIII_II->Divide(hdetect_VIII_II,hmissing_VIII_II);
  hEff_VIII_II->Draw("colz text");
  
  TCanvas *cZ_VIII_III = new TCanvas("VIII_III","VIII_III",800,800);
  cZ_VIII_III->cd();
  hEff_VIII_III->Divide(hdetect_VIII_III,hmissing_VIII_III);
  hEff_VIII_III->Draw("colz text");
  
  TCanvas *cZ_VIII_IV = new TCanvas("VIII_IV","VIII_IV",800,800);
  cZ_VIII_IV->cd();
  hEff_VIII_IV->Divide(hdetect_VIII_IV,hmissing_VIII_IV);
  hEff_VIII_IV->Draw("colz text");
  
  TCanvas *cZ_VIII_V = new TCanvas("VIII_V","VIII_V",800,800);
  cZ_VIII_V->cd();
  hEff_VIII_V->Divide(hdetect_VIII_V,hmissing_VIII_V);
  hEff_VIII_V->Draw("colz text");
  
  TCanvas *cZ_VIII_VI = new TCanvas("VIII_VI","VIII_VI",800,800);
  cZ_VIII_VI->cd();
  hEff_VIII_VI->Divide(hdetect_VIII_VI,hmissing_VIII_VI);
  hEff_VIII_VI->Draw("colz text");
  
  TCanvas *cZ_VIII_VII = new TCanvas("VIII_VII","VIII_VII",800,800);
  cZ_VIII_VII->cd();
  hEff_VIII_VII->Divide(hdetect_VIII_VII,hmissing_VIII_VII);
  hEff_VIII_VII->Draw("colz text");
  
  TCanvas *cZ_VIII_VIII = new TCanvas("VIII_VIII","VIII_VIII",800,800);
  cZ_VIII_VIII->cd();
  hEff_VIII_VIII->Divide(hdetect_VIII_VIII,hmissing_VIII_VIII);
  hEff_VIII_VIII->Draw("colz text");
  
  TFile fout("Efficiency_Plots_data.root","recreate");

  hmissing_I_I->Write();
  hdetect_I_I->Write();
  hEff_I_I->Write();
  
  hmissing_I_II->Write();
  hdetect_I_II->Write();
  hEff_I_II->Write();
  
  hmissing_I_III->Write();
  hdetect_I_III->Write();
  hEff_I_III->Write();
  
  hmissing_I_IV->Write();
  hdetect_I_IV->Write();
  hEff_I_IV->Write();
  
  hmissing_I_V->Write();
  hdetect_I_V->Write();
  hEff_I_V->Write();
  
  hmissing_I_VI->Write();
  hdetect_I_VI->Write();
  hEff_I_VI->Write();
  
  hmissing_I_VII->Write();
  hdetect_I_VII->Write();
  hEff_I_VII->Write();
  
  hmissing_I_VIII->Write();
  hdetect_I_VIII->Write();
  hEff_I_VIII->Write();
  
  hmissing_II_I->Write();
  hdetect_II_I->Write();
  hEff_II_I->Write();
  
  hmissing_II_II->Write();
  hdetect_II_II->Write();
  hEff_II_II->Write();
  
  hmissing_II_III->Write();
  hdetect_II_III->Write();
  hEff_II_III->Write();
  
  hmissing_II_IV->Write();
  hdetect_II_IV->Write();
  hEff_II_IV->Write();
  
  hmissing_II_V->Write();
  hdetect_II_V->Write();
  hEff_II_V->Write();
  
  hmissing_II_VI->Write();
  hdetect_II_VI->Write();
  hEff_II_VI->Write();
  
  hmissing_II_VII->Write();
  hdetect_II_VII->Write();
  hEff_II_VII->Write();
  
  hmissing_II_VIII->Write();
  hdetect_II_VIII->Write();
  hEff_II_VIII->Write();
  
  hmissing_III_I->Write();
  hdetect_III_I->Write();
  hEff_III_I->Write();
  
  hmissing_III_II->Write();
  hdetect_III_II->Write();
  hEff_III_II->Write();
  
  hmissing_III_III->Write();
  hdetect_III_III->Write();
  hEff_III_III->Write();
  
  hmissing_III_IV->Write();
  hdetect_III_IV->Write();
  hEff_III_IV->Write();
  
  hmissing_III_V->Write();
  hdetect_III_V->Write();
  hEff_III_V->Write();
  
  hmissing_III_VI->Write();
  hdetect_III_VI->Write();
  hEff_III_VI->Write();
  
  hmissing_III_VII->Write();
  hdetect_III_VII->Write();
  hEff_III_VII->Write();
  
  hmissing_III_VIII->Write();
  hdetect_III_VIII->Write();
  hEff_III_VIII->Write();
  
  hmissing_IV_I->Write();
  hdetect_IV_I->Write();
  hEff_IV_I->Write();
  
  hmissing_IV_II->Write();
  hdetect_IV_II->Write();
  hEff_IV_II->Write();
  
  hmissing_IV_III->Write();
  hdetect_IV_III->Write();
  hEff_IV_III->Write();
  
  hmissing_IV_IV->Write();
  hdetect_IV_IV->Write();
  hEff_IV_IV->Write();
  
  hmissing_IV_V->Write();
  hdetect_IV_V->Write();
  hEff_IV_V->Write();
  
  hmissing_IV_VI->Write();
  hdetect_IV_VI->Write();
  hEff_IV_VI->Write();
  
  hmissing_IV_VII->Write();
  hdetect_IV_VII->Write();
  hEff_IV_VII->Write();
  
  hmissing_IV_VIII->Write();
  hdetect_IV_VIII->Write();
  hEff_IV_VIII->Write();
  
  hmissing_V_I->Write();
  hdetect_V_I->Write();
  hEff_V_I->Write();
  
  hmissing_V_II->Write();
  hdetect_V_II->Write();
  hEff_V_II->Write();
  
  hmissing_V_III->Write();
  hdetect_V_III->Write();
  hEff_V_III->Write();
  
  hmissing_V_IV->Write();
  hdetect_V_IV->Write();
  hEff_V_IV->Write();
  
  hmissing_V_V->Write();
  hdetect_V_V->Write();
  hEff_V_V->Write();
  
  hmissing_V_VI->Write();
  hdetect_V_VI->Write();
  hEff_V_VI->Write();
  
  hmissing_V_VII->Write();
  hdetect_V_VII->Write();
  hEff_V_VII->Write();
  
  hmissing_V_VIII->Write();
  hdetect_V_VIII->Write();
  hEff_V_VIII->Write();
  
  hmissing_VI_I->Write();
  hdetect_VI_I->Write();
  hEff_VI_I->Write();
  
  hmissing_VI_II->Write();
  hdetect_VI_II->Write();
  hEff_VI_II->Write();
  
  hmissing_VI_III->Write();
  hdetect_VI_III->Write();
  hEff_VI_III->Write();
  
  hmissing_VI_IV->Write();
  hdetect_VI_IV->Write();
  hEff_VI_IV->Write();
  
  hmissing_VI_V->Write();
  hdetect_VI_V->Write();
  hEff_VI_V->Write();
  
  hmissing_VI_VI->Write();
  hdetect_VI_VI->Write();
  hEff_VI_VI->Write();
  
  hmissing_VI_VII->Write();
  hdetect_VI_VII->Write();
  hEff_VI_VII->Write();
  
  hmissing_VI_VIII->Write();
  hdetect_VI_VIII->Write();
  hEff_VI_VIII->Write();
  
  hmissing_VII_I->Write();
  hdetect_VII_I->Write();
  hEff_VII_I->Write();
  
  hmissing_VII_II->Write();
  hdetect_VII_II->Write();
  hEff_VII_II->Write();
  
  hmissing_VII_III->Write();
  hdetect_VII_III->Write();
  hEff_VII_III->Write();
  
  hmissing_VII_IV->Write();
  hdetect_VII_IV->Write();
  hEff_VII_IV->Write();
  
  hmissing_VII_V->Write();
  hdetect_VII_V->Write();
  hEff_VII_V->Write();
  
  hmissing_VII_VI->Write();
  hdetect_VII_VI->Write();
  hEff_VII_VI->Write();
  
  hmissing_VII_VII->Write();
  hdetect_VII_VII->Write();
  hEff_VII_VII->Write();
  
  hmissing_VII_VIII->Write();
  hdetect_VII_VIII->Write();
  hEff_VII_VIII->Write();
  
  hmissing_VIII_I->Write();
  hdetect_VIII_I->Write();
  hEff_VIII_I->Write();
  
  hmissing_VIII_II->Write();
  hdetect_VIII_II->Write();
  hEff_VIII_II->Write();
  
  hmissing_VIII_III->Write();
  hdetect_VIII_III->Write();
  hEff_VIII_III->Write();
  
  hmissing_VIII_IV->Write();
  hdetect_VIII_IV->Write();
  hEff_VIII_IV->Write();
  
  hmissing_VIII_V->Write();
  hdetect_VIII_V->Write();
  hEff_VIII_V->Write();
  
  hmissing_VIII_VI->Write();
  hdetect_VIII_VI->Write();
  hEff_VIII_VI->Write();
  
  hmissing_VIII_VII->Write();
  hdetect_VIII_VII->Write();
  hEff_VIII_VII->Write();
  
  hmissing_VIII_VIII->Write();
  hdetect_VIII_VIII->Write();
  hEff_VIII_VIII->Write();
  
  fout.Close();
  
  cout<<Npass<<"  "<<Nfail<<"  "<<(float)Npass/((float)(Npass+Nfail))<<endl;
  //  for(Int_t i = 1;i<hdetect->GetNbinsX();i++){
  //    for(Int_t j = 1;j<hdetect->GetNbinsY();j++){
  //      for(Int_t k = 1;k<hdetect->GetNbinsZ();k++){
  //        if(hdetect->GetBinContent(i,j,k)>0.){
  //          cout<<hdetect->GetBinContent(i,j,k)<<endl;
  //        }
  //      }
  //    }
  //
  //  }
  
}

TVector3  MatchTracks( TVector3 v1, TVector3 p1,  TVector3 v2, TVector3 p2, Double_t *dist, Int_t *stat)
{
  Double_t R1 = 0;
  TVector3 diff = (v1) - (v2);
  
  TVector3 p1unit = p1.Unit();
  TVector3 p2unit = p2.Unit();
  
  Double_t R = p1unit.Dot(p2unit);
  TVector3 MidPoint;
  if( R >= 1. ) {
    cout << "lines are parallel" << endl;
    (*stat) = -1;
    MidPoint.SetXYZ(-1000,-1000,-1000);
    return MidPoint;
  }
  
  else {
    R1 = 1 / ( 1- R*R );
  }
  
  TVector3 RP21 = p2unit*R - p1unit;
  TVector3 RP12 = p2unit - p1unit*R;
  
  Double_t DOT21 = diff.Dot(RP21);
  Double_t DOT12 = diff.Dot(RP12);
  
  TVector3 M1 = v1 + p1unit*R1*DOT21;
  TVector3 M2 = v2 + p2unit*R1*DOT12;
  
  TVector3 diff1 = M2 - M1;
  if(M2.Mag() > M1.Mag()){
    (*dist) = -diff1.Mag();
  }
  else{(*dist) = diff1.Mag();}
  
  (*stat) = 1;
  MidPoint = ( M1 + M2 ) * 0.5;
  return  MidPoint;
}



