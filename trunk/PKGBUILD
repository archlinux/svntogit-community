# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Tomislav Ivek <tomislav.ivek@gmail.com>

pkgname=python-distro
pkgver=1.7.0
pkgrel=1
pkgdesc='Linux OS platform information API'
url='https://github.com/python-distro/distro'
arch=('any')
license=('Apache')
depends=('python' 'python-setuptools')
makedepends=('python-sphinx' 'python-build' 'python-installer' 'python-wheel')
checkdepends=('python-pytest')
options=('!makeflags')
source=(${url}/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('6d2e2640b5233f9503adec1290d61cfe58a75faba75b42c71c219c73cf32d7a071018543721894d2565219d3d41b616300469bac8d6d4c5a91db89120343d32e')
b2sums=('18f92f51d912ab0a64dce54dfbb90b8300b927d59a1715b8e00ee4100b7183010f0093032dcd23bfbf0e51b8f2d5fd017cb66f5e25f0510db42032cf403ca0a8')

build() {
  cd distro-${pkgver}
  python -m build --wheel --no-isolation
}

check() {
  cd distro-${pkgver}
  PYTHONPATH="build/lib" pytest
}

package() {
  cd distro-${pkgver}
  python -m installer --destdir="${pkgdir}" dist/*.whl
  install -Dm 644 README.md CHANGELOG.md -t "${pkgdir}/usr/share/doc/${pkgname}"
}

# vim: ts=2 sw=2 et:
