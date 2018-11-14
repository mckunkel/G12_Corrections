#!/apps/bin/perl -w

use strict;
use warnings;
#print("#!/opt/local/bin/perl -w \n");

my $file_list = "unfinishFiles.dat";

my $output_dir = "/volatile/clas/clasg12/mkunkel/EFFICIENCY/ROOT";
my $rundir = "/work/clas/clasg12/mkunkel/twolep/NOPID/EFFICIENCY/SUBMIT_ALL_EFF/EXECUTABLES";
my $mss_dir = "mss:/mss/clas/g12/production/pass1/bos";
my $parms_dir = "/u/home/mkunkel/Kinefitter/LEPTON_KINEFITTER_03_06_2015/parms";

my $flag = 0;
my $totalFiles = 1;	#12 total number of files per job
my $nJobs = 1;	#3459 total number of job

open my $FILE_f, "<", $file_list or die "Cannot open $file_list for read :$!";
my $line = <$FILE_f>;
my $totalW = 0;
my $iJob = 0;

while($iJob < $nJobs and $line ne ""){
	  my $make_dir = "mkdir parms";
      my $mv_parms = "cp $parms_dir/g* parms";
  
	open my $job_file, ">job.xml" or die "cannot open job.xml file:$!";
	print $job_file "<Request>
  <Email email=\"mkunkel\@jlab.org\" request=\"false\" job=\"false\"/>
  <Project name=\"G12\"/>
  <Track name=\"analysis\"/>
  <OS name=\"centos65\"/>
  <Name name=\"g12_efficiency\"/>
  <Memory space=\"500\" unit=\"MB\"/>
  <Command><![CDATA[
                    source buildCentos65.cshrc
                    
                    foreach index (`seq $totalFiles`)
                    Pim_Efficiency data1_\$index.bos data2_\$index.bos data3_\$index.bos data4_\$index.bos data5_\$index.bos
                    PPip_missingPim Ppp_cE.root Pim_Efficiency_\$index.root
                    rm Ppp_cE.root
                    Pip_Efficiency data1_\$index.bos data2_\$index.bos data3_\$index.bos data4_\$index.bos data5_\$index.bos                
                    PPim_missingPip Ppp_cE.root Pip_Efficiency_\$index.root 
                    rm Ppp_cE.root            
                    Prot_Efficiency data1_\$index.bos data2_\$index.bos data3_\$index.bos data4_\$index.bos data5_\$index.bos
                    PipPim_missingProt Ppp_cE.root Prot_Efficiency_\$index.root
                    rm Ppp_cE.root
                    end
                    
                    ]]></Command>
  
  <TimeLimit unit=\"minutes\" time=\"120\"/>
  <Input src=\"$rundir/buildCentos65.cshrc\" dest=\"buildCentos65.cshrc\"/>
  <Input src=\"$rundir/Pim_Efficiency\" dest=\"Pim_Efficiency\"/>
  <Input src=\"$rundir/Pip_Efficiency\" dest=\"Pip_Efficiency\"/>
  <Input src=\"$rundir/Prot_Efficiency\" dest=\"Prot_Efficiency\"/>
  <Input src=\"$rundir/PPip_missingPim\" dest=\"PPip_missingPim\"/>
  <Input src=\"$rundir/PPim_missingPip\" dest=\"PPim_missingPip\"/>
  <Input src=\"$rundir/PipPim_missingProt\" dest=\"PipPim_missingProt\"/>

  <DiskSpace space=\"5\" unit=\"GB\"/>
  <Job>
  ";
  
  my $n = 1;
	while($n <= $totalFiles and $line ne ""){
		chop($line); #chop($line);
		#print "$line\n";
		my $file = $line;
		$file =~ tr#.#_#;
   my $Pimfile = "g12_Pim_Efficiency_".$file;
   my $Pipfile = "g12_Pip_Efficiency_".$file;
   my $Protfile = "g12_Prot_Efficiency_".$file;
		my $rootF = $output_dir."/".$Pimfile.".root";
		my $rootF_II = $output_dir."/".$Pipfile.".root";
		my $rootF_III = $output_dir."/".$Protfile.".root";
    my $bosFile = $file.".bos";
#my $bos_outputFile = $bos_output_dir."/".$bosFile;
    
		if(-e $rootF){
			$flag = 1;
		}
		else{
			print $job_file "
      
      
      <Input src=\"$mss_dir/1-1ckaon1ctrk/$line\" dest=\"data1_$n.bos\"/>
      <Input src=\"$mss_dir/2-2pos1neg_not_1ckaon1ctrk/$line\" dest=\"data2_$n.bos\"/>
      <Input src=\"$mss_dir/3-2ctrk_not_2pos1neg_1ckaon1ctrk/$line\" dest=\"data3_$n.bos\"/>
      <Input src=\"$mss_dir/4-not_2ctrk_2pos1neg_1ckaon1ctrk/$line\" dest=\"data4_$n.bos\"/>
      <Input src=\"$mss_dir/5-other/$line\" dest=\"data5_$n.bos\"/>
      
      <Output src=\"Pim_Efficiency_$n.root\" dest=\"$rootF\"/>
      <Output src=\"Pip_Efficiency_$n.root\" dest=\"$rootF_II\"/>
      <Output src=\"Prot_Efficiency_$n.root\" dest=\"$rootF_III\"/>
      ";
      $n++;
#      <Output src=\"twolep.bos\" dest=\"$bos_outputFile\"/>
      
		}
		$line = <$FILE_f>;
	}
  print $job_file "\n \t</Job>\n</Request>";
  
#print $job_file "\n</Request>";
  
	close $job_file;
  
	my $sub = "jsub -xml job.xml";
	system($sub);
	print "submitted job $iJob\n";
	$iJob++;
}	
