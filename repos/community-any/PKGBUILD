# Maintainer: David Runge <dave@sleepmap.de>
_name=toml
pkgbase=python-toml
pkgname=('python-toml' 'python2-toml')
pkgver=0.10.0
pkgrel=3
pkgdesc="A Python library for parsing and creating TOML"
arch=('any')
url="https://github.com/uiri/toml"
license=('MIT')
makedepends=('python-setuptools' 'python2-setuptools')
checkdepends=('python-pytest' 'python2-pytest')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/${_name}/${_name}-${pkgver}.tar.gz"
        "https://raw.githubusercontent.com/uiri/toml/master/test.toml")
sha512sums=('26f26c38ce9cd48305218c2c34c5a5407b00aefc25a933f044bb7be22c23cfdfa3b8cf2da952d17760c4b9038df62e405fa039cc7b63dd3e94c9c312f04f9182'
            '47510e59f9e0bdaaf4052fc5edb570a36b8b173ed7b8e5fac52804f6619f409e545ae3c91f838dbaeefe3c7cfd1a835b699164ac631feaa61de971d2381ac246')

prepare() {
  mv -v "${_name}-$pkgver" "$pkgbase-$pkgver"
  cp -v test.toml "$pkgbase-$pkgver"
  cd "$pkgbase-$pkgver"
}

build() {
  cd "$pkgbase-$pkgver"
  python setup.py build
  python2 setup.py build
}

check() {
  cd "$pkgname-$pkgver"
  export PYTHONPATH="../build/lib/:${PYTHONPATH}"
  # disable useless tests
  py.test tests -k 'not test_invalid_tests and not test_valid_tests'
  py.test2 tests -k 'not test_invalid_tests and not test_valid_tests'
}

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
