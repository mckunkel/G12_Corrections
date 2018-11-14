#!/apps/bin/perl -w
use strict;
use warnings;

my $file_list = "filenames";
my $data_dir = "/volatile/clas/clasg12/mkunkel/LEPTON_RESKIM/ROOT/";
my $added_dir = "/volatile/clas/clasg12/mkunkel/LEPTON_RESKIM/HADDED/";
my $flag = 0;
#g12_lepton_56363_A00.root

open my $FILE_f, "<", $file_list or die "Cannot open $file_list for read :$!";

while (<$FILE_f>) {	
  chop($_);
  my $line = $_;
  chop($line);
  my $addedFile = $added_dir."g12_lepton_$line.root";
  if(-e $addedFile){
    $flag = 1;
  }
  else{
    my $command = ("hadd $addedFile $data_dir*_$line"."_*");
    #print "$command \n";
    system($command);
    #print $job_file "$fileSub ";
  }
}	
