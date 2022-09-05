# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Maintainer: Jan-Erik Rediger <badboy at archlinux dot us>
# Contributor: Gerardo Exequiel Pozzi <vmlinuz386@yahoo.com.ar>
# Contributor: Francois Charette <firmicus@gmx.net>

pkgname=perl-ipc-run
pkgver=20220807.0
pkgrel=1
pkgdesc="IPC::Run - system() and background procs w/ piping, redirs, ptys"
arch=('any')
url="https://search.cpan.org/dist/IPC-Run"
license=('GPL' 'PerlArtistic')
# IPC::Run depends on IO::Pty which is provided by perl-io-tty
depends=('perl' 'perl-io-tty')
options=('!emptydirs')
source=("https://search.cpan.org/CPAN/authors/id/T/TO/TODDR/IPC-Run-$pkgver.tar.gz")
sha256sums=('277d781dbbc98af18e979c7ef36f222513d7361742c52507c3348b265f6f5e69')

build() {
  cd "$srcdir"/IPC-Run-$pkgver
  PERL_MM_USE_DEFAULT=1 perl Makefile.PL INSTALLDIRS=vendor
  make
}

package() {
  cd "$srcdir"/IPC-Run-$pkgver
  make install DESTDIR="$pkgdir"
  find "$pkgdir" -name perllocal.pod -delete
  find "$pkgdir" -name .packlist -delete
}
