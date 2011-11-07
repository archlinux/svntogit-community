# Maintainer: Thomas Dziedzic < gostrc at gmail >
# Contributor: Slash <demodevil5 [at] yahoo [dot] com>

pkgname=nut
pkgver=17.4
pkgrel=1
pkgdesc='Records what you eat and analyzes your meals for nutrient levels in terms of the Daily Value or DV which is the standard for food labeling in the US.'
url='http://nut.sourceforge.net/'
license=('GPL')
arch=('i686' 'x86_64')
source=("http://downloads.sourceforge.net/project/nut/nut/${pkgver}/nut-${pkgver}.tar.gz")
md5sums=('9d8b33fe0edbc54a6ebc8050dec7d56b')

build() {
  cd ${pkgname}-${pkgver}

  # change install path to /usr instead of /usr/local
  sed \
    -e 's#/local##' \
    -i Makefile

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
