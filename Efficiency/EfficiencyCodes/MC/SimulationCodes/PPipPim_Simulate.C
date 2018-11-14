#include "TGraphAsymmErrors.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "TChain.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TGraphAsymmErrors.h"
#include "TFile.h"

//Jlab
#include "PParticle.h"
#include "PInclusiveModel.h"
#include "PReaction.h"
#include "PBeamSmearing.h"
#include "PAnyDistribution.h"
#include "scatter_mod/PScatterCrossSection.h"



/*
#include "/Users/Mike/Pluto/pluto_v5.42/src/PParticle.h"
#include "/Users/Mike/Pluto/pluto_v5.42/src/PInclusiveModel.h"
#include "/Users/Mike/Pluto/pluto_v5.42/src/PReaction.h"
#include "/Users/Mike/Pluto/pluto_v5.42/src/PBeamSmearing.h"
#include "/Users/Mike/Pluto/pluto_v5.42/src/PAnyDistribution.h"
#include "/Users/Mike/Pluto/pluto_v5.42/plugins/scatter_mod/PScatterCrossSection.h"
*/

void PPipPim_Simulate(int input, int events) //int input, int events

{
  gROOT->Reset();
  
  double ebeam_min = 1.075;
  double ebeam_max = 5.45;
  PBeamSmearing *beam_smear = new PBeamSmearing("beam_smear", "Beam smearing");
  TF1* beam_smear_fn = new TF1("beam_smear_fn", "(1./x)", ebeam_min, ebeam_max);
  TF1 *f1 = new TF1("f1", "(x<3.6)*(1./x) + (x>3.6)*(2./x)", ebeam_min, ebeam_max);
  //TF1* beam_smear_fn = new TF1("beam_smear_fn", "1", ebeam_min, ebeam_max);

  beam_smear->SetReaction("g + p");
  beam_smear->SetMomentumFunction(f1);
  makeDistributionManager()->Add(beam_smear);
  PUtils::SetSeed(input);

  PReaction my_reaction("_P1 = 2.2","g","p","p pi+ pi-","ppippim",1,0,0,0);
  my_reaction.Print();
  char gamp_file[75];
  sprintf(gamp_file,"%s","G12_PPipPim.gamp");

  my_reaction.Output(gamp_file,"mybeam=([g+p]->GetBeam())->E(); pippx=[pi+]->Px(); pippy=[pi+]->Py(); pippz=[pi+]->Pz();pipE=[pi+]->E();  pimpx=[pi-]->Px(); pimpy=[pi-]->Py(); pimpz=[pi-]->Pz();pimE=[pi-]->E();  ppx=[p]->Px(); ppy=[p]->Py(); ppz=[p]->Pz();pE=[p]->E(); echo 4 \n1 0 0.0 0.0 $mybeam $mybeam \n8 1 $pippx $pippy $pippz $pipE \n9 -1 $pimpx $pimpy $pimpz $pimE \n14 1 $ppx $ppy $ppz $pE");
  /*
  TH1F * histo2 = new TH1F ("histo2","IM pi+ pi-",100,0.0,2.2);
  
  TH1F * histo3 = new TH1F ("histo3","Beam",100,0.0,5.5);
  
  my_reaction.Do(histo3,"_w =1;_x = ([g+p]->GetBeam())->E();");
  my_reaction.Do(histo2,"_w =1;_x = ([pi+] +[pi-])->M() ");
  */
  my_reaction.Loop(events);
  


  /*
  TCanvas *c1 = new TCanvas("c1","c1");
  c1->cd();
  histo2->Draw();
  
  TCanvas *c2 = new TCanvas("c2","c2");
  c2->cd();
  histo3->SetLineColor(kRed);
  histo3->Draw();
*/

  
  
  
}

