//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Jan 30 11:17:28 2017 by ROOT version 5.34/36
// from TTree Lep/Lep
// found on file: g12_Pim_Efficiency_8138.root
//////////////////////////////////////////////////////////

#ifndef Analyze_h
#define Analyze_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class Analyze {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Double_t        Eg;
   Double_t        Eg_fit;
   Int_t           nProt;
   Int_t           nPip;
   Int_t           nPim;
   Double_t        P_p;
   Double_t        P_px;
   Double_t        P_py;
   Double_t        P_pz;
   Double_t        P_theta;
   Double_t        P_phi;
   Double_t        P_px_fit;
   Double_t        P_py_fit;
   Double_t        P_pz_fit;
   Double_t        P_theta_fit;
   Double_t        P_phi_fit;
   Double_t        P_vx;
   Double_t        P_vy;
   Double_t        P_vz;
   Int_t           P_sec;
   Double_t        P_dTOF;
   Double_t        Timing_P;
   Double_t        P_Ptot_fit;
   Double_t        Pip_p;
   Double_t        Pip_px;
   Double_t        Pip_py;
   Double_t        Pip_pz;
   Double_t        Pip_theta;
   Double_t        Pip_phi;
   Double_t        Pip_px_fit;
   Double_t        Pip_py_fit;
   Double_t        Pip_pz_fit;
   Double_t        Pip_theta_fit;
   Double_t        Pip_phi_fit;
   Double_t        Pip_vx;
   Double_t        Pip_vy;
   Double_t        Pip_vz;
   Int_t           Pip_sec;
   Double_t        Pip_dTOF;
   Double_t        Timing_Pip;
   Double_t        Pip_Ptot_fit;
   Double_t        Pim_p;
   Double_t        Pim_px;
   Double_t        Pim_py;
   Double_t        Pim_pz;
   Double_t        Pim_theta;
   Double_t        Pim_phi;
   Double_t        Pim_vx;
   Double_t        Pim_vy;
   Double_t        Pim_vz;
   Double_t        Pim_sec;
   Double_t        Pim_dTOF;
   Double_t        Timing_Pim;
   Double_t        Pim_px_missing_fit;
   Double_t        Pim_py_missing_fit;
   Double_t        Pim_pz_missing_fit;
   Double_t        Pim_theta_missing_fit;
   Double_t        Pim_phi_missing_fit;
   Double_t        Pim_px_missing;
   Double_t        Pim_py_missing;
   Double_t        Pim_pz_missing;
   Double_t        Pim_theta_missing;
   Double_t        Pim_phi_missing;
   Double_t        Pim_Ptot_missing;
   Double_t        Pim_Ptot_missing_fit;
   Double_t        Pull_Chi;
   Double_t        Pull_Prob;
   Double_t        Pull_Zero;
   Double_t        Pull_One;
   Double_t        Pull_Two;
   Double_t        Pull_Three;
   Double_t        Pull_Four;
   Double_t        Pull_Five;
   Double_t        Pull_Six;
   Double_t        mm_PPip_fit;
   Double_t        mm_PPip;
   Double_t        mm2_PPip_fit;
   Double_t        mm2_PPip;
   Int_t           P_fidpass;
   Int_t           Pip_fidpass;
   Int_t           Pim_fidpass;
   Int_t           P_tofKO;
   Int_t           Pip_tofKO;
   Int_t           Pim_tofKO;

   // List of branches
   TBranch        *b_Eg;   //!
   TBranch        *b_Eg_fit;   //!
   TBranch        *b_nProt;   //!
   TBranch        *b_nPip;   //!
   TBranch        *b_nPim;   //!
   TBranch        *b_P_p;   //!
   TBranch        *b_P_px;   //!
   TBranch        *b_P_py;   //!
   TBranch        *b_P_pz;   //!
   TBranch        *b_P_theta;   //!
   TBranch        *b_P_phi;   //!
   TBranch        *b_P_px_fit;   //!
   TBranch        *b_P_py_fit;   //!
   TBranch        *b_P_pz_fit;   //!
   TBranch        *b_P_theta_fit;   //!
   TBranch        *b_P_phi_fit;   //!
   TBranch        *b_P_vx;   //!
   TBranch        *b_P_vy;   //!
   TBranch        *b_P_vz;   //!
   TBranch        *b_P_sec;   //!
   TBranch        *b_P_dTOF;   //!
   TBranch        *b_Timing_P;   //!
   TBranch        *b_P_Ptot_fit;   //!
   TBranch        *b_Pip_p;   //!
   TBranch        *b_Pip_px;   //!
   TBranch        *b_Pip_py;   //!
   TBranch        *b_Pip_pz;   //!
   TBranch        *b_Pip_theta;   //!
   TBranch        *b_Pip_phi;   //!
   TBranch        *b_Pip_px_fit;   //!
   TBranch        *b_Pip_py_fit;   //!
   TBranch        *b_Pip_pz_fit;   //!
   TBranch        *b_Pip_theta_fit;   //!
   TBranch        *b_Pip_phi_fit;   //!
   TBranch        *b_Pip_vx;   //!
   TBranch        *b_Pip_vy;   //!
   TBranch        *b_Pip_vz;   //!
   TBranch        *b_Pip_sec;   //!
   TBranch        *b_Pip_dTOF;   //!
   TBranch        *b_Timing_Pip;   //!
   TBranch        *b_Pip_Ptot_fit;   //!
   TBranch        *b_Pim_p;   //!
   TBranch        *b_Pim_px;   //!
   TBranch        *b_Pim_py;   //!
   TBranch        *b_Pim_pz;   //!
   TBranch        *b_Pim_theta;   //!
   TBranch        *b_Pim_phi;   //!
   TBranch        *b_Pim_vx;   //!
   TBranch        *b_Pim_vy;   //!
   TBranch        *b_Pim_vz;   //!
   TBranch        *b_Pim_sec;   //!
   TBranch        *b_Pim_dTOF;   //!
   TBranch        *b_Timing_Pim;   //!
   TBranch        *b_Pim_px_missing_fit;   //!
   TBranch        *b_Pim_py_missing_fit;   //!
   TBranch        *b_Pim_pz_missing_fit;   //!
   TBranch        *b_Pim_theta_missing_fit;   //!
   TBranch        *b_Pim_phi_missing_fit;   //!
   TBranch        *b_Pim_px_missing;   //!
   TBranch        *b_Pim_py_missing;   //!
   TBranch        *b_Pim_pz_missing;   //!
   TBranch        *b_Pim_theta_missing;   //!
   TBranch        *b_Pim_phi_missing;   //!
   TBranch        *b_Pim_Ptot_missing;   //!
   TBranch        *b_Pim_Ptot_missing_fit;   //!
   TBranch        *b_Pull_Chi;   //!
   TBranch        *b_Pull_Prob;   //!
   TBranch        *b_Pull_Zero;   //!
   TBranch        *b_Pull_One;   //!
   TBranch        *b_Pull_Two;   //!
   TBranch        *b_Pull_Three;   //!
   TBranch        *b_Pull_Four;   //!
   TBranch        *b_Pull_Five;   //!
   TBranch        *b_Pull_Six;   //!
   TBranch        *b_mm_PPip_fit;   //!
   TBranch        *b_mm_PPip;   //!
   TBranch        *b_mm2_PPip_fit;   //!
   TBranch        *b_mm2_PPip;   //!
   TBranch        *b_P_fidpass;   //!
   TBranch        *b_Pip_fidpass;   //!
   TBranch        *b_Pim_fidpass;   //!
   TBranch        *b_P_tofKO;   //!
   TBranch        *b_Pip_tofKO;   //!
   TBranch        *b_Pim_tofKO;   //!

   Analyze(TTree *tree=0);
   virtual ~Analyze();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Analyze_cxx
Analyze::Analyze(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("g12_Pim_Efficiency_8138.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("g12_Pim_Efficiency_8138.root");
      }
      f->GetObject("Lep",tree);

   }
   Init(tree);
}

Analyze::~Analyze()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Analyze::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Analyze::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void Analyze::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Eg", &Eg, &b_Eg);
   fChain->SetBranchAddress("Eg_fit", &Eg_fit, &b_Eg_fit);
   fChain->SetBranchAddress("nProt", &nProt, &b_nProt);
   fChain->SetBranchAddress("nPip", &nPip, &b_nPip);
   fChain->SetBranchAddress("nPim", &nPim, &b_nPim);
   fChain->SetBranchAddress("P_p", &P_p, &b_P_p);
   fChain->SetBranchAddress("P_px", &P_px, &b_P_px);
   fChain->SetBranchAddress("P_py", &P_py, &b_P_py);
   fChain->SetBranchAddress("P_pz", &P_pz, &b_P_pz);
   fChain->SetBranchAddress("P_theta", &P_theta, &b_P_theta);
   fChain->SetBranchAddress("P_phi", &P_phi, &b_P_phi);
   fChain->SetBranchAddress("P_px_fit", &P_px_fit, &b_P_px_fit);
   fChain->SetBranchAddress("P_py_fit", &P_py_fit, &b_P_py_fit);
   fChain->SetBranchAddress("P_pz_fit", &P_pz_fit, &b_P_pz_fit);
   fChain->SetBranchAddress("P_theta_fit", &P_theta_fit, &b_P_theta_fit);
   fChain->SetBranchAddress("P_phi_fit", &P_phi_fit, &b_P_phi_fit);
   fChain->SetBranchAddress("P_vx", &P_vx, &b_P_vx);
   fChain->SetBranchAddress("P_vy", &P_vy, &b_P_vy);
   fChain->SetBranchAddress("P_vz", &P_vz, &b_P_vz);
   fChain->SetBranchAddress("P_sec", &P_sec, &b_P_sec);
   fChain->SetBranchAddress("P_dTOF", &P_dTOF, &b_P_dTOF);
   fChain->SetBranchAddress("Timing_P", &Timing_P, &b_Timing_P);
   fChain->SetBranchAddress("P_Ptot_fit", &P_Ptot_fit, &b_P_Ptot_fit);
   fChain->SetBranchAddress("Pip_p", &Pip_p, &b_Pip_p);
   fChain->SetBranchAddress("Pip_px", &Pip_px, &b_Pip_px);
   fChain->SetBranchAddress("Pip_py", &Pip_py, &b_Pip_py);
   fChain->SetBranchAddress("Pip_pz", &Pip_pz, &b_Pip_pz);
   fChain->SetBranchAddress("Pip_theta", &Pip_theta, &b_Pip_theta);
   fChain->SetBranchAddress("Pip_phi", &Pip_phi, &b_Pip_phi);
   fChain->SetBranchAddress("Pip_px_fit", &Pip_px_fit, &b_Pip_px_fit);
   fChain->SetBranchAddress("Pip_py_fit", &Pip_py_fit, &b_Pip_py_fit);
   fChain->SetBranchAddress("Pip_pz_fit", &Pip_pz_fit, &b_Pip_pz_fit);
   fChain->SetBranchAddress("Pip_theta_fit", &Pip_theta_fit, &b_Pip_theta_fit);
   fChain->SetBranchAddress("Pip_phi_fit", &Pip_phi_fit, &b_Pip_phi_fit);
   fChain->SetBranchAddress("Pip_vx", &Pip_vx, &b_Pip_vx);
   fChain->SetBranchAddress("Pip_vy", &Pip_vy, &b_Pip_vy);
   fChain->SetBranchAddress("Pip_vz", &Pip_vz, &b_Pip_vz);
   fChain->SetBranchAddress("Pip_sec", &Pip_sec, &b_Pip_sec);
   fChain->SetBranchAddress("Pip_dTOF", &Pip_dTOF, &b_Pip_dTOF);
   fChain->SetBranchAddress("Timing_Pip", &Timing_Pip, &b_Timing_Pip);
   fChain->SetBranchAddress("Pip_Ptot_fit", &Pip_Ptot_fit, &b_Pip_Ptot_fit);
   fChain->SetBranchAddress("Pim_p", &Pim_p, &b_Pim_p);
   fChain->SetBranchAddress("Pim_px", &Pim_px, &b_Pim_px);
   fChain->SetBranchAddress("Pim_py", &Pim_py, &b_Pim_py);
   fChain->SetBranchAddress("Pim_pz", &Pim_pz, &b_Pim_pz);
   fChain->SetBranchAddress("Pim_theta", &Pim_theta, &b_Pim_theta);
   fChain->SetBranchAddress("Pim_phi", &Pim_phi, &b_Pim_phi);
   fChain->SetBranchAddress("Pim_vx", &Pim_vx, &b_Pim_vx);
   fChain->SetBranchAddress("Pim_vy", &Pim_vy, &b_Pim_vy);
   fChain->SetBranchAddress("Pim_vz", &Pim_vz, &b_Pim_vz);
   fChain->SetBranchAddress("Pim_sec", &Pim_sec, &b_Pim_sec);
   fChain->SetBranchAddress("Pim_dTOF", &Pim_dTOF, &b_Pim_dTOF);
   fChain->SetBranchAddress("Timing_Pim", &Timing_Pim, &b_Timing_Pim);
   fChain->SetBranchAddress("Pim_px_missing_fit", &Pim_px_missing_fit, &b_Pim_px_missing_fit);
   fChain->SetBranchAddress("Pim_py_missing_fit", &Pim_py_missing_fit, &b_Pim_py_missing_fit);
   fChain->SetBranchAddress("Pim_pz_missing_fit", &Pim_pz_missing_fit, &b_Pim_pz_missing_fit);
   fChain->SetBranchAddress("Pim_theta_missing_fit", &Pim_theta_missing_fit, &b_Pim_theta_missing_fit);
   fChain->SetBranchAddress("Pim_phi_missing_fit", &Pim_phi_missing_fit, &b_Pim_phi_missing_fit);
   fChain->SetBranchAddress("Pim_px_missing", &Pim_px_missing, &b_Pim_px_missing);
   fChain->SetBranchAddress("Pim_py_missing", &Pim_py_missing, &b_Pim_py_missing);
   fChain->SetBranchAddress("Pim_pz_missing", &Pim_pz_missing, &b_Pim_pz_missing);
   fChain->SetBranchAddress("Pim_theta_missing", &Pim_theta_missing, &b_Pim_theta_missing);
   fChain->SetBranchAddress("Pim_phi_missing", &Pim_phi_missing, &b_Pim_phi_missing);
   fChain->SetBranchAddress("Pim_Ptot_missing", &Pim_Ptot_missing, &b_Pim_Ptot_missing);
   fChain->SetBranchAddress("Pim_Ptot_missing_fit", &Pim_Ptot_missing_fit, &b_Pim_Ptot_missing_fit);
   fChain->SetBranchAddress("Pull_Chi", &Pull_Chi, &b_Pull_Chi);
   fChain->SetBranchAddress("Pull_Prob", &Pull_Prob, &b_Pull_Prob);
   fChain->SetBranchAddress("Pull_Zero", &Pull_Zero, &b_Pull_Zero);
   fChain->SetBranchAddress("Pull_One", &Pull_One, &b_Pull_One);
   fChain->SetBranchAddress("Pull_Two", &Pull_Two, &b_Pull_Two);
   fChain->SetBranchAddress("Pull_Three", &Pull_Three, &b_Pull_Three);
   fChain->SetBranchAddress("Pull_Four", &Pull_Four, &b_Pull_Four);
   fChain->SetBranchAddress("Pull_Five", &Pull_Five, &b_Pull_Five);
   fChain->SetBranchAddress("Pull_Six", &Pull_Six, &b_Pull_Six);
   fChain->SetBranchAddress("mm_PPip_fit", &mm_PPip_fit, &b_mm_PPip_fit);
   fChain->SetBranchAddress("mm_PPip", &mm_PPip, &b_mm_PPip);
   fChain->SetBranchAddress("mm2_PPip_fit", &mm2_PPip_fit, &b_mm2_PPip_fit);
   fChain->SetBranchAddress("mm2_PPip", &mm2_PPip, &b_mm2_PPip);
   fChain->SetBranchAddress("P_fidpass", &P_fidpass, &b_P_fidpass);
   fChain->SetBranchAddress("Pip_fidpass", &Pip_fidpass, &b_Pip_fidpass);
   fChain->SetBranchAddress("Pim_fidpass", &Pim_fidpass, &b_Pim_fidpass);
   fChain->SetBranchAddress("P_tofKO", &P_tofKO, &b_P_tofKO);
   fChain->SetBranchAddress("Pip_tofKO", &Pip_tofKO, &b_Pip_tofKO);
   fChain->SetBranchAddress("Pim_tofKO", &Pim_tofKO, &b_Pim_tofKO);
   Notify();
}

Bool_t Analyze::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Analyze::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Analyze::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Analyze_cxx
