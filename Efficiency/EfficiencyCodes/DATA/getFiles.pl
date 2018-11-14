#!/apps/bin/perl -w
use strict;
use warnings;

my $file_list = "good_totfile";

my $out_dir = "/volatile/clas/clasg12/mkunkel/EFFICIENCY/ROOT/DATA";

open my $get_file, ">unfinishFiles.dat" or die "cannot open unfinishFiles.dat file:$!";

open my $FILE_f, "<", $file_list or die "Cannot open $file_list for read :$!";
my $flag = 0;

while (<$FILE_f>) {
  chop($_);
  my $file = $_;
  #$file =~ tr#.#_#;
  $file = "g12_Prot_Efficiency_".$file;
  #print "selecting $file \n";
  my $rootF = $out_dir."/".$file.".root";
  #print "$rootF \n";
  if(-e $rootF){
    $flag = 1;
  }
  else{
    my $fileSub = $_;
    print $get_file "$fileSub\n";
    #print "$rootF \n";
  }
}
close $FILE_f;
close $get_file;
