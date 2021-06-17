# Maintainer: David Runge <dvzrv@archlinux.org>

pkgname=pypiserver
pkgver=1.4.2
pkgrel=1
pkgdesc="Minimal PyPI server for uploading and downloading packages with pip/easy_install"
arch=('any')
url="https://github.com/pypiserver/pypiserver"
license=('MIT' 'zlib')
depends=('python')
makedepends=('python-setuptools' 'python-setuptools-git' 'python-wheel')
checkdepends=('python-passlib' 'python-pip' 'python-pytest' 'python-webtest' 'twine')
optdepends=('python-passlib: for authentication')
source=("$pkgname-$pkgver.tar.gz::https://github.com/${pkgname}/${pkgname}/archive/refs/tags/v${pkgver}.tar.gz")
sha512sums=('8597a6a7e83cb3f5ead3418ee91167e1764c123b244c05397fa892c8ebe84b58569f27ce85cd9849d6a41d20342de21cf9cc46e00b233d9d94d0540470e1c49b')
b2sums=('fe9a41c35d601ee20f2cfe0773ce341b8c8fe387a2b825d1e6d669d5f358846b436158beb8a1222fa33cf1841cad5aceacc0f5063f899445ad15ca9eb5b8efd7')
validpgpkeys=('0BFB950A1851C0E7EE46D9BCAF5C892A5573ABED') # Matthew Planchard (2020-06-22-mininix) <msplanchard@gmail.com>

build() {
  cd "$pkgname-$pkgver"
  python setup.py build
}

check() {
  cd "$pkgname-$pkgver"
  export PYTHONPATH="build:${PYTHONPATH}"
  pytest -v
}

package() {
  cd "$pkgname-$pkgver"
  python setup.py install --skip-build \
                          --optimize=1 \
                          --root="${pkgdir}"
  install -vDm 644 {AUTHORS,CHANGES,README}.rst -t "${pkgdir}/usr/share/doc/${pkgname}/"
  install -vDm 644 LICENSE.txt -t "${pkgdir}/usr/share/licenses/${pkgname}/"
}
