#include "TROOT.h"
#include "TRint.h"
#include "TTree.h"
#include "TFile.h"
#include "TBranch.h"
#include "TH1F.h"
#include "TH2F.h"


// structure definitions
typedef struct ntupcom{
  int run;
  int event;
  float egam;
  float tpho;
  float vx;
  float vy;
  float vz;
  float vtime;
  int NPart;
} Nt_com;
extern Nt_com nt;

#define MAX_HITS 10
#define MATRIX_NUM 5
#define IN_PHOT_HITS 100
typedef struct ntupcom1{
  
  int in_Nphoton;
  int N_in_timePhoton;
  int in_photon_stat[IN_PHOT_HITS];
  float in_photon_E[IN_PHOT_HITS];
  float in_photon_tpho[IN_PHOT_HITS];
  float in_photon_ttag[IN_PHOT_HITS];
  
  int NProt;
  int NPip;
  int NPim;
  
  //------------ For Pip -------------
  float pip_vz;
  float pip_vy;
  float pip_vx;
  
  float pip_P;
  float pip_Pt;
  float pip_Pl;
  float pip_Theta;
  float pip_Phi;
  
  int pip_sec;
  int pip_tofKO;
  
  float pip_dTOF;
  float pip_mat[MATRIX_NUM][MATRIX_NUM];
  float Timing_pip;
  
  //------------ For Pim --------------
  float pim_vz;
  float pim_vy;
  float pim_vx;
  float pim_P;
  float pim_Pt;
  float pim_Pl;
  float pim_Theta;
  float pim_Phi;
  
  int pim_sec;
  int pim_tofKO;
  
  float pim_dTOF;
  float pim_mat[MATRIX_NUM][MATRIX_NUM];
  
  float Timing_pim;
  
  
  //------------ For Proton -------------
  float prot_vz;
  float prot_vy;
  float prot_vx;
  
  float prot_P;
  float prot_Pt;
  float prot_Pl;
  float prot_Theta;
  float prot_Phi;
  
  int prot_sec;
  int prot_tofKO;
  
  float prot_dTOF;
  float prot_mat[MATRIX_NUM][MATRIX_NUM];
  float Timing_prot;
  
  
} Nt_com_e;
extern Nt_com_e ntlep;

/* some extra global variables */
extern  TFile lep_f;
extern  TTree lepTree;
