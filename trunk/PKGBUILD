# CPAN Name  : List::AllUtils
# Contributor: Anton Leontiev <bunder /at/ t-25.ru>
# Generator  : CPANPLUS::Dist::Arch 1.29

pkgname=perl-list-someutils
pkgver=0.59
pkgrel=1
pkgdesc='Perl package that combines List::Util and List::MoreUtils in one bite-sized package'
arch=('any')
url='https://search.cpan.org/dist/List-SomeUtils'
license=('Artistic2.0')
depends=('perl' 'perl-module-implementation')
checkdepends=('perl-test-warnings')
source=(https://search.cpan.org/CPAN/authors/id/D/DR/DROLSKY/List-SomeUtils-$pkgver.tar.gz)
options=(!emptydirs)
sha256sums=('fab30372e4c67bf5a46062da38d1d0c8756279feada866eb439fa29571a2dc7b')

build() {
	cd List-SomeUtils-$pkgver
	unset PERL5LIB PERL_MM_OPT PERL_LOCAL_LIB_ROOT
	export PERL_MM_USE_DEFAULT=1 PERL_AUTOINSTALL=--skipdeps
	perl Makefile.PL INSTALLDIRS=vendor
	make
}

check() {
	cd List-SomeUtils-$pkgver
	unset PERL5LIB PERL_MM_OPT PERL_LOCAL_LIB_ROOT
	export PERL_MM_USE_DEFAULT=1
	make test
}

package() {
	cd List-SomeUtils-$pkgver
	unset PERL5LIB PERL_MM_OPT PERL_LOCAL_LIB_ROOT
	make install DESTDIR="$pkgdir"
	find "$pkgdir" -name .packlist -o -name perllocal.pod -delete
}
