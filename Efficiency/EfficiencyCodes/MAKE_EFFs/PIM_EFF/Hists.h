#include "TROOT.h"
#include "TRint.h"
#include "TTree.h"
#include "TFile.h"
#include "TBranch.h"
#include "TH1F.h"
#include "TH2F.h"

TH2D *hmissing_I_I;
TH2D *hdetect_I_I;
TH2D *hEff_I_I;

TH2D *hmissing_I_II;
TH2D *hdetect_I_II;
TH2D *hEff_I_II;

TH2D *hmissing_I_III;
TH2D *hdetect_I_III;
TH2D *hEff_I_III;

TH2D *hmissing_I_IV;
TH2D *hdetect_I_IV;
TH2D *hEff_I_IV;

TH2D *hmissing_I_V;
TH2D *hdetect_I_V;
TH2D *hEff_I_V;

TH2D *hmissing_I_VI;
TH2D *hdetect_I_VI;
TH2D *hEff_I_VI;

TH2D *hmissing_I_VII;
TH2D *hdetect_I_VII;
TH2D *hEff_I_VII;

TH2D *hmissing_I_VIII;
TH2D *hdetect_I_VIII;
TH2D *hEff_I_VIII;

TH2D *hmissing_II_I;
TH2D *hdetect_II_I;
TH2D *hEff_II_I;

TH2D *hmissing_II_II;
TH2D *hdetect_II_II;
TH2D *hEff_II_II;

TH2D *hmissing_II_III;
TH2D *hdetect_II_III;
TH2D *hEff_II_III;

TH2D *hmissing_II_IV;
TH2D *hdetect_II_IV;
TH2D *hEff_II_IV;

TH2D *hmissing_II_V;
TH2D *hdetect_II_V;
TH2D *hEff_II_V;

TH2D *hmissing_II_VI;
TH2D *hdetect_II_VI;
TH2D *hEff_II_VI;

TH2D *hmissing_II_VII;
TH2D *hdetect_II_VII;
TH2D *hEff_II_VII;

TH2D *hmissing_II_VIII;
TH2D *hdetect_II_VIII;
TH2D *hEff_II_VIII;

TH2D *hmissing_III_I;
TH2D *hdetect_III_I;
TH2D *hEff_III_I;

TH2D *hmissing_III_II;
TH2D *hdetect_III_II;
TH2D *hEff_III_II;

TH2D *hmissing_III_III;
TH2D *hdetect_III_III;
TH2D *hEff_III_III;

TH2D *hmissing_III_IV;
TH2D *hdetect_III_IV;
TH2D *hEff_III_IV;

TH2D *hmissing_III_V;
TH2D *hdetect_III_V;
TH2D *hEff_III_V;

TH2D *hmissing_III_VI;
TH2D *hdetect_III_VI;
TH2D *hEff_III_VI;

TH2D *hmissing_III_VII;
TH2D *hdetect_III_VII;
TH2D *hEff_III_VII;

TH2D *hmissing_III_VIII;
TH2D *hdetect_III_VIII;
TH2D *hEff_III_VIII;

TH2D *hmissing_IV_I;
TH2D *hdetect_IV_I;
TH2D *hEff_IV_I;

TH2D *hmissing_IV_II;
TH2D *hdetect_IV_II;
TH2D *hEff_IV_II;

TH2D *hmissing_IV_III;
TH2D *hdetect_IV_III;
TH2D *hEff_IV_III;

TH2D *hmissing_IV_IV;
TH2D *hdetect_IV_IV;
TH2D *hEff_IV_IV;

TH2D *hmissing_IV_V;
TH2D *hdetect_IV_V;
TH2D *hEff_IV_V;

TH2D *hmissing_IV_VI;
TH2D *hdetect_IV_VI;
TH2D *hEff_IV_VI;

TH2D *hmissing_IV_VII;
TH2D *hdetect_IV_VII;
TH2D *hEff_IV_VII;

TH2D *hmissing_IV_VIII;
TH2D *hdetect_IV_VIII;
TH2D *hEff_IV_VIII;

TH2D *hmissing_V_I;
TH2D *hdetect_V_I;
TH2D *hEff_V_I;

TH2D *hmissing_V_II;
TH2D *hdetect_V_II;
TH2D *hEff_V_II;

TH2D *hmissing_V_III;
TH2D *hdetect_V_III;
TH2D *hEff_V_III;

TH2D *hmissing_V_IV;
TH2D *hdetect_V_IV;
TH2D *hEff_V_IV;

TH2D *hmissing_V_V;
TH2D *hdetect_V_V;
TH2D *hEff_V_V;

TH2D *hmissing_V_VI;
TH2D *hdetect_V_VI;
TH2D *hEff_V_VI;

TH2D *hmissing_V_VII;
TH2D *hdetect_V_VII;
TH2D *hEff_V_VII;

TH2D *hmissing_V_VIII;
TH2D *hdetect_V_VIII;
TH2D *hEff_V_VIII;

TH2D *hmissing_VI_I;
TH2D *hdetect_VI_I;
TH2D *hEff_VI_I;

TH2D *hmissing_VI_II;
TH2D *hdetect_VI_II;
TH2D *hEff_VI_II;

TH2D *hmissing_VI_III;
TH2D *hdetect_VI_III;
TH2D *hEff_VI_III;

TH2D *hmissing_VI_IV;
TH2D *hdetect_VI_IV;
TH2D *hEff_VI_IV;

TH2D *hmissing_VI_V;
TH2D *hdetect_VI_V;
TH2D *hEff_VI_V;

TH2D *hmissing_VI_VI;
TH2D *hdetect_VI_VI;
TH2D *hEff_VI_VI;

TH2D *hmissing_VI_VII;
TH2D *hdetect_VI_VII;
TH2D *hEff_VI_VII;

TH2D *hmissing_VI_VIII;
TH2D *hdetect_VI_VIII;
TH2D *hEff_VI_VIII;

TH2D *hmissing_VII_I;
TH2D *hdetect_VII_I;
TH2D *hEff_VII_I;

TH2D *hmissing_VII_II;
TH2D *hdetect_VII_II;
TH2D *hEff_VII_II;

TH2D *hmissing_VII_III;
TH2D *hdetect_VII_III;
TH2D *hEff_VII_III;

TH2D *hmissing_VII_IV;
TH2D *hdetect_VII_IV;
TH2D *hEff_VII_IV;

TH2D *hmissing_VII_V;
TH2D *hdetect_VII_V;
TH2D *hEff_VII_V;

TH2D *hmissing_VII_VI;
TH2D *hdetect_VII_VI;
TH2D *hEff_VII_VI;

TH2D *hmissing_VII_VII;
TH2D *hdetect_VII_VII;
TH2D *hEff_VII_VII;

TH2D *hmissing_VII_VIII;
TH2D *hdetect_VII_VIII;
TH2D *hEff_VII_VIII;

TH2D *hmissing_VIII_I;
TH2D *hdetect_VIII_I;
TH2D *hEff_VIII_I;

TH2D *hmissing_VIII_II;
TH2D *hdetect_VIII_II;
TH2D *hEff_VIII_II;

TH2D *hmissing_VIII_III;
TH2D *hdetect_VIII_III;
TH2D *hEff_VIII_III;

TH2D *hmissing_VIII_IV;
TH2D *hdetect_VIII_IV;
TH2D *hEff_VIII_IV;

TH2D *hmissing_VIII_V;
TH2D *hdetect_VIII_V;
TH2D *hEff_VIII_V;

TH2D *hmissing_VIII_VI;
TH2D *hdetect_VIII_VI;
TH2D *hEff_VIII_VI;

TH2D *hmissing_VIII_VII;
TH2D *hdetect_VIII_VII;
TH2D *hEff_VIII_VII;

TH2D *hmissing_VIII_VIII;
TH2D *hdetect_VIII_VIII;
TH2D *hEff_VIII_VIII;
