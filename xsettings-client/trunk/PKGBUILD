# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Alois Belaska <lloyd@centrum.cz>

pkgname=xsettings-client
pkgver=0.10
pkgrel=9
pkgdesc="Provides cross toolkit configuration settings such as theme parameters"
arch=('x86_64')
license=('GPL')
url="http://matchbox-project.org"
depends=('libx11')
source=(https://downloads.yoctoproject.org/releases/matchbox/optional-dependencies/Xsettings-client-$pkgver.tar.gz)
sha512sums=('051eaafa3410f82afea8f5909e5ef46548737f5b7bb3cb9c31262426ebc8e39ce4e84cfa76629cfb6b608fc764b2bbc3e7345a0e8e4257c7f6ea640c3b419634')

build() {
  cd "$srcdir"/Xsettings-client-$pkgver
  ./configure --prefix=/usr
  make
}

package() {
  cd "$srcdir"/Xsettings-client-$pkgver
  make DESTDIR="$pkgdir" install
}
