#include <iostream>
#include <fstream>
#include "TF1.h"
extern "C" {
  
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <errno.h>
#include <ntypes.h>
#include <bostypes.h>
#include <clas_cern.h>
#include <particleType.h>
#include <kinematics.h>
#include <pdgutil.h>
#include <pid.h>
#include <scalers.h>
#include <utility.h>
#include <printBOS.h>
#include <ec.h>
#include <PartUtil.h>
#include <dataIO.h>
#include <itape.h>
#include <vertex.h>
#include <sc.h>
}

#include <Vec.h>
#include <lorentz.h>
#include <pputil.h>
#include <clasEvent.h>
#include <matrix.h>
#include <Ppp_cE.h>

#include "/u/home/mkunkel/G12_NECCESSITIES/g12_corrections/g12_corrections.hpp"

/*bitwise drop flags*/
#define DROP_RAW BIT(0)
#define DROP_DC0 BIT(1)
#define DROP_DC1 BIT(2)
#define DROP_HBLA BIT(3)
#define DROP_TBLA BIT(4)
#define DROP_HBTB BIT(5)
#define DROP_SC BIT(6)
#define DROP_EC BIT(7)
#define DROP_HBID BIT(8)
#define DROP_CL01 BIT(9)
#define DROP_SEB BIT(10)
#define DROP_TBID BIT(11)
#define DROP_HDPL BIT(12)
#define DROP_LAC BIT(13)
#define DROP_CC BIT(14)
#define DROP_ST BIT(15)
#define DROP_DHCL BIT(16)
#define DROP_TAGR BIT(17)

#define BUFSIZE 200000
#define PI 3.1415927

Nt_com nt;
Nt_com_e ntlep;


int Get_NInComingGamma(BOSbank);
int Get_NInTimeComingGamma(BOSbank, float);
int GetInComingGamma(BOSbank, int, int*, float*, float*, float*);


extern "C" {
  void bnames_(int *);
  int SetVerbose(int);
}

int StartRun(int);
int ProcessEvent(clasEvent &event);
int DropList(int DropFlag);
void PrintUsage(char *processName);
void Ppp_cE_tree();

int CurrentRun = 0;
int CurrentEvent = 0;
int partbank0 = 1;
int partbank = 0;

static int count = 0;
bool checkCon = false;

int StartRun(int runNo)
{
  if (CurrentRun != runNo) {
    vertex_brun(runNo);
    make_SCG_banks(runNo);
    CurrentRun = runNo;
  }
  return 0;
}

extern particleDataTable PDGtable;

int DropList(int DropFlag)
{
  /* Mask off banks according to DropFlag*/
  
  if (DropFlag & DROP_RAW) bankList(&bcs_, "E-", "R");
  if (DropFlag & DROP_DC0) bankList(&bcs_, "E-", "DC0 ");
  if (DropFlag & DROP_DC1) bankList(&bcs_, "E-", "DC1 ");
  if (DropFlag & DROP_HBLA) bankList(&bcs_, "E-", "HBLA");
  if (DropFlag & DROP_TBLA) bankList(&bcs_, "E-", "TBLA");
  if (DropFlag & DROP_HBTB) bankList(&bcs_, "E-", "HBTB");
  if (DropFlag & DROP_SC) bankList(&bcs_, "E-", SC_BANKS);
  if (DropFlag & DROP_EC) bankList(&bcs_, "E-", EC_BANKS);
  if (DropFlag & DROP_HBID) bankList(&bcs_, "E-", "HBID");
  if (DropFlag & DROP_CL01) bankList(&bcs_, "E-", "CL01");
  if (DropFlag & DROP_SEB) bankList(&bcs_, "E-", SEB_BANKS);
  if (DropFlag & DROP_TBID) bankList(&bcs_, "E-", "TBIDPARTTBERTBTR");
  if (DropFlag & DROP_HDPL) bankList(&bcs_, "E-", "HDPL");
  if (DropFlag & DROP_LAC) bankList(&bcs_, "E-", "EC1R");
  if (DropFlag & DROP_CC) bankList(&bcs_, "E-", CC_BANKS);
  if (DropFlag & DROP_ST) bankList(&bcs_, "E-", ST_BANKS);
  if (DropFlag & DROP_DHCL) bankList(&bcs_, "E-", "DHCL");
  if (DropFlag & DROP_TAGR) bankList(&bcs_, "E-", TAGGER_BANKS);
  
  return(0);
}


void PrintUsage(char *processName)
{
  cerr << processName << " <options> <filename>\n";
  cerr << "\toptions are:\n";
  cerr << "\t-b#\t\tSet beam type(0=electron, 1=photon[def.], 2=g7, etc).\n";
  cerr << "\t-t#\t\ttrigger mask.\n";
  cerr << "\t-p#\t\tUse this PART bank group number(default=1).\n";
  cerr << "\t-D#\t\tDrop flag.\n";
  cerr << "\t-o<filename>\tBOS output file.\n";
  cerr << "\t-M#\t\tprocess maximum # of events.\n";
  cerr << "\t-i\t\tquiet mode (no counter).\n";
  cerr << "\t-T\t\tRebuild the TBID banks.\n";
  cerr << "\t-h\t\tprint the above" << endl;
}


/* -------Root stuff must be global in SCOPE ------------*/

TFile lep_f("Ppp_cE.root","RECREATE");
TTree lepTree("lepTree","Ppp_cE tree");

// ------------------------------------------------
// ------------------ Main program ----------------
// ---------- To be modified to fit need ----------
// ------------------------------------------------

int main(int argc,char **argv)
{
  
  extern char *optarg;
  int c;
  extern int optind;
  
  int i;
  int max = 0;
  int verbose = 0;
  int ret = 1;
  int Nevents = 0;
  int Nproc = 0;
  int Nwrite = 0;
  char *argptr;
  int Dispatch = 0;
  unsigned int tMask = 0;
  int writeFlag = 0;
  int remakeTBID = 0;
  int BeamType = 1;
  
  // bos stuff
  clasOutput coutput;
  char *BOSoutfile = "Ppp_cE.bos";
  int OutputUnitNo = 9;
  int MaxBanks = 1000;
  char  out[300];
  char Elist[5 * MaxBanks];
  
  int DropFlag = 0x0;
  bool bBatchMode = false;    // events counter is on by default
  
  for (i = 0; i < argc; ++i) cerr << argv[i] << " "; cerr << endl;
  while ((c = getopt(argc,argv, "b:Tt:p:D:o:M:ih")) != -1 ) {
    switch (c) {
        
      case 'b':
        BeamType = atoi(optarg);
        set_beam_type(BeamType); // set beam type for RUNC bank
        break;
        
      case 'T':
        remakeTBID = 1;
        break;
        
      case 't':
        tMask = strtoul(optarg,NULL,0);
        break;
        
      case 'p':
        partbank0 = atoi(optarg);
        cerr << "Using PART bank " << partbank0 << " for analysis" << endl;
        break;
        
      case 'D':
        DropFlag = strtoul(optarg,NULL,0);
        break;
        
      case 'o':
        BOSoutfile = optarg;
        if(BOSoutfile) {
          unlink(BOSoutfile);
          coutput.open(BOSoutfile,OutputUnitNo);
          cerr << "Output file: " << BOSoutfile << endl;
        }
        
        break;
        
      case 'M':
        max = atoi(optarg);
        break;
        
      case 'i':
        bBatchMode = true;
        break;
        
      case 'h':
        PrintUsage(argv[0]);
        exit(0);
        break;
        
      default:
        cerr << "Unrecognized argument: " << optarg << endl;
        PrintUsage(argv[0]);
        exit(0);
        break;
    }
  }
  
  // Initialize BOS
  bnames_(&MaxBanks);
  initbos();
  configure_banks(stderr,0);
  
  PDGtable.initialize();
  
  Ppp_cE_tree();
  
  for (i = optind; i < argc; ++i) {
    argptr = argv[i];
    // process all arguments on command line.
    if (*argptr != '-') {
      // we have a file to process
      clasEvent event(argptr,&bcs_,partbank0,0);
      
      cerr << "initialize:\t" << argptr << endl;
      
      Dispatch = isDispatcher(argptr);
      if (event.status()) {
        ret = 1;
        while ((max ? Nevents < max : 1) && ret) {
          // process every event in the file
          ret = event.read(partbank0);
          if (ret == DISIO_DATA) {
            
            Nevents++;
            if (!bBatchMode && ((Nevents % 100) == 0)){
              cerr << Nevents << "\r";
            }
            if (event.status()) {
              if(event.triggerMask(tMask)){
                
                int runno = event.run();
                StartRun(runno);
                InitEloss(runno);
                
                if(remakeTBID) event.buildTBID(partbank0);
                
                writeFlag = ProcessEvent(event);
                if (coutput.status() && writeFlag) {
                  if (DropFlag) {
                    DropList(DropFlag);
                  }
                  coutput.write(&bcs_);
                  Nwrite++;
                }
              }
            }
          }else if (ret == DISIO_COMMAND) {
            cerr << "Message from Giant Head: " << getBuffer() << endl;;
          }
          event.clean();
          Nproc++;
        }
        cerr << "\nTotal number of itape records read:\t" << Nevents << endl;
        cerr << "Total number of events processed:\t" << Nproc << endl;
        cerr << "\tTotal number of records written:\t" << Nwrite << endl;
      }else {
        cerr << "Unable to open " << argptr << endl;
      }
    }
  }
  
  if (Dispatch) {
    disIO_command("FINISHED");
  }
  
  cerr << "\nTotal number of itape records:\t" << Nevents << endl;
  
  /*  close root file  */
  lep_f.Write();
  lep_f.Close();
  
  // Write and close the BOS output file
  if(coutput.status()) {
    coutput.write(&bcs_,"0");
    coutput.close();
  }
  
  return (0);
}


// ------------------------------------------------
// ---------------- ProcessEvent ------------------
// ------------ Make all analysis here ------------
// ------------------------------------------------

int ProcessEvent(clasEvent &event)
{
  event.eLoss();  // This does energy loss for the event.
  //event.g12Pcor();  //Momentum corrections....
  
  // Here I set up the clas particles I am interested in skimming
  clasParticle prot;
  clasParticle pip;
  clasParticle pim;
  clasParticle photon;
  
  // I will want to do some rudimentary 4-vector analysis on the reaction, so here I define some clasEvent 4-vectors.
  fourVec pip4V;
  fourVec pim4V;
  fourVec prot4V;
  fourVec phot4V;
  fourVec init_beam;
  
  fourVec photon4V[MAX_HITS];
  fourVec target(0.9382,threeVec(0.0,0.0,0.0));
  
  vector<float>photon4V_Theta;
  vector<float>photon4V_Phi;
  vector<float>photon4V_P;
  
  
  // These are counters
  int Npos;   //Total number of pi+
  int Nneg;   //Total number of pi-
  int Npart;  //Total number of particles
  int Nprot;  //Total number of protons
  int Ngam;   //Total number of photons
  int NcharP; //Total number of detected charged particles
  
  int ret=0;
  
  //These are for saving variables into my root ntuple
  memset(&nt,0,sizeof(nt));
  memset(&ntlep,0,sizeof(ntlep));
  
  
  Nprot = event.N(Proton);
  Npart = event.N();
  Npos = event.N(PiPlus);
  Nneg = event.N(PiMinus);

  
  NcharP = Nprot + Npos + Nneg;  // Georgie (have added a cut of Ngam below)
  if((Npos == 1) && (Nprot == 1)){
    
    nt.run = event.run(); // get run number
    nt.event = event.event(); // get event number
    
    fourVec beam = event.beam().get4P(); // photon beam 4V
    nt.egam = beam.t();          // photon beam energy
    
    nt.tpho = event.tpho(); // Photon timing
    nt.vtime = event.vtime(); // The event vertex time
    
    nt.vx = event.x(); // x vertex of the event
    nt.vy = event.y(); // y vertex of the event
    nt.vz = event.z(); // z vertex of the event
    
    nt.NPart = Npart;
    ntlep.NProt = Nprot;
    ntlep.NPip = Npos;
    
//    int N_incoming = Get_NInComingGamma(bcs_);
//    ntlep.in_Nphoton = N_incoming;
//    
//    ntlep.N_in_timePhoton = Get_NInTimeComingGamma(bcs_, event.tpho());
//    
//    int N_in_time_hold = 0;
    
//    for(int i = 0; i <N_incoming; i++){
//      int in_phot_stat;
//      float in_phot_E;
//      float in_phot_tpho;
//      float in_phot_ttag;
//      int check_incoming = GetInComingGamma(bcs_, i, &in_phot_stat,  &in_phot_E,  &in_phot_tpho,  &in_phot_ttag);
//      if (in_phot_stat == 7 || in_phot_stat ==15) {
//        if (abs(event.tpho() - in_phot_tpho)<= 1.002) {
//          
//          ntlep.in_photon_stat[N_in_time_hold] = in_phot_stat;
//          ntlep.in_photon_E[N_in_time_hold] = in_phot_E;
//          ntlep.in_photon_tpho[N_in_time_hold] = in_phot_tpho;
//          ntlep.in_photon_ttag[N_in_time_hold] = in_phot_ttag;
//          
//          N_in_time_hold++;
//        }
//      }
//    }
    
    
    // Here I set the clasParticles in the event
    pip = event.cp(PiPlus,1);
    ntlep.pip_tofKO = clas::g12::pass_g12_TOFKO(pip.sec(),pip.scPaddleId(), 1);
    //------------ For Pip -------------
    ntlep.pip_vz = pip.z();    // This is the z-vertex of the pi+
    ntlep.pip_vy = pip.y();    // This is the y-vertex of the pi+
    ntlep.pip_vx = pip.x();    // This is the x-vertex of the pi+
    pip4V = pip.p();           // Here I set the 4-vector for the pi+
    ntlep.pip_P = ~pip4V.V();    // This is the pi+ momentum magnitude
    ntlep.pip_sec = pip.sec();
    //All variables are in the lab-frame.
    ntlep.pip_Pl = pip4V.V().z(); // Longitudinal momentum
    ntlep.pip_Pt = sqrt(pip4V.V().x()*pip4V.V().x() + pip4V.V().y()*pip4V.V().y()); // Transverse momentum
    ntlep.pip_Theta = RAD2DEG*pip.p().V().theta(); // Theta
    ntlep.pip_Phi = RAD2DEG*pip.p().V().phi(); //Phi
    double dPip_TOF = ((pip.sc_time() - pip.st_time()) - (pip.pathlenST_SC()/(~pip4V.V()))*sqrt(pow(0.1349,2) + pow(~pip4V.V(),2))/29.9792458);
    ntlep.pip_dTOF = dPip_TOF;
    ntlep.Timing_pip = event.tpho() - pip.scVertexTime(M(PiPlus)) + pip.tprop(ntlep.pip_vz);
    
    //------------ For Prot --------------
    
    prot = event.cp(Proton,1);
    ntlep.prot_tofKO = clas::g12::pass_g12_TOFKO(prot.sec(), prot.scPaddleId(), 1);

    ntlep.prot_vz = prot.z();    // This is the z-vertex of the pi+
    ntlep.prot_vy = prot.y();    // This is the y-vertex of the pi+
    ntlep.prot_vx = prot.x();    // This is the x-vertex of the pi+
    prot4V = prot.p();           // Here I set the 4-vector for the pi+
    ntlep.prot_P = ~prot4V.V();    // This is the pi+ momentum magnitude
    ntlep.prot_sec = prot.sec();
    //All variables are in the lab-frame.
    ntlep.prot_Pl = prot4V.V().z(); // Longitudinal momentum
    ntlep.prot_Pt = sqrt(prot4V.V().x()*prot4V.V().x() + prot4V.V().y()*prot4V.V().y()); // Transverse momentum
    ntlep.prot_Theta = RAD2DEG*prot.p().V().theta(); // Theta
    ntlep.prot_Phi = RAD2DEG*prot.p().V().phi(); //Phi
    double dprot_TOF = ((prot.sc_time() - prot.st_time()) - (prot.pathlenST_SC()/(~prot4V.V()))*sqrt(pow(0.9382,2) + pow(~prot4V.V(),2))/29.9792458);
    ntlep.prot_dTOF = dprot_TOF;
    ntlep.Timing_prot = event.tpho() - prot.scVertexTime(M(Proton)) + prot.tprop(ntlep.prot_vz);
    
    
    //###################### TBER Matrix #####################################
    //------------ FOR PIP TBER MATRIX -----------------------------
    
    matrix<double> pip_matrix = pip.TBERmatrix();
    
    ntlep.pip_mat[0][0] = pip_matrix.el(0,0);
    ntlep.pip_mat[0][1] = pip_matrix.el(0,1);
    ntlep.pip_mat[0][2] = pip_matrix.el(0,2);
    ntlep.pip_mat[0][3] = pip_matrix.el(0,3);
    ntlep.pip_mat[0][4] = pip_matrix.el(0,4);
    
    ntlep.pip_mat[1][1] = pip_matrix.el(1,1);
    ntlep.pip_mat[1][2] = pip_matrix.el(1,2);
    ntlep.pip_mat[1][3] = pip_matrix.el(1,3);
    ntlep.pip_mat[1][4] = pip_matrix.el(1,4);
    
    ntlep.pip_mat[2][2] = pip_matrix.el(2,2);
    ntlep.pip_mat[2][3] = pip_matrix.el(2,3);
    ntlep.pip_mat[2][4] = pip_matrix.el(2,4);
    
    ntlep.pip_mat[3][3] = pip_matrix.el(3,3);
    ntlep.pip_mat[3][4] = pip_matrix.el(3,4);
    
    ntlep.pip_mat[4][4] = pip_matrix.el(4,4);
    
    //Symmetric part--------------------------
    ntlep.pip_mat[1][0] = pip_matrix.el(1,0);
    
    ntlep.pip_mat[2][0] = pip_matrix.el(2,0);
    ntlep.pip_mat[2][1] = pip_matrix.el(2,1);
    
    ntlep.pip_mat[3][0] = pip_matrix.el(3,0);
    ntlep.pip_mat[3][1] = pip_matrix.el(3,1);
    ntlep.pip_mat[3][2] = pip_matrix.el(3,2);
    
    ntlep.pip_mat[4][0] = pip_matrix.el(4,0);
    ntlep.pip_mat[4][1] = pip_matrix.el(4,1);
    ntlep.pip_mat[4][2] = pip_matrix.el(4,2);
    ntlep.pip_mat[4][3] = pip_matrix.el(4,3);
    
    //------------ FOR PROT TBER MATRIX -----------------------------
    
    matrix<double> prot_matrix = prot.TBERmatrix();
    
    ntlep.prot_mat[0][0] = prot_matrix.el(0,0);
    ntlep.prot_mat[0][1] = prot_matrix.el(0,1);
    ntlep.prot_mat[0][2] = prot_matrix.el(0,2);
    ntlep.prot_mat[0][3] = prot_matrix.el(0,3);
    ntlep.prot_mat[0][4] = prot_matrix.el(0,4);
    
    ntlep.prot_mat[1][1] = prot_matrix.el(1,1);
    ntlep.prot_mat[1][2] = prot_matrix.el(1,2);
    ntlep.prot_mat[1][3] = prot_matrix.el(1,3);
    ntlep.prot_mat[1][4] = prot_matrix.el(1,4);
    
    ntlep.prot_mat[2][2] = prot_matrix.el(2,2);
    ntlep.prot_mat[2][3] = prot_matrix.el(2,3);
    ntlep.prot_mat[2][4] = prot_matrix.el(2,4);
    
    ntlep.prot_mat[3][3] = prot_matrix.el(3,3);
    ntlep.prot_mat[3][4] = prot_matrix.el(3,4);
    
    ntlep.prot_mat[4][4] = prot_matrix.el(4,4);
    
    //Symmetric part--------------------------
    ntlep.prot_mat[1][0] = prot_matrix.el(1,0);
    
    ntlep.prot_mat[2][0] = prot_matrix.el(2,0);
    ntlep.prot_mat[2][1] = prot_matrix.el(2,1);
    
    ntlep.prot_mat[3][0] = prot_matrix.el(3,0);
    ntlep.prot_mat[3][1] = prot_matrix.el(3,1);
    ntlep.prot_mat[3][2] = prot_matrix.el(3,2);
    
    ntlep.prot_mat[4][0] = prot_matrix.el(4,0);
    ntlep.prot_mat[4][1] = prot_matrix.el(4,1);
    ntlep.prot_mat[4][2] = prot_matrix.el(4,2);
    ntlep.prot_mat[4][3] = prot_matrix.el(4,3);
    
    
    //------------ For Pim -------------
    if(Nneg == 1){
      ntlep.NPim = Nneg;

      pim = event.cp(PiMinus,1);
      ntlep.pim_tofKO = clas::g12::pass_g12_TOFKO(pim.sec(), pim.scPaddleId(), 1);

      ntlep.pim_vz = pim.z();    // This is the z-vertex of the pi+
      ntlep.pim_vy = pim.y();    // This is the y-vertex of the pi+
      ntlep.pim_vx = pim.x();    // This is the x-vertex of the pi+
      pim4V = pim.p();           // Here I set the 4-vector for the pi+
      ntlep.pim_P = ~pim4V.V();    // This is the pi+ momentum magnitude
      ntlep.pim_sec = pim.sec();
      //All variables are in the lab-frame.
      ntlep.pim_Pl = pim4V.V().z(); // Longitudinal momentum
      ntlep.pim_Pt = sqrt(pim4V.V().x()*pim4V.V().x() + pim4V.V().y()*pim4V.V().y()); // Transverse momentum
      ntlep.pim_Theta = RAD2DEG*pim.p().V().theta(); // Theta
      ntlep.pim_Phi = RAD2DEG*pim.p().V().phi(); //Phi
      double dpim_TOF = ((pim.sc_time() - pim.st_time()) - (pim.pathlenST_SC()/(~pim4V.V()))*sqrt(pow(0.1349,2) + pow(~pim4V.V(),2))/29.9792458);
      ntlep.pim_dTOF = dpim_TOF;
      ntlep.Timing_pim = event.tpho() - pim.scVertexTime(M(PiMinus)) + pim.tprop(ntlep.pim_vz);
      
      //-------------- FOR PIM TBER MATRIX ----------------------------
      
      matrix<double> pim_matrix = pim.TBERmatrix();
      
      ntlep.pim_mat[0][0] = pim_matrix.el(0,0);
      ntlep.pim_mat[0][1] = pim_matrix.el(0,1);
      ntlep.pim_mat[0][2] = pim_matrix.el(0,2);
      ntlep.pim_mat[0][3] = pim_matrix.el(0,3);
      ntlep.pim_mat[0][4] = pim_matrix.el(0,4);
      
      ntlep.pim_mat[1][1] = pim_matrix.el(1,1);
      ntlep.pim_mat[1][2] = pim_matrix.el(1,2);
      ntlep.pim_mat[1][3] = pim_matrix.el(1,3);
      ntlep.pim_mat[1][4] = pim_matrix.el(1,4);
      
      ntlep.pim_mat[2][2] = pim_matrix.el(2,2);
      ntlep.pim_mat[2][3] = pim_matrix.el(2,3);
      ntlep.pim_mat[2][4] = pim_matrix.el(2,4);
      
      ntlep.pim_mat[3][3] = pim_matrix.el(3,3);
      ntlep.pim_mat[3][4] = pim_matrix.el(3,4);
      
      ntlep.pim_mat[4][4] = pim_matrix.el(4,4);
      
      //Symmetric part--------------------------
      ntlep.pim_mat[1][0] = pim_matrix.el(1,0);
      
      ntlep.pim_mat[2][0] = pim_matrix.el(2,0);
      ntlep.pim_mat[2][1] = pim_matrix.el(2,1);
      
      ntlep.pim_mat[3][0] = pim_matrix.el(3,0);
      ntlep.pim_mat[3][1] = pim_matrix.el(3,1);
      ntlep.pim_mat[3][2] = pim_matrix.el(3,2);
      
      ntlep.pim_mat[4][0] = pim_matrix.el(4,0);
      ntlep.pim_mat[4][1] = pim_matrix.el(4,1);
      ntlep.pim_mat[4][2] = pim_matrix.el(4,2);
      ntlep.pim_mat[4][3] = pim_matrix.el(4,3);
      
    }
    else{ntlep.NPim = 0;}
    
    lepTree.Fill();
    ret = 1;
  }
  //lepTree.Fill();
  //ret = 1;
  return (ret);
  
}


int Get_NInComingGamma(BOSbank ptr_)
{
  int to_be_returned = 0;
  
  clasTAGR_t *TAGR = (clasTAGR_t *) getBank(&ptr_,"TAGR");
  
  if(TAGR){
    
    to_be_returned = TAGR->bank.nrow;
    
  }
  return to_be_returned;
}

int Get_NInTimeComingGamma(BOSbank ptr_, float time1)//time1 is tpho of chosen by reconstruction.
{
  int to_be_returned = 0;
  
  clasTAGR_t *TAGR = (clasTAGR_t *) getBank(&ptr_,"TAGR");
  
  if(TAGR){
    for (int jh =0 ; jh < TAGR->bank.nrow; jh++) {
      tagr_t *tagr = &TAGR->tagr[jh];
      float E1 = tagr->erg;
      float TPHO = tagr->tpho;
      float TTAG = tagr->ttag;
      int ID =tagr->stat;
      if (ID == 7 || ID ==15) {
        if (abs(time1 - TPHO)< 1.002) {
          to_be_returned++;
        }
      }
    }
  }
  return to_be_returned;
}

int GetInComingGamma(BOSbank ptr_, int N ,int *ID, float *E1, float *TPHO, float *TTAG)
{
  
  int to_be_returned = 1;
  clasTAGR_t *TAGR = (clasTAGR_t *) getBank(&ptr_,"TAGR");
  
  if(TAGR){
    tagr_t *tagr = &TAGR->tagr[N];
    (*E1) = tagr->erg;
    (*TPHO) = tagr->tpho;
    (*TTAG) = tagr->ttag;
    (*ID) =tagr->stat;
    
  }
  return to_be_returned;
}
