#!/apps/bin/perl -w

use strict;
use warnings;
#SO lets try the new swif system
#need to define workflow
#workflow changes according to personal project....i.e.
#reskim and simulations should be 2 different work flows
my $workflow = "-workflow efficiency";
my $project = "-project G12";
my $track = "-track analysis";
my $time = "-time 120min";
my $OS = "-os centos65";
my $shell = "-shell /bin/tcsh";
my $ram = "-ram 2g";
my $disk = "-disk 40g";
my $CPU_count = "-cores 1";

my $flag = 0;
my $totalFiles =10;	# total number of files per job
my $nJobs = 5600;	# total number of job 8159

my $file_list = "unfinishFiles.dat";
my $output_dir = "/volatile/clas/clasg12/mkunkel/EFFICIENCY/ROOT/DATA";
my $rundir = "/work/clas/clasg12/mkunkel/twolep/NOPID/EFFICIENCY/DATA/EXECUTABLES";
my $mss_dir = "mss:/mss/clas/g12/production/pass1/bos";

my $code_input_1 = "-input buildCentos65.cshrc $rundir/buildCentos65.cshrc";
my $code_input_2 = "-input Pim_Efficiency $rundir/Pim_Efficiency";
my $code_input_3 = "-input Pip_Efficiency $rundir/Pip_Efficiency";
my $code_input_4 = "-input Prot_Efficiency $rundir/Prot_Efficiency";
my $code_input_5 = "-input PPip_missingPim $rundir/PPip_missingPim";
my $code_input_6 = "-input PPim_missingPip $rundir/PPim_missingPip";
my $code_input_7 = "-input PipPim_missingProt $rundir/PipPim_missingProt";

my $command_1 = "source buildCentos65.cshrc";
my $command_2 = "
foreach index (`seq $totalFiles`)
echo file \$index is running
Pim_Efficiency data1_\$index.bos data2_\$index.bos
PPip_missingPim Ppp_cE.root Pim_Efficiency_\$index.root
rm Ppp_cE.root
Pip_Efficiency data1_\$index.bos data2_\$index.bos
PPim_missingPip Ppp_cE.root Pip_Efficiency_\$index.root
rm Ppp_cE.root
Prot_Efficiency data1_\$index.bos data2_\$index.bos
PipPim_missingProt Ppp_cE.root Prot_Efficiency_\$index.root
rm Ppp_cE.root
end";
my $command_3 = "
exit 0";

open my $FILE_f, "<", $file_list or die "Cannot open $file_list for read :$!";
my $line = <$FILE_f>;
my $iJob = 0;

while($iJob < $nJobs and $line ne ""){
  
  my $job_name = "reskim $iJob";
  
  my @input_3; my @input_4; my @input_5; my @input_6; my @input_7; my @output_1; my @output_2; my @output_3;
  
  my $n = 1;
  while($n <= $totalFiles and $line ne ""){
    #print "$line\n";
    chop($line);
    #print "$line\n";
    my $file = $line;
    #$file =~ tr#.#_#;
    #print "$file\n";
    my $Pimfile = "g12_Pim_Efficiency_".$file;
    my $Pipfile = "g12_Pip_Efficiency_".$file;
    my $Protfile = "g12_Prot_Efficiency_".$file;
    my $rootF = $output_dir."/".$Pimfile.".root";
    my $rootF_II = $output_dir."/".$Pipfile.".root";
    my $rootF_III = $output_dir."/".$Protfile.".root";
    my $bosFile = $file.".bos";
    
    if(-e $rootF){
      $flag = 1;
      next;
    }
    else{
      
      push(@input_3, "-input data1_$n.bos  $mss_dir/1-1ckaon1ctrk/$line");
      push(@input_4, "-input data2_$n.bos  $mss_dir/2-2pos1neg_not_1ckaon1ctrk/$line");
      push(@output_1, "-output Pim_Efficiency_$n.root $rootF");
      push(@output_2, "-output Pip_Efficiency_$n.root $rootF_II");
      push(@output_3, "-output Prot_Efficiency_$n.root $rootF_III");
      
      $n++;
      
    }
    $line = <$FILE_f>;
  }
  open my $command_file, ">command.dat" or die "cannot open command.dat file:$!";
  print $command_file "$command_1 ; $command_2";
  close $command_file;
  my $sub = "swif add-job $workflow $project $track $time $OS $ram $disk $CPU_count $code_input_1 $code_input_2 $code_input_3 $code_input_4 $code_input_5 $code_input_6 $code_input_7 @input_3 @input_4 @output_1 @output_2 @output_3 -script command.dat ";

  
  #print "$sub \n";
  system($sub);
  #print "submitted job $iJob\n";
  $iJob++;
}
