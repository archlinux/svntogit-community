# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

pkgname=python-sphinx-autodoc-typehints
_pyname=${pkgname/python-/}
_commit=09197b80cd5a5aa3a3a7a69fcea4d0ca410d1e9f
pkgver=1.23.0
pkgrel=2
pkgdesc='Type hints support for the Sphinx autodoc extension'
url='https://github.com/tox-dev/sphinx-autodoc-typehints'
arch=('any')
license=('MIT')
depends=('python' 'python-sphinx' 'python-typing_extensions')
makedepends=('git' 'python-build' 'python-installer' 'python-hatchling' 'python-hatch-vcs')
checkdepends=('python-pytest' 'python-sphobjinv' 'python-nptyping')
source=("git+$url.git#commit=${_commit}")
sha512sums=('SKIP')

build() {
  cd ${_pyname}
  python -m build --wheel --no-isolation
}

check() {
  cd ${_pyname}
  PYTHONPATH="$PWD/src" pytest
}

package() {
  cd ${_pyname}
  python -m installer --destdir="${pkgdir}" dist/*.whl
  install -Dm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
  install -Dm 644 README.md -t "${pkgdir}/usr/share/doc/${pkgname}"
}

# vim: ts=2 sw=2 et:
