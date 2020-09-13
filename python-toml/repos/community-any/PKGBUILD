# Maintainer: David Runge <dvzrv@archlinux.org>

_name=toml
pkgbase=python-toml
pkgname=('python-toml' 'python2-toml')
pkgver=0.10.1
pkgrel=2
pkgdesc="A Python library for parsing and creating TOML"
arch=('any')
url="https://github.com/uiri/toml"
license=('MIT')
makedepends=('python-setuptools' 'python2-setuptools')
checkdepends=('python-numpy' 'python-pytest' 'python2-numpy' 'python2-pytest')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/${_name}/${_name}-${pkgver}.tar.gz"
        "${pkgbase}-0.10.1-install_type_hints.patch")
sha512sums=('9dc813f84b56bee6519c70efe49a834d6695c82d429f0b7cc6e6153a1fb14d3fb627dea24df2d2664354f27108389d51475609272d59fc7e4b64a2c17d74f33f'
            '000fd1416341567a1828034f6e3844f7c5436e2b89f06b0ffa2567fc86d3b72dd4a8085d26d4366764446dfb050cfececaada4ca53f9c355c62aafb26ea87be4')
b2sums=('ef607093fae3a148c7f904a2281b8218855aad6d8af7a54eda2c7c835e8a86719b240a5486f761850e4d80ef1c1711ef33077fa6fd49eeb903faeae550d8941b'
        '23449773cb0c7004d6c367c4cef666561e16fcd38166d17428a8192f6649bdfa76277f20bd4662f7571bc020fba6e5614e8f7dcf8502d18eb1e0ede6cb3ddde2')

prepare() {
  mv -v "${_name}-$pkgver" "$pkgbase-$pkgver"
  cd "$pkgbase-$pkgver"
  patch -Np1 -i ../"${pkgbase}-0.10.1-install_type_hints.patch"
  mv -v "${_name}.pyi" "${_name}/__init__.pyi"
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
