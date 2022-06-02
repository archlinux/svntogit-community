# Maintainer: Sergej Pupykin <arch+pub@sergej.pp.ru>
# Maintainer: Maxwell Pray a.k.a. Synthead <synthead@gmail.com>
# Contributor: aurperl@juster.us

pkgname="perl-b-hooks-endofscope"
_cpanname="B-Hooks-EndOfScope"
pkgver=0.26
pkgrel=1
pkgdesc="Execute code after a scope finished compilation"
arch=("any")
license=("PerlArtistic" "GPL")
options=("!emptydirs")
depends=("perl-module-implementation"
	 "perl-module-runtime"
	 "perl-sub-exporter"
	 "perl-sub-exporter-progressive"
	 "perl-try-tiny"
	 "perl-variable-magic>=0.34"
	 "perl>=5.5.0")
url="https://search.cpan.org/~bobtfish/B-Hooks-EndOfScope-$pkgver/"
source=("https://search.cpan.org/CPAN/authors/id/E/ET/ETHER/B-Hooks-EndOfScope-$pkgver.tar.gz")
sha256sums=('39df2f8c007a754672075f95b90797baebe97ada6d944b197a6352709cb30671')

build() {
	cd "$srcdir"/B-Hooks-EndOfScope-$pkgver
	PERL_MM_USE_DEFAULT=1 perl Makefile.PL INSTALLDIRS=vendor
	make
}

check() {
	cd "$srcdir"/B-Hooks-EndOfScope-$pkgver
	make test
}

package() {
	cd "$srcdir"/B-Hooks-EndOfScope-$pkgver
	make install DESTDIR="$pkgdir"
	# Remove "perllocal.pod" and ".packlist".
	find "$pkgdir" -name .packlist -o -name perllocal.pod -delete
}
