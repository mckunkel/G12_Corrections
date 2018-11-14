void Compare_Pim_Efficiency_new(){
  gStyle->SetPaintTextFormat("4.2f");
  
	
  TFile Data("Efficiency_Plots_data.root");
  TFile MC("Efficiency_Plots_MC.root");
	
	
	hdata_I_I= (TH2D*)Data.Get("hEff_I_I");
  hMC_I_I= (TH2D*)MC.Get("hEff_I_I");
  hdata_I_I->SetName("hdata_I_I");
  hMC_I_I->SetName("hMC_I_I");
  TH2D *hPimEff_I_I =new TH2D("hPimEff_I_I","Efficiency at -110. < z < -105. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hPimEff_I_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_I_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_I_I->Sumw2();
  TCanvas *cZ_I_I = new TCanvas("I_I","I_I",800,800);
  cZ_I_I->cd();
  hPimEff_I_I->Divide(hMC_I_I,hdata_I_I);
  hPimEff_I_I->SetDirectory(0);
  hPimEff_I_I->Draw("colz text");
  
  
  hdata_I_II= (TH2D*)Data.Get("hEff_I_II");
  hMC_I_II= (TH2D*)MC.Get("hEff_I_II");
  hdata_I_II->SetName("hdata_I_II");
  hMC_I_II->SetName("hMC_I_II");
  TH2D *hPimEff_I_II =new TH2D("hPimEff_I_II","Efficiency at -110. < z < -105. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hPimEff_I_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_I_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_I_II->Sumw2();
  TCanvas *cZ_I_II = new TCanvas("I_II","I_II",800,800);
  cZ_I_II->cd();
  hPimEff_I_II->Divide(hMC_I_II,hdata_I_II);
  hPimEff_I_II->SetDirectory(0);
  hPimEff_I_II->Draw("colz text");
  
  
  hdata_I_III= (TH2D*)Data.Get("hEff_I_III");
  hMC_I_III= (TH2D*)MC.Get("hEff_I_III");
  hdata_I_III->SetName("hdata_I_III");
  hMC_I_III->SetName("hMC_I_III");
  TH2D *hPimEff_I_III =new TH2D("hPimEff_I_III","Efficiency at -110. < z < -105. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hPimEff_I_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_I_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_I_III->Sumw2();
  TCanvas *cZ_I_III = new TCanvas("I_III","I_III",800,800);
  cZ_I_III->cd();
  hPimEff_I_III->Divide(hMC_I_III,hdata_I_III);
  hPimEff_I_III->SetDirectory(0);
  hPimEff_I_III->Draw("colz text");
  
  
  hdata_I_IV= (TH2D*)Data.Get("hEff_I_IV");
  hMC_I_IV= (TH2D*)MC.Get("hEff_I_IV");
  hdata_I_IV->SetName("hdata_I_IV");
  hMC_I_IV->SetName("hMC_I_IV");
  TH2D *hPimEff_I_IV =new TH2D("hPimEff_I_IV","Efficiency at -110. < z < -105. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hPimEff_I_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_I_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_I_IV->Sumw2();
  TCanvas *cZ_I_IV = new TCanvas("I_IV","I_IV",800,800);
  cZ_I_IV->cd();
  hPimEff_I_IV->Divide(hMC_I_IV,hdata_I_IV);
  hPimEff_I_IV->SetDirectory(0);
  hPimEff_I_IV->Draw("colz text");
  
  
  hdata_I_V= (TH2D*)Data.Get("hEff_I_V");
  hMC_I_V= (TH2D*)MC.Get("hEff_I_V");
  hdata_I_V->SetName("hdata_I_V");
  hMC_I_V->SetName("hMC_I_V");
  TH2D *hPimEff_I_V =new TH2D("hPimEff_I_V","Efficiency at -110. < z < -105. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hPimEff_I_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_I_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_I_V->Sumw2();
  TCanvas *cZ_I_V = new TCanvas("I_V","I_V",800,800);
  cZ_I_V->cd();
  hPimEff_I_V->Divide(hMC_I_V,hdata_I_V);
  hPimEff_I_V->SetDirectory(0);
  hPimEff_I_V->Draw("colz text");
  
  
  hdata_I_VI= (TH2D*)Data.Get("hEff_I_VI");
  hMC_I_VI= (TH2D*)MC.Get("hEff_I_VI");
  hdata_I_VI->SetName("hdata_I_VI");
  hMC_I_VI->SetName("hMC_I_VI");
  TH2D *hPimEff_I_VI =new TH2D("hPimEff_I_VI","Efficiency at -110. < z < -105. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hPimEff_I_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_I_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_I_VI->Sumw2();
  TCanvas *cZ_I_VI = new TCanvas("I_VI","I_VI",800,800);
  cZ_I_VI->cd();
  hPimEff_I_VI->Divide(hMC_I_VI,hdata_I_VI);
  hPimEff_I_VI->SetDirectory(0);
  hPimEff_I_VI->Draw("colz text");
  
  
  hdata_I_VII= (TH2D*)Data.Get("hEff_I_VII");
  hMC_I_VII= (TH2D*)MC.Get("hEff_I_VII");
  hdata_I_VII->SetName("hdata_I_VII");
  hMC_I_VII->SetName("hMC_I_VII");
  TH2D *hPimEff_I_VII =new TH2D("hPimEff_I_VII","Efficiency at -110. < z < -105. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hPimEff_I_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_I_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_I_VII->Sumw2();
  TCanvas *cZ_I_VII = new TCanvas("I_VII","I_VII",800,800);
  cZ_I_VII->cd();
  hPimEff_I_VII->Divide(hMC_I_VII,hdata_I_VII);
  hPimEff_I_VII->SetDirectory(0);
  hPimEff_I_VII->Draw("colz text");
  
  
  hdata_I_VIII= (TH2D*)Data.Get("hEff_I_VIII");
  hMC_I_VIII= (TH2D*)MC.Get("hEff_I_VIII");
  hdata_I_VIII->SetName("hdata_I_VIII");
  hMC_I_VIII->SetName("hMC_I_VIII");
  TH2D *hPimEff_I_VIII =new TH2D("hPimEff_I_VIII","Efficiency at -110. < z < -105. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hPimEff_I_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_I_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_I_VIII->Sumw2();
  TCanvas *cZ_I_VIII = new TCanvas("I_VIII","I_VIII",800,800);
  cZ_I_VIII->cd();
  hPimEff_I_VIII->Divide(hMC_I_VIII,hdata_I_VIII);
  hPimEff_I_VIII->SetDirectory(0);
  hPimEff_I_VIII->Draw("colz text");
  
  
  hdata_II_I= (TH2D*)Data.Get("hEff_II_I");
  hMC_II_I= (TH2D*)MC.Get("hEff_II_I");
  hdata_II_I->SetName("hdata_II_I");
  hMC_II_I->SetName("hMC_II_I");
  TH2D *hPimEff_II_I =new TH2D("hPimEff_II_I","Efficiency at -105. < z < -100. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hPimEff_II_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_II_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_II_I->Sumw2();
  TCanvas *cZ_II_I = new TCanvas("II_I","II_I",800,800);
  cZ_II_I->cd();
  hPimEff_II_I->Divide(hMC_II_I,hdata_II_I);
  hPimEff_II_I->SetDirectory(0);
  hPimEff_II_I->Draw("colz text");
  
  
  hdata_II_II= (TH2D*)Data.Get("hEff_II_II");
  hMC_II_II= (TH2D*)MC.Get("hEff_II_II");
  hdata_II_II->SetName("hdata_II_II");
  hMC_II_II->SetName("hMC_II_II");
  TH2D *hPimEff_II_II =new TH2D("hPimEff_II_II","Efficiency at -105. < z < -100. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hPimEff_II_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_II_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_II_II->Sumw2();
  TCanvas *cZ_II_II = new TCanvas("II_II","II_II",800,800);
  cZ_II_II->cd();
  hPimEff_II_II->Divide(hMC_II_II,hdata_II_II);
  hPimEff_II_II->SetDirectory(0);
  hPimEff_II_II->Draw("colz text");
  
  
  hdata_II_III= (TH2D*)Data.Get("hEff_II_III");
  hMC_II_III= (TH2D*)MC.Get("hEff_II_III");
  hdata_II_III->SetName("hdata_II_III");
  hMC_II_III->SetName("hMC_II_III");
  TH2D *hPimEff_II_III =new TH2D("hPimEff_II_III","Efficiency at -105. < z < -100. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hPimEff_II_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_II_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_II_III->Sumw2();
  TCanvas *cZ_II_III = new TCanvas("II_III","II_III",800,800);
  cZ_II_III->cd();
  hPimEff_II_III->Divide(hMC_II_III,hdata_II_III);
  hPimEff_II_III->SetDirectory(0);
  hPimEff_II_III->Draw("colz text");
  
  
  hdata_II_IV= (TH2D*)Data.Get("hEff_II_IV");
  hMC_II_IV= (TH2D*)MC.Get("hEff_II_IV");
  hdata_II_IV->SetName("hdata_II_IV");
  hMC_II_IV->SetName("hMC_II_IV");
  TH2D *hPimEff_II_IV =new TH2D("hPimEff_II_IV","Efficiency at -105. < z < -100. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hPimEff_II_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_II_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_II_IV->Sumw2();
  TCanvas *cZ_II_IV = new TCanvas("II_IV","II_IV",800,800);
  cZ_II_IV->cd();
  hPimEff_II_IV->Divide(hMC_II_IV,hdata_II_IV);
  hPimEff_II_IV->SetDirectory(0);
  hPimEff_II_IV->Draw("colz text");
  
  
  hdata_II_V= (TH2D*)Data.Get("hEff_II_V");
  hMC_II_V= (TH2D*)MC.Get("hEff_II_V");
  hdata_II_V->SetName("hdata_II_V");
  hMC_II_V->SetName("hMC_II_V");
  TH2D *hPimEff_II_V =new TH2D("hPimEff_II_V","Efficiency at -105. < z < -100. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hPimEff_II_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_II_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_II_V->Sumw2();
  TCanvas *cZ_II_V = new TCanvas("II_V","II_V",800,800);
  cZ_II_V->cd();
  hPimEff_II_V->Divide(hMC_II_V,hdata_II_V);
  hPimEff_II_V->SetDirectory(0);
  hPimEff_II_V->Draw("colz text");
  
  
  hdata_II_VI= (TH2D*)Data.Get("hEff_II_VI");
  hMC_II_VI= (TH2D*)MC.Get("hEff_II_VI");
  hdata_II_VI->SetName("hdata_II_VI");
  hMC_II_VI->SetName("hMC_II_VI");
  TH2D *hPimEff_II_VI =new TH2D("hPimEff_II_VI","Efficiency at -105. < z < -100. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hPimEff_II_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_II_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_II_VI->Sumw2();
  TCanvas *cZ_II_VI = new TCanvas("II_VI","II_VI",800,800);
  cZ_II_VI->cd();
  hPimEff_II_VI->Divide(hMC_II_VI,hdata_II_VI);
  hPimEff_II_VI->SetDirectory(0);
  hPimEff_II_VI->Draw("colz text");
  
  
  hdata_II_VII= (TH2D*)Data.Get("hEff_II_VII");
  hMC_II_VII= (TH2D*)MC.Get("hEff_II_VII");
  hdata_II_VII->SetName("hdata_II_VII");
  hMC_II_VII->SetName("hMC_II_VII");
  TH2D *hPimEff_II_VII =new TH2D("hPimEff_II_VII","Efficiency at -105. < z < -100. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hPimEff_II_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_II_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_II_VII->Sumw2();
  TCanvas *cZ_II_VII = new TCanvas("II_VII","II_VII",800,800);
  cZ_II_VII->cd();
  hPimEff_II_VII->Divide(hMC_II_VII,hdata_II_VII);
  hPimEff_II_VII->SetDirectory(0);
  hPimEff_II_VII->Draw("colz text");
  
  
  hdata_II_VIII= (TH2D*)Data.Get("hEff_II_VIII");
  hMC_II_VIII= (TH2D*)MC.Get("hEff_II_VIII");
  hdata_II_VIII->SetName("hdata_II_VIII");
  hMC_II_VIII->SetName("hMC_II_VIII");
  TH2D *hPimEff_II_VIII =new TH2D("hPimEff_II_VIII","Efficiency at -105. < z < -100. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hPimEff_II_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_II_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_II_VIII->Sumw2();
  TCanvas *cZ_II_VIII = new TCanvas("II_VIII","II_VIII",800,800);
  cZ_II_VIII->cd();
  hPimEff_II_VIII->Divide(hMC_II_VIII,hdata_II_VIII);
  hPimEff_II_VIII->SetDirectory(0);
  hPimEff_II_VIII->Draw("colz text");
  
  
  hdata_III_I= (TH2D*)Data.Get("hEff_III_I");
  hMC_III_I= (TH2D*)MC.Get("hEff_III_I");
  hdata_III_I->SetName("hdata_III_I");
  hMC_III_I->SetName("hMC_III_I");
  TH2D *hPimEff_III_I =new TH2D("hPimEff_III_I","Efficiency at -100. < z < -95. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hPimEff_III_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_III_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_III_I->Sumw2();
  TCanvas *cZ_III_I = new TCanvas("III_I","III_I",800,800);
  cZ_III_I->cd();
  hPimEff_III_I->Divide(hMC_III_I,hdata_III_I);
  hPimEff_III_I->SetDirectory(0);
  hPimEff_III_I->Draw("colz text");
  
  
  hdata_III_II= (TH2D*)Data.Get("hEff_III_II");
  hMC_III_II= (TH2D*)MC.Get("hEff_III_II");
  hdata_III_II->SetName("hdata_III_II");
  hMC_III_II->SetName("hMC_III_II");
  TH2D *hPimEff_III_II =new TH2D("hPimEff_III_II","Efficiency at -100. < z < -95. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hPimEff_III_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_III_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_III_II->Sumw2();
  TCanvas *cZ_III_II = new TCanvas("III_II","III_II",800,800);
  cZ_III_II->cd();
  hPimEff_III_II->Divide(hMC_III_II,hdata_III_II);
  hPimEff_III_II->SetDirectory(0);
  hPimEff_III_II->Draw("colz text");
  
  
  hdata_III_III= (TH2D*)Data.Get("hEff_III_III");
  hMC_III_III= (TH2D*)MC.Get("hEff_III_III");
  hdata_III_III->SetName("hdata_III_III");
  hMC_III_III->SetName("hMC_III_III");
  TH2D *hPimEff_III_III =new TH2D("hPimEff_III_III","Efficiency at -100. < z < -95. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hPimEff_III_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_III_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_III_III->Sumw2();
  TCanvas *cZ_III_III = new TCanvas("III_III","III_III",800,800);
  cZ_III_III->cd();
  hPimEff_III_III->Divide(hMC_III_III,hdata_III_III);
  hPimEff_III_III->SetDirectory(0);
  hPimEff_III_III->Draw("colz text");
  
  
  hdata_III_IV= (TH2D*)Data.Get("hEff_III_IV");
  hMC_III_IV= (TH2D*)MC.Get("hEff_III_IV");
  hdata_III_IV->SetName("hdata_III_IV");
  hMC_III_IV->SetName("hMC_III_IV");
  TH2D *hPimEff_III_IV =new TH2D("hPimEff_III_IV","Efficiency at -100. < z < -95. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hPimEff_III_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_III_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_III_IV->Sumw2();
  TCanvas *cZ_III_IV = new TCanvas("III_IV","III_IV",800,800);
  cZ_III_IV->cd();
  hPimEff_III_IV->Divide(hMC_III_IV,hdata_III_IV);
  hPimEff_III_IV->SetDirectory(0);
  hPimEff_III_IV->Draw("colz text");
  
  
  hdata_III_V= (TH2D*)Data.Get("hEff_III_V");
  hMC_III_V= (TH2D*)MC.Get("hEff_III_V");
  hdata_III_V->SetName("hdata_III_V");
  hMC_III_V->SetName("hMC_III_V");
  TH2D *hPimEff_III_V =new TH2D("hPimEff_III_V","Efficiency at -100. < z < -95. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hPimEff_III_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_III_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_III_V->Sumw2();
  TCanvas *cZ_III_V = new TCanvas("III_V","III_V",800,800);
  cZ_III_V->cd();
  hPimEff_III_V->Divide(hMC_III_V,hdata_III_V);
  hPimEff_III_V->SetDirectory(0);
  hPimEff_III_V->Draw("colz text");
  
  
  hdata_III_VI= (TH2D*)Data.Get("hEff_III_VI");
  hMC_III_VI= (TH2D*)MC.Get("hEff_III_VI");
  hdata_III_VI->SetName("hdata_III_VI");
  hMC_III_VI->SetName("hMC_III_VI");
  TH2D *hPimEff_III_VI =new TH2D("hPimEff_III_VI","Efficiency at -100. < z < -95. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hPimEff_III_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_III_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_III_VI->Sumw2();
  TCanvas *cZ_III_VI = new TCanvas("III_VI","III_VI",800,800);
  cZ_III_VI->cd();
  hPimEff_III_VI->Divide(hMC_III_VI,hdata_III_VI);
  hPimEff_III_VI->SetDirectory(0);
  hPimEff_III_VI->Draw("colz text");
  
  
  hdata_III_VII= (TH2D*)Data.Get("hEff_III_VII");
  hMC_III_VII= (TH2D*)MC.Get("hEff_III_VII");
  hdata_III_VII->SetName("hdata_III_VII");
  hMC_III_VII->SetName("hMC_III_VII");
  TH2D *hPimEff_III_VII =new TH2D("hPimEff_III_VII","Efficiency at -100. < z < -95. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hPimEff_III_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_III_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_III_VII->Sumw2();
  TCanvas *cZ_III_VII = new TCanvas("III_VII","III_VII",800,800);
  cZ_III_VII->cd();
  hPimEff_III_VII->Divide(hMC_III_VII,hdata_III_VII);
  hPimEff_III_VII->SetDirectory(0);
  hPimEff_III_VII->Draw("colz text");
  
  
  hdata_III_VIII= (TH2D*)Data.Get("hEff_III_VIII");
  hMC_III_VIII= (TH2D*)MC.Get("hEff_III_VIII");
  hdata_III_VIII->SetName("hdata_III_VIII");
  hMC_III_VIII->SetName("hMC_III_VIII");
  TH2D *hPimEff_III_VIII =new TH2D("hPimEff_III_VIII","Efficiency at -100. < z < -95. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hPimEff_III_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_III_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_III_VIII->Sumw2();
  TCanvas *cZ_III_VIII = new TCanvas("III_VIII","III_VIII",800,800);
  cZ_III_VIII->cd();
  hPimEff_III_VIII->Divide(hMC_III_VIII,hdata_III_VIII);
  hPimEff_III_VIII->SetDirectory(0);
  hPimEff_III_VIII->Draw("colz text");
  
  
  hdata_IV_I= (TH2D*)Data.Get("hEff_IV_I");
  hMC_IV_I= (TH2D*)MC.Get("hEff_IV_I");
  hdata_IV_I->SetName("hdata_IV_I");
  hMC_IV_I->SetName("hMC_IV_I");
  TH2D *hPimEff_IV_I =new TH2D("hPimEff_IV_I","Efficiency at -95. < z < -90. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hPimEff_IV_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_IV_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_IV_I->Sumw2();
  TCanvas *cZ_IV_I = new TCanvas("IV_I","IV_I",800,800);
  cZ_IV_I->cd();
  hPimEff_IV_I->Divide(hMC_IV_I,hdata_IV_I);
  hPimEff_IV_I->SetDirectory(0);
  hPimEff_IV_I->Draw("colz text");
  
  
  hdata_IV_II= (TH2D*)Data.Get("hEff_IV_II");
  hMC_IV_II= (TH2D*)MC.Get("hEff_IV_II");
  hdata_IV_II->SetName("hdata_IV_II");
  hMC_IV_II->SetName("hMC_IV_II");
  TH2D *hPimEff_IV_II =new TH2D("hPimEff_IV_II","Efficiency at -95. < z < -90. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hPimEff_IV_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_IV_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_IV_II->Sumw2();
  TCanvas *cZ_IV_II = new TCanvas("IV_II","IV_II",800,800);
  cZ_IV_II->cd();
  hPimEff_IV_II->Divide(hMC_IV_II,hdata_IV_II);
  hPimEff_IV_II->SetDirectory(0);
  hPimEff_IV_II->Draw("colz text");
  
  
  hdata_IV_III= (TH2D*)Data.Get("hEff_IV_III");
  hMC_IV_III= (TH2D*)MC.Get("hEff_IV_III");
  hdata_IV_III->SetName("hdata_IV_III");
  hMC_IV_III->SetName("hMC_IV_III");
  TH2D *hPimEff_IV_III =new TH2D("hPimEff_IV_III","Efficiency at -95. < z < -90. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hPimEff_IV_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_IV_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_IV_III->Sumw2();
  TCanvas *cZ_IV_III = new TCanvas("IV_III","IV_III",800,800);
  cZ_IV_III->cd();
  hPimEff_IV_III->Divide(hMC_IV_III,hdata_IV_III);
  hPimEff_IV_III->SetDirectory(0);
  hPimEff_IV_III->Draw("colz text");
  
  
  hdata_IV_IV= (TH2D*)Data.Get("hEff_IV_IV");
  hMC_IV_IV= (TH2D*)MC.Get("hEff_IV_IV");
  hdata_IV_IV->SetName("hdata_IV_IV");
  hMC_IV_IV->SetName("hMC_IV_IV");
  TH2D *hPimEff_IV_IV =new TH2D("hPimEff_IV_IV","Efficiency at -95. < z < -90. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hPimEff_IV_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_IV_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_IV_IV->Sumw2();
  TCanvas *cZ_IV_IV = new TCanvas("IV_IV","IV_IV",800,800);
  cZ_IV_IV->cd();
  hPimEff_IV_IV->Divide(hMC_IV_IV,hdata_IV_IV);
  hPimEff_IV_IV->SetDirectory(0);
  hPimEff_IV_IV->Draw("colz text");
  
  
  hdata_IV_V= (TH2D*)Data.Get("hEff_IV_V");
  hMC_IV_V= (TH2D*)MC.Get("hEff_IV_V");
  hdata_IV_V->SetName("hdata_IV_V");
  hMC_IV_V->SetName("hMC_IV_V");
  TH2D *hPimEff_IV_V =new TH2D("hPimEff_IV_V","Efficiency at -95. < z < -90. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hPimEff_IV_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_IV_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_IV_V->Sumw2();
  TCanvas *cZ_IV_V = new TCanvas("IV_V","IV_V",800,800);
  cZ_IV_V->cd();
  hPimEff_IV_V->Divide(hMC_IV_V,hdata_IV_V);
  hPimEff_IV_V->SetDirectory(0);
  hPimEff_IV_V->Draw("colz text");
  
  
  hdata_IV_VI= (TH2D*)Data.Get("hEff_IV_VI");
  hMC_IV_VI= (TH2D*)MC.Get("hEff_IV_VI");
  hdata_IV_VI->SetName("hdata_IV_VI");
  hMC_IV_VI->SetName("hMC_IV_VI");
  TH2D *hPimEff_IV_VI =new TH2D("hPimEff_IV_VI","Efficiency at -95. < z < -90. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hPimEff_IV_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_IV_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_IV_VI->Sumw2();
  TCanvas *cZ_IV_VI = new TCanvas("IV_VI","IV_VI",800,800);
  cZ_IV_VI->cd();
  hPimEff_IV_VI->Divide(hMC_IV_VI,hdata_IV_VI);
  hPimEff_IV_VI->SetDirectory(0);
  hPimEff_IV_VI->Draw("colz text");
  
  
  hdata_IV_VII= (TH2D*)Data.Get("hEff_IV_VII");
  hMC_IV_VII= (TH2D*)MC.Get("hEff_IV_VII");
  hdata_IV_VII->SetName("hdata_IV_VII");
  hMC_IV_VII->SetName("hMC_IV_VII");
  TH2D *hPimEff_IV_VII =new TH2D("hPimEff_IV_VII","Efficiency at -95. < z < -90. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hPimEff_IV_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_IV_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_IV_VII->Sumw2();
  TCanvas *cZ_IV_VII = new TCanvas("IV_VII","IV_VII",800,800);
  cZ_IV_VII->cd();
  hPimEff_IV_VII->Divide(hMC_IV_VII,hdata_IV_VII);
  hPimEff_IV_VII->SetDirectory(0);
  hPimEff_IV_VII->Draw("colz text");
  
  
  hdata_IV_VIII= (TH2D*)Data.Get("hEff_IV_VIII");
  hMC_IV_VIII= (TH2D*)MC.Get("hEff_IV_VIII");
  hdata_IV_VIII->SetName("hdata_IV_VIII");
  hMC_IV_VIII->SetName("hMC_IV_VIII");
  TH2D *hPimEff_IV_VIII =new TH2D("hPimEff_IV_VIII","Efficiency at -95. < z < -90. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hPimEff_IV_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_IV_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_IV_VIII->Sumw2();
  TCanvas *cZ_IV_VIII = new TCanvas("IV_VIII","IV_VIII",800,800);
  cZ_IV_VIII->cd();
  hPimEff_IV_VIII->Divide(hMC_IV_VIII,hdata_IV_VIII);
  hPimEff_IV_VIII->SetDirectory(0);
  hPimEff_IV_VIII->Draw("colz text");
  
  
  hdata_V_I= (TH2D*)Data.Get("hEff_V_I");
  hMC_V_I= (TH2D*)MC.Get("hEff_V_I");
  hdata_V_I->SetName("hdata_V_I");
  hMC_V_I->SetName("hMC_V_I");
  TH2D *hPimEff_V_I =new TH2D("hPimEff_V_I","Efficiency at -90. < z < -85. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hPimEff_V_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_V_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_V_I->Sumw2();
  TCanvas *cZ_V_I = new TCanvas("V_I","V_I",800,800);
  cZ_V_I->cd();
  hPimEff_V_I->Divide(hMC_V_I,hdata_V_I);
  hPimEff_V_I->SetDirectory(0);
  hPimEff_V_I->Draw("colz text");
  
  
  hdata_V_II= (TH2D*)Data.Get("hEff_V_II");
  hMC_V_II= (TH2D*)MC.Get("hEff_V_II");
  hdata_V_II->SetName("hdata_V_II");
  hMC_V_II->SetName("hMC_V_II");
  TH2D *hPimEff_V_II =new TH2D("hPimEff_V_II","Efficiency at -90. < z < -85. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hPimEff_V_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_V_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_V_II->Sumw2();
  TCanvas *cZ_V_II = new TCanvas("V_II","V_II",800,800);
  cZ_V_II->cd();
  hPimEff_V_II->Divide(hMC_V_II,hdata_V_II);
  hPimEff_V_II->SetDirectory(0);
  hPimEff_V_II->Draw("colz text");
  
  
  hdata_V_III= (TH2D*)Data.Get("hEff_V_III");
  hMC_V_III= (TH2D*)MC.Get("hEff_V_III");
  hdata_V_III->SetName("hdata_V_III");
  hMC_V_III->SetName("hMC_V_III");
  TH2D *hPimEff_V_III =new TH2D("hPimEff_V_III","Efficiency at -90. < z < -85. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hPimEff_V_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_V_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_V_III->Sumw2();
  TCanvas *cZ_V_III = new TCanvas("V_III","V_III",800,800);
  cZ_V_III->cd();
  hPimEff_V_III->Divide(hMC_V_III,hdata_V_III);
  hPimEff_V_III->SetDirectory(0);
  hPimEff_V_III->Draw("colz text");
  
  
  hdata_V_IV= (TH2D*)Data.Get("hEff_V_IV");
  hMC_V_IV= (TH2D*)MC.Get("hEff_V_IV");
  hdata_V_IV->SetName("hdata_V_IV");
  hMC_V_IV->SetName("hMC_V_IV");
  TH2D *hPimEff_V_IV =new TH2D("hPimEff_V_IV","Efficiency at -90. < z < -85. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hPimEff_V_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_V_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_V_IV->Sumw2();
  TCanvas *cZ_V_IV = new TCanvas("V_IV","V_IV",800,800);
  cZ_V_IV->cd();
  hPimEff_V_IV->Divide(hMC_V_IV,hdata_V_IV);
  hPimEff_V_IV->SetDirectory(0);
  hPimEff_V_IV->Draw("colz text");
  
  
  hdata_V_V= (TH2D*)Data.Get("hEff_V_V");
  hMC_V_V= (TH2D*)MC.Get("hEff_V_V");
  hdata_V_V->SetName("hdata_V_V");
  hMC_V_V->SetName("hMC_V_V");
  TH2D *hPimEff_V_V =new TH2D("hPimEff_V_V","Efficiency at -90. < z < -85. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hPimEff_V_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_V_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_V_V->Sumw2();
  TCanvas *cZ_V_V = new TCanvas("V_V","V_V",800,800);
  cZ_V_V->cd();
  hPimEff_V_V->Divide(hMC_V_V,hdata_V_V);
  hPimEff_V_V->SetDirectory(0);
  hPimEff_V_V->Draw("colz text");
  
  
  hdata_V_VI= (TH2D*)Data.Get("hEff_V_VI");
  hMC_V_VI= (TH2D*)MC.Get("hEff_V_VI");
  hdata_V_VI->SetName("hdata_V_VI");
  hMC_V_VI->SetName("hMC_V_VI");
  TH2D *hPimEff_V_VI =new TH2D("hPimEff_V_VI","Efficiency at -90. < z < -85. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hPimEff_V_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_V_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_V_VI->Sumw2();
  TCanvas *cZ_V_VI = new TCanvas("V_VI","V_VI",800,800);
  cZ_V_VI->cd();
  hPimEff_V_VI->Divide(hMC_V_VI,hdata_V_VI);
  hPimEff_V_VI->SetDirectory(0);
  hPimEff_V_VI->Draw("colz text");
  
  
  hdata_V_VII= (TH2D*)Data.Get("hEff_V_VII");
  hMC_V_VII= (TH2D*)MC.Get("hEff_V_VII");
  hdata_V_VII->SetName("hdata_V_VII");
  hMC_V_VII->SetName("hMC_V_VII");
  TH2D *hPimEff_V_VII =new TH2D("hPimEff_V_VII","Efficiency at -90. < z < -85. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hPimEff_V_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_V_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_V_VII->Sumw2();
  TCanvas *cZ_V_VII = new TCanvas("V_VII","V_VII",800,800);
  cZ_V_VII->cd();
  hPimEff_V_VII->Divide(hMC_V_VII,hdata_V_VII);
  hPimEff_V_VII->SetDirectory(0);
  hPimEff_V_VII->Draw("colz text");
  
  
  hdata_V_VIII= (TH2D*)Data.Get("hEff_V_VIII");
  hMC_V_VIII= (TH2D*)MC.Get("hEff_V_VIII");
  hdata_V_VIII->SetName("hdata_V_VIII");
  hMC_V_VIII->SetName("hMC_V_VIII");
  TH2D *hPimEff_V_VIII =new TH2D("hPimEff_V_VIII","Efficiency at -90. < z < -85. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hPimEff_V_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_V_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_V_VIII->Sumw2();
  TCanvas *cZ_V_VIII = new TCanvas("V_VIII","V_VIII",800,800);
  cZ_V_VIII->cd();
  hPimEff_V_VIII->Divide(hMC_V_VIII,hdata_V_VIII);
  hPimEff_V_VIII->SetDirectory(0);
  hPimEff_V_VIII->Draw("colz text");
  
  
  hdata_VI_I= (TH2D*)Data.Get("hEff_VI_I");
  hMC_VI_I= (TH2D*)MC.Get("hEff_VI_I");
  hdata_VI_I->SetName("hdata_VI_I");
  hMC_VI_I->SetName("hMC_VI_I");
  TH2D *hPimEff_VI_I =new TH2D("hPimEff_VI_I","Efficiency at -85. < z < -80. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hPimEff_VI_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_VI_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_VI_I->Sumw2();
  TCanvas *cZ_VI_I = new TCanvas("VI_I","VI_I",800,800);
  cZ_VI_I->cd();
  hPimEff_VI_I->Divide(hMC_VI_I,hdata_VI_I);
  hPimEff_VI_I->SetDirectory(0);
  hPimEff_VI_I->Draw("colz text");
  
  
  hdata_VI_II= (TH2D*)Data.Get("hEff_VI_II");
  hMC_VI_II= (TH2D*)MC.Get("hEff_VI_II");
  hdata_VI_II->SetName("hdata_VI_II");
  hMC_VI_II->SetName("hMC_VI_II");
  TH2D *hPimEff_VI_II =new TH2D("hPimEff_VI_II","Efficiency at -85. < z < -80. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hPimEff_VI_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_VI_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_VI_II->Sumw2();
  TCanvas *cZ_VI_II = new TCanvas("VI_II","VI_II",800,800);
  cZ_VI_II->cd();
  hPimEff_VI_II->Divide(hMC_VI_II,hdata_VI_II);
  hPimEff_VI_II->SetDirectory(0);
  hPimEff_VI_II->Draw("colz text");
  
  
  hdata_VI_III= (TH2D*)Data.Get("hEff_VI_III");
  hMC_VI_III= (TH2D*)MC.Get("hEff_VI_III");
  hdata_VI_III->SetName("hdata_VI_III");
  hMC_VI_III->SetName("hMC_VI_III");
  TH2D *hPimEff_VI_III =new TH2D("hPimEff_VI_III","Efficiency at -85. < z < -80. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hPimEff_VI_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_VI_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_VI_III->Sumw2();
  TCanvas *cZ_VI_III = new TCanvas("VI_III","VI_III",800,800);
  cZ_VI_III->cd();
  hPimEff_VI_III->Divide(hMC_VI_III,hdata_VI_III);
  hPimEff_VI_III->SetDirectory(0);
  hPimEff_VI_III->Draw("colz text");
  
  
  hdata_VI_IV= (TH2D*)Data.Get("hEff_VI_IV");
  hMC_VI_IV= (TH2D*)MC.Get("hEff_VI_IV");
  hdata_VI_IV->SetName("hdata_VI_IV");
  hMC_VI_IV->SetName("hMC_VI_IV");
  TH2D *hPimEff_VI_IV =new TH2D("hPimEff_VI_IV","Efficiency at -85. < z < -80. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hPimEff_VI_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_VI_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_VI_IV->Sumw2();
  TCanvas *cZ_VI_IV = new TCanvas("VI_IV","VI_IV",800,800);
  cZ_VI_IV->cd();
  hPimEff_VI_IV->Divide(hMC_VI_IV,hdata_VI_IV);
  hPimEff_VI_IV->SetDirectory(0);
  hPimEff_VI_IV->Draw("colz text");
  
  
  hdata_VI_V= (TH2D*)Data.Get("hEff_VI_V");
  hMC_VI_V= (TH2D*)MC.Get("hEff_VI_V");
  hdata_VI_V->SetName("hdata_VI_V");
  hMC_VI_V->SetName("hMC_VI_V");
  TH2D *hPimEff_VI_V =new TH2D("hPimEff_VI_V","Efficiency at -85. < z < -80. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hPimEff_VI_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_VI_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_VI_V->Sumw2();
  TCanvas *cZ_VI_V = new TCanvas("VI_V","VI_V",800,800);
  cZ_VI_V->cd();
  hPimEff_VI_V->Divide(hMC_VI_V,hdata_VI_V);
  hPimEff_VI_V->SetDirectory(0);
  hPimEff_VI_V->Draw("colz text");
  
  
  hdata_VI_VI= (TH2D*)Data.Get("hEff_VI_VI");
  hMC_VI_VI= (TH2D*)MC.Get("hEff_VI_VI");
  hdata_VI_VI->SetName("hdata_VI_VI");
  hMC_VI_VI->SetName("hMC_VI_VI");
  TH2D *hPimEff_VI_VI =new TH2D("hPimEff_VI_VI","Efficiency at -85. < z < -80. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hPimEff_VI_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_VI_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_VI_VI->Sumw2();
  TCanvas *cZ_VI_VI = new TCanvas("VI_VI","VI_VI",800,800);
  cZ_VI_VI->cd();
  hPimEff_VI_VI->Divide(hMC_VI_VI,hdata_VI_VI);
  hPimEff_VI_VI->SetDirectory(0);
  hPimEff_VI_VI->Draw("colz text");
  
  
  hdata_VI_VII= (TH2D*)Data.Get("hEff_VI_VII");
  hMC_VI_VII= (TH2D*)MC.Get("hEff_VI_VII");
  hdata_VI_VII->SetName("hdata_VI_VII");
  hMC_VI_VII->SetName("hMC_VI_VII");
  TH2D *hPimEff_VI_VII =new TH2D("hPimEff_VI_VII","Efficiency at -85. < z < -80. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hPimEff_VI_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_VI_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_VI_VII->Sumw2();
  TCanvas *cZ_VI_VII = new TCanvas("VI_VII","VI_VII",800,800);
  cZ_VI_VII->cd();
  hPimEff_VI_VII->Divide(hMC_VI_VII,hdata_VI_VII);
  hPimEff_VI_VII->SetDirectory(0);
  hPimEff_VI_VII->Draw("colz text");
  
  
  hdata_VI_VIII= (TH2D*)Data.Get("hEff_VI_VIII");
  hMC_VI_VIII= (TH2D*)MC.Get("hEff_VI_VIII");
  hdata_VI_VIII->SetName("hdata_VI_VIII");
  hMC_VI_VIII->SetName("hMC_VI_VIII");
  TH2D *hPimEff_VI_VIII =new TH2D("hPimEff_VI_VIII","Efficiency at -85. < z < -80. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hPimEff_VI_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_VI_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_VI_VIII->Sumw2();
  TCanvas *cZ_VI_VIII = new TCanvas("VI_VIII","VI_VIII",800,800);
  cZ_VI_VIII->cd();
  hPimEff_VI_VIII->Divide(hMC_VI_VIII,hdata_VI_VIII);
  hPimEff_VI_VIII->SetDirectory(0);
  hPimEff_VI_VIII->Draw("colz text");
  
  
  hdata_VII_I= (TH2D*)Data.Get("hEff_VII_I");
  hMC_VII_I= (TH2D*)MC.Get("hEff_VII_I");
  hdata_VII_I->SetName("hdata_VII_I");
  hMC_VII_I->SetName("hMC_VII_I");
  TH2D *hPimEff_VII_I =new TH2D("hPimEff_VII_I","Efficiency at -80. < z < -75. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hPimEff_VII_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_VII_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_VII_I->Sumw2();
  TCanvas *cZ_VII_I = new TCanvas("VII_I","VII_I",800,800);
  cZ_VII_I->cd();
  hPimEff_VII_I->Divide(hMC_VII_I,hdata_VII_I);
  hPimEff_VII_I->SetDirectory(0);
  hPimEff_VII_I->Draw("colz text");
  
  
  hdata_VII_II= (TH2D*)Data.Get("hEff_VII_II");
  hMC_VII_II= (TH2D*)MC.Get("hEff_VII_II");
  hdata_VII_II->SetName("hdata_VII_II");
  hMC_VII_II->SetName("hMC_VII_II");
  TH2D *hPimEff_VII_II =new TH2D("hPimEff_VII_II","Efficiency at -80. < z < -75. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hPimEff_VII_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_VII_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_VII_II->Sumw2();
  TCanvas *cZ_VII_II = new TCanvas("VII_II","VII_II",800,800);
  cZ_VII_II->cd();
  hPimEff_VII_II->Divide(hMC_VII_II,hdata_VII_II);
  hPimEff_VII_II->SetDirectory(0);
  hPimEff_VII_II->Draw("colz text");
  
  
  hdata_VII_III= (TH2D*)Data.Get("hEff_VII_III");
  hMC_VII_III= (TH2D*)MC.Get("hEff_VII_III");
  hdata_VII_III->SetName("hdata_VII_III");
  hMC_VII_III->SetName("hMC_VII_III");
  TH2D *hPimEff_VII_III =new TH2D("hPimEff_VII_III","Efficiency at -80. < z < -75. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hPimEff_VII_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_VII_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_VII_III->Sumw2();
  TCanvas *cZ_VII_III = new TCanvas("VII_III","VII_III",800,800);
  cZ_VII_III->cd();
  hPimEff_VII_III->Divide(hMC_VII_III,hdata_VII_III);
  hPimEff_VII_III->SetDirectory(0);
  hPimEff_VII_III->Draw("colz text");
  
  
  hdata_VII_IV= (TH2D*)Data.Get("hEff_VII_IV");
  hMC_VII_IV= (TH2D*)MC.Get("hEff_VII_IV");
  hdata_VII_IV->SetName("hdata_VII_IV");
  hMC_VII_IV->SetName("hMC_VII_IV");
  TH2D *hPimEff_VII_IV =new TH2D("hPimEff_VII_IV","Efficiency at -80. < z < -75. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hPimEff_VII_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_VII_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_VII_IV->Sumw2();
  TCanvas *cZ_VII_IV = new TCanvas("VII_IV","VII_IV",800,800);
  cZ_VII_IV->cd();
  hPimEff_VII_IV->Divide(hMC_VII_IV,hdata_VII_IV);
  hPimEff_VII_IV->SetDirectory(0);
  hPimEff_VII_IV->Draw("colz text");
  
  
  hdata_VII_V= (TH2D*)Data.Get("hEff_VII_V");
  hMC_VII_V= (TH2D*)MC.Get("hEff_VII_V");
  hdata_VII_V->SetName("hdata_VII_V");
  hMC_VII_V->SetName("hMC_VII_V");
  TH2D *hPimEff_VII_V =new TH2D("hPimEff_VII_V","Efficiency at -80. < z < -75. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hPimEff_VII_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_VII_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_VII_V->Sumw2();
  TCanvas *cZ_VII_V = new TCanvas("VII_V","VII_V",800,800);
  cZ_VII_V->cd();
  hPimEff_VII_V->Divide(hMC_VII_V,hdata_VII_V);
  hPimEff_VII_V->SetDirectory(0);
  hPimEff_VII_V->Draw("colz text");
  
  
  hdata_VII_VI= (TH2D*)Data.Get("hEff_VII_VI");
  hMC_VII_VI= (TH2D*)MC.Get("hEff_VII_VI");
  hdata_VII_VI->SetName("hdata_VII_VI");
  hMC_VII_VI->SetName("hMC_VII_VI");
  TH2D *hPimEff_VII_VI =new TH2D("hPimEff_VII_VI","Efficiency at -80. < z < -75. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hPimEff_VII_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_VII_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_VII_VI->Sumw2();
  TCanvas *cZ_VII_VI = new TCanvas("VII_VI","VII_VI",800,800);
  cZ_VII_VI->cd();
  hPimEff_VII_VI->Divide(hMC_VII_VI,hdata_VII_VI);
  hPimEff_VII_VI->SetDirectory(0);
  hPimEff_VII_VI->Draw("colz text");
  
  
  hdata_VII_VII= (TH2D*)Data.Get("hEff_VII_VII");
  hMC_VII_VII= (TH2D*)MC.Get("hEff_VII_VII");
  hdata_VII_VII->SetName("hdata_VII_VII");
  hMC_VII_VII->SetName("hMC_VII_VII");
  TH2D *hPimEff_VII_VII =new TH2D("hPimEff_VII_VII","Efficiency at -80. < z < -75. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hPimEff_VII_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_VII_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_VII_VII->Sumw2();
  TCanvas *cZ_VII_VII = new TCanvas("VII_VII","VII_VII",800,800);
  cZ_VII_VII->cd();
  hPimEff_VII_VII->Divide(hMC_VII_VII,hdata_VII_VII);
  hPimEff_VII_VII->SetDirectory(0);
  hPimEff_VII_VII->Draw("colz text");
  
  
  hdata_VII_VIII= (TH2D*)Data.Get("hEff_VII_VIII");
  hMC_VII_VIII= (TH2D*)MC.Get("hEff_VII_VIII");
  hdata_VII_VIII->SetName("hdata_VII_VIII");
  hMC_VII_VIII->SetName("hMC_VII_VIII");
  TH2D *hPimEff_VII_VIII =new TH2D("hPimEff_VII_VIII","Efficiency at -80. < z < -75. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hPimEff_VII_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_VII_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_VII_VIII->Sumw2();
  TCanvas *cZ_VII_VIII = new TCanvas("VII_VIII","VII_VIII",800,800);
  cZ_VII_VIII->cd();
  hPimEff_VII_VIII->Divide(hMC_VII_VIII,hdata_VII_VIII);
  hPimEff_VII_VIII->SetDirectory(0);
  hPimEff_VII_VIII->Draw("colz text");
  
  
  hdata_VIII_I= (TH2D*)Data.Get("hEff_VIII_I");
  hMC_VIII_I= (TH2D*)MC.Get("hEff_VIII_I");
  hdata_VIII_I->SetName("hdata_VIII_I");
  hMC_VIII_I->SetName("hMC_VIII_I");
  TH2D *hPimEff_VIII_I =new TH2D("hPimEff_VIII_I","Efficiency at -75. < z < -70. at 0. < P < 0.5" ,30,-100,100,30,-100,100);
  hPimEff_VIII_I->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_VIII_I->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_VIII_I->Sumw2();
  TCanvas *cZ_VIII_I = new TCanvas("VIII_I","VIII_I",800,800);
  cZ_VIII_I->cd();
  hPimEff_VIII_I->Divide(hMC_VIII_I,hdata_VIII_I);
  hPimEff_VIII_I->SetDirectory(0);
  hPimEff_VIII_I->Draw("colz text");
  
  
  hdata_VIII_II= (TH2D*)Data.Get("hEff_VIII_II");
  hMC_VIII_II= (TH2D*)MC.Get("hEff_VIII_II");
  hdata_VIII_II->SetName("hdata_VIII_II");
  hMC_VIII_II->SetName("hMC_VIII_II");
  TH2D *hPimEff_VIII_II =new TH2D("hPimEff_VIII_II","Efficiency at -75. < z < -70. at 0.5 < P < 0.75" ,30,-100,100,30,-100,100);
  hPimEff_VIII_II->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_VIII_II->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_VIII_II->Sumw2();
  TCanvas *cZ_VIII_II = new TCanvas("VIII_II","VIII_II",800,800);
  cZ_VIII_II->cd();
  hPimEff_VIII_II->Divide(hMC_VIII_II,hdata_VIII_II);
  hPimEff_VIII_II->SetDirectory(0);
  hPimEff_VIII_II->Draw("colz text");
  
  
  hdata_VIII_III= (TH2D*)Data.Get("hEff_VIII_III");
  hMC_VIII_III= (TH2D*)MC.Get("hEff_VIII_III");
  hdata_VIII_III->SetName("hdata_VIII_III");
  hMC_VIII_III->SetName("hMC_VIII_III");
  TH2D *hPimEff_VIII_III =new TH2D("hPimEff_VIII_III","Efficiency at -75. < z < -70. at 0.75 < P < 1." ,30,-100,100,30,-100,100);
  hPimEff_VIII_III->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_VIII_III->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_VIII_III->Sumw2();
  TCanvas *cZ_VIII_III = new TCanvas("VIII_III","VIII_III",800,800);
  cZ_VIII_III->cd();
  hPimEff_VIII_III->Divide(hMC_VIII_III,hdata_VIII_III);
  hPimEff_VIII_III->SetDirectory(0);
  hPimEff_VIII_III->Draw("colz text");
  
  
  hdata_VIII_IV= (TH2D*)Data.Get("hEff_VIII_IV");
  hMC_VIII_IV= (TH2D*)MC.Get("hEff_VIII_IV");
  hdata_VIII_IV->SetName("hdata_VIII_IV");
  hMC_VIII_IV->SetName("hMC_VIII_IV");
  TH2D *hPimEff_VIII_IV =new TH2D("hPimEff_VIII_IV","Efficiency at -75. < z < -70. at 1. < P < 1.5" ,30,-100,100,30,-100,100);
  hPimEff_VIII_IV->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_VIII_IV->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_VIII_IV->Sumw2();
  TCanvas *cZ_VIII_IV = new TCanvas("VIII_IV","VIII_IV",800,800);
  cZ_VIII_IV->cd();
  hPimEff_VIII_IV->Divide(hMC_VIII_IV,hdata_VIII_IV);
  hPimEff_VIII_IV->SetDirectory(0);
  hPimEff_VIII_IV->Draw("colz text");
  
  
  hdata_VIII_V= (TH2D*)Data.Get("hEff_VIII_V");
  hMC_VIII_V= (TH2D*)MC.Get("hEff_VIII_V");
  hdata_VIII_V->SetName("hdata_VIII_V");
  hMC_VIII_V->SetName("hMC_VIII_V");
  TH2D *hPimEff_VIII_V =new TH2D("hPimEff_VIII_V","Efficiency at -75. < z < -70. at 1.5 < P < 2." ,30,-100,100,30,-100,100);
  hPimEff_VIII_V->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_VIII_V->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_VIII_V->Sumw2();
  TCanvas *cZ_VIII_V = new TCanvas("VIII_V","VIII_V",800,800);
  cZ_VIII_V->cd();
  hPimEff_VIII_V->Divide(hMC_VIII_V,hdata_VIII_V);
  hPimEff_VIII_V->SetDirectory(0);
  hPimEff_VIII_V->Draw("colz text");
  
  
  hdata_VIII_VI= (TH2D*)Data.Get("hEff_VIII_VI");
  hMC_VIII_VI= (TH2D*)MC.Get("hEff_VIII_VI");
  hdata_VIII_VI->SetName("hdata_VIII_VI");
  hMC_VIII_VI->SetName("hMC_VIII_VI");
  TH2D *hPimEff_VIII_VI =new TH2D("hPimEff_VIII_VI","Efficiency at -75. < z < -70. at 2. < P < 2.5" ,30,-100,100,30,-100,100);
  hPimEff_VIII_VI->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_VIII_VI->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_VIII_VI->Sumw2();
  TCanvas *cZ_VIII_VI = new TCanvas("VIII_VI","VIII_VI",800,800);
  cZ_VIII_VI->cd();
  hPimEff_VIII_VI->Divide(hMC_VIII_VI,hdata_VIII_VI);
  hPimEff_VIII_VI->SetDirectory(0);
  hPimEff_VIII_VI->Draw("colz text");
  
  
  hdata_VIII_VII= (TH2D*)Data.Get("hEff_VIII_VII");
  hMC_VIII_VII= (TH2D*)MC.Get("hEff_VIII_VII");
  hdata_VIII_VII->SetName("hdata_VIII_VII");
  hMC_VIII_VII->SetName("hMC_VIII_VII");
  TH2D *hPimEff_VIII_VII =new TH2D("hPimEff_VIII_VII","Efficiency at -75. < z < -70. at 2.5 < P < 3." ,30,-100,100,30,-100,100);
  hPimEff_VIII_VII->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_VIII_VII->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_VIII_VII->Sumw2();
  TCanvas *cZ_VIII_VII = new TCanvas("VIII_VII","VIII_VII",800,800);
  cZ_VIII_VII->cd();
  hPimEff_VIII_VII->Divide(hMC_VIII_VII,hdata_VIII_VII);
  hPimEff_VIII_VII->SetDirectory(0);
  hPimEff_VIII_VII->Draw("colz text");
  
  
  hdata_VIII_VIII= (TH2D*)Data.Get("hEff_VIII_VIII");
  hMC_VIII_VIII= (TH2D*)MC.Get("hEff_VIII_VIII");
  hdata_VIII_VIII->SetName("hdata_VIII_VIII");
  hMC_VIII_VIII->SetName("hMC_VIII_VIII");
  TH2D *hPimEff_VIII_VIII =new TH2D("hPimEff_VIII_VIII","Efficiency at -75. < z < -70. at 3. < P < 5." ,30,-100,100,30,-100,100);
  hPimEff_VIII_VIII->SetXTitle("#theta sin(#phi) [#circ] ");
  hPimEff_VIII_VIII->SetYTitle("#theta cos(#phi) [#circ] ");
  hPimEff_VIII_VIII->Sumw2();
  TCanvas *cZ_VIII_VIII = new TCanvas("VIII_VIII","VIII_VIII",800,800);
  cZ_VIII_VIII->cd();
  hPimEff_VIII_VIII->Divide(hMC_VIII_VIII,hdata_VIII_VIII);
  hPimEff_VIII_VIII->SetDirectory(0);
  hPimEff_VIII_VIII->Draw("colz text");
  
  TFile fout("Efficiency_Plots_Compared_Pim.root","recreate");
  hdata_I_I->Write();
  hMC_I_I->Write();
  hPimEff_I_I->Write();
  
  hdata_I_II->Write();
  hMC_I_II->Write();
  hPimEff_I_II->Write();
  
  hdata_I_III->Write();
  hMC_I_III->Write();
  hPimEff_I_III->Write();
  
  hdata_I_IV->Write();
  hMC_I_IV->Write();
  hPimEff_I_IV->Write();
  
  hdata_I_V->Write();
  hMC_I_V->Write();
  hPimEff_I_V->Write();
  
  hdata_I_VI->Write();
  hMC_I_VI->Write();
  hPimEff_I_VI->Write();
  
  hdata_I_VII->Write();
  hMC_I_VII->Write();
  hPimEff_I_VII->Write();
  
  hdata_I_VIII->Write();
  hMC_I_VIII->Write();
  hPimEff_I_VIII->Write();
  
  hdata_II_I->Write();
  hMC_II_I->Write();
  hPimEff_II_I->Write();
  
  hdata_II_II->Write();
  hMC_II_II->Write();
  hPimEff_II_II->Write();
  
  hdata_II_III->Write();
  hMC_II_III->Write();
  hPimEff_II_III->Write();
  
  hdata_II_IV->Write();
  hMC_II_IV->Write();
  hPimEff_II_IV->Write();
  
  hdata_II_V->Write();
  hMC_II_V->Write();
  hPimEff_II_V->Write();
  
  hdata_II_VI->Write();
  hMC_II_VI->Write();
  hPimEff_II_VI->Write();
  
  hdata_II_VII->Write();
  hMC_II_VII->Write();
  hPimEff_II_VII->Write();
  
  hdata_II_VIII->Write();
  hMC_II_VIII->Write();
  hPimEff_II_VIII->Write();
  
  hdata_III_I->Write();
  hMC_III_I->Write();
  hPimEff_III_I->Write();
  
  hdata_III_II->Write();
  hMC_III_II->Write();
  hPimEff_III_II->Write();
  
  hdata_III_III->Write();
  hMC_III_III->Write();
  hPimEff_III_III->Write();
  
  hdata_III_IV->Write();
  hMC_III_IV->Write();
  hPimEff_III_IV->Write();
  
  hdata_III_V->Write();
  hMC_III_V->Write();
  hPimEff_III_V->Write();
  
  hdata_III_VI->Write();
  hMC_III_VI->Write();
  hPimEff_III_VI->Write();
  
  hdata_III_VII->Write();
  hMC_III_VII->Write();
  hPimEff_III_VII->Write();
  
  hdata_III_VIII->Write();
  hMC_III_VIII->Write();
  hPimEff_III_VIII->Write();
  
  hdata_IV_I->Write();
  hMC_IV_I->Write();
  hPimEff_IV_I->Write();
  
  hdata_IV_II->Write();
  hMC_IV_II->Write();
  hPimEff_IV_II->Write();
  
  hdata_IV_III->Write();
  hMC_IV_III->Write();
  hPimEff_IV_III->Write();
  
  hdata_IV_IV->Write();
  hMC_IV_IV->Write();
  hPimEff_IV_IV->Write();
  
  hdata_IV_V->Write();
  hMC_IV_V->Write();
  hPimEff_IV_V->Write();
  
  hdata_IV_VI->Write();
  hMC_IV_VI->Write();
  hPimEff_IV_VI->Write();
  
  hdata_IV_VII->Write();
  hMC_IV_VII->Write();
  hPimEff_IV_VII->Write();
  
  hdata_IV_VIII->Write();
  hMC_IV_VIII->Write();
  hPimEff_IV_VIII->Write();
  
  hdata_V_I->Write();
  hMC_V_I->Write();
  hPimEff_V_I->Write();
  
  hdata_V_II->Write();
  hMC_V_II->Write();
  hPimEff_V_II->Write();
  
  hdata_V_III->Write();
  hMC_V_III->Write();
  hPimEff_V_III->Write();
  
  hdata_V_IV->Write();
  hMC_V_IV->Write();
  hPimEff_V_IV->Write();
  
  hdata_V_V->Write();
  hMC_V_V->Write();
  hPimEff_V_V->Write();
  
  hdata_V_VI->Write();
  hMC_V_VI->Write();
  hPimEff_V_VI->Write();
  
  hdata_V_VII->Write();
  hMC_V_VII->Write();
  hPimEff_V_VII->Write();
  
  hdata_V_VIII->Write();
  hMC_V_VIII->Write();
  hPimEff_V_VIII->Write();
  
  hdata_VI_I->Write();
  hMC_VI_I->Write();
  hPimEff_VI_I->Write();
  
  hdata_VI_II->Write();
  hMC_VI_II->Write();
  hPimEff_VI_II->Write();
  
  hdata_VI_III->Write();
  hMC_VI_III->Write();
  hPimEff_VI_III->Write();
  
  hdata_VI_IV->Write();
  hMC_VI_IV->Write();
  hPimEff_VI_IV->Write();
  
  hdata_VI_V->Write();
  hMC_VI_V->Write();
  hPimEff_VI_V->Write();
  
  hdata_VI_VI->Write();
  hMC_VI_VI->Write();
  hPimEff_VI_VI->Write();
  
  hdata_VI_VII->Write();
  hMC_VI_VII->Write();
  hPimEff_VI_VII->Write();
  
  hdata_VI_VIII->Write();
  hMC_VI_VIII->Write();
  hPimEff_VI_VIII->Write();
  
  hdata_VII_I->Write();
  hMC_VII_I->Write();
  hPimEff_VII_I->Write();
  
  hdata_VII_II->Write();
  hMC_VII_II->Write();
  hPimEff_VII_II->Write();
  
  hdata_VII_III->Write();
  hMC_VII_III->Write();
  hPimEff_VII_III->Write();
  
  hdata_VII_IV->Write();
  hMC_VII_IV->Write();
  hPimEff_VII_IV->Write();
  
  hdata_VII_V->Write();
  hMC_VII_V->Write();
  hPimEff_VII_V->Write();
  
  hdata_VII_VI->Write();
  hMC_VII_VI->Write();
  hPimEff_VII_VI->Write();
  
  hdata_VII_VII->Write();
  hMC_VII_VII->Write();
  hPimEff_VII_VII->Write();
  
  hdata_VII_VIII->Write();
  hMC_VII_VIII->Write();
  hPimEff_VII_VIII->Write();
  
  hdata_VIII_I->Write();
  hMC_VIII_I->Write();
  hPimEff_VIII_I->Write();
  
  hdata_VIII_II->Write();
  hMC_VIII_II->Write();
  hPimEff_VIII_II->Write();
  
  hdata_VIII_III->Write();
  hMC_VIII_III->Write();
  hPimEff_VIII_III->Write();
  
  hdata_VIII_IV->Write();
  hMC_VIII_IV->Write();
  hPimEff_VIII_IV->Write();
  
  hdata_VIII_V->Write();
  hMC_VIII_V->Write();
  hPimEff_VIII_V->Write();
  
  hdata_VIII_VI->Write();
  hMC_VIII_VI->Write();
  hPimEff_VIII_VI->Write();
  
  hdata_VIII_VII->Write();
  hMC_VIII_VII->Write();
  hPimEff_VIII_VII->Write();
  
  hdata_VIII_VIII->Write();
  hMC_VIII_VIII->Write();
  hPimEff_VIII_VIII->Write();
  
  fout.Close();  	
	
}
