use 5.006001;
use ExtUtils::MakeMaker;
WriteMakefile(
    NAME             => "PerlIO::via::symlink",
    VERSION_FROM     => 'symlink.pm',
    'dist'           => {
        COMPRESS     => 'gzip -9f',
        SUFFIX       => 'gz',
        DIST_DEFAULT => 'all tardist',
    },
    MAN3PODS         => {'symlink.pm' => 'blib/man3/PerlIO::via::symlink.3pm'},
    INSTALLDIRS      => 'perl',
);
