# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Bartosz Feński <fenio@debian.org>

pkgname=reaver
pkgver=1.6.6
pkgrel=1
pkgdesc='Brute force attack against Wifi Protected Setup'
url='https://github.com/t6x/reaver-wps-fork-t6x'
arch=('x86_64')
license=('GPL2')
depends=('glibc' 'libpcap')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/t6x/reaver-wps-fork-t6x/archive/v${pkgver}.tar.gz)
sha512sums=('431e3ed03eb6145a33a27bd03f4568c58046721566505f06bb0fe42ace8327d6749a70d443a592278253248f676299ff29962c839409d0173733eaaf0e2e6410')

prepare() {
  cd reaver-wps-fork-t6x-${pkgver}
  sed 's|CFLAGS=|CFLAGS+=|' -i src/Makefile
}

build() {
  cd reaver-wps-fork-t6x-${pkgver}/src
  ./configure --prefix=/usr --sysconfdir=/etc
  make CONFDIR=/etc/reaver
}

package() {
  cd reaver-wps-fork-t6x-${pkgver}
  install -Dm 755 src/{reaver,wash} -t "${pkgdir}"/usr/bin
  install -dm 755 "${pkgdir}"/etc/reaver
  install -Dm 644 docs/README -t "${pkgdir}"/usr/share/doc/reaver
  install -Dm 644 docs/reaver.1 -t "${pkgdir}"/usr/share/man/man1
}
