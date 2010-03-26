#!/usr/bin/perl

# $Id: example.pl,v 1.0.0-0 2009/09/04 17:03:39 Cnangel Exp $

use strict;
use warnings;
use vars qw/$starttime %ARGV/;
BEGIN { $starttime = (times)[0] + (times)[1]; }
END { printf("%d\n", ((times)[0] + (times)[1] - $starttime) * 1000) if ($ARGV{debug}); }
use Getopt::Long qw(:config no_ignore_case);
use Pod::Usage;
# use File::Find;
use FindBin qw/$Bin/;
use lib "$Bin/../lib";
use Conf::Libconfig;
use Net::FTP;

my $man = 0;
my $help = 0;
pod2usage() if (scalar @ARGV == 0); 
GetOptions (
		"c|conf=s"			=> \$ARGV{conf},
		"debug"             => \$ARGV{debug},
		"verbose"           => \$ARGV{verbose},
		'help|?'            => \$help,
		man                 => \$man
		) or pod2usage(2);
pod2usage(1) if $help;
pod2usage(-exitstatus => 0, -verbose => 2) if $man;
$ARGV{conf} = "$Bin/../conf/config.cfg" unless ($ARGV{conf} && -f $ARGV{conf});
pod2usage() unless (-f $ARGV{conf});

# use vars qw/@files/;
use Data::Dumper;

# read config file
my $conf = Conf::Libconfig->new;
$conf->read_file($ARGV{'conf'});
my $key = $ARGV{'key'} ? $ARGV{'key'} : $conf->lookup_value("application.key");

# sub GetFileFromDir
# {
# 	my $dir = shift;
# 	find(\&wanted, $dir);
# 	return \@files;
# }
# 
# sub wanted
# {
# 	push @files, $File::Find::name if (-f $_);
# }

__END__

=head1 NAME

example.pl - Example Perl Script

=head1 SYNOPSIS

example.pl -c <conf>

example.pl -help

=head1 OPTIONS

=over 8

=item B<-c|--conf>

Configuration for the script, default is $PROJECT_HOME/conf.

=item B<--debug>

Debug mode, you can see how much time spent in B<this program>.

=item B<--help>

Print a brief help message and exits.

=item B<--man>

Prints the manual page and exits.

=back

=head1 DESCRIPTION

B<This program> will read the given input file(s) and do something
useful with the contents thereof, then output result of file(s).

=head1 AUTHOR 

B<Cnangel> (I<cnangel@gmail.com>)

=head1 HISTORY

I<2009/09/04 17:03:39> Builded.

=cut
