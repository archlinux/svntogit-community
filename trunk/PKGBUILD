# Maintainer: jsteel <mail at jsteel dot org>
# Contributor: Alan Young <harleypig@gmail.com>

pkgname='perl-sub-exporter-progressive'
_pkgname='Sub-Exporter-Progressive'
pkgver='0.001010'
pkgrel='1'
pkgdesc='Only use Sub::Exporter if you need it'
arch=('any')
url='http://search.cpan.org/dist/Sub-Exporter-Progressive'
license=('PerlArtistic' 'GPL')
options=('!emptydirs')
source=("http://search.cpan.org/CPAN/authors/id/F/FR/FREW/$_pkgname-$pkgver.tar.gz")
md5sums=('0350d9e12549112ae1f618cbff3ecbd9')

build() {
  export MODULEBUILDRC=/dev/null \
         PERL5LIB="" \
         PERL_AUTOINSTALL=--skipdeps \
         PERL_MB_OPT="--installdirs vendor --destdir \"$pkgdir\"" \
         PERL_MM_OPT="INSTALLDIRS=vendor DESTDIR=\"$pkgdir\"" \
         PERL_MM_USE_DEFAULT=1

  cd "$srcdir"/$_pkgname-$pkgver

  if [[ -e ./Build.PL ]]; then
    /usr/bin/perl Build.PL
    ./Build
  elif [[ -e ./Makefile.PL ]]; then
    /usr/bin/perl Makefile.PL
    make
  fi
}

check() {
  export MODULEBUILDRC=/dev/null \
         PERL5LIB="" \
         PERL_AUTOINSTALL=--skipdeps \
         PERL_MB_OPT="--installdirs vendor --destdir \"$pkgdir\"" \
         PERL_MM_OPT="INSTALLDIRS=vendor DESTDIR=\"$pkgdir\"" \
         PERL_MM_USE_DEFAULT=1

  cd "$srcdir"/$_pkgname-$pkgver

  if [[ -e ./Build.PL ]]; then
    ./Build test
  elif [[ -e ./Makefile.PL ]]; then
    make test
  fi
}

package() {
  export MODULEBUILDRC=/dev/null \
         PERL5LIB="" \
         PERL_AUTOINSTALL=--skipdeps \
         PERL_MB_OPT="--installdirs vendor --destdir \"$pkgdir\"" \
         PERL_MM_OPT="INSTALLDIRS=vendor DESTDIR=\"$pkgdir\"" \
         PERL_MM_USE_DEFAULT=1

  cd "$srcdir"/$_pkgname-$pkgver

  if [[ -e ./Build.PL ]]; then
    ./Build install
  elif [[ -e ./Makefile.PL ]]; then
    make install
  fi

  find "$pkgdir" -name .packlist -o -name perllocal.pod -delete
}
