#!/usr/bin/perl

use strict;

my $n = shift;
my $i;

print $n, "\n";
for($i = 0; $i < $n; $i++){
  print int(rand()*(10000)), " ", int(rand()*(10000)), "\n";
}
print "0\n";
