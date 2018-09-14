# Maintainer: David Runge <dave@sleepmap.de>
_name=toml
pkgbase=python-toml
pkgname=('python-toml' 'python2-toml')
pkgver=0.9.6
pkgrel=1
pkgdesc="A Python library for parsing and creating TOML"
arch=('any')
url="https://github.com/uiri/toml"
license=('MIT')
makedepends=('python-setuptools' 'python2-setuptools')
checkdepends=('python-pytest')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/${_name}/${_name}-${pkgver}.tar.gz")
sha512sums=('9f2804daebae0744c3a00bfb27b2f1efd73c96e7e5a14316d492200d63ba546167f669a187297c76daca5ef35b7adb6f309c1f6129302b6f41e6b7673bdb43b6')

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
#  python setup.py test
#  python2 setup.py test
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
