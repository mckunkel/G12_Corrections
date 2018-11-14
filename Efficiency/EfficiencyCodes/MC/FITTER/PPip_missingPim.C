//Current skims PipPim as of March 13, 2013

#include "TROOT.h"
#include "TRint.h"
#include "TH1F.h"
#include "TH2F.h"
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

#include "KinLine.C"
#include "Kstream.C"

#include "/u/home/mkunkel/G12_NECCESSITIES/g12_corrections/g12_corrections.hpp"


using namespace std;

int main(int argc, char* argv[]){
  
  if (argc < 3) {
    
    std::cerr << "Usage: " << argv[0] << " NAME" << std::endl;
    
    return 1;
  }
  
  std::cout << argv[0] << " takes, " << argv[1] << "!"<< " and makes " << argv[2] << "!" << std::endl;
  
  TChain *chain = new TChain("lepTree");
  
  chain->Add(argv[1]);
  
  Int_t nEvent = chain->GetEntries();
  
  std::cout <<"Number of events  " <<nEvent <<std::endl;
  
  const Int_t TBER_len = 5;
  //----------------------------------------------------For Incoming gamma---------------------------------------------------------
  
  Float_t egam, tpho;
  
  chain->SetBranchAddress("egam", &egam);
  chain->SetBranchAddress("tpho", &tpho);
  
  Int_t run, NProt, NPip, NPim;
  
  chain->SetBranchAddress("run",&run);
  chain->SetBranchAddress("NProt",&NProt);
  chain->SetBranchAddress("NPip",&NPip);
  chain->SetBranchAddress("NPim",&NPim);

  //----------------------------------------------------For PiPlus-------------------------------------------------------------------
  
  Float_t pip_P, pip_Pt, pip_Pl, pip_Phi, pip_Theta, pip_vx, pip_vy, pip_vz;
  Float_t pip_mat[TBER_len][TBER_len];
  Int_t pip_sec;
  
  chain->SetBranchAddress("pip_P",&pip_P);
  chain->SetBranchAddress("pip_Pt",&pip_Pt);
  chain->SetBranchAddress("pip_Pl",&pip_Pl);
  chain->SetBranchAddress("pip_Phi",&pip_Phi);
  chain->SetBranchAddress("pip_Theta",&pip_Theta);
  chain->SetBranchAddress("pip_vx",&pip_vx);
  chain->SetBranchAddress("pip_vy",&pip_vy);
  chain->SetBranchAddress("pip_vz",&pip_vz);
  chain->SetBranchAddress("pip_sec",&pip_sec);
  chain->SetBranchAddress("pip_mat",&pip_mat);
  
  Float_t pip_dTOF, Timing_pip;
  chain->SetBranchAddress("pip_dTOF",&pip_dTOF);
  chain->SetBranchAddress("Timing_pip",&Timing_pip);
  
  //----------------------------------------------------For PiMinus-------------------------------------------------------------------
  
  Float_t pim_P, pim_Phi, pim_Pt, pim_Pl, pim_Theta, pim_vx, pim_vy, pim_vz;
  Float_t pim_mat[TBER_len][TBER_len];
  Int_t pim_sec;
  
  chain->SetBranchAddress("pim_P",&pim_P);
  chain->SetBranchAddress("pim_Pt",&pim_Pt);
  chain->SetBranchAddress("pim_Pl",&pim_Pl);
  chain->SetBranchAddress("pim_Phi",&pim_Phi);
  chain->SetBranchAddress("pim_Theta",&pim_Theta);
  chain->SetBranchAddress("pim_vx",&pim_vx);
  chain->SetBranchAddress("pim_vy",&pim_vy);
  chain->SetBranchAddress("pim_vz",&pim_vz);
  chain->SetBranchAddress("pim_sec",&pim_sec);
  chain->SetBranchAddress("pim_mat",&pim_mat);
  
  
  Float_t pim_dTOF, Timing_pim;
  chain->SetBranchAddress("pim_dTOF",&pim_dTOF);
  chain->SetBranchAddress("Timing_pim",&Timing_pim);
  
  //----------------------------------------------------For Proton-------------------------------------------------------------------
  
  Float_t prot_P, prot_Pt, prot_Pl, prot_Phi, prot_Theta, prot_vx, prot_vy, prot_vz;
  Float_t prot_mat[TBER_len][TBER_len];
  Int_t prot_sec;
  
  chain->SetBranchAddress("prot_P",&prot_P);
  chain->SetBranchAddress("prot_Pt",&prot_Pt);
  chain->SetBranchAddress("prot_Pl",&prot_Pl);
  chain->SetBranchAddress("prot_Phi",&prot_Phi);
  chain->SetBranchAddress("prot_Theta",&prot_Theta);
  chain->SetBranchAddress("prot_vx",&prot_vx);
  chain->SetBranchAddress("prot_vy",&prot_vy);
  chain->SetBranchAddress("prot_vz",&prot_vz);
  chain->SetBranchAddress("prot_sec",&prot_sec);
  chain->SetBranchAddress("prot_mat",&prot_mat);
  
  Float_t prot_dTOF, Timing_prot;
  chain->SetBranchAddress("prot_dTOF",&prot_dTOF);
  chain->SetBranchAddress("Timing_prot",&Timing_prot);
  
  Int_t prot_tofKO, pip_tofKO, pim_tofKO;
  chain->SetBranchAddress("prot_tofKO",&prot_tofKO);
  chain->SetBranchAddress("pip_tofKO",&pip_tofKO);
  chain->SetBranchAddress("pim_tofKO",&pim_tofKO);
  
  //###########################################   END INCOMING DATA   ###############################################################
  
  
  //###########################################   BEGIN OUTGOING DATA   ###############################################################
  
  
  cout<<"here  2 "<<argv[2]<<endl;
  
  TFile f(argv[2],"recreate");
  
  TTree *t4 = new TTree("Lep","Lep");
  
  //----------------------------------------------------For Incoming Gamma------------------------------------------------------------------------
  
  Double_t Eg, Eg_fit;
  t4->Branch("Eg",&Eg,"Eg/D");
  t4->Branch("Eg_fit",&Eg_fit,"Eg_fit/D");
  
  
  Int_t nProt, nPip, nPim;
  t4->Branch("nProt",&nProt,"nProt/I");
  t4->Branch("nPip",&nPip,"nPip/I");
  t4->Branch("nPim",&nPim,"nPim/I");

  //----------------------------------------------------For Proton -------------------------------------------------------------------
  
  Double_t P_p, P_px, P_py, P_pz, P_theta, P_phi;
  
  t4->Branch("P_p",&P_p,"P_p/D");
  t4->Branch("P_px",&P_px,"P_px/D");
  t4->Branch("P_py",&P_py,"P_py/D");
  t4->Branch("P_pz",&P_pz,"P_pz/D");
  t4->Branch("P_theta",&P_theta,"P_theta/D");
  t4->Branch("P_phi",&P_phi,"P_phi/D");
  
  Double_t P_px_fit, P_py_fit, P_pz_fit, P_theta_fit, P_phi_fit;
  
  t4->Branch("P_px_fit",&P_px_fit,"P_px_fit/D");
  t4->Branch("P_py_fit",&P_py_fit,"P_py_fit/D");
  t4->Branch("P_pz_fit",&P_pz_fit,"P_pz_fit/D");
  t4->Branch("P_theta_fit",&P_theta_fit,"P_theta_fit/D");
  t4->Branch("P_phi_fit",&P_phi_fit,"P_phi_fit/D");
  
  Double_t P_vx, P_vy, P_vz;
  Int_t P_sec;
  
  t4->Branch("P_vx",&P_vx,"P_vx/D");
  t4->Branch("P_vy",&P_vy,"P_vy/D");
  t4->Branch("P_vz",&P_vz,"P_vz/D");
  t4->Branch("P_sec",&P_sec,"P_sec/I");
  
  Double_t P_dTOF, Timing_P;
  t4->Branch("P_dTOF",&P_dTOF,"P_dTOF/D");
  t4->Branch("Timing_P",&Timing_P,"Timing_P/D");
    
  Double_t P_Ptot_fit;
  t4->Branch("P_Ptot_fit",&P_Ptot_fit,"P_Ptot_fit/D");
  //----------------------------------------------------For PiPlus -------------------------------------------------------------------
  
  Double_t Pip_px, Pip_py, Pip_pz, Pip_p, Pip_theta, Pip_phi;
  
  t4->Branch("Pip_p",&Pip_p,"Pip_p/D");
  t4->Branch("Pip_px",&Pip_px,"Pip_px/D");
  t4->Branch("Pip_py",&Pip_py,"Pip_py/D");
  t4->Branch("Pip_pz",&Pip_pz,"Pip_pz/D");
  t4->Branch("Pip_theta",&Pip_theta,"Pip_theta/D");
  t4->Branch("Pip_phi",&Pip_phi,"Pip_phi/D");
  
  Double_t Pip_px_fit, Pip_py_fit, Pip_pz_fit, Pip_theta_fit, Pip_phi_fit;
  
  t4->Branch("Pip_px_fit",&Pip_px_fit,"Pip_px_fit/D");
  t4->Branch("Pip_py_fit",&Pip_py_fit,"Pip_py_fit/D");
  t4->Branch("Pip_pz_fit",&Pip_pz_fit,"Pip_pz_fit/D");
  t4->Branch("Pip_theta_fit",&Pip_theta_fit,"Pip_theta_fit/D");
  t4->Branch("Pip_phi_fit",&Pip_phi_fit,"Pip_phi_fit/D");

  
  Double_t  Pip_vx, Pip_vy, Pip_vz;
  Int_t Pip_sec;
  
  t4->Branch("Pip_vx",&Pip_vx,"Pip_vx/D");
  t4->Branch("Pip_vy",&Pip_vy,"Pip_vy/D");
  t4->Branch("Pip_vz",&Pip_vz,"Pip_vz/D");
  t4->Branch("Pip_sec",&Pip_sec,"Pip_sec/I");
  
  
  Double_t Pip_dTOF, Timing_Pip;
  t4->Branch("Pip_dTOF",&Pip_dTOF,"Pip_dTOF/D");
  t4->Branch("Timing_Pip",&Timing_Pip,"Timing_Pip/D");
  
  Double_t Pip_Ptot_fit;
  t4->Branch("Pip_Ptot_fit",&Pip_Ptot_fit,"Pip_Ptot_fit/D");
  //----------------------------------------------------For PiMinus -------------------------------------------------------------------
  
  Double_t Pim_px, Pim_py, Pim_pz, Pim_p, Pim_theta, Pim_phi;
  
  t4->Branch("Pim_p",&Pim_p,"Pim_p/D");
  t4->Branch("Pim_px",&Pim_px,"Pim_px/D");
  t4->Branch("Pim_py",&Pim_py,"Pim_py/D");
  t4->Branch("Pim_pz",&Pim_pz,"Pim_pz/D");
  t4->Branch("Pim_theta",&Pim_theta,"Pim_theta/D");
  t4->Branch("Pim_phi",&Pim_phi,"Pim_phi/D");
  
//  Double_t Pim_px_fit, Pim_py_fit, Pim_pz_fit, Pim_theta_fit, Pim_phi_fit;
//  
//  t4->Branch("Pim_px_fit",&Pim_px_fit,"Pim_px_fit/D");
//  t4->Branch("Pim_py_fit",&Pim_py_fit,"Pim_py_fit/D");
//  t4->Branch("Pim_pz_fit",&Pim_pz_fit,"Pim_pz_fit/D");
//  t4->Branch("Pim_theta_fit",&Pim_theta_fit,"Pim_theta_fit/D");
//  t4->Branch("Pim_phi_fit",&Pim_phi_fit,"Pim_phi_fit/D");
  
  Double_t Pim_vx, Pim_vy, Pim_vz;
  Int_t Pim_sec;
  
  t4->Branch("Pim_vx",&Pim_vx,"Pim_vx/D");
  t4->Branch("Pim_vy",&Pim_vy,"Pim_vy/D");
  t4->Branch("Pim_vz",&Pim_vz,"Pim_vz/D");
  t4->Branch("Pim_sec",&Pim_sec,"Pim_sec/D");
  
  Double_t Pim_dTOF, Timing_Pim;
  t4->Branch("Pim_dTOF",&Pim_dTOF,"Pim_dTOF/D");
  t4->Branch("Timing_Pim",&Timing_Pim,"Timing_Pim/D");
  
  Double_t Pim_px_missing_fit, Pim_py_missing_fit, Pim_pz_missing_fit, Pim_theta_missing_fit, Pim_phi_missing_fit;
  
  t4->Branch("Pim_px_missing_fit",&Pim_px_missing_fit,"Pim_px_missing_fit/D");
  t4->Branch("Pim_py_missing_fit",&Pim_py_missing_fit,"Pim_py_missing_fit/D");
  t4->Branch("Pim_pz_missing_fit",&Pim_pz_missing_fit,"Pim_pz_missing_fit/D");
  t4->Branch("Pim_theta_missing_fit",&Pim_theta_missing_fit,"Pim_theta_missing_fit/D");
  t4->Branch("Pim_phi_missing_fit",&Pim_phi_missing_fit,"Pim_phi_missing_fit/D");
  
  Double_t Pim_px_missing, Pim_py_missing, Pim_pz_missing, Pim_theta_missing, Pim_phi_missing;
  t4->Branch("Pim_px_missing",&Pim_px_missing,"Pim_px_missing/D");
  t4->Branch("Pim_py_missing",&Pim_py_missing,"Pim_py_missing/D");
  t4->Branch("Pim_pz_missing",&Pim_pz_missing,"Pim_pz_missing/D");
  t4->Branch("Pim_theta_missing",&Pim_theta_missing,"Pim_theta_missing/D");
  t4->Branch("Pim_phi_missing",&Pim_phi_missing,"Pim_phi_missing/D");
  
  
  Double_t Pim_Ptot_missing, Pim_Ptot_missing_fit;
  
  t4->Branch("Pim_Ptot_missing",&Pim_Ptot_missing,"Pim_Ptot_missing/D");
  t4->Branch("Pim_Ptot_missing_fit",&Pim_Ptot_missing_fit,"Pim_Ptot_missing_fit/D");
  
  
//------------------------------ For Fitting ------------------------------------------------------------
  
  Double_t Pull_Chi, Pull_Prob, Pull_Zero, Pull_One, Pull_Two, Pull_Three, Pull_Four, Pull_Five, Pull_Six;
  
  t4->Branch("Pull_Chi",&Pull_Chi,"Pull_Chi/D");
  t4->Branch("Pull_Prob",&Pull_Prob,"Pull_Prob/D");
  t4->Branch("Pull_Zero",&Pull_Zero,"Pull_Zero/D");
  t4->Branch("Pull_One",&Pull_One,"Pull_One/D");
  t4->Branch("Pull_Two",&Pull_Two,"Pull_Two/D");
  t4->Branch("Pull_Three",&Pull_Three,"Pull_Three/D");
  t4->Branch("Pull_Four",&Pull_Four,"Pull_Four/D");
  t4->Branch("Pull_Five",&Pull_Five,"Pull_Five/D");
  t4->Branch("Pull_Six",&Pull_Six,"Pull_Six/D");

  
  //----------------------------------------------------For Missing Mass -------------------------------------------------------------------
  
  Double_t mm_PPip_fit, mm_PPip, mm2_PPip_fit, mm2_PPip;
  t4->Branch("mm_PPip_fit",&mm_PPip_fit,"mm_PPip_fit/D");
  t4->Branch("mm_PPip",&mm_PPip,"mm_PPip/D");
  t4->Branch("mm2_PPip_fit",&mm2_PPip_fit,"mm2_PPip_fit/D");
  t4->Branch("mm2_PPip",&mm2_PPip,"mm2_PPip/D");
  
  //--------------------------------------------------------Fiducial cuts--------------------------------------------------------------------
  Int_t P_fidpass;
  Int_t Pip_fidpass;
  Int_t Pim_fidpass;
  
  t4->Branch("P_fidpass",&P_fidpass,"P_fidpass/I");
  t4->Branch("Pip_fidpass",&Pip_fidpass,"Pip_fidpass/I");
  t4->Branch("Pim_fidpass",&Pim_fidpass,"Pim_fidpass/I");
  
  //--------------------------------------------------------TOF KO--------------------------------------------------------------------
  
  Int_t P_tofKO, Pip_tofKO, Pim_tofKO;
  t4->Branch("P_tofKO",&P_tofKO,"P_tofKO/I");
  t4->Branch("Pip_tofKO",&Pip_tofKO,"Pip_tofKO/I");
  t4->Branch("Pim_tofKO",&Pim_tofKO,"Pim_tofKO/I");
  
  //---------------------------------------------Masses of Particles in GeV/c^2--------------------------------------------------
  
  Double_t M_P = 0.938272;   //Proton
  Double_t M_Pi = 0.139570;  //Pion
  Double_t c = 29.9792458; //units m/s/e7
  Double_t pi = TMath::Pi();
  Double_t DegToRad = pi/180.0;
  Double_t RadtoDeg = 180.0/pi;

  //----------------Initializing Lorentz Vectors -------------------------------------
  
  TLorentzVector vT, vEg, vP, vPip, vPim, vPip_fit, vP_fit, vEg_fit;
  vT.SetPxPyPzE(0.0, 0.0, 0.0, M_P);
  
  for( Int_t i = 0; i < nEvent ; i++){
    chain->GetEntry(i);
    
  
//    if (TMath::IsNaN(prot_P) || TMath::IsNaN(pip_P) || TMath::IsNaN(pim_P)) {continue;}
//    if (TMath::IsNaN(prot_Phi) || TMath::IsNaN(pip_Phi) || TMath::IsNaN(pim_Phi)) {continue;}
//    if (TMath::IsNaN(prot_Theta) || TMath::IsNaN(pip_Theta) || TMath::IsNaN(pim_Theta)) {continue;}
    
    if(!(i%100000)) std::cout << "\r done " << i << " out of " << nEvent << " ==> " << double(i)*100.0/double(nEvent) << "%" << flush;
    
    nPip = NPip; nPim = NPim; nProt = NProt;
    
    P_vx = prot_vx; prot_vy = P_vy; P_vz = prot_vz;
    P_sec = prot_sec;
    P_dTOF = prot_dTOF; Timing_P = Timing_prot;
    
    Pip_vx = pip_vx; Pip_vy = pip_vy; Pip_vz = pip_vz;
    Pip_sec = pip_sec;
    Pip_dTOF = pip_dTOF; Timing_Pip = Timing_pip;
    
    Pim_vx = pim_vx; Pim_vy = pim_vy; Pim_vz = pim_vz;
    Pim_sec = pim_sec;
    Pim_dTOF = pim_dTOF; Timing_Pim = Timing_pim;
  
    
    P_p = prot_P;
    P_theta = prot_Theta;
    P_phi = prot_Phi;
    double P_pxx = prot_P*sin(DegToRad*prot_Theta)*cos(DegToRad*prot_Phi);
    double P_pyy = prot_P*sin(DegToRad*prot_Theta)*sin(DegToRad*prot_Phi);
    double P_pzz = prot_P*cos(DegToRad*prot_Theta);
    //P_pz = Pt_Pl;
    
    Pip_p = pip_P;
    Pip_theta = pip_Theta;
    Pip_phi = pip_Phi;
    double Pip_pxx = pip_P*sin(DegToRad*pip_Theta)*cos(DegToRad*pip_Phi);
    double Pip_pyy = pip_P*sin(DegToRad*pip_Theta)*sin(DegToRad*pip_Phi);
    double Pip_pzz = pip_P*cos(DegToRad*pip_Theta);
    
    
    Pim_p = pim_P;
    Pim_theta = pim_Theta;
    Pim_phi = pim_Phi;
    double Pim_pxx = pim_P*sin(DegToRad*pim_Theta)*cos(DegToRad*pim_Phi);
    double Pim_pyy = pim_P*sin(DegToRad*pim_Theta)*sin(DegToRad*pim_Phi);
    double Pim_pzz = pim_P*cos(DegToRad*pim_Theta);
    
    P_px = P_pxx;
    P_py = P_pyy;
    P_pz = P_pzz;
    
    Pip_px = Pip_pxx;
    Pip_py = Pip_pyy;
    Pip_pz = Pip_pzz;
    
    Pim_px = Pim_pxx;
    Pim_py = Pim_pyy;
    Pim_pz = Pim_pzz;
    
    P_tofKO = prot_tofKO;
    Pip_tofKO = pip_tofKO;
    Pim_tofKO = pim_tofKO;
    
    
    P_fidpass = 0;
    Pip_fidpass = 0;
    Pim_fidpass = 0;
    
    if(clas::g12::g12_PosParticle_fiducial_cuts(prot_P,prot_Theta,prot_Phi,"nominal")){P_fidpass = 1;}
    if (NPim) {
      if(clas::g12::g12_NegParticle_fiducial_cuts(pim_P,pim_Theta,pim_Phi,"nominal")){Pim_fidpass = 1;}
    }
    if(clas::g12::g12_PosParticle_fiducial_cuts(pip_P,pip_Theta,pip_Phi,"nominal")){Pip_fidpass = 1;}
    

    
    //-------------------momenta squared-----------------------------------
    
    Double_t p2_P = P_px*P_px + P_py*P_py + P_pz*P_pz;
    Double_t p2_Pip = Pip_px*Pip_px + Pip_py*Pip_py + Pip_pz*Pip_pz;
    Double_t p2_Pim = Pim_px*Pim_px + Pim_py*Pim_py + Pim_pz*Pim_pz;
    
    //---------------------------Energy -----------------------------------
    
    Double_t E_P = sqrt(p2_P + M_P*M_P);
    Double_t E_Pip = sqrt(p2_Pip + M_Pi*M_Pi);
    Double_t E_Pim = sqrt(p2_Pim + M_Pi*M_Pi);
    
    Eg = egam;
    
    //----------------setting Lorentz Vectors -------------------------------------
    vEg.SetPxPyPzE(0.0, 0.0, Eg, Eg);
    vP.SetPxPyPzE(P_px, P_py, P_pz, E_P);
    vPip.SetPxPyPzE(Pip_px, Pip_py, Pip_pz, E_Pip);
    //vPim.SetPxPyPzE(Pim_px, Pim_py, Pim_pz, E_Pim);
    
    //----------------------------------------missing mass vectors----------------------------------------------------------------

    TLorentzVector MM_PPipVec = (vEg + vT) - (vP + vPip);
    mm2_PPip = MM_PPipVec.M2();
    mm_PPip = MM_PPipVec.M();
    
    Pim_px_missing = MM_PPipVec.Px();
    Pim_py_missing = MM_PPipVec.Py();
    Pim_pz_missing = MM_PPipVec.Pz();
    Pim_theta_missing = RadtoDeg*MM_PPipVec.Theta();
    Pim_phi_missing = RadtoDeg*MM_PPipVec.Phi();
    
    Pim_Ptot_missing = sqrt(pow(Pim_px_missing,2) + pow(Pim_py_missing,2) + pow(Pim_pz_missing,2));

    
    //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ Start	Kinematic Fitter $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
    
    //--------------------------------------------------- Start CovMatrix -------------------------------------------------------
    
    Double_t c00 = pow((0.001*5.715),2.)/3.; //Electron beam energy
    
    //    TMatrixD covMatrix(7,7);
    //    TMatrixD covTrack(7,7);
    
    TMatrixD covMatrix(7,7);
    TMatrixD covTrack(7,7);
    
    covTrack(0,0)=c00;
    
    //----------------------------------------------------For Proton-------------------------------------------------------------------
    
//    covTrack(1,1)= prot_mat[0][0]*pow(P_p,4);covTrack(1,2)= -prot_mat[0][1]*pow(P_p,2);covTrack(1,3)= -prot_mat[0][2]*pow(P_p,2);
//    covTrack(2,1)= -prot_mat[0][1]*pow(P_p,2);covTrack(2,2)= prot_mat[1][1];covTrack(2,3)= prot_mat[1][2];
//    covTrack(3,1)= -prot_mat[0][2]*pow(P_p,2);covTrack(3,2)= prot_mat[1][2];covTrack(3,3)=prot_mat[2][2];
//    
//    //----------------------------------------------------For Pip-------------------------------------------------------------------
//    
//    covTrack(4,4)= pip_mat[0][0]*pow(Pip_p,4);covTrack(4,5)= -pip_mat[0][1]*pow(Pip_p,2);covTrack(4,6)= -pip_mat[0][2]*pow(Pip_p,2);
//    covTrack(5,4)= -pip_mat[0][1]*pow(Pip_p,2);covTrack(5,5)= pip_mat[1][1];covTrack(5,6)= pim_mat[1][2];
//    covTrack(6,4)= -pip_mat[0][2]*pow(Pip_p,2);covTrack(6,5)= pip_mat[1][2];covTrack(6,6)= pip_mat[2][2];
//    
//    //----------------------------------------------------For Pim-------------------------------------------------------------------
//    covTrack(7,7)= pim_mat[0][0]*pow(Pim_p,4);covTrack(7,8)= pim_mat[0][1]*pow(Pim_p,2);covTrack(7,9)= pim_mat[0][2]*pow(Pim_p,2);
//    covTrack(8,7)= pim_mat[0][1]*pow(Pim_p,2);covTrack(8,8)= pim_mat[1][1];covTrack(8,9)= pim_mat[1][2];
//    covTrack(9,7)= pim_mat[0][2]*pow(Pim_p,2);covTrack(9,8)= pim_mat[1][2];covTrack(9,9)= pim_mat[2][2];
    
    
    
    //----------------------------------------------------For Proton-------------------------------------------------------------------
    
        covTrack(1,1)= prot_mat[0][0]*pow(P_p,4);covTrack(1,2)= -prot_mat[0][1]*pow(P_p,2);covTrack(1,3)= -prot_mat[0][2]*pow(P_p,2);
        covTrack(2,1)= -prot_mat[0][1]*pow(P_p,2);covTrack(2,2)= prot_mat[1][1];covTrack(2,3)= prot_mat[1][2];
        covTrack(3,1)= -prot_mat[0][2]*pow(P_p,2);covTrack(3,2)= prot_mat[1][2];covTrack(3,3)=prot_mat[2][2];
    
        //----------------------------------------------------For Pip-------------------------------------------------------------------
    
        covTrack(4,4)= pip_mat[0][0]*pow(Pip_p,4);covTrack(4,5)= -pip_mat[0][1]*pow(Pip_p,2);covTrack(4,6)= -pip_mat[0][2]*pow(Pip_p,2);
        covTrack(5,4)= -pip_mat[0][1]*pow(Pip_p,2);covTrack(5,5)= pip_mat[1][1];covTrack(5,6)= pim_mat[1][2];
        covTrack(6,4)= -pip_mat[0][2]*pow(Pip_p,2);covTrack(6,5)= pip_mat[1][2];covTrack(6,6)= pip_mat[2][2];
    
    //--------------------------------------------------- End CovMatrix -------------------------------------------------------
    
    const int num_parts = 2;               // Edit for total number of charged particles to be detected
    std::vector<TLorentzVector> p4(num_parts);
    std::vector<TVector3> vert(num_parts);
    std::vector<string> particles(num_parts);
    
    bool Multi = false;
    bool MC = true;
    std::vector<bool> set1(num_parts);
    
    set1[0] = false;
    set1[1] = false;
    //set1[2] = false;
    
    TVector3 vertP, vertPip, vertPim;
    
    vertP.SetXYZ(prot_vx, prot_vy, prot_vz);
    vertPip.SetXYZ(pip_vx, pip_vy, pip_vz);
    //vertPim.SetXYZ(pim_vx, pim_vy, pim_vz);
    
    
    p4[0] = vP;
    p4[1] = vPip;
    //p4[1] = vPim;
    
    vert[0] = vertP;
    vert[1] = vertPip;
    //vert[1] = vertPim;
    
    particles[0] = "p";
    particles[1] = "pi+";
    //particles[1] = "pi-";
    
    string experiment ="g12";
    
    covMatrix = CorrectCLAS_V(covTrack,particles,p4,vert,Multi,MC ,experiment);
    //	covMatrix2 = CorrectCLAS_V(covTrack,particles,p44,vert,momCor,is_mc,experiment);
    
    Kstream pifit;
    pifit.StringNames(particles);
    pifit.FitInput(Eg,p4,covMatrix,M_P);
    
    pifit.Fit("pi-");
    //pifit.Fit("p");
    
    Pull_Chi = pifit.Chi2();
    //        if(pifit.Prob() < 0.01){continue;}
    Pull_Prob = pifit.Prob();
    Pull_Zero = pifit.GetPull(0);
    Pull_One = pifit.GetPull(1);
    Pull_Two = pifit.GetPull(2);
    Pull_Three = pifit.GetPull(3);
    Pull_Four = pifit.GetPull(4);
    Pull_Five = pifit.GetPull(5);
    Pull_Six = pifit.GetPull(6);
    
    //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ End Kinematic Fitter $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
    
    Eg_fit = pifit.FitPhotonEnergy();
    
    for(int i = 0; i < num_parts; i++) p4[i] = pifit.FitP4(i);
    //for(int i = 0; i < 2; i++) p4[i] = pifit.FitP4(i);
    
    vEg_fit.SetPxPyPzE(0.0,0.0,Eg_fit,Eg_fit);
    vP_fit = p4[0];
    vPip_fit = p4[1];
    //vPim_fit = p4[1];
    
    
    TLorentzVector MM_PPipVec_fit = vEg_fit + vT - (vP_fit + vPip_fit);
    
    mm_PPip_fit = MM_PPipVec_fit.M();
    mm2_PPip_fit = MM_PPipVec_fit.M2();

    P_px_fit = vP.Px();
    P_py_fit = vP.Py();
    P_pz_fit = vP.Pz();
    
    Pip_px_fit = vPip_fit.Px();
    Pip_py_fit = vPip_fit.Py();
    Pip_pz_fit = vPip_fit.Pz();
    Pip_theta_fit = RadtoDeg*vPip_fit.Theta();
    Pip_phi_fit = RadtoDeg*vPip_fit.Phi();

    Pim_px_missing_fit = MM_PPipVec_fit.Px();
    Pim_py_missing_fit = MM_PPipVec_fit.Py();
    Pim_pz_missing_fit = MM_PPipVec_fit.Pz();
    Pim_theta_missing_fit = RadtoDeg*MM_PPipVec_fit.Theta();
    Pim_phi_missing_fit = RadtoDeg*MM_PPipVec_fit.Phi();

    
    P_Ptot_fit = sqrt(pow(P_px_fit,2) + pow(P_py_fit,2) + pow(P_pz_fit,2));
    Pip_Ptot_fit = sqrt(pow(Pip_px_fit,2) + pow(Pip_py_fit,2) + pow(Pip_pz_fit,2));
    Pim_Ptot_missing_fit = sqrt(pow(Pim_px_missing_fit,2) + pow(Pim_py_missing_fit,2) + pow(Pim_pz_missing_fit,2));
    
    
    if(Pull_Prob>0.01 && P_fidpass ==1 && Pip_fidpass ==1){
      t4->Fill();
    }
    // t4 ->Fill();
    
  }
  //###########################################   END OUTGOING DATA  ###############################################################
  
  t4->Write();
  f.Close();
}
//MKDone
