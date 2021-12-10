# Maintainer: David Runge <dvzrv@archlinux.org>

_name=sphinx-argparse
pkgname=python-sphinx-argparse
pkgver=0.3.1
pkgrel=2
pkgdesc="Sphinx extension that automatically documents argparse commands and options"
arch=(any)
url="https://github.com/ashb/sphinx-argparse"
license=(MIT)
depends=(python-sphinx)
makedepends=(python-setuptools)
checkdepends=(python-pytest)
optdepends=('python-commonmark: markdown support')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/${_name}/${_name}-${pkgver}.tar.gz"
)
sha512sums=('de6948a24abc4012b1b2431176d0547f04e1076804b2a186b027fcb76a458b6ae670aca91400cc3e2fa789b5cd3754cf6b24116258e04fc81f91890bb0f08a46')
b2sums=('47343114843e0af7c296302d167a70d021e6c9f75f6ef9d01fcaca52a120f606cb6732f2e90876fa29303c23ce1f066540116d6ba2d67caa267a1a421c23d253')

prepare() {
  mv -v "${_name}-${pkgver}" "${pkgname}-${pkgver}"
}

build() {
  cd "${pkgname}-${pkgver}"
  python setup.py build
}

check() {
  cd "${pkgname}-${pkgver}"
  export PYTHONPATH="build:${PYTHONPATH}"
  # disable tests that rely on hardcoding argparse output: https://github.com/ashb/sphinx-argparse/issues/5
  pytest -vv -k "not test_parse_nested and not test_parse_nested_with_alias and not test_parse_groups and not test_action_groups_with_subcommands"
}

package() {
  cd "${pkgname}-${pkgver}"
  python setup.py install --optimize=1 --root="${pkgdir}"
  install -vDm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
  # remove conflicting top-level test dir https://github.com/ashb/sphinx-argparse/issues/6
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")
  rm -frv "${pkgdir}/${site_packages}/test"
}
# vim:set ts=2 sw=2 et:
