# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>

pkgname=perl-net-imap-simple
pkgver=1.2203
pkgrel=1
pkgdesc="Net::IMAP::Simple - a simple IMAP access library"
arch=(i686 x86_64)
license=('GPL' 'PerlArtistic')
url="http://search.cpan.org/dist/Net-IMAP-Simple/"
depends=('perl>=5.10.0')
options=(!emptydirs)
source=(http://search.cpan.org/CPAN/authors/id/J/JE/JETTERO/Net-IMAP-Simple-${pkgver}.tar.gz)
md5sums=('9697aa4197aa8bedda506904fa0b1a6e')

build() {
  cd $srcdir/Net-IMAP-Simple-${pkgver}
  yes n | perl Makefile.PL INSTALLDIRS=vendor
  make
}

package() {
  cd $srcdir/Net-IMAP-Simple-${pkgver}
  make install DESTDIR=$pkgdir
  find $pkgdir -name perllocal.pod -delete
  find $pkgdir -name .packlist -delete
}
