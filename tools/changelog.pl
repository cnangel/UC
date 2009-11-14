#!/usr/bin/perl

use strict;
use warnings;

if (@ARGV != 2) {
	print "Usage: $0 <README> <ChangeLog>\n";
	exit(1);
}

my %INFO;
open my $fp1, '<', $ARGV[0] or die "Can't read the file:$!";
while (my $line = <$fp1>)
{
	$line =~ s/^\s*//;
	$line =~ s/\s*$//;
	next unless ($line);
	if ($line =~ /\(([^\(]+\@[^\)]+)\)/)
	{
		$INFO{'email'} = $1;
		last;
	}
}
close $fp1;

open my $fp2, '<', $ARGV[1] or die "Can't read the file:$!";
while (my $line = <$fp2>)
{
	$line =~ s/^\s*//;
	$line =~ s/\s*$//;
	next unless ($line);
	unless (defined $INFO{'release'})
	{
		$INFO{'release'} = $1 if ($line =~ /^RELEASE\s(\d+)\sNOW/);
	}
	next unless ($line =~ /^\*/ || $line =~ /^(?:\d+\.){2}\d+/);
	if ($line =~ /^\*/) {
		$line =~ s/^\*/-/;
	} elsif ($line =~ /^((?:\d+\.){2}\d+)\s+(\w+\s+)(\d+\s+)(\w+\s+)(\d{4}\s+)(?:[\d\:\s]+)[A|P]M\s+CST\s+([a-zA-Z0-9]+)$/) {
		$line = "* " . $2 . $4 . $3 . $5 . $6 . ' <' . $INFO{'email'} . '> ' . $1 . (defined $INFO{'release'} ? '-' . $INFO{'release'} : '');
	}
	undef $INFO{'release'} if (defined $INFO{'release'});
	print "$line\n";
}
close $fp2;
