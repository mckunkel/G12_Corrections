extern "C" {
#include <stdlib.h>                                 /* standard header files */
#include <stdio.h>
#include <math.h>
}
#include <Ppp_cE.h>

// set up tree
void Ppp_cE_tree(){
  
  lepTree.Branch("in_Nphoton",&ntlep.in_Nphoton,"in_Nphoton/I");
  lepTree.Branch("N_in_timePhoton",&ntlep.N_in_timePhoton,"N_in_timePhoton/I");
  
  lepTree.Branch("in_photon_stat",&ntlep.in_photon_stat,"in_photon_stat[in_Nphoton]/I");
  lepTree.Branch("in_photon_E",&ntlep.in_photon_E,"in_photon_E[in_Nphoton]/F");
  lepTree.Branch("in_photon_tpho",&ntlep.in_photon_tpho,"in_photon_tpho[in_Nphoton]/F");
  lepTree.Branch("in_photon_ttag",&ntlep.in_photon_ttag,"in_photon_ttag[in_Nphoton]/F");
  
  lepTree.Branch("run",&nt.run,"run/I");
  lepTree.Branch("event",&nt.event,"event/I");
  lepTree.Branch("egam",&nt.egam,"egam/F");
  lepTree.Branch("tpho",&nt.tpho,"tpho/F");
  lepTree.Branch("vtime",&nt.vtime,"vtime/F");
  lepTree.Branch("vx",&nt.vx,"vx/F");
  lepTree.Branch("vy",&nt.vy,"vy/F");
  lepTree.Branch("vz",&nt.vz,"vz/F");
  lepTree.Branch("NPart",&nt.NPart,"NPart/I");
  //------------ For Outgoing Gamma -------------
  lepTree.Branch("NProt",&ntlep.NProt,"NProt/I");
  lepTree.Branch("NPip",&ntlep.NPip,"NPip/I");
  lepTree.Branch("NPim",&ntlep.NPim,"NPim/I");
  
  
  //------------ For Pip -------------
  lepTree.Branch("pip_vz",&ntlep.pip_vz,"pip_vz/F");
  lepTree.Branch("pip_vy",&ntlep.pip_vy,"pip_vy/F");
  lepTree.Branch("pip_vx",&ntlep.pip_vx,"pip_vx/F");
  
  lepTree.Branch("pip_P",&ntlep.pip_P,"pip_P/F");
  lepTree.Branch("pip_Pt",&ntlep.pip_Pt,"pip_Pt/F");
  lepTree.Branch("pip_Pl",&ntlep.pip_Pl,"pip_Pl/F");
  lepTree.Branch("pip_Theta",&ntlep.pip_Theta,"pip_Theta/F");
  lepTree.Branch("pip_Phi",&ntlep.pip_Phi,"pip_Phi/F");
  
  lepTree.Branch("pip_sec",&ntlep.pip_sec,"pip_sec/I");
  lepTree.Branch("pip_tofKO",&ntlep.pip_tofKO,"pip_tofKO/I");
  
  lepTree.Branch("pip_dTOF",&ntlep.pip_dTOF,"pip_dTOF/F");
  lepTree.Branch("pip_mat",&ntlep.pip_mat,"pip_mat[5][5]/F");
  
  lepTree.Branch("Timing_pip",&ntlep.Timing_pip,"Timing_pip/F");
  
  //------------ For Pim -------------
  lepTree.Branch("pim_vz",&ntlep.pim_vz,"pim_vz/F");
  lepTree.Branch("pim_vy",&ntlep.pim_vy,"pim_vy/F");
  lepTree.Branch("pim_vx",&ntlep.pim_vx,"pim_vx/F");
  
  lepTree.Branch("pim_P",&ntlep.pim_P,"pim_P/F");
  lepTree.Branch("pim_Pt",&ntlep.pim_Pt,"pim_Pt/F");
  lepTree.Branch("pim_Pl",&ntlep.pim_Pl,"pim_Pl/F");
  lepTree.Branch("pim_Theta",&ntlep.pim_Theta,"pim_Theta/F");
  lepTree.Branch("pim_Phi",&ntlep.pim_Phi,"pim_Phi/F");
  
  lepTree.Branch("pim_sec",&ntlep.pim_sec,"pim_sec/I");
  lepTree.Branch("pim_tofKO",&ntlep.pim_tofKO,"pim_tofKO/I");
  
  lepTree.Branch("pim_dTOF",&ntlep.pim_dTOF,"pim_dTOF/F");
  lepTree.Branch("Timing_pim",&ntlep.Timing_pim,"Timing_pim/F");
  
  lepTree.Branch("pim_mat",&ntlep.pim_mat,"pim_mat[5][5]/F");
  
  
  
  //------------ For Proton -------------
  lepTree.Branch("prot_vz",&ntlep.prot_vz,"prot_vz/F");
  lepTree.Branch("prot_vy",&ntlep.prot_vy,"prot_vy/F");
  lepTree.Branch("prot_vx",&ntlep.prot_vx,"prot_vx/F");
  
  lepTree.Branch("prot_P",&ntlep.prot_P,"prot_P/F");
  lepTree.Branch("prot_Pt",&ntlep.prot_Pt,"prot_Pt/F");
  lepTree.Branch("prot_Pl",&ntlep.prot_Pl,"prot_Pl/F");
  lepTree.Branch("prot_Theta",&ntlep.prot_Theta,"prot_Theta/F");
  lepTree.Branch("prot_Phi",&ntlep.prot_Phi,"prot_Phi/F");
  
  lepTree.Branch("prot_sec",&ntlep.prot_sec,"prot_sec/I");
  lepTree.Branch("prot_tofKO",&ntlep.prot_tofKO,"prot_tofKO/I");
  
  lepTree.Branch("prot_dTOF",&ntlep.prot_dTOF,"prot_dTOF/F");
  lepTree.Branch("prot_mat",&ntlep.prot_mat,"prot_mat[5][5]/F");
  lepTree.Branch("Timing_prot",&ntlep.Timing_prot,"Timing_prot/F");
  
  
  
}






