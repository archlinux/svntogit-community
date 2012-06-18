#!/usr/bin/perl -w

%INDEX=();

print "Reading index\n";

open FH, "<index.html" || die;

while(<FH>)
{
    if(/HREF='([0-9]+).html'\>(.+)\<\/A\>$/)
    {
        $INDEX{$1} = $2;
    }
}

close FH;

sub fix_file {
    my $in = shift @_;

    open FH, "<$in" || die;
    open FHO, ">tmpout.html" || die;

    $_ = join "", <FH>;

    foreach $i (keys %INDEX)
    {
        s/href=\"\/index.php\/\Q$INDEX{$i}\E\"/href=\"$i.html\"/gsm;
        s/href=\"htt\S+\/\/wiki.archlinux.org\/index.php\/\Q$INDEX{$i}\E\"/href=\"$i.html\"/gsm;
    }
    print FHO;

    close FH;
    close FHO;

    rename("tmpout.html", "$in");
}

@files=<0*.html>;

foreach $f (@files)
{
    print "Fixing $f\n";
    fix_file($f);
}
