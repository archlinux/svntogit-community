# Maintainer: David Runge <dvzrv@archlinux.org>

_name=toml
pkgbase=python-toml
pkgname=('python-toml' 'python2-toml')
pkgver=0.10.1
pkgrel=1
pkgdesc="A Python library for parsing and creating TOML"
arch=('any')
url="https://github.com/uiri/toml"
license=('MIT')
makedepends=('python-setuptools' 'python2-setuptools')
checkdepends=('python-numpy' 'python-pytest' 'python2-numpy' 'python2-pytest')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/${_name}/${_name}-${pkgver}.tar.gz")
sha512sums=('9dc813f84b56bee6519c70efe49a834d6695c82d429f0b7cc6e6153a1fb14d3fb627dea24df2d2664354f27108389d51475609272d59fc7e4b64a2c17d74f33f')

prepare() {
  mv -v "${_name}-$pkgver" "$pkgbase-$pkgver"
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
