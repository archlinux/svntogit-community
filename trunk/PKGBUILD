# Maintainer: Maxwell Pray a.k.a. Synthead <synthead@gmail.com>
# Contributor: aurperl@juster.us

pkgname="perl-b-hooks-endofscope"
_cpanname="B-Hooks-EndOfScope"
pkgver="0.13"
pkgrel="1"
pkgdesc="Execute code after a scope finished compilation"
arch=("any")
license=("PerlArtistic" "GPL")
options=("!emptydirs")
depends=(
	"perl-module-implementation"
	"perl-module-runtime"
	"perl-sub-exporter"
	"perl-sub-exporter-progressive"
	"perl-try-tiny"
	"perl-variable-magic>=0.34"
	"perl>=5.5.0"
)
url="http://search.cpan.org/~bobtfish/$_cpanname-$pkgver/"
source=("http://search.cpan.org/CPAN/authors/id/E/ET/ETHER/$_cpanname-$pkgver.tar.gz")
md5sums=("6cdaaa88a39054cd13aacad7bd2171da")

# Function to change to the working directory and set
# environment variables to override undesired options.
prepareEnvironment() {
	cd "$srcdir/$_cpanname-$pkgver"
	export \
		PERL_MM_USE_DEFAULT=1 \
		PERL_AUTOINSTALL=--skipdeps \
		PERL_MM_OPT="INSTALLDIRS=vendor DESTDIR='$pkgdir'" \
		PERL_MB_OPT="--installdirs vendor --destdir '$pkgdir'" \
		MODULEBUILDRC=/dev/null
}

build() {
	prepareEnvironment
	/usr/bin/perl Makefile.PL
	make
}

check() {
	prepareEnvironment
	make test
}

package() {
	prepareEnvironment
	make install

	# Remove "perllocal.pod" and ".packlist".
	find "$pkgdir" -name .packlist -o -name perllocal.pod -delete
}
