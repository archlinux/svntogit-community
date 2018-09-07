# Maintainer: David Runge <dave@sleepmap.de>
_name=toml
pkgbase=python-toml
pkgname=('python-toml' 'python2-toml')
pkgver=0.9.4
pkgrel=4
pkgdesc="A Python library for parsing and creating TOML"
arch=('any')
url="https://github.com/uiri/toml"
license=('MIT')
makedepends=('python-setuptools' 'python2-setuptools')
checkdepends=('python-pytest')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/${_name}/${_name}-${pkgver}.tar.gz")
sha512sums=('4f87344c5735e8c6c5377c9c48e301c04a224e078e6f8755a9c1f9076cd852fd12dffe25d83cfc6d5dbf181ef1156fa56233cae11537a164416c4b6424b154ba')
validpgpkeys=()

prepare() {
  mv -v "${_name}-$pkgver" "$pkgbase-$pkgver"
  cd "$pkgbase-$pkgver"
}

build() {
  cd "$pkgbase-$pkgver"
  python setup.py build
  python2 setup.py build
}

# no tests in pypi source: https://github.com/uiri/toml/issues/192
#check() {
#  cd "$pkgname-$pkgver"
#  python setup.py build
#  python2 setup.py build
#}

package_python-toml() {
  cd "$pkgname-$pkgver"
  depends=('python')
  python setup.py install --skip-build \
    --optimize=1 \
    --prefix=/usr \
    --root="${pkgdir}"
  install -vDm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
  install -vDm 644 README.rst -t "${pkgdir}/usr/share/doc/${pkgname}"
}

package_python2-toml() {
  cd "$pkgbase-$pkgver"
  depends=('python2')
  python2 setup.py install --skip-build \
    --optimize=1 \
    --prefix=/usr \
    --root="${pkgdir}"
  install -vDm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
  install -vDm 644 README.rst -t "${pkgdir}/usr/share/doc/${pkgname}"
}
