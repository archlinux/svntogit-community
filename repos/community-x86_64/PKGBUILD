# Maintainer: Thomas Dziedzic < gostrc at gmail >
# Contributor: Slash <demodevil5 [at] yahoo [dot] com>

pkgname=nut
pkgver=16.1
pkgrel=1
pkgdesc='Records what you eat and analyzes your meals for nutrient levels in terms of the Daily Value or DV which is the standard for food labeling in the US.'
url='http://nut.sourceforge.net/'
license=('GPL')
arch=('i686' 'x86_64')
source=("http://downloads.sourceforge.net/project/${pkgname}/${pkgname}/${pkgver}/${pkgname}-${pkgver}.tar.gz")
md5sums=('52bdf41a38406ad82f0e447d60ab2e37')

build() {
  cd ${pkgname}-${pkgver}

  # change install path to /usr instead of /usr/local
  sed -i 's#local/##' Makefile

  make
}

package() {
  cd ${pkgname}-${pkgver}

  # Install Data
  install -d ${pkgdir}/usr/lib/${pkgname}
  install -m644 raw.data/* \
    ${pkgdir}/usr/lib/${pkgname}/

  # Install Binary
  install -D ${pkgname} \
    ${pkgdir}/usr/bin/${pkgname}

  # Install Man Page
  install -D -m644 ${pkgname}.1 \
    ${pkgdir}/usr/share/man/man1/${pkgname}.1
}
