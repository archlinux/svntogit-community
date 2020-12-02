# Maintainer: David Runge <dvzrv@archlinux.org>

_name=sphinx-argparse
pkgname=python-sphinx-argparse
pkgver=0.2.5
pkgrel=4
pkgdesc="Sphinx extension that automatically documents argparse commands and options"
arch=('any')
url="https://github.com/ribozz/sphinx-argparse"
license=('MIT')
depends=('python-sphinx')
makedepends=('python-setuptools')
checkdepends=('python-pytest')
optdepends=('python-commonmark: markdown support')
# license file missing in source tarball: https://github.com/ribozz/sphinx-argparse/issues/116
source=("https://files.pythonhosted.org/packages/source/${_name::1}/${_name}/${_name}-${pkgver}.tar.gz"
        "${pkgname}-${pkgver}.LICENSE::https://raw.githubusercontent.com/ribozz/${_name}/${pkgver}/LICENSE")
sha512sums=('785e2b1ea04b39721d28aee712b87f7fccb56a25a2d5ccf7825b27673a7e53069265c89b32f7b63d4f788127fe815595913af699dba3cd60db37a7efdef6ea55'
            '35a00cf0287c871f0eaee9288f5cd14470440b006d6be6abcbe75a34040324777fbb6de94ee9d9f5d2f6aca85a8d73c09ecbf12cf9b4c5c52ed7545cbe30871d')

prepare() {
  mv -v "${_name}-${pkgver}" "${pkgname}-${pkgver}"
  # fix problematic file permissions: https://github.com/ribozz/sphinx-argparse/issues/117
  cd "${pkgname}-${pkgver}"
  chmod 644 sphinx_argparse.egg-info/*
}

build() {
  cd "${pkgname}-${pkgver}"
  python setup.py build
}

check() {
  cd "${pkgname}-${pkgver}"
  export PYTHONPATH="build:${PYTHONPATH}"
  py.test
}

package() {
  cd "${pkgname}-${pkgver}"
  python setup.py install --skip-build \
    --optimize=1 \
    --prefix=/usr \
    --root="${pkgdir}"
  install -vDm 644 README.md -t "${pkgdir}/usr/share/doc/${pkgname}"
  install -vDm 644 "../${pkgname}-${pkgver}.LICENSE" \
    -t "${pkgdir}/usr/share/licenses/${pkgname}"
}
# vim:set ts=2 sw=2 et:
