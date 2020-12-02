# Maintainer: David Runge <dvzrv@archlinux.org>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_name=toml
pkgbase=python-toml
pkgname=('python-toml' 'python2-toml')
pkgver=0.10.2
pkgrel=3
pkgdesc="A Python library for parsing and creating TOML"
arch=('any')
url="https://github.com/uiri/toml"
license=('MIT')
makedepends=('python-setuptools' 'python2-setuptools')
checkdepends=('python-numpy' 'python-pytest' 'python2-numpy' 'python2-pytest')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/${_name}/${_name}-${pkgver}.tar.gz"
        "${pkgbase}-0.10.1-install_type_hints.patch")
sha256sums=('b3bda1d108d5dd99f4a20d24d9c348e91c4db7ab1b749200bded2f839ccbe68f'
            '7597ca115ba497797cf7c1330f5e93146ff5a924ef3bc331a8e77da12ee880cf')
b2sums=('a613d5e86fc77279f2d7b130309627eed1cab3a65fe8647cb1dc3e58d09a9d58c078472638f06f45394b00c142bcb2bc75e9c0c649d58aade2f4f6bdab23f12e'
        '23449773cb0c7004d6c367c4cef666561e16fcd38166d17428a8192f6649bdfa76277f20bd4662f7571bc020fba6e5614e8f7dcf8502d18eb1e0ede6cb3ddde2')

prepare() {
  mv -v "${_name}-$pkgver" "$pkgbase-$pkgver"
  cd "$pkgbase-$pkgver"
  patch -Np1 -i ../"${pkgbase}-0.10.1-install_type_hints.patch"
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
  pytest -v tests -k 'not test_invalid_tests and not test_valid_tests'
  pytest2 -v tests -k 'not test_invalid_tests and not test_valid_tests'
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
