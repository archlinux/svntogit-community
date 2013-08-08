# Maintainer: jsteel <mail at jsteel dot org>
# Contributor: Alan Young <harleypig@gmail.com>

pkgname='perl-devel-globaldestruction'
pkgver='0.11'
pkgrel='1'
pkgdesc="Expose the flag which marks global"
arch=('any')
license=('PerlArtistic' 'GPL')
options=('!emptydirs')
depends=('perl>=5.6.0' 'perl-sub-exporter' 'perl-sub-exporter-progressive>=0.001002')
url='http://search.cpan.org/dist/Devel-GlobalDestruction'
source=(http://search.cpan.org/CPAN/authors/id/H/HA/HAARG/Devel-GlobalDestruction-$pkgver.tar.gz)
md5sums=('f2f811fc3e8876aa3fa23d1d16dfb2bd')

build() {
  ( export PERL_MM_USE_DEFAULT=1 PERL5LIB=""                 \
      PERL_AUTOINSTALL=--skipdeps                            \
      PERL_MM_OPT="INSTALLDIRS=vendor DESTDIR='$pkgdir'"     \
      PERL_MB_OPT="--installdirs vendor --destdir '$pkgdir'" \
      MODULEBUILDRC=/dev/null

    cd "$srcdir"/Devel-GlobalDestruction-$pkgver

    /usr/bin/perl Makefile.PL

    make
  )
}

check() {
  cd "$srcdir"/Devel-GlobalDestruction-$pkgver

  ( export PERL_MM_USE_DEFAULT=1 PERL5LIB=""
    make test
  )
}

package() {
  cd "$srcdir"/Devel-GlobalDestruction-$pkgver

  make install

  find "$pkgdir" -name .packlist -o -name perllocal.pod -delete
}
