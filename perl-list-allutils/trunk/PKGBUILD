# CPAN Name  : List::AllUtils
# Contributor: Anton Leontiev <bunder /at/ t-25.ru>
# Generator  : CPANPLUS::Dist::Arch 1.29

pkgname=perl-list-allutils
pkgver=0.09
pkgrel=1
pkgdesc='Perl package that combines List::Util and List::MoreUtils in one bite-sized package'
arch=('any')
url='http://search.cpan.org/dist/List-AllUtils'
license=('Artistic2.0')
depends=('perl>=5.19.3' 'perl-list-moreutils>=0.28')
checkdepends=('perl-test-warnings')
source=(http://search.cpan.org/CPAN/authors/id/D/DR/DROLSKY/List-AllUtils-0.09.tar.gz)
options=(!emptydirs)
md5sums=('3e2dfeeef80c4e1952443c6b7d48583c')

build() {
	cd List-AllUtils-0.09
	unset PERL5LIB PERL_MM_OPT PERL_LOCAL_LIB_ROOT
	export PERL_MM_USE_DEFAULT=1 PERL_AUTOINSTALL=--skipdeps
	/usr/bin/perl Makefile.PL INSTALLDIRS=vendor
	make
}

check() {
	cd List-AllUtils-0.09
	unset PERL5LIB PERL_MM_OPT PERL_LOCAL_LIB_ROOT
	export PERL_MM_USE_DEFAULT=1
	make test
}

package() {
	cd List-AllUtils-0.09
	unset PERL5LIB PERL_MM_OPT PERL_LOCAL_LIB_ROOT
	make install DESTDIR="$pkgdir"
	find "$pkgdir" -name .packlist -o -name perllocal.pod -delete
}
