# Maintainer: Jonathan Steel <jsteel at aur.archlinux.org>
# Contributor: Justin Davis (juster) <jrcd83@gmail.com>

pkgname=perl-params-util
pkgver=1.102
pkgrel=3
pkgdesc='Simple, compact and correct param-checking functions'
arch=('x86_64')
url="https://metacpan.org/release/Params-Util"
license=('PerlArtistic' 'GPL')
depends=('perl')
options=('!emptydirs')
source=("https://search.cpan.org/CPAN/authors/id/R/RE/REHSACK/Params-Util-$pkgver.tar.gz")
sha512sums=('e2587b62545cf0572cc8f719ea8e5411d710789c3cbcab4038c5b01f86073a010d32191551f6aeea1bdae22d49e7d34358250b4e7ece9f261a598854af187194')

build() {
  cd "$srcdir/Params-Util-$pkgver"
  export PERL_MM_USE_DEFAULT=1 PERL_AUTOINSTALL=--skipdeps
  unset PERL5LIB PERL_MM_OPT
  /usr/bin/perl Makefile.PL
  make
}

check() {
  cd "$srcdir/Params-Util-$pkgver"
  export PERL_MM_USE_DEFAULT=1
  unset PERL5LIB
  make test
}

package() {
  cd "$srcdir/Params-Util-$pkgver"
  make install INSTALLDIRS=vendor DESTDIR="$pkgdir"
  find "$pkgdir" -name .packlist -o -name perllocal.pod -delete
}

# Local Variables:
# mode: shell-script
# sh-basic-offset: 2
# End:
# vim:set ts=2 sw=2 et:
