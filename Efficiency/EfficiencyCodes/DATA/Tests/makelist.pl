#!/apps/bin/perl -w
use strict;
use warnings;

my $file_list = "eff_totfile";

#my $output_dir = "/volatile/clas/clasg12/mkunkel/LEPTON_RESKIM/ROOT";

open my $get_file, ">filenames" or die "cannot open filenames file:$!";

open my $FILE_f, "<", $file_list or die "Cannot open $file_list for read :$!";
my $flag = 0;
my $string_1 = "Group";
my $test;
while (<$FILE_f>) {	
	chop($_);
	my $file = $_;
  chop($file); #chop($file); chop($file); chop($file);
  my $file_I = $file.".A10";
  my $file_II = $file.".A18";
  my $file_III = $file.".A05";
  my $file_IV= $file.".A03";
  if($file !~ m/$string_1/){
    print "$file_I \n";
    print "$file_II \n";
    print "$file_III \n";
    print "$file_IV \n";
    print $get_file "$file_I \n";
    print $get_file "$file_II \n";
    print $get_file "$file_III \n";
    print $get_file "$file_IV \n";
    $string_1 = $file;
    $flag++;

  }

}
print "$flag RUNS \n";

close $FILE_f;
close $get_file;

