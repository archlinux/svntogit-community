# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Jens Adam <jra@byte.cx>

pkgname=fpc-src
pkgver=3.2.2
pkgrel=3
pkgdesc='Sources for the FreePascal compiler (required by the Lazarus IDE)'
url='https://www.freepascal.org/'
license=('GPL')
arch=('any')
options=('!strip' 'staticlibs')
source=("https://downloads.sourceforge.net/project/freepascal/Source/$pkgver/fpcbuild-$pkgver.tar.gz")
sha512sums=('75889bb54adc70a6e2cbd291476b9b12d61c8f943a05b7d16d2024de3215c935465ff43b1400c412e128e260c7f49a9c66e35c21f86cb866e671b5b60a282d82')

package() {
  cd "$srcdir"/fpcbuild-$pkgver/fpcsrc
  mkdir -p "$pkgdir"/usr/lib/fpc/src
  cp -R . "$pkgdir"/usr/lib/fpc/src
}
