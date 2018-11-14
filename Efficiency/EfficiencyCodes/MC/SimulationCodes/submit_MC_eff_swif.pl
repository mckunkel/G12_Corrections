#!/apps/bin/perl -w

use strict;
use warnings;
#SO lets try the new swif system
#need to define workflow
#workflow changes according to personal project....i.e.
#reskim and simulations should be 2 different work flows
my $workflow = "-workflow MC_efficiency";
my $project = "-project G12";
my $track = "-track simulation";
my $time = "-time 400min";
my $OS = "-os centos65";
my $shell = "-shell /bin/tcsh";
my $ram = "-ram 2g";
my $disk = "-disk 40g";
my $CPU_count = "-cores 1";

#
#
################################
my $nJobs = 50000;	# total number of job 5000
my $NEvents = 100008; #100008
my $iJob = 10003;
my $done_job = 0;

my $output_dir = "/volatile/clas/clasg12/mkunkel/EFFICIENCY/ROOT/MC";
my $rundir = "/work/clas/clasg12/mkunkel/twolep/NOPID/EFFICIENCY/MC/SimulationCodes";

my $input_1 = "-input buildCentos65.cshrc $rundir/buildCentos65.cshrc";
my $input_2 = "-input PPipPim_Simulate.C $rundir/PPipPim_Simulate.C";
my $input_3 = "-input ffread.g12_LEPTON $rundir/ffread.g12_LEPTON";
my $input_4 = "-input Pim_Efficiency $rundir/Pim_Efficiency";
my $input_5 = "-input Pip_Efficiency $rundir/Pip_Efficiency";
my $input_6 = "-input Prot_Efficiency $rundir/Prot_Efficiency";
my $input_7 = "-input PPip_missingPim $rundir/PPip_missingPim";
my $input_8 = "-input PPim_missingPip $rundir/PPim_missingPip";
my $input_9 = "-input PipPim_missingProt $rundir/PipPim_missingProt";
  

my $command_source = "source buildCentos65.cshrc";
my $command_exit = "exit 0";

while($iJob < $nJobs){
	
  my $gen_file = "ppippim".$iJob.".root";
  my $gamp_file = "G12_PPipPim".$iJob.".gamp";
  my $part_file = "ppippim".$iJob.".part";
  my $gpp_file = "ppippim".$iJob.".gpp";
  my $out_file = "ppippim".$iJob.".root";
  my $Pimfile = "g12_Pim_Efficiency_".$iJob.".root";
  my $Pipfile = "g12_Pip_Efficiency_".$iJob.".root";
  my $Protfile = "g12_Prot_Efficiency_".$iJob.".root";
   
  my $Pimfile_raw = "g12_Pim_Raw_".$iJob.".root";
  my $Pipfile_raw = "g12_Pip_Raw_".$iJob.".root";
  my $Protfile_raw = "g12_Prot_Raw_".$iJob.".root";
   
	my $num =$iJob+1;
#my $test =`filetest -e $out_dir/$root_file`;
#system($test);
  
	if(-e $output_dir."/".$gen_file){
#print "YO!";
		$iJob++;
		$done_job++;
		next;
	}
	
  my $cal_db = "echo \$CLAS_CALDB_RUNINDEX is the run index that was sourced";
  my $run_pluto = "root -b -q -l -x 'PPipPim_Simulate.C+($iJob,$NEvents)'";
  my $gamp2part = "gamp2part -r56855 -o$part_file -T -S-0.321,0.378,-0.254,0.407 -z-110,-70 G12_PPipPim.gamp";
  my $gsim_run = "gsim_bat -ffread ffread.g12_LEPTON -kine 1 -mcin $part_file -bosout";
  my $gpp_run = "gpp -a2.73 -b1.7 -c1.93 -f1 -Y -s -R56855 -P0x7f -o$gpp_file gsimout*";
  my $a1c_run = "a1c -R56855 -T4 -sa -ct1930 -cm0 -cp0 -X0 -d1 -F -P0x1bff -z0,0,-90 -Aprlink_tg-90pm30.bos -O $gpp_file";
  my $Pim_run = "./Pim_Efficiency run*";
  my $Pip_run = "./Pip_Efficiency run*";
  my $Prot_run = "./Prot_Efficiency run*";
  my $Pim_fit = "./PPip_missingPim Ppp_cE.root $Pimfile";
  my $Pip_fit = "./PPim_missingPip Ppp_cE.root $Pipfile";
  my $Prot_fit = "./PipPim_missingProt Ppp_cE.root $Protfile";
   
  my $moverI = "rm ppippim.root ";
  my $moverII = "rm G12_PPipPim.gamp ";
  my $Pimmover = "mv $Pimfile $output_dir";
  my $Pipmover = "mv $Pipfile $output_dir";
  my $Protmover = "mv $Protfile $output_dir";
## I am testing the pull dist for the simulation of the fitter only outputting raw files. Uncomment above and comment below when pull dist is fixed. Also change the command line to what is below
#COMMAND: $sim_source;  $make_dir; $mv_parms; $cal_db; $run_pluto ; $gamp2part ; $gsim_run; $gpp_run ; $a1c_run ; $Pim_run; $Pim_fit; $Pimmover; $removeIV; $Pip_run; $Pip_fit; $Pipmover; $removeIV; $Prot_run; $Prot_fit; $Protmover; $removeIV; $remove_V; $remove_III; $remove_II; $remove_I;
#below For testing 
#COMMAND: $sim_source; $make_dir; $mv_parms; $cal_db; $run_pluto ; $gamp2part ; $gsim_run; $gpp_run ; $a1c_run ; $Pim_run; $Pimmover;$Pip_run; $Pipmover; $Prot_run; $Protmover; $remove_V; $remove_III; $remove_II; $remove_I;

  #my $Pimmover = "mv Ppp_cE.root $out_dir/$Pimfile_raw";
  #my $Pipmover = "mv Ppp_cE.root $out_dir/$Pipfile_raw";
  #my $Protmover = "mv Ppp_cE.root $out_dir/$Protfile_raw";
##
  my $remove_I = "rm *.part ";
  my $remove_II = "rm *.gpp ";
  my $remove_III = "rm gsimout.* ";
  my $removeIV = "rm Ppp_cE.root";
  my $remove_V = "rm run* "; #$out_dir
  
  #$Pim_run; $Pim_fit; $Pimmover; $removeIV; $Pip_run; $Pip_fit; $Pipmover; $removeIV; $Prot_run; $Prot_fit; $Protmover; $removeIV;
	 open my $command_file, ">command.dat" or die "cannot open command.dat file:$!";
	print $command_file "$command_source ; $cal_db; $run_pluto; $gamp2part; $gsim_run; $gpp_run; $a1c_run; $Pim_run; $Pim_fit; $Pimmover; $removeIV; $Pip_run; $Pip_fit; $Pipmover; $removeIV; $Prot_run; $Prot_fit; $Protmover; $removeIV; $remove_V; $remove_III; $remove_II; $remove_I; $command_exit";
	close $command_file;
	  my $sub = "swif add-job $workflow $project $track $time $OS $ram $disk $CPU_count $input_1 $input_2 $input_3 $input_4 $input_5 $input_6 $input_7 $input_8 $input_9 -script command.dat";
  system ($sub);
  print "$sub \n";
  
	$iJob++;
}


