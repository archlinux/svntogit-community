# Maintainer: Maxwell Pray a.k.a. Synthead <synthead@gmail.com>

pkgname=perl-list-utilsby
_cpanname="List-UtilsBy"
pkgver=0.12
pkgrel=1
pkgdesc="Higher-order list utility functions"
arch=('any')
url="https://search.cpan.org/~pevans/$_cpanname"
license=('GPL' 'PerlArtistic')
depends=('perl>=5.5.0')
options=('!emptydirs')
# Function to change to the working directory and set
# environment variables to override undesired options.
prepareEnvironment() {
	cd "$srcdir/$_cpanname-$pkgver"
	export \
		PERL_MM_USE_DEFAULT=1 \
		PERL_AUTOINSTALL=--skipdeps \
		PERL_MM_OPT="INSTALLDIRS=vendor DESTDIR='"$pkgdir"'" \
		PERL_MB_OPT="--installdirs vendor --destdir '"$pkgdir"'" \
		MODULEBUILDRC=/dev/null
}
source=("https://search.cpan.org/CPAN/authors/id/P/PE/PEVANS/$_cpanname-$pkgver.tar.gz")
sha256sums=('fff1281fd469fe982b1a58044becfd970f313bff3a26e1c7b2b3f4c0a5ed71e0')

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
