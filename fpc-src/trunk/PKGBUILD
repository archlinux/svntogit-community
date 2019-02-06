# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Jens Adam <jra@byte.cx>

pkgname=fpc-src
pkgver=3.0.4
pkgrel=2
pkgdesc='Sources for the FreePascal compiler (required by the Lazarus IDE)'
url='https://www.freepascal.org/'
license=('GPL')
arch=('any')
options=('!strip' 'staticlibs')
source=("ftp://ftp.freepascal.org/pub/fpc/dist/$pkgver/source/fpcbuild-$pkgver.tar.gz")
sha512sums=('eedfeb4d25b3f4cb30ae9c8f30e0fec2405ef806fa565933cef7904d512f781730e3f023aea2f908c21250e3ced4f74fa780abad77b560728a88cedf591505b6')

package() {
  cd "$srcdir"/fpcbuild-$pkgver/fpcsrc
  mkdir -p "$pkgdir"/usr/lib/fpc/src
  cp -R . "$pkgdir"/usr/lib/fpc/src
}
