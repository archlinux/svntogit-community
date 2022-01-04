# Maintainer: Filipe Laíns (FFY00) <lains@archlçinux.org>
# Contributor: Lukas Fleischer <lfleischer@archlinux.org>
# Contributor: Stefan Husmann <stefan-husmann@t-online.de>
# Contributor: Simon Lipp <sloonz+aur@gmail.com>

pkgname=java-commons-io
pkgver=2.11.0
pkgrel=1
pkgdesc='IO related classes for Java.'
arch=('any')
url='https://commons.apache.org/io/'
license=('APACHE')
depends=('java-runtime')
source=("https://www.apache.org/dist/commons/io/binaries/commons-io-$pkgver-bin.tar.gz"{,.asc})
sha512sums=('b28938f197f29a7145f6e43e41b917ebd98bd6ba308e3b7ba85a455b77e3e5a7d62beac1a83e20246ac07ba19048fb4f952e3f5323c714f2b515dd94a1524d46'
            'SKIP')
validpgpkeys=('6BDACA2C0493CCA133B372D09C4F7E9D98B1CC53'  # Benson Margulies
              'CD5464315F0B98C77E6E8ECD9DAADC1C9FCC82D0'  # Benedikt Ritter
              '2DB4F1EF0FA761ECC4EA935C86FDC7E2A11262CB') # Gary David Gregory (Code signing key) <ggregory@apache.org>

package() {
  install -Dm 644 "$srcdir"/commons-io-$pkgver/commons-io-$pkgver.jar "$pkgdir"/usr/share/java/commons-io/commons-io.jar
}
