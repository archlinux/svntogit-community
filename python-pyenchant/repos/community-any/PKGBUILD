# Contributor: Pierre Buard <pierre.buard@gmail.com>
# Contributor: Allan McRae <allan@archlinux.org>
# Contributor: Sebastien Piccand <sebcactus gmail com>
# Contributor: Daniel J Griffiths <ghost1227@archlinux.us>
# Maintainer: Jelle van der Waa <jelle@archlinux.org>

pkgname=python-pyenchant
pkgver=3.2.2
pkgrel=2
arch=('any')
url="https://pypi.python.org/pypi/pyenchant"
license=('LGPL')
pkgdesc='PyEnchant is a spellchecking library for Python3 based on the Enchant library'
depends=('python' 'enchant')
makedepends=('python-setuptools' 'enchant')
source=("${pkgname}-${pkgver}.tar.gz::https://github.com/rfk/pyenchant/archive/v${pkgver}.tar.gz")
sha512sums=('42ab2e0cc38af4223ec0233c9e22cd151aa9bda5b56b7bd642e39e3a323ab3c034391123af5d3a5399551533ba1c1746abd6bc9ee2ab4c7879b9bf0ac91e056d')

build() {
  cd pyenchant-${pkgver}

  python3 setup.py build
}

package() {
  cd pyenchant-${pkgver}
  
  python3 setup.py install --root="${pkgdir}" --optimize=1
}
